from vk_types import VkFunction, VkFunctionField
from name_rules import *
from utils import is_vulkan_video
from typing import TextIO
import xml.etree.ElementTree as ET


def extract_command_field_impl(_root) -> VkFunctionField:
    type_str = _root.find("type").text.strip()
    type_res = ""
    if make_type(type_str):
        type_str = make_type(type_str)
        type_res = type_str
    else:
        type_str = make_cpp_name(type_str)
        type_res = f"ktl::api::{make_cpp_name(type_str)}"
    name_str = make_cpp_name(_root.find("name").text.strip())

    raw_field = ET.tostring(_root, encoding='unicode')
    static_size = _root.find("enum")
    for elem in _root.iter():
        if elem.tag.endswith('}enum') or elem.tag == 'enum':
            static_size = elem.text.strip()
    if "[" in raw_field and "]" in raw_field:
        exit_cond = False
        size = make_constant(static_size)
        start = raw_field.find('[')
        comment_start = raw_field.find("comment")
        if size is None:
            end = raw_field.find(']')
            size = raw_field[start + 1:end]
            if not size.isdigit():
                exit_cond = True

        if start > comment_start and comment_start != -1 or exit_cond:
            pass
        else:
            name_str = f"{name_str}[{size}]"

    is_const = "const" in raw_field
    is_pointer = "*" in raw_field

    return VkFunctionField(type_res, f"_{name_str}", is_const, is_pointer)


def extract_command_impl(_root) -> VkFunction | None:
    alias_name = make_cpp_name(_root.get("name"))
    raw_alias = _root.get("alias")
    pfn_alias = make_cpp_name(raw_alias)
    if alias_name and raw_alias:
        return VkFunction(f"pfn_{alias_name}", raw_alias, None, None, f"pfn_{pfn_alias}")

    proto = _root.find("proto")
    tppe = make_type(proto.find("type").text.strip())
    name = proto.find("name").text.strip()
    if is_vulkan_video(name):
        return None

    fields = []
    for field in _root.findall("param"):
        fields.append(extract_command_field_impl(field))
    fields = list(dict.fromkeys(fields))

    return VkFunction(f"pfn_{make_cpp_name(name)}", name, tppe, fields, None)


def fill_definition(_file: TextIO, _commands: list) -> None:
    _file.write("""
namespace ktl::api
{
""")
    for command in _commands:
        if command.alias:
            _file.write(f"using {command.pfn} = {command.alias};\n")
        else:
            _file.write(f"using {command.pfn} = {command.tppe}(*)(")
            fields_str = ""
            for field in command.fields:
                if field.is_const:
                    fields_str += "const "
                fields_str += f"{field.tppe} "
                if field.is_pointer:
                    fields_str += "* "
                fields_str += field.name
                fields_str += ", "
            fields_str = fields_str[:-2]
            _file.write(fields_str)
            _file.write(");\n")
    _file.write("}\n")


def fill_implementation(_file: TextIO, _commands: list):
    _file.write(f"""
namespace ktl::api
{{
static constexpr ktl::usize pfn_table_size = {len(_commands)};
using pfn_table = std::array< ktl::loader::proc_type, pfn_table_size >;
inline thread_local pfn_table * ptable = nullptr;           

""")
    _file.write("enum class command : ktl::u32\n{\n")
    for i in range(len(_commands)):
        command = _commands[i]
        if command.alias:
            _file.write(f"{command.pfn[4:]} = {command.alias[4:]},\n")
        else:
            _file.write(f"{command.pfn[4:]} = {i},\n")
    _file.write("};\n\n")

    for i in range(len(_commands)):
        command = _commands[i]
        if command.alias:
            # print(command.alias)
            # _file.write(f"using {command.pfn[4:]} = ")
            continue

        _file.write(f"inline {command.tppe} {command.pfn[4:]}(")
        fields_str = ""
        for field in command.fields:
            if field.is_const:
                fields_str += "const "
            fields_str += f"{field.tppe} "
            if field.is_pointer:
                fields_str += "* "
            fields_str += field.name
            fields_str += ", "
        fields_str = fields_str[:-2]
        _file.write(fields_str)
        _file.write(")\n{\n")

        _file.write(f"""ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::{command.pfn[4:]})];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{{
std::abort();
}}
return (({command.pfn})ptr)(""")
        fields_str = ""
        for field in command.fields:
            fields_str += field.name.split('[')[0]
            fields_str += ", "
        fields_str = fields_str[:-2]
        _file.write(fields_str)
        _file.write(");\n")
        _file.write("}\n\n")
    _file.write("}\n")


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
struct version< {version} >
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
inline std::span< const ktl::api::command >
get_commands_by_version(ktl::api::version _version) noexcept
{
    if (_version == ktl::api::version_1_0)
    {
        return ktl::meta::version< ktl::api::version_1_0 >::commands;
    }
    if (_version == ktl::api::version_1_1)
    {
        return ktl::meta::version< ktl::api::version_1_1 >::commands;
    }
    if (_version == ktl::api::version_1_2)
    {
        return ktl::meta::version< ktl::api::version_1_2 >::commands;
    }
    if (_version == ktl::api::version_1_3)
    {
        return ktl::meta::version< ktl::api::version_1_3 >::commands;
    }
    if (_version == ktl::api::version_1_4)
    {
        return ktl::meta::version< ktl::api::version_1_4 >::commands;
    }
    return {};
}
""")
    _file.write("}")


def fill_match(_file: TextIO, _commands):
    _file.write("""
namespace ktl::meta
{
inline std::string_view
raw_command(ktl::api::command _command) noexcept
{
    switch (_command)
    {
""")
    for command in _commands:
        if command.alias:
            continue
        _file.write(f"case ktl::api::command::{command.pfn[4:]}:\n")
        _file.write(f'return "{command.name}";\n')
    _file.write("}}}")


def extract(_root) -> list:
    commands = []

    root = _root.find("commands")
    for command in root.findall("command"):
        if command.get("api") == "vulkansc":
            continue
        if result := extract_command_impl(command):
            commands.append(result)

    return commands

def extract_version_commands_impl(_root) -> list:
    commands = []
    for require in _root.findall("require"):
        for cmd in require.findall("command"):
            commands.append(f"ktl::api::command::{make_cpp_name(cmd.get("name"))}")

    # print(commands)
    return commands


def extract_version_commands(_root) -> dict:
    commands = {}
    commands["ktl::api::version_1_0"] = []
    commands["ktl::api::version_1_1"] = []
    commands["ktl::api::version_1_2"] = []
    commands["ktl::api::version_1_3"] = []
    commands["ktl::api::version_1_4"] = []

    for feature in _root.findall("feature"):
        name = feature.get("name")
        if name.startswith("VK_BASE_VERSION") or name.startswith("VK_COMPUTE_VERSION") or name.startswith("VK_GRAPHICS_VERSION"):
            cmds = extract_version_commands_impl(feature)
            vers = name[-3:]
            if vers == "1_0":
                commands["ktl::api::version_1_0"] += cmds
            if vers == "1_1":
                commands["ktl::api::version_1_1"] += cmds
            if vers == "1_2":
                commands["ktl::api::version_1_2"] += cmds
            if vers == "1_3":
                commands["ktl::api::version_1_3"] += cmds
            if vers == "1_4":
                commands["ktl::api::version_1_4"] += cmds
    
    # print(commands)
    return commands
