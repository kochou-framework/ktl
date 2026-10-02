from vk_types import VkExtension
from name_rules import *
from typing import TextIO
from cpp_meta import EXTENSION_META
from api_filter import vulkan_extensions, vulkan_requires
import enums


from dataclasses import dataclass
from typing import Union, Tuple, Optional

@dataclass
class VkDependency:
    feature: Optional[str] = None
    extension: Optional[str] = None
    version: Optional[str] = None

    def is_version(self) -> bool:
        return self.version is not None

    def get_version_tuple(self) -> Optional[Tuple[int, int]]:
        if not self.version:
            return None
        parts = self.version.replace("VK_VERSION_", "").split("_")
        return (int(parts[0]), int(parts[1]))
    
    def get_name(self) -> str:
        return self.extension or self.version or self.feature or ""


@dataclass(frozen=True)
class OrGroup:
    options: Tuple[Union[VkDependency, 'OrGroup', 'AndGroup'], ...]

@dataclass(frozen=True)
class AndGroup:
    requirements: Tuple[Union[VkDependency, 'OrGroup', 'AndGroup'], ...]

DepNode = Union[VkDependency, OrGroup, AndGroup]


def parse_depends(_depends: str) -> DepNode:
    s = _depends.replace(' ', '')
    if not s:
        return VkDependency()

    pos = [0]

    def parse_name() -> VkDependency:
        start = pos[0]
        while pos[0] < len(s) and s[pos[0]] not in '+,()':
            pos[0] += 1
        if start == pos[0]:
            raise ValueError(f"Expected name at index {pos[0]}")
        
        name = s[start:pos[0]]

        if name.startswith("VK_VERSION_"):
            return VkDependency(version=name)
        elif "::" in name: # feature boolean: VkPhysicalDevice...Features::member
            return VkDependency(feature=name)
        else:
            return VkDependency(extension=f"ktl::api::extension::{make_cpp_name(name)}")

    def parse_term() -> DepNode:
        if pos[0] >= len(s):
            raise ValueError("Unexpected EOF")
        if s[pos[0]] == '(':
            pos[0] += 1
            res = parse_expr()
            if pos[0] >= len(s) or s[pos[0]] != ')':
                raise ValueError("Expected ')'")
            pos[0] += 1
            return res
        return parse_name()

    def parse_expr() -> DepNode:
        items = [parse_term()]
        ops = []
        while pos[0] < len(s) and s[pos[0]] in '+,':
            ops.append(s[pos[0]])
            pos[0] += 1
            items.append(parse_term())

        if not ops:
            return items[0]

        # Левостороннее вычисление с одинаковым приоритетом '+' и ','
        res = items[0]
        for i, op in enumerate(ops):
            if op == ',':
                res = OrGroup((res, items[i+1])) if not isinstance(res, OrGroup) else OrGroup(res.options + (items[i+1],))
            else:  # '+'
                res = AndGroup((res, items[i+1])) if not isinstance(res, AndGroup) else AndGroup(res.requirements + (items[i+1],))
        return res

    res = parse_expr()
    if pos[0] != len(s):
        raise ValueError(f"Unexpected character '{s[pos[0]]}' at index {pos[0]}")
    return res


def make_dnf(_node: DepNode) -> list[list[VkDependency]]:
    if isinstance(_node, VkDependency):
        return [[_node]]
    if isinstance(_node, OrGroup):
        return [alternative for option in _node.options for alternative in make_dnf(option)]
    result = [[]]
    for requirement in _node.requirements:
        result = [lhs + rhs for lhs in result for rhs in make_dnf(requirement)]
    return result


def make_requirements(_depends: str | None) -> list[list[str]]:
    """
    depends expression as DNF: any of the requirements is enough, every dependency of a requirement is needed.
    Versions are monotone (1.3 implies 1.2): a requirement keeps only its highest version
    and is dropped when a weaker requirement exists. No depends is one empty requirement.
    """
    if not _depends:
        return [[]]

    requirements = []
    for alternative in make_dnf(parse_depends(_depends)):
        version = (1, 0)
        extensions = []
        for dependency in alternative:
            if dependency.feature:
                raise ValueError(f"feature dependency {dependency.feature} in {_depends!r} is not supported")
            if dependency.version:
                version = max(version, dependency.get_version_tuple())
            elif dependency.extension not in extensions:
                extensions.append(dependency.extension)
        # same extensions in another order are the same requirement, otherwise both would absorb each other
        if not any(version == other[0] and set(extensions) == set(other[1]) for other in requirements):
            requirements.append((version, extensions))

    def is_weaker(_lhs, _rhs) -> bool:
        return _lhs[0] <= _rhs[0] and set(_lhs[1]) <= set(_rhs[1])

    result = []
    for requirement in requirements:
        if any(other is not requirement and is_weaker(other, requirement) for other in requirements):
            continue
        version, extensions = requirement
        dependencies = list(extensions)
        if version > (1, 0):
            cpp_version = make_version(f"VK_VERSION_{version[0]}_{version[1]}")
            if cpp_version is None:
                raise ValueError(f"unknown version {version} in {_depends!r}")
            dependencies.insert(0, cpp_version)
        result.append(dependencies)
    return result


