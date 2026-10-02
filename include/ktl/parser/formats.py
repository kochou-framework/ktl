from vk_types import VkFormat, VkFormatComponent, VkFormatPlane
from name_rules import *
from typing import TextIO
from cpp_meta import FORMAT_META


def extract_format_impl(_root) -> VkFormat:
    format_name = f"ktl::api::format::{make_field_name(_root.get("name"), "format")}"
    block_size = _root.get("blockSize")
    texels_per_block = _root.get("texelsPerBlock")
    packed = _root.get("packed") or "0"
    chroma = _root.get("chroma") or "0"
    block_extent = _root.get("blockExtent") # "width,height,depth"
    block_width, block_height, block_depth = (v.strip() for v in block_extent.split(",")) if block_extent else ("0", "0", "0")
    is_3d = "true" if int(block_depth) > 1 else "false"
    # compressed="BC|ETC2|EAC|ASTC..." is set for every compressed format, components of EAC still have numeric bits
    is_compressed = "true" if _root.get("compressed") else "false"
    planes_amount = 0
    planes = [None, None, None]

    # R, G, B, A, depth D and stencil S; a repeated component (G of 422 formats) keeps the last one
    components = {}
    for component in _root.findall("component"):
        bits = component.get("bits")
        bits = "0" if bits == "compressed" else bits
        plane = component.get("planeIndex")
        components[component.get("name")] = VkFormatComponent(bits, "true" if plane else "false", plane if plane else "0", "true")
    absent = VkFormatComponent("0", "false", "0", "false")
    r, g, b, a, d, s = (components.get(name, absent) for name in "RGBADS")

    for plane in _root.findall("plane"):
        index = plane.get("index")
        width_divisor = plane.get("widthDivisor")
        height_divisor = plane.get("heightDivisor")
        compatible = f"ktl::api::format::{make_field_name(plane.get("compatible"), "format")}"
        planes[int(index)] = VkFormatPlane(width_divisor, height_divisor, compatible)
    for i in range(len(planes)):
        if not planes[i]:
            planes[i] = VkFormatPlane("0", "0", "ktl::api::format::v_undefined")
            continue
        planes_amount = str(i + 1)

    return VkFormat(format_name,
                    block_size,
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


def fill_definition():
    pass # nothing to do


def fill_implementation():
    pass # nothing to do


def fill_meta(_file: TextIO, _formats: list):
    _file.write(f"""namespace ktl::meta
{{
{FORMAT_META}
""")
    for format in _formats:
        _file.write(f"""
template <>
struct format< {format.name} >
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
            {format.planes[0].compatible}
        }},
        plane{{
            {format.planes[1].width_divisor},
            {format.planes[1].height_divisor},
            {format.planes[1].compatible}
        }},
        plane{{
            {format.planes[2].width_divisor},
            {format.planes[2].height_divisor},
            {format.planes[2].compatible}
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
    for format in _formats:
        if format.name == "ktl::api::format::v_undefined":
            continue

        _file.write(f"""
case {format.name}:
        return ktl::meta::format_cast< {format.name} >();""")
    _file.write("""
        default:
            return ktl::meta::format_cast< ktl::api::format::v_undefined >();
    }
}""")

    _file.write("}\n")


def extract(_root) -> list:
    formats = []
    for src in _root.findall("formats"):
        for format in src.findall("format"):
            formats.append(extract_format_impl(format))

    return formats
