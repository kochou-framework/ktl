from model import Bitmask
from naming import make_cpp_name
from typing import TextIO
from api_filter import is_vulkan_type


def write_declarations(_file: TextIO, _model) -> None:
    _file.write("""
namespace ktl::api
{
""")
    for bitmask in _model.bitmasks.values():
        _file.write(f"using {bitmask.name} = {_model.types[bitmask.tppe]};\n")
    _file.write("}\n")


def load(_root, _model) -> None:
    for src in _root.find("types").findall("type[@category='bitmask']"):
        # bitmask can be declared separately for vulkan and vulkansc
        if not is_vulkan_type(_root, src):
            continue
        if src.get("alias"):
            _model.bitmasks[src.get("name")] = Bitmask(make_cpp_name(src.get("name")), None, src.get("alias"))
        else:
            name = src.findtext("name").strip()
            _model.bitmasks[name] = Bitmask(make_cpp_name(name), src.findtext("type").strip(), None)


def resolve(_model) -> None:
    # an alias is declared as its target: using pipeline_create_flags_2_khr = ktl::api::flag64
    for c_name, bitmask in _model.bitmasks.items():
        if bitmask.alias:
            target = _model.find(_model.bitmasks, bitmask.alias, "bitmask", f"alias {c_name}")
            if target.alias:
                raise ValueError(f"alias {c_name} names alias {bitmask.alias}")
            bitmask.tppe = target.tppe
        _model.find(_model.types, bitmask.tppe, "type", c_name)
