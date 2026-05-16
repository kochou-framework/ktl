from vk_types import VkEnumField, VkEntension, VkDependency
from name_rules import *
from utils import is_vulkan_video, make_vulkan_value
from typing import TextIO
from cpp_meta import EXTENSION_META


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
        else:
            cpp_name = f"ktl::api::extension::{make_cpp_name(name)}" if 'make_cpp_name' in globals() else name
            return VkDependency(extension=cpp_name)

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


def resolve_for_version(node: DepNode, target: Tuple[int, int]) -> Optional[list[str]]:
    if isinstance(node, VkDependency):
        # Обработка атомарной зависимости
        if node.is_version():
            # Проверяем версию
            ver_tuple = node.get_version_tuple()
            if ver_tuple and target >= ver_tuple:
                return []  # Версия покрыта, требований нет
            return None  # Версия не покрыта, эта ветка не работает
        else:
            # Расширение или фича: требует явного включения
            name = node.get_name()
            if name:
                return [name]
            return []  # Пустая зависимость считаем выполненной

    if isinstance(node, AndGroup):
        reqs = []
        for child in node.requirements:
            child_reqs = resolve_for_version(child, target)
            if child_reqs is None:
                return None  # Любое невыполненное условие AND ломает всю группу
            reqs.extend(child_reqs)
        return reqs

    if isinstance(node, OrGroup):
        best = None
        for child in node.options:
            child_reqs = resolve_for_version(child, target)
            if child_reqs is not None:
                # Предпочитаем более короткие списки (версии дают [], расширения [ext])
                if best is None or len(child_reqs) < len(best):
                    best = child_reqs
                if len(best) == 0:
                    return []  # Версия покрыла условие, дальше не ищем
        return best
    
    return None  # Неизвестный тип узла

def extract_requirements(depends_str: str, versions: list[Tuple[int, int]]) -> dict[str, list[str]]:
    """Возвращает словарь { версия: [требуемые расширения] }."""
    ast = parse_depends(depends_str)
    if ast == "":
        return {f"VK_VERSION_{v[0]}_{v[1]}": [] for v in versions}

    result = {}
    for v in versions:
        key = f"version_{v[0]}_{v[1]}"
        reqs = resolve_for_version(ast, v)
        result[key] = reqs if reqs is not None else ["UNSATISFIABLE"]
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
        deps = ""
        if extension.deps:
            deps = "{"
            for version, value in extension.deps.items():
                deps += f"{{ktl::api::{version}, {"false" if value == ['UNSATISFIABLE'] else "true"}, {len(value)}, {{"
                if value != ['UNSATISFIABLE']:
                    for dep in value:
                        deps += f"{dep},"
                    if deps[-1] == ',':
                        deps = deps[:-1]
                deps += "}},"
            if deps[-1] == ',':
                deps = deps[:-1]
            deps += "}"
        commands = ""
        for cmd in extension.commands:
            commands += f"{cmd},"
        if len(commands) > 0 and commands[-1] == ',':
            commands = commands[:-1]
        _file.write(f"""
template <>
struct extension< ktl::api::extension::{extension.name} >
{{
    static constexpr std::string_view          raw_name    = "{extension.raw}";
    static constexpr bool                      is_instance = {"true" if extension.is_instance else "false"};
    static constexpr ktl::meta::dependency     promoted    = {{{extension.promoted}}};

    static constexpr std::array< ktl::api::command, {len(extension.commands)} > commands = {{{commands}}};
    static constexpr std::array< ktl::meta::version_deps, {len(extension.deps)} > deps   = {{{deps}}};
}};
""")

    _file.write("""
inline constexpr ktl::api::extension
extension_from_raw(std::string_view _extension)
{
""")
    for extension in _extensions:
        _file.write(f'if (_extension == "{extension.raw}") {{ return ktl::api::extension::{extension.name}; }}\n')
    # TODO
    _file.write("return ktl::api::extension{};")
    _file.write("}\n")

    _file.write("""
inline constexpr ktl::meta::any_extension
extension_cast(ktl::api::extension _extension)
{
""")
    for extension in _extensions:
        _file.write(f'if (_extension == ktl::api::extension::{extension.name}) {{ return extension_cast< ktl::api::extension::{extension.name} >(); }}\n')
    # TODO
    _file.write("return ktl::meta::any_extension{};")
    _file.write("}\n")

    _file.write("}\n")


def extract(root, enums) -> list:
    extensions = []

    for extension in root.findall(".//extension"):
        name = extension.get("name")
        if is_vulkan_video(name):
            continue

        number = extension.get("number")
        tppe = extension.get("type")
        depends = extension.get("depends")
        commands = []
        req = ""
        if depends:
            versions = [(1,0), (1,1), (1,2), (1,3), (1,4)]
            req = extract_requirements(depends, versions)

        for require in extension.findall("require"):
            # enums
            for enum in require.findall("enum"):
                extend = enum.get("extends")
                if extend:
                    target = next((e for e in enums if e.name == make_cpp_name(extend)), None)
                    if not target:
                        continue
                    offset = enum.get("offset")
                    value = enum.get("value")
                    direction = enum.get("dir")
                    bitpos = enum.get("bitpos")
                    alias = make_field_name(enum.get("alias"), target.name)
                    deprecated = bool(enum.get("deprecated"))
                    if offset:
                        field_name = make_field_name(enum.get("name"), target.name)
                        field_value = make_vulkan_value(number, offset)
                        target.fields.append(VkEnumField(field_name, field_value, False, deprecated))
                    if value:
                        if direction:
                            value =f"-{value}"
                        field_name = make_field_name(enum.get("name"), target.name)
                        target.fields.append(VkEnumField(field_name, value, False, deprecated))
                    if bitpos:
                        field_name = make_field_name(enum.get("name"), target.name)
                        bitvalue = make_bitpos(bitpos, target.underling_type)
                        target.fields.append(VkEnumField(field_name, bitvalue, False, deprecated))
                    if alias:
                        field_name = make_field_name(enum.get("name"), target.name)
                        target.fields.append(VkEnumField(field_name, alias, True, deprecated))
            # commands
            for command in require.findall("command"):
                if is_vulkan_video(command.get("name")):
                    continue
                commands.append(f"ktl::api::command::{make_cpp_name(command.get("name"))}")
        promoted = extension.get("promotedto") or None
        if not promoted:
            promoted = ""
        elif promoted.startswith("VK_VERSION"):
            promoted = make_version(promoted)
        else:
            promoted = f"ktl::api::extension::{make_cpp_name(promoted)}"

        extensions.append(VkEntension(make_cpp_name(name),
                                      name,
                                      "ktl::api::version_1_0",
                                      True if tppe == "instance" else False,
                                      promoted,
                                      req,
                                      commands))

    return extensions