def fill_definition():
    pass # nothing to do


def fill_implementation(_file: TextIO, _extensions: list) -> None:
    _file.write("namespace ktl::api\n{\n")
    _file.write("enum class extension : ktl::u32\n{\n")
    for extension in _extensions:
        _file.write(f"{extension.name},\n")
    _file.write("\n};}\n")


def fill_meta(_file: TextIO, _extensions: list) -> None:
    _file.write(f"""namespace ktl::meta
{{
{EXTENSION_META}

""")
    for extension in _extensions:
        # requirements point into the dependency pool, depends and conditions point into the requirement pool
        dependencies = []
        requirements = []
        ranges = {}

        def add_requirements(_requirements: list[list[str]]) -> str:
            key = tuple(tuple(requirement) for requirement in _requirements)
            if key not in ranges:
                ranges[key] = (len(requirements), len(_requirements))
                for requirement in _requirements:
                    requirements.append(f"std::span{{dependencies}}.subspan({len(dependencies)}, {len(requirement)})"
                                        if requirement else "ktl::meta::requirement{}")
                    dependencies.extend(requirement)
            offset, count = ranges[key]
            return f"std::span{{requirements}}.subspan({offset}, {count})"

        depends = add_requirements(extension.depends)
        conditional_commands = [f"ktl::meta::conditional_command{{{command}, {add_requirements(condition)}}}"
                                for command, condition in extension.conditional_commands]
        _file.write(f"""
template <>
struct extension< ktl::api::extension::{extension.name} >
{{
    static constexpr std::string_view          raw_name    = "{extension.raw}";
    static constexpr bool                      is_instance = {"true" if extension.is_instance else "false"};
    static constexpr ktl::meta::dependency     promoted    = {{{extension.promoted}}};

    static constexpr std::array< ktl::api::command, {len(extension.commands)} > commands = {{{",".join(extension.commands)}}};

    static constexpr std::array< ktl::meta::dependency, {len(dependencies)} > dependencies = {{{",".join(dependencies)}}};
    static constexpr std::array< ktl::meta::requirement, {len(requirements)} > requirements = {{{",".join(requirements)}}};
    static constexpr std::span< ktl::meta::requirement const > depends = {depends};
    static constexpr std::array< ktl::meta::conditional_command, {len(conditional_commands)} > conditional_commands = {{{",".join(conditional_commands)}}};
}};
""")

    # unknown name (newer driver, filtered extension) must not turn into extension{} == khr_surface
    _file.write("""
inline constexpr std::optional< ktl::api::extension >
extension_from_raw(std::string_view _extension)
{
""")
    for extension in _extensions:
        _file.write(f'if (_extension == "{extension.raw}") {{ return ktl::api::extension::{extension.name}; }}\n')
    _file.write("return std::nullopt;")
    _file.write("}\n")

    _file.write("""
inline constexpr ktl::meta::any_extension
extension_cast(ktl::api::extension _extension)
{
""")
    for extension in _extensions:
        _file.write(f'if (_extension == ktl::api::extension::{extension.name}) {{ return extension_cast< ktl::api::extension::{extension.name} >(); }}\n')
    _file.write("return ktl::meta::any_extension{};")
    _file.write("}\n")

    _file.write("}\n")


def extract(root, _enums) -> list:
    extensions = []

    for extension in vulkan_extensions(root):
        name = extension.get("name")
        number = extension.get("number")
        tppe = extension.get("type")
        depends = make_requirements(extension.get("depends"))
        commands = []
        conditions = {} # command from <require depends="..."> -> depends of every such block

        for require in vulkan_requires(extension):
            enums.add_require_values(require, _enums, number)
            # commands
            for command in require.findall("command"):
                command_name = f"ktl::api::command::{make_cpp_name(command.get("name"))}"
                if require.get("depends"):
                    conditions.setdefault(command_name, []).append(require.get("depends"))
                elif command_name not in commands:
                    commands.append(command_name)

        # command required by several blocks is available when any of them is, unconditional block wins
        conditional_commands = [(command, make_requirements(",".join(f"({d})" for d in blocks)))
                                for command, blocks in conditions.items() if command not in commands]

        promoted = extension.get("promotedto") or None
        if not promoted:
            promoted = ""
        elif promoted.startswith("VK_VERSION"):
            promoted = make_version(promoted)
        else:
            promoted = f"ktl::api::extension::{make_cpp_name(promoted)}"

        extensions.append(VkExtension(make_cpp_name(name),
                                      name,
                                      True if tppe == "instance" else False,
                                      promoted,
                                      depends,
                                      commands,
                                      conditional_commands))

    return extensions
