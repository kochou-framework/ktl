from model import Handle
from naming import make_cpp_name
from api_filter import is_vulkan_type
from typing import TextIO


# primary template of meta/handle.hpp, specialized for every handle
HANDLE_META = """template < typename T >
struct handle_meta
{
    using parent = T::parent;
    using type   = T::type;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = 0
    };
};"""


def write_declarations(_file: TextIO, _model) -> None:
    _file.write("""namespace ktl::api
{
""")
    for handle in _model.handles.values():
        if handle.alias:
            _file.write(f"using {handle.name} = {make_cpp_name(handle.alias)};\n\n")
        else:
            _file.write(f"""struct opaque_{handle.name};
using {handle.name} = opaque_{handle.name} *;
""")
    _file.write("}\n")


def write_meta(_file: TextIO, _model) -> None:
    # ktl::meta as the other meta, handle types are in ktl::api
    _file.write(f"""namespace ktl::meta
{{
{HANDLE_META}
""")
    for handle in _model.handles.values():
        if handle.alias:
            continue
        parent = f"ktl::api::opaque_{make_cpp_name(handle.parent)}" if handle.parent else "void"
        _file.write(f"""
template <>
struct handle_meta< ktl::api::{handle.name} >
{{
    using parent = {parent};
    using type   = ktl::api::opaque_{handle.name};
    enum : std::underlying_type_t< ktl::api::object_type >
    {{
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >({_model.value_ref("VkObjectType", handle.object)})
    }};
}};
""")
    _file.write("}\n")

    _file.write("""namespace std
{""")
    for handle in _model.handles.values():
        if handle.alias:
            continue
        _file.write(f"""
template <>
struct formatter< ktl::api::{handle.name}, char >
{{
    constexpr auto
    parse(format_parse_context & ctx)
    {{
        return ctx.begin();
    }}

    template < typename FormatContext >
    auto
    format(const ktl::api::{handle.name} & _handle, FormatContext & ctx) const
    {{
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{{:x}}", ptr);
    }}
}};""")
    _file.write("}")


def load(_root, _model) -> None:
    for src in _root.find("types").findall("type[@category='handle']"):
        if not is_vulkan_type(_root, src):
            continue
        if src.get("alias"):
            _model.handles[src.get("name")] = Handle(make_cpp_name(src.get("name")), None, None, False, src.get("alias"))
        else:
            name = src.findtext("name").strip()
            _model.handles[name] = Handle(make_cpp_name(name), src.get("parent"), src.get("objtypeenum"),
                                          src.findtext("type") == "VK_DEFINE_HANDLE", None)


def resolve(_model) -> None:
    for c_name, handle in _model.handles.items():
        if handle.alias:
            _model.find(_model.handles, handle.alias, "handle", f"alias {c_name}")
            continue
        # handle_meta::parent is the opaque type of the parent, an alias has none
        if handle.parent and _model.find(_model.handles, handle.parent, "handle", f"parent of {c_name}").alias:
            raise ValueError(f"parent of {c_name} is alias {handle.parent}")
        if not handle.object:
            raise ValueError(f"handle {c_name} has no objtypeenum")
        _model.check_value("VkObjectType", handle.object, f"objtypeenum of {c_name}")
