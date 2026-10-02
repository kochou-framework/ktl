from collections import deque
from model import Struct, Member
from naming import make_cpp_name
from typing import TextIO
from decl import parse_decl
from api_filter import is_vulkan_api, is_vulkan_type
import features


def load_member(_root, _struct: str, _is_feature: bool, _vendors: tuple) -> Member:
    decl = parse_decl(_root)
    name = make_cpp_name(decl.name)
    if _is_feature and decl.tppe == "VkBool32":
        name = features.make_feature_name(name, _struct, _vendors)
    return Member(name, decl.tppe, decl.const, decl.array, decl.bitfield, _root.get("optional") == "true", _root.get("values"))


def sort_by_dependencies(_structs: dict) -> dict:
    # Kahn's algorithm: a struct goes after the struct it aliases and the structs of its members by value,
    # a pointer needs only the declaration from common.hpp
    dependents = {name: [] for name in _structs}
    degree = dict.fromkeys(_structs, 0)
    for name, struct in _structs.items():
        dependencies = {struct.alias} if struct.alias else set()
        dependencies |= {member.tppe for member in struct.members if member.pointer_count == 0}
        for dependency in dependencies & _structs.keys():
            dependents[dependency].append(name)
            degree[name] += 1

    queue = deque(name for name in _structs if degree[name] == 0)
    result = {}
    while queue:
        current = queue.popleft()
        result[current] = _structs[current]
        for dependent in dependents[current]:
            degree[dependent] -= 1
            if degree[dependent] == 0:
                queue.append(dependent)

    if len(result) != len(_structs):
        raise ValueError(f"cyclic dependencies of structs: {[name for name in _structs if name not in result]}")
    return result


def write_declarations(_file: TextIO, _model) -> None:
    _file.write("""namespace ktl::api
{
""")
    for struct in _model.structs.values():
        if struct.alias:
            _file.write(f"using {struct.name} = {make_cpp_name(struct.alias)};\n")
        else:
            _file.write(f"{'union' if struct.is_union else 'struct'} {struct.name};\n")
    _file.write("}\n")


def write_definitions(_file: TextIO, _model) -> None:
    _file.write("""namespace ktl::api
{
""")
    for struct in _model.structs.values():
        if struct.alias:
            continue
        _file.write(f"{'union' if struct.is_union else 'struct'} {struct.name}\n{{\n")
        for member in struct.members:
            declaration = _model.declare(member)
            # a union has no default member initializers, though its pointers can be optional
            if member.is_optional and not struct.is_union:
                declaration += " = {}"
            elif member.values and not struct.is_union:
                declaration += f" = {_model.value_ref(member.tppe, member.values)}"
            _file.write(f"{declaration};\n")
        _file.write("};\n")
    _file.write("}\n")


def load(_root, _model) -> None:
    for src in _root.find("types").findall("type"):
        if src.get("category") not in ("struct", "union") or not is_vulkan_type(_root, src):
            continue
        name = make_cpp_name(src.get("name"))
        is_union = src.get("category") == "union"
        if src.get("alias"):
            _model.structs[src.get("name")] = Struct(name, [], is_union, False, src.get("alias"))
            continue
        is_feature = not is_union and features.is_feature_struct(src)
        members = [load_member(member, name, is_feature, _model.vendors) for member in src.findall("member") if is_vulkan_api(member)]
        _model.structs[src.get("name")] = Struct(name, members, is_union, is_feature, None)


def resolve(_model) -> None:
    for c_name, struct in _model.structs.items():
        if struct.alias:
            _model.find(_model.structs, struct.alias, "struct", f"alias {c_name}")
            continue
        for member in struct.members:
            where = f"{c_name}::{member.name}"
            _model.check_member(member, where)
            if member.values:
                _model.check_value(member.tppe, member.values, where)
    _model.structs = sort_by_dependencies(_model.structs)
