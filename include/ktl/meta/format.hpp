#ifndef KTL_META_FORMAT_HPP
#define KTL_META_FORMAT_HPP

#include <array>

#include <ktl/api.hpp>

namespace ktl::meta
{
template < ktl::api::format FORMAT >
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
}

template <>
struct format< ktl::api::format::v_r4g4_unorm_pack8 >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 8;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {4, false, 0, true};
    static constexpr component              g                = {4, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r4g4b4a4_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {4, false, 0, true};
    static constexpr component              g                = {4, false, 0, true};
    static constexpr component              b                = {4, false, 0, true};
    static constexpr component              a                = {4, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b4g4r4a4_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {4, false, 0, true};
    static constexpr component              g                = {4, false, 0, true};
    static constexpr component              b                = {4, false, 0, true};
    static constexpr component              a                = {4, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r5g6b5_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {5, false, 0, true};
    static constexpr component              g                = {6, false, 0, true};
    static constexpr component              b                = {5, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b5g6r5_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {5, false, 0, true};
    static constexpr component              g                = {6, false, 0, true};
    static constexpr component              b                = {5, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r5g5b5a1_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {5, false, 0, true};
    static constexpr component              g                = {5, false, 0, true};
    static constexpr component              b                = {5, false, 0, true};
    static constexpr component              a                = {1, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b5g5r5a1_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {5, false, 0, true};
    static constexpr component              g                = {5, false, 0, true};
    static constexpr component              b                = {5, false, 0, true};
    static constexpr component              a                = {1, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a1r5g5b5_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {5, false, 0, true};
    static constexpr component              g                = {5, false, 0, true};
    static constexpr component              b                = {5, false, 0, true};
    static constexpr component              a                = {1, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a1b5g5r5_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {5, false, 0, true};
    static constexpr component              g                = {5, false, 0, true};
    static constexpr component              b                = {5, false, 0, true};
    static constexpr component              a                = {1, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a8_unorm >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {0, false, 0, false};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8_unorm >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8_snorm >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8_uscaled >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8_sscaled >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8_uint >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8_sint >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8_srgb >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8_unorm >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8_snorm >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8_uscaled >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8_sscaled >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8_uint >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8_sint >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8_srgb >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8_unorm >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8_snorm >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8_uscaled >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8_sscaled >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8_uint >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8_sint >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8_srgb >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8_unorm >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8_snorm >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8_uscaled >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8_sscaled >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8_uint >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8_sint >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8_srgb >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8a8_unorm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8a8_snorm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8a8_uscaled >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8a8_sscaled >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8a8_uint >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8a8_sint >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8g8b8a8_srgb >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8a8_unorm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8a8_snorm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8a8_uscaled >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8a8_sscaled >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8a8_uint >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8a8_sint >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8a8_srgb >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a8b8g8r8_unorm_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a8b8g8r8_snorm_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a8b8g8r8_uscaled_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a8b8g8r8_sscaled_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a8b8g8r8_uint_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a8b8g8r8_sint_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a8b8g8r8_srgb_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {8, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2r10g10b10_unorm_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2r10g10b10_snorm_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2r10g10b10_uscaled_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2r10g10b10_sscaled_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2r10g10b10_uint_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2r10g10b10_sint_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2b10g10r10_unorm_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2b10g10r10_snorm_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2b10g10r10_uscaled_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2b10g10r10_sscaled_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2b10g10r10_uint_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a2b10g10r10_sint_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {2, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16_unorm >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16_snorm >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16_uscaled >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16_sscaled >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16_uint >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16_sint >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16_sfloat >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16_unorm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16_snorm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16_uscaled >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16_sscaled >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16_uint >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16_sint >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16_sfloat >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16_unorm >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16_snorm >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16_uscaled >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16_sscaled >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16_uint >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16_sint >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16_sfloat >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16a16_unorm >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {16, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16a16_snorm >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {16, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16a16_uscaled >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {16, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16a16_sscaled >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {16, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16a16_uint >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {16, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16a16_sint >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {16, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16b16a16_sfloat >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {16, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32_uint >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32_sint >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32_sfloat >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32g32_uint >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {32, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32g32_sint >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {32, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32g32_sfloat >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {32, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32g32b32_uint >
{
    static constexpr ktl::u32               block_size       = 12;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {32, false, 0, true};
    static constexpr component              b                = {32, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32g32b32_sint >
{
    static constexpr ktl::u32               block_size       = 12;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {32, false, 0, true};
    static constexpr component              b                = {32, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32g32b32_sfloat >
{
    static constexpr ktl::u32               block_size       = 12;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {32, false, 0, true};
    static constexpr component              b                = {32, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32g32b32a32_uint >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {32, false, 0, true};
    static constexpr component              b                = {32, false, 0, true};
    static constexpr component              a                = {32, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32g32b32a32_sint >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {32, false, 0, true};
    static constexpr component              b                = {32, false, 0, true};
    static constexpr component              a                = {32, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r32g32b32a32_sfloat >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {32, false, 0, true};
    static constexpr component              g                = {32, false, 0, true};
    static constexpr component              b                = {32, false, 0, true};
    static constexpr component              a                = {32, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64_uint >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64_sint >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64_sfloat >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64g64_uint >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {64, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64g64_sint >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {64, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64g64_sfloat >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {64, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64g64b64_uint >
{
    static constexpr ktl::u32               block_size       = 24;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {64, false, 0, true};
    static constexpr component              b                = {64, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64g64b64_sint >
{
    static constexpr ktl::u32               block_size       = 24;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {64, false, 0, true};
    static constexpr component              b                = {64, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64g64b64_sfloat >
{
    static constexpr ktl::u32               block_size       = 24;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {64, false, 0, true};
    static constexpr component              b                = {64, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64g64b64a64_uint >
{
    static constexpr ktl::u32               block_size       = 32;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {64, false, 0, true};
    static constexpr component              b                = {64, false, 0, true};
    static constexpr component              a                = {64, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64g64b64a64_sint >
{
    static constexpr ktl::u32               block_size       = 32;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {64, false, 0, true};
    static constexpr component              b                = {64, false, 0, true};
    static constexpr component              a                = {64, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r64g64b64a64_sfloat >
{
    static constexpr ktl::u32               block_size       = 32;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {64, false, 0, true};
    static constexpr component              g                = {64, false, 0, true};
    static constexpr component              b                = {64, false, 0, true};
    static constexpr component              a                = {64, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b10g11r11_ufloat_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {11, false, 0, true};
    static constexpr component              g                = {11, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_e5b9g9r9_ufloat_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {9, false, 0, true};
    static constexpr component              g                = {9, false, 0, true};
    static constexpr component              b                = {9, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_d16_unorm >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {0, false, 0, false};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {16, false, 0, true};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_x8_d24_unorm_pack32 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 32;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {0, false, 0, false};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {24, false, 0, true};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_d32_sfloat >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {0, false, 0, false};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {32, false, 0, true};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_s8_uint >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {0, false, 0, false};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {8, false, 0, true};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_d16_unorm_s8_uint >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {0, false, 0, false};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {16, false, 0, true};
    static constexpr component              s                = {8, false, 0, true};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_d24_unorm_s8_uint >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {0, false, 0, false};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {24, false, 0, true};
    static constexpr component              s                = {8, false, 0, true};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_d32_sfloat_s8_uint >
{
    static constexpr ktl::u32               block_size       = 5;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {0, false, 0, false};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {32, false, 0, true};
    static constexpr component              s                = {8, false, 0, true};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc1_rgb_unorm_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc1_rgb_srgb_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc1_rgba_unorm_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc1_rgba_srgb_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc2_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc2_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc3_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc3_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc4_unorm_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc4_snorm_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc5_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc5_snorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc6h_ufloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc6h_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc7_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc7_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc2_r8g8b8_unorm_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc2_r8g8b8_srgb_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc2_r8g8b8a1_unorm_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc2_r8g8b8a1_srgb_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc2_r8g8b8a8_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc2_r8g8b8a8_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_eac_r11_unorm_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {11, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_eac_r11_snorm_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {11, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_eac_r11g11_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {11, false, 0, true};
    static constexpr component              g                = {11, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_eac_r11g11_snorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {11, false, 0, true};
    static constexpr component              g                = {11, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x4_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x4_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x4_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 20;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x4_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 20;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x5_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 25;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x5_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 25;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x5_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 30;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x5_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 30;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x6_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 36;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x6_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 36;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x5_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 40;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x5_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 40;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x6_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 48;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x6_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 48;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x8_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 64;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 8;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x8_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 64;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 8;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x5_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 50;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x5_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 50;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x6_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 60;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x6_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 60;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x8_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 80;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 8;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x8_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 80;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 8;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x10_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 100;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 10;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x10_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 100;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 10;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x10_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 120;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 12;
    static constexpr ktl::u32               block_height     = 10;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x10_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 120;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 12;
    static constexpr ktl::u32               block_height     = 10;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x12_unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 144;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 12;
    static constexpr ktl::u32               block_height     = 12;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x12_srgb_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 144;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 12;
    static constexpr ktl::u32               block_height     = 12;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g8b8g8r8_422_unorm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 2;
    static constexpr ktl::u32               block_height     = 1;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b8g8r8g8_422_unorm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 2;
    static constexpr ktl::u32               block_height     = 1;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {8, false, 0, true};
    static constexpr component              b                = {8, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g8_b8_r8_3plane_420_unorm >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 420;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, true, 2, true};
    static constexpr component              g                = {8, true, 0, true};
    static constexpr component              b                = {8, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r8_unorm},
                                                                plane{2, 2, ktl::api::format::v_r8_unorm},
                                                                plane{2, 2, ktl::api::format::v_r8_unorm}};
};

template <>
struct format< ktl::api::format::v_g8_b8r8_2plane_420_unorm >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 420;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, true, 1, true};
    static constexpr component              g                = {8, true, 0, true};
    static constexpr component              b                = {8, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r8_unorm},
                                                                plane{2, 2, ktl::api::format::v_r8g8_unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g8_b8_r8_3plane_422_unorm >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, true, 2, true};
    static constexpr component              g                = {8, true, 0, true};
    static constexpr component              b                = {8, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r8_unorm},
                                                                plane{2, 1, ktl::api::format::v_r8_unorm},
                                                                plane{2, 1, ktl::api::format::v_r8_unorm}};
};

template <>
struct format< ktl::api::format::v_g8_b8r8_2plane_422_unorm >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, true, 1, true};
    static constexpr component              g                = {8, true, 0, true};
    static constexpr component              b                = {8, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r8_unorm},
                                                                plane{2, 1, ktl::api::format::v_r8g8_unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g8_b8_r8_3plane_444_unorm >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 444;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, true, 2, true};
    static constexpr component              g                = {8, true, 0, true};
    static constexpr component              b                = {8, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r8_unorm},
                                                                plane{1, 1, ktl::api::format::v_r8_unorm},
                                                                plane{1, 1, ktl::api::format::v_r8_unorm}};
};

template <>
struct format< ktl::api::format::v_r10x6_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r10x6g10x6_unorm_2pack16 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r10x6g10x6b10x6a10x6_unorm_4pack16 >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 444;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {10, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g10x6b10x6g10x6r10x6_422_unorm_4pack16 >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 2;
    static constexpr ktl::u32               block_height     = 1;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b10x6g10x6r10x6g10x6_422_unorm_4pack16 >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 2;
    static constexpr ktl::u32               block_height     = 1;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g10x6_b10x6_r10x6_3plane_420_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 420;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, true, 2, true};
    static constexpr component              g                = {10, true, 0, true};
    static constexpr component              b                = {10, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r10x6_unorm_pack16},
                                                                plane{2, 2, ktl::api::format::v_r10x6_unorm_pack16},
                                                                plane{2, 2, ktl::api::format::v_r10x6_unorm_pack16}};
};

template <>
struct format< ktl::api::format::v_g10x6_b10x6r10x6_2plane_420_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 420;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, true, 1, true};
    static constexpr component              g                = {10, true, 0, true};
    static constexpr component              b                = {10, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r10x6_unorm_pack16},
                                                                plane{2, 2, ktl::api::format::v_r10x6g10x6_unorm_2pack16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g10x6_b10x6_r10x6_3plane_422_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, true, 2, true};
    static constexpr component              g                = {10, true, 0, true};
    static constexpr component              b                = {10, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r10x6_unorm_pack16},
                                                                plane{2, 1, ktl::api::format::v_r10x6_unorm_pack16},
                                                                plane{2, 1, ktl::api::format::v_r10x6_unorm_pack16}};
};

template <>
struct format< ktl::api::format::v_g10x6_b10x6r10x6_2plane_422_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, true, 1, true};
    static constexpr component              g                = {10, true, 0, true};
    static constexpr component              b                = {10, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r10x6_unorm_pack16},
                                                                plane{2, 1, ktl::api::format::v_r10x6g10x6_unorm_2pack16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g10x6_b10x6_r10x6_3plane_444_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 444;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, true, 2, true};
    static constexpr component              g                = {10, true, 0, true};
    static constexpr component              b                = {10, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r10x6_unorm_pack16},
                                                                plane{1, 1, ktl::api::format::v_r10x6_unorm_pack16},
                                                                plane{1, 1, ktl::api::format::v_r10x6_unorm_pack16}};
};

template <>
struct format< ktl::api::format::v_r12x4_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r12x4g12x4_unorm_2pack16 >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, false, 0, true};
    static constexpr component              g                = {12, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r12x4g12x4b12x4a12x4_unorm_4pack16 >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 444;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, false, 0, true};
    static constexpr component              g                = {12, false, 0, true};
    static constexpr component              b                = {12, false, 0, true};
    static constexpr component              a                = {12, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g12x4b12x4g12x4r12x4_422_unorm_4pack16 >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 2;
    static constexpr ktl::u32               block_height     = 1;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, false, 0, true};
    static constexpr component              g                = {12, false, 0, true};
    static constexpr component              b                = {12, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b12x4g12x4r12x4g12x4_422_unorm_4pack16 >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 2;
    static constexpr ktl::u32               block_height     = 1;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, false, 0, true};
    static constexpr component              g                = {12, false, 0, true};
    static constexpr component              b                = {12, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g12x4_b12x4_r12x4_3plane_420_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 420;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, true, 2, true};
    static constexpr component              g                = {12, true, 0, true};
    static constexpr component              b                = {12, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r12x4_unorm_pack16},
                                                                plane{2, 2, ktl::api::format::v_r12x4_unorm_pack16},
                                                                plane{2, 2, ktl::api::format::v_r12x4_unorm_pack16}};
};

template <>
struct format< ktl::api::format::v_g12x4_b12x4r12x4_2plane_420_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 420;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, true, 1, true};
    static constexpr component              g                = {12, true, 0, true};
    static constexpr component              b                = {12, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r12x4_unorm_pack16},
                                                                plane{2, 2, ktl::api::format::v_r12x4g12x4_unorm_2pack16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g12x4_b12x4_r12x4_3plane_422_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, true, 2, true};
    static constexpr component              g                = {12, true, 0, true};
    static constexpr component              b                = {12, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r12x4_unorm_pack16},
                                                                plane{2, 1, ktl::api::format::v_r12x4_unorm_pack16},
                                                                plane{2, 1, ktl::api::format::v_r12x4_unorm_pack16}};
};

template <>
struct format< ktl::api::format::v_g12x4_b12x4r12x4_2plane_422_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, true, 1, true};
    static constexpr component              g                = {12, true, 0, true};
    static constexpr component              b                = {12, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r12x4_unorm_pack16},
                                                                plane{2, 1, ktl::api::format::v_r12x4g12x4_unorm_2pack16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g12x4_b12x4_r12x4_3plane_444_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 444;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, true, 2, true};
    static constexpr component              g                = {12, true, 0, true};
    static constexpr component              b                = {12, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r12x4_unorm_pack16},
                                                                plane{1, 1, ktl::api::format::v_r12x4_unorm_pack16},
                                                                plane{1, 1, ktl::api::format::v_r12x4_unorm_pack16}};
};

template <>
struct format< ktl::api::format::v_g16b16g16r16_422_unorm >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 2;
    static constexpr ktl::u32               block_height     = 1;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b16g16r16g16_422_unorm >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 2;
    static constexpr ktl::u32               block_height     = 1;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {16, false, 0, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g16_b16_r16_3plane_420_unorm >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 420;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, true, 2, true};
    static constexpr component              g                = {16, true, 0, true};
    static constexpr component              b                = {16, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r16_unorm},
                                                                plane{2, 2, ktl::api::format::v_r16_unorm},
                                                                plane{2, 2, ktl::api::format::v_r16_unorm}};
};

template <>
struct format< ktl::api::format::v_g16_b16r16_2plane_420_unorm >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 420;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, true, 1, true};
    static constexpr component              g                = {16, true, 0, true};
    static constexpr component              b                = {16, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r16_unorm},
                                                                plane{2, 2, ktl::api::format::v_r16g16_unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g16_b16_r16_3plane_422_unorm >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, true, 2, true};
    static constexpr component              g                = {16, true, 0, true};
    static constexpr component              b                = {16, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r16_unorm},
                                                                plane{2, 1, ktl::api::format::v_r16_unorm},
                                                                plane{2, 1, ktl::api::format::v_r16_unorm}};
};

template <>
struct format< ktl::api::format::v_g16_b16r16_2plane_422_unorm >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, true, 1, true};
    static constexpr component              g                = {16, true, 0, true};
    static constexpr component              b                = {16, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r16_unorm},
                                                                plane{2, 1, ktl::api::format::v_r16g16_unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g16_b16_r16_3plane_444_unorm >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 444;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, true, 2, true};
    static constexpr component              g                = {16, true, 0, true};
    static constexpr component              b                = {16, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r16_unorm},
                                                                plane{1, 1, ktl::api::format::v_r16_unorm},
                                                                plane{1, 1, ktl::api::format::v_r16_unorm}};
};

template <>
struct format< ktl::api::format::v_pvrtc1_2bpp_unorm_block_img >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc1_4bpp_unorm_block_img >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc2_2bpp_unorm_block_img >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc2_4bpp_unorm_block_img >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc1_2bpp_srgb_block_img >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc1_4bpp_srgb_block_img >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc2_2bpp_srgb_block_img >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc2_4bpp_srgb_block_img >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x4_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x4_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 20;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x5_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 25;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x5_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 30;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x6_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 36;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x5_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 40;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x6_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 48;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x8_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 64;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 8;
    static constexpr ktl::u32               block_height     = 8;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x5_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 50;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x6_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 60;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x8_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 80;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 8;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x10_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 100;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 10;
    static constexpr ktl::u32               block_height     = 10;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x10_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 120;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 12;
    static constexpr ktl::u32               block_height     = 10;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x12_sfloat_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 144;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 12;
    static constexpr ktl::u32               block_height     = 12;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_3x3x3_unorm_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 27;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 3;
    static constexpr ktl::u32               block_height     = 3;
    static constexpr ktl::u32               block_depth      = 3;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_3x3x3_srgb_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 27;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 3;
    static constexpr ktl::u32               block_height     = 3;
    static constexpr ktl::u32               block_depth      = 3;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_3x3x3_sfloat_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 27;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 3;
    static constexpr ktl::u32               block_height     = 3;
    static constexpr ktl::u32               block_depth      = 3;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x3x3_unorm_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 36;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 3;
    static constexpr ktl::u32               block_depth      = 3;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x3x3_srgb_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 36;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 3;
    static constexpr ktl::u32               block_depth      = 3;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x3x3_sfloat_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 36;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 3;
    static constexpr ktl::u32               block_depth      = 3;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x4x3_unorm_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 48;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 3;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x4x3_srgb_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 48;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 3;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x4x3_sfloat_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 48;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 3;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x4x4_unorm_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 64;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 4;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x4x4_srgb_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 64;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 4;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x4x4_sfloat_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 64;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 4;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x4x4_unorm_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 80;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 4;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x4x4_srgb_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 80;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 4;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x4x4_sfloat_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 80;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 4;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x5x4_unorm_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 100;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 4;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x5x4_srgb_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 100;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 4;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x5x4_sfloat_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 100;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 4;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x5x5_unorm_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 125;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 5;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x5x5_srgb_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 125;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 5;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x5x5_sfloat_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 125;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 5;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 5;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x5x5_unorm_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 150;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 5;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x5x5_srgb_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 150;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 5;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x5x5_sfloat_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 150;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 5;
    static constexpr ktl::u32               block_depth      = 5;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x6x5_unorm_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 180;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 5;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x6x5_srgb_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 180;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 5;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x6x5_sfloat_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 180;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 5;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x6x6_unorm_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 216;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 6;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x6x6_srgb_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 216;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 6;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x6x6_sfloat_block_ext >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 216;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 6;
    static constexpr ktl::u32               block_height     = 6;
    static constexpr ktl::u32               block_depth      = 6;
    static constexpr bool                   is_3d            = true;
    static constexpr bool                   is_compressed    = true;
    static constexpr component              r                = {0, false, 0, true};
    static constexpr component              g                = {0, false, 0, true};
    static constexpr component              b                = {0, false, 0, true};
    static constexpr component              a                = {0, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g8_b8r8_2plane_444_unorm >
{
    static constexpr ktl::u32               block_size       = 3;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 444;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, true, 1, true};
    static constexpr component              g                = {8, true, 0, true};
    static constexpr component              b                = {8, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r8_unorm},
                                                                plane{1, 1, ktl::api::format::v_r8g8_unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g10x6_b10x6r10x6_2plane_444_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 444;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, true, 1, true};
    static constexpr component              g                = {10, true, 0, true};
    static constexpr component              b                = {10, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r10x6_unorm_pack16},
                                                                plane{1, 1, ktl::api::format::v_r10x6g10x6_unorm_2pack16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g12x4_b12x4r12x4_2plane_444_unorm_3pack16 >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 444;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, true, 1, true};
    static constexpr component              g                = {12, true, 0, true};
    static constexpr component              b                = {12, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r12x4_unorm_pack16},
                                                                plane{1, 1, ktl::api::format::v_r12x4g12x4_unorm_2pack16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g16_b16r16_2plane_444_unorm >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 444;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, true, 1, true};
    static constexpr component              g                = {16, true, 0, true};
    static constexpr component              b                = {16, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r16_unorm},
                                                                plane{1, 1, ktl::api::format::v_r16g16_unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a4r4g4b4_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {4, false, 0, true};
    static constexpr component              g                = {4, false, 0, true};
    static constexpr component              b                = {4, false, 0, true};
    static constexpr component              a                = {4, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a4b4g4r4_unorm_pack16 >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {4, false, 0, true};
    static constexpr component              g                = {4, false, 0, true};
    static constexpr component              b                = {4, false, 0, true};
    static constexpr component              a                = {4, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16g16_sfixed5_nv >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {16, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r10x6_uint_pack16_arm >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r10x6g10x6_uint_2pack16_arm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r10x6g10x6b10x6a10x6_uint_4pack16_arm >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {10, false, 0, true};
    static constexpr component              g                = {10, false, 0, true};
    static constexpr component              b                = {10, false, 0, true};
    static constexpr component              a                = {10, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r12x4_uint_pack16_arm >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r12x4g12x4_uint_2pack16_arm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, false, 0, true};
    static constexpr component              g                = {12, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r12x4g12x4b12x4a12x4_uint_4pack16_arm >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {12, false, 0, true};
    static constexpr component              g                = {12, false, 0, true};
    static constexpr component              b                = {12, false, 0, true};
    static constexpr component              a                = {12, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r14x2_uint_pack16_arm >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {14, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r14x2g14x2_uint_2pack16_arm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {14, false, 0, true};
    static constexpr component              g                = {14, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r14x2g14x2b14x2a14x2_uint_4pack16_arm >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {14, false, 0, true};
    static constexpr component              g                = {14, false, 0, true};
    static constexpr component              b                = {14, false, 0, true};
    static constexpr component              a                = {14, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r14x2_unorm_pack16_arm >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {14, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r14x2g14x2_unorm_2pack16_arm >
{
    static constexpr ktl::u32               block_size       = 4;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {14, false, 0, true};
    static constexpr component              g                = {14, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r14x2g14x2b14x2a14x2_unorm_4pack16_arm >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {14, false, 0, true};
    static constexpr component              g                = {14, false, 0, true};
    static constexpr component              b                = {14, false, 0, true};
    static constexpr component              a                = {14, false, 0, true};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g14x2_b14x2r14x2_2plane_420_unorm_3pack16_arm >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 420;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {14, true, 1, true};
    static constexpr component              g                = {14, true, 0, true};
    static constexpr component              b                = {14, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r14x2_unorm_pack16_arm},
                                                                plane{2, 2, ktl::api::format::v_r14x2g14x2_unorm_2pack16_arm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g14x2_b14x2r14x2_2plane_422_unorm_3pack16_arm >
{
    static constexpr ktl::u32               block_size       = 6;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 16;
    static constexpr ktl::u32               chroma           = 422;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {14, true, 1, true};
    static constexpr component              g                = {14, true, 0, true};
    static constexpr component              b                = {14, true, 1, true};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r14x2_unorm_pack16_arm},
                                                                plane{2, 1, ktl::api::format::v_r14x2g14x2_unorm_2pack16_arm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8_bool_arm >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r16_sfloat_fpencoding_bfloat16_arm >
{
    static constexpr ktl::u32               block_size       = 2;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {16, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8_sfloat_fpencoding_float8e4m3_arm >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r8_sfloat_fpencoding_float8e5m2_arm >
{
    static constexpr ktl::u32               block_size       = 1;
    static constexpr ktl::u32               texels_per_block = 1;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 0;
    static constexpr ktl::u32               block_height     = 0;
    static constexpr ktl::u32               block_depth      = 0;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {8, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr component              d                = {0, false, 0, false};
    static constexpr component              s                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

inline constexpr any_format
match(ktl::api::format _format) noexcept
{
    switch (_format)
    {
    case ktl::api::format::v_r4g4_unorm_pack8:
        return ktl::meta::format_cast< ktl::api::format::v_r4g4_unorm_pack8 >();
    case ktl::api::format::v_r4g4b4a4_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_r4g4b4a4_unorm_pack16 >();
    case ktl::api::format::v_b4g4r4a4_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_b4g4r4a4_unorm_pack16 >();
    case ktl::api::format::v_r5g6b5_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_r5g6b5_unorm_pack16 >();
    case ktl::api::format::v_b5g6r5_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_b5g6r5_unorm_pack16 >();
    case ktl::api::format::v_r5g5b5a1_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_r5g5b5a1_unorm_pack16 >();
    case ktl::api::format::v_b5g5r5a1_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_b5g5r5a1_unorm_pack16 >();
    case ktl::api::format::v_a1r5g5b5_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_a1r5g5b5_unorm_pack16 >();
    case ktl::api::format::v_a1b5g5r5_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_a1b5g5r5_unorm_pack16 >();
    case ktl::api::format::v_a8_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_a8_unorm >();
    case ktl::api::format::v_r8_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r8_unorm >();
    case ktl::api::format::v_r8_snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r8_snorm >();
    case ktl::api::format::v_r8_uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r8_uscaled >();
    case ktl::api::format::v_r8_sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r8_sscaled >();
    case ktl::api::format::v_r8_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r8_uint >();
    case ktl::api::format::v_r8_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r8_sint >();
    case ktl::api::format::v_r8_srgb:
        return ktl::meta::format_cast< ktl::api::format::v_r8_srgb >();
    case ktl::api::format::v_r8g8_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8_unorm >();
    case ktl::api::format::v_r8g8_snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8_snorm >();
    case ktl::api::format::v_r8g8_uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8_uscaled >();
    case ktl::api::format::v_r8g8_sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8_sscaled >();
    case ktl::api::format::v_r8g8_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8_uint >();
    case ktl::api::format::v_r8g8_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8_sint >();
    case ktl::api::format::v_r8g8_srgb:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8_srgb >();
    case ktl::api::format::v_r8g8b8_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8_unorm >();
    case ktl::api::format::v_r8g8b8_snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8_snorm >();
    case ktl::api::format::v_r8g8b8_uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8_uscaled >();
    case ktl::api::format::v_r8g8b8_sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8_sscaled >();
    case ktl::api::format::v_r8g8b8_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8_uint >();
    case ktl::api::format::v_r8g8b8_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8_sint >();
    case ktl::api::format::v_r8g8b8_srgb:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8_srgb >();
    case ktl::api::format::v_b8g8r8_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8_unorm >();
    case ktl::api::format::v_b8g8r8_snorm:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8_snorm >();
    case ktl::api::format::v_b8g8r8_uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8_uscaled >();
    case ktl::api::format::v_b8g8r8_sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8_sscaled >();
    case ktl::api::format::v_b8g8r8_uint:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8_uint >();
    case ktl::api::format::v_b8g8r8_sint:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8_sint >();
    case ktl::api::format::v_b8g8r8_srgb:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8_srgb >();
    case ktl::api::format::v_r8g8b8a8_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8a8_unorm >();
    case ktl::api::format::v_r8g8b8a8_snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8a8_snorm >();
    case ktl::api::format::v_r8g8b8a8_uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8a8_uscaled >();
    case ktl::api::format::v_r8g8b8a8_sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8a8_sscaled >();
    case ktl::api::format::v_r8g8b8a8_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8a8_uint >();
    case ktl::api::format::v_r8g8b8a8_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8a8_sint >();
    case ktl::api::format::v_r8g8b8a8_srgb:
        return ktl::meta::format_cast< ktl::api::format::v_r8g8b8a8_srgb >();
    case ktl::api::format::v_b8g8r8a8_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8a8_unorm >();
    case ktl::api::format::v_b8g8r8a8_snorm:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8a8_snorm >();
    case ktl::api::format::v_b8g8r8a8_uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8a8_uscaled >();
    case ktl::api::format::v_b8g8r8a8_sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8a8_sscaled >();
    case ktl::api::format::v_b8g8r8a8_uint:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8a8_uint >();
    case ktl::api::format::v_b8g8r8a8_sint:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8a8_sint >();
    case ktl::api::format::v_b8g8r8a8_srgb:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8a8_srgb >();
    case ktl::api::format::v_a8b8g8r8_unorm_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a8b8g8r8_unorm_pack32 >();
    case ktl::api::format::v_a8b8g8r8_snorm_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a8b8g8r8_snorm_pack32 >();
    case ktl::api::format::v_a8b8g8r8_uscaled_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a8b8g8r8_uscaled_pack32 >();
    case ktl::api::format::v_a8b8g8r8_sscaled_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a8b8g8r8_sscaled_pack32 >();
    case ktl::api::format::v_a8b8g8r8_uint_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a8b8g8r8_uint_pack32 >();
    case ktl::api::format::v_a8b8g8r8_sint_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a8b8g8r8_sint_pack32 >();
    case ktl::api::format::v_a8b8g8r8_srgb_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a8b8g8r8_srgb_pack32 >();
    case ktl::api::format::v_a2r10g10b10_unorm_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2r10g10b10_unorm_pack32 >();
    case ktl::api::format::v_a2r10g10b10_snorm_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2r10g10b10_snorm_pack32 >();
    case ktl::api::format::v_a2r10g10b10_uscaled_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2r10g10b10_uscaled_pack32 >();
    case ktl::api::format::v_a2r10g10b10_sscaled_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2r10g10b10_sscaled_pack32 >();
    case ktl::api::format::v_a2r10g10b10_uint_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2r10g10b10_uint_pack32 >();
    case ktl::api::format::v_a2r10g10b10_sint_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2r10g10b10_sint_pack32 >();
    case ktl::api::format::v_a2b10g10r10_unorm_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2b10g10r10_unorm_pack32 >();
    case ktl::api::format::v_a2b10g10r10_snorm_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2b10g10r10_snorm_pack32 >();
    case ktl::api::format::v_a2b10g10r10_uscaled_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2b10g10r10_uscaled_pack32 >();
    case ktl::api::format::v_a2b10g10r10_sscaled_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2b10g10r10_sscaled_pack32 >();
    case ktl::api::format::v_a2b10g10r10_uint_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2b10g10r10_uint_pack32 >();
    case ktl::api::format::v_a2b10g10r10_sint_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_a2b10g10r10_sint_pack32 >();
    case ktl::api::format::v_r16_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r16_unorm >();
    case ktl::api::format::v_r16_snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r16_snorm >();
    case ktl::api::format::v_r16_uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r16_uscaled >();
    case ktl::api::format::v_r16_sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r16_sscaled >();
    case ktl::api::format::v_r16_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r16_uint >();
    case ktl::api::format::v_r16_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r16_sint >();
    case ktl::api::format::v_r16_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r16_sfloat >();
    case ktl::api::format::v_r16g16_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16_unorm >();
    case ktl::api::format::v_r16g16_snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16_snorm >();
    case ktl::api::format::v_r16g16_uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16_uscaled >();
    case ktl::api::format::v_r16g16_sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16_sscaled >();
    case ktl::api::format::v_r16g16_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16_uint >();
    case ktl::api::format::v_r16g16_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16_sint >();
    case ktl::api::format::v_r16g16_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16_sfloat >();
    case ktl::api::format::v_r16g16b16_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16_unorm >();
    case ktl::api::format::v_r16g16b16_snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16_snorm >();
    case ktl::api::format::v_r16g16b16_uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16_uscaled >();
    case ktl::api::format::v_r16g16b16_sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16_sscaled >();
    case ktl::api::format::v_r16g16b16_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16_uint >();
    case ktl::api::format::v_r16g16b16_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16_sint >();
    case ktl::api::format::v_r16g16b16_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16_sfloat >();
    case ktl::api::format::v_r16g16b16a16_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16a16_unorm >();
    case ktl::api::format::v_r16g16b16a16_snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16a16_snorm >();
    case ktl::api::format::v_r16g16b16a16_uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16a16_uscaled >();
    case ktl::api::format::v_r16g16b16a16_sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16a16_sscaled >();
    case ktl::api::format::v_r16g16b16a16_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16a16_uint >();
    case ktl::api::format::v_r16g16b16a16_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16a16_sint >();
    case ktl::api::format::v_r16g16b16a16_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16b16a16_sfloat >();
    case ktl::api::format::v_r32_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r32_uint >();
    case ktl::api::format::v_r32_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r32_sint >();
    case ktl::api::format::v_r32_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r32_sfloat >();
    case ktl::api::format::v_r32g32_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r32g32_uint >();
    case ktl::api::format::v_r32g32_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r32g32_sint >();
    case ktl::api::format::v_r32g32_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r32g32_sfloat >();
    case ktl::api::format::v_r32g32b32_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r32g32b32_uint >();
    case ktl::api::format::v_r32g32b32_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r32g32b32_sint >();
    case ktl::api::format::v_r32g32b32_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r32g32b32_sfloat >();
    case ktl::api::format::v_r32g32b32a32_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r32g32b32a32_uint >();
    case ktl::api::format::v_r32g32b32a32_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r32g32b32a32_sint >();
    case ktl::api::format::v_r32g32b32a32_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r32g32b32a32_sfloat >();
    case ktl::api::format::v_r64_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r64_uint >();
    case ktl::api::format::v_r64_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r64_sint >();
    case ktl::api::format::v_r64_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r64_sfloat >();
    case ktl::api::format::v_r64g64_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r64g64_uint >();
    case ktl::api::format::v_r64g64_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r64g64_sint >();
    case ktl::api::format::v_r64g64_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r64g64_sfloat >();
    case ktl::api::format::v_r64g64b64_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r64g64b64_uint >();
    case ktl::api::format::v_r64g64b64_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r64g64b64_sint >();
    case ktl::api::format::v_r64g64b64_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r64g64b64_sfloat >();
    case ktl::api::format::v_r64g64b64a64_uint:
        return ktl::meta::format_cast< ktl::api::format::v_r64g64b64a64_uint >();
    case ktl::api::format::v_r64g64b64a64_sint:
        return ktl::meta::format_cast< ktl::api::format::v_r64g64b64a64_sint >();
    case ktl::api::format::v_r64g64b64a64_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r64g64b64a64_sfloat >();
    case ktl::api::format::v_b10g11r11_ufloat_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_b10g11r11_ufloat_pack32 >();
    case ktl::api::format::v_e5b9g9r9_ufloat_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_e5b9g9r9_ufloat_pack32 >();
    case ktl::api::format::v_d16_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_d16_unorm >();
    case ktl::api::format::v_x8_d24_unorm_pack32:
        return ktl::meta::format_cast< ktl::api::format::v_x8_d24_unorm_pack32 >();
    case ktl::api::format::v_d32_sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_d32_sfloat >();
    case ktl::api::format::v_s8_uint:
        return ktl::meta::format_cast< ktl::api::format::v_s8_uint >();
    case ktl::api::format::v_d16_unorm_s8_uint:
        return ktl::meta::format_cast< ktl::api::format::v_d16_unorm_s8_uint >();
    case ktl::api::format::v_d24_unorm_s8_uint:
        return ktl::meta::format_cast< ktl::api::format::v_d24_unorm_s8_uint >();
    case ktl::api::format::v_d32_sfloat_s8_uint:
        return ktl::meta::format_cast< ktl::api::format::v_d32_sfloat_s8_uint >();
    case ktl::api::format::v_bc1_rgb_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc1_rgb_unorm_block >();
    case ktl::api::format::v_bc1_rgb_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc1_rgb_srgb_block >();
    case ktl::api::format::v_bc1_rgba_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc1_rgba_unorm_block >();
    case ktl::api::format::v_bc1_rgba_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc1_rgba_srgb_block >();
    case ktl::api::format::v_bc2_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc2_unorm_block >();
    case ktl::api::format::v_bc2_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc2_srgb_block >();
    case ktl::api::format::v_bc3_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc3_unorm_block >();
    case ktl::api::format::v_bc3_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc3_srgb_block >();
    case ktl::api::format::v_bc4_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc4_unorm_block >();
    case ktl::api::format::v_bc4_snorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc4_snorm_block >();
    case ktl::api::format::v_bc5_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc5_unorm_block >();
    case ktl::api::format::v_bc5_snorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc5_snorm_block >();
    case ktl::api::format::v_bc6h_ufloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc6h_ufloat_block >();
    case ktl::api::format::v_bc6h_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc6h_sfloat_block >();
    case ktl::api::format::v_bc7_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc7_unorm_block >();
    case ktl::api::format::v_bc7_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc7_srgb_block >();
    case ktl::api::format::v_etc2_r8g8b8_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc2_r8g8b8_unorm_block >();
    case ktl::api::format::v_etc2_r8g8b8_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc2_r8g8b8_srgb_block >();
    case ktl::api::format::v_etc2_r8g8b8a1_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc2_r8g8b8a1_unorm_block >();
    case ktl::api::format::v_etc2_r8g8b8a1_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc2_r8g8b8a1_srgb_block >();
    case ktl::api::format::v_etc2_r8g8b8a8_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc2_r8g8b8a8_unorm_block >();
    case ktl::api::format::v_etc2_r8g8b8a8_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc2_r8g8b8a8_srgb_block >();
    case ktl::api::format::v_eac_r11_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_eac_r11_unorm_block >();
    case ktl::api::format::v_eac_r11_snorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_eac_r11_snorm_block >();
    case ktl::api::format::v_eac_r11g11_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_eac_r11g11_unorm_block >();
    case ktl::api::format::v_eac_r11g11_snorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_eac_r11g11_snorm_block >();
    case ktl::api::format::v_astc_4x4_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x4_unorm_block >();
    case ktl::api::format::v_astc_4x4_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x4_srgb_block >();
    case ktl::api::format::v_astc_5x4_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x4_unorm_block >();
    case ktl::api::format::v_astc_5x4_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x4_srgb_block >();
    case ktl::api::format::v_astc_5x5_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x5_unorm_block >();
    case ktl::api::format::v_astc_5x5_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x5_srgb_block >();
    case ktl::api::format::v_astc_6x5_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x5_unorm_block >();
    case ktl::api::format::v_astc_6x5_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x5_srgb_block >();
    case ktl::api::format::v_astc_6x6_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x6_unorm_block >();
    case ktl::api::format::v_astc_6x6_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x6_srgb_block >();
    case ktl::api::format::v_astc_8x5_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x5_unorm_block >();
    case ktl::api::format::v_astc_8x5_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x5_srgb_block >();
    case ktl::api::format::v_astc_8x6_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x6_unorm_block >();
    case ktl::api::format::v_astc_8x6_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x6_srgb_block >();
    case ktl::api::format::v_astc_8x8_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x8_unorm_block >();
    case ktl::api::format::v_astc_8x8_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x8_srgb_block >();
    case ktl::api::format::v_astc_10x5_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x5_unorm_block >();
    case ktl::api::format::v_astc_10x5_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x5_srgb_block >();
    case ktl::api::format::v_astc_10x6_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x6_unorm_block >();
    case ktl::api::format::v_astc_10x6_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x6_srgb_block >();
    case ktl::api::format::v_astc_10x8_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x8_unorm_block >();
    case ktl::api::format::v_astc_10x8_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x8_srgb_block >();
    case ktl::api::format::v_astc_10x10_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x10_unorm_block >();
    case ktl::api::format::v_astc_10x10_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x10_srgb_block >();
    case ktl::api::format::v_astc_12x10_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x10_unorm_block >();
    case ktl::api::format::v_astc_12x10_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x10_srgb_block >();
    case ktl::api::format::v_astc_12x12_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x12_unorm_block >();
    case ktl::api::format::v_astc_12x12_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x12_srgb_block >();
    case ktl::api::format::v_g8b8g8r8_422_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g8b8g8r8_422_unorm >();
    case ktl::api::format::v_b8g8r8g8_422_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_b8g8r8g8_422_unorm >();
    case ktl::api::format::v_g8_b8_r8_3plane_420_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g8_b8_r8_3plane_420_unorm >();
    case ktl::api::format::v_g8_b8r8_2plane_420_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g8_b8r8_2plane_420_unorm >();
    case ktl::api::format::v_g8_b8_r8_3plane_422_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g8_b8_r8_3plane_422_unorm >();
    case ktl::api::format::v_g8_b8r8_2plane_422_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g8_b8r8_2plane_422_unorm >();
    case ktl::api::format::v_g8_b8_r8_3plane_444_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g8_b8_r8_3plane_444_unorm >();
    case ktl::api::format::v_r10x6_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_r10x6_unorm_pack16 >();
    case ktl::api::format::v_r10x6g10x6_unorm_2pack16:
        return ktl::meta::format_cast< ktl::api::format::v_r10x6g10x6_unorm_2pack16 >();
    case ktl::api::format::v_r10x6g10x6b10x6a10x6_unorm_4pack16:
        return ktl::meta::format_cast< ktl::api::format::v_r10x6g10x6b10x6a10x6_unorm_4pack16 >();
    case ktl::api::format::v_g10x6b10x6g10x6r10x6_422_unorm_4pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g10x6b10x6g10x6r10x6_422_unorm_4pack16 >();
    case ktl::api::format::v_b10x6g10x6r10x6g10x6_422_unorm_4pack16:
        return ktl::meta::format_cast< ktl::api::format::v_b10x6g10x6r10x6g10x6_422_unorm_4pack16 >();
    case ktl::api::format::v_g10x6_b10x6_r10x6_3plane_420_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g10x6_b10x6_r10x6_3plane_420_unorm_3pack16 >();
    case ktl::api::format::v_g10x6_b10x6r10x6_2plane_420_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g10x6_b10x6r10x6_2plane_420_unorm_3pack16 >();
    case ktl::api::format::v_g10x6_b10x6_r10x6_3plane_422_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g10x6_b10x6_r10x6_3plane_422_unorm_3pack16 >();
    case ktl::api::format::v_g10x6_b10x6r10x6_2plane_422_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g10x6_b10x6r10x6_2plane_422_unorm_3pack16 >();
    case ktl::api::format::v_g10x6_b10x6_r10x6_3plane_444_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g10x6_b10x6_r10x6_3plane_444_unorm_3pack16 >();
    case ktl::api::format::v_r12x4_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_r12x4_unorm_pack16 >();
    case ktl::api::format::v_r12x4g12x4_unorm_2pack16:
        return ktl::meta::format_cast< ktl::api::format::v_r12x4g12x4_unorm_2pack16 >();
    case ktl::api::format::v_r12x4g12x4b12x4a12x4_unorm_4pack16:
        return ktl::meta::format_cast< ktl::api::format::v_r12x4g12x4b12x4a12x4_unorm_4pack16 >();
    case ktl::api::format::v_g12x4b12x4g12x4r12x4_422_unorm_4pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g12x4b12x4g12x4r12x4_422_unorm_4pack16 >();
    case ktl::api::format::v_b12x4g12x4r12x4g12x4_422_unorm_4pack16:
        return ktl::meta::format_cast< ktl::api::format::v_b12x4g12x4r12x4g12x4_422_unorm_4pack16 >();
    case ktl::api::format::v_g12x4_b12x4_r12x4_3plane_420_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g12x4_b12x4_r12x4_3plane_420_unorm_3pack16 >();
    case ktl::api::format::v_g12x4_b12x4r12x4_2plane_420_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g12x4_b12x4r12x4_2plane_420_unorm_3pack16 >();
    case ktl::api::format::v_g12x4_b12x4_r12x4_3plane_422_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g12x4_b12x4_r12x4_3plane_422_unorm_3pack16 >();
    case ktl::api::format::v_g12x4_b12x4r12x4_2plane_422_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g12x4_b12x4r12x4_2plane_422_unorm_3pack16 >();
    case ktl::api::format::v_g12x4_b12x4_r12x4_3plane_444_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g12x4_b12x4_r12x4_3plane_444_unorm_3pack16 >();
    case ktl::api::format::v_g16b16g16r16_422_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g16b16g16r16_422_unorm >();
    case ktl::api::format::v_b16g16r16g16_422_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_b16g16r16g16_422_unorm >();
    case ktl::api::format::v_g16_b16_r16_3plane_420_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g16_b16_r16_3plane_420_unorm >();
    case ktl::api::format::v_g16_b16r16_2plane_420_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g16_b16r16_2plane_420_unorm >();
    case ktl::api::format::v_g16_b16_r16_3plane_422_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g16_b16_r16_3plane_422_unorm >();
    case ktl::api::format::v_g16_b16r16_2plane_422_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g16_b16r16_2plane_422_unorm >();
    case ktl::api::format::v_g16_b16_r16_3plane_444_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g16_b16_r16_3plane_444_unorm >();
    case ktl::api::format::v_pvrtc1_2bpp_unorm_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc1_2bpp_unorm_block_img >();
    case ktl::api::format::v_pvrtc1_4bpp_unorm_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc1_4bpp_unorm_block_img >();
    case ktl::api::format::v_pvrtc2_2bpp_unorm_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc2_2bpp_unorm_block_img >();
    case ktl::api::format::v_pvrtc2_4bpp_unorm_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc2_4bpp_unorm_block_img >();
    case ktl::api::format::v_pvrtc1_2bpp_srgb_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc1_2bpp_srgb_block_img >();
    case ktl::api::format::v_pvrtc1_4bpp_srgb_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc1_4bpp_srgb_block_img >();
    case ktl::api::format::v_pvrtc2_2bpp_srgb_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc2_2bpp_srgb_block_img >();
    case ktl::api::format::v_pvrtc2_4bpp_srgb_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc2_4bpp_srgb_block_img >();
    case ktl::api::format::v_astc_4x4_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x4_sfloat_block >();
    case ktl::api::format::v_astc_5x4_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x4_sfloat_block >();
    case ktl::api::format::v_astc_5x5_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x5_sfloat_block >();
    case ktl::api::format::v_astc_6x5_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x5_sfloat_block >();
    case ktl::api::format::v_astc_6x6_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x6_sfloat_block >();
    case ktl::api::format::v_astc_8x5_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x5_sfloat_block >();
    case ktl::api::format::v_astc_8x6_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x6_sfloat_block >();
    case ktl::api::format::v_astc_8x8_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x8_sfloat_block >();
    case ktl::api::format::v_astc_10x5_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x5_sfloat_block >();
    case ktl::api::format::v_astc_10x6_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x6_sfloat_block >();
    case ktl::api::format::v_astc_10x8_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x8_sfloat_block >();
    case ktl::api::format::v_astc_10x10_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x10_sfloat_block >();
    case ktl::api::format::v_astc_12x10_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x10_sfloat_block >();
    case ktl::api::format::v_astc_12x12_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x12_sfloat_block >();
    case ktl::api::format::v_astc_3x3x3_unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_3x3x3_unorm_block_ext >();
    case ktl::api::format::v_astc_3x3x3_srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_3x3x3_srgb_block_ext >();
    case ktl::api::format::v_astc_3x3x3_sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_3x3x3_sfloat_block_ext >();
    case ktl::api::format::v_astc_4x3x3_unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x3x3_unorm_block_ext >();
    case ktl::api::format::v_astc_4x3x3_srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x3x3_srgb_block_ext >();
    case ktl::api::format::v_astc_4x3x3_sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x3x3_sfloat_block_ext >();
    case ktl::api::format::v_astc_4x4x3_unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x4x3_unorm_block_ext >();
    case ktl::api::format::v_astc_4x4x3_srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x4x3_srgb_block_ext >();
    case ktl::api::format::v_astc_4x4x3_sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x4x3_sfloat_block_ext >();
    case ktl::api::format::v_astc_4x4x4_unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x4x4_unorm_block_ext >();
    case ktl::api::format::v_astc_4x4x4_srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x4x4_srgb_block_ext >();
    case ktl::api::format::v_astc_4x4x4_sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x4x4_sfloat_block_ext >();
    case ktl::api::format::v_astc_5x4x4_unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x4x4_unorm_block_ext >();
    case ktl::api::format::v_astc_5x4x4_srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x4x4_srgb_block_ext >();
    case ktl::api::format::v_astc_5x4x4_sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x4x4_sfloat_block_ext >();
    case ktl::api::format::v_astc_5x5x4_unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x5x4_unorm_block_ext >();
    case ktl::api::format::v_astc_5x5x4_srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x5x4_srgb_block_ext >();
    case ktl::api::format::v_astc_5x5x4_sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x5x4_sfloat_block_ext >();
    case ktl::api::format::v_astc_5x5x5_unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x5x5_unorm_block_ext >();
    case ktl::api::format::v_astc_5x5x5_srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x5x5_srgb_block_ext >();
    case ktl::api::format::v_astc_5x5x5_sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x5x5_sfloat_block_ext >();
    case ktl::api::format::v_astc_6x5x5_unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x5x5_unorm_block_ext >();
    case ktl::api::format::v_astc_6x5x5_srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x5x5_srgb_block_ext >();
    case ktl::api::format::v_astc_6x5x5_sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x5x5_sfloat_block_ext >();
    case ktl::api::format::v_astc_6x6x5_unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x6x5_unorm_block_ext >();
    case ktl::api::format::v_astc_6x6x5_srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x6x5_srgb_block_ext >();
    case ktl::api::format::v_astc_6x6x5_sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x6x5_sfloat_block_ext >();
    case ktl::api::format::v_astc_6x6x6_unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x6x6_unorm_block_ext >();
    case ktl::api::format::v_astc_6x6x6_srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x6x6_srgb_block_ext >();
    case ktl::api::format::v_astc_6x6x6_sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x6x6_sfloat_block_ext >();
    case ktl::api::format::v_g8_b8r8_2plane_444_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g8_b8r8_2plane_444_unorm >();
    case ktl::api::format::v_g10x6_b10x6r10x6_2plane_444_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g10x6_b10x6r10x6_2plane_444_unorm_3pack16 >();
    case ktl::api::format::v_g12x4_b12x4r12x4_2plane_444_unorm_3pack16:
        return ktl::meta::format_cast< ktl::api::format::v_g12x4_b12x4r12x4_2plane_444_unorm_3pack16 >();
    case ktl::api::format::v_g16_b16r16_2plane_444_unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g16_b16r16_2plane_444_unorm >();
    case ktl::api::format::v_a4r4g4b4_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_a4r4g4b4_unorm_pack16 >();
    case ktl::api::format::v_a4b4g4r4_unorm_pack16:
        return ktl::meta::format_cast< ktl::api::format::v_a4b4g4r4_unorm_pack16 >();
    case ktl::api::format::v_r16g16_sfixed5_nv:
        return ktl::meta::format_cast< ktl::api::format::v_r16g16_sfixed5_nv >();
    case ktl::api::format::v_r10x6_uint_pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r10x6_uint_pack16_arm >();
    case ktl::api::format::v_r10x6g10x6_uint_2pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r10x6g10x6_uint_2pack16_arm >();
    case ktl::api::format::v_r10x6g10x6b10x6a10x6_uint_4pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r10x6g10x6b10x6a10x6_uint_4pack16_arm >();
    case ktl::api::format::v_r12x4_uint_pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r12x4_uint_pack16_arm >();
    case ktl::api::format::v_r12x4g12x4_uint_2pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r12x4g12x4_uint_2pack16_arm >();
    case ktl::api::format::v_r12x4g12x4b12x4a12x4_uint_4pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r12x4g12x4b12x4a12x4_uint_4pack16_arm >();
    case ktl::api::format::v_r14x2_uint_pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r14x2_uint_pack16_arm >();
    case ktl::api::format::v_r14x2g14x2_uint_2pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r14x2g14x2_uint_2pack16_arm >();
    case ktl::api::format::v_r14x2g14x2b14x2a14x2_uint_4pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r14x2g14x2b14x2a14x2_uint_4pack16_arm >();
    case ktl::api::format::v_r14x2_unorm_pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r14x2_unorm_pack16_arm >();
    case ktl::api::format::v_r14x2g14x2_unorm_2pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r14x2g14x2_unorm_2pack16_arm >();
    case ktl::api::format::v_r14x2g14x2b14x2a14x2_unorm_4pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r14x2g14x2b14x2a14x2_unorm_4pack16_arm >();
    case ktl::api::format::v_g14x2_b14x2r14x2_2plane_420_unorm_3pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_g14x2_b14x2r14x2_2plane_420_unorm_3pack16_arm >();
    case ktl::api::format::v_g14x2_b14x2r14x2_2plane_422_unorm_3pack16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_g14x2_b14x2r14x2_2plane_422_unorm_3pack16_arm >();
    case ktl::api::format::v_r8_bool_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r8_bool_arm >();
    case ktl::api::format::v_r16_sfloat_fpencoding_bfloat16_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r16_sfloat_fpencoding_bfloat16_arm >();
    case ktl::api::format::v_r8_sfloat_fpencoding_float8e4m3_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r8_sfloat_fpencoding_float8e4m3_arm >();
    case ktl::api::format::v_r8_sfloat_fpencoding_float8e5m2_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r8_sfloat_fpencoding_float8e5m2_arm >();
    default:
        return ktl::meta::format_cast< ktl::api::format::v_undefined >();
    }
}
} // namespace ktl::meta

#endif
