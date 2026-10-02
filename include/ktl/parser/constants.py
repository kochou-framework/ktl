from vk_types import VkConstant
from name_rules import *
from typing import TextIO
from api_filter import is_vulkan_api, vulkan_features, vulkan_extensions, vulkan_requires


def fill_definition(_file: TextIO, _constants: list) -> None:
    for constant in _constants:
        _file.write(f"#define {constant.name} {constant.value}\n")


def fill_implementation() -> None:
    pass # nothing to do


def fill_meta() -> None:
    pass # nothing to do


def extract_constant_impl(_root) -> VkConstant | None:
    name  = make_constant(_root.get("name"))
    tppe  = make_type(_root.get("type"))
    value = _root.get("value")

    if name:
        return VkConstant(name, tppe, value)
    return None


def extract(_root) -> list:
    constants = []

    for src in _root.findall("enums[@type='constants']"):
        for constant in src.findall("enum"):
            if not is_vulkan_api(constant):
                continue
            if result := extract_constant_impl(constant):
                constants.append(result)

    # aliases are declared by features and extensions: <enum name="VK_LUID_SIZE_KHR" alias="VK_LUID_SIZE"/>
    known = {constant.name: constant for constant in constants}
    for block in vulkan_features(_root) + vulkan_extensions(_root):
        for require in vulkan_requires(block):
            for enum in require.findall("enum"):
                target = known.get(make_constant(enum.get("alias")))
                name = make_constant(enum.get("name"))
                if target and not enum.get("extends") and is_vulkan_api(enum) and name not in known:
                    known[name] = VkConstant(name, target.tppe, target.name)
                    constants.append(known[name])

    constants.sort(key=lambda c: len(c.name), reverse=True)
    return sorted(constants, key=lambda c: c.tppe)
