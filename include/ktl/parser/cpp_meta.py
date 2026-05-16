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
    ktl::u32               planes_amount;
    std::array< plane, 3 > planes;
};

template < ktl::api::format FORMAT >
any_format
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
            format::planes_amount,
            format::planes};
}"""


ENUM_META = """"""


STRUCT_META = """"""


COMMAND_META = """template < ktl::u32 >
struct command
{
    static constexpr ktl::api::version                    version     = {};
    static constexpr std::array< ktl::api::extension, 0 > extensions  = {};
    static constexpr bool                                 is_instance = {};
    static constexpr std::string_view                     raw_name    = {};

    static constexpr bool     conditionalrendering = {};
    static constexpr bool     allow_no_queues      = {};
    static constexpr ktl::u32 queues               = {};
    static constexpr ktl::u32 renderpass           = {};
    static constexpr ktl::u32 cmdbufferlevel       = {};
    static constexpr ktl::u32 tasks                = {};
};"""


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

    static constexpr std::array< ktl::api::command, 0 >       commands  = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps      = {};
};

struct any_extension
{
    std::string_view      raw_name    = {};
    bool                  is_instance = {};
    ktl::meta::dependency promoted    = {};

    std::span< ktl::api::command const >       commands = {};
    std::span< ktl::meta::version_deps const > deps     = {};
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
            extension::deps};
}"""
