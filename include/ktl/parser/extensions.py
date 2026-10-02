from dataclasses import dataclass
from model import Extension
from naming import make_cpp_name, make_version, parse_version
from typing import TextIO
from api_filter import vulkan_extensions, vulkan_requires


# meta/extension.hpp: primary template, any_extension and extension_cast
EXTENSION_META = """template < ktl::api::extension >
struct extension
{
    static constexpr std::string_view      raw_name    = {};
    static constexpr bool                  is_instance = {};
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >              commands             = {};
    static constexpr std::span< ktl::meta::requirement const >       depends              = {};
    static constexpr std::array< ktl::meta::conditional_command, 0 > conditional_commands = {};
};

struct any_extension
{
    std::string_view      raw_name    = {};
    bool                  is_instance = {};
    ktl::meta::dependency promoted    = {};

    // commands of <require> without depends
    std::span< ktl::api::command const > commands = {};
    // any of the requirements is enough, every dependency of a requirement is needed;
    // extension without depends has one empty requirement
    std::span< ktl::meta::requirement const > depends = {};
    // commands of <require depends="...">, available when their depends are met
    std::span< ktl::meta::conditional_command const > conditional_commands = {};
};

template < ktl::api::extension EXTENSION >
constexpr any_extension
extension_cast() noexcept
{
    using extension = ktl::meta::extension< EXTENSION >;
    return {extension::raw_name,
            extension::is_instance,
            extension::promoted,
            extension::commands,
            extension::depends,
            extension::conditional_commands};
}"""


@dataclass(frozen=True)
class Dependency:
    # a name of a depends expression, one of them is set
    feature: str | None = None    # feature boolean: VkPhysicalDevice...Features::member
    extension: str | None = None  # C name
    version: str | None = None    # VK_VERSION_1_3 or its part VK_BASE_VERSION_1_3


@dataclass(frozen=True)
class OrGroup:
    options: tuple["Dependency | OrGroup | AndGroup", ...]


@dataclass(frozen=True)
class AndGroup:
    requirements: tuple["Dependency | OrGroup | AndGroup", ...]


DepNode = Dependency | OrGroup | AndGroup


def parse_depends(_depends: str) -> DepNode:
    s = _depends.replace(' ', '')
    pos = [0]

    def parse_name() -> Dependency:
        start = pos[0]
        while pos[0] < len(s) and s[pos[0]] not in '+,()':
            pos[0] += 1
        if start == pos[0]:
            raise ValueError(f"Expected name at index {pos[0]}")

        name = s[start:pos[0]]

        if parse_version(name): # VK_VERSION_1_3 or VK_BASE_VERSION_1_3
            return Dependency(version=name)
        elif "::" in name: # feature boolean: VkPhysicalDevice...Features::member
            return Dependency(feature=name)
        else:
            return Dependency(extension=name)

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

        # left to right, '+' and ',' have the same precedence
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


def make_dnf(_node: DepNode) -> list[list[Dependency]]:
    if isinstance(_node, Dependency):
        return [[_node]]
    if isinstance(_node, OrGroup):
        return [alternative for option in _node.options for alternative in make_dnf(option)]
    result = [[]]
    for requirement in _node.requirements:
        result = [lhs + rhs for lhs in result for rhs in make_dnf(requirement)]
    return result


