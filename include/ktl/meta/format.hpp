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
}

template <>
struct format< ktl::api::format::v_r_4g_4unorm_pack_8 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_4g_4b_4a_4unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_4g_4r_4a_4unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_5g_6b_5unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_5g_6r_5unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_5g_5b_5a_1unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_5g_5r_5a_1unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_1r_5g_5b_5unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_1b_5g_5r_5unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_8unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8snorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8uscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8sscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8srgb >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8snorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8uscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8sscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8srgb >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8snorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8uscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8sscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8srgb >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8snorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8uscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8sscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8srgb >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8a_8unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8a_8snorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8a_8uscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8a_8sscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8a_8uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8a_8sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8g_8b_8a_8srgb >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8a_8unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8a_8snorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8a_8uscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8a_8sscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8a_8uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8a_8sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8a_8srgb >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_8b_8g_8r_8unorm_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_8b_8g_8r_8snorm_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_8b_8g_8r_8uscaled_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_8b_8g_8r_8sscaled_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_8b_8g_8r_8uint_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_8b_8g_8r_8sint_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_8b_8g_8r_8srgb_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2r_10g_10b_10unorm_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2r_10g_10b_10snorm_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2r_10g_10b_10uscaled_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2r_10g_10b_10sscaled_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2r_10g_10b_10uint_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2r_10g_10b_10sint_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2b_10g_10r_10unorm_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2b_10g_10r_10snorm_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2b_10g_10r_10uscaled_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2b_10g_10r_10sscaled_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2b_10g_10r_10uint_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_2b_10g_10r_10sint_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16snorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16uscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16sscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16snorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16uscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16sscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16snorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16uscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16sscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16a_16unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16a_16snorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16a_16uscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16a_16sscaled >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16a_16uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16a_16sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16b_16a_16sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32g_32uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32g_32sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32g_32sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32g_32b_32uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32g_32b_32sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32g_32b_32sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32g_32b_32a_32uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32g_32b_32a_32sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_32g_32b_32a_32sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64g_64uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64g_64sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64g_64sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64g_64b_64uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64g_64b_64sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64g_64b_64sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64g_64b_64a_64uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64g_64b_64a_64sint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_64g_64b_64a_64sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_10g_11r_11ufloat_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_e_5b_9g_9r_9ufloat_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_d_16unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_x_8d_24unorm_pack_32 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_d_32sfloat >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_s_8uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_d_16unorm_s_8uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_d_24unorm_s_8uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_d_32sfloat_s_8uint >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_1rgb_unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_1rgb_srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_1rgba_unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_1rgba_srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_2unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_2srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_3unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_3srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_4unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_4snorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_5unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_5snorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_6h_ufloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_6h_sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_7unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_bc_7srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc_2r_8g_8b_8unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc_2r_8g_8b_8srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc_2r_8g_8b_8a_1unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc_2r_8g_8b_8a_1srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc_2r_8g_8b_8a_8unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_etc_2r_8g_8b_8a_8srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_eac_r_11unorm_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {11, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_eac_r_11snorm_block >
{
    static constexpr ktl::u32               block_size       = 8;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {11, false, 0, true};
    static constexpr component              g                = {0, false, 0, false};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_eac_r_11g_11unorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {11, false, 0, true};
    static constexpr component              g                = {11, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_eac_r_11g_11snorm_block >
{
    static constexpr ktl::u32               block_size       = 16;
    static constexpr ktl::u32               texels_per_block = 16;
    static constexpr ktl::u32               packed           = 0;
    static constexpr ktl::u32               chroma           = 0;
    static constexpr ktl::u32               block_width      = 4;
    static constexpr ktl::u32               block_height     = 4;
    static constexpr ktl::u32               block_depth      = 1;
    static constexpr bool                   is_3d            = false;
    static constexpr bool                   is_compressed    = false;
    static constexpr component              r                = {11, false, 0, true};
    static constexpr component              g                = {11, false, 0, true};
    static constexpr component              b                = {0, false, 0, false};
    static constexpr component              a                = {0, false, 0, false};
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_4unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_4srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_4unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_4srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_5unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_5srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_5unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_5srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_6unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_6srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x_5unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x_5srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x_6unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x_6srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x_8unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x_8srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_5unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_5srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_6unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_6srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_8unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_8srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_10unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_10srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x_10unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x_10srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x_12unorm_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x_12srgb_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_8b_8g_8r_8422unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_8g_8r_8g_8422unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_8b_8r_83plane_420unorm >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_8unorm},
                                                                plane{2, 2, ktl::api::format::v_r_8unorm},
                                                                plane{2, 2, ktl::api::format::v_r_8unorm}};
};

template <>
struct format< ktl::api::format::v_g_8b_8r_82plane_420unorm >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_8unorm},
                                                                plane{2, 2, ktl::api::format::v_r_8g_8unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_8b_8r_83plane_422unorm >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_8unorm},
                                                                plane{2, 1, ktl::api::format::v_r_8unorm},
                                                                plane{2, 1, ktl::api::format::v_r_8unorm}};
};

template <>
struct format< ktl::api::format::v_g_8b_8r_82plane_422unorm >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_8unorm},
                                                                plane{2, 1, ktl::api::format::v_r_8g_8unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_8b_8r_83plane_444unorm >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_8unorm},
                                                                plane{1, 1, ktl::api::format::v_r_8unorm},
                                                                plane{1, 1, ktl::api::format::v_r_8unorm}};
};

