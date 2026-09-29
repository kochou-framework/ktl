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


def make_feature_enum_name(field_snake: str, source_snake: str) -> str:
    if source_snake == "physical_device_features" or re.search(r"vulkan\d+features$", source_snake):
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


def extract_struct_field_impl(_root, _name) -> VkStructField:
    decl = parse_decl(_root)
    type_res = make_decl_type(decl.tppe)
    name_str = make_cpp_name(decl.name)
    if type_res == "ktl::api::bool32" and "features" in _name:
        name_str = make_feature_enum_name(name_str, _name)

    is_optional = _root.get("optional") == "true"
    default_value = _root.get("values")
    if default_value:
        type_str = make_cpp_name(decl.tppe)
        default_value = f"ktl::api::{type_str}::{make_field_name(default_value, type_str)}"
    if is_optional:
        default_value = "{}"

    return VkStructField(type_res, name_str, is_optional, decl.const, decl.array, decl.bitfield, default_value)


def extract_struct_impl(_root, _unique) -> tuple:
    name = make_cpp_name(_root.get("name"))
    if is_vulkan_video(name):
        return None, None

    features = []
    fields = []
    for field in _root.findall("member"):
        if not field.get("api") == "vulkansc":
            result = extract_struct_field_impl(field, name)
            fields.append(result)
            if result.tppe == "ktl::api::bool32" and "features" in name:
                feature = result.name # make_feature_enum_name(result.name, name)
                if feature not in _unique:
                    _unique.add(feature)
                    # print(name, feature)
                    features.append(VkFeature(result.name, name, name))

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
    features = []
    unique = set()

    types = _root.find("types")
    for src in types.findall("type"):
        if src.get("category") == "struct":
            if alias := make_cpp_name(src.get("alias")):
                name = make_cpp_name(src.get("name"))
                if not is_vulkan_video(name):
                    structs.append(VkStruct(name, [], False, alias))
            else:
                result, ff = extract_struct_impl(src, unique)
                if result:
                    structs.append(result)
                    features += ff

        elif src.get("category") == "union":
            result, _ = extract_struct_impl(src, unique)
            if result:
                result.is_union = True
                structs.append(result)
    return sort_by_dependencies(structs), features
