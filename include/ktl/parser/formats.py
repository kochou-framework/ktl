from model import Format, FormatComponent, FormatPlane
from typing import TextIO


# meta/format.hpp: primary template, v_undefined, any_format and format_cast
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


def load_format(_root) -> Format:
    block_size = _root.get("blockSize")
    texels_per_block = _root.get("texelsPerBlock")
    packed = _root.get("packed") or "0"
    chroma = _root.get("chroma") or "0"
    block_extent = _root.get("blockExtent") # "width,height,depth"
    block_width, block_height, block_depth = (v.strip() for v in block_extent.split(",")) if block_extent else ("0", "0", "0")
    is_3d = "true" if int(block_depth) > 1 else "false"
    # compressed="BC|ETC2|EAC|ASTC..." is set for every compressed format, components of EAC still have numeric bits
    is_compressed = "true" if _root.get("compressed") else "false"
    planes_amount = "0"
    planes = [None, None, None]

    # R, G, B, A, depth D and stencil S; a repeated component (G of 422 formats) keeps the last one
    components = {}
    for component in _root.findall("component"):
        bits = component.get("bits")
        bits = "0" if bits == "compressed" else bits
        plane = component.get("planeIndex")
        components[component.get("name")] = FormatComponent(bits, "true" if plane else "false", plane if plane else "0", "true")
    absent = FormatComponent("0", "false", "0", "false")
    r, g, b, a, d, s = (components.get(name, absent) for name in "RGBADS")

    for plane in _root.findall("plane"):
        index = plane.get("index")
        width_divisor = plane.get("widthDivisor")
        height_divisor = plane.get("heightDivisor")
        planes[int(index)] = FormatPlane(width_divisor, height_divisor, plane.get("compatible"))
    for i in range(len(planes)):
        if not planes[i]:
            planes[i] = FormatPlane("0", "0", "VK_FORMAT_UNDEFINED")
            continue
        planes_amount = str(i + 1)

    return Format(block_size,
                  texels_per_block,
                  packed,
                  chroma,
                  block_width,
                  block_height,
                  block_depth,
                  is_3d,
                  is_compressed,
                  r, g, b, a, d, s,
                  planes_amount,
                  planes)


def write_meta(_file: TextIO, _model) -> None:
    _file.write(f"""namespace ktl::meta
{{
{FORMAT_META}
""")
    for c_name, format in _model.formats.items():
        _file.write(f"""
template <>
struct format< {_model.value_ref("VkFormat", c_name)} >
{{
    static constexpr ktl::u32 block_size = {format.block_size};
    static constexpr ktl::u32 texels_per_block = {format.texels_per_block};
    static constexpr ktl::u32 packed = {format.packed};
    static constexpr ktl::u32 chroma = {format.chroma};
    static constexpr ktl::u32 block_width = {format.block_width};
    static constexpr ktl::u32 block_height = {format.block_height};
    static constexpr ktl::u32 block_depth = {format.block_depth};
    static constexpr bool is_3d = {format.is_3d};
    static constexpr bool is_compressed = {format.is_compressed};
    static constexpr component r = {{
        {format.r.bits},
        {format.r.has_plane},
        {format.r.plane_index},
        {format.r.is_present}
    }};
    static constexpr component g = {{
        {format.g.bits},
        {format.g.has_plane},
        {format.g.plane_index},
        {format.g.is_present}
    }};
    static constexpr component b = {{
        {format.b.bits},
        {format.b.has_plane},
        {format.b.plane_index},
        {format.b.is_present}
    }};
    static constexpr component a = {{
        {format.a.bits},
        {format.a.has_plane},
        {format.a.plane_index},
        {format.a.is_present}
    }};
    static constexpr component d = {{
        {format.d.bits},
        {format.d.has_plane},
        {format.d.plane_index},
        {format.d.is_present}
    }};
    static constexpr component s = {{
        {format.s.bits},
        {format.s.has_plane},
        {format.s.plane_index},
        {format.s.is_present}
    }};
    static constexpr ktl::u32 planes_amount = {format.planes_amount};
    static constexpr std::array< plane, 3 > planes = {{
        plane{{
            {format.planes[0].width_divisor},
            {format.planes[0].height_divisor},
            {_model.value_ref("VkFormat", format.planes[0].compatible)}
        }},
        plane{{
            {format.planes[1].width_divisor},
            {format.planes[1].height_divisor},
            {_model.value_ref("VkFormat", format.planes[1].compatible)}
        }},
        plane{{
            {format.planes[2].width_divisor},
            {format.planes[2].height_divisor},
            {_model.value_ref("VkFormat", format.planes[2].compatible)}
        }}
    }};
}};
""")

    _file.write("""
inline constexpr any_format
match(ktl::api::format _format) noexcept
{
    switch (_format)
    {""")
    for c_name in _model.formats:
        if c_name == "VK_FORMAT_UNDEFINED":
            continue

        _file.write(f"""
case {_model.value_ref("VkFormat", c_name)}:
        return ktl::meta::format_cast< {_model.value_ref("VkFormat", c_name)} >();""")
    _file.write("""
        default:
            return ktl::meta::format_cast< ktl::api::format::v_undefined >();
    }
}""")

    _file.write("}\n")


def load(_root, _model) -> None:
    for src in _root.findall("formats"):
        for format in src.findall("format"):
            _model.formats[format.get("name")] = load_format(format)


def resolve(_model) -> None:
    for c_name, format in _model.formats.items():
        _model.check_value("VkFormat", c_name, "format")
        for plane in format.planes:
            _model.check_value("VkFormat", plane.compatible, f"plane of {c_name}")
