HANDLE_META = """template < typename T >
struct handle_meta
{
    using parent = T::parent;
    using type   = T::type;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = 0
    };
};"""


FORMAT_META = """template < ktl::api::format FORMAT >
struct format
{
};

struct component final
{
    ktl::u32 bits;
    bool     has_plane;
    ktl::u32 plane_index;
    bool     is_present;
};
struct plane final
{
    ktl::u32         width_divisor;
    ktl::u32         height_divisor;
    ktl::api::format compatible;
};

template <>
struct format< ktl::api::format::v_undefined >
{
    static constexpr ktl::u32               block_size       = {};
    static constexpr ktl::u32               texels_per_block = {};
    static constexpr ktl::u32               packed           = {};
    static constexpr ktl::u32               chroma           = {};
    static constexpr ktl::u32               block_width      = {};
    static constexpr ktl::u32               block_height     = {};
    static constexpr ktl::u32               block_depth      = {};
    static constexpr bool                   is_3d            = {};
    static constexpr bool                   is_compressed    = {};
    static constexpr component              r                = {};
    static constexpr component              g                = {};
    static constexpr component              b                = {};
    static constexpr component              a                = {};
    static constexpr component              d                = {};
    static constexpr component              s                = {};
    static constexpr ktl::u32               planes_amount    = {};
    static constexpr std::array< plane, 3 > planes           = {};
};

struct any_format
{
    ktl::u32               block_size;
    ktl::u32               texels_per_block;
    ktl::u32               packed;
    ktl::u32               chroma;
    ktl::u32               block_width;
    ktl::u32               block_height;
    ktl::u32               block_depth;
    bool                   is_3d;
    bool                   is_compressed;
    component              r;
    component              g;
    component              b;
    component              a;
    component              d; // depth
    component              s; // stencil
    ktl::u32               planes_amount;
    std::array< plane, 3 > planes;
};

template < ktl::api::format FORMAT >
constexpr any_format
format_cast() noexcept
{
    using format = ktl::meta::format< FORMAT >;
    return {format::block_size,
            format::texels_per_block,
            format::packed,
            format::chroma,
            format::block_width,
            format::block_height,
            format::block_depth,
            format::is_3d,
            format::is_compressed,
            format::r,
            format::g,
            format::b,
            format::a,
            format::d,
            format::s,
            format::planes_amount,
            format::planes};
}"""


FEATURE_META = """template < ktl::api::feature >
struct feature
{
    static constexpr ktl::api::feature        value          = {};
    static constexpr bool                     is_core        = {};
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = {};
    static constexpr ktl::usize               offsetof_stype = {};
    static constexpr ktl::usize               offsetof_pnext = {};
    static constexpr ktl::usize               offsetof_field = {};
};

struct any_feature
{
    ktl::api::feature        value;
    bool                     is_core;
    ktl::api::structure_type stype;
    ktl::usize               sizeof_struct;
    ktl::usize               offsetof_stype;
    ktl::usize               offsetof_pnext;
    ktl::usize               offsetof_field;
};"""


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


# api/version.hpp: VERSION_META, the constants of every version (commands.fill_versions), VERSION_STD
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
