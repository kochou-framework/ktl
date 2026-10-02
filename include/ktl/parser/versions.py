from naming import make_cpp_name, make_version
from typing import TextIO
from api_filter import vulkan_features, vulkan_requires, feature_version


# api/version.hpp: VERSION_META, the constants of every version, VERSION_STD
VERSION_META = """struct version
{
    ktl::u32 variant;
    ktl::u32 major;
    ktl::u32 minor;
    ktl::u32 patch;

    constexpr version() noexcept : variant(0), major(0), minor(0), patch(0) {}

    constexpr explicit version(ktl::u32 _version) noexcept
        : variant((_version >> 29U) & 0x7U), major((_version >> 22U) & 0x7FU), minor((_version >> 12U) & 0x3FFU),
          patch(_version & 0xFFFU)
    {
    }
    constexpr explicit version(ktl::u32 _variant, ktl::u32 _major, ktl::u32 _minor, ktl::u32 _patch) noexcept
        : variant(_variant), major(_major), minor(_minor), patch(_patch)
    {
    }

    constexpr ktl::u32
    operator()() const noexcept
    {
        return (variant << 29U) | (major << 22U) | (minor << 12U) | patch;
    }

    constexpr explicit
    operator ktl::u32() const noexcept
    {
        return operator()();
    }

    constexpr std::strong_ordering
    operator<=>(version _rhs) const noexcept
    {
        return operator()() <=> _rhs.operator()();
    }

    constexpr bool
    operator==(version _rhs) const noexcept
    {
        return operator()() == _rhs.operator()();
    }
};"""


VERSION_STD = """namespace std
{
template <>
struct hash< ktl::api::version >
{
    [[nodiscard]] ktl::usize
    operator()(ktl::api::version _version) const noexcept
    {
        return static_cast< ktl::usize >(_version());
    }
};

template <>
struct formatter< ktl::api::version, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::version _version, FormatContext & ctx) const
    {
        return std::format_to(ctx.out(), "{}.{}.{}", _version.major, _version.minor, _version.patch);
    }
};
} // namespace std"""


def write_definitions(_file: TextIO, _model) -> None:
    # a constant for every vulkan version of vk.xml and all of them in common_versions
    _file.write(f"""namespace ktl::api
{{
{VERSION_META}

""")
    for major, minor in _model.versions:
        _file.write(f"static constexpr ktl::api::version version_{major}_{minor}(0, {major}, {minor}, 0);\n")
    names = ", ".join(f"version_{major}_{minor}" for major, minor in _model.versions)
    _file.write(f"static constexpr std::array< ktl::api::version, {len(_model.versions)} > common_versions = {{{names}}};\n")
    _file.write(f"""}} // namespace ktl::api

{VERSION_STD}
""")


def write_meta(_file: TextIO, _model) -> None:
    _file.write("""
namespace ktl::meta
{
template < ktl::api::version >
struct version
{
};
""")
    for version, commands in _model.version_commands.items():
        _file.write(f"""
template <>
struct version< {make_version(version)} >
{{
    static constexpr std::array< ktl::api::command, {len(commands)} > commands = {{
""")
        _file.write(",\n".join(f"        ktl::api::command::{make_cpp_name(command)}" for command in commands))
        _file.write("\n    };\n};\n")
    _file.write("""
inline constexpr std::span< const ktl::api::command >
get_commands_by_version(ktl::api::version _version) noexcept
{
    // patch adds no commands: 1.3.250 has the commands of 1.3; variant other than 0 is not vulkan
    const ktl::api::version rounded(_version.variant, _version.major, _version.minor, 0);
""")
    for version in _model.version_commands:
        _file.write(f"""    if (rounded == {make_version(version)})
    {{
        return ktl::meta::version< {make_version(version)} >::commands;
    }}
""")
    _file.write("""    return {};
}
""")
    _file.write("}")


def load(_root, _model) -> None:
    # (major, minor) -> commands added by the version, from every feature of its number:
    # VK_BASE_VERSION_1_3, VK_COMPUTE_VERSION_1_3, VK_GRAPHICS_VERSION_1_3 and VK_VERSION_1_3
    _model.version_commands = {version: [] for version in _model.versions}
    for feature in vulkan_features(_root):
        for require in vulkan_requires(feature):
            _model.version_commands[feature_version(feature)] += [command.get("name") for command in require.findall("command")]


def resolve(_model) -> None:
    for (major, minor), commands in _model.version_commands.items():
        for command in commands:
            _model.find(_model.commands, command, "command", f"version {major}.{minor}")
