from vk_types import VkFunction, VkFunctionField
from name_rules import *
from typing import TextIO
from decl import parse_decl, make_decl_type, make_declaration
from api_filter import is_vulkan_api, excluded_names, vulkan_features, vulkan_requires, feature_version, vulkan_versions


def extract_command_field_impl(_root) -> VkFunctionField:
    decl = parse_decl(_root)
    return VkFunctionField(make_decl_type(decl.tppe), f"_{make_cpp_name(decl.name)}", decl.const, decl.array)


def extract_return_type_impl(_proto) -> str:
    decl = parse_decl(_proto)
    return make_declaration(make_decl_type(decl.tppe), decl.const)


def extract_command_fields_impl(_root) -> list:
    # same parameter can be declared separately for vulkan and vulkansc
    return [extract_command_field_impl(param) for param in _root.findall("param") if is_vulkan_api(param)]


def make_params(_fields: list) -> str:
    return ", ".join(make_declaration(field.tppe, field.const, field.name, field.array) for field in _fields)


COMMAND_LEVELS = ("global", "instance", "physical_device", "device")


def extract_dispatchable_levels(_root) -> dict:
    # VkInstance -> instance, VkPhysicalDevice -> physical_device, VkDevice and its children -> device
    roots = {"VkInstance": "instance", "VkPhysicalDevice": "physical_device", "VkDevice": "device"}
    parents = {}
    dispatchable = []
    for src in _root.find("types").findall("type[@category='handle']"):
        name = src.find("name")
        if name is None: # alias
            continue
        parents[name.text] = src.get("parent")
        if src.find("type").text == "VK_DEFINE_HANDLE":
            dispatchable.append(name.text)

    levels = {}
    for handle in dispatchable:
        current = handle
        while current not in roots:
            current = parents.get(current)
            if current is None:
                raise ValueError(f"dispatchable handle {handle} has no VkInstance, VkPhysicalDevice or VkDevice parent")
        levels[handle] = roots[current]
    return levels


def extract_command_level_impl(_root, _levels: dict) -> str:
    # level is the one of the dispatchable object passed by value as the first parameter, otherwise command is global
    params = [param for param in _root.findall("param") if is_vulkan_api(param)]
    if params:
        decl = parse_decl(params[0])
        if decl.pointer_count == 0 and decl.tppe in _levels:
            return _levels[decl.tppe]
    return "global"


def extract_command_impl(_root, _levels: dict) -> VkFunction | None:
    alias_name = make_cpp_name(_root.get("name"))
    raw_alias = _root.get("alias")
    pfn_alias = make_cpp_name(raw_alias)
    if alias_name and raw_alias:
        # signature is taken from the target in extract()
        return VkFunction(f"pfn_{alias_name}", _root.get("name"), None, None, f"pfn_{pfn_alias}")

    proto = _root.find("proto")
    tppe = extract_return_type_impl(proto)
    name = proto.find("name").text.strip()
    fields = extract_command_fields_impl(_root)
    level = extract_command_level_impl(_root, _levels)
    return VkFunction(f"pfn_{make_cpp_name(name)}", name, tppe, fields, None, level)


def fill_definition(_file: TextIO, _commands: list) -> None:
    _file.write("""
namespace ktl::api
{
""")
    for command in _commands:
        if command.alias:
            _file.write(f"using {command.pfn} = {command.alias};\n")
        else:
            _file.write(f"using {command.pfn} = {command.tppe}(*)({make_params(command.fields)});\n")
    _file.write("}\n")


def fill_implementation(_file: TextIO, _commands: list):
    _file.write(f"""
namespace ktl::api
{{
static constexpr ktl::usize pfn_table_size = {len(_commands)};
using pfn_table = std::array< ktl::loader::proc_type, pfn_table_size >;
// set by the user to a loaded table: commands abort while it is null or their slot is proc_null
inline pfn_table * ptable = nullptr;

""")
    # every alias has its own slot: vkGet*ProcAddr resolves core and extension names under different conditions
    _file.write("enum class command : ktl::u32\n{\n")
    for i in range(len(_commands)):
        _file.write(f"{_commands[i].pfn[4:]} = {i},\n")
    _file.write("};\n\n")

    for command in _commands:
        _file.write(f"inline {command.tppe} {command.pfn[4:]}({make_params(command.fields)})\n{{\n")

        # null ptable (before setup or after reset) reads as an unloaded command and aborts instead of a crash;
        # one check keeps the hot path one branch longer only, two checks also move the frame setup into it
        _file.write(f"""ktl::loader::proc_type ptr = ptable != nullptr ? (*ptable)[static_cast< ktl::u32 >(ktl::api::command::{command.pfn[4:]})] : ktl::loader::proc_null;
if (ptr == ktl::loader::proc_null) [[unlikely]]
{{
std::abort();
}}
return (({command.pfn})ptr)(""")
        _file.write(", ".join(field.name for field in command.fields))
        _file.write(");\n")
        _file.write("}\n\n")
    _file.write("}\n")


