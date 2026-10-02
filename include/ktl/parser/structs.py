from vk_types import VkStruct, VkStructField, VkFeature
from name_rules import *
from utils import is_vulkan_video
from typing import TextIO
from decl import parse_decl, make_decl_type, make_declaration
from utils import sort_by_dependencies

import re

_VENDORS = (
    "khr", "khx", "ext",
    "amd", "amdx",
    "nv", "nvx",
    "intel", "img", "arm", "qcom", "viv", "vsi",
    "android", "fuchsia", "ggp", "google", "chromium",
    "tizen", "qnx", "ohos",
    "fsl", "nxp", "brcm", "mesa", "lunarg", "nzxt",
    "samsung", "sec", "renderdoc", "nn", "mvk",
    "huawei", "valve", "juice", "fb", "rastergrid",
    "msft", "shady", "fredemmott", "mtk", "openxr",
    "kdab"
)
_BIT_WIDTHS = {"8", "16", "32", "64"}


def is_feature_struct(_root) -> bool:
    # VkPhysicalDeviceFeatures itself is chained through VkPhysicalDeviceFeatures2::features
    if _root.get("name") == "VkPhysicalDeviceFeatures":
        return True
    return "VkPhysicalDeviceFeatures2" in (_root.get("structextends") or "").split(",")


def is_core_features(source_snake: str) -> bool:
    # physical_device_vulkan_11features ... physical_device_vulkan_14features
    return re.search(r"vulkan_\d+features$", source_snake) is not None


def make_feature_enum_name(field_snake: str, source_snake: str) -> str:
    if source_snake == "physical_device_features" or is_core_features(source_snake):
        return field_snake

    result = field_snake
    vendor = next((f"_{v}" for v in _VENDORS if source_snake.endswith(f"_{v}")), "")
    base_for_nums = source_snake[:-len(vendor)] if vendor else source_snake
    src_nums = re.findall(r'\d+', base_for_nums)
    field_nums = set(re.findall(r'\d+', result))
    extra_nums = [n for n in src_nums if n not in field_nums and n not in _BIT_WIDTHS]
    
    if extra_nums: result += f"_{extra_nums[0]}"
    if vendor and not result.endswith(vendor): result += vendor
    return make_cpp_name(result)


def extract_struct_field_impl(_root, _name, _is_feature) -> VkStructField:
    decl = parse_decl(_root)
    type_res = make_decl_type(decl.tppe)
    name_str = make_cpp_name(decl.name)
    if type_res == "ktl::api::bool32" and _is_feature:
        name_str = make_feature_enum_name(name_str, _name)

    is_optional = _root.get("optional") == "true"
    default_value = _root.get("values")
    if default_value:
        type_str = make_cpp_name(decl.tppe)
        default_value = f"ktl::api::{type_str}::{make_field_name(default_value, type_str)}"
    if is_optional:
        default_value = "{}"

    return VkStructField(type_res, name_str, is_optional, decl.const, decl.array, decl.bitfield, default_value)


def extract_struct_impl(_root) -> tuple:
    name = make_cpp_name(_root.get("name"))
    if is_vulkan_video(name):
        return None, None

    is_feature = is_feature_struct(_root)
    feature_names = []
    fields = []
    for field in _root.findall("member"):
        if not field.get("api") == "vulkansc":
            result = extract_struct_field_impl(field, name, is_feature)
            fields.append(result)
            if result.tppe == "ktl::api::bool32" and is_feature:
                feature_names.append(result.name)

    # stype is taken from values="VK_STRUCTURE_TYPE_..." of sType, VkPhysicalDeviceFeatures has no sType
    stype = next((field.default_value for field in fields if field.name == "stype"), None)
    if feature_names and stype is None and name != "physical_device_features":
        raise ValueError(f"feature struct {name} has no sType value")
    features = [VkFeature(feature, stype, name) for feature in feature_names]

    return VkStruct(name, fields, False, None), features


def fill_definition(_file: TextIO, _structs: list) -> None:
    _file.write("""namespace ktl::api
{
""")
    for struct in _structs:
        if struct.is_union:
            _file.write(f"union {struct.name};\n")
        else:
            if struct.alias:
                _file.write(f"using {struct.name} = {struct.alias};\n")
            else:
                _file.write(f"struct {struct.name};\n")
    _file.write("}\n")


def fill_implementation(_file: TextIO, _structs: list) -> None:
    _file.write("""namespace ktl::api
{
""")
    for struct in _structs:
        if struct.is_union:
            _file.write(f"union {struct.name}\n{{\n")
            for field in struct.fields:
                _file.write(f"{make_declaration(field.tppe, field.const, field.name, field.array)};\n")
            _file.write("};\n")
        else:
            if struct.alias:
                continue

            _file.write(f"struct {struct.name}\n{{\n")
            for field in struct.fields:
                act = make_declaration(field.tppe, field.const, field.name, field.array, field.bitfield)
                if field.default_value:
                    act += f" = {field.default_value}"
                _file.write(f"{act};\n")
            _file.write("};\n")
    _file.write("}\n")


def extract(_root) -> tuple:
    structs = []
    features = {}

    types = _root.find("types")
    for src in types.findall("type"):
        if src.get("category") == "struct":
            if alias := make_cpp_name(src.get("alias")):
                name = make_cpp_name(src.get("name"))
                if not is_vulkan_video(name):
                    structs.append(VkStruct(name, [], False, alias))
            else:
                result, ff = extract_struct_impl(src)
                if result:
                    structs.append(result)
                    for feature in ff:
                        # same feature is declared in physical_device_vulkan_XYfeatures and in its own struct:
                        # own struct is valid both for core version and for extension
                        known = features.get(feature.name)
                        if known is None or (is_core_features(known.struct) and not is_core_features(feature.struct)):
                            features[feature.name] = feature

        elif src.get("category") == "union":
            result, _ = extract_struct_impl(src)
            if result:
                result.is_union = True
                structs.append(result)
    return sort_by_dependencies(structs), list(features.values())
