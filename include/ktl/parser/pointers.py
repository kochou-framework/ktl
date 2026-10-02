from model import Function
from naming import make_cpp_name
from typing import TextIO
from commands import load_result, load_params, make_params, check_function
from api_filter import is_vulkan_type


def write_declarations(_file: TextIO, _model) -> None:
    _file.write("""
namespace ktl::api
{
""")
    for pointer in _model.funcpointers.values():
        _file.write(f"using pfn_{pointer.name} = {_model.declare(pointer.result)}(*)({make_params(_model, pointer.params)});\n")
    _file.write("}\n")


def load(_root, _model) -> None:
    for src in _root.find("types").findall("type[@category='funcpointer']"):
        if not is_vulkan_type(_root, src):
            continue
        proto = src.find("proto")
        raw = proto.findtext("name").strip()
        _model.funcpointers[raw] = Function(make_cpp_name(raw), raw, load_result(proto), load_params(src), None)


def resolve(_model) -> None:
    for pointer in _model.funcpointers.values():
        check_function(_model, pointer)
