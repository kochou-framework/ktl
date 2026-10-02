from model import Enum, EnumValue
from naming import make_cpp_name, make_field_name
from api_filter import is_vulkan_api, is_vulkan_type, required_names, vulkan_features, vulkan_extensions, vulkan_requires
from typing import TextIO
from dataclasses import replace


def make_vulkan_value(_number: str, _offset: str, _direction: str | None = None) -> str:
    value = 1_000_000_000 + (int(_number) - 1) * 1000 + int(_offset)
    return str(-value if _direction == "-" else value)


# bitwidth="64" of 64-bit flags, enums without it are 32-bit; a bit is (1U << n) or (1ULL << n)
_UNDERLYING_TYPES = {"32": "ktl::u32", "64": "ktl::u64"}
_BITS = {"ktl::u32": "1U", "ktl::u64": "1ULL"}
_SIGNED_TYPES = {"ktl::u32": "ktl::i32", "ktl::u64": "ktl::i64"}


def make_underlying_type(_bitwidth: str | None, _name: str) -> str:
    if (_bitwidth or "32") not in _UNDERLYING_TYPES:
        raise ValueError(f"enum {_name} has unsupported bitwidth {_bitwidth}")
    return _UNDERLYING_TYPES[_bitwidth or "32"]


def make_value(_root, _enum: Enum, _number: str | None = None) -> EnumValue:
    # <enum> of <enums> or added by <require>: value, bitpos, offset from the extension number or alias;
    # values are added before resolve, so the underlying type is unsigned here
    kinds = [kind for kind in ("value", "bitpos", "offset", "alias") if _root.get(kind)]
    if len(kinds) != 1:
        raise ValueError(f"value {_root.get('name')} of {_enum.name} has {' and '.join(kinds) or 'no value'}")
    name = make_field_name(_root.get("name"), _enum.name)
    deprecated = bool(_root.get("deprecated"))
    match kinds[0]:
        case "value":
            value = _root.get("value")
            return EnumValue(name, f"-{value}" if _root.get("dir") else value, False, deprecated)
        case "bitpos":
            return EnumValue(name, f"({_BITS[_enum.underlying_type]} << {_root.get('bitpos')})", False, deprecated)
        case "offset":
            number = _root.get("extnumber") or _number
            if not number:
                raise ValueError(f"value {_root.get('name')} of {_enum.name} has offset but no extension number")
            return EnumValue(name, make_vulkan_value(number, _root.get("offset"), _root.get("dir")), False, deprecated)
        case _:
            return EnumValue(name, make_field_name(_root.get("alias"), _enum.name), True, deprecated)


def make_values(_enum: Enum) -> list:
    # one value per name, values before aliases; an alias names the final value instead of another alias,
    # so the order of aliases in vk.xml does not matter. A name is added again by several <require> blocks:
    # every such value must be the same, otherwise the dropped one would be lost
    values = {}
    for value in sorted(_enum.values, key=lambda value: value.is_alias):
        values.setdefault(value.name, value)
    numbers = {value.name: value.value for value in values.values() if not value.is_alias}
    targets = {value.name: value.value for value in values.values() if value.is_alias}

    def final(_name: str, _chain: tuple = ()) -> str:
        if _name in numbers:
            return _name
        if _name not in targets or _name in _chain:
            raise ValueError(f"alias {_enum.name}::{(_chain + (_name,))[0]} has no value: {' -> '.join(_chain + (_name,))}")
        return final(targets[_name], _chain + (_name,))

    for value in _enum.values:
        if (numbers[final(value.value, (value.name,))] if value.is_alias else value.value) != numbers[final(value.name)]:
            raise ValueError(f"{_enum.name}::{value.name} is added with different values")
    return [replace(value, value=final(value.value, (value.name,))) if value.is_alias else value for value in values.values()]


def write_declarations(_file: TextIO, _model) -> None:
    _file.write("""namespace ktl::api
{
""")
    for enum in _model.enums.values():
        if enum.alias:
            _file.write(f"using {enum.name} = {make_cpp_name(enum.alias)};\n")
        else:
            _file.write(f"enum class {enum.name} : {enum.underlying_type};\n")
    _file.write("}\n")


def write_definitions(_file: TextIO, _model) -> None:
    _file.write("""namespace ktl::api
{
""")
    for enum in _model.enums.values():
        if enum.alias:
            continue
        _file.write(f"enum class {enum.name} : {enum.underlying_type}\n{{\n")
        values = [f"{value.name} [[deprecated]] = {value.value}" if value.is_deprecated else f"{value.name} = {value.value}"
                  for value in enum.values]
        _file.write("".join(f"{value},\n" for value in values[:-1]) + "".join(f"{value}\n" for value in values[-1:]))
        _file.write("};\n")
    _file.write("}\n")


def load(_root, _model) -> None:
    for src in _root.findall("enums"):
        if src.get("type") in ("enum", "bitmask") and src.get("name") in required_names(_root):
            enum = Enum(make_cpp_name(src.get("name")), [], make_underlying_type(src.get("bitwidth"), src.get("name")), None)
            enum.values = [make_value(value, enum) for value in src.findall("enum") if is_vulkan_api(value)]
            _model.enums[src.get("name")] = enum

    for src in _root.find("types").findall("type[@category='enum']"):
        if src.get("alias") and is_vulkan_type(_root, src):
            _model.enums[src.get("name")] = Enum(make_cpp_name(src.get("name")), [], None, src.get("alias"))

    # versions and extensions add values to existing enums: <require><enum extends="..."/>,
    # an offset is counted from the extension number unless the value has extnumber
    for block in vulkan_features(_root) + vulkan_extensions(_root):
        number = block.get("number") if block.tag == "extension" else None
        for require in vulkan_requires(block):
            for src in require.findall("enum"):
                if not src.get("extends") or not is_vulkan_api(src):
                    continue
                where = f"{src.get('name')} of {block.get('name')}"
                enum = _model.find(_model.enums, src.get("extends"), "enum", where)
                if enum.alias:
                    raise ValueError(f"{where} extends alias {src.get('extends')}")
                enum.values.append(make_value(src, enum, number))


def resolve(_model) -> None:
    for c_name, enum in _model.enums.items():
        if enum.alias:
            _model.find(_model.enums, enum.alias, "enum", f"alias {c_name}")
            continue
        # every value is added: a negative value of a version or an extension does not fit an unsigned type
        if any(not value.is_alias and value.value.startswith("-") for value in enum.values):
            enum.underlying_type = _SIGNED_TYPES[enum.underlying_type]
        enum.values = make_values(enum)
