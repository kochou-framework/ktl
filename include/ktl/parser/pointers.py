from vk_types import VkFunction
from name_rules import *
from typing import TextIO
from commands import extract_return_type_impl, extract_command_fields_impl, make_params
from api_filter import is_vulkan_type


def extract_pointer_impl(_root) -> VkFunction | None:
    proto = _root.find("proto")
    tppe = extract_return_type_impl(proto)
    name = proto.find("name").text.strip()
    fields = extract_command_fields_impl(_root)
    return VkFunction(f"pfn_{make_cpp_name(name)}", name, tppe, fields, None)


def fill_definition(_file: TextIO, _pointers: list) -> None:
    _file.write("""
namespace ktl::api
{
""")
    for pointer in _pointers:
        if pointer.alias:
            _file.write(f"using {pointer.pfn} = {pointer.alias};\n")
        else:
            _file.write(f"using {pointer.pfn} = {pointer.tppe}(*)({make_params(pointer.fields)});\n")
    _file.write("}\n")


def fill_implementation():
    pass # nothing to do


def extract(_root) -> list:
    pointers = []

    types = _root.find("types")
    for pointer in types.findall("type[@category='funcpointer']"):
        if not is_vulkan_type(_root, pointer):
            continue
        if result := extract_pointer_impl(pointer):
            pointers.append(result)

    return pointers