def make_requirements(_depends: str | None, _versions: tuple) -> list[list[tuple[int, int] | str]]:
    """
    depends expression as DNF: any of the requirements is enough, every dependency of a requirement is needed.
    Versions are monotone (1.3 implies 1.2): a requirement keeps only its highest version, (major, minor) first,
    and is dropped when a weaker requirement exists. No depends is one empty requirement.
    _versions are the vulkan versions of vk.xml, any other version is an error.
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
                if parse_version(dependency.version) not in _versions:
                    raise ValueError(f"unknown version {dependency.version} in {_depends!r}")
                version = max(version, parse_version(dependency.version))
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
            dependencies.insert(0, version)
        result.append(dependencies)
    return result


def make_dependency(_dependency: tuple[int, int] | str) -> str:
    # version or C name of an extension
    return make_version(_dependency) if isinstance(_dependency, tuple) else f"ktl::api::extension::{make_cpp_name(_dependency)}"


def make_command(_command: str) -> str:
    return f"ktl::api::command::{make_cpp_name(_command)}"


def write_definitions(_file: TextIO, _model) -> None:
    _file.write("namespace ktl::api\n{\n")
    _file.write("enum class extension : ktl::u32\n{\n")
    for extension in _model.extensions.values():
        _file.write(f"{extension.name},\n")
    _file.write("\n};}\n")


def write_meta(_file: TextIO, _model) -> None:
    _file.write(f"""namespace ktl::meta
{{
{EXTENSION_META}

""")
    for extension in _model.extensions.values():
        # requirements point into the dependency pool, depends and conditions point into the requirement pool
        dependencies = []
        requirements = []
        ranges = {}

        def add_requirements(_requirements: list[list[tuple[int, int] | str]]) -> str:
            key = tuple(tuple(make_dependency(dependency) for dependency in requirement) for requirement in _requirements)
            if key not in ranges:
                ranges[key] = (len(requirements), len(_requirements))
                for requirement in key:
                    requirements.append(f"std::span{{dependencies}}.subspan({len(dependencies)}, {len(requirement)})"
                                        if requirement else "ktl::meta::requirement{}")
                    dependencies.extend(requirement)
            offset, count = ranges[key]
            return f"std::span{{requirements}}.subspan({offset}, {count})"

        depends = add_requirements(extension.depends)
        conditional_commands = [f"ktl::meta::conditional_command{{{make_command(command)}, {add_requirements(condition)}}}"
                                for command, condition in extension.conditional_commands]
        _file.write(f"""
template <>
struct extension< ktl::api::extension::{extension.name} >
{{
    static constexpr std::string_view          raw_name    = "{extension.raw}";
    static constexpr bool                      is_instance = {"true" if extension.is_instance else "false"};
    static constexpr ktl::meta::dependency     promoted    = {{{make_dependency(extension.promoted) if extension.promoted else ""}}};

    static constexpr std::array< ktl::api::command, {len(extension.commands)} > commands = {{{",".join(make_command(command) for command in extension.commands)}}};

    static constexpr std::array< ktl::meta::dependency, {len(dependencies)} > dependencies = {{{",".join(dependencies)}}};
    static constexpr std::array< ktl::meta::requirement, {len(requirements)} > requirements = {{{",".join(requirements)}}};
    static constexpr std::span< ktl::meta::requirement const > depends = {depends};
    static constexpr std::array< ktl::meta::conditional_command, {len(conditional_commands)} > conditional_commands = {{{",".join(conditional_commands)}}};
}};
""")

    # unknown name (newer driver, filtered extension) must not turn into extension{} == khr_surface
    _file.write("""
inline constexpr std::optional< ktl::api::extension >
extension_from_raw(std::string_view _extension) noexcept
{
""")
    for extension in _model.extensions.values():
        _file.write(f'if (_extension == "{extension.raw}") {{ return ktl::api::extension::{extension.name}; }}\n')
    _file.write("return std::nullopt;")
    _file.write("}\n")

    _file.write("""
inline constexpr ktl::meta::any_extension
extension_cast(ktl::api::extension _extension) noexcept
{
    switch (_extension)
    {
""")
    for extension in _model.extensions.values():
        _file.write(f"case ktl::api::extension::{extension.name}:\nreturn extension_cast< ktl::api::extension::{extension.name} >();\n")
    # value outside of the enum, falling off a non-void function is UB
    _file.write("}\nstd::abort();\n}\n")

    _file.write("}\n")


def load(_root, _model) -> None:
    for src in vulkan_extensions(_root):
        raw = src.get("name")
        commands = []
        conditions = {} # command from <require depends="..."> -> depends of every such block
        for require in vulkan_requires(src):
            for command in require.findall("command"):
                if require.get("depends"):
                    conditions.setdefault(command.get("name"), []).append(require.get("depends"))
                elif command.get("name") not in commands:
                    commands.append(command.get("name"))

        # command required by several blocks is available when any of them is, unconditional block wins
        conditional_commands = [(command, make_requirements(",".join(f"({d})" for d in blocks), _model.versions))
                                for command, blocks in conditions.items() if command not in commands]

        promoted = src.get("promotedto") or None
        if promoted and (version := parse_version(promoted)):
            if version not in _model.versions:
                raise ValueError(f"{raw} is promoted to unknown version {promoted}")
            promoted = version

        _model.extensions[raw] = Extension(make_cpp_name(raw),
                                           raw,
                                           src.get("type") == "instance",
                                           promoted,
                                           make_requirements(src.get("depends"), _model.versions),
                                           commands,
                                           conditional_commands)


def resolve(_model) -> None:
    # promotedto, depends and conditions of commands name generated extensions only
    for raw, extension in _model.extensions.items():
        if isinstance(extension.promoted, str):
            _model.find(_model.extensions, extension.promoted, "extension", f"promotedto of {raw}")
        conditions = [(f"depends of {raw}", extension.depends)]
        conditions += [(f"depends of {command} in {raw}", condition) for command, condition in extension.conditional_commands]
        for where, requirements in conditions:
            for requirement in requirements:
                for dependency in requirement:
                    if isinstance(dependency, str):
                        _model.find(_model.extensions, dependency, "extension", where)
        for command in extension.commands + [command for command, _ in extension.conditional_commands]:
            _model.find(_model.commands, command, "command", raw)
