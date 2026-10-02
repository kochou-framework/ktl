from model import Function, Member
from naming import make_cpp_name
from typing import TextIO
from decl import parse_decl
from api_filter import is_vulkan_api, excluded_names


def load_result(_proto) -> Member:
    decl = parse_decl(_proto)
    return Member("", decl.tppe, decl.const, decl.array)


def load_params(_root) -> list:
    # same parameter can be declared separately for vulkan and vulkansc
    params = [parse_decl(param) for param in _root.findall("param") if is_vulkan_api(param)]
    return [Member(f"_{make_cpp_name(decl.name)}", decl.tppe, decl.const, decl.array) for decl in params]


def make_params(_model, _params: list) -> str:
    return ", ".join(_model.declare(param) for param in _params)


def check_function(_model, _function: Function) -> None:
    _model.check_member(_function.result, f"{_function.raw} return")
    for param in _function.params:
        _model.check_member(param, f"{_function.raw}({param.name})")


COMMAND_LEVELS = ("global", "instance", "physical_device", "device")


def make_levels(_model) -> dict:
    # VkInstance -> instance, VkPhysicalDevice -> physical_device, VkDevice and its children -> device
    roots = {"VkInstance": "instance", "VkPhysicalDevice": "physical_device", "VkDevice": "device"}
    levels = {}
    for c_name, handle in _model.handles.items():
        if not handle.is_dispatchable:
            continue
        current = c_name
        while current not in roots:
            current = _model.handles[current].parent
            if current is None:
                raise ValueError(f"dispatchable handle {c_name} has no VkInstance, VkPhysicalDevice or VkDevice parent")
        levels[c_name] = roots[current]
    return levels


def make_level(_command: Function, _levels: dict) -> str:
    # level is the one of the dispatchable object passed by value as the first parameter, otherwise command is global
    if _command.params and _command.params[0].pointer_count == 0 and _command.params[0].tppe in _levels:
        return _levels[_command.params[0].tppe]
    return "global"


def write_declarations(_file: TextIO, _model) -> None:
    _file.write("""
namespace ktl::api
{
""")
    for command in _model.commands.values():
        if command.alias:
            _file.write(f"using pfn_{command.name} = pfn_{make_cpp_name(command.alias)};\n")
        else:
            _file.write(f"using pfn_{command.name} = {_model.declare(command.result)}(*)({make_params(_model, command.params)});\n")
    _file.write("}\n")


def write_definitions(_file: TextIO, _model) -> None:
    commands = list(_model.commands.values())
    _file.write(f"""
namespace ktl::api
{{
static constexpr ktl::usize pfn_table_size = {len(commands)};
using pfn_table = std::array< ktl::loader::proc_type, pfn_table_size >;
// set by the user to a loaded table: commands abort while it is null or their slot is proc_null
inline pfn_table * ptable = nullptr;

""")
    # every alias has its own slot: vkGet*ProcAddr resolves core and extension names under different conditions
    _file.write("enum class command : ktl::u32\n{\n")
    for i, command in enumerate(commands):
        _file.write(f"{command.name} = {i},\n")
    _file.write("};\n\n")

    for command in commands:
        _file.write(f"inline {_model.declare(command.result)} {command.name}({make_params(_model, command.params)})\n{{\n")

        # null ptable (before setup or after reset) reads as an unloaded command and aborts instead of a crash;
        # one check keeps the hot path one branch longer only, two checks also move the frame setup into it
        _file.write(f"""ktl::loader::proc_type ptr = ptable != nullptr ? (*ptable)[static_cast< ktl::u32 >(ktl::api::command::{command.name})] : ktl::loader::proc_null;
if (ptr == ktl::loader::proc_null) [[unlikely]]
{{
std::abort();
}}
return ((pfn_{command.name})ptr)(""")
        _file.write(", ".join(param.name for param in command.params))
        _file.write(");\n")
        _file.write("}\n\n")
    _file.write("}\n")


def write_meta(_file: TextIO, _model) -> None:
    _file.write("""
namespace ktl::meta
{
inline constexpr std::string_view
raw_command(ktl::api::command _command) noexcept
{
    switch (_command)
    {
""")
    for command in _model.commands.values():
        _file.write(f"case ktl::api::command::{command.name}:\n")
        _file.write(f'return "{command.raw}";\n')
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
        for command in _model.commands.values():
            if command.level == level:
                _file.write(f"case ktl::api::command::{command.name}:\n")
        _file.write(f"return ktl::meta::command_level::{level};\n")
    _file.write("}\nstd::abort();\n}\n}")


def load(_root, _model) -> None:
    for src in _root.find("commands").findall("command"):
        raw = src.get("name") or src.findtext("proto/name")
        if not is_vulkan_api(src) or raw in excluded_names(_root):
            continue
        if src.get("alias"):
            # signature and level are the ones of the target: resolve()
            _model.commands[raw] = Function(make_cpp_name(raw), raw, None, [], src.get("alias"))
        else:
            _model.commands[raw] = Function(make_cpp_name(raw), raw, load_result(src.find("proto")), load_params(src), None)


def resolve(_model) -> None:
    levels = make_levels(_model)
    for command in _model.commands.values():
        if not command.alias:
            check_function(_model, command)
            command.level = make_level(command, levels)
    for raw, command in _model.commands.items():
        if command.alias:
            target = _model.find(_model.commands, command.alias, "command", f"alias {raw}")
            if target.alias:
                raise ValueError(f"alias {raw} names alias {command.alias}")
            command.result, command.params, command.level = target.result, target.params, target.level
