from model import Constant
from naming import FIXED_TYPES, make_constant
from typing import TextIO
from api_filter import is_vulkan_api, required_names, vulkan_features, vulkan_extensions, vulkan_requires


def write_declarations(_file: TextIO, _model) -> None:
    constants = sorted(_model.constants.values(), key=lambda c: len(c.name), reverse=True)
    for constant in sorted(constants, key=lambda c: c.tppe):
        _file.write(f"#define {constant.name} {constant.value}\n")


def load(_root, _model) -> None:
    for src in _root.findall("enums[@type='constants']"):
        for constant in src.findall("enum"):
            if not is_vulkan_api(constant) or constant.get("name") not in required_names(_root):
                continue
            name = constant.get("name")
            if not make_constant(name) or constant.get("type") not in FIXED_TYPES:
                raise ValueError(f"constant {name} of type {constant.get('type')} is not supported")
            _model.constants[name] = Constant(make_constant(name), FIXED_TYPES[constant.get("type")], constant.get("value"))

    # aliases are declared by features and extensions: <enum name="VK_LUID_SIZE_KHR" alias="VK_LUID_SIZE"/>,
    # other aliases of a <require> name values of enums or SPEC_VERSION / EXTENSION_NAME of extensions
    for block in vulkan_features(_root) + vulkan_extensions(_root):
        for require in vulkan_requires(block):
            for enum in require.findall("enum"):
                target = _model.constants.get(enum.get("alias"))
                name = enum.get("name")
                if target and not enum.get("extends") and is_vulkan_api(enum) and name not in _model.constants:
                    _model.constants[name] = Constant(make_constant(name), target.tppe, target.name)