def fill_versions(_file: TextIO, _versions) -> None:
    # api/version.hpp: a constant for every vulkan version of vk.xml and all of them in common_versions
    for major, minor in _versions:
        _file.write(f"static constexpr ktl::api::version version_{major}_{minor}(0, {major}, {minor}, 0);\n")
    names = ", ".join(f"version_{major}_{minor}" for major, minor in _versions)
    _file.write(f"static constexpr std::array< ktl::api::version, {len(_versions)} > common_versions = {{{names}}};\n")


def fill_meta(_file: TextIO, _version_commands):
    _file.write("""
namespace ktl::meta
{
template < ktl::api::version >
struct version
{
};
""")
    for version, commands in _version_commands.items():
        _file.write(f"""
template <>
struct version< {make_version(version)} >
{{
    static constexpr std::array< ktl::api::command, {len(commands)} > commands = {{
""")
        st = ""
        for command in commands:
            st += f"{command},"
        st = st[:-1]
        _file.write(st)
        _file.write("};};\n")
    _file.write("""
inline constexpr std::span< const ktl::api::command >
get_commands_by_version(ktl::api::version _version) noexcept
{
    // patch adds no commands: 1.3.250 has the commands of 1.3; variant other than 0 is not vulkan
    const ktl::api::version rounded(_version.variant, _version.major, _version.minor, 0);
""")
    for version in _version_commands:
        _file.write(f"""    if (rounded == {make_version(version)})
    {{
        return ktl::meta::version< {make_version(version)} >::commands;
    }}
""")
    _file.write("""    return {};
}
""")
    _file.write("}")


def fill_match(_file: TextIO, _commands):
    _file.write("""
namespace ktl::meta
{
inline constexpr std::string_view
raw_command(ktl::api::command _command) noexcept
{
    switch (_command)
    {
""")
    for command in _commands:
        _file.write(f"case ktl::api::command::{command.pfn[4:]}:\n")
        _file.write(f'return "{command.name}";\n')
    # value outside of the enum, falling off a non-void function is UB
    _file.write("}\nstd::abort();\n}\n")

    # vkGetDeviceProcAddr returns only device commands, physical_device commands of device extensions
    # come from vkGetInstanceProcAddr even before the device is created
    _file.write("""
// level of the dispatchable object in the first parameter:
// global commands are loaded with vkGetInstanceProcAddr(NULL), instance and physical_device commands
// with vkGetInstanceProcAddr(instance), device commands with vkGetDeviceProcAddr(device);
// vkGetDeviceProcAddr itself is a device command, it is loaded with vkGetInstanceProcAddr(instance) first
enum class command_level : ktl::u32
{
    global,
    instance,
    physical_device,
    device
};

inline constexpr command_level
get_command_level(ktl::api::command _command) noexcept
{
    switch (_command)
    {
""")
    for level in COMMAND_LEVELS:
        for command in _commands:
            if command.level == level:
                _file.write(f"case ktl::api::command::{command.pfn[4:]}:\n")
        _file.write(f"return ktl::meta::command_level::{level};\n")
    _file.write("}\nstd::abort();\n}\n}")


def extract(_root) -> list:
    commands = []
    levels = extract_dispatchable_levels(_root)

    root = _root.find("commands")
    for command in root.findall("command"):
        name = command.get("name") or command.findtext("proto/name")
        if not is_vulkan_api(command) or name in excluded_names(_root):
            continue
        if result := extract_command_impl(command, levels):
            commands.append(result)

    targets = {command.pfn: command for command in commands if not command.alias}
    for command in commands:
        if command.alias:
            if command.alias not in targets:
                raise ValueError(f"alias {command.name} of unknown command {command.alias}")
            command.tppe = targets[command.alias].tppe
            command.fields = targets[command.alias].fields
            command.level = targets[command.alias].level

    return commands

def extract_version_commands_impl(_root) -> list:
    commands = []
    for require in vulkan_requires(_root):
        for cmd in require.findall("command"):
            commands.append(f"ktl::api::command::{make_cpp_name(cmd.get("name"))}")

    # print(commands)
    return commands


def extract_version_commands(_root) -> dict:
    # (major, minor) -> commands added by the version, from every feature of its number:
    # VK_BASE_VERSION_1_3, VK_COMPUTE_VERSION_1_3, VK_GRAPHICS_VERSION_1_3 and VK_VERSION_1_3
    commands = {version: [] for version in vulkan_versions(_root)}
    for feature in vulkan_features(_root):
        commands[feature_version(feature)] += extract_version_commands_impl(feature)
    return commands