template <>
struct format< ktl::api::format::v_r_10x_6unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_10x_6g_10x_6unorm_2pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_10x_6g_10x_6b_10x_6a_10x_6unorm_4pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_10x_6b_10x_6g_10x_6r_10x_6422unorm_4pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_10x_6g_10x_6r_10x_6g_10x_6422unorm_4pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_10x_6b_10x_6r_10x_63plane_420unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_10x_6unorm_pack_16},
                                                                plane{2, 2, ktl::api::format::v_r_10x_6unorm_pack_16},
                                                                plane{2, 2, ktl::api::format::v_r_10x_6unorm_pack_16}};
};

template <>
struct format< ktl::api::format::v_g_10x_6b_10x_6r_10x_62plane_420unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_10x_6unorm_pack_16},
                                                                plane{2, 2, ktl::api::format::v_r_10x_6g_10x_6unorm_2pack_16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_10x_6b_10x_6r_10x_63plane_422unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_10x_6unorm_pack_16},
                                                                plane{2, 1, ktl::api::format::v_r_10x_6unorm_pack_16},
                                                                plane{2, 1, ktl::api::format::v_r_10x_6unorm_pack_16}};
};

template <>
struct format< ktl::api::format::v_g_10x_6b_10x_6r_10x_62plane_422unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_10x_6unorm_pack_16},
                                                                plane{2, 1, ktl::api::format::v_r_10x_6g_10x_6unorm_2pack_16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_10x_6b_10x_6r_10x_63plane_444unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_10x_6unorm_pack_16},
                                                                plane{1, 1, ktl::api::format::v_r_10x_6unorm_pack_16},
                                                                plane{1, 1, ktl::api::format::v_r_10x_6unorm_pack_16}};
};

template <>
struct format< ktl::api::format::v_r_12x_4unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_12x_4g_12x_4unorm_2pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_12x_4g_12x_4b_12x_4a_12x_4unorm_4pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_12x_4b_12x_4g_12x_4r_12x_4422unorm_4pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_12x_4g_12x_4r_12x_4g_12x_4422unorm_4pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_12x_4b_12x_4r_12x_43plane_420unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_12x_4unorm_pack_16},
                                                                plane{2, 2, ktl::api::format::v_r_12x_4unorm_pack_16},
                                                                plane{2, 2, ktl::api::format::v_r_12x_4unorm_pack_16}};
};

template <>
struct format< ktl::api::format::v_g_12x_4b_12x_4r_12x_42plane_420unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_12x_4unorm_pack_16},
                                                                plane{2, 2, ktl::api::format::v_r_12x_4g_12x_4unorm_2pack_16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_12x_4b_12x_4r_12x_43plane_422unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_12x_4unorm_pack_16},
                                                                plane{2, 1, ktl::api::format::v_r_12x_4unorm_pack_16},
                                                                plane{2, 1, ktl::api::format::v_r_12x_4unorm_pack_16}};
};

template <>
struct format< ktl::api::format::v_g_12x_4b_12x_4r_12x_42plane_422unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_12x_4unorm_pack_16},
                                                                plane{2, 1, ktl::api::format::v_r_12x_4g_12x_4unorm_2pack_16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_12x_4b_12x_4r_12x_43plane_444unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_12x_4unorm_pack_16},
                                                                plane{1, 1, ktl::api::format::v_r_12x_4unorm_pack_16},
                                                                plane{1, 1, ktl::api::format::v_r_12x_4unorm_pack_16}};
};

template <>
struct format< ktl::api::format::v_g_16b_16g_16r_16422unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_b_16g_16r_16g_16422unorm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_16b_16r_163plane_420unorm >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_16unorm},
                                                                plane{2, 2, ktl::api::format::v_r_16unorm},
                                                                plane{2, 2, ktl::api::format::v_r_16unorm}};
};

template <>
struct format< ktl::api::format::v_g_16b_16r_162plane_420unorm >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_16unorm},
                                                                plane{2, 2, ktl::api::format::v_r_16g_16unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_16b_16r_163plane_422unorm >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_16unorm},
                                                                plane{2, 1, ktl::api::format::v_r_16unorm},
                                                                plane{2, 1, ktl::api::format::v_r_16unorm}};
};

template <>
struct format< ktl::api::format::v_g_16b_16r_162plane_422unorm >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_16unorm},
                                                                plane{2, 1, ktl::api::format::v_r_16g_16unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_16b_16r_163plane_444unorm >
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
    static constexpr ktl::u32               planes_amount    = 3;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_16unorm},
                                                                plane{1, 1, ktl::api::format::v_r_16unorm},
                                                                plane{1, 1, ktl::api::format::v_r_16unorm}};
};

