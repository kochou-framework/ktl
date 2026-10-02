from typing import TextIO
from cpp_meta import FEATURE_META
from api_filter import vulkan_features, vulkan_requires
import enums


def fill_definition():
    pass # nothing to do


def fill_implementation(_file: TextIO, _features_dependencies: list) -> None:
    _file.write("namespace ktl::api\n{\n")
    _file.write("enum class feature : ktl::u32\n{\n")
    for feature in _features_dependencies:
        _file.write(f"{feature.name},\n")
    _file.write("\n};\n}\n")


def fill_meta(_file: TextIO, _features: list) -> None:
    _file.write(f"""namespace ktl::meta
{{
{FEATURE_META}

""")
    for feature in _features:
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
    static constexpr ktl::api::structure_type stype          = {feature.stype};
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
    for feature in _features:
        _file.write(f"case ktl::api::feature::{feature.name}:\nreturn ktl::meta::feature_cast< ktl::api::feature::{feature.name} >();\n")
    # value outside of the enum, falling off a non-void function is UB
    _file.write("}\nstd::abort();\n}\n}")


def add_core_enum_values(_root, _enums: list) -> None:
    # core versions (<feature>) add values to existing enums, extensions do the same in extensions.extract
    for feature in vulkan_features(_root):
        for require in vulkan_requires(feature):
            enums.add_require_values(require, _enums)
