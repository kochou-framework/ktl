from vk_types import VkEnumField
from name_rules import *
from utils import is_vulkan_video, make_vulkan_value
from typing import TextIO
from cpp_meta import FEATURE_META


def process_enums(_root, _enums) -> str:
    extension = None

    for enum in _root.findall("enum"):
        extend = enum.get("extends")
        if extend is not None:
            target = next((e for e in _enums if e.name == make_cpp_name(extend)), None)
            if not target:
                continue
            offset = enum.get("offset")
            number = enum.get("extnumber")
            value = enum.get("value")
            direction = enum.get("dir")
            bitpos = enum.get("bitpos")
            alias = make_field_name(enum.get("alias"), target.name)
            deprecated = bool(enum.get("deprecated"))
            if offset:
                field_name = make_field_name(enum.get("name"), target.name)
                field_value = make_vulkan_value(number, offset)
                target.fields.append(VkEnumField(field_name, field_value, False, deprecated))
                if target.name == "structure_type":
                    extension = f"ktl::api::structure_type::{field_name}"
            if value:
                if direction:
                    value =f"-{value}"
                field_name = make_field_name(enum.get("name"), target.name)
                target.fields.append(VkEnumField(field_name, value, False, deprecated))
            if bitpos:
                field_name = make_field_name(enum.get("name"), target.name)
                bitvalue = make_bitpos(bitpos, target.underling_type)
                target.fields.append(VkEnumField(field_name, bitvalue, False, deprecated))
            if alias:
                field_name = make_field_name(enum.get("name"), target.name)
                target.fields.append(VkEnumField(field_name, alias, True, deprecated))
    return extension


def process_commands(_root, _commands) -> list:
    for command in _root.findall("command"):
        pass


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
        if feature.stype == "physical_device_texture_compression_astchdr_features":
            feature.stype = "physical_device_texture_compression_astc_hdr_features"
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
    static constexpr ktl::api::structure_type stype          = ktl::api::structure_type::v_{feature.stype};
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

inline any_feature
match(ktl::api::feature _feature) noexcept
{
    switch (_feature)
    {
""")
    for feature in _features:
        _file.write(f"case ktl::api::feature::{feature.name}:\nreturn ktl::meta::feature_cast< ktl::api::feature::{feature.name} >();\n")
    _file.write("}}}")

def extract(_root, _enums, _commands) -> list:
    features = []

    for feature in _root.findall("feature"):
        name = make_cpp_name(feature.get("name"))
        if is_vulkan_video(name):
            continue

        extensions = []
        for require in feature.findall("require"):
            if extension := process_enums(require, _enums):
                extensions.append(extension)
            #commands = process_commands(require, _commands)

    return features