template <>
struct format< ktl::api::format::v_pvrtc_12bpp_unorm_block_img >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc_14bpp_unorm_block_img >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc_22bpp_unorm_block_img >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc_24bpp_unorm_block_img >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc_12bpp_srgb_block_img >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc_14bpp_srgb_block_img >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc_22bpp_srgb_block_img >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_pvrtc_24bpp_srgb_block_img >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_4sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_4sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_5sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_5sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_6sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x_5sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x_6sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_8x_8sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_5sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_6sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_8sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_10x_10sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x_10sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_12x_12sfloat_block >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_3x_3x_3unorm_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_3x_3x_3srgb_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_3x_3x_3sfloat_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_3x_3unorm_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_3x_3srgb_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_3x_3sfloat_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_4x_3unorm_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_4x_3srgb_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_4x_3sfloat_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_4x_4unorm_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_4x_4srgb_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_4x_4x_4sfloat_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_4x_4unorm_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_4x_4srgb_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_4x_4sfloat_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_5x_4unorm_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_5x_4srgb_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_5x_4sfloat_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_5x_5unorm_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_5x_5srgb_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_5x_5x_5sfloat_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_5x_5unorm_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_5x_5srgb_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_5x_5sfloat_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_6x_5unorm_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_6x_5srgb_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_6x_5sfloat_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_6x_6unorm_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_6x_6srgb_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_astc_6x_6x_6sfloat_block_ext >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_8b_8r_82plane_444unorm >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_8unorm},
                                                                plane{1, 1, ktl::api::format::v_r_8g_8unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_10x_6b_10x_6r_10x_62plane_444unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_10x_6unorm_pack_16},
                                                                plane{1, 1, ktl::api::format::v_r_10x_6g_10x_6unorm_2pack_16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_12x_4b_12x_4r_12x_42plane_444unorm_3pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_12x_4unorm_pack_16},
                                                                plane{1, 1, ktl::api::format::v_r_12x_4g_12x_4unorm_2pack_16},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_16b_16r_162plane_444unorm >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes           = {plane{1, 1, ktl::api::format::v_r_16unorm},
                                                                plane{1, 1, ktl::api::format::v_r_16g_16unorm},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_4r_4g_4b_4unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_a_4b_4g_4r_4unorm_pack_16 >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16g_16sfixed_5nv >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_10x_6uint_pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_10x_6g_10x_6uint_2pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_10x_6g_10x_6b_10x_6a_10x_6uint_4pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_12x_4uint_pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_12x_4g_12x_4uint_2pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_12x_4g_12x_4b_12x_4a_12x_4uint_4pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_14x_2uint_pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_14x_2g_14x_2uint_2pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_14x_2g_14x_2b_14x_2a_14x_2uint_4pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_14x_2unorm_pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_14x_2g_14x_2unorm_2pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_14x_2g_14x_2b_14x_2a_14x_2unorm_4pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_14x_2b_14x_2r_14x_22plane_420unorm_3pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes = {plane{1, 1, ktl::api::format::v_r_14x_2unorm_pack_16arm},
                                                      plane{2, 2, ktl::api::format::v_r_14x_2g_14x_2unorm_2pack_16arm},
                                                      plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_g_14x_2b_14x_2r_14x_22plane_422unorm_3pack_16arm >
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
    static constexpr ktl::u32               planes_amount    = 2;
    static constexpr std::array< plane, 3 > planes = {plane{1, 1, ktl::api::format::v_r_14x_2unorm_pack_16arm},
                                                      plane{2, 1, ktl::api::format::v_r_14x_2g_14x_2unorm_2pack_16arm},
                                                      plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8bool_arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_16sfloat_fpencoding_bfloat_16arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8sfloat_fpencoding_float_8e_4m_3arm >
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
    static constexpr ktl::u32               planes_amount    = 0;
    static constexpr std::array< plane, 3 > planes           = {plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined},
                                                                plane{0, 0, ktl::api::format::v_undefined}};
};

template <>
struct format< ktl::api::format::v_r_8sfloat_fpencoding_float_8e_5m_2arm >
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
    case ktl::api::format::v_r_4g_4unorm_pack_8:
        return ktl::meta::format_cast< ktl::api::format::v_r_4g_4unorm_pack_8 >();
    case ktl::api::format::v_r_4g_4b_4a_4unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_r_4g_4b_4a_4unorm_pack_16 >();
    case ktl::api::format::v_b_4g_4r_4a_4unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_b_4g_4r_4a_4unorm_pack_16 >();
    case ktl::api::format::v_r_5g_6b_5unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_r_5g_6b_5unorm_pack_16 >();
    case ktl::api::format::v_b_5g_6r_5unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_b_5g_6r_5unorm_pack_16 >();
    case ktl::api::format::v_r_5g_5b_5a_1unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_r_5g_5b_5a_1unorm_pack_16 >();
    case ktl::api::format::v_b_5g_5r_5a_1unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_b_5g_5r_5a_1unorm_pack_16 >();
    case ktl::api::format::v_a_1r_5g_5b_5unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_a_1r_5g_5b_5unorm_pack_16 >();
    case ktl::api::format::v_a_1b_5g_5r_5unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_a_1b_5g_5r_5unorm_pack_16 >();
    case ktl::api::format::v_a_8unorm:
        return ktl::meta::format_cast< ktl::api::format::v_a_8unorm >();
    case ktl::api::format::v_r_8unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_8unorm >();
    case ktl::api::format::v_r_8snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_8snorm >();
    case ktl::api::format::v_r_8uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_8uscaled >();
    case ktl::api::format::v_r_8sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_8sscaled >();
    case ktl::api::format::v_r_8uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_8uint >();
    case ktl::api::format::v_r_8sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_8sint >();
    case ktl::api::format::v_r_8srgb:
        return ktl::meta::format_cast< ktl::api::format::v_r_8srgb >();
    case ktl::api::format::v_r_8g_8unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8unorm >();
    case ktl::api::format::v_r_8g_8snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8snorm >();
    case ktl::api::format::v_r_8g_8uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8uscaled >();
    case ktl::api::format::v_r_8g_8sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8sscaled >();
    case ktl::api::format::v_r_8g_8uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8uint >();
    case ktl::api::format::v_r_8g_8sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8sint >();
    case ktl::api::format::v_r_8g_8srgb:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8srgb >();
    case ktl::api::format::v_r_8g_8b_8unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8unorm >();
    case ktl::api::format::v_r_8g_8b_8snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8snorm >();
    case ktl::api::format::v_r_8g_8b_8uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8uscaled >();
    case ktl::api::format::v_r_8g_8b_8sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8sscaled >();
    case ktl::api::format::v_r_8g_8b_8uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8uint >();
    case ktl::api::format::v_r_8g_8b_8sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8sint >();
    case ktl::api::format::v_r_8g_8b_8srgb:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8srgb >();
    case ktl::api::format::v_b_8g_8r_8unorm:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8unorm >();
    case ktl::api::format::v_b_8g_8r_8snorm:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8snorm >();
    case ktl::api::format::v_b_8g_8r_8uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8uscaled >();
    case ktl::api::format::v_b_8g_8r_8sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8sscaled >();
    case ktl::api::format::v_b_8g_8r_8uint:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8uint >();
    case ktl::api::format::v_b_8g_8r_8sint:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8sint >();
    case ktl::api::format::v_b_8g_8r_8srgb:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8srgb >();
    case ktl::api::format::v_r_8g_8b_8a_8unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8a_8unorm >();
    case ktl::api::format::v_r_8g_8b_8a_8snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8a_8snorm >();
    case ktl::api::format::v_r_8g_8b_8a_8uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8a_8uscaled >();
    case ktl::api::format::v_r_8g_8b_8a_8sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8a_8sscaled >();
    case ktl::api::format::v_r_8g_8b_8a_8uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8a_8uint >();
    case ktl::api::format::v_r_8g_8b_8a_8sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8a_8sint >();
    case ktl::api::format::v_r_8g_8b_8a_8srgb:
        return ktl::meta::format_cast< ktl::api::format::v_r_8g_8b_8a_8srgb >();
    case ktl::api::format::v_b_8g_8r_8a_8unorm:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8a_8unorm >();
    case ktl::api::format::v_b_8g_8r_8a_8snorm:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8a_8snorm >();
    case ktl::api::format::v_b_8g_8r_8a_8uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8a_8uscaled >();
    case ktl::api::format::v_b_8g_8r_8a_8sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8a_8sscaled >();
    case ktl::api::format::v_b_8g_8r_8a_8uint:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8a_8uint >();
    case ktl::api::format::v_b_8g_8r_8a_8sint:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8a_8sint >();
    case ktl::api::format::v_b_8g_8r_8a_8srgb:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8a_8srgb >();
    case ktl::api::format::v_a_8b_8g_8r_8unorm_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_8b_8g_8r_8unorm_pack_32 >();
    case ktl::api::format::v_a_8b_8g_8r_8snorm_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_8b_8g_8r_8snorm_pack_32 >();
    case ktl::api::format::v_a_8b_8g_8r_8uscaled_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_8b_8g_8r_8uscaled_pack_32 >();
    case ktl::api::format::v_a_8b_8g_8r_8sscaled_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_8b_8g_8r_8sscaled_pack_32 >();
    case ktl::api::format::v_a_8b_8g_8r_8uint_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_8b_8g_8r_8uint_pack_32 >();
    case ktl::api::format::v_a_8b_8g_8r_8sint_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_8b_8g_8r_8sint_pack_32 >();
    case ktl::api::format::v_a_8b_8g_8r_8srgb_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_8b_8g_8r_8srgb_pack_32 >();
    case ktl::api::format::v_a_2r_10g_10b_10unorm_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2r_10g_10b_10unorm_pack_32 >();
    case ktl::api::format::v_a_2r_10g_10b_10snorm_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2r_10g_10b_10snorm_pack_32 >();
    case ktl::api::format::v_a_2r_10g_10b_10uscaled_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2r_10g_10b_10uscaled_pack_32 >();
    case ktl::api::format::v_a_2r_10g_10b_10sscaled_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2r_10g_10b_10sscaled_pack_32 >();
    case ktl::api::format::v_a_2r_10g_10b_10uint_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2r_10g_10b_10uint_pack_32 >();
    case ktl::api::format::v_a_2r_10g_10b_10sint_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2r_10g_10b_10sint_pack_32 >();
    case ktl::api::format::v_a_2b_10g_10r_10unorm_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2b_10g_10r_10unorm_pack_32 >();
    case ktl::api::format::v_a_2b_10g_10r_10snorm_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2b_10g_10r_10snorm_pack_32 >();
    case ktl::api::format::v_a_2b_10g_10r_10uscaled_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2b_10g_10r_10uscaled_pack_32 >();
    case ktl::api::format::v_a_2b_10g_10r_10sscaled_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2b_10g_10r_10sscaled_pack_32 >();
    case ktl::api::format::v_a_2b_10g_10r_10uint_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2b_10g_10r_10uint_pack_32 >();
    case ktl::api::format::v_a_2b_10g_10r_10sint_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_a_2b_10g_10r_10sint_pack_32 >();
    case ktl::api::format::v_r_16unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_16unorm >();
    case ktl::api::format::v_r_16snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_16snorm >();
    case ktl::api::format::v_r_16uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_16uscaled >();
    case ktl::api::format::v_r_16sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_16sscaled >();
    case ktl::api::format::v_r_16uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_16uint >();
    case ktl::api::format::v_r_16sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_16sint >();
    case ktl::api::format::v_r_16sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_16sfloat >();
    case ktl::api::format::v_r_16g_16unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16unorm >();
    case ktl::api::format::v_r_16g_16snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16snorm >();
    case ktl::api::format::v_r_16g_16uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16uscaled >();
    case ktl::api::format::v_r_16g_16sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16sscaled >();
    case ktl::api::format::v_r_16g_16uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16uint >();
    case ktl::api::format::v_r_16g_16sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16sint >();
    case ktl::api::format::v_r_16g_16sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16sfloat >();
    case ktl::api::format::v_r_16g_16b_16unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16unorm >();
    case ktl::api::format::v_r_16g_16b_16snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16snorm >();
    case ktl::api::format::v_r_16g_16b_16uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16uscaled >();
    case ktl::api::format::v_r_16g_16b_16sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16sscaled >();
    case ktl::api::format::v_r_16g_16b_16uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16uint >();
    case ktl::api::format::v_r_16g_16b_16sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16sint >();
    case ktl::api::format::v_r_16g_16b_16sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16sfloat >();
    case ktl::api::format::v_r_16g_16b_16a_16unorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16a_16unorm >();
    case ktl::api::format::v_r_16g_16b_16a_16snorm:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16a_16snorm >();
    case ktl::api::format::v_r_16g_16b_16a_16uscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16a_16uscaled >();
    case ktl::api::format::v_r_16g_16b_16a_16sscaled:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16a_16sscaled >();
    case ktl::api::format::v_r_16g_16b_16a_16uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16a_16uint >();
    case ktl::api::format::v_r_16g_16b_16a_16sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16a_16sint >();
    case ktl::api::format::v_r_16g_16b_16a_16sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16b_16a_16sfloat >();
    case ktl::api::format::v_r_32uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_32uint >();
    case ktl::api::format::v_r_32sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_32sint >();
    case ktl::api::format::v_r_32sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_32sfloat >();
    case ktl::api::format::v_r_32g_32uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_32g_32uint >();
    case ktl::api::format::v_r_32g_32sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_32g_32sint >();
    case ktl::api::format::v_r_32g_32sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_32g_32sfloat >();
    case ktl::api::format::v_r_32g_32b_32uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_32g_32b_32uint >();
    case ktl::api::format::v_r_32g_32b_32sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_32g_32b_32sint >();
    case ktl::api::format::v_r_32g_32b_32sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_32g_32b_32sfloat >();
    case ktl::api::format::v_r_32g_32b_32a_32uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_32g_32b_32a_32uint >();
    case ktl::api::format::v_r_32g_32b_32a_32sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_32g_32b_32a_32sint >();
    case ktl::api::format::v_r_32g_32b_32a_32sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_32g_32b_32a_32sfloat >();
    case ktl::api::format::v_r_64uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_64uint >();
    case ktl::api::format::v_r_64sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_64sint >();
    case ktl::api::format::v_r_64sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_64sfloat >();
    case ktl::api::format::v_r_64g_64uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_64g_64uint >();
    case ktl::api::format::v_r_64g_64sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_64g_64sint >();
    case ktl::api::format::v_r_64g_64sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_64g_64sfloat >();
    case ktl::api::format::v_r_64g_64b_64uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_64g_64b_64uint >();
    case ktl::api::format::v_r_64g_64b_64sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_64g_64b_64sint >();
    case ktl::api::format::v_r_64g_64b_64sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_64g_64b_64sfloat >();
    case ktl::api::format::v_r_64g_64b_64a_64uint:
        return ktl::meta::format_cast< ktl::api::format::v_r_64g_64b_64a_64uint >();
    case ktl::api::format::v_r_64g_64b_64a_64sint:
        return ktl::meta::format_cast< ktl::api::format::v_r_64g_64b_64a_64sint >();
    case ktl::api::format::v_r_64g_64b_64a_64sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_r_64g_64b_64a_64sfloat >();
    case ktl::api::format::v_b_10g_11r_11ufloat_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_b_10g_11r_11ufloat_pack_32 >();
    case ktl::api::format::v_e_5b_9g_9r_9ufloat_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_e_5b_9g_9r_9ufloat_pack_32 >();
    case ktl::api::format::v_d_16unorm:
        return ktl::meta::format_cast< ktl::api::format::v_d_16unorm >();
    case ktl::api::format::v_x_8d_24unorm_pack_32:
        return ktl::meta::format_cast< ktl::api::format::v_x_8d_24unorm_pack_32 >();
    case ktl::api::format::v_d_32sfloat:
        return ktl::meta::format_cast< ktl::api::format::v_d_32sfloat >();
    case ktl::api::format::v_s_8uint:
        return ktl::meta::format_cast< ktl::api::format::v_s_8uint >();
    case ktl::api::format::v_d_16unorm_s_8uint:
        return ktl::meta::format_cast< ktl::api::format::v_d_16unorm_s_8uint >();
    case ktl::api::format::v_d_24unorm_s_8uint:
        return ktl::meta::format_cast< ktl::api::format::v_d_24unorm_s_8uint >();
    case ktl::api::format::v_d_32sfloat_s_8uint:
        return ktl::meta::format_cast< ktl::api::format::v_d_32sfloat_s_8uint >();
    case ktl::api::format::v_bc_1rgb_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_1rgb_unorm_block >();
    case ktl::api::format::v_bc_1rgb_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_1rgb_srgb_block >();
    case ktl::api::format::v_bc_1rgba_unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_1rgba_unorm_block >();
    case ktl::api::format::v_bc_1rgba_srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_1rgba_srgb_block >();
    case ktl::api::format::v_bc_2unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_2unorm_block >();
    case ktl::api::format::v_bc_2srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_2srgb_block >();
    case ktl::api::format::v_bc_3unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_3unorm_block >();
    case ktl::api::format::v_bc_3srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_3srgb_block >();
    case ktl::api::format::v_bc_4unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_4unorm_block >();
    case ktl::api::format::v_bc_4snorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_4snorm_block >();
    case ktl::api::format::v_bc_5unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_5unorm_block >();
    case ktl::api::format::v_bc_5snorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_5snorm_block >();
    case ktl::api::format::v_bc_6h_ufloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_6h_ufloat_block >();
    case ktl::api::format::v_bc_6h_sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_6h_sfloat_block >();
    case ktl::api::format::v_bc_7unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_7unorm_block >();
    case ktl::api::format::v_bc_7srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_bc_7srgb_block >();
    case ktl::api::format::v_etc_2r_8g_8b_8unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc_2r_8g_8b_8unorm_block >();
    case ktl::api::format::v_etc_2r_8g_8b_8srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc_2r_8g_8b_8srgb_block >();
    case ktl::api::format::v_etc_2r_8g_8b_8a_1unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc_2r_8g_8b_8a_1unorm_block >();
    case ktl::api::format::v_etc_2r_8g_8b_8a_1srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc_2r_8g_8b_8a_1srgb_block >();
    case ktl::api::format::v_etc_2r_8g_8b_8a_8unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc_2r_8g_8b_8a_8unorm_block >();
    case ktl::api::format::v_etc_2r_8g_8b_8a_8srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_etc_2r_8g_8b_8a_8srgb_block >();
    case ktl::api::format::v_eac_r_11unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_eac_r_11unorm_block >();
    case ktl::api::format::v_eac_r_11snorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_eac_r_11snorm_block >();
    case ktl::api::format::v_eac_r_11g_11unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_eac_r_11g_11unorm_block >();
    case ktl::api::format::v_eac_r_11g_11snorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_eac_r_11g_11snorm_block >();
    case ktl::api::format::v_astc_4x_4unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_4unorm_block >();
    case ktl::api::format::v_astc_4x_4srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_4srgb_block >();
    case ktl::api::format::v_astc_5x_4unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_4unorm_block >();
    case ktl::api::format::v_astc_5x_4srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_4srgb_block >();
    case ktl::api::format::v_astc_5x_5unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_5unorm_block >();
    case ktl::api::format::v_astc_5x_5srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_5srgb_block >();
    case ktl::api::format::v_astc_6x_5unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_5unorm_block >();
    case ktl::api::format::v_astc_6x_5srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_5srgb_block >();
    case ktl::api::format::v_astc_6x_6unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_6unorm_block >();
    case ktl::api::format::v_astc_6x_6srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_6srgb_block >();
    case ktl::api::format::v_astc_8x_5unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x_5unorm_block >();
    case ktl::api::format::v_astc_8x_5srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x_5srgb_block >();
    case ktl::api::format::v_astc_8x_6unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x_6unorm_block >();
    case ktl::api::format::v_astc_8x_6srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x_6srgb_block >();
    case ktl::api::format::v_astc_8x_8unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x_8unorm_block >();
    case ktl::api::format::v_astc_8x_8srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x_8srgb_block >();
    case ktl::api::format::v_astc_10x_5unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_5unorm_block >();
    case ktl::api::format::v_astc_10x_5srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_5srgb_block >();
    case ktl::api::format::v_astc_10x_6unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_6unorm_block >();
    case ktl::api::format::v_astc_10x_6srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_6srgb_block >();
    case ktl::api::format::v_astc_10x_8unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_8unorm_block >();
    case ktl::api::format::v_astc_10x_8srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_8srgb_block >();
    case ktl::api::format::v_astc_10x_10unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_10unorm_block >();
    case ktl::api::format::v_astc_10x_10srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_10srgb_block >();
    case ktl::api::format::v_astc_12x_10unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x_10unorm_block >();
    case ktl::api::format::v_astc_12x_10srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x_10srgb_block >();
    case ktl::api::format::v_astc_12x_12unorm_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x_12unorm_block >();
    case ktl::api::format::v_astc_12x_12srgb_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x_12srgb_block >();
    case ktl::api::format::v_g_8b_8g_8r_8422unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_8b_8g_8r_8422unorm >();
    case ktl::api::format::v_b_8g_8r_8g_8422unorm:
        return ktl::meta::format_cast< ktl::api::format::v_b_8g_8r_8g_8422unorm >();
    case ktl::api::format::v_g_8b_8r_83plane_420unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_8b_8r_83plane_420unorm >();
    case ktl::api::format::v_g_8b_8r_82plane_420unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_8b_8r_82plane_420unorm >();
    case ktl::api::format::v_g_8b_8r_83plane_422unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_8b_8r_83plane_422unorm >();
    case ktl::api::format::v_g_8b_8r_82plane_422unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_8b_8r_82plane_422unorm >();
    case ktl::api::format::v_g_8b_8r_83plane_444unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_8b_8r_83plane_444unorm >();
    case ktl::api::format::v_r_10x_6unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_r_10x_6unorm_pack_16 >();
    case ktl::api::format::v_r_10x_6g_10x_6unorm_2pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_r_10x_6g_10x_6unorm_2pack_16 >();
    case ktl::api::format::v_r_10x_6g_10x_6b_10x_6a_10x_6unorm_4pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_r_10x_6g_10x_6b_10x_6a_10x_6unorm_4pack_16 >();
    case ktl::api::format::v_g_10x_6b_10x_6g_10x_6r_10x_6422unorm_4pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_10x_6b_10x_6g_10x_6r_10x_6422unorm_4pack_16 >();
    case ktl::api::format::v_b_10x_6g_10x_6r_10x_6g_10x_6422unorm_4pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_b_10x_6g_10x_6r_10x_6g_10x_6422unorm_4pack_16 >();
    case ktl::api::format::v_g_10x_6b_10x_6r_10x_63plane_420unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_10x_6b_10x_6r_10x_63plane_420unorm_3pack_16 >();
    case ktl::api::format::v_g_10x_6b_10x_6r_10x_62plane_420unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_10x_6b_10x_6r_10x_62plane_420unorm_3pack_16 >();
    case ktl::api::format::v_g_10x_6b_10x_6r_10x_63plane_422unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_10x_6b_10x_6r_10x_63plane_422unorm_3pack_16 >();
    case ktl::api::format::v_g_10x_6b_10x_6r_10x_62plane_422unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_10x_6b_10x_6r_10x_62plane_422unorm_3pack_16 >();
    case ktl::api::format::v_g_10x_6b_10x_6r_10x_63plane_444unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_10x_6b_10x_6r_10x_63plane_444unorm_3pack_16 >();
    case ktl::api::format::v_r_12x_4unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_r_12x_4unorm_pack_16 >();
    case ktl::api::format::v_r_12x_4g_12x_4unorm_2pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_r_12x_4g_12x_4unorm_2pack_16 >();
    case ktl::api::format::v_r_12x_4g_12x_4b_12x_4a_12x_4unorm_4pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_r_12x_4g_12x_4b_12x_4a_12x_4unorm_4pack_16 >();
    case ktl::api::format::v_g_12x_4b_12x_4g_12x_4r_12x_4422unorm_4pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_12x_4b_12x_4g_12x_4r_12x_4422unorm_4pack_16 >();
    case ktl::api::format::v_b_12x_4g_12x_4r_12x_4g_12x_4422unorm_4pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_b_12x_4g_12x_4r_12x_4g_12x_4422unorm_4pack_16 >();
    case ktl::api::format::v_g_12x_4b_12x_4r_12x_43plane_420unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_12x_4b_12x_4r_12x_43plane_420unorm_3pack_16 >();
    case ktl::api::format::v_g_12x_4b_12x_4r_12x_42plane_420unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_12x_4b_12x_4r_12x_42plane_420unorm_3pack_16 >();
    case ktl::api::format::v_g_12x_4b_12x_4r_12x_43plane_422unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_12x_4b_12x_4r_12x_43plane_422unorm_3pack_16 >();
    case ktl::api::format::v_g_12x_4b_12x_4r_12x_42plane_422unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_12x_4b_12x_4r_12x_42plane_422unorm_3pack_16 >();
    case ktl::api::format::v_g_12x_4b_12x_4r_12x_43plane_444unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_12x_4b_12x_4r_12x_43plane_444unorm_3pack_16 >();
    case ktl::api::format::v_g_16b_16g_16r_16422unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_16b_16g_16r_16422unorm >();
    case ktl::api::format::v_b_16g_16r_16g_16422unorm:
        return ktl::meta::format_cast< ktl::api::format::v_b_16g_16r_16g_16422unorm >();
    case ktl::api::format::v_g_16b_16r_163plane_420unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_16b_16r_163plane_420unorm >();
    case ktl::api::format::v_g_16b_16r_162plane_420unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_16b_16r_162plane_420unorm >();
    case ktl::api::format::v_g_16b_16r_163plane_422unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_16b_16r_163plane_422unorm >();
    case ktl::api::format::v_g_16b_16r_162plane_422unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_16b_16r_162plane_422unorm >();
    case ktl::api::format::v_g_16b_16r_163plane_444unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_16b_16r_163plane_444unorm >();
    case ktl::api::format::v_pvrtc_12bpp_unorm_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc_12bpp_unorm_block_img >();
    case ktl::api::format::v_pvrtc_14bpp_unorm_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc_14bpp_unorm_block_img >();
    case ktl::api::format::v_pvrtc_22bpp_unorm_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc_22bpp_unorm_block_img >();
    case ktl::api::format::v_pvrtc_24bpp_unorm_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc_24bpp_unorm_block_img >();
    case ktl::api::format::v_pvrtc_12bpp_srgb_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc_12bpp_srgb_block_img >();
    case ktl::api::format::v_pvrtc_14bpp_srgb_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc_14bpp_srgb_block_img >();
    case ktl::api::format::v_pvrtc_22bpp_srgb_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc_22bpp_srgb_block_img >();
    case ktl::api::format::v_pvrtc_24bpp_srgb_block_img:
        return ktl::meta::format_cast< ktl::api::format::v_pvrtc_24bpp_srgb_block_img >();
    case ktl::api::format::v_astc_4x_4sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_4sfloat_block >();
    case ktl::api::format::v_astc_5x_4sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_4sfloat_block >();
    case ktl::api::format::v_astc_5x_5sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_5sfloat_block >();
    case ktl::api::format::v_astc_6x_5sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_5sfloat_block >();
    case ktl::api::format::v_astc_6x_6sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_6sfloat_block >();
    case ktl::api::format::v_astc_8x_5sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x_5sfloat_block >();
    case ktl::api::format::v_astc_8x_6sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x_6sfloat_block >();
    case ktl::api::format::v_astc_8x_8sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_8x_8sfloat_block >();
    case ktl::api::format::v_astc_10x_5sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_5sfloat_block >();
    case ktl::api::format::v_astc_10x_6sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_6sfloat_block >();
    case ktl::api::format::v_astc_10x_8sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_8sfloat_block >();
    case ktl::api::format::v_astc_10x_10sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_10x_10sfloat_block >();
    case ktl::api::format::v_astc_12x_10sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x_10sfloat_block >();
    case ktl::api::format::v_astc_12x_12sfloat_block:
        return ktl::meta::format_cast< ktl::api::format::v_astc_12x_12sfloat_block >();
    case ktl::api::format::v_astc_3x_3x_3unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_3x_3x_3unorm_block_ext >();
    case ktl::api::format::v_astc_3x_3x_3srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_3x_3x_3srgb_block_ext >();
    case ktl::api::format::v_astc_3x_3x_3sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_3x_3x_3sfloat_block_ext >();
    case ktl::api::format::v_astc_4x_3x_3unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_3x_3unorm_block_ext >();
    case ktl::api::format::v_astc_4x_3x_3srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_3x_3srgb_block_ext >();
    case ktl::api::format::v_astc_4x_3x_3sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_3x_3sfloat_block_ext >();
    case ktl::api::format::v_astc_4x_4x_3unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_4x_3unorm_block_ext >();
    case ktl::api::format::v_astc_4x_4x_3srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_4x_3srgb_block_ext >();
    case ktl::api::format::v_astc_4x_4x_3sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_4x_3sfloat_block_ext >();
    case ktl::api::format::v_astc_4x_4x_4unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_4x_4unorm_block_ext >();
    case ktl::api::format::v_astc_4x_4x_4srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_4x_4srgb_block_ext >();
    case ktl::api::format::v_astc_4x_4x_4sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_4x_4x_4sfloat_block_ext >();
    case ktl::api::format::v_astc_5x_4x_4unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_4x_4unorm_block_ext >();
    case ktl::api::format::v_astc_5x_4x_4srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_4x_4srgb_block_ext >();
    case ktl::api::format::v_astc_5x_4x_4sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_4x_4sfloat_block_ext >();
    case ktl::api::format::v_astc_5x_5x_4unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_5x_4unorm_block_ext >();
    case ktl::api::format::v_astc_5x_5x_4srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_5x_4srgb_block_ext >();
    case ktl::api::format::v_astc_5x_5x_4sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_5x_4sfloat_block_ext >();
    case ktl::api::format::v_astc_5x_5x_5unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_5x_5unorm_block_ext >();
    case ktl::api::format::v_astc_5x_5x_5srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_5x_5srgb_block_ext >();
    case ktl::api::format::v_astc_5x_5x_5sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_5x_5x_5sfloat_block_ext >();
    case ktl::api::format::v_astc_6x_5x_5unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_5x_5unorm_block_ext >();
    case ktl::api::format::v_astc_6x_5x_5srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_5x_5srgb_block_ext >();
    case ktl::api::format::v_astc_6x_5x_5sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_5x_5sfloat_block_ext >();
    case ktl::api::format::v_astc_6x_6x_5unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_6x_5unorm_block_ext >();
    case ktl::api::format::v_astc_6x_6x_5srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_6x_5srgb_block_ext >();
    case ktl::api::format::v_astc_6x_6x_5sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_6x_5sfloat_block_ext >();
    case ktl::api::format::v_astc_6x_6x_6unorm_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_6x_6unorm_block_ext >();
    case ktl::api::format::v_astc_6x_6x_6srgb_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_6x_6srgb_block_ext >();
    case ktl::api::format::v_astc_6x_6x_6sfloat_block_ext:
        return ktl::meta::format_cast< ktl::api::format::v_astc_6x_6x_6sfloat_block_ext >();
    case ktl::api::format::v_g_8b_8r_82plane_444unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_8b_8r_82plane_444unorm >();
    case ktl::api::format::v_g_10x_6b_10x_6r_10x_62plane_444unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_10x_6b_10x_6r_10x_62plane_444unorm_3pack_16 >();
    case ktl::api::format::v_g_12x_4b_12x_4r_12x_42plane_444unorm_3pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_g_12x_4b_12x_4r_12x_42plane_444unorm_3pack_16 >();
    case ktl::api::format::v_g_16b_16r_162plane_444unorm:
        return ktl::meta::format_cast< ktl::api::format::v_g_16b_16r_162plane_444unorm >();
    case ktl::api::format::v_a_4r_4g_4b_4unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_a_4r_4g_4b_4unorm_pack_16 >();
    case ktl::api::format::v_a_4b_4g_4r_4unorm_pack_16:
        return ktl::meta::format_cast< ktl::api::format::v_a_4b_4g_4r_4unorm_pack_16 >();
    case ktl::api::format::v_r_16g_16sfixed_5nv:
        return ktl::meta::format_cast< ktl::api::format::v_r_16g_16sfixed_5nv >();
    case ktl::api::format::v_r_10x_6uint_pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_10x_6uint_pack_16arm >();
    case ktl::api::format::v_r_10x_6g_10x_6uint_2pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_10x_6g_10x_6uint_2pack_16arm >();
    case ktl::api::format::v_r_10x_6g_10x_6b_10x_6a_10x_6uint_4pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_10x_6g_10x_6b_10x_6a_10x_6uint_4pack_16arm >();
    case ktl::api::format::v_r_12x_4uint_pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_12x_4uint_pack_16arm >();
    case ktl::api::format::v_r_12x_4g_12x_4uint_2pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_12x_4g_12x_4uint_2pack_16arm >();
    case ktl::api::format::v_r_12x_4g_12x_4b_12x_4a_12x_4uint_4pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_12x_4g_12x_4b_12x_4a_12x_4uint_4pack_16arm >();
    case ktl::api::format::v_r_14x_2uint_pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_14x_2uint_pack_16arm >();
    case ktl::api::format::v_r_14x_2g_14x_2uint_2pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_14x_2g_14x_2uint_2pack_16arm >();
    case ktl::api::format::v_r_14x_2g_14x_2b_14x_2a_14x_2uint_4pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_14x_2g_14x_2b_14x_2a_14x_2uint_4pack_16arm >();
    case ktl::api::format::v_r_14x_2unorm_pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_14x_2unorm_pack_16arm >();
    case ktl::api::format::v_r_14x_2g_14x_2unorm_2pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_14x_2g_14x_2unorm_2pack_16arm >();
    case ktl::api::format::v_r_14x_2g_14x_2b_14x_2a_14x_2unorm_4pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_14x_2g_14x_2b_14x_2a_14x_2unorm_4pack_16arm >();
    case ktl::api::format::v_g_14x_2b_14x_2r_14x_22plane_420unorm_3pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_g_14x_2b_14x_2r_14x_22plane_420unorm_3pack_16arm >();
    case ktl::api::format::v_g_14x_2b_14x_2r_14x_22plane_422unorm_3pack_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_g_14x_2b_14x_2r_14x_22plane_422unorm_3pack_16arm >();
    case ktl::api::format::v_r_8bool_arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_8bool_arm >();
    case ktl::api::format::v_r_16sfloat_fpencoding_bfloat_16arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_16sfloat_fpencoding_bfloat_16arm >();
    case ktl::api::format::v_r_8sfloat_fpencoding_float_8e_4m_3arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_8sfloat_fpencoding_float_8e_4m_3arm >();
    case ktl::api::format::v_r_8sfloat_fpencoding_float_8e_5m_2arm:
        return ktl::meta::format_cast< ktl::api::format::v_r_8sfloat_fpencoding_float_8e_5m_2arm >();
    default:
        return ktl::meta::format_cast< ktl::api::format::v_undefined >();
    }
}
} // namespace ktl::meta

#endif
