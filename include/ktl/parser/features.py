import re
from typing import TextIO
from model import Feature


# meta/feature.hpp: primary template and any_feature
FEATURE_META = """template < ktl::api::feature >
struct feature
{
    static constexpr ktl::api::feature        value          = {};
    static constexpr bool                     is_core        = {};
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = {};
    static constexpr ktl::usize               offsetof_stype = {};
    static constexpr ktl::usize               offsetof_pnext = {};
    static constexpr ktl::usize               offsetof_field = {};
};

struct any_feature
{
    ktl::api::feature        value;
    bool                     is_core;
    ktl::api::structure_type stype;
    ktl::usize               sizeof_struct;
    ktl::usize               offsetof_stype;
    ktl::usize               offsetof_pnext;
    ktl::usize               offsetof_field;
};"""


def vulkan_vendors(_root) -> tuple:
    # vendor suffixes of names from <tags><tag name="KHR" .../>: a hand-written list misses new vendors
    return tuple(tag.get("name").lower() for tag in _root.find("tags"))


def is_feature_struct(_root) -> bool:
    # VkPhysicalDeviceFeatures itself is chained through VkPhysicalDeviceFeatures2::features
    if _root.get("name") == "VkPhysicalDeviceFeatures":
        return True
    return "VkPhysicalDeviceFeatures2" in (_root.get("structextends") or "").split(",")


def is_core_features(source_snake: str) -> bool:
    # physical_device_vulkan_1_1_features ... physical_device_vulkan_1_4_features
    return re.search(r"vulkan_\d+_\d+_features$", source_snake) is not None


def make_feature_name(field_snake: str, source_snake: str, _vendors: tuple) -> str:
    # a feature of an extension struct gets the vendor suffix of the struct: null_descriptor -> null_descriptor_khr,
    # a number of the struct is not added, the same feature in two extension structs is an error in load()
    if source_snake == "physical_device_features" or is_core_features(source_snake):
        return field_snake
    vendor = next((f"_{v}" for v in _vendors if source_snake.endswith(f"_{v}")), "")
    return field_snake if field_snake.endswith(vendor) else field_snake + vendor


def write_definitions(_file: TextIO, _model) -> None:
    _file.write("namespace ktl::api\n{\n")
    _file.write("enum class feature : ktl::u32\n{\n")
    for feature in _model.features.values():
        _file.write(f"{feature.name},\n")
    _file.write("\n};\n}\n")


def write_meta(_file: TextIO, _model) -> None:
    _file.write(f"""namespace ktl::meta
{{
{FEATURE_META}

""")
    for feature in _model.features.values():
        if feature.struct == "physical_device_features":
            _file.write(f"""
template <>
struct feature< ktl::api::feature::{feature.name} >
{{
    static constexpr ktl::api::feature        value          = ktl::api::feature::{feature.name};
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {{}};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::{feature.struct});
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field = offsetof(ktl::api::{feature.struct}, {feature.name});
}};""")
        else:
            _file.write(f"""
template <>
struct feature< ktl::api::feature::{feature.name} >
{{
    static constexpr ktl::api::feature        value          = ktl::api::feature::{feature.name};
    static constexpr bool                     is_core        = false;
    static constexpr ktl::api::structure_type stype          = {_model.value_ref("VkStructureType", feature.stype)};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::{feature.struct});
    static constexpr ktl::usize               offsetof_stype = offsetof(ktl::api::{feature.struct}, stype);
    static constexpr ktl::usize               offsetof_pnext = offsetof(ktl::api::{feature.struct}, pnext);
    static constexpr ktl::usize               offsetof_field = offsetof(ktl::api::{feature.struct}, {feature.name});
}};""")

    _file.write("""
template< ktl::api::feature FEATURE >
constexpr any_feature
feature_cast() noexcept
{
    using feature = ktl::meta::feature< FEATURE >;
    return {
        feature::value,
        feature::is_core,
        feature::stype,
        feature::sizeof_struct,
        feature::offsetof_stype,
        feature::offsetof_pnext,
        feature::offsetof_field
    };
}

inline constexpr any_feature
match(ktl::api::feature _feature) noexcept
{
    switch (_feature)
    {
""")
    for feature in _model.features.values():
        _file.write(f"case ktl::api::feature::{feature.name}:\nreturn ktl::meta::feature_cast< ktl::api::feature::{feature.name} >();\n")
    # value outside of the enum, falling off a non-void function is UB
    _file.write("}\nstd::abort();\n}\n}")


def load(_model) -> None:
    # booleans of feature structs: the same feature is declared in physical_device_vulkan_X_Y_features
    # and in its own struct, own struct is valid both for core version and for extension
    for struct in _model.structs.values():
        if not struct.is_feature:
            continue
        # VkPhysicalDeviceFeatures has no sType
        stype = next((member.values for member in struct.members if member.name == "stype"), None)
        names = [member.name for member in struct.members if member.tppe == "VkBool32"]
        if names and stype is None and struct.name != "physical_device_features":
            raise ValueError(f"feature struct {struct.name} has no sType value")
        for name in names:
            known = _model.features.get(name)
            if known and not is_core_features(known.struct) and not is_core_features(struct.name):
                # one of them would be lost silently or bound to the other struct
                raise ValueError(f"feature {name} is declared by {known.struct} and {struct.name}")
            if known is None or (is_core_features(known.struct) and not is_core_features(struct.name)):
                _model.features[name] = Feature(name, struct.name, stype)
