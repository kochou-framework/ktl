from vk_types import VkHandle
from name_rules import *
from api_filter import is_vulkan_type
from typing import TextIO
from cpp_meta import HANDLE_META


def opaque_name_rule(src: str) -> str | None:
    if src is None:
        return None
    return f"opaque_{src}"


def pointer_name_rule(src: str) -> str | None:
    if src is None:
        return None
    return f"{src}"


def extract_handle_name_impl(_root) -> str | None:
    name = _root.find("name")
    if name is not None and name.text:
        return make_cpp_name(name.text.strip())
    return None


def extract_parent_impl(_root) -> str:
    parent = _root.get("parent")
    if parent:
        return opaque_name_rule(make_cpp_name(parent))
    return "void"


def extract_object_impl(_root) -> str | None:
    object = _root.get("objtypeenum")
    if object:
        return make_field_name(object, "object_type")
    return None


def extract_handle_impl(_root, _name) -> VkHandle:
    opaque  = opaque_name_rule(_name)
    pointer = pointer_name_rule(_name)
    parent  = extract_parent_impl(_root)
    object  = extract_object_impl(_root)
    return VkHandle(_name, opaque, pointer, parent, object, None)


def fill_definition(_file: TextIO, _handles: list) -> None:
    _file.write("""namespace ktl::api
{
""")
    for handle in _handles:
        if handle.alias:
            _file.write(f"using {handle.name} = {handle.alias};\n\n")
        else:
            _file.write(f"""struct {handle.opaque};
using {handle.pointer} = {handle.opaque} *;
""")
    _file.write("}\n")

def fill_implementation() -> None:
    pass

def fill_meta(_file: TextIO, _handles: list) -> None:
    _file.write(f"""namespace ktl::api
{{
{HANDLE_META}
""")
    for handle in _handles:
        if handle.alias:
            continue
        else:
            _file.write(f"""
template <>
struct handle_meta< {handle.pointer} >
{{
    using parent = {handle.parent};
    using type   = {handle.opaque};
    enum : std::underlying_type_t< ktl::api::object_type >
    {{
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::{handle.object})
    }};
}};
""")
    _file.write("}\n")

    _file.write("""namespace std
{""")
    for handle in _handles:
        if handle.alias:
            continue
        _file.write(f"""
template <>
struct formatter< ktl::api::{handle.pointer}, char >
{{
    constexpr auto
    parse(format_parse_context & ctx)
    {{
        return ctx.begin();
    }}

    template < typename FormatContext >
    auto
    format(const ktl::api::{handle.pointer} & _handle, FormatContext & ctx) const
    {{
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{{:x}}", ptr);
    }}
}};""")
    _file.write("}")


def extract(_root) -> list:
    handles = []

    types = _root.find("types")
    for src in types.findall("type[@category='handle']"):
        if not is_vulkan_type(_root, src):
            continue
        alias = make_cpp_name(src.get("alias"))
        if alias:
            handles.append(VkHandle(make_cpp_name(src.get("name")), None, None, None, None, alias))
        else:
            handles.append(extract_handle_impl(src, extract_handle_name_impl(src)))

    return handles
