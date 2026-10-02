from vk_types import VkEnum, VkEnumField
from name_rules import *
from utils import make_vulkan_value
from api_filter import is_vulkan_api, is_vulkan_type, excluded_names
from typing import TextIO
from dataclasses import replace


def extract_field_impl(_root, _name, _underling_type: str) -> VkEnumField:
    name       = make_field_name(_root.get("name"), _name)
    alias      = make_field_name(_root.get("alias"), _name)
    value      = _root.get("value")
    bitpos     = _root.get("bitpos")
    deprecated = True if _root.get("deprecated") else False

    if value:
        return VkEnumField(name, value, False, deprecated)
    if bitpos:
        return VkEnumField(name, make_bitpos(bitpos, _underling_type), False, deprecated)
    if alias:
        return VkEnumField(name, alias, True, deprecated)
    raise ValueError(f"value {_root.get('name')} of {_name} has no value, bitpos or alias")


def extract_enum_impl(_root) -> VkEnum | None:
    name = make_cpp_name(_root.get("name"))
    # signed type depends on the values that features and extensions add as well: update_underlying_types()
    underling_type = make_underling_type(_root.get("bitwidth"), True)
    fields = [extract_field_impl(src, name, underling_type) for src in _root.findall("enum") if is_vulkan_api(src)]
    return VkEnum(name, fields, underling_type, None)


_SIGNED_TYPES = {"ktl::u32": "ktl::i32", "ktl::u64": "ktl::i64"}


def update_underlying_types(_enums: list) -> None:
    # after every value is added: a negative value of a feature or an extension does not fit an unsigned type
    for enum in _enums:
        if not enum.alias and any(not field.is_alias and field.value.startswith("-") for field in enum.fields):
            enum.underling_type = _SIGNED_TYPES.get(enum.underling_type, enum.underling_type)


def make_fields(_enum: VkEnum) -> list:
    # one field per name, values before aliases; an alias names the final value instead of another alias,
    # so the order of aliases in vk.xml does not matter. A name is added again by several <require> blocks:
    # every such field must mean the same value, otherwise the dropped one would be lost
    fields = list(dict.fromkeys(sorted(_enum.fields, key=lambda field: field.is_alias)))
    values = {field.name: field.value for field in fields if not field.is_alias}
    targets = {field.name: field.value for field in fields if field.is_alias}

    def final(_name: str, _chain: tuple = ()) -> str:
        if _name in values:
            return _name
        if _name not in targets or _name in _chain:
            raise ValueError(f"alias {_enum.name}::{(_chain + (_name,))[0]} has no value: {' -> '.join(_chain + (_name,))}")
        return final(targets[_name], _chain + (_name,))

    for field in _enum.fields:
        if (values[final(field.value, (field.name,))] if field.is_alias else field.value) != values[final(field.name)]:
            raise ValueError(f"{_enum.name}::{field.name} is added with different values")
    return [replace(field, value=final(field.value, (field.name,))) if field.is_alias else field for field in fields]


def fill_definition(_file: TextIO, _enums: list) -> None:
    _file.write("""namespace ktl::api
{
""")
    for enum in _enums:
        if enum.alias:
            _file.write(f"using {enum.name} = {enum.alias};\n")
        else:
            _file.write(f"enum class {enum.name} : {enum.underling_type};\n")
    _file.write("}\n")


def fill_implementation(_file: TextIO, _enums: list) -> None:
    _file.write("""namespace ktl::api
{
""")
    for enum in _enums:
        if enum.alias:
            continue
        else:
            _file.write(f"enum class {enum.name} : {enum.underling_type}\n{{\n")
            valid_fields = make_fields(enum)
            for field in valid_fields:
                if field.is_deprecated:
                    _file.write(f"{field.name} [[deprecated]] = {field.value}")
                else:
                    _file.write(f"{field.name} = {field.value}")
                if field != valid_fields[-1]:
                    _file.write(",")
                _file.write("\n")
            _file.write("};\n")
    _file.write("}\n")


def add_require_values(_require, _enums: list, _number: str | None = None) -> None:
    # values that features and extensions add to existing enums: <require><enum extends="..."/>
    # _number is the extension number, used when the value has no extnumber of its own
    for enum in _require.findall("enum"):
        extend = enum.get("extends")
        if not extend or not is_vulkan_api(enum):
            continue
        target = next((e for e in _enums if e.name == make_cpp_name(extend)), None)
        if not target:
            continue
        offset = enum.get("offset")
        value = enum.get("value")
        direction = enum.get("dir")
        bitpos = enum.get("bitpos")
        alias = make_field_name(enum.get("alias"), target.name)
        deprecated = bool(enum.get("deprecated"))
        field_name = make_field_name(enum.get("name"), target.name)
        if offset:
            field_value = make_vulkan_value(enum.get("extnumber") or _number, offset, direction)
            target.fields.append(VkEnumField(field_name, field_value, False, deprecated))
        if value:
            if direction:
                value = f"-{value}"
            target.fields.append(VkEnumField(field_name, value, False, deprecated))
        if bitpos:
            target.fields.append(VkEnumField(field_name, make_bitpos(bitpos, target.underling_type), False, deprecated))
        if alias:
            target.fields.append(VkEnumField(field_name, alias, True, deprecated))


def extract(root) -> list:
    enums = []

    for src in root.findall("enums"):
        if src.get("type") in ("enum", "bitmask") and src.get("name") not in excluded_names(root):
            if result := extract_enum_impl(src):
                enums.append(result)

    return enums


def extract_aliased(root) -> list:
    enums = []

    types = root.find("types")
    for src in types.findall("type[@category='enum']"):
        if not is_vulkan_type(root, src):
            continue
        if alias := make_cpp_name(src.get("alias")):
            enums.append(VkEnum(make_cpp_name(src.get("name")), None, None, alias))

    return enums
