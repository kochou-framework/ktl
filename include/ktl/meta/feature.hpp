#ifndef KTL_META_FEATURE_HPP
#define KTL_META_FEATURE_HPP

#include <ktl/api.hpp>
namespace ktl::meta
{
template < ktl::api::feature >
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
};

template <>
struct feature< ktl::api::feature::robust_buffer_access >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::robust_buffer_access;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, robust_buffer_access);
};
template <>
struct feature< ktl::api::feature::full_draw_index_uint_32 >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::full_draw_index_uint_32;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, full_draw_index_uint_32);
};
template <>
struct feature< ktl::api::feature::image_cube_array >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::image_cube_array;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, image_cube_array);
};
template <>
struct feature< ktl::api::feature::independent_blend >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::independent_blend;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, independent_blend);
};
template <>
struct feature< ktl::api::feature::geometry_shader >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::geometry_shader;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, geometry_shader);
};
template <>
struct feature< ktl::api::feature::tessellation_shader >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::tessellation_shader;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, tessellation_shader);
};
template <>
struct feature< ktl::api::feature::sample_rate_shading >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::sample_rate_shading;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, sample_rate_shading);
};
template <>
struct feature< ktl::api::feature::dual_src_blend >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::dual_src_blend;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, dual_src_blend);
};
template <>
struct feature< ktl::api::feature::logic_op >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::logic_op;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field = offsetof(ktl::api::physical_device_features, logic_op);
};
template <>
struct feature< ktl::api::feature::multi_draw_indirect >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::multi_draw_indirect;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, multi_draw_indirect);
};
template <>
struct feature< ktl::api::feature::draw_indirect_first_instance >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::draw_indirect_first_instance;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, draw_indirect_first_instance);
};
template <>
struct feature< ktl::api::feature::depth_clamp >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::depth_clamp;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, depth_clamp);
};
template <>
struct feature< ktl::api::feature::depth_bias_clamp >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::depth_bias_clamp;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, depth_bias_clamp);
};
template <>
struct feature< ktl::api::feature::fill_mode_non_solid >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::fill_mode_non_solid;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, fill_mode_non_solid);
};
template <>
struct feature< ktl::api::feature::depth_bounds >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::depth_bounds;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, depth_bounds);
};
template <>
struct feature< ktl::api::feature::wide_lines >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::wide_lines;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field = offsetof(ktl::api::physical_device_features, wide_lines);
};
template <>
struct feature< ktl::api::feature::large_points >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::large_points;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, large_points);
};
template <>
struct feature< ktl::api::feature::alpha_to_one >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::alpha_to_one;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, alpha_to_one);
};
template <>
struct feature< ktl::api::feature::multi_viewport >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::multi_viewport;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, multi_viewport);
};
template <>
struct feature< ktl::api::feature::sampler_anisotropy >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::sampler_anisotropy;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, sampler_anisotropy);
};
template <>
struct feature< ktl::api::feature::texture_compression_etc_2 >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::texture_compression_etc_2;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, texture_compression_etc_2);
};
template <>
struct feature< ktl::api::feature::texture_compression_astc_ldr >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::texture_compression_astc_ldr;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, texture_compression_astc_ldr);
};
template <>
struct feature< ktl::api::feature::texture_compression_bc >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::texture_compression_bc;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, texture_compression_bc);
};
template <>
struct feature< ktl::api::feature::occlusion_query_precise >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::occlusion_query_precise;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, occlusion_query_precise);
};
template <>
struct feature< ktl::api::feature::pipeline_statistics_query >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::pipeline_statistics_query;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, pipeline_statistics_query);
};
template <>
struct feature< ktl::api::feature::vertex_pipeline_stores_and_atomics >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::vertex_pipeline_stores_and_atomics;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, vertex_pipeline_stores_and_atomics);
};
template <>
struct feature< ktl::api::feature::fragment_stores_and_atomics >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::fragment_stores_and_atomics;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, fragment_stores_and_atomics);
};
template <>
struct feature< ktl::api::feature::shader_tessellation_and_geometry_point_size >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_tessellation_and_geometry_point_size;
    static constexpr bool                     is_core = true;
    static constexpr ktl::api::structure_type stype   = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, shader_tessellation_and_geometry_point_size);
};
template <>
struct feature< ktl::api::feature::shader_image_gather_extended >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::shader_image_gather_extended;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, shader_image_gather_extended);
};
template <>
struct feature< ktl::api::feature::shader_storage_image_extended_formats >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::shader_storage_image_extended_formats;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, shader_storage_image_extended_formats);
};
template <>
struct feature< ktl::api::feature::shader_storage_image_multisample >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::shader_storage_image_multisample;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, shader_storage_image_multisample);
};
template <>
struct feature< ktl::api::feature::shader_storage_image_read_without_format >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_storage_image_read_without_format;
    static constexpr bool                     is_core = true;
    static constexpr ktl::api::structure_type stype   = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, shader_storage_image_read_without_format);
};
template <>
struct feature< ktl::api::feature::shader_storage_image_write_without_format >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_storage_image_write_without_format;
    static constexpr bool                     is_core = true;
    static constexpr ktl::api::structure_type stype   = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, shader_storage_image_write_without_format);
};
template <>
struct feature< ktl::api::feature::shader_uniform_buffer_array_dynamic_indexing >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_uniform_buffer_array_dynamic_indexing;
    static constexpr bool                     is_core = true;
    static constexpr ktl::api::structure_type stype   = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, shader_uniform_buffer_array_dynamic_indexing);
};
template <>
struct feature< ktl::api::feature::shader_sampled_image_array_dynamic_indexing >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_sampled_image_array_dynamic_indexing;
    static constexpr bool                     is_core = true;
    static constexpr ktl::api::structure_type stype   = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, shader_sampled_image_array_dynamic_indexing);
};
template <>
struct feature< ktl::api::feature::shader_storage_buffer_array_dynamic_indexing >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_storage_buffer_array_dynamic_indexing;
    static constexpr bool                     is_core = true;
    static constexpr ktl::api::structure_type stype   = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, shader_storage_buffer_array_dynamic_indexing);
};
template <>
struct feature< ktl::api::feature::shader_storage_image_array_dynamic_indexing >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_storage_image_array_dynamic_indexing;
    static constexpr bool                     is_core = true;
    static constexpr ktl::api::structure_type stype   = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, shader_storage_image_array_dynamic_indexing);
};
template <>
struct feature< ktl::api::feature::shader_clip_distance >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::shader_clip_distance;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, shader_clip_distance);
};
template <>
struct feature< ktl::api::feature::shader_cull_distance >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::shader_cull_distance;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, shader_cull_distance);
};
template <>
struct feature< ktl::api::feature::shader_float_64 >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::shader_float_64;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, shader_float_64);
};
template <>
struct feature< ktl::api::feature::shader_int_64 >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::shader_int_64;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, shader_int_64);
};
template <>
struct feature< ktl::api::feature::shader_int_16 >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::shader_int_16;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, shader_int_16);
};
template <>
struct feature< ktl::api::feature::shader_resource_residency >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::shader_resource_residency;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, shader_resource_residency);
};
template <>
struct feature< ktl::api::feature::shader_resource_min_lod >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::shader_resource_min_lod;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, shader_resource_min_lod);
};
template <>
struct feature< ktl::api::feature::sparse_binding >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::sparse_binding;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, sparse_binding);
};
template <>
struct feature< ktl::api::feature::sparse_residency_buffer >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::sparse_residency_buffer;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, sparse_residency_buffer);
};
template <>
struct feature< ktl::api::feature::sparse_residency_image_2d >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::sparse_residency_image_2d;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, sparse_residency_image_2d);
};
template <>
struct feature< ktl::api::feature::sparse_residency_image_3d >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::sparse_residency_image_3d;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, sparse_residency_image_3d);
};
template <>
struct feature< ktl::api::feature::sparse_residency_2samples >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::sparse_residency_2samples;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, sparse_residency_2samples);
};
template <>
struct feature< ktl::api::feature::sparse_residency_4samples >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::sparse_residency_4samples;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, sparse_residency_4samples);
};
template <>
struct feature< ktl::api::feature::sparse_residency_8samples >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::sparse_residency_8samples;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, sparse_residency_8samples);
};
template <>
struct feature< ktl::api::feature::sparse_residency_16samples >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::sparse_residency_16samples;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, sparse_residency_16samples);
};
template <>
struct feature< ktl::api::feature::sparse_residency_aliased >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::sparse_residency_aliased;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, sparse_residency_aliased);
};
template <>
struct feature< ktl::api::feature::variable_multisample_rate >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::variable_multisample_rate;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize               offsetof_field =
        offsetof(ktl::api::physical_device_features, variable_multisample_rate);
};
template <>
struct feature< ktl::api::feature::inherited_queries >
{
    static constexpr ktl::api::feature        value          = ktl::api::feature::inherited_queries;
    static constexpr bool                     is_core        = true;
    static constexpr ktl::api::structure_type stype          = {};
    static constexpr ktl::usize               sizeof_struct  = sizeof(ktl::api::physical_device_features);
    static constexpr ktl::usize               offsetof_stype = 0;
    static constexpr ktl::usize               offsetof_pnext = 0;
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_features, inherited_queries);
};
template <>
struct feature< ktl::api::feature::sci_buf_import_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sci_buf_import_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_memory_sci_buf_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_external_memory_sci_buf_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_memory_sci_buf_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_memory_sci_buf_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_memory_sci_buf_features_nv, sci_buf_import_nv);
};
template <>
struct feature< ktl::api::feature::sci_buf_export_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sci_buf_export_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_memory_sci_buf_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_external_memory_sci_buf_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_memory_sci_buf_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_memory_sci_buf_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_memory_sci_buf_features_nv, sci_buf_export_nv);
};
template <>
struct feature< ktl::api::feature::device_generated_commands_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_generated_commands_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_device_generated_commands_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_device_generated_commands_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_device_generated_commands_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_device_generated_commands_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_device_generated_commands_features_nv, device_generated_commands_nv);
};
template <>
struct feature< ktl::api::feature::push_constant_bank_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::push_constant_bank_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_push_constant_bank_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_push_constant_bank_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_push_constant_bank_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_push_constant_bank_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_push_constant_bank_features_nv, push_constant_bank_nv);
};
template <>
struct feature< ktl::api::feature::device_generated_compute_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_generated_compute_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_device_generated_commands_compute_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_device_generated_commands_compute_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_device_generated_commands_compute_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_device_generated_commands_compute_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_device_generated_commands_compute_features_nv, device_generated_compute_nv);
};
template <>
struct feature< ktl::api::feature::device_generated_compute_pipelines_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_generated_compute_pipelines_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_device_generated_commands_compute_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_device_generated_commands_compute_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_device_generated_commands_compute_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_device_generated_commands_compute_features_nv, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_device_generated_commands_compute_features_nv, device_generated_compute_pipelines_nv);
};
template <>
struct feature< ktl::api::feature::device_generated_compute_capture_replay_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_generated_compute_capture_replay_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_device_generated_commands_compute_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_device_generated_commands_compute_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_device_generated_commands_compute_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_device_generated_commands_compute_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_device_generated_commands_compute_features_nv,
                 device_generated_compute_capture_replay_nv);
};
template <>
struct feature< ktl::api::feature::private_data >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::private_data;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_private_data_features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_private_data_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_private_data_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_private_data_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_private_data_features, private_data);
};
template <>
struct feature< ktl::api::feature::cluster_acceleration_structure_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cluster_acceleration_structure_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cluster_acceleration_structure_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_cluster_acceleration_structure_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cluster_acceleration_structure_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cluster_acceleration_structure_features_nv, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_cluster_acceleration_structure_features_nv, cluster_acceleration_structure_nv);
};
template <>
struct feature< ktl::api::feature::variable_pointers_storage_buffer >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::variable_pointers_storage_buffer;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_variable_pointers_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_variable_pointers_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_variable_pointers_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_variable_pointers_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_variable_pointers_features, variable_pointers_storage_buffer);
};
template <>
struct feature< ktl::api::feature::variable_pointers >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::variable_pointers;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_variable_pointers_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_variable_pointers_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_variable_pointers_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_variable_pointers_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_variable_pointers_features, variable_pointers);
};
template <>
struct feature< ktl::api::feature::sci_sync_fence_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sci_sync_fence_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_sci_sync_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_external_sci_sync_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, sci_sync_fence_nv);
};
template <>
struct feature< ktl::api::feature::sci_sync_semaphore_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sci_sync_semaphore_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_sci_sync_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_external_sci_sync_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, sci_sync_semaphore_nv);
};
template <>
struct feature< ktl::api::feature::sci_sync_import_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sci_sync_import_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_sci_sync_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_external_sci_sync_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, sci_sync_import_nv);
};
template <>
struct feature< ktl::api::feature::sci_sync_export_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sci_sync_export_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_sci_sync_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_external_sci_sync_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_sci_sync_features_nv, sci_sync_export_nv);
};
template <>
struct feature< ktl::api::feature::sci_sync_fence_2nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sci_sync_fence_2nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_sci_sync_2features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_external_sci_sync_2features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, sci_sync_fence_2nv);
};
template <>
struct feature< ktl::api::feature::sci_sync_semaphore_2nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sci_sync_semaphore_2nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_sci_sync_2features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_external_sci_sync_2features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, sci_sync_semaphore_2nv);
};
template <>
struct feature< ktl::api::feature::sci_sync_import_2nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sci_sync_import_2nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_sci_sync_2features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_external_sci_sync_2features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, sci_sync_import_2nv);
};
template <>
struct feature< ktl::api::feature::sci_sync_export_2nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sci_sync_export_2nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_sci_sync_2features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_external_sci_sync_2features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_sci_sync_2features_nv, sci_sync_export_2nv);
};
template <>
struct feature< ktl::api::feature::multiview >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multiview;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_multiview_features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_multiview_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_multiview_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_multiview_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_multiview_features, multiview);
};
template <>
struct feature< ktl::api::feature::multiview_geometry_shader >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multiview_geometry_shader;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_multiview_features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_multiview_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_multiview_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_multiview_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_multiview_features, multiview_geometry_shader);
};
template <>
struct feature< ktl::api::feature::multiview_tessellation_shader >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multiview_tessellation_shader;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_multiview_features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_multiview_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_multiview_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_multiview_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_multiview_features, multiview_tessellation_shader);
};
template <>
struct feature< ktl::api::feature::present_id_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::present_id_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_present_id_features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_present_id_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_present_id_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_present_id_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_present_id_features_khr, present_id_khr);
};
template <>
struct feature< ktl::api::feature::present_id_2khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::present_id_2khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_present_id_2features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_present_id_2features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_present_id_2features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_present_id_2features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_present_id_2features_khr, present_id_2khr);
};
template <>
struct feature< ktl::api::feature::present_wait_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::present_wait_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_present_wait_features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_present_wait_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_present_wait_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_present_wait_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_present_wait_features_khr, present_wait_khr);
};
template <>
struct feature< ktl::api::feature::present_wait_2khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::present_wait_2khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_present_wait_2features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_present_wait_2features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_present_wait_2features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_present_wait_2features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_present_wait_2features_khr, present_wait_2khr);
};
template <>
struct feature< ktl::api::feature::present_timing_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::present_timing_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_present_timing_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_present_timing_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_present_timing_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_present_timing_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_present_timing_features_ext, present_timing_ext);
};
template <>
struct feature< ktl::api::feature::present_at_absolute_time_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::present_at_absolute_time_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_present_timing_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_present_timing_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_present_timing_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_present_timing_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_present_timing_features_ext, present_at_absolute_time_ext);
};
template <>
struct feature< ktl::api::feature::present_at_relative_time_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::present_at_relative_time_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_present_timing_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_present_timing_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_present_timing_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_present_timing_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_present_timing_features_ext, present_at_relative_time_ext);
};
template <>
struct feature< ktl::api::feature::storage_buffer_16bit_access >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::storage_buffer_16bit_access;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_16bit_storage_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_16bit_storage_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_16bit_storage_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_16bit_storage_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_16bit_storage_features, storage_buffer_16bit_access);
};
template <>
struct feature< ktl::api::feature::uniform_and_storage_buffer_16bit_access >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::uniform_and_storage_buffer_16bit_access;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_16bit_storage_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_16bit_storage_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_16bit_storage_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_16bit_storage_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_16bit_storage_features, uniform_and_storage_buffer_16bit_access);
};
template <>
struct feature< ktl::api::feature::storage_push_constant_16 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::storage_push_constant_16;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_16bit_storage_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_16bit_storage_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_16bit_storage_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_16bit_storage_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_16bit_storage_features, storage_push_constant_16);
};
template <>
struct feature< ktl::api::feature::storage_input_output_16 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::storage_input_output_16;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_16bit_storage_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_16bit_storage_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_16bit_storage_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_16bit_storage_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_16bit_storage_features, storage_input_output_16);
};
template <>
struct feature< ktl::api::feature::shader_subgroup_extended_types >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_subgroup_extended_types;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_subgroup_extended_types_features;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_subgroup_extended_types_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_subgroup_extended_types_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_subgroup_extended_types_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_subgroup_extended_types_features, shader_subgroup_extended_types);
};
template <>
struct feature< ktl::api::feature::sampler_ycbcr_conversion >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sampler_ycbcr_conversion;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_sampler_ycbcr_conversion_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_sampler_ycbcr_conversion_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_sampler_ycbcr_conversion_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_sampler_ycbcr_conversion_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_sampler_ycbcr_conversion_features, sampler_ycbcr_conversion);
};
template <>
struct feature< ktl::api::feature::protected_memory >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::protected_memory;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_protected_memory_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_protected_memory_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_protected_memory_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_protected_memory_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_protected_memory_features, protected_memory);
};
template <>
struct feature< ktl::api::feature::advanced_blend_coherent_operations_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::advanced_blend_coherent_operations_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_blend_operation_advanced_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_blend_operation_advanced_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_blend_operation_advanced_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_blend_operation_advanced_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_blend_operation_advanced_features_ext, advanced_blend_coherent_operations_ext);
};
template <>
struct feature< ktl::api::feature::multi_draw_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multi_draw_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_multi_draw_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_multi_draw_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_multi_draw_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_multi_draw_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_multi_draw_features_ext, multi_draw_ext);
};
template <>
struct feature< ktl::api::feature::inline_uniform_block >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::inline_uniform_block;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_inline_uniform_block_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_inline_uniform_block_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_inline_uniform_block_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_inline_uniform_block_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_inline_uniform_block_features, inline_uniform_block);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_inline_uniform_block_update_after_bind >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::descriptor_binding_inline_uniform_block_update_after_bind;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_inline_uniform_block_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_inline_uniform_block_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_inline_uniform_block_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_inline_uniform_block_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_inline_uniform_block_features,
                                                          descriptor_binding_inline_uniform_block_update_after_bind);
};
template <>
struct feature< ktl::api::feature::maintenance_4 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::maintenance_4;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_maintenance_4features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_maintenance_4features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_maintenance_4features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_maintenance_4features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_maintenance_4features, maintenance_4);
};
template <>
struct feature< ktl::api::feature::maintenance_5 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::maintenance_5;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_maintenance_5features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_maintenance_5features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_maintenance_5features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_maintenance_5features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_maintenance_5features, maintenance_5);
};
template <>
struct feature< ktl::api::feature::maintenance_6 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::maintenance_6;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_maintenance_6features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_maintenance_6features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_maintenance_6features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_maintenance_6features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_maintenance_6features, maintenance_6);
};
template <>
struct feature< ktl::api::feature::maintenance_7khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::maintenance_7khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_maintenance_7features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_maintenance_7features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_maintenance_7features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_maintenance_7features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_maintenance_7features_khr, maintenance_7khr);
};
template <>
struct feature< ktl::api::feature::maintenance_8khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::maintenance_8khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_maintenance_8features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_maintenance_8features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_maintenance_8features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_maintenance_8features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_maintenance_8features_khr, maintenance_8khr);
};
template <>
struct feature< ktl::api::feature::maintenance_9khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::maintenance_9khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_maintenance_9features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_maintenance_9features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_maintenance_9features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_maintenance_9features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_maintenance_9features_khr, maintenance_9khr);
};
template <>
struct feature< ktl::api::feature::maintenance_11khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::maintenance_11khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_maintenance_11features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_maintenance_11features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_maintenance_11features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_maintenance_11features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_maintenance_11features_khr, maintenance_11khr);
};
template <>
struct feature< ktl::api::feature::maintenance_10khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::maintenance_10khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_maintenance_10features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_maintenance_10features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_maintenance_10features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_maintenance_10features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_maintenance_10features_khr, maintenance_10khr);
};
template <>
struct feature< ktl::api::feature::shader_draw_parameters >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_draw_parameters;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_draw_parameters_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_draw_parameters_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_draw_parameters_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_draw_parameters_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_draw_parameters_features, shader_draw_parameters);
};
template <>
struct feature< ktl::api::feature::shader_float_16 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_float_16;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_float_16int_8features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_float_16int_8features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_float_16int_8features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_float_16int_8features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_float_16int_8features, shader_float_16);
};
template <>
struct feature< ktl::api::feature::shader_int_8 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_int_8;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_float_16int_8features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_float_16int_8features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_float_16int_8features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_float_16int_8features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_float_16int_8features, shader_int_8);
};
template <>
struct feature< ktl::api::feature::host_query_reset >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::host_query_reset;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_host_query_reset_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_host_query_reset_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_host_query_reset_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_host_query_reset_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_host_query_reset_features, host_query_reset);
};
template <>
struct feature< ktl::api::feature::elapsed_timer_query_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::elapsed_timer_query_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_elapsed_timer_query_features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_elapsed_timer_query_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_elapsed_timer_query_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_elapsed_timer_query_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_elapsed_timer_query_features_qcom, elapsed_timer_query_qcom);
};
template <>
struct feature< ktl::api::feature::global_priority_query >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::global_priority_query;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_global_priority_query_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_global_priority_query_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_global_priority_query_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_global_priority_query_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_global_priority_query_features, global_priority_query);
};
template <>
struct feature< ktl::api::feature::device_memory_report_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_memory_report_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_device_memory_report_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_device_memory_report_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_device_memory_report_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_device_memory_report_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_device_memory_report_features_ext, device_memory_report_ext);
};
template <>
struct feature< ktl::api::feature::shader_input_attachment_array_dynamic_indexing >
{
    static constexpr ktl::api::feature        value = ktl::api::feature::shader_input_attachment_array_dynamic_indexing;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          shader_input_attachment_array_dynamic_indexing);
};
template <>
struct feature< ktl::api::feature::shader_uniform_texel_buffer_array_dynamic_indexing >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_uniform_texel_buffer_array_dynamic_indexing;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          shader_uniform_texel_buffer_array_dynamic_indexing);
};
template <>
struct feature< ktl::api::feature::shader_storage_texel_buffer_array_dynamic_indexing >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_storage_texel_buffer_array_dynamic_indexing;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          shader_storage_texel_buffer_array_dynamic_indexing);
};
template <>
struct feature< ktl::api::feature::shader_uniform_buffer_array_non_uniform_indexing >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_uniform_buffer_array_non_uniform_indexing;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          shader_uniform_buffer_array_non_uniform_indexing);
};
template <>
struct feature< ktl::api::feature::shader_sampled_image_array_non_uniform_indexing >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_sampled_image_array_non_uniform_indexing;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          shader_sampled_image_array_non_uniform_indexing);
};
template <>
struct feature< ktl::api::feature::shader_storage_buffer_array_non_uniform_indexing >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_storage_buffer_array_non_uniform_indexing;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          shader_storage_buffer_array_non_uniform_indexing);
};
template <>
struct feature< ktl::api::feature::shader_storage_image_array_non_uniform_indexing >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_storage_image_array_non_uniform_indexing;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          shader_storage_image_array_non_uniform_indexing);
};
template <>
struct feature< ktl::api::feature::shader_input_attachment_array_non_uniform_indexing >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_input_attachment_array_non_uniform_indexing;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          shader_input_attachment_array_non_uniform_indexing);
};
template <>
struct feature< ktl::api::feature::shader_uniform_texel_buffer_array_non_uniform_indexing >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::shader_uniform_texel_buffer_array_non_uniform_indexing;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          shader_uniform_texel_buffer_array_non_uniform_indexing);
};
template <>
struct feature< ktl::api::feature::shader_storage_texel_buffer_array_non_uniform_indexing >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::shader_storage_texel_buffer_array_non_uniform_indexing;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          shader_storage_texel_buffer_array_non_uniform_indexing);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_uniform_buffer_update_after_bind >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::descriptor_binding_uniform_buffer_update_after_bind;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          descriptor_binding_uniform_buffer_update_after_bind);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_sampled_image_update_after_bind >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::descriptor_binding_sampled_image_update_after_bind;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          descriptor_binding_sampled_image_update_after_bind);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_storage_image_update_after_bind >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::descriptor_binding_storage_image_update_after_bind;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          descriptor_binding_storage_image_update_after_bind);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_storage_buffer_update_after_bind >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::descriptor_binding_storage_buffer_update_after_bind;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          descriptor_binding_storage_buffer_update_after_bind);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_uniform_texel_buffer_update_after_bind >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::descriptor_binding_uniform_texel_buffer_update_after_bind;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          descriptor_binding_uniform_texel_buffer_update_after_bind);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_storage_texel_buffer_update_after_bind >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::descriptor_binding_storage_texel_buffer_update_after_bind;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          descriptor_binding_storage_texel_buffer_update_after_bind);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_update_unused_while_pending >
{
    static constexpr ktl::api::feature        value = ktl::api::feature::descriptor_binding_update_unused_while_pending;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_descriptor_indexing_features,
                                                          descriptor_binding_update_unused_while_pending);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_partially_bound >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_binding_partially_bound;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, descriptor_binding_partially_bound);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_variable_descriptor_count >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_binding_variable_descriptor_count;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, descriptor_binding_variable_descriptor_count);
};
template <>
struct feature< ktl::api::feature::runtime_descriptor_array >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::runtime_descriptor_array;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_indexing_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_indexing_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_descriptor_indexing_features, runtime_descriptor_array);
};
template <>
struct feature< ktl::api::feature::timeline_semaphore >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::timeline_semaphore;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_timeline_semaphore_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_timeline_semaphore_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_timeline_semaphore_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_timeline_semaphore_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_timeline_semaphore_features, timeline_semaphore);
};
template <>
struct feature< ktl::api::feature::storage_buffer_8bit_access >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::storage_buffer_8bit_access;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_8bit_storage_features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_8bit_storage_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_8bit_storage_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_8bit_storage_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_8bit_storage_features, storage_buffer_8bit_access);
};
template <>
struct feature< ktl::api::feature::uniform_and_storage_buffer_8bit_access >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::uniform_and_storage_buffer_8bit_access;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_8bit_storage_features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_8bit_storage_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_8bit_storage_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_8bit_storage_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_8bit_storage_features, uniform_and_storage_buffer_8bit_access);
};
template <>
struct feature< ktl::api::feature::storage_push_constant_8 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::storage_push_constant_8;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_8bit_storage_features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_8bit_storage_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_8bit_storage_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_8bit_storage_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_8bit_storage_features, storage_push_constant_8);
};
template <>
struct feature< ktl::api::feature::conditional_rendering_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::conditional_rendering_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_conditional_rendering_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_conditional_rendering_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_conditional_rendering_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_conditional_rendering_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_conditional_rendering_features_ext, conditional_rendering_ext);
};
template <>
struct feature< ktl::api::feature::inherited_conditional_rendering_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::inherited_conditional_rendering_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_conditional_rendering_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_conditional_rendering_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_conditional_rendering_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_conditional_rendering_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_conditional_rendering_features_ext, inherited_conditional_rendering_ext);
};
template <>
struct feature< ktl::api::feature::vulkan_memory_model >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::vulkan_memory_model;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_vulkan_memory_model_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_vulkan_memory_model_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_vulkan_memory_model_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_vulkan_memory_model_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_memory_model_features, vulkan_memory_model);
};
template <>
struct feature< ktl::api::feature::vulkan_memory_model_device_scope >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::vulkan_memory_model_device_scope;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_vulkan_memory_model_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_vulkan_memory_model_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_vulkan_memory_model_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_vulkan_memory_model_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_memory_model_features, vulkan_memory_model_device_scope);
};
template <>
struct feature< ktl::api::feature::vulkan_memory_model_availability_visibility_chains >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::vulkan_memory_model_availability_visibility_chains;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_vulkan_memory_model_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_vulkan_memory_model_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_vulkan_memory_model_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_vulkan_memory_model_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_memory_model_features,
                                                          vulkan_memory_model_availability_visibility_chains);
};
template <>
struct feature< ktl::api::feature::shader_buffer_int_64atomics >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_buffer_int_64atomics;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_int_64features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_int_64features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_int_64features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_int_64features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_int_64features, shader_buffer_int_64atomics);
};
template <>
struct feature< ktl::api::feature::shader_shared_int_64atomics >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_shared_int_64atomics;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_int_64features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_int_64features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_int_64features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_int_64features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_int_64features, shader_shared_int_64atomics);
};
template <>
struct feature< ktl::api::feature::shader_buffer_float_32atomics_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_buffer_float_32atomics_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, shader_buffer_float_32atomics_ext);
};
template <>
struct feature< ktl::api::feature::shader_buffer_float_32atomic_add_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_buffer_float_32atomic_add_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, shader_buffer_float_32atomic_add_ext);
};
template <>
struct feature< ktl::api::feature::shader_buffer_float_64atomics_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_buffer_float_64atomics_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, shader_buffer_float_64atomics_ext);
};
template <>
struct feature< ktl::api::feature::shader_buffer_float_64atomic_add_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_buffer_float_64atomic_add_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, shader_buffer_float_64atomic_add_ext);
};
template <>
struct feature< ktl::api::feature::shader_shared_float_32atomics_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_shared_float_32atomics_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, shader_shared_float_32atomics_ext);
};
template <>
struct feature< ktl::api::feature::shader_shared_float_32atomic_add_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_shared_float_32atomic_add_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, shader_shared_float_32atomic_add_ext);
};
template <>
struct feature< ktl::api::feature::shader_shared_float_64atomics_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_shared_float_64atomics_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, shader_shared_float_64atomics_ext);
};
template <>
struct feature< ktl::api::feature::shader_shared_float_64atomic_add_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_shared_float_64atomic_add_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, shader_shared_float_64atomic_add_ext);
};
template <>
struct feature< ktl::api::feature::shader_image_float_32atomics_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_image_float_32atomics_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, shader_image_float_32atomics_ext);
};
template <>
struct feature< ktl::api::feature::shader_image_float_32atomic_add_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_image_float_32atomic_add_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, shader_image_float_32atomic_add_ext);
};
template <>
struct feature< ktl::api::feature::sparse_image_float_32atomics_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sparse_image_float_32atomics_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, sparse_image_float_32atomics_ext);
};
template <>
struct feature< ktl::api::feature::sparse_image_float_32atomic_add_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sparse_image_float_32atomic_add_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_features_ext, sparse_image_float_32atomic_add_ext);
};
template <>
struct feature< ktl::api::feature::shader_buffer_float_16atomics_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_buffer_float_16atomics_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, shader_buffer_float_16atomics_2ext);
};
template <>
struct feature< ktl::api::feature::shader_buffer_float_16atomic_add_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_buffer_float_16atomic_add_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, shader_buffer_float_16atomic_add_2ext);
};
template <>
struct feature< ktl::api::feature::shader_buffer_float_16atomic_min_max_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_buffer_float_16atomic_min_max_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext,
                                                          shader_buffer_float_16atomic_min_max_2ext);
};
template <>
struct feature< ktl::api::feature::shader_buffer_float_32atomic_min_max_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_buffer_float_32atomic_min_max_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext,
                                                          shader_buffer_float_32atomic_min_max_2ext);
};
template <>
struct feature< ktl::api::feature::shader_buffer_float_64atomic_min_max_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_buffer_float_64atomic_min_max_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext,
                                                          shader_buffer_float_64atomic_min_max_2ext);
};
template <>
struct feature< ktl::api::feature::shader_shared_float_16atomics_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_shared_float_16atomics_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, shader_shared_float_16atomics_2ext);
};
template <>
struct feature< ktl::api::feature::shader_shared_float_16atomic_add_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_shared_float_16atomic_add_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, shader_shared_float_16atomic_add_2ext);
};
template <>
struct feature< ktl::api::feature::shader_shared_float_16atomic_min_max_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_shared_float_16atomic_min_max_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext,
                                                          shader_shared_float_16atomic_min_max_2ext);
};
template <>
struct feature< ktl::api::feature::shader_shared_float_32atomic_min_max_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_shared_float_32atomic_min_max_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext,
                                                          shader_shared_float_32atomic_min_max_2ext);
};
template <>
struct feature< ktl::api::feature::shader_shared_float_64atomic_min_max_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_shared_float_64atomic_min_max_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext,
                                                          shader_shared_float_64atomic_min_max_2ext);
};
template <>
struct feature< ktl::api::feature::shader_image_float_32atomic_min_max_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_image_float_32atomic_min_max_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, shader_image_float_32atomic_min_max_2ext);
};
template <>
struct feature< ktl::api::feature::sparse_image_float_32atomic_min_max_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sparse_image_float_32atomic_min_max_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_atomic_float_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_2features_ext, sparse_image_float_32atomic_min_max_2ext);
};
template <>
struct feature< ktl::api::feature::vertex_attribute_instance_rate_divisor >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::vertex_attribute_instance_rate_divisor;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_vertex_attribute_divisor_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_vertex_attribute_divisor_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_vertex_attribute_divisor_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_vertex_attribute_divisor_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vertex_attribute_divisor_features, vertex_attribute_instance_rate_divisor);
};
template <>
struct feature< ktl::api::feature::vertex_attribute_instance_rate_zero_divisor >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::vertex_attribute_instance_rate_zero_divisor;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_vertex_attribute_divisor_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_vertex_attribute_divisor_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_vertex_attribute_divisor_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_vertex_attribute_divisor_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vertex_attribute_divisor_features,
                                                          vertex_attribute_instance_rate_zero_divisor);
};
template <>
struct feature< ktl::api::feature::decode_mode_shared_exponent_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::decode_mode_shared_exponent_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_astc_decode_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_astc_decode_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_astc_decode_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_astc_decode_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_astc_decode_features_ext, decode_mode_shared_exponent_ext);
};
template <>
struct feature< ktl::api::feature::transform_feedback_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::transform_feedback_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_transform_feedback_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_transform_feedback_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_transform_feedback_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_transform_feedback_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_transform_feedback_features_ext, transform_feedback_ext);
};
template <>
struct feature< ktl::api::feature::geometry_streams_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::geometry_streams_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_transform_feedback_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_transform_feedback_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_transform_feedback_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_transform_feedback_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_transform_feedback_features_ext, geometry_streams_ext);
};
template <>
struct feature< ktl::api::feature::representative_fragment_test_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::representative_fragment_test_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_representative_fragment_test_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_representative_fragment_test_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_representative_fragment_test_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_representative_fragment_test_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_representative_fragment_test_features_nv, representative_fragment_test_nv);
};
template <>
struct feature< ktl::api::feature::exclusive_scissor_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::exclusive_scissor_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_exclusive_scissor_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_exclusive_scissor_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_exclusive_scissor_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_exclusive_scissor_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_exclusive_scissor_features_nv, exclusive_scissor_nv);
};
template <>
struct feature< ktl::api::feature::corner_sampled_image_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::corner_sampled_image_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_corner_sampled_image_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_corner_sampled_image_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_corner_sampled_image_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_corner_sampled_image_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_corner_sampled_image_features_nv, corner_sampled_image_nv);
};
template <>
struct feature< ktl::api::feature::compute_derivative_group_quads_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::compute_derivative_group_quads_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_compute_shader_derivatives_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_compute_shader_derivatives_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_compute_shader_derivatives_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_compute_shader_derivatives_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_compute_shader_derivatives_features_khr, compute_derivative_group_quads_khr);
};
template <>
struct feature< ktl::api::feature::compute_derivative_group_linear_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::compute_derivative_group_linear_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_compute_shader_derivatives_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_compute_shader_derivatives_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_compute_shader_derivatives_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_compute_shader_derivatives_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_compute_shader_derivatives_features_khr, compute_derivative_group_linear_khr);
};
template <>
struct feature< ktl::api::feature::image_footprint_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::image_footprint_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_image_footprint_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_image_footprint_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_image_footprint_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_image_footprint_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_image_footprint_features_nv, image_footprint_nv);
};
template <>
struct feature< ktl::api::feature::dedicated_allocation_image_aliasing_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::dedicated_allocation_image_aliasing_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_dedicated_allocation_image_aliasing_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_dedicated_allocation_image_aliasing_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_dedicated_allocation_image_aliasing_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_dedicated_allocation_image_aliasing_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_dedicated_allocation_image_aliasing_features_nv,
                 dedicated_allocation_image_aliasing_nv);
};
template <>
struct feature< ktl::api::feature::indirect_memory_copy_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::indirect_memory_copy_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_copy_memory_indirect_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_copy_memory_indirect_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_copy_memory_indirect_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_copy_memory_indirect_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_copy_memory_indirect_features_khr, indirect_memory_copy_khr);
};
template <>
struct feature< ktl::api::feature::indirect_memory_to_image_copy_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::indirect_memory_to_image_copy_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_copy_memory_indirect_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_copy_memory_indirect_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_copy_memory_indirect_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_copy_memory_indirect_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_copy_memory_indirect_features_khr, indirect_memory_to_image_copy_khr);
};
template <>
struct feature< ktl::api::feature::indirect_copy_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::indirect_copy_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_copy_memory_indirect_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_copy_memory_indirect_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_copy_memory_indirect_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_copy_memory_indirect_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_copy_memory_indirect_features_nv, indirect_copy_nv);
};
template <>
struct feature< ktl::api::feature::memory_decompression_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::memory_decompression_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_memory_decompression_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_memory_decompression_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_memory_decompression_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_memory_decompression_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_memory_decompression_features_ext, memory_decompression_ext);
};
template <>
struct feature< ktl::api::feature::shading_rate_image_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shading_rate_image_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shading_rate_image_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shading_rate_image_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shading_rate_image_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shading_rate_image_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shading_rate_image_features_nv, shading_rate_image_nv);
};
template <>
struct feature< ktl::api::feature::shading_rate_coarse_sample_order_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shading_rate_coarse_sample_order_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shading_rate_image_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shading_rate_image_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shading_rate_image_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shading_rate_image_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shading_rate_image_features_nv, shading_rate_coarse_sample_order_nv);
};
template <>
struct feature< ktl::api::feature::invocation_mask_huawei >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::invocation_mask_huawei;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_invocation_mask_features_huawei;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_invocation_mask_features_huawei);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_invocation_mask_features_huawei, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_invocation_mask_features_huawei, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_invocation_mask_features_huawei, invocation_mask_huawei);
};
template <>
struct feature< ktl::api::feature::task_shader_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::task_shader_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_mesh_shader_features_nv;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_mesh_shader_features_nv);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_mesh_shader_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_mesh_shader_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_mesh_shader_features_nv, task_shader_nv);
};
template <>
struct feature< ktl::api::feature::mesh_shader_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::mesh_shader_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_mesh_shader_features_nv;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_mesh_shader_features_nv);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_mesh_shader_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_mesh_shader_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_mesh_shader_features_nv, mesh_shader_nv);
};
template <>
struct feature< ktl::api::feature::task_shader_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::task_shader_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_mesh_shader_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_mesh_shader_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_mesh_shader_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_mesh_shader_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_mesh_shader_features_ext, task_shader_ext);
};
template <>
struct feature< ktl::api::feature::mesh_shader_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::mesh_shader_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_mesh_shader_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_mesh_shader_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_mesh_shader_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_mesh_shader_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_mesh_shader_features_ext, mesh_shader_ext);
};
template <>
struct feature< ktl::api::feature::multiview_mesh_shader_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multiview_mesh_shader_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_mesh_shader_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_mesh_shader_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_mesh_shader_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_mesh_shader_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_mesh_shader_features_ext, multiview_mesh_shader_ext);
};
template <>
struct feature< ktl::api::feature::primitive_fragment_shading_rate_mesh_shader_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::primitive_fragment_shading_rate_mesh_shader_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_mesh_shader_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_mesh_shader_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_mesh_shader_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_mesh_shader_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_mesh_shader_features_ext, primitive_fragment_shading_rate_mesh_shader_ext);
};
template <>
struct feature< ktl::api::feature::mesh_shader_queries_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::mesh_shader_queries_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_mesh_shader_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_mesh_shader_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_mesh_shader_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_mesh_shader_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_mesh_shader_features_ext, mesh_shader_queries_ext);
};
template <>
struct feature< ktl::api::feature::acceleration_structure_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::acceleration_structure_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_acceleration_structure_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_acceleration_structure_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr, acceleration_structure_khr);
};
template <>
struct feature< ktl::api::feature::acceleration_structure_capture_replay_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::acceleration_structure_capture_replay_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_acceleration_structure_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_acceleration_structure_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_acceleration_structure_features_khr,
                                                          acceleration_structure_capture_replay_khr);
};
template <>
struct feature< ktl::api::feature::acceleration_structure_indirect_build_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::acceleration_structure_indirect_build_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_acceleration_structure_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_acceleration_structure_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_acceleration_structure_features_khr,
                                                          acceleration_structure_indirect_build_khr);
};
template <>
struct feature< ktl::api::feature::acceleration_structure_host_commands_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::acceleration_structure_host_commands_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_acceleration_structure_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_acceleration_structure_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_acceleration_structure_features_khr,
                                                          acceleration_structure_host_commands_khr);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_acceleration_structure_update_after_bind_khr >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::descriptor_binding_acceleration_structure_update_after_bind_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_acceleration_structure_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_acceleration_structure_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_acceleration_structure_features_khr,
                 descriptor_binding_acceleration_structure_update_after_bind_khr);
};
template <>
struct feature< ktl::api::feature::ray_tracing_pipeline_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ray_tracing_pipeline_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_pipeline_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ray_tracing_pipeline_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, ray_tracing_pipeline_khr);
};
template <>
struct feature< ktl::api::feature::ray_tracing_pipeline_shader_group_handle_capture_replay_khr >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::ray_tracing_pipeline_shader_group_handle_capture_replay_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_pipeline_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ray_tracing_pipeline_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr,
                                                          ray_tracing_pipeline_shader_group_handle_capture_replay_khr);
};
template <>
struct feature< ktl::api::feature::ray_tracing_pipeline_shader_group_handle_capture_replay_mixed_khr >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::ray_tracing_pipeline_shader_group_handle_capture_replay_mixed_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_pipeline_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ray_tracing_pipeline_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr,
                 ray_tracing_pipeline_shader_group_handle_capture_replay_mixed_khr);
};
template <>
struct feature< ktl::api::feature::ray_tracing_pipeline_trace_rays_indirect_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ray_tracing_pipeline_trace_rays_indirect_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_pipeline_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ray_tracing_pipeline_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr,
                                                          ray_tracing_pipeline_trace_rays_indirect_khr);
};
template <>
struct feature< ktl::api::feature::ray_traversal_primitive_culling_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ray_traversal_primitive_culling_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_pipeline_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ray_tracing_pipeline_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ray_tracing_pipeline_features_khr, ray_traversal_primitive_culling_khr);
};
template <>
struct feature< ktl::api::feature::ray_query_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ray_query_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_query_features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_ray_query_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_ray_query_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_ray_query_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ray_query_features_khr, ray_query_khr);
};
template <>
struct feature< ktl::api::feature::ray_tracing_maintenance_1khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ray_tracing_maintenance_1khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_maintenance_1features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ray_tracing_maintenance_1features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_maintenance_1features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_maintenance_1features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ray_tracing_maintenance_1features_khr, ray_tracing_maintenance_1khr);
};
template <>
struct feature< ktl::api::feature::ray_tracing_pipeline_trace_rays_indirect_21khr >
{
    static constexpr ktl::api::feature        value = ktl::api::feature::ray_tracing_pipeline_trace_rays_indirect_21khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_maintenance_1features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ray_tracing_maintenance_1features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_maintenance_1features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_maintenance_1features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ray_tracing_maintenance_1features_khr,
                 ray_tracing_pipeline_trace_rays_indirect_21khr);
};
template <>
struct feature< ktl::api::feature::fragment_density_map_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::fragment_density_map_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_density_map_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_fragment_density_map_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_density_map_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_density_map_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fragment_density_map_features_ext, fragment_density_map_ext);
};
template <>
struct feature< ktl::api::feature::fragment_density_map_dynamic_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::fragment_density_map_dynamic_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_density_map_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_fragment_density_map_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_density_map_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_density_map_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fragment_density_map_features_ext, fragment_density_map_dynamic_ext);
};
template <>
struct feature< ktl::api::feature::fragment_density_map_non_subsampled_images_ext >
{
    static constexpr ktl::api::feature        value = ktl::api::feature::fragment_density_map_non_subsampled_images_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_density_map_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_fragment_density_map_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_density_map_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_density_map_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_fragment_density_map_features_ext,
                                                          fragment_density_map_non_subsampled_images_ext);
};
template <>
struct feature< ktl::api::feature::fragment_density_map_deferred_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::fragment_density_map_deferred_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_density_map_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_fragment_density_map_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_density_map_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_density_map_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fragment_density_map_2features_ext, fragment_density_map_deferred_2ext);
};
template <>
struct feature< ktl::api::feature::fragment_density_map_offset_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::fragment_density_map_offset_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_density_map_offset_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_fragment_density_map_offset_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_density_map_offset_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_density_map_offset_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fragment_density_map_offset_features_ext, fragment_density_map_offset_ext);
};
template <>
struct feature< ktl::api::feature::scalar_block_layout >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::scalar_block_layout;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_scalar_block_layout_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_scalar_block_layout_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_scalar_block_layout_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_scalar_block_layout_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_scalar_block_layout_features, scalar_block_layout);
};
template <>
struct feature< ktl::api::feature::uniform_buffer_standard_layout >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::uniform_buffer_standard_layout;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_uniform_buffer_standard_layout_features;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_uniform_buffer_standard_layout_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_uniform_buffer_standard_layout_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_uniform_buffer_standard_layout_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_uniform_buffer_standard_layout_features, uniform_buffer_standard_layout);
};
template <>
struct feature< ktl::api::feature::depth_clip_enable_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::depth_clip_enable_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_depth_clip_enable_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_depth_clip_enable_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_depth_clip_enable_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_depth_clip_enable_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_depth_clip_enable_features_ext, depth_clip_enable_ext);
};
template <>
struct feature< ktl::api::feature::memory_priority_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::memory_priority_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_memory_priority_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_memory_priority_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_memory_priority_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_memory_priority_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_memory_priority_features_ext, memory_priority_ext);
};
template <>
struct feature< ktl::api::feature::pageable_device_local_memory_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pageable_device_local_memory_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_pageable_device_local_memory_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_pageable_device_local_memory_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_pageable_device_local_memory_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_pageable_device_local_memory_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_pageable_device_local_memory_features_ext, pageable_device_local_memory_ext);
};
template <>
struct feature< ktl::api::feature::buffer_device_address >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::buffer_device_address;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_buffer_device_address_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_buffer_device_address_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_buffer_device_address_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_buffer_device_address_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_buffer_device_address_features, buffer_device_address);
};
template <>
struct feature< ktl::api::feature::buffer_device_address_capture_replay >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::buffer_device_address_capture_replay;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_buffer_device_address_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_buffer_device_address_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_buffer_device_address_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_buffer_device_address_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_buffer_device_address_features, buffer_device_address_capture_replay);
};
template <>
struct feature< ktl::api::feature::buffer_device_address_multi_device >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::buffer_device_address_multi_device;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_buffer_device_address_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_buffer_device_address_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_buffer_device_address_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_buffer_device_address_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_buffer_device_address_features, buffer_device_address_multi_device);
};
template <>
struct feature< ktl::api::feature::buffer_device_address_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::buffer_device_address_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_buffer_device_address_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_buffer_device_address_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_buffer_device_address_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_buffer_device_address_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_buffer_device_address_features_ext, buffer_device_address_ext);
};
template <>
struct feature< ktl::api::feature::buffer_device_address_capture_replay_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::buffer_device_address_capture_replay_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_buffer_device_address_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_buffer_device_address_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_buffer_device_address_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_buffer_device_address_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_buffer_device_address_features_ext,
                                                          buffer_device_address_capture_replay_ext);
};
template <>
struct feature< ktl::api::feature::buffer_device_address_multi_device_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::buffer_device_address_multi_device_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_buffer_device_address_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_buffer_device_address_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_buffer_device_address_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_buffer_device_address_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_buffer_device_address_features_ext, buffer_device_address_multi_device_ext);
};
template <>
struct feature< ktl::api::feature::imageless_framebuffer >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::imageless_framebuffer;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_imageless_framebuffer_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_imageless_framebuffer_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_imageless_framebuffer_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_imageless_framebuffer_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_imageless_framebuffer_features, imageless_framebuffer);
};
template <>
struct feature< ktl::api::feature::texture_compression_astc_hdr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::texture_compression_astc_hdr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_texture_compression_astc_hdr_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_texture_compression_astchdr_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_texture_compression_astchdr_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_texture_compression_astchdr_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_texture_compression_astchdr_features, texture_compression_astc_hdr);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_matrix_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cooperative_matrix_features_nv, cooperative_matrix_nv);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_robust_buffer_access_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_robust_buffer_access_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_matrix_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cooperative_matrix_features_nv, cooperative_matrix_robust_buffer_access_nv);
};
template <>
struct feature< ktl::api::feature::ycbcr_image_arrays_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ycbcr_image_arrays_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ycbcr_image_arrays_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ycbcr_image_arrays_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ycbcr_image_arrays_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ycbcr_image_arrays_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ycbcr_image_arrays_features_ext, ycbcr_image_arrays_ext);
};
template <>
struct feature< ktl::api::feature::present_barrier_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::present_barrier_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_present_barrier_features_nv;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_present_barrier_features_nv);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_present_barrier_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_present_barrier_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_present_barrier_features_nv, present_barrier_nv);
};
template <>
struct feature< ktl::api::feature::performance_counter_query_pools_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::performance_counter_query_pools_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_performance_query_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_performance_query_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_performance_query_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_performance_query_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_performance_query_features_khr, performance_counter_query_pools_khr);
};
template <>
struct feature< ktl::api::feature::performance_counter_multiple_query_pools_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::performance_counter_multiple_query_pools_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_performance_query_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_performance_query_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_performance_query_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_performance_query_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_performance_query_features_khr,
                                                          performance_counter_multiple_query_pools_khr);
};
template <>
struct feature< ktl::api::feature::coverage_reduction_mode_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::coverage_reduction_mode_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_coverage_reduction_mode_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_coverage_reduction_mode_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_coverage_reduction_mode_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_coverage_reduction_mode_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_coverage_reduction_mode_features_nv, coverage_reduction_mode_nv);
};
template <>
struct feature< ktl::api::feature::shader_integer_functions_2intel >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_integer_functions_2intel;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_integer_functions_2features_intel;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_integer_functions_2features_intel);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_integer_functions_2features_intel, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_integer_functions_2features_intel, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_integer_functions_2features_intel, shader_integer_functions_2intel);
};
template <>
struct feature< ktl::api::feature::shader_subgroup_clock_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_subgroup_clock_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_clock_features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_shader_clock_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_shader_clock_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_shader_clock_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_clock_features_khr, shader_subgroup_clock_khr);
};
template <>
struct feature< ktl::api::feature::shader_device_clock_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_device_clock_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_clock_features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_shader_clock_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_shader_clock_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_shader_clock_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_clock_features_khr, shader_device_clock_khr);
};
template <>
struct feature< ktl::api::feature::index_type_uint_8 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::index_type_uint_8;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_index_type_uint_8features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_index_type_uint_8features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_index_type_uint_8features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_index_type_uint_8features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_index_type_uint_8features, index_type_uint_8);
};
template <>
struct feature< ktl::api::feature::shader_sm_builtins_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_sm_builtins_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_sm_builtins_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_sm_builtins_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_sm_builtins_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_sm_builtins_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_sm_builtins_features_nv, shader_sm_builtins_nv);
};
template <>
struct feature< ktl::api::feature::fragment_shader_sample_interlock_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::fragment_shader_sample_interlock_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_shader_interlock_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_fragment_shader_interlock_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_shader_interlock_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_shader_interlock_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_fragment_shader_interlock_features_ext, fragment_shader_sample_interlock_ext);
};
template <>
struct feature< ktl::api::feature::fragment_shader_pixel_interlock_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::fragment_shader_pixel_interlock_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_shader_interlock_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_fragment_shader_interlock_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_shader_interlock_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_shader_interlock_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fragment_shader_interlock_features_ext, fragment_shader_pixel_interlock_ext);
};
template <>
struct feature< ktl::api::feature::fragment_shader_shading_rate_interlock_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::fragment_shader_shading_rate_interlock_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_shader_interlock_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_fragment_shader_interlock_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_shader_interlock_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_shader_interlock_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_fragment_shader_interlock_features_ext, fragment_shader_shading_rate_interlock_ext);
};
template <>
struct feature< ktl::api::feature::separate_depth_stencil_layouts >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::separate_depth_stencil_layouts;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_separate_depth_stencil_layouts_features;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_separate_depth_stencil_layouts_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_separate_depth_stencil_layouts_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_separate_depth_stencil_layouts_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_separate_depth_stencil_layouts_features, separate_depth_stencil_layouts);
};
template <>
struct feature< ktl::api::feature::primitive_topology_list_restart_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::primitive_topology_list_restart_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_primitive_topology_list_restart_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_primitive_topology_list_restart_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_primitive_topology_list_restart_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_primitive_topology_list_restart_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_primitive_topology_list_restart_features_ext, primitive_topology_list_restart_ext);
};
template <>
struct feature< ktl::api::feature::primitive_topology_patch_list_restart_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::primitive_topology_patch_list_restart_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_primitive_topology_list_restart_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_primitive_topology_list_restart_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_primitive_topology_list_restart_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_primitive_topology_list_restart_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_primitive_topology_list_restart_features_ext,
                 primitive_topology_patch_list_restart_ext);
};
template <>
struct feature< ktl::api::feature::pipeline_executable_info_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_executable_info_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_pipeline_executable_properties_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_pipeline_executable_properties_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_pipeline_executable_properties_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_pipeline_executable_properties_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_pipeline_executable_properties_features_khr, pipeline_executable_info_khr);
};
template <>
struct feature< ktl::api::feature::shader_demote_to_helper_invocation >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_demote_to_helper_invocation;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_demote_to_helper_invocation_features;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_demote_to_helper_invocation_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_demote_to_helper_invocation_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_demote_to_helper_invocation_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_shader_demote_to_helper_invocation_features, shader_demote_to_helper_invocation);
};
template <>
struct feature< ktl::api::feature::texel_buffer_alignment_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::texel_buffer_alignment_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_texel_buffer_alignment_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_texel_buffer_alignment_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_texel_buffer_alignment_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_texel_buffer_alignment_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_texel_buffer_alignment_features_ext, texel_buffer_alignment_ext);
};
template <>
struct feature< ktl::api::feature::subgroup_size_control >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::subgroup_size_control;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_subgroup_size_control_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_subgroup_size_control_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_subgroup_size_control_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_subgroup_size_control_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_subgroup_size_control_features, subgroup_size_control);
};
template <>
struct feature< ktl::api::feature::compute_full_subgroups >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::compute_full_subgroups;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_subgroup_size_control_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_subgroup_size_control_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_subgroup_size_control_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_subgroup_size_control_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_subgroup_size_control_features, compute_full_subgroups);
};
template <>
struct feature< ktl::api::feature::rectangular_lines >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::rectangular_lines;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_line_rasterization_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_line_rasterization_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_line_rasterization_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_line_rasterization_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_line_rasterization_features, rectangular_lines);
};
template <>
struct feature< ktl::api::feature::bresenham_lines >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::bresenham_lines;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_line_rasterization_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_line_rasterization_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_line_rasterization_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_line_rasterization_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_line_rasterization_features, bresenham_lines);
};
template <>
struct feature< ktl::api::feature::smooth_lines >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::smooth_lines;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_line_rasterization_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_line_rasterization_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_line_rasterization_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_line_rasterization_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_line_rasterization_features, smooth_lines);
};
template <>
struct feature< ktl::api::feature::stippled_rectangular_lines >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::stippled_rectangular_lines;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_line_rasterization_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_line_rasterization_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_line_rasterization_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_line_rasterization_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_line_rasterization_features, stippled_rectangular_lines);
};
template <>
struct feature< ktl::api::feature::stippled_bresenham_lines >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::stippled_bresenham_lines;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_line_rasterization_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_line_rasterization_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_line_rasterization_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_line_rasterization_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_line_rasterization_features, stippled_bresenham_lines);
};
template <>
struct feature< ktl::api::feature::stippled_smooth_lines >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::stippled_smooth_lines;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_line_rasterization_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_line_rasterization_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_line_rasterization_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_line_rasterization_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_line_rasterization_features, stippled_smooth_lines);
};
template <>
struct feature< ktl::api::feature::pipeline_creation_cache_control >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_creation_cache_control;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_pipeline_creation_cache_control_features;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_pipeline_creation_cache_control_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_pipeline_creation_cache_control_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_pipeline_creation_cache_control_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_pipeline_creation_cache_control_features, pipeline_creation_cache_control);
};
template <>
struct feature< ktl::api::feature::storage_buffer_16bit_access_11 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::storage_buffer_16bit_access_11;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_11features, storage_buffer_16bit_access_11);
};
template <>
struct feature< ktl::api::feature::uniform_and_storage_buffer_16bit_access_11 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::uniform_and_storage_buffer_16bit_access_11;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_11features, uniform_and_storage_buffer_16bit_access_11);
};
template <>
struct feature< ktl::api::feature::storage_push_constant_1611 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::storage_push_constant_1611;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_11features, storage_push_constant_1611);
};
template <>
struct feature< ktl::api::feature::storage_input_output_1611 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::storage_input_output_1611;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_11features, storage_input_output_1611);
};
template <>
struct feature< ktl::api::feature::multiview_11 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multiview_11;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_11features, multiview_11);
};
template <>
struct feature< ktl::api::feature::multiview_geometry_shader_11 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multiview_geometry_shader_11;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_11features, multiview_geometry_shader_11);
};
template <>
struct feature< ktl::api::feature::multiview_tessellation_shader_11 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multiview_tessellation_shader_11;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_11features, multiview_tessellation_shader_11);
};
template <>
struct feature< ktl::api::feature::variable_pointers_storage_buffer_11 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::variable_pointers_storage_buffer_11;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_11features, variable_pointers_storage_buffer_11);
};
template <>
struct feature< ktl::api::feature::variable_pointers_11 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::variable_pointers_11;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_11features, variable_pointers_11);
};
template <>
struct feature< ktl::api::feature::protected_memory_11 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::protected_memory_11;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_11features, protected_memory_11);
};
template <>
struct feature< ktl::api::feature::sampler_ycbcr_conversion_11 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sampler_ycbcr_conversion_11;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_11features, sampler_ycbcr_conversion_11);
};
template <>
struct feature< ktl::api::feature::shader_draw_parameters_11 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_draw_parameters_11;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_11features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_11features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_11features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_11features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_11features, shader_draw_parameters_11);
};
template <>
struct feature< ktl::api::feature::sampler_mirror_clamp_to_edge_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sampler_mirror_clamp_to_edge_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, sampler_mirror_clamp_to_edge_12);
};
template <>
struct feature< ktl::api::feature::draw_indirect_count_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::draw_indirect_count_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, draw_indirect_count_12);
};
template <>
struct feature< ktl::api::feature::storage_buffer_8bit_access_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::storage_buffer_8bit_access_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, storage_buffer_8bit_access_12);
};
template <>
struct feature< ktl::api::feature::uniform_and_storage_buffer_8bit_access_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::uniform_and_storage_buffer_8bit_access_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, uniform_and_storage_buffer_8bit_access_12);
};
template <>
struct feature< ktl::api::feature::storage_push_constant_812 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::storage_push_constant_812;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, storage_push_constant_812);
};
template <>
struct feature< ktl::api::feature::shader_buffer_int_64atomics_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_buffer_int_64atomics_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_buffer_int_64atomics_12);
};
template <>
struct feature< ktl::api::feature::shader_shared_int_64atomics_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_shared_int_64atomics_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_shared_int_64atomics_12);
};
template <>
struct feature< ktl::api::feature::shader_float_1612 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_float_1612;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_float_1612);
};
template <>
struct feature< ktl::api::feature::shader_int_812 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_int_812;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_12features, shader_int_812);
};
template <>
struct feature< ktl::api::feature::descriptor_indexing_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_indexing_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, descriptor_indexing_12);
};
template <>
struct feature< ktl::api::feature::shader_input_attachment_array_dynamic_indexing_12 >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_input_attachment_array_dynamic_indexing_12;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_input_attachment_array_dynamic_indexing_12);
};
template <>
struct feature< ktl::api::feature::shader_uniform_texel_buffer_array_dynamic_indexing_12 >
{
    static constexpr ktl::api::feature value = ktl::api::feature::shader_uniform_texel_buffer_array_dynamic_indexing_12;
    static constexpr bool              is_core      = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_uniform_texel_buffer_array_dynamic_indexing_12);
};
template <>
struct feature< ktl::api::feature::shader_storage_texel_buffer_array_dynamic_indexing_12 >
{
    static constexpr ktl::api::feature value = ktl::api::feature::shader_storage_texel_buffer_array_dynamic_indexing_12;
    static constexpr bool              is_core      = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_storage_texel_buffer_array_dynamic_indexing_12);
};
template <>
struct feature< ktl::api::feature::shader_uniform_buffer_array_non_uniform_indexing_12 >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_uniform_buffer_array_non_uniform_indexing_12;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_uniform_buffer_array_non_uniform_indexing_12);
};
template <>
struct feature< ktl::api::feature::shader_sampled_image_array_non_uniform_indexing_12 >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_sampled_image_array_non_uniform_indexing_12;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_sampled_image_array_non_uniform_indexing_12);
};
template <>
struct feature< ktl::api::feature::shader_storage_buffer_array_non_uniform_indexing_12 >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_storage_buffer_array_non_uniform_indexing_12;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_storage_buffer_array_non_uniform_indexing_12);
};
template <>
struct feature< ktl::api::feature::shader_storage_image_array_non_uniform_indexing_12 >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_storage_image_array_non_uniform_indexing_12;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_storage_image_array_non_uniform_indexing_12);
};
template <>
struct feature< ktl::api::feature::shader_input_attachment_array_non_uniform_indexing_12 >
{
    static constexpr ktl::api::feature value = ktl::api::feature::shader_input_attachment_array_non_uniform_indexing_12;
    static constexpr bool              is_core      = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_input_attachment_array_non_uniform_indexing_12);
};
template <>
struct feature< ktl::api::feature::shader_uniform_texel_buffer_array_non_uniform_indexing_12 >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::shader_uniform_texel_buffer_array_non_uniform_indexing_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_12features,
                                                          shader_uniform_texel_buffer_array_non_uniform_indexing_12);
};
template <>
struct feature< ktl::api::feature::shader_storage_texel_buffer_array_non_uniform_indexing_12 >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::shader_storage_texel_buffer_array_non_uniform_indexing_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_12features,
                                                          shader_storage_texel_buffer_array_non_uniform_indexing_12);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_uniform_buffer_update_after_bind_12 >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::descriptor_binding_uniform_buffer_update_after_bind_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, descriptor_binding_uniform_buffer_update_after_bind_12);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_sampled_image_update_after_bind_12 >
{
    static constexpr ktl::api::feature value = ktl::api::feature::descriptor_binding_sampled_image_update_after_bind_12;
    static constexpr bool              is_core      = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, descriptor_binding_sampled_image_update_after_bind_12);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_storage_image_update_after_bind_12 >
{
    static constexpr ktl::api::feature value = ktl::api::feature::descriptor_binding_storage_image_update_after_bind_12;
    static constexpr bool              is_core      = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, descriptor_binding_storage_image_update_after_bind_12);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_storage_buffer_update_after_bind_12 >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::descriptor_binding_storage_buffer_update_after_bind_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, descriptor_binding_storage_buffer_update_after_bind_12);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_uniform_texel_buffer_update_after_bind_12 >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::descriptor_binding_uniform_texel_buffer_update_after_bind_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_12features,
                                                          descriptor_binding_uniform_texel_buffer_update_after_bind_12);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_storage_texel_buffer_update_after_bind_12 >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::descriptor_binding_storage_texel_buffer_update_after_bind_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_12features,
                                                          descriptor_binding_storage_texel_buffer_update_after_bind_12);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_update_unused_while_pending_12 >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::descriptor_binding_update_unused_while_pending_12;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, descriptor_binding_update_unused_while_pending_12);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_partially_bound_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_binding_partially_bound_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, descriptor_binding_partially_bound_12);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_variable_descriptor_count_12 >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::descriptor_binding_variable_descriptor_count_12;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, descriptor_binding_variable_descriptor_count_12);
};
template <>
struct feature< ktl::api::feature::runtime_descriptor_array_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::runtime_descriptor_array_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, runtime_descriptor_array_12);
};
template <>
struct feature< ktl::api::feature::sampler_filter_minmax_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sampler_filter_minmax_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, sampler_filter_minmax_12);
};
template <>
struct feature< ktl::api::feature::scalar_block_layout_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::scalar_block_layout_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, scalar_block_layout_12);
};
template <>
struct feature< ktl::api::feature::imageless_framebuffer_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::imageless_framebuffer_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, imageless_framebuffer_12);
};
template <>
struct feature< ktl::api::feature::uniform_buffer_standard_layout_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::uniform_buffer_standard_layout_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, uniform_buffer_standard_layout_12);
};
template <>
struct feature< ktl::api::feature::shader_subgroup_extended_types_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_subgroup_extended_types_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_subgroup_extended_types_12);
};
template <>
struct feature< ktl::api::feature::separate_depth_stencil_layouts_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::separate_depth_stencil_layouts_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, separate_depth_stencil_layouts_12);
};
template <>
struct feature< ktl::api::feature::host_query_reset_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::host_query_reset_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, host_query_reset_12);
};
template <>
struct feature< ktl::api::feature::timeline_semaphore_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::timeline_semaphore_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, timeline_semaphore_12);
};
template <>
struct feature< ktl::api::feature::buffer_device_address_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::buffer_device_address_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, buffer_device_address_12);
};
template <>
struct feature< ktl::api::feature::buffer_device_address_capture_replay_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::buffer_device_address_capture_replay_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, buffer_device_address_capture_replay_12);
};
template <>
struct feature< ktl::api::feature::buffer_device_address_multi_device_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::buffer_device_address_multi_device_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, buffer_device_address_multi_device_12);
};
template <>
struct feature< ktl::api::feature::vulkan_memory_model_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::vulkan_memory_model_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, vulkan_memory_model_12);
};
template <>
struct feature< ktl::api::feature::vulkan_memory_model_device_scope_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::vulkan_memory_model_device_scope_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, vulkan_memory_model_device_scope_12);
};
template <>
struct feature< ktl::api::feature::vulkan_memory_model_availability_visibility_chains_12 >
{
    static constexpr ktl::api::feature value = ktl::api::feature::vulkan_memory_model_availability_visibility_chains_12;
    static constexpr bool              is_core      = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, vulkan_memory_model_availability_visibility_chains_12);
};
template <>
struct feature< ktl::api::feature::shader_output_viewport_index_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_output_viewport_index_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_output_viewport_index_12);
};
template <>
struct feature< ktl::api::feature::shader_output_layer_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_output_layer_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, shader_output_layer_12);
};
template <>
struct feature< ktl::api::feature::subgroup_broadcast_dynamic_id_12 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::subgroup_broadcast_dynamic_id_12;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_12features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_12features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_12features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_12features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_12features, subgroup_broadcast_dynamic_id_12);
};
template <>
struct feature< ktl::api::feature::robust_image_access_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::robust_image_access_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, robust_image_access_13);
};
template <>
struct feature< ktl::api::feature::inline_uniform_block_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::inline_uniform_block_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, inline_uniform_block_13);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_inline_uniform_block_update_after_bind_13 >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::descriptor_binding_inline_uniform_block_update_after_bind_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_13features,
                                                          descriptor_binding_inline_uniform_block_update_after_bind_13);
};
template <>
struct feature< ktl::api::feature::pipeline_creation_cache_control_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_creation_cache_control_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, pipeline_creation_cache_control_13);
};
template <>
struct feature< ktl::api::feature::private_data_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::private_data_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_13features, private_data_13);
};
template <>
struct feature< ktl::api::feature::shader_demote_to_helper_invocation_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_demote_to_helper_invocation_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, shader_demote_to_helper_invocation_13);
};
template <>
struct feature< ktl::api::feature::shader_terminate_invocation_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_terminate_invocation_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, shader_terminate_invocation_13);
};
template <>
struct feature< ktl::api::feature::subgroup_size_control_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::subgroup_size_control_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, subgroup_size_control_13);
};
template <>
struct feature< ktl::api::feature::compute_full_subgroups_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::compute_full_subgroups_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, compute_full_subgroups_13);
};
template <>
struct feature< ktl::api::feature::synchronization_213 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::synchronization_213;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, synchronization_213);
};
template <>
struct feature< ktl::api::feature::texture_compression_astc_hdr_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::texture_compression_astc_hdr_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, texture_compression_astc_hdr_13);
};
template <>
struct feature< ktl::api::feature::shader_zero_initialize_workgroup_memory_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_zero_initialize_workgroup_memory_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, shader_zero_initialize_workgroup_memory_13);
};
template <>
struct feature< ktl::api::feature::dynamic_rendering_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::dynamic_rendering_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, dynamic_rendering_13);
};
template <>
struct feature< ktl::api::feature::shader_integer_dot_product_13 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_integer_dot_product_13;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_13features, shader_integer_dot_product_13);
};
template <>
struct feature< ktl::api::feature::maintenance_413 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::maintenance_413;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_13features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_13features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_13features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_13features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_13features, maintenance_413);
};
template <>
struct feature< ktl::api::feature::global_priority_query_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::global_priority_query_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, global_priority_query_14);
};
template <>
struct feature< ktl::api::feature::shader_subgroup_rotate_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_subgroup_rotate_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, shader_subgroup_rotate_14);
};
template <>
struct feature< ktl::api::feature::shader_subgroup_rotate_clustered_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_subgroup_rotate_clustered_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, shader_subgroup_rotate_clustered_14);
};
template <>
struct feature< ktl::api::feature::shader_float_controls_214 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_float_controls_214;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, shader_float_controls_214);
};
template <>
struct feature< ktl::api::feature::shader_expect_assume_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_expect_assume_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, shader_expect_assume_14);
};
template <>
struct feature< ktl::api::feature::rectangular_lines_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::rectangular_lines_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, rectangular_lines_14);
};
template <>
struct feature< ktl::api::feature::bresenham_lines_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::bresenham_lines_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, bresenham_lines_14);
};
template <>
struct feature< ktl::api::feature::smooth_lines_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::smooth_lines_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_14features, smooth_lines_14);
};
template <>
struct feature< ktl::api::feature::stippled_rectangular_lines_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::stippled_rectangular_lines_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, stippled_rectangular_lines_14);
};
template <>
struct feature< ktl::api::feature::stippled_bresenham_lines_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::stippled_bresenham_lines_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, stippled_bresenham_lines_14);
};
template <>
struct feature< ktl::api::feature::stippled_smooth_lines_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::stippled_smooth_lines_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, stippled_smooth_lines_14);
};
template <>
struct feature< ktl::api::feature::vertex_attribute_instance_rate_divisor_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::vertex_attribute_instance_rate_divisor_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, vertex_attribute_instance_rate_divisor_14);
};
template <>
struct feature< ktl::api::feature::vertex_attribute_instance_rate_zero_divisor_14 >
{
    static constexpr ktl::api::feature        value = ktl::api::feature::vertex_attribute_instance_rate_zero_divisor_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, vertex_attribute_instance_rate_zero_divisor_14);
};
template <>
struct feature< ktl::api::feature::index_type_uint_814 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::index_type_uint_814;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, index_type_uint_814);
};
template <>
struct feature< ktl::api::feature::dynamic_rendering_local_read_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::dynamic_rendering_local_read_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, dynamic_rendering_local_read_14);
};
template <>
struct feature< ktl::api::feature::maintenance_514 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::maintenance_514;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_14features, maintenance_514);
};
template <>
struct feature< ktl::api::feature::maintenance_614 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::maintenance_614;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_vulkan_14features, maintenance_614);
};
template <>
struct feature< ktl::api::feature::pipeline_protected_access_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_protected_access_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, pipeline_protected_access_14);
};
template <>
struct feature< ktl::api::feature::pipeline_robustness_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_robustness_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, pipeline_robustness_14);
};
template <>
struct feature< ktl::api::feature::host_image_copy_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::host_image_copy_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, host_image_copy_14);
};
template <>
struct feature< ktl::api::feature::push_descriptor_14 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::push_descriptor_14;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_vulkan_14features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_14features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_14features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_14features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_14features, push_descriptor_14);
};
template <>
struct feature< ktl::api::feature::device_coherent_memory_amd >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_coherent_memory_amd;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_coherent_memory_features_amd;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_coherent_memory_features_amd);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_coherent_memory_features_amd, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_coherent_memory_features_amd, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_coherent_memory_features_amd, device_coherent_memory_amd);
};
template <>
struct feature< ktl::api::feature::perf_counters_amd >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::perf_counters_amd;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_gpa_features_amd;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_gpa_features_amd);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_gpa_features_amd, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_gpa_features_amd, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_gpa_features_amd, perf_counters_amd);
};
template <>
struct feature< ktl::api::feature::streaming_perf_counters_amd >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::streaming_perf_counters_amd;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_gpa_features_amd;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_gpa_features_amd);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_gpa_features_amd, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_gpa_features_amd, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_gpa_features_amd, streaming_perf_counters_amd);
};
template <>
struct feature< ktl::api::feature::sq_thread_tracing_amd >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sq_thread_tracing_amd;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_gpa_features_amd;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_gpa_features_amd);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_gpa_features_amd, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_gpa_features_amd, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_gpa_features_amd, sq_thread_tracing_amd);
};
template <>
struct feature< ktl::api::feature::clock_modes_amd >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::clock_modes_amd;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_gpa_features_amd;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_gpa_features_amd);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_gpa_features_amd, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_gpa_features_amd, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_gpa_features_amd, clock_modes_amd);
};
template <>
struct feature< ktl::api::feature::custom_border_colors_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::custom_border_colors_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_custom_border_color_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_custom_border_color_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_custom_border_color_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_custom_border_color_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_custom_border_color_features_ext, custom_border_colors_ext);
};
template <>
struct feature< ktl::api::feature::custom_border_color_without_format_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::custom_border_color_without_format_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_custom_border_color_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_custom_border_color_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_custom_border_color_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_custom_border_color_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_custom_border_color_features_ext, custom_border_color_without_format_ext);
};
template <>
struct feature< ktl::api::feature::border_color_swizzle_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::border_color_swizzle_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_border_color_swizzle_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_border_color_swizzle_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_border_color_swizzle_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_border_color_swizzle_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_border_color_swizzle_features_ext, border_color_swizzle_ext);
};
template <>
struct feature< ktl::api::feature::border_color_swizzle_from_image_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::border_color_swizzle_from_image_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_border_color_swizzle_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_border_color_swizzle_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_border_color_swizzle_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_border_color_swizzle_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_border_color_swizzle_features_ext, border_color_swizzle_from_image_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::extended_dynamic_state_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_features_ext, extended_dynamic_state_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_2ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::extended_dynamic_state_2ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_2features_ext, extended_dynamic_state_2ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_2logic_op_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::extended_dynamic_state_2logic_op_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_2features_ext, extended_dynamic_state_2logic_op_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_2patch_control_points_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::extended_dynamic_state_2patch_control_points_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_2features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_2features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_2features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_2features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_2features_ext,
                 extended_dynamic_state_2patch_control_points_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3tessellation_domain_origin_ext >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::extended_dynamic_state_3tessellation_domain_origin_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3tessellation_domain_origin_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3depth_clamp_enable_ext >
{
    static constexpr ktl::api::feature        value = ktl::api::feature::extended_dynamic_state_3depth_clamp_enable_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_extended_dynamic_state_3features_ext, extended_dynamic_state_3depth_clamp_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3polygon_mode_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::extended_dynamic_state_3polygon_mode_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_extended_dynamic_state_3features_ext, extended_dynamic_state_3polygon_mode_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3rasterization_samples_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::extended_dynamic_state_3rasterization_samples_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3rasterization_samples_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3sample_mask_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::extended_dynamic_state_3sample_mask_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_extended_dynamic_state_3features_ext, extended_dynamic_state_3sample_mask_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3alpha_to_coverage_enable_ext >
{
    static constexpr ktl::api::feature value = ktl::api::feature::extended_dynamic_state_3alpha_to_coverage_enable_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3alpha_to_coverage_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3alpha_to_one_enable_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::extended_dynamic_state_3alpha_to_one_enable_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3alpha_to_one_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3logic_op_enable_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::extended_dynamic_state_3logic_op_enable_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_extended_dynamic_state_3features_ext, extended_dynamic_state_3logic_op_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3color_blend_enable_ext >
{
    static constexpr ktl::api::feature        value = ktl::api::feature::extended_dynamic_state_3color_blend_enable_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_extended_dynamic_state_3features_ext, extended_dynamic_state_3color_blend_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3color_blend_equation_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::extended_dynamic_state_3color_blend_equation_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3color_blend_equation_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3color_write_mask_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::extended_dynamic_state_3color_write_mask_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_extended_dynamic_state_3features_ext, extended_dynamic_state_3color_write_mask_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3rasterization_stream_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::extended_dynamic_state_3rasterization_stream_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3rasterization_stream_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3conservative_rasterization_mode_ext >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::extended_dynamic_state_3conservative_rasterization_mode_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3conservative_rasterization_mode_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3extra_primitive_overestimation_size_ext >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::extended_dynamic_state_3extra_primitive_overestimation_size_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3extra_primitive_overestimation_size_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3depth_clip_enable_ext >
{
    static constexpr ktl::api::feature        value = ktl::api::feature::extended_dynamic_state_3depth_clip_enable_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_extended_dynamic_state_3features_ext, extended_dynamic_state_3depth_clip_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3sample_locations_enable_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::extended_dynamic_state_3sample_locations_enable_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3sample_locations_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3color_blend_advanced_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::extended_dynamic_state_3color_blend_advanced_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3color_blend_advanced_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3provoking_vertex_mode_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::extended_dynamic_state_3provoking_vertex_mode_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3provoking_vertex_mode_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3line_rasterization_mode_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::extended_dynamic_state_3line_rasterization_mode_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3line_rasterization_mode_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3line_stipple_enable_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::extended_dynamic_state_3line_stipple_enable_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3line_stipple_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3depth_clip_negative_one_to_one_ext >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::extended_dynamic_state_3depth_clip_negative_one_to_one_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3depth_clip_negative_one_to_one_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3viewport_w_scaling_enable_ext >
{
    static constexpr ktl::api::feature value = ktl::api::feature::extended_dynamic_state_3viewport_w_scaling_enable_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3viewport_w_scaling_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3viewport_swizzle_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::extended_dynamic_state_3viewport_swizzle_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_extended_dynamic_state_3features_ext, extended_dynamic_state_3viewport_swizzle_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3coverage_to_color_enable_ext >
{
    static constexpr ktl::api::feature value = ktl::api::feature::extended_dynamic_state_3coverage_to_color_enable_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3coverage_to_color_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3coverage_to_color_location_ext >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::extended_dynamic_state_3coverage_to_color_location_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3coverage_to_color_location_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3coverage_modulation_mode_ext >
{
    static constexpr ktl::api::feature value = ktl::api::feature::extended_dynamic_state_3coverage_modulation_mode_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3coverage_modulation_mode_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3coverage_modulation_table_enable_ext >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::extended_dynamic_state_3coverage_modulation_table_enable_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3coverage_modulation_table_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3coverage_modulation_table_ext >
{
    static constexpr ktl::api::feature value = ktl::api::feature::extended_dynamic_state_3coverage_modulation_table_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3coverage_modulation_table_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3coverage_reduction_mode_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::extended_dynamic_state_3coverage_reduction_mode_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3coverage_reduction_mode_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3representative_fragment_test_enable_ext >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::extended_dynamic_state_3representative_fragment_test_enable_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3representative_fragment_test_enable_ext);
};
template <>
struct feature< ktl::api::feature::extended_dynamic_state_3shading_rate_image_enable_ext >
{
    static constexpr ktl::api::feature value = ktl::api::feature::extended_dynamic_state_3shading_rate_image_enable_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_dynamic_state_3features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_extended_dynamic_state_3features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_dynamic_state_3features_ext,
                 extended_dynamic_state_3shading_rate_image_enable_ext);
};
template <>
struct feature< ktl::api::feature::partitioned_acceleration_structure_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::partitioned_acceleration_structure_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_partitioned_acceleration_structure_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_partitioned_acceleration_structure_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_partitioned_acceleration_structure_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_partitioned_acceleration_structure_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_partitioned_acceleration_structure_features_nv,
                 partitioned_acceleration_structure_nv);
};
template <>
struct feature< ktl::api::feature::diagnostics_config_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::diagnostics_config_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_diagnostics_config_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_diagnostics_config_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_diagnostics_config_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_diagnostics_config_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_diagnostics_config_features_nv, diagnostics_config_nv);
};
template <>
struct feature< ktl::api::feature::shader_zero_initialize_workgroup_memory >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_zero_initialize_workgroup_memory;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_zero_initialize_workgroup_memory_features;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_zero_initialize_workgroup_memory_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_zero_initialize_workgroup_memory_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_zero_initialize_workgroup_memory_features, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_zero_initialize_workgroup_memory_features, shader_zero_initialize_workgroup_memory);
};
template <>
struct feature< ktl::api::feature::shader_subgroup_uniform_control_flow_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_subgroup_uniform_control_flow_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_subgroup_uniform_control_flow_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_subgroup_uniform_control_flow_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_subgroup_uniform_control_flow_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_subgroup_uniform_control_flow_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_subgroup_uniform_control_flow_features_khr,
                 shader_subgroup_uniform_control_flow_khr);
};
template <>
struct feature< ktl::api::feature::robust_buffer_access_2khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::robust_buffer_access_2khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_robustness_2features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_robustness_2features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_robustness_2features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_robustness_2features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_robustness_2features_khr, robust_buffer_access_2khr);
};
template <>
struct feature< ktl::api::feature::robust_image_access_2khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::robust_image_access_2khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_robustness_2features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_robustness_2features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_robustness_2features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_robustness_2features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_robustness_2features_khr, robust_image_access_2khr);
};
template <>
struct feature< ktl::api::feature::null_descriptor_2khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::null_descriptor_2khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_robustness_2features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_robustness_2features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_robustness_2features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_robustness_2features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_robustness_2features_khr, null_descriptor_2khr);
};
template <>
struct feature< ktl::api::feature::robust_image_access >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::robust_image_access;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_robustness_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_image_robustness_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_image_robustness_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_image_robustness_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_robustness_features, robust_image_access);
};
template <>
struct feature< ktl::api::feature::workgroup_memory_explicit_layout_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::workgroup_memory_explicit_layout_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_workgroup_memory_explicit_layout_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr, workgroup_memory_explicit_layout_khr);
};
template <>
struct feature< ktl::api::feature::workgroup_memory_explicit_layout_scalar_block_layout_khr >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::workgroup_memory_explicit_layout_scalar_block_layout_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_workgroup_memory_explicit_layout_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr,
                 workgroup_memory_explicit_layout_scalar_block_layout_khr);
};
template <>
struct feature< ktl::api::feature::workgroup_memory_explicit_layout_8bit_access_khr >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::workgroup_memory_explicit_layout_8bit_access_khr;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_workgroup_memory_explicit_layout_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr,
                 workgroup_memory_explicit_layout_8bit_access_khr);
};
template <>
struct feature< ktl::api::feature::workgroup_memory_explicit_layout_16bit_access_khr >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::workgroup_memory_explicit_layout_16bit_access_khr;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_workgroup_memory_explicit_layout_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_workgroup_memory_explicit_layout_features_khr,
                 workgroup_memory_explicit_layout_16bit_access_khr);
};
template <>
struct feature< ktl::api::feature::constant_alpha_color_blend_factors_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::constant_alpha_color_blend_factors_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, constant_alpha_color_blend_factors_khr);
};
template <>
struct feature< ktl::api::feature::events_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::events_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, events_khr);
};
template <>
struct feature< ktl::api::feature::image_view_format_reinterpretation_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::image_view_format_reinterpretation_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, image_view_format_reinterpretation_khr);
};
template <>
struct feature< ktl::api::feature::image_view_format_swizzle_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::image_view_format_swizzle_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, image_view_format_swizzle_khr);
};
template <>
struct feature< ktl::api::feature::image_view_2d_on_3d_image_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::image_view_2d_on_3d_image_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, image_view_2d_on_3d_image_khr);
};
template <>
struct feature< ktl::api::feature::multisample_array_image_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multisample_array_image_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, multisample_array_image_khr);
};
template <>
struct feature< ktl::api::feature::mutable_comparison_samplers_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::mutable_comparison_samplers_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, mutable_comparison_samplers_khr);
};
template <>
struct feature< ktl::api::feature::point_polygons_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::point_polygons_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, point_polygons_khr);
};
template <>
struct feature< ktl::api::feature::sampler_mip_lod_bias_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sampler_mip_lod_bias_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, sampler_mip_lod_bias_khr);
};
template <>
struct feature< ktl::api::feature::separate_stencil_mask_ref_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::separate_stencil_mask_ref_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, separate_stencil_mask_ref_khr);
};
template <>
struct feature< ktl::api::feature::shader_sample_rate_interpolation_functions_khr >
{
    static constexpr ktl::api::feature        value = ktl::api::feature::shader_sample_rate_interpolation_functions_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_portability_subset_features_khr,
                                                          shader_sample_rate_interpolation_functions_khr);
};
template <>
struct feature< ktl::api::feature::tessellation_isolines_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tessellation_isolines_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, tessellation_isolines_khr);
};
template <>
struct feature< ktl::api::feature::tessellation_point_mode_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tessellation_point_mode_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, tessellation_point_mode_khr);
};
template <>
struct feature< ktl::api::feature::triangle_fans_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::triangle_fans_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, triangle_fans_khr);
};
template <>
struct feature< ktl::api::feature::vertex_attribute_access_beyond_stride_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::vertex_attribute_access_beyond_stride_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_portability_subset_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_portability_subset_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_portability_subset_features_khr, vertex_attribute_access_beyond_stride_khr);
};
template <>
struct feature< ktl::api::feature::format_a_4r_4g_4b_44444ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::format_a_4r_4g_4b_44444ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_4444formats_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_4444formats_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_4444formats_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_4444formats_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_4444formats_features_ext, format_a_4r_4g_4b_44444ext);
};
template <>
struct feature< ktl::api::feature::format_a_4b_4g_4r_44444ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::format_a_4b_4g_4r_44444ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_4444formats_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_4444formats_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_4444formats_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_4444formats_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_4444formats_features_ext, format_a_4b_4g_4r_44444ext);
};
template <>
struct feature< ktl::api::feature::subpass_shading_huawei >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::subpass_shading_huawei;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_subpass_shading_features_huawei;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_subpass_shading_features_huawei);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_subpass_shading_features_huawei, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_subpass_shading_features_huawei, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_subpass_shading_features_huawei, subpass_shading_huawei);
};
template <>
struct feature< ktl::api::feature::clusterculling_shader_huawei >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::clusterculling_shader_huawei;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cluster_culling_shader_features_huawei;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_cluster_culling_shader_features_huawei);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cluster_culling_shader_features_huawei, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cluster_culling_shader_features_huawei, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cluster_culling_shader_features_huawei, clusterculling_shader_huawei);
};
template <>
struct feature< ktl::api::feature::multiview_cluster_culling_shader_huawei >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multiview_cluster_culling_shader_huawei;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cluster_culling_shader_features_huawei;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_cluster_culling_shader_features_huawei);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cluster_culling_shader_features_huawei, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cluster_culling_shader_features_huawei, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_cluster_culling_shader_features_huawei, multiview_cluster_culling_shader_huawei);
};
template <>
struct feature< ktl::api::feature::cluster_shading_rate_huawei >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cluster_shading_rate_huawei;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cluster_culling_shader_vrs_features_huawei;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_cluster_culling_shader_vrs_features_huawei);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cluster_culling_shader_vrs_features_huawei, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cluster_culling_shader_vrs_features_huawei, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cluster_culling_shader_vrs_features_huawei, cluster_shading_rate_huawei);
};
template <>
struct feature< ktl::api::feature::shader_image_int_64atomics_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_image_int_64atomics_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_image_atomic_int_64features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_image_atomic_int_64features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_image_atomic_int_64features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_image_atomic_int_64features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_image_atomic_int_64features_ext, shader_image_int_64atomics_ext);
};
template <>
struct feature< ktl::api::feature::sparse_image_int_64atomics_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sparse_image_int_64atomics_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_image_atomic_int_64features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_image_atomic_int_64features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_image_atomic_int_64features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_image_atomic_int_64features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_image_atomic_int_64features_ext, sparse_image_int_64atomics_ext);
};
template <>
struct feature< ktl::api::feature::pipeline_fragment_shading_rate_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_fragment_shading_rate_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_shading_rate_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_fragment_shading_rate_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_shading_rate_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_shading_rate_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fragment_shading_rate_features_khr, pipeline_fragment_shading_rate_khr);
};
template <>
struct feature< ktl::api::feature::primitive_fragment_shading_rate_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::primitive_fragment_shading_rate_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_shading_rate_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_fragment_shading_rate_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_shading_rate_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_shading_rate_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fragment_shading_rate_features_khr, primitive_fragment_shading_rate_khr);
};
template <>
struct feature< ktl::api::feature::attachment_fragment_shading_rate_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::attachment_fragment_shading_rate_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_shading_rate_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_fragment_shading_rate_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_shading_rate_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_shading_rate_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fragment_shading_rate_features_khr, attachment_fragment_shading_rate_khr);
};
template <>
struct feature< ktl::api::feature::shader_terminate_invocation >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_terminate_invocation;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_terminate_invocation_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_terminate_invocation_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_terminate_invocation_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_terminate_invocation_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_terminate_invocation_features, shader_terminate_invocation);
};
template <>
struct feature< ktl::api::feature::fragment_shading_rate_enums_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::fragment_shading_rate_enums_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_shading_rate_enums_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_fragment_shading_rate_enums_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_shading_rate_enums_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_shading_rate_enums_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fragment_shading_rate_enums_features_nv, fragment_shading_rate_enums_nv);
};
template <>
struct feature< ktl::api::feature::supersample_fragment_shading_rates_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::supersample_fragment_shading_rates_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_shading_rate_enums_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_fragment_shading_rate_enums_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_shading_rate_enums_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_shading_rate_enums_features_nv, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_fragment_shading_rate_enums_features_nv, supersample_fragment_shading_rates_nv);
};
template <>
struct feature< ktl::api::feature::no_invocation_fragment_shading_rates_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::no_invocation_fragment_shading_rates_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_shading_rate_enums_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_fragment_shading_rate_enums_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_shading_rate_enums_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_shading_rate_enums_features_nv, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_fragment_shading_rate_enums_features_nv, no_invocation_fragment_shading_rates_nv);
};
template <>
struct feature< ktl::api::feature::image_2d_view_of_3d_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::image_2d_view_of_3d_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_2d_view_of_3d_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_2d_view_of_3d_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_2d_view_of_3d_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_2d_view_of_3d_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_2d_view_of_3d_features_ext, image_2d_view_of_3d_ext);
};
template <>
struct feature< ktl::api::feature::sampler_2d_view_of_3d_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::sampler_2d_view_of_3d_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_2d_view_of_3d_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_2d_view_of_3d_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_2d_view_of_3d_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_2d_view_of_3d_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_2d_view_of_3d_features_ext, sampler_2d_view_of_3d_ext);
};
template <>
struct feature< ktl::api::feature::image_sliced_view_of_3d_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::image_sliced_view_of_3d_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_sliced_view_of_3d_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_sliced_view_of_3d_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_sliced_view_of_3d_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_sliced_view_of_3d_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_sliced_view_of_3d_features_ext, image_sliced_view_of_3d_ext);
};
template <>
struct feature< ktl::api::feature::attachment_feedback_loop_dynamic_state_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::attachment_feedback_loop_dynamic_state_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_attachment_feedback_loop_dynamic_state_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_attachment_feedback_loop_dynamic_state_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_attachment_feedback_loop_dynamic_state_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_attachment_feedback_loop_dynamic_state_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_attachment_feedback_loop_dynamic_state_features_ext,
                 attachment_feedback_loop_dynamic_state_ext);
};
template <>
struct feature< ktl::api::feature::legacy_vertex_attributes_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::legacy_vertex_attributes_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_legacy_vertex_attributes_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_legacy_vertex_attributes_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_legacy_vertex_attributes_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_legacy_vertex_attributes_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_legacy_vertex_attributes_features_ext, legacy_vertex_attributes_ext);
};
template <>
struct feature< ktl::api::feature::mutable_descriptor_type_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::mutable_descriptor_type_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_mutable_descriptor_type_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_mutable_descriptor_type_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_mutable_descriptor_type_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_mutable_descriptor_type_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_mutable_descriptor_type_features_ext, mutable_descriptor_type_ext);
};
template <>
struct feature< ktl::api::feature::depth_clip_control_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::depth_clip_control_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_depth_clip_control_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_depth_clip_control_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_depth_clip_control_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_depth_clip_control_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_depth_clip_control_features_ext, depth_clip_control_ext);
};
template <>
struct feature< ktl::api::feature::zero_initialize_device_memory_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::zero_initialize_device_memory_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_zero_initialize_device_memory_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_zero_initialize_device_memory_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_zero_initialize_device_memory_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_zero_initialize_device_memory_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_zero_initialize_device_memory_features_ext, zero_initialize_device_memory_ext);
};
template <>
struct feature< ktl::api::feature::custom_resolve_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::custom_resolve_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_custom_resolve_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_custom_resolve_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_custom_resolve_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_custom_resolve_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_custom_resolve_features_ext, custom_resolve_ext);
};
template <>
struct feature< ktl::api::feature::device_generated_commands_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_generated_commands_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_device_generated_commands_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_device_generated_commands_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_device_generated_commands_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_device_generated_commands_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_device_generated_commands_features_ext, device_generated_commands_ext);
};
template <>
struct feature< ktl::api::feature::dynamic_generated_pipeline_layout_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::dynamic_generated_pipeline_layout_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_device_generated_commands_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_device_generated_commands_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_device_generated_commands_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_device_generated_commands_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_device_generated_commands_features_ext, dynamic_generated_pipeline_layout_ext);
};
template <>
struct feature< ktl::api::feature::depth_clamp_control_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::depth_clamp_control_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_depth_clamp_control_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_depth_clamp_control_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_depth_clamp_control_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_depth_clamp_control_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_depth_clamp_control_features_ext, depth_clamp_control_ext);
};
template <>
struct feature< ktl::api::feature::vertex_input_dynamic_state_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::vertex_input_dynamic_state_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_vertex_input_dynamic_state_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_vertex_input_dynamic_state_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_vertex_input_dynamic_state_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_vertex_input_dynamic_state_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vertex_input_dynamic_state_features_ext, vertex_input_dynamic_state_ext);
};
template <>
struct feature< ktl::api::feature::external_memory_rdma_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::external_memory_rdma_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_memory_rdma_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_external_memory_rdma_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_memory_rdma_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_memory_rdma_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_memory_rdma_features_nv, external_memory_rdma_nv);
};
template <>
struct feature< ktl::api::feature::shader_relaxed_extended_instruction_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_relaxed_extended_instruction_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_relaxed_extended_instruction_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_relaxed_extended_instruction_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_relaxed_extended_instruction_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_relaxed_extended_instruction_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_relaxed_extended_instruction_features_khr,
                 shader_relaxed_extended_instruction_khr);
};
template <>
struct feature< ktl::api::feature::color_write_enable_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::color_write_enable_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_color_write_enable_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_color_write_enable_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_color_write_enable_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_color_write_enable_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_color_write_enable_features_ext, color_write_enable_ext);
};
template <>
struct feature< ktl::api::feature::synchronization_2 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::synchronization_2;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_synchronization_2features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_synchronization_2features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_synchronization_2features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_synchronization_2features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_synchronization_2features, synchronization_2);
};
template <>
struct feature< ktl::api::feature::unified_image_layouts_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::unified_image_layouts_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_unified_image_layouts_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_unified_image_layouts_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_unified_image_layouts_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_unified_image_layouts_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_unified_image_layouts_features_khr, unified_image_layouts_khr);
};
template <>
struct feature< ktl::api::feature::unified_image_layouts_video_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::unified_image_layouts_video_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_unified_image_layouts_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_unified_image_layouts_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_unified_image_layouts_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_unified_image_layouts_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_unified_image_layouts_features_khr, unified_image_layouts_video_khr);
};
template <>
struct feature< ktl::api::feature::host_image_copy >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::host_image_copy;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_host_image_copy_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_host_image_copy_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_host_image_copy_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_host_image_copy_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_host_image_copy_features, host_image_copy);
};
template <>
struct feature< ktl::api::feature::shader_atomic_instructions_10 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_atomic_instructions_10;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_vulkan_sc_10features;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_vulkan_sc_10features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_vulkan_sc_10features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_vulkan_sc_10features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vulkan_sc_10features, shader_atomic_instructions_10);
};
template <>
struct feature< ktl::api::feature::primitives_generated_query_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::primitives_generated_query_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_primitives_generated_query_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_primitives_generated_query_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_primitives_generated_query_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_primitives_generated_query_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_primitives_generated_query_features_ext, primitives_generated_query_ext);
};
template <>
struct feature< ktl::api::feature::primitives_generated_query_with_rasterizer_discard_ext >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::primitives_generated_query_with_rasterizer_discard_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_primitives_generated_query_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_primitives_generated_query_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_primitives_generated_query_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_primitives_generated_query_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_primitives_generated_query_features_ext,
                 primitives_generated_query_with_rasterizer_discard_ext);
};
template <>
struct feature< ktl::api::feature::primitives_generated_query_with_non_zero_streams_ext >
{
    static constexpr ktl::api::feature value = ktl::api::feature::primitives_generated_query_with_non_zero_streams_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_primitives_generated_query_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_primitives_generated_query_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_primitives_generated_query_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_primitives_generated_query_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_primitives_generated_query_features_ext,
                 primitives_generated_query_with_non_zero_streams_ext);
};
template <>
struct feature< ktl::api::feature::legacy_dithering_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::legacy_dithering_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_legacy_dithering_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_legacy_dithering_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_legacy_dithering_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_legacy_dithering_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_legacy_dithering_features_ext, legacy_dithering_ext);
};
template <>
struct feature< ktl::api::feature::multisampled_render_to_single_sampled_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multisampled_render_to_single_sampled_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_multisampled_render_to_single_sampled_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_multisampled_render_to_single_sampled_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_multisampled_render_to_single_sampled_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_multisampled_render_to_single_sampled_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_multisampled_render_to_single_sampled_features_ext,
                 multisampled_render_to_single_sampled_ext);
};
template <>
struct feature< ktl::api::feature::pipeline_protected_access >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_protected_access;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_pipeline_protected_access_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_pipeline_protected_access_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_pipeline_protected_access_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_pipeline_protected_access_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_pipeline_protected_access_features, pipeline_protected_access);
};
template <>
struct feature< ktl::api::feature::inherited_viewport_scissor_2d_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::inherited_viewport_scissor_2d_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_inherited_viewport_scissor_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_inherited_viewport_scissor_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_inherited_viewport_scissor_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_inherited_viewport_scissor_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_inherited_viewport_scissor_features_nv, inherited_viewport_scissor_2d_nv);
};
template <>
struct feature< ktl::api::feature::ycbcr_2plane_444formats_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ycbcr_2plane_444formats_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ycbcr_2plane_444formats_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ycbcr_2plane_444formats_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ycbcr_2plane_444formats_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ycbcr_2plane_444formats_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ycbcr_2plane_444formats_features_ext, ycbcr_2plane_444formats_ext);
};
template <>
struct feature< ktl::api::feature::provoking_vertex_last_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::provoking_vertex_last_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_provoking_vertex_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_provoking_vertex_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_provoking_vertex_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_provoking_vertex_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_provoking_vertex_features_ext, provoking_vertex_last_ext);
};
template <>
struct feature< ktl::api::feature::transform_feedback_preserves_provoking_vertex_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::transform_feedback_preserves_provoking_vertex_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_provoking_vertex_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_provoking_vertex_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_provoking_vertex_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_provoking_vertex_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_provoking_vertex_features_ext,
                                                          transform_feedback_preserves_provoking_vertex_ext);
};
template <>
struct feature< ktl::api::feature::descriptor_buffer_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_buffer_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_buffer_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_buffer_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, descriptor_buffer_ext);
};
template <>
struct feature< ktl::api::feature::descriptor_buffer_capture_replay_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_buffer_capture_replay_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_buffer_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_buffer_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, descriptor_buffer_capture_replay_ext);
};
template <>
struct feature< ktl::api::feature::descriptor_buffer_image_layout_ignored_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_buffer_image_layout_ignored_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_buffer_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_buffer_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, descriptor_buffer_image_layout_ignored_ext);
};
template <>
struct feature< ktl::api::feature::descriptor_buffer_push_descriptors_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_buffer_push_descriptors_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_buffer_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_buffer_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_descriptor_buffer_features_ext, descriptor_buffer_push_descriptors_ext);
};
template <>
struct feature< ktl::api::feature::shader_integer_dot_product >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_integer_dot_product;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_integer_dot_product_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_integer_dot_product_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_integer_dot_product_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_integer_dot_product_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_integer_dot_product_features, shader_integer_dot_product);
};
template <>
struct feature< ktl::api::feature::fragment_shader_barycentric_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::fragment_shader_barycentric_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_shader_barycentric_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_fragment_shader_barycentric_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_shader_barycentric_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_shader_barycentric_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fragment_shader_barycentric_features_khr, fragment_shader_barycentric_khr);
};
template <>
struct feature< ktl::api::feature::shader_fma_float_16khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_fma_float_16khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_fma_features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_shader_fma_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_shader_fma_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_shader_fma_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_fma_features_khr, shader_fma_float_16khr);
};
template <>
struct feature< ktl::api::feature::shader_fma_float_32khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_fma_float_32khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_fma_features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_shader_fma_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_shader_fma_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_shader_fma_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_fma_features_khr, shader_fma_float_32khr);
};
template <>
struct feature< ktl::api::feature::shader_fma_float_64khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_fma_float_64khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_fma_features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_shader_fma_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_shader_fma_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_shader_fma_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_fma_features_khr, shader_fma_float_64khr);
};
template <>
struct feature< ktl::api::feature::ray_tracing_motion_blur_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ray_tracing_motion_blur_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_motion_blur_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ray_tracing_motion_blur_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_motion_blur_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_motion_blur_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ray_tracing_motion_blur_features_nv, ray_tracing_motion_blur_nv);
};
template <>
struct feature< ktl::api::feature::ray_tracing_motion_blur_pipeline_trace_rays_indirect_nv >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::ray_tracing_motion_blur_pipeline_trace_rays_indirect_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_motion_blur_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ray_tracing_motion_blur_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_motion_blur_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_motion_blur_features_nv, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_ray_tracing_motion_blur_features_nv,
                                                          ray_tracing_motion_blur_pipeline_trace_rays_indirect_nv);
};
template <>
struct feature< ktl::api::feature::ray_tracing_validation_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ray_tracing_validation_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_validation_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_ray_tracing_validation_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_validation_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_validation_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ray_tracing_validation_features_nv, ray_tracing_validation_nv);
};
template <>
struct feature< ktl::api::feature::spheres_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::spheres_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_linear_swept_spheres_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_ray_tracing_linear_swept_spheres_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_linear_swept_spheres_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_linear_swept_spheres_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ray_tracing_linear_swept_spheres_features_nv, spheres_nv);
};
template <>
struct feature< ktl::api::feature::linear_swept_spheres_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::linear_swept_spheres_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_linear_swept_spheres_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_ray_tracing_linear_swept_spheres_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_linear_swept_spheres_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_linear_swept_spheres_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ray_tracing_linear_swept_spheres_features_nv, linear_swept_spheres_nv);
};
template <>
struct feature< ktl::api::feature::format_rgba_10x_6without_y_cb_cr_sampler_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::format_rgba_10x_6without_y_cb_cr_sampler_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_rgba_10x_6formats_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_rgba_10x_6formats_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_rgba_10x_6formats_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_rgba_10x_6formats_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_rgba_10x_6formats_features_ext,
                                                          format_rgba_10x_6without_y_cb_cr_sampler_ext);
};
template <>
struct feature< ktl::api::feature::dynamic_rendering >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::dynamic_rendering;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_dynamic_rendering_features;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_dynamic_rendering_features);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_dynamic_rendering_features, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_dynamic_rendering_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_dynamic_rendering_features, dynamic_rendering);
};
template <>
struct feature< ktl::api::feature::min_lod_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::min_lod_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_view_min_lod_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_view_min_lod_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_view_min_lod_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_view_min_lod_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_view_min_lod_features_ext, min_lod_ext);
};
template <>
struct feature< ktl::api::feature::rasterization_order_color_attachment_access_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::rasterization_order_color_attachment_access_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_rasterization_order_attachment_access_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext,
                 rasterization_order_color_attachment_access_ext);
};
template <>
struct feature< ktl::api::feature::rasterization_order_depth_attachment_access_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::rasterization_order_depth_attachment_access_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_rasterization_order_attachment_access_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext,
                 rasterization_order_depth_attachment_access_ext);
};
template <>
struct feature< ktl::api::feature::rasterization_order_stencil_attachment_access_ext >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::rasterization_order_stencil_attachment_access_ext;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_rasterization_order_attachment_access_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_rasterization_order_attachment_access_features_ext,
                 rasterization_order_stencil_attachment_access_ext);
};
template <>
struct feature< ktl::api::feature::linear_color_attachment_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::linear_color_attachment_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_linear_color_attachment_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_linear_color_attachment_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_linear_color_attachment_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_linear_color_attachment_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_linear_color_attachment_features_nv, linear_color_attachment_nv);
};
template <>
struct feature< ktl::api::feature::graphics_pipeline_library_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::graphics_pipeline_library_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_graphics_pipeline_library_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_graphics_pipeline_library_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_graphics_pipeline_library_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_graphics_pipeline_library_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_graphics_pipeline_library_features_ext, graphics_pipeline_library_ext);
};
template <>
struct feature< ktl::api::feature::pipeline_binaries_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_binaries_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_pipeline_binary_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_pipeline_binary_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_pipeline_binary_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_pipeline_binary_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_pipeline_binary_features_khr, pipeline_binaries_khr);
};
template <>
struct feature< ktl::api::feature::data_graph_neural_accelerator_statistics_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::data_graph_neural_accelerator_statistics_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_data_graph_neural_accelerator_statistics_features_arm;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_data_graph_neural_accelerator_statistics_features_arm);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_data_graph_neural_accelerator_statistics_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_data_graph_neural_accelerator_statistics_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_data_graph_neural_accelerator_statistics_features_arm,
                 data_graph_neural_accelerator_statistics_arm);
};
template <>
struct feature< ktl::api::feature::descriptor_set_host_mapping_valve >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_set_host_mapping_valve;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_set_host_mapping_features_valve;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_descriptor_set_host_mapping_features_valve);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_set_host_mapping_features_valve, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_set_host_mapping_features_valve, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_descriptor_set_host_mapping_features_valve, descriptor_set_host_mapping_valve);
};
template <>
struct feature< ktl::api::feature::nested_command_buffer_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::nested_command_buffer_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_nested_command_buffer_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_nested_command_buffer_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_nested_command_buffer_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_nested_command_buffer_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_nested_command_buffer_features_ext, nested_command_buffer_ext);
};
template <>
struct feature< ktl::api::feature::nested_command_buffer_rendering_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::nested_command_buffer_rendering_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_nested_command_buffer_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_nested_command_buffer_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_nested_command_buffer_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_nested_command_buffer_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_nested_command_buffer_features_ext, nested_command_buffer_rendering_ext);
};
template <>
struct feature< ktl::api::feature::nested_command_buffer_simultaneous_use_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::nested_command_buffer_simultaneous_use_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_nested_command_buffer_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_nested_command_buffer_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_nested_command_buffer_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_nested_command_buffer_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_nested_command_buffer_features_ext,
                                                          nested_command_buffer_simultaneous_use_ext);
};
template <>
struct feature< ktl::api::feature::shader_module_identifier_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_module_identifier_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_module_identifier_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_module_identifier_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_module_identifier_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_module_identifier_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_module_identifier_features_ext, shader_module_identifier_ext);
};
template <>
struct feature< ktl::api::feature::image_compression_control_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::image_compression_control_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_compression_control_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_image_compression_control_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_compression_control_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_compression_control_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_compression_control_features_ext, image_compression_control_ext);
};
template <>
struct feature< ktl::api::feature::image_compression_control_swapchain_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::image_compression_control_swapchain_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_compression_control_swapchain_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_image_compression_control_swapchain_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_compression_control_swapchain_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_compression_control_swapchain_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_compression_control_swapchain_features_ext,
                 image_compression_control_swapchain_ext);
};
template <>
struct feature< ktl::api::feature::subpass_merge_feedback_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::subpass_merge_feedback_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_subpass_merge_feedback_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_subpass_merge_feedback_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_subpass_merge_feedback_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_subpass_merge_feedback_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_subpass_merge_feedback_features_ext, subpass_merge_feedback_ext);
};
template <>
struct feature< ktl::api::feature::micromap_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::micromap_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_opacity_micromap_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_opacity_micromap_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_opacity_micromap_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_opacity_micromap_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_opacity_micromap_features_khr, micromap_khr);
};
template <>
struct feature< ktl::api::feature::micromap_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::micromap_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_opacity_micromap_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_opacity_micromap_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_opacity_micromap_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_opacity_micromap_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_opacity_micromap_features_ext, micromap_ext);
};
template <>
struct feature< ktl::api::feature::micromap_capture_replay_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::micromap_capture_replay_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_opacity_micromap_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_opacity_micromap_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_opacity_micromap_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_opacity_micromap_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_opacity_micromap_features_ext, micromap_capture_replay_ext);
};
template <>
struct feature< ktl::api::feature::micromap_host_commands_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::micromap_host_commands_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_opacity_micromap_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_opacity_micromap_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_opacity_micromap_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_opacity_micromap_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_opacity_micromap_features_ext, micromap_host_commands_ext);
};
template <>
struct feature< ktl::api::feature::displacement_micromap_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::displacement_micromap_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_displacement_micromap_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_displacement_micromap_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_displacement_micromap_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_displacement_micromap_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_displacement_micromap_features_nv, displacement_micromap_nv);
};
template <>
struct feature< ktl::api::feature::pipeline_properties_identifier_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_properties_identifier_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_pipeline_properties_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_pipeline_properties_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_pipeline_properties_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_pipeline_properties_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_pipeline_properties_features_ext, pipeline_properties_identifier_ext);
};
template <>
struct feature< ktl::api::feature::shader_early_and_late_fragment_tests_amd >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_early_and_late_fragment_tests_amd;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_early_and_late_fragment_tests_features_amd;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_early_and_late_fragment_tests_features_amd);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_early_and_late_fragment_tests_features_amd, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_early_and_late_fragment_tests_features_amd, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_early_and_late_fragment_tests_features_amd,
                 shader_early_and_late_fragment_tests_amd);
};
template <>
struct feature< ktl::api::feature::non_seamless_cube_map_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::non_seamless_cube_map_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_non_seamless_cube_map_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_non_seamless_cube_map_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_non_seamless_cube_map_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_non_seamless_cube_map_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_non_seamless_cube_map_features_ext, non_seamless_cube_map_ext);
};
template <>
struct feature< ktl::api::feature::pipeline_robustness >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_robustness;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_pipeline_robustness_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_pipeline_robustness_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_pipeline_robustness_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_pipeline_robustness_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_pipeline_robustness_features, pipeline_robustness);
};
template <>
struct feature< ktl::api::feature::shader_multiple_wait_queues_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_multiple_wait_queues_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_multiple_wait_queues_features_qcom;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_multiple_wait_queues_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_multiple_wait_queues_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_multiple_wait_queues_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_multiple_wait_queues_features_qcom, shader_multiple_wait_queues_qcom);
};
template <>
struct feature< ktl::api::feature::texture_sample_weighted_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::texture_sample_weighted_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_processing_features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_processing_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_processing_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_processing_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_processing_features_qcom, texture_sample_weighted_qcom);
};
template <>
struct feature< ktl::api::feature::texture_box_filter_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::texture_box_filter_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_processing_features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_processing_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_processing_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_processing_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_processing_features_qcom, texture_box_filter_qcom);
};
template <>
struct feature< ktl::api::feature::texture_block_match_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::texture_block_match_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_processing_features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_processing_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_processing_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_processing_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_processing_features_qcom, texture_block_match_qcom);
};
template <>
struct feature< ktl::api::feature::tile_properties_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_properties_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_properties_features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_tile_properties_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_tile_properties_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_tile_properties_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_properties_features_qcom, tile_properties_qcom);
};
template <>
struct feature< ktl::api::feature::amigo_profiling_sec >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::amigo_profiling_sec;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_amigo_profiling_features_sec;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_amigo_profiling_features_sec);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_amigo_profiling_features_sec, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_amigo_profiling_features_sec, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_amigo_profiling_features_sec, amigo_profiling_sec);
};
template <>
struct feature< ktl::api::feature::attachment_feedback_loop_layout_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::attachment_feedback_loop_layout_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_attachment_feedback_loop_layout_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_attachment_feedback_loop_layout_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_attachment_feedback_loop_layout_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_attachment_feedback_loop_layout_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_attachment_feedback_loop_layout_features_ext, attachment_feedback_loop_layout_ext);
};
template <>
struct feature< ktl::api::feature::report_address_binding_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::report_address_binding_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_address_binding_report_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_address_binding_report_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_address_binding_report_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_address_binding_report_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_address_binding_report_features_ext, report_address_binding_ext);
};
template <>
struct feature< ktl::api::feature::optical_flow_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::optical_flow_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_optical_flow_features_nv;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_optical_flow_features_nv);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_optical_flow_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_optical_flow_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_optical_flow_features_nv, optical_flow_nv);
};
template <>
struct feature< ktl::api::feature::device_fault_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_fault_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_fault_features_ext;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_fault_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_fault_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_fault_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fault_features_ext, device_fault_ext);
};
template <>
struct feature< ktl::api::feature::device_fault_vendor_binary_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_fault_vendor_binary_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_fault_features_ext;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_fault_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_fault_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_fault_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fault_features_ext, device_fault_vendor_binary_ext);
};
template <>
struct feature< ktl::api::feature::device_fault_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_fault_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_fault_features_khr;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_fault_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_fault_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_fault_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fault_features_khr, device_fault_khr);
};
template <>
struct feature< ktl::api::feature::device_fault_vendor_binary_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_fault_vendor_binary_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_fault_features_khr;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_fault_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_fault_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_fault_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fault_features_khr, device_fault_vendor_binary_khr);
};
template <>
struct feature< ktl::api::feature::device_fault_report_masked_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_fault_report_masked_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_fault_features_khr;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_fault_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_fault_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_fault_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fault_features_khr, device_fault_report_masked_khr);
};
template <>
struct feature< ktl::api::feature::device_fault_device_lost_on_masked_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_fault_device_lost_on_masked_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_fault_features_khr;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_fault_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_fault_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_fault_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_fault_features_khr, device_fault_device_lost_on_masked_khr);
};
template <>
struct feature< ktl::api::feature::pipeline_library_group_handles_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_library_group_handles_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_pipeline_library_group_handles_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_pipeline_library_group_handles_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_pipeline_library_group_handles_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_pipeline_library_group_handles_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_pipeline_library_group_handles_features_ext, pipeline_library_group_handles_ext);
};
template <>
struct feature< ktl::api::feature::shader_core_builtins_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_core_builtins_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_core_builtins_features_arm;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_core_builtins_features_arm);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_core_builtins_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_core_builtins_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_core_builtins_features_arm, shader_core_builtins_arm);
};
template <>
struct feature< ktl::api::feature::frame_boundary_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::frame_boundary_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_frame_boundary_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_frame_boundary_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_frame_boundary_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_frame_boundary_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_frame_boundary_features_ext, frame_boundary_ext);
};
template <>
struct feature< ktl::api::feature::dynamic_rendering_unused_attachments_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::dynamic_rendering_unused_attachments_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_dynamic_rendering_unused_attachments_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_dynamic_rendering_unused_attachments_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_dynamic_rendering_unused_attachments_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_dynamic_rendering_unused_attachments_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_dynamic_rendering_unused_attachments_features_ext,
                 dynamic_rendering_unused_attachments_ext);
};
template <>
struct feature< ktl::api::feature::internally_synchronized_queues_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::internally_synchronized_queues_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_internally_synchronized_queues_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_internally_synchronized_queues_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_internally_synchronized_queues_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_internally_synchronized_queues_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_internally_synchronized_queues_features_khr, internally_synchronized_queues_khr);
};
template <>
struct feature< ktl::api::feature::swapchain_maintenance_1khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::swapchain_maintenance_1khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_swapchain_maintenance_1features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_swapchain_maintenance_1features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_swapchain_maintenance_1features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_swapchain_maintenance_1features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_swapchain_maintenance_1features_khr, swapchain_maintenance_1khr);
};
template <>
struct feature< ktl::api::feature::depth_bias_control_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::depth_bias_control_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_depth_bias_control_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_depth_bias_control_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_depth_bias_control_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_depth_bias_control_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_depth_bias_control_features_ext, depth_bias_control_ext);
};
template <>
struct feature< ktl::api::feature::least_representable_value_force_unorm_representation_ext >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::least_representable_value_force_unorm_representation_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_depth_bias_control_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_depth_bias_control_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_depth_bias_control_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_depth_bias_control_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_depth_bias_control_features_ext,
                                                          least_representable_value_force_unorm_representation_ext);
};
template <>
struct feature< ktl::api::feature::float_representation_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::float_representation_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_depth_bias_control_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_depth_bias_control_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_depth_bias_control_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_depth_bias_control_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_depth_bias_control_features_ext, float_representation_ext);
};
template <>
struct feature< ktl::api::feature::depth_bias_exact_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::depth_bias_exact_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_depth_bias_control_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_depth_bias_control_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_depth_bias_control_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_depth_bias_control_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_depth_bias_control_features_ext, depth_bias_exact_ext);
};
template <>
struct feature< ktl::api::feature::ray_tracing_invocation_reorder_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ray_tracing_invocation_reorder_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_invocation_reorder_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_ray_tracing_invocation_reorder_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_invocation_reorder_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_invocation_reorder_features_ext, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_ray_tracing_invocation_reorder_features_ext, ray_tracing_invocation_reorder_ext);
};
template <>
struct feature< ktl::api::feature::ray_tracing_invocation_reorder_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ray_tracing_invocation_reorder_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_invocation_reorder_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_ray_tracing_invocation_reorder_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_invocation_reorder_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_invocation_reorder_features_nv, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_ray_tracing_invocation_reorder_features_nv, ray_tracing_invocation_reorder_nv);
};
template <>
struct feature< ktl::api::feature::extended_sparse_address_space_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::extended_sparse_address_space_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_extended_sparse_address_space_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_extended_sparse_address_space_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_extended_sparse_address_space_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_extended_sparse_address_space_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_extended_sparse_address_space_features_nv, extended_sparse_address_space_nv);
};
template <>
struct feature< ktl::api::feature::multiview_per_view_viewports_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multiview_per_view_viewports_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_multiview_per_view_viewports_features_qcom;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_multiview_per_view_viewports_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_multiview_per_view_viewports_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_multiview_per_view_viewports_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_multiview_per_view_viewports_features_qcom, multiview_per_view_viewports_qcom);
};
template <>
struct feature< ktl::api::feature::ray_tracing_position_fetch_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ray_tracing_position_fetch_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ray_tracing_position_fetch_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_ray_tracing_position_fetch_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_ray_tracing_position_fetch_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_ray_tracing_position_fetch_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ray_tracing_position_fetch_features_khr, ray_tracing_position_fetch_khr);
};
template <>
struct feature< ktl::api::feature::multiview_per_view_render_areas_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::multiview_per_view_render_areas_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_multiview_per_view_render_areas_features_qcom;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_multiview_per_view_render_areas_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_multiview_per_view_render_areas_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_multiview_per_view_render_areas_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_multiview_per_view_render_areas_features_qcom, multiview_per_view_render_areas_qcom);
};
template <>
struct feature< ktl::api::feature::shader_object_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_object_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_object_features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_shader_object_features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_shader_object_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_shader_object_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_object_features_ext, shader_object_ext);
};
template <>
struct feature< ktl::api::feature::shader_tile_image_color_read_access_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_tile_image_color_read_access_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_tile_image_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_tile_image_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_tile_image_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_tile_image_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_tile_image_features_ext, shader_tile_image_color_read_access_ext);
};
template <>
struct feature< ktl::api::feature::shader_tile_image_depth_read_access_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_tile_image_depth_read_access_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_tile_image_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_tile_image_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_tile_image_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_tile_image_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_tile_image_features_ext, shader_tile_image_depth_read_access_ext);
};
template <>
struct feature< ktl::api::feature::shader_tile_image_stencil_read_access_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_tile_image_stencil_read_access_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_tile_image_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_tile_image_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_tile_image_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_tile_image_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_tile_image_features_ext, shader_tile_image_stencil_read_access_ext);
};
template <>
struct feature< ktl::api::feature::screen_buffer_import_qnx >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::screen_buffer_import_qnx;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_memory_screen_buffer_features_qnx;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_external_memory_screen_buffer_features_qnx);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_memory_screen_buffer_features_qnx, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_memory_screen_buffer_features_qnx, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_memory_screen_buffer_features_qnx, screen_buffer_import_qnx);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_matrix_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cooperative_matrix_features_khr, cooperative_matrix_khr);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_robust_buffer_access_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_robust_buffer_access_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_matrix_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_cooperative_matrix_features_khr,
                                                          cooperative_matrix_robust_buffer_access_khr);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_conversion_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_conversion_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_conversion_features_qcom;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_cooperative_matrix_conversion_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_conversion_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_conversion_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_cooperative_matrix_conversion_features_qcom, cooperative_matrix_conversion_qcom);
};
template <>
struct feature< ktl::api::feature::shader_enqueue_amdx >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_enqueue_amdx;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_enqueue_features_amdx;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_enqueue_features_amdx);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_enqueue_features_amdx, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_enqueue_features_amdx, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_enqueue_features_amdx, shader_enqueue_amdx);
};
template <>
struct feature< ktl::api::feature::shader_mesh_enqueue_amdx >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_mesh_enqueue_amdx;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_enqueue_features_amdx;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_enqueue_features_amdx);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_enqueue_features_amdx, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_enqueue_features_amdx, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_enqueue_features_amdx, shader_mesh_enqueue_amdx);
};
template <>
struct feature< ktl::api::feature::anti_lag_amd >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::anti_lag_amd;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_anti_lag_features_amd;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_anti_lag_features_amd);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_anti_lag_features_amd, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_anti_lag_features_amd, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_anti_lag_features_amd, anti_lag_amd);
};
template <>
struct feature< ktl::api::feature::tile_memory_heap_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_memory_heap_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_memory_heap_features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_tile_memory_heap_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_tile_memory_heap_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_tile_memory_heap_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_memory_heap_features_qcom, tile_memory_heap_qcom);
};
template <>
struct feature< ktl::api::feature::cubic_range_clamp_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cubic_range_clamp_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cubic_clamp_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_cubic_clamp_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_cubic_clamp_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_cubic_clamp_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cubic_clamp_features_qcom, cubic_range_clamp_qcom);
};
template <>
struct feature< ktl::api::feature::ycbcr_degamma_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::ycbcr_degamma_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_ycbcr_degamma_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_ycbcr_degamma_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_ycbcr_degamma_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_ycbcr_degamma_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_ycbcr_degamma_features_qcom, ycbcr_degamma_qcom);
};
template <>
struct feature< ktl::api::feature::selectable_cubic_weights_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::selectable_cubic_weights_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cubic_weights_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_cubic_weights_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_cubic_weights_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_cubic_weights_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cubic_weights_features_qcom, selectable_cubic_weights_qcom);
};
template <>
struct feature< ktl::api::feature::texture_block_match_2qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::texture_block_match_2qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_processing_2features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_processing_2features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_processing_2features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_processing_2features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_processing_2features_qcom, texture_block_match_2qcom);
};
template <>
struct feature< ktl::api::feature::image_gather_linear_3qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::image_gather_linear_3qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_processing_3features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_processing_3features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_processing_3features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_processing_3features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_processing_3features_qcom, image_gather_linear_3qcom);
};
template <>
struct feature< ktl::api::feature::image_gather_extended_modes_3qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::image_gather_extended_modes_3qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_processing_3features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_processing_3features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_processing_3features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_processing_3features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_processing_3features_qcom, image_gather_extended_modes_3qcom);
};
template <>
struct feature< ktl::api::feature::block_match_extended_clamp_to_edge_3qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::block_match_extended_clamp_to_edge_3qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_processing_3features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_processing_3features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_processing_3features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_processing_3features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_processing_3features_qcom, block_match_extended_clamp_to_edge_3qcom);
};
template <>
struct feature< ktl::api::feature::descriptor_pool_overallocation_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_pool_overallocation_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_pool_overallocation_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_descriptor_pool_overallocation_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_pool_overallocation_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_pool_overallocation_features_nv, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_descriptor_pool_overallocation_features_nv, descriptor_pool_overallocation_nv);
};
template <>
struct feature< ktl::api::feature::per_stage_descriptor_set_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::per_stage_descriptor_set_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_per_stage_descriptor_set_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_per_stage_descriptor_set_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_per_stage_descriptor_set_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_per_stage_descriptor_set_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_per_stage_descriptor_set_features_nv, per_stage_descriptor_set_nv);
};
template <>
struct feature< ktl::api::feature::dynamic_pipeline_layout_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::dynamic_pipeline_layout_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_per_stage_descriptor_set_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_per_stage_descriptor_set_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_per_stage_descriptor_set_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_per_stage_descriptor_set_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_per_stage_descriptor_set_features_nv, dynamic_pipeline_layout_nv);
};
template <>
struct feature< ktl::api::feature::external_format_resolve_android >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::external_format_resolve_android;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_external_format_resolve_features_android;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_external_format_resolve_features_android);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_external_format_resolve_features_android, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_external_format_resolve_features_android, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_external_format_resolve_features_android, external_format_resolve_android);
};
template <>
struct feature< ktl::api::feature::cuda_kernel_launch_features_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cuda_kernel_launch_features_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cuda_kernel_launch_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cuda_kernel_launch_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cuda_kernel_launch_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cuda_kernel_launch_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cuda_kernel_launch_features_nv, cuda_kernel_launch_features_nv);
};
template <>
struct feature< ktl::api::feature::scheduling_controls_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::scheduling_controls_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_scheduling_controls_features_arm;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_scheduling_controls_features_arm);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_scheduling_controls_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_scheduling_controls_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_scheduling_controls_features_arm, scheduling_controls_arm);
};
template <>
struct feature< ktl::api::feature::relaxed_line_rasterization_img >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::relaxed_line_rasterization_img;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_relaxed_line_rasterization_features_img;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_relaxed_line_rasterization_features_img);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_relaxed_line_rasterization_features_img, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_relaxed_line_rasterization_features_img, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_relaxed_line_rasterization_features_img, relaxed_line_rasterization_img);
};
template <>
struct feature< ktl::api::feature::render_pass_striped_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::render_pass_striped_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_render_pass_striped_features_arm;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_render_pass_striped_features_arm);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_render_pass_striped_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_render_pass_striped_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_render_pass_striped_features_arm, render_pass_striped_arm);
};
template <>
struct feature< ktl::api::feature::pipeline_opacity_micromap_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_opacity_micromap_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_pipeline_opacity_micromap_features_arm;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_pipeline_opacity_micromap_features_arm);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_pipeline_opacity_micromap_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_pipeline_opacity_micromap_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_pipeline_opacity_micromap_features_arm, pipeline_opacity_micromap_arm);
};
template <>
struct feature< ktl::api::feature::shader_maximal_reconvergence_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_maximal_reconvergence_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_maximal_reconvergence_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_maximal_reconvergence_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_maximal_reconvergence_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_maximal_reconvergence_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_maximal_reconvergence_features_khr, shader_maximal_reconvergence_khr);
};
template <>
struct feature< ktl::api::feature::shader_subgroup_rotate >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_subgroup_rotate;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_subgroup_rotate_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_subgroup_rotate_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_subgroup_rotate_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_subgroup_rotate_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_subgroup_rotate_features, shader_subgroup_rotate);
};
template <>
struct feature< ktl::api::feature::shader_subgroup_rotate_clustered >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_subgroup_rotate_clustered;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_subgroup_rotate_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_subgroup_rotate_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_subgroup_rotate_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_subgroup_rotate_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_subgroup_rotate_features, shader_subgroup_rotate_clustered);
};
template <>
struct feature< ktl::api::feature::shader_expect_assume >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_expect_assume;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_expect_assume_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_expect_assume_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_expect_assume_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_expect_assume_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_expect_assume_features, shader_expect_assume);
};
template <>
struct feature< ktl::api::feature::shader_float_controls_2 >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_float_controls_2;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_float_controls_2features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_float_controls_2features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_float_controls_2features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_float_controls_2features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_float_controls_2features, shader_float_controls_2);
};
template <>
struct feature< ktl::api::feature::dynamic_rendering_local_read >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::dynamic_rendering_local_read;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_dynamic_rendering_local_read_features;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_dynamic_rendering_local_read_features);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_dynamic_rendering_local_read_features, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_dynamic_rendering_local_read_features, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_dynamic_rendering_local_read_features, dynamic_rendering_local_read);
};
template <>
struct feature< ktl::api::feature::shader_quad_control_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_quad_control_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_quad_control_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_quad_control_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_quad_control_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_quad_control_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_quad_control_features_khr, shader_quad_control_khr);
};
template <>
struct feature< ktl::api::feature::shader_float_16vector_atomics_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_float_16vector_atomics_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_atomic_float_16vector_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_atomic_float_16vector_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_atomic_float_16vector_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_atomic_float_16vector_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_atomic_float_16vector_features_nv, shader_float_16vector_atomics_nv);
};
template <>
struct feature< ktl::api::feature::memory_map_placed_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::memory_map_placed_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_map_memory_placed_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_map_memory_placed_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_map_memory_placed_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_map_memory_placed_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_map_memory_placed_features_ext, memory_map_placed_ext);
};
template <>
struct feature< ktl::api::feature::memory_map_range_placed_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::memory_map_range_placed_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_map_memory_placed_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_map_memory_placed_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_map_memory_placed_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_map_memory_placed_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_map_memory_placed_features_ext, memory_map_range_placed_ext);
};
template <>
struct feature< ktl::api::feature::memory_unmap_reserve_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::memory_unmap_reserve_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_map_memory_placed_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_map_memory_placed_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_map_memory_placed_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_map_memory_placed_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_map_memory_placed_features_ext, memory_unmap_reserve_ext);
};
template <>
struct feature< ktl::api::feature::shader_b_float_16type_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_b_float_16type_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_bfloat_16features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_bfloat_16features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_bfloat_16features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_bfloat_16features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_bfloat_16features_khr, shader_b_float_16type_khr);
};
template <>
struct feature< ktl::api::feature::shader_b_float_16dot_product_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_b_float_16dot_product_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_bfloat_16features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_bfloat_16features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_bfloat_16features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_bfloat_16features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_bfloat_16features_khr, shader_b_float_16dot_product_khr);
};
template <>
struct feature< ktl::api::feature::shader_b_float_16cooperative_matrix_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_b_float_16cooperative_matrix_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_bfloat_16features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_bfloat_16features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_bfloat_16features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_bfloat_16features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_bfloat_16features_khr, shader_b_float_16cooperative_matrix_khr);
};
template <>
struct feature< ktl::api::feature::shader_raw_access_chains_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_raw_access_chains_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_raw_access_chains_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_raw_access_chains_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_raw_access_chains_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_raw_access_chains_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_raw_access_chains_features_nv, shader_raw_access_chains_nv);
};
template <>
struct feature< ktl::api::feature::command_buffer_inheritance_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::command_buffer_inheritance_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_command_buffer_inheritance_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_command_buffer_inheritance_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_command_buffer_inheritance_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_command_buffer_inheritance_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_command_buffer_inheritance_features_nv, command_buffer_inheritance_nv);
};
template <>
struct feature< ktl::api::feature::image_alignment_control_mesa >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::image_alignment_control_mesa;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_image_alignment_control_features_mesa;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_image_alignment_control_features_mesa);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_image_alignment_control_features_mesa, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_image_alignment_control_features_mesa, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_image_alignment_control_features_mesa, image_alignment_control_mesa);
};
template <>
struct feature< ktl::api::feature::shader_replicated_composites_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_replicated_composites_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_replicated_composites_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_replicated_composites_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_replicated_composites_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_replicated_composites_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_replicated_composites_features_ext, shader_replicated_composites_ext);
};
template <>
struct feature< ktl::api::feature::present_mode_fifo_latest_ready_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::present_mode_fifo_latest_ready_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_present_mode_fifo_latest_ready_features_khr;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_present_mode_fifo_latest_ready_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_present_mode_fifo_latest_ready_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_present_mode_fifo_latest_ready_features_khr, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_present_mode_fifo_latest_ready_features_khr, present_mode_fifo_latest_ready_khr);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_workgroup_scope_2nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_workgroup_scope_2nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_2features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_matrix_2features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, cooperative_matrix_workgroup_scope_2nv);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_flexible_dimensions_2nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_flexible_dimensions_2nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_2features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_matrix_2features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, cooperative_matrix_flexible_dimensions_2nv);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_reductions_2nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_reductions_2nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_2features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_matrix_2features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, cooperative_matrix_reductions_2nv);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_conversions_2nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_conversions_2nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_2features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_matrix_2features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, cooperative_matrix_conversions_2nv);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_per_element_operations_2nv >
{
    static constexpr ktl::api::feature        value = ktl::api::feature::cooperative_matrix_per_element_operations_2nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_2features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_matrix_2features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv,
                                                          cooperative_matrix_per_element_operations_2nv);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_tensor_addressing_2nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_tensor_addressing_2nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_2features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_matrix_2features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, cooperative_matrix_tensor_addressing_2nv);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_block_loads_2nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_block_loads_2nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_2features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_matrix_2features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cooperative_matrix_2features_nv, cooperative_matrix_block_loads_2nv);
};
template <>
struct feature< ktl::api::feature::cooperative_matrix_decode_vector_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_matrix_decode_vector_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_matrix_decode_vector_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_cooperative_matrix_decode_vector_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_matrix_decode_vector_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_matrix_decode_vector_features_nv, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_cooperative_matrix_decode_vector_features_nv, cooperative_matrix_decode_vector_nv);
};
template <>
struct feature< ktl::api::feature::hdr_vivid_huawei >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::hdr_vivid_huawei;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_hdr_vivid_features_huawei;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_hdr_vivid_features_huawei);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_hdr_vivid_features_huawei, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_hdr_vivid_features_huawei, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_hdr_vivid_features_huawei, hdr_vivid_huawei);
};
template <>
struct feature< ktl::api::feature::vertex_attribute_robustness_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::vertex_attribute_robustness_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_vertex_attribute_robustness_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_vertex_attribute_robustness_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_vertex_attribute_robustness_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_vertex_attribute_robustness_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_vertex_attribute_robustness_features_ext, vertex_attribute_robustness_ext);
};
template <>
struct feature< ktl::api::feature::dense_geometry_format_amdx >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::dense_geometry_format_amdx;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_dense_geometry_format_features_amdx;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_dense_geometry_format_features_amdx);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_dense_geometry_format_features_amdx, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_dense_geometry_format_features_amdx, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_dense_geometry_format_features_amdx, dense_geometry_format_amdx);
};
template <>
struct feature< ktl::api::feature::depth_clamp_zero_one_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::depth_clamp_zero_one_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_depth_clamp_zero_one_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_depth_clamp_zero_one_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_depth_clamp_zero_one_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_depth_clamp_zero_one_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_depth_clamp_zero_one_features_khr, depth_clamp_zero_one_khr);
};
template <>
struct feature< ktl::api::feature::cooperative_vector_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_vector_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_vector_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_vector_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_vector_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_vector_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cooperative_vector_features_nv, cooperative_vector_nv);
};
template <>
struct feature< ktl::api::feature::cooperative_vector_training_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::cooperative_vector_training_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_cooperative_vector_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_cooperative_vector_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_cooperative_vector_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_cooperative_vector_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_cooperative_vector_features_nv, cooperative_vector_training_nv);
};
template <>
struct feature< ktl::api::feature::tile_shading_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_fragment_stage_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_fragment_stage_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_fragment_stage_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_color_attachments_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_color_attachments_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_color_attachments_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_depth_attachments_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_depth_attachments_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_depth_attachments_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_stencil_attachments_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_stencil_attachments_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_stencil_attachments_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_input_attachments_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_input_attachments_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_input_attachments_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_sampled_attachments_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_sampled_attachments_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_sampled_attachments_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_per_tile_draw_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_per_tile_draw_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_per_tile_draw_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_per_tile_dispatch_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_per_tile_dispatch_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_per_tile_dispatch_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_dispatch_tile_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_dispatch_tile_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_dispatch_tile_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_apron_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_apron_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_apron_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_anisotropic_apron_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_anisotropic_apron_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_anisotropic_apron_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_atomic_ops_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_atomic_ops_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_atomic_ops_qcom);
};
template <>
struct feature< ktl::api::feature::tile_shading_image_processing_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tile_shading_image_processing_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_tile_shading_features_qcom;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_tile_shading_features_qcom);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tile_shading_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tile_shading_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tile_shading_features_qcom, tile_shading_image_processing_qcom);
};
template <>
struct feature< ktl::api::feature::fragment_density_map_layered_valve >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::fragment_density_map_layered_valve;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_fragment_density_map_layered_features_valve;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_fragment_density_map_layered_features_valve);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_fragment_density_map_layered_features_valve, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_fragment_density_map_layered_features_valve, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_fragment_density_map_layered_features_valve, fragment_density_map_layered_valve);
};
template <>
struct feature< ktl::api::feature::present_metering_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::present_metering_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_present_metering_features_nv;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_present_metering_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_present_metering_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_present_metering_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_present_metering_features_nv, present_metering_nv);
};
template <>
struct feature< ktl::api::feature::shader_uniform_buffer_unsized_array_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_uniform_buffer_unsized_array_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_uniform_buffer_unsized_array_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_uniform_buffer_unsized_array_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_uniform_buffer_unsized_array_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_uniform_buffer_unsized_array_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_uniform_buffer_unsized_array_features_ext,
                 shader_uniform_buffer_unsized_array_ext);
};
template <>
struct feature< ktl::api::feature::shader_mixed_float_dot_product_float_16acc_float_32valve >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::shader_mixed_float_dot_product_float_16acc_float_32valve;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_mixed_float_dot_product_features_valve;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve,
                 shader_mixed_float_dot_product_float_16acc_float_32valve);
};
template <>
struct feature< ktl::api::feature::shader_mixed_float_dot_product_float_16acc_float_16valve >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::shader_mixed_float_dot_product_float_16acc_float_16valve;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_mixed_float_dot_product_features_valve;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve,
                 shader_mixed_float_dot_product_float_16acc_float_16valve);
};
template <>
struct feature< ktl::api::feature::shader_mixed_float_dot_product_b_float_16acc_valve >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_mixed_float_dot_product_b_float_16acc_valve;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_mixed_float_dot_product_features_valve;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve,
                 shader_mixed_float_dot_product_b_float_16acc_valve);
};
template <>
struct feature< ktl::api::feature::shader_mixed_float_dot_product_float_8acc_float_32valve >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::shader_mixed_float_dot_product_float_8acc_float_32valve;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_mixed_float_dot_product_features_valve;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_mixed_float_dot_product_features_valve,
                 shader_mixed_float_dot_product_float_8acc_float_32valve);
};
template <>
struct feature< ktl::api::feature::primitive_restart_index_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::primitive_restart_index_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_primitive_restart_index_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_primitive_restart_index_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_primitive_restart_index_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_primitive_restart_index_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_primitive_restart_index_features_ext, primitive_restart_index_ext);
};
template <>
struct feature< ktl::api::feature::format_pack_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::format_pack_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_format_pack_features_arm;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_format_pack_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_format_pack_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_format_pack_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_format_pack_features_arm, format_pack_arm);
};
template <>
struct feature< ktl::api::feature::throttle_hint_sec >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::throttle_hint_sec;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_throttle_hint_features_sec;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_throttle_hint_features_sec);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_throttle_hint_features_sec, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_throttle_hint_features_sec, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_throttle_hint_features_sec, throttle_hint_sec);
};
template <>
struct feature< ktl::api::feature::tensor_non_packed_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tensor_non_packed_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_tensor_features_arm;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_tensor_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tensor_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tensor_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tensor_features_arm, tensor_non_packed_arm);
};
template <>
struct feature< ktl::api::feature::shader_tensor_access_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_tensor_access_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_tensor_features_arm;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_tensor_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tensor_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tensor_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tensor_features_arm, shader_tensor_access_arm);
};
template <>
struct feature< ktl::api::feature::shader_storage_tensor_array_dynamic_indexing_arm >
{
    static constexpr ktl::api::feature value   = ktl::api::feature::shader_storage_tensor_array_dynamic_indexing_arm;
    static constexpr bool              is_core = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_tensor_features_arm;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_tensor_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tensor_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tensor_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tensor_features_arm, shader_storage_tensor_array_dynamic_indexing_arm);
};
template <>
struct feature< ktl::api::feature::shader_storage_tensor_array_non_uniform_indexing_arm >
{
    static constexpr ktl::api::feature value = ktl::api::feature::shader_storage_tensor_array_non_uniform_indexing_arm;
    static constexpr bool              is_core      = false;
    static constexpr ktl::api::structure_type stype = ktl::api::structure_type::v_physical_device_tensor_features_arm;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_tensor_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tensor_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tensor_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_tensor_features_arm, shader_storage_tensor_array_non_uniform_indexing_arm);
};
template <>
struct feature< ktl::api::feature::descriptor_binding_storage_tensor_update_after_bind_arm >
{
    static constexpr ktl::api::feature value =
        ktl::api::feature::descriptor_binding_storage_tensor_update_after_bind_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_tensor_features_arm;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_tensor_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tensor_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tensor_features_arm, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_tensor_features_arm,
                                                          descriptor_binding_storage_tensor_update_after_bind_arm);
};
template <>
struct feature< ktl::api::feature::tensors_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::tensors_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype   = ktl::api::structure_type::v_physical_device_tensor_features_arm;
    static constexpr ktl::usize               sizeof_struct = sizeof(ktl::api::physical_device_tensor_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_tensor_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_tensor_features_arm, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(ktl::api::physical_device_tensor_features_arm, tensors_arm);
};
template <>
struct feature< ktl::api::feature::descriptor_buffer_tensor_descriptors_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_buffer_tensor_descriptors_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_buffer_tensor_features_arm;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_buffer_tensor_features_arm);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_buffer_tensor_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_buffer_tensor_features_arm, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_descriptor_buffer_tensor_features_arm, descriptor_buffer_tensor_descriptors_arm);
};
template <>
struct feature< ktl::api::feature::shader_float_8ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_float_8ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_float_8features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_shader_float_8features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_shader_float_8features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_shader_float_8features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_float_8features_ext, shader_float_8ext);
};
template <>
struct feature< ktl::api::feature::shader_float_8cooperative_matrix_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_float_8cooperative_matrix_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_float_8features_ext;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_shader_float_8features_ext);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_shader_float_8features_ext, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_shader_float_8features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_float_8features_ext, shader_float_8cooperative_matrix_ext);
};
template <>
struct feature< ktl::api::feature::data_graph_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::data_graph_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_data_graph_features_arm;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_data_graph_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_data_graph_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_data_graph_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_data_graph_features_arm, data_graph_arm);
};
template <>
struct feature< ktl::api::feature::data_graph_update_after_bind_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::data_graph_update_after_bind_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_data_graph_features_arm;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_data_graph_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_data_graph_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_data_graph_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_data_graph_features_arm, data_graph_update_after_bind_arm);
};
template <>
struct feature< ktl::api::feature::data_graph_specialization_constants_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::data_graph_specialization_constants_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_data_graph_features_arm;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_data_graph_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_data_graph_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_data_graph_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_data_graph_features_arm, data_graph_specialization_constants_arm);
};
template <>
struct feature< ktl::api::feature::data_graph_descriptor_buffer_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::data_graph_descriptor_buffer_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_data_graph_features_arm;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_data_graph_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_data_graph_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_data_graph_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_data_graph_features_arm, data_graph_descriptor_buffer_arm);
};
template <>
struct feature< ktl::api::feature::data_graph_shader_module_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::data_graph_shader_module_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_data_graph_features_arm;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_data_graph_features_arm);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_data_graph_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_data_graph_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_data_graph_features_arm, data_graph_shader_module_arm);
};
template <>
struct feature< ktl::api::feature::pipeline_cache_incremental_mode_sec >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::pipeline_cache_incremental_mode_sec;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_pipeline_cache_incremental_mode_features_sec;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_pipeline_cache_incremental_mode_features_sec);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_pipeline_cache_incremental_mode_features_sec, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_pipeline_cache_incremental_mode_features_sec, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_pipeline_cache_incremental_mode_features_sec, pipeline_cache_incremental_mode_sec);
};
template <>
struct feature< ktl::api::feature::data_graph_model_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::data_graph_model_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_data_graph_model_features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_data_graph_model_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_data_graph_model_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_data_graph_model_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_data_graph_model_features_qcom, data_graph_model_qcom);
};
template <>
struct feature< ktl::api::feature::shader_untyped_pointers_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_untyped_pointers_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_untyped_pointers_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_untyped_pointers_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_untyped_pointers_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_untyped_pointers_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_untyped_pointers_features_khr, shader_untyped_pointers_khr);
};
template <>
struct feature< ktl::api::feature::shader_64bit_indexing_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_64bit_indexing_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_64bit_indexing_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_64bit_indexing_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_64bit_indexing_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_64bit_indexing_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_64bit_indexing_features_ext, shader_64bit_indexing_ext);
};
template <>
struct feature< ktl::api::feature::queue_perf_hint_qcom >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::queue_perf_hint_qcom;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_queue_perf_hint_features_qcom;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_queue_perf_hint_features_qcom);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_queue_perf_hint_features_qcom, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_queue_perf_hint_features_qcom, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_queue_perf_hint_features_qcom, queue_perf_hint_qcom);
};
template <>
struct feature< ktl::api::feature::performance_counters_by_region_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::performance_counters_by_region_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_performance_counters_by_region_features_arm;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_performance_counters_by_region_features_arm);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_performance_counters_by_region_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_performance_counters_by_region_features_arm, pnext);
    static constexpr ktl::usize offsetof_field = offsetof(
        ktl::api::physical_device_performance_counters_by_region_features_arm, performance_counters_by_region_arm);
};
template <>
struct feature< ktl::api::feature::compute_occupancy_priority_nv >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::compute_occupancy_priority_nv;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_compute_occupancy_priority_features_nv;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_compute_occupancy_priority_features_nv);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_compute_occupancy_priority_features_nv, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_compute_occupancy_priority_features_nv, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_compute_occupancy_priority_features_nv, compute_occupancy_priority_nv);
};
template <>
struct feature< ktl::api::feature::long_vector_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::long_vector_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_long_vector_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_long_vector_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_long_vector_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_long_vector_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_long_vector_features_ext, long_vector_ext);
};
template <>
struct feature< ktl::api::feature::texture_compression_astc_3d_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::texture_compression_astc_3d_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_texture_compression_astc_3d_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_texture_compression_astc_3d_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_texture_compression_astc_3d_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_texture_compression_astc_3d_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_texture_compression_astc_3d_features_ext, texture_compression_astc_3d_ext);
};
template <>
struct feature< ktl::api::feature::shader_subgroup_partitioned_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_subgroup_partitioned_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_subgroup_partitioned_features_ext;
    static constexpr ktl::usize sizeof_struct =
        sizeof(ktl::api::physical_device_shader_subgroup_partitioned_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_subgroup_partitioned_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_subgroup_partitioned_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_subgroup_partitioned_features_ext, shader_subgroup_partitioned_ext);
};
template <>
struct feature< ktl::api::feature::shader_split_barrier_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_split_barrier_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_split_barrier_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_split_barrier_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_split_barrier_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_split_barrier_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_split_barrier_features_ext, shader_split_barrier_ext);
};
template <>
struct feature< ktl::api::feature::descriptor_heap_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_heap_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_heap_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_heap_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_heap_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_heap_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_descriptor_heap_features_ext, descriptor_heap_ext);
};
template <>
struct feature< ktl::api::feature::descriptor_heap_capture_replay_ext >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::descriptor_heap_capture_replay_ext;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_descriptor_heap_features_ext;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_descriptor_heap_features_ext);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_descriptor_heap_features_ext, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_descriptor_heap_features_ext, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_descriptor_heap_features_ext, descriptor_heap_capture_replay_ext);
};
template <>
struct feature< ktl::api::feature::shader_instrumentation_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_instrumentation_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_instrumentation_features_arm;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_instrumentation_features_arm);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_instrumentation_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_instrumentation_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_instrumentation_features_arm, shader_instrumentation_arm);
};
template <>
struct feature< ktl::api::feature::device_address_commands_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::device_address_commands_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_device_address_commands_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_device_address_commands_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_device_address_commands_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_device_address_commands_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_device_address_commands_features_khr, device_address_commands_khr);
};
template <>
struct feature< ktl::api::feature::shader_constant_data_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_constant_data_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_constant_data_features_khr;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_shader_constant_data_features_khr);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_shader_constant_data_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_shader_constant_data_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_constant_data_features_khr, shader_constant_data_khr);
};
template <>
struct feature< ktl::api::feature::shader_abort_khr >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::shader_abort_khr;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_shader_abort_features_khr;
    static constexpr ktl::usize sizeof_struct  = sizeof(ktl::api::physical_device_shader_abort_features_khr);
    static constexpr ktl::usize offsetof_stype = offsetof(ktl::api::physical_device_shader_abort_features_khr, stype);
    static constexpr ktl::usize offsetof_pnext = offsetof(ktl::api::physical_device_shader_abort_features_khr, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_shader_abort_features_khr, shader_abort_khr);
};
template <>
struct feature< ktl::api::feature::data_graph_optical_flow_arm >
{
    static constexpr ktl::api::feature        value   = ktl::api::feature::data_graph_optical_flow_arm;
    static constexpr bool                     is_core = false;
    static constexpr ktl::api::structure_type stype =
        ktl::api::structure_type::v_physical_device_data_graph_optical_flow_features_arm;
    static constexpr ktl::usize sizeof_struct = sizeof(ktl::api::physical_device_data_graph_optical_flow_features_arm);
    static constexpr ktl::usize offsetof_stype =
        offsetof(ktl::api::physical_device_data_graph_optical_flow_features_arm, stype);
    static constexpr ktl::usize offsetof_pnext =
        offsetof(ktl::api::physical_device_data_graph_optical_flow_features_arm, pnext);
    static constexpr ktl::usize offsetof_field =
        offsetof(ktl::api::physical_device_data_graph_optical_flow_features_arm, data_graph_optical_flow_arm);
};
template < ktl::api::feature FEATURE >
constexpr any_feature
feature_cast() noexcept
{
    using feature = ktl::meta::feature< FEATURE >;
    return {feature::value,          feature::is_core,        feature::stype,         feature::sizeof_struct,
            feature::offsetof_stype, feature::offsetof_pnext, feature::offsetof_field};
}

inline any_feature
match(ktl::api::feature _feature) noexcept
{
    switch (_feature)
    {
    case ktl::api::feature::robust_buffer_access:
        return ktl::meta::feature_cast< ktl::api::feature::robust_buffer_access >();
    case ktl::api::feature::full_draw_index_uint_32:
        return ktl::meta::feature_cast< ktl::api::feature::full_draw_index_uint_32 >();
    case ktl::api::feature::image_cube_array:
        return ktl::meta::feature_cast< ktl::api::feature::image_cube_array >();
    case ktl::api::feature::independent_blend:
        return ktl::meta::feature_cast< ktl::api::feature::independent_blend >();
    case ktl::api::feature::geometry_shader:
        return ktl::meta::feature_cast< ktl::api::feature::geometry_shader >();
    case ktl::api::feature::tessellation_shader:
        return ktl::meta::feature_cast< ktl::api::feature::tessellation_shader >();
    case ktl::api::feature::sample_rate_shading:
        return ktl::meta::feature_cast< ktl::api::feature::sample_rate_shading >();
    case ktl::api::feature::dual_src_blend:
        return ktl::meta::feature_cast< ktl::api::feature::dual_src_blend >();
    case ktl::api::feature::logic_op:
        return ktl::meta::feature_cast< ktl::api::feature::logic_op >();
    case ktl::api::feature::multi_draw_indirect:
        return ktl::meta::feature_cast< ktl::api::feature::multi_draw_indirect >();
    case ktl::api::feature::draw_indirect_first_instance:
        return ktl::meta::feature_cast< ktl::api::feature::draw_indirect_first_instance >();
    case ktl::api::feature::depth_clamp:
        return ktl::meta::feature_cast< ktl::api::feature::depth_clamp >();
    case ktl::api::feature::depth_bias_clamp:
        return ktl::meta::feature_cast< ktl::api::feature::depth_bias_clamp >();
    case ktl::api::feature::fill_mode_non_solid:
        return ktl::meta::feature_cast< ktl::api::feature::fill_mode_non_solid >();
    case ktl::api::feature::depth_bounds:
        return ktl::meta::feature_cast< ktl::api::feature::depth_bounds >();
    case ktl::api::feature::wide_lines:
        return ktl::meta::feature_cast< ktl::api::feature::wide_lines >();
    case ktl::api::feature::large_points:
        return ktl::meta::feature_cast< ktl::api::feature::large_points >();
    case ktl::api::feature::alpha_to_one:
        return ktl::meta::feature_cast< ktl::api::feature::alpha_to_one >();
    case ktl::api::feature::multi_viewport:
        return ktl::meta::feature_cast< ktl::api::feature::multi_viewport >();
    case ktl::api::feature::sampler_anisotropy:
        return ktl::meta::feature_cast< ktl::api::feature::sampler_anisotropy >();
    case ktl::api::feature::texture_compression_etc_2:
        return ktl::meta::feature_cast< ktl::api::feature::texture_compression_etc_2 >();
    case ktl::api::feature::texture_compression_astc_ldr:
        return ktl::meta::feature_cast< ktl::api::feature::texture_compression_astc_ldr >();
    case ktl::api::feature::texture_compression_bc:
        return ktl::meta::feature_cast< ktl::api::feature::texture_compression_bc >();
    case ktl::api::feature::occlusion_query_precise:
        return ktl::meta::feature_cast< ktl::api::feature::occlusion_query_precise >();
    case ktl::api::feature::pipeline_statistics_query:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_statistics_query >();
    case ktl::api::feature::vertex_pipeline_stores_and_atomics:
        return ktl::meta::feature_cast< ktl::api::feature::vertex_pipeline_stores_and_atomics >();
    case ktl::api::feature::fragment_stores_and_atomics:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_stores_and_atomics >();
    case ktl::api::feature::shader_tessellation_and_geometry_point_size:
        return ktl::meta::feature_cast< ktl::api::feature::shader_tessellation_and_geometry_point_size >();
    case ktl::api::feature::shader_image_gather_extended:
        return ktl::meta::feature_cast< ktl::api::feature::shader_image_gather_extended >();
    case ktl::api::feature::shader_storage_image_extended_formats:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_image_extended_formats >();
    case ktl::api::feature::shader_storage_image_multisample:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_image_multisample >();
    case ktl::api::feature::shader_storage_image_read_without_format:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_image_read_without_format >();
    case ktl::api::feature::shader_storage_image_write_without_format:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_image_write_without_format >();
    case ktl::api::feature::shader_uniform_buffer_array_dynamic_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_uniform_buffer_array_dynamic_indexing >();
    case ktl::api::feature::shader_sampled_image_array_dynamic_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_sampled_image_array_dynamic_indexing >();
    case ktl::api::feature::shader_storage_buffer_array_dynamic_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_buffer_array_dynamic_indexing >();
    case ktl::api::feature::shader_storage_image_array_dynamic_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_image_array_dynamic_indexing >();
    case ktl::api::feature::shader_clip_distance:
        return ktl::meta::feature_cast< ktl::api::feature::shader_clip_distance >();
    case ktl::api::feature::shader_cull_distance:
        return ktl::meta::feature_cast< ktl::api::feature::shader_cull_distance >();
    case ktl::api::feature::shader_float_64:
        return ktl::meta::feature_cast< ktl::api::feature::shader_float_64 >();
    case ktl::api::feature::shader_int_64:
        return ktl::meta::feature_cast< ktl::api::feature::shader_int_64 >();
    case ktl::api::feature::shader_int_16:
        return ktl::meta::feature_cast< ktl::api::feature::shader_int_16 >();
    case ktl::api::feature::shader_resource_residency:
        return ktl::meta::feature_cast< ktl::api::feature::shader_resource_residency >();
    case ktl::api::feature::shader_resource_min_lod:
        return ktl::meta::feature_cast< ktl::api::feature::shader_resource_min_lod >();
    case ktl::api::feature::sparse_binding:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_binding >();
    case ktl::api::feature::sparse_residency_buffer:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_residency_buffer >();
    case ktl::api::feature::sparse_residency_image_2d:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_residency_image_2d >();
    case ktl::api::feature::sparse_residency_image_3d:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_residency_image_3d >();
    case ktl::api::feature::sparse_residency_2samples:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_residency_2samples >();
    case ktl::api::feature::sparse_residency_4samples:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_residency_4samples >();
    case ktl::api::feature::sparse_residency_8samples:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_residency_8samples >();
    case ktl::api::feature::sparse_residency_16samples:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_residency_16samples >();
    case ktl::api::feature::sparse_residency_aliased:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_residency_aliased >();
    case ktl::api::feature::variable_multisample_rate:
        return ktl::meta::feature_cast< ktl::api::feature::variable_multisample_rate >();
    case ktl::api::feature::inherited_queries:
        return ktl::meta::feature_cast< ktl::api::feature::inherited_queries >();
    case ktl::api::feature::sci_buf_import_nv:
        return ktl::meta::feature_cast< ktl::api::feature::sci_buf_import_nv >();
    case ktl::api::feature::sci_buf_export_nv:
        return ktl::meta::feature_cast< ktl::api::feature::sci_buf_export_nv >();
    case ktl::api::feature::device_generated_commands_nv:
        return ktl::meta::feature_cast< ktl::api::feature::device_generated_commands_nv >();
    case ktl::api::feature::push_constant_bank_nv:
        return ktl::meta::feature_cast< ktl::api::feature::push_constant_bank_nv >();
    case ktl::api::feature::device_generated_compute_nv:
        return ktl::meta::feature_cast< ktl::api::feature::device_generated_compute_nv >();
    case ktl::api::feature::device_generated_compute_pipelines_nv:
        return ktl::meta::feature_cast< ktl::api::feature::device_generated_compute_pipelines_nv >();
    case ktl::api::feature::device_generated_compute_capture_replay_nv:
        return ktl::meta::feature_cast< ktl::api::feature::device_generated_compute_capture_replay_nv >();
    case ktl::api::feature::private_data:
        return ktl::meta::feature_cast< ktl::api::feature::private_data >();
    case ktl::api::feature::cluster_acceleration_structure_nv:
        return ktl::meta::feature_cast< ktl::api::feature::cluster_acceleration_structure_nv >();
    case ktl::api::feature::variable_pointers_storage_buffer:
        return ktl::meta::feature_cast< ktl::api::feature::variable_pointers_storage_buffer >();
    case ktl::api::feature::variable_pointers:
        return ktl::meta::feature_cast< ktl::api::feature::variable_pointers >();
    case ktl::api::feature::sci_sync_fence_nv:
        return ktl::meta::feature_cast< ktl::api::feature::sci_sync_fence_nv >();
    case ktl::api::feature::sci_sync_semaphore_nv:
        return ktl::meta::feature_cast< ktl::api::feature::sci_sync_semaphore_nv >();
    case ktl::api::feature::sci_sync_import_nv:
        return ktl::meta::feature_cast< ktl::api::feature::sci_sync_import_nv >();
    case ktl::api::feature::sci_sync_export_nv:
        return ktl::meta::feature_cast< ktl::api::feature::sci_sync_export_nv >();
    case ktl::api::feature::sci_sync_fence_2nv:
        return ktl::meta::feature_cast< ktl::api::feature::sci_sync_fence_2nv >();
    case ktl::api::feature::sci_sync_semaphore_2nv:
        return ktl::meta::feature_cast< ktl::api::feature::sci_sync_semaphore_2nv >();
    case ktl::api::feature::sci_sync_import_2nv:
        return ktl::meta::feature_cast< ktl::api::feature::sci_sync_import_2nv >();
    case ktl::api::feature::sci_sync_export_2nv:
        return ktl::meta::feature_cast< ktl::api::feature::sci_sync_export_2nv >();
    case ktl::api::feature::multiview:
        return ktl::meta::feature_cast< ktl::api::feature::multiview >();
    case ktl::api::feature::multiview_geometry_shader:
        return ktl::meta::feature_cast< ktl::api::feature::multiview_geometry_shader >();
    case ktl::api::feature::multiview_tessellation_shader:
        return ktl::meta::feature_cast< ktl::api::feature::multiview_tessellation_shader >();
    case ktl::api::feature::present_id_khr:
        return ktl::meta::feature_cast< ktl::api::feature::present_id_khr >();
    case ktl::api::feature::present_id_2khr:
        return ktl::meta::feature_cast< ktl::api::feature::present_id_2khr >();
    case ktl::api::feature::present_wait_khr:
        return ktl::meta::feature_cast< ktl::api::feature::present_wait_khr >();
    case ktl::api::feature::present_wait_2khr:
        return ktl::meta::feature_cast< ktl::api::feature::present_wait_2khr >();
    case ktl::api::feature::present_timing_ext:
        return ktl::meta::feature_cast< ktl::api::feature::present_timing_ext >();
    case ktl::api::feature::present_at_absolute_time_ext:
        return ktl::meta::feature_cast< ktl::api::feature::present_at_absolute_time_ext >();
    case ktl::api::feature::present_at_relative_time_ext:
        return ktl::meta::feature_cast< ktl::api::feature::present_at_relative_time_ext >();
    case ktl::api::feature::storage_buffer_16bit_access:
        return ktl::meta::feature_cast< ktl::api::feature::storage_buffer_16bit_access >();
    case ktl::api::feature::uniform_and_storage_buffer_16bit_access:
        return ktl::meta::feature_cast< ktl::api::feature::uniform_and_storage_buffer_16bit_access >();
    case ktl::api::feature::storage_push_constant_16:
        return ktl::meta::feature_cast< ktl::api::feature::storage_push_constant_16 >();
    case ktl::api::feature::storage_input_output_16:
        return ktl::meta::feature_cast< ktl::api::feature::storage_input_output_16 >();
    case ktl::api::feature::shader_subgroup_extended_types:
        return ktl::meta::feature_cast< ktl::api::feature::shader_subgroup_extended_types >();
    case ktl::api::feature::sampler_ycbcr_conversion:
        return ktl::meta::feature_cast< ktl::api::feature::sampler_ycbcr_conversion >();
    case ktl::api::feature::protected_memory:
        return ktl::meta::feature_cast< ktl::api::feature::protected_memory >();
    case ktl::api::feature::advanced_blend_coherent_operations_ext:
        return ktl::meta::feature_cast< ktl::api::feature::advanced_blend_coherent_operations_ext >();
    case ktl::api::feature::multi_draw_ext:
        return ktl::meta::feature_cast< ktl::api::feature::multi_draw_ext >();
    case ktl::api::feature::inline_uniform_block:
        return ktl::meta::feature_cast< ktl::api::feature::inline_uniform_block >();
    case ktl::api::feature::descriptor_binding_inline_uniform_block_update_after_bind:
        return ktl::meta::feature_cast<
            ktl::api::feature::descriptor_binding_inline_uniform_block_update_after_bind >();
    case ktl::api::feature::maintenance_4:
        return ktl::meta::feature_cast< ktl::api::feature::maintenance_4 >();
    case ktl::api::feature::maintenance_5:
        return ktl::meta::feature_cast< ktl::api::feature::maintenance_5 >();
    case ktl::api::feature::maintenance_6:
        return ktl::meta::feature_cast< ktl::api::feature::maintenance_6 >();
    case ktl::api::feature::maintenance_7khr:
        return ktl::meta::feature_cast< ktl::api::feature::maintenance_7khr >();
    case ktl::api::feature::maintenance_8khr:
        return ktl::meta::feature_cast< ktl::api::feature::maintenance_8khr >();
    case ktl::api::feature::maintenance_9khr:
        return ktl::meta::feature_cast< ktl::api::feature::maintenance_9khr >();
    case ktl::api::feature::maintenance_11khr:
        return ktl::meta::feature_cast< ktl::api::feature::maintenance_11khr >();
    case ktl::api::feature::maintenance_10khr:
        return ktl::meta::feature_cast< ktl::api::feature::maintenance_10khr >();
    case ktl::api::feature::shader_draw_parameters:
        return ktl::meta::feature_cast< ktl::api::feature::shader_draw_parameters >();
    case ktl::api::feature::shader_float_16:
        return ktl::meta::feature_cast< ktl::api::feature::shader_float_16 >();
    case ktl::api::feature::shader_int_8:
        return ktl::meta::feature_cast< ktl::api::feature::shader_int_8 >();
    case ktl::api::feature::host_query_reset:
        return ktl::meta::feature_cast< ktl::api::feature::host_query_reset >();
    case ktl::api::feature::elapsed_timer_query_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::elapsed_timer_query_qcom >();
    case ktl::api::feature::global_priority_query:
        return ktl::meta::feature_cast< ktl::api::feature::global_priority_query >();
    case ktl::api::feature::device_memory_report_ext:
        return ktl::meta::feature_cast< ktl::api::feature::device_memory_report_ext >();
    case ktl::api::feature::shader_input_attachment_array_dynamic_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_input_attachment_array_dynamic_indexing >();
    case ktl::api::feature::shader_uniform_texel_buffer_array_dynamic_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_uniform_texel_buffer_array_dynamic_indexing >();
    case ktl::api::feature::shader_storage_texel_buffer_array_dynamic_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_texel_buffer_array_dynamic_indexing >();
    case ktl::api::feature::shader_uniform_buffer_array_non_uniform_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_uniform_buffer_array_non_uniform_indexing >();
    case ktl::api::feature::shader_sampled_image_array_non_uniform_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_sampled_image_array_non_uniform_indexing >();
    case ktl::api::feature::shader_storage_buffer_array_non_uniform_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_buffer_array_non_uniform_indexing >();
    case ktl::api::feature::shader_storage_image_array_non_uniform_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_image_array_non_uniform_indexing >();
    case ktl::api::feature::shader_input_attachment_array_non_uniform_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_input_attachment_array_non_uniform_indexing >();
    case ktl::api::feature::shader_uniform_texel_buffer_array_non_uniform_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_uniform_texel_buffer_array_non_uniform_indexing >();
    case ktl::api::feature::shader_storage_texel_buffer_array_non_uniform_indexing:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_texel_buffer_array_non_uniform_indexing >();
    case ktl::api::feature::descriptor_binding_uniform_buffer_update_after_bind:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_uniform_buffer_update_after_bind >();
    case ktl::api::feature::descriptor_binding_sampled_image_update_after_bind:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_sampled_image_update_after_bind >();
    case ktl::api::feature::descriptor_binding_storage_image_update_after_bind:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_storage_image_update_after_bind >();
    case ktl::api::feature::descriptor_binding_storage_buffer_update_after_bind:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_storage_buffer_update_after_bind >();
    case ktl::api::feature::descriptor_binding_uniform_texel_buffer_update_after_bind:
        return ktl::meta::feature_cast<
            ktl::api::feature::descriptor_binding_uniform_texel_buffer_update_after_bind >();
    case ktl::api::feature::descriptor_binding_storage_texel_buffer_update_after_bind:
        return ktl::meta::feature_cast<
            ktl::api::feature::descriptor_binding_storage_texel_buffer_update_after_bind >();
    case ktl::api::feature::descriptor_binding_update_unused_while_pending:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_update_unused_while_pending >();
    case ktl::api::feature::descriptor_binding_partially_bound:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_partially_bound >();
    case ktl::api::feature::descriptor_binding_variable_descriptor_count:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_variable_descriptor_count >();
    case ktl::api::feature::runtime_descriptor_array:
        return ktl::meta::feature_cast< ktl::api::feature::runtime_descriptor_array >();
    case ktl::api::feature::timeline_semaphore:
        return ktl::meta::feature_cast< ktl::api::feature::timeline_semaphore >();
    case ktl::api::feature::storage_buffer_8bit_access:
        return ktl::meta::feature_cast< ktl::api::feature::storage_buffer_8bit_access >();
    case ktl::api::feature::uniform_and_storage_buffer_8bit_access:
        return ktl::meta::feature_cast< ktl::api::feature::uniform_and_storage_buffer_8bit_access >();
    case ktl::api::feature::storage_push_constant_8:
        return ktl::meta::feature_cast< ktl::api::feature::storage_push_constant_8 >();
    case ktl::api::feature::conditional_rendering_ext:
        return ktl::meta::feature_cast< ktl::api::feature::conditional_rendering_ext >();
    case ktl::api::feature::inherited_conditional_rendering_ext:
        return ktl::meta::feature_cast< ktl::api::feature::inherited_conditional_rendering_ext >();
    case ktl::api::feature::vulkan_memory_model:
        return ktl::meta::feature_cast< ktl::api::feature::vulkan_memory_model >();
    case ktl::api::feature::vulkan_memory_model_device_scope:
        return ktl::meta::feature_cast< ktl::api::feature::vulkan_memory_model_device_scope >();
    case ktl::api::feature::vulkan_memory_model_availability_visibility_chains:
        return ktl::meta::feature_cast< ktl::api::feature::vulkan_memory_model_availability_visibility_chains >();
    case ktl::api::feature::shader_buffer_int_64atomics:
        return ktl::meta::feature_cast< ktl::api::feature::shader_buffer_int_64atomics >();
    case ktl::api::feature::shader_shared_int_64atomics:
        return ktl::meta::feature_cast< ktl::api::feature::shader_shared_int_64atomics >();
    case ktl::api::feature::shader_buffer_float_32atomics_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_buffer_float_32atomics_ext >();
    case ktl::api::feature::shader_buffer_float_32atomic_add_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_buffer_float_32atomic_add_ext >();
    case ktl::api::feature::shader_buffer_float_64atomics_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_buffer_float_64atomics_ext >();
    case ktl::api::feature::shader_buffer_float_64atomic_add_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_buffer_float_64atomic_add_ext >();
    case ktl::api::feature::shader_shared_float_32atomics_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_shared_float_32atomics_ext >();
    case ktl::api::feature::shader_shared_float_32atomic_add_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_shared_float_32atomic_add_ext >();
    case ktl::api::feature::shader_shared_float_64atomics_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_shared_float_64atomics_ext >();
    case ktl::api::feature::shader_shared_float_64atomic_add_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_shared_float_64atomic_add_ext >();
    case ktl::api::feature::shader_image_float_32atomics_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_image_float_32atomics_ext >();
    case ktl::api::feature::shader_image_float_32atomic_add_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_image_float_32atomic_add_ext >();
    case ktl::api::feature::sparse_image_float_32atomics_ext:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_image_float_32atomics_ext >();
    case ktl::api::feature::sparse_image_float_32atomic_add_ext:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_image_float_32atomic_add_ext >();
    case ktl::api::feature::shader_buffer_float_16atomics_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_buffer_float_16atomics_2ext >();
    case ktl::api::feature::shader_buffer_float_16atomic_add_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_buffer_float_16atomic_add_2ext >();
    case ktl::api::feature::shader_buffer_float_16atomic_min_max_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_buffer_float_16atomic_min_max_2ext >();
    case ktl::api::feature::shader_buffer_float_32atomic_min_max_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_buffer_float_32atomic_min_max_2ext >();
    case ktl::api::feature::shader_buffer_float_64atomic_min_max_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_buffer_float_64atomic_min_max_2ext >();
    case ktl::api::feature::shader_shared_float_16atomics_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_shared_float_16atomics_2ext >();
    case ktl::api::feature::shader_shared_float_16atomic_add_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_shared_float_16atomic_add_2ext >();
    case ktl::api::feature::shader_shared_float_16atomic_min_max_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_shared_float_16atomic_min_max_2ext >();
    case ktl::api::feature::shader_shared_float_32atomic_min_max_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_shared_float_32atomic_min_max_2ext >();
    case ktl::api::feature::shader_shared_float_64atomic_min_max_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_shared_float_64atomic_min_max_2ext >();
    case ktl::api::feature::shader_image_float_32atomic_min_max_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_image_float_32atomic_min_max_2ext >();
    case ktl::api::feature::sparse_image_float_32atomic_min_max_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_image_float_32atomic_min_max_2ext >();
    case ktl::api::feature::vertex_attribute_instance_rate_divisor:
        return ktl::meta::feature_cast< ktl::api::feature::vertex_attribute_instance_rate_divisor >();
    case ktl::api::feature::vertex_attribute_instance_rate_zero_divisor:
        return ktl::meta::feature_cast< ktl::api::feature::vertex_attribute_instance_rate_zero_divisor >();
    case ktl::api::feature::decode_mode_shared_exponent_ext:
        return ktl::meta::feature_cast< ktl::api::feature::decode_mode_shared_exponent_ext >();
    case ktl::api::feature::transform_feedback_ext:
        return ktl::meta::feature_cast< ktl::api::feature::transform_feedback_ext >();
    case ktl::api::feature::geometry_streams_ext:
        return ktl::meta::feature_cast< ktl::api::feature::geometry_streams_ext >();
    case ktl::api::feature::representative_fragment_test_nv:
        return ktl::meta::feature_cast< ktl::api::feature::representative_fragment_test_nv >();
    case ktl::api::feature::exclusive_scissor_nv:
        return ktl::meta::feature_cast< ktl::api::feature::exclusive_scissor_nv >();
    case ktl::api::feature::corner_sampled_image_nv:
        return ktl::meta::feature_cast< ktl::api::feature::corner_sampled_image_nv >();
    case ktl::api::feature::compute_derivative_group_quads_khr:
        return ktl::meta::feature_cast< ktl::api::feature::compute_derivative_group_quads_khr >();
    case ktl::api::feature::compute_derivative_group_linear_khr:
        return ktl::meta::feature_cast< ktl::api::feature::compute_derivative_group_linear_khr >();
    case ktl::api::feature::image_footprint_nv:
        return ktl::meta::feature_cast< ktl::api::feature::image_footprint_nv >();
    case ktl::api::feature::dedicated_allocation_image_aliasing_nv:
        return ktl::meta::feature_cast< ktl::api::feature::dedicated_allocation_image_aliasing_nv >();
    case ktl::api::feature::indirect_memory_copy_khr:
        return ktl::meta::feature_cast< ktl::api::feature::indirect_memory_copy_khr >();
    case ktl::api::feature::indirect_memory_to_image_copy_khr:
        return ktl::meta::feature_cast< ktl::api::feature::indirect_memory_to_image_copy_khr >();
    case ktl::api::feature::indirect_copy_nv:
        return ktl::meta::feature_cast< ktl::api::feature::indirect_copy_nv >();
    case ktl::api::feature::memory_decompression_ext:
        return ktl::meta::feature_cast< ktl::api::feature::memory_decompression_ext >();
    case ktl::api::feature::shading_rate_image_nv:
        return ktl::meta::feature_cast< ktl::api::feature::shading_rate_image_nv >();
    case ktl::api::feature::shading_rate_coarse_sample_order_nv:
        return ktl::meta::feature_cast< ktl::api::feature::shading_rate_coarse_sample_order_nv >();
    case ktl::api::feature::invocation_mask_huawei:
        return ktl::meta::feature_cast< ktl::api::feature::invocation_mask_huawei >();
    case ktl::api::feature::task_shader_nv:
        return ktl::meta::feature_cast< ktl::api::feature::task_shader_nv >();
    case ktl::api::feature::mesh_shader_nv:
        return ktl::meta::feature_cast< ktl::api::feature::mesh_shader_nv >();
    case ktl::api::feature::task_shader_ext:
        return ktl::meta::feature_cast< ktl::api::feature::task_shader_ext >();
    case ktl::api::feature::mesh_shader_ext:
        return ktl::meta::feature_cast< ktl::api::feature::mesh_shader_ext >();
    case ktl::api::feature::multiview_mesh_shader_ext:
        return ktl::meta::feature_cast< ktl::api::feature::multiview_mesh_shader_ext >();
    case ktl::api::feature::primitive_fragment_shading_rate_mesh_shader_ext:
        return ktl::meta::feature_cast< ktl::api::feature::primitive_fragment_shading_rate_mesh_shader_ext >();
    case ktl::api::feature::mesh_shader_queries_ext:
        return ktl::meta::feature_cast< ktl::api::feature::mesh_shader_queries_ext >();
    case ktl::api::feature::acceleration_structure_khr:
        return ktl::meta::feature_cast< ktl::api::feature::acceleration_structure_khr >();
    case ktl::api::feature::acceleration_structure_capture_replay_khr:
        return ktl::meta::feature_cast< ktl::api::feature::acceleration_structure_capture_replay_khr >();
    case ktl::api::feature::acceleration_structure_indirect_build_khr:
        return ktl::meta::feature_cast< ktl::api::feature::acceleration_structure_indirect_build_khr >();
    case ktl::api::feature::acceleration_structure_host_commands_khr:
        return ktl::meta::feature_cast< ktl::api::feature::acceleration_structure_host_commands_khr >();
    case ktl::api::feature::descriptor_binding_acceleration_structure_update_after_bind_khr:
        return ktl::meta::feature_cast<
            ktl::api::feature::descriptor_binding_acceleration_structure_update_after_bind_khr >();
    case ktl::api::feature::ray_tracing_pipeline_khr:
        return ktl::meta::feature_cast< ktl::api::feature::ray_tracing_pipeline_khr >();
    case ktl::api::feature::ray_tracing_pipeline_shader_group_handle_capture_replay_khr:
        return ktl::meta::feature_cast<
            ktl::api::feature::ray_tracing_pipeline_shader_group_handle_capture_replay_khr >();
    case ktl::api::feature::ray_tracing_pipeline_shader_group_handle_capture_replay_mixed_khr:
        return ktl::meta::feature_cast<
            ktl::api::feature::ray_tracing_pipeline_shader_group_handle_capture_replay_mixed_khr >();
    case ktl::api::feature::ray_tracing_pipeline_trace_rays_indirect_khr:
        return ktl::meta::feature_cast< ktl::api::feature::ray_tracing_pipeline_trace_rays_indirect_khr >();
    case ktl::api::feature::ray_traversal_primitive_culling_khr:
        return ktl::meta::feature_cast< ktl::api::feature::ray_traversal_primitive_culling_khr >();
    case ktl::api::feature::ray_query_khr:
        return ktl::meta::feature_cast< ktl::api::feature::ray_query_khr >();
    case ktl::api::feature::ray_tracing_maintenance_1khr:
        return ktl::meta::feature_cast< ktl::api::feature::ray_tracing_maintenance_1khr >();
    case ktl::api::feature::ray_tracing_pipeline_trace_rays_indirect_21khr:
        return ktl::meta::feature_cast< ktl::api::feature::ray_tracing_pipeline_trace_rays_indirect_21khr >();
    case ktl::api::feature::fragment_density_map_ext:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_density_map_ext >();
    case ktl::api::feature::fragment_density_map_dynamic_ext:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_density_map_dynamic_ext >();
    case ktl::api::feature::fragment_density_map_non_subsampled_images_ext:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_density_map_non_subsampled_images_ext >();
    case ktl::api::feature::fragment_density_map_deferred_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_density_map_deferred_2ext >();
    case ktl::api::feature::fragment_density_map_offset_ext:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_density_map_offset_ext >();
    case ktl::api::feature::scalar_block_layout:
        return ktl::meta::feature_cast< ktl::api::feature::scalar_block_layout >();
    case ktl::api::feature::uniform_buffer_standard_layout:
        return ktl::meta::feature_cast< ktl::api::feature::uniform_buffer_standard_layout >();
    case ktl::api::feature::depth_clip_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::depth_clip_enable_ext >();
    case ktl::api::feature::memory_priority_ext:
        return ktl::meta::feature_cast< ktl::api::feature::memory_priority_ext >();
    case ktl::api::feature::pageable_device_local_memory_ext:
        return ktl::meta::feature_cast< ktl::api::feature::pageable_device_local_memory_ext >();
    case ktl::api::feature::buffer_device_address:
        return ktl::meta::feature_cast< ktl::api::feature::buffer_device_address >();
    case ktl::api::feature::buffer_device_address_capture_replay:
        return ktl::meta::feature_cast< ktl::api::feature::buffer_device_address_capture_replay >();
    case ktl::api::feature::buffer_device_address_multi_device:
        return ktl::meta::feature_cast< ktl::api::feature::buffer_device_address_multi_device >();
    case ktl::api::feature::buffer_device_address_ext:
        return ktl::meta::feature_cast< ktl::api::feature::buffer_device_address_ext >();
    case ktl::api::feature::buffer_device_address_capture_replay_ext:
        return ktl::meta::feature_cast< ktl::api::feature::buffer_device_address_capture_replay_ext >();
    case ktl::api::feature::buffer_device_address_multi_device_ext:
        return ktl::meta::feature_cast< ktl::api::feature::buffer_device_address_multi_device_ext >();
    case ktl::api::feature::imageless_framebuffer:
        return ktl::meta::feature_cast< ktl::api::feature::imageless_framebuffer >();
    case ktl::api::feature::texture_compression_astc_hdr:
        return ktl::meta::feature_cast< ktl::api::feature::texture_compression_astc_hdr >();
    case ktl::api::feature::cooperative_matrix_nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_nv >();
    case ktl::api::feature::cooperative_matrix_robust_buffer_access_nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_robust_buffer_access_nv >();
    case ktl::api::feature::ycbcr_image_arrays_ext:
        return ktl::meta::feature_cast< ktl::api::feature::ycbcr_image_arrays_ext >();
    case ktl::api::feature::present_barrier_nv:
        return ktl::meta::feature_cast< ktl::api::feature::present_barrier_nv >();
    case ktl::api::feature::performance_counter_query_pools_khr:
        return ktl::meta::feature_cast< ktl::api::feature::performance_counter_query_pools_khr >();
    case ktl::api::feature::performance_counter_multiple_query_pools_khr:
        return ktl::meta::feature_cast< ktl::api::feature::performance_counter_multiple_query_pools_khr >();
    case ktl::api::feature::coverage_reduction_mode_nv:
        return ktl::meta::feature_cast< ktl::api::feature::coverage_reduction_mode_nv >();
    case ktl::api::feature::shader_integer_functions_2intel:
        return ktl::meta::feature_cast< ktl::api::feature::shader_integer_functions_2intel >();
    case ktl::api::feature::shader_subgroup_clock_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_subgroup_clock_khr >();
    case ktl::api::feature::shader_device_clock_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_device_clock_khr >();
    case ktl::api::feature::index_type_uint_8:
        return ktl::meta::feature_cast< ktl::api::feature::index_type_uint_8 >();
    case ktl::api::feature::shader_sm_builtins_nv:
        return ktl::meta::feature_cast< ktl::api::feature::shader_sm_builtins_nv >();
    case ktl::api::feature::fragment_shader_sample_interlock_ext:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_shader_sample_interlock_ext >();
    case ktl::api::feature::fragment_shader_pixel_interlock_ext:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_shader_pixel_interlock_ext >();
    case ktl::api::feature::fragment_shader_shading_rate_interlock_ext:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_shader_shading_rate_interlock_ext >();
    case ktl::api::feature::separate_depth_stencil_layouts:
        return ktl::meta::feature_cast< ktl::api::feature::separate_depth_stencil_layouts >();
    case ktl::api::feature::primitive_topology_list_restart_ext:
        return ktl::meta::feature_cast< ktl::api::feature::primitive_topology_list_restart_ext >();
    case ktl::api::feature::primitive_topology_patch_list_restart_ext:
        return ktl::meta::feature_cast< ktl::api::feature::primitive_topology_patch_list_restart_ext >();
    case ktl::api::feature::pipeline_executable_info_khr:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_executable_info_khr >();
    case ktl::api::feature::shader_demote_to_helper_invocation:
        return ktl::meta::feature_cast< ktl::api::feature::shader_demote_to_helper_invocation >();
    case ktl::api::feature::texel_buffer_alignment_ext:
        return ktl::meta::feature_cast< ktl::api::feature::texel_buffer_alignment_ext >();
    case ktl::api::feature::subgroup_size_control:
        return ktl::meta::feature_cast< ktl::api::feature::subgroup_size_control >();
    case ktl::api::feature::compute_full_subgroups:
        return ktl::meta::feature_cast< ktl::api::feature::compute_full_subgroups >();
    case ktl::api::feature::rectangular_lines:
        return ktl::meta::feature_cast< ktl::api::feature::rectangular_lines >();
    case ktl::api::feature::bresenham_lines:
        return ktl::meta::feature_cast< ktl::api::feature::bresenham_lines >();
    case ktl::api::feature::smooth_lines:
        return ktl::meta::feature_cast< ktl::api::feature::smooth_lines >();
    case ktl::api::feature::stippled_rectangular_lines:
        return ktl::meta::feature_cast< ktl::api::feature::stippled_rectangular_lines >();
    case ktl::api::feature::stippled_bresenham_lines:
        return ktl::meta::feature_cast< ktl::api::feature::stippled_bresenham_lines >();
    case ktl::api::feature::stippled_smooth_lines:
        return ktl::meta::feature_cast< ktl::api::feature::stippled_smooth_lines >();
    case ktl::api::feature::pipeline_creation_cache_control:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_creation_cache_control >();
    case ktl::api::feature::storage_buffer_16bit_access_11:
        return ktl::meta::feature_cast< ktl::api::feature::storage_buffer_16bit_access_11 >();
    case ktl::api::feature::uniform_and_storage_buffer_16bit_access_11:
        return ktl::meta::feature_cast< ktl::api::feature::uniform_and_storage_buffer_16bit_access_11 >();
    case ktl::api::feature::storage_push_constant_1611:
        return ktl::meta::feature_cast< ktl::api::feature::storage_push_constant_1611 >();
    case ktl::api::feature::storage_input_output_1611:
        return ktl::meta::feature_cast< ktl::api::feature::storage_input_output_1611 >();
    case ktl::api::feature::multiview_11:
        return ktl::meta::feature_cast< ktl::api::feature::multiview_11 >();
    case ktl::api::feature::multiview_geometry_shader_11:
        return ktl::meta::feature_cast< ktl::api::feature::multiview_geometry_shader_11 >();
    case ktl::api::feature::multiview_tessellation_shader_11:
        return ktl::meta::feature_cast< ktl::api::feature::multiview_tessellation_shader_11 >();
    case ktl::api::feature::variable_pointers_storage_buffer_11:
        return ktl::meta::feature_cast< ktl::api::feature::variable_pointers_storage_buffer_11 >();
    case ktl::api::feature::variable_pointers_11:
        return ktl::meta::feature_cast< ktl::api::feature::variable_pointers_11 >();
    case ktl::api::feature::protected_memory_11:
        return ktl::meta::feature_cast< ktl::api::feature::protected_memory_11 >();
    case ktl::api::feature::sampler_ycbcr_conversion_11:
        return ktl::meta::feature_cast< ktl::api::feature::sampler_ycbcr_conversion_11 >();
    case ktl::api::feature::shader_draw_parameters_11:
        return ktl::meta::feature_cast< ktl::api::feature::shader_draw_parameters_11 >();
    case ktl::api::feature::sampler_mirror_clamp_to_edge_12:
        return ktl::meta::feature_cast< ktl::api::feature::sampler_mirror_clamp_to_edge_12 >();
    case ktl::api::feature::draw_indirect_count_12:
        return ktl::meta::feature_cast< ktl::api::feature::draw_indirect_count_12 >();
    case ktl::api::feature::storage_buffer_8bit_access_12:
        return ktl::meta::feature_cast< ktl::api::feature::storage_buffer_8bit_access_12 >();
    case ktl::api::feature::uniform_and_storage_buffer_8bit_access_12:
        return ktl::meta::feature_cast< ktl::api::feature::uniform_and_storage_buffer_8bit_access_12 >();
    case ktl::api::feature::storage_push_constant_812:
        return ktl::meta::feature_cast< ktl::api::feature::storage_push_constant_812 >();
    case ktl::api::feature::shader_buffer_int_64atomics_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_buffer_int_64atomics_12 >();
    case ktl::api::feature::shader_shared_int_64atomics_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_shared_int_64atomics_12 >();
    case ktl::api::feature::shader_float_1612:
        return ktl::meta::feature_cast< ktl::api::feature::shader_float_1612 >();
    case ktl::api::feature::shader_int_812:
        return ktl::meta::feature_cast< ktl::api::feature::shader_int_812 >();
    case ktl::api::feature::descriptor_indexing_12:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_indexing_12 >();
    case ktl::api::feature::shader_input_attachment_array_dynamic_indexing_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_input_attachment_array_dynamic_indexing_12 >();
    case ktl::api::feature::shader_uniform_texel_buffer_array_dynamic_indexing_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_uniform_texel_buffer_array_dynamic_indexing_12 >();
    case ktl::api::feature::shader_storage_texel_buffer_array_dynamic_indexing_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_texel_buffer_array_dynamic_indexing_12 >();
    case ktl::api::feature::shader_uniform_buffer_array_non_uniform_indexing_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_uniform_buffer_array_non_uniform_indexing_12 >();
    case ktl::api::feature::shader_sampled_image_array_non_uniform_indexing_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_sampled_image_array_non_uniform_indexing_12 >();
    case ktl::api::feature::shader_storage_buffer_array_non_uniform_indexing_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_buffer_array_non_uniform_indexing_12 >();
    case ktl::api::feature::shader_storage_image_array_non_uniform_indexing_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_image_array_non_uniform_indexing_12 >();
    case ktl::api::feature::shader_input_attachment_array_non_uniform_indexing_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_input_attachment_array_non_uniform_indexing_12 >();
    case ktl::api::feature::shader_uniform_texel_buffer_array_non_uniform_indexing_12:
        return ktl::meta::feature_cast<
            ktl::api::feature::shader_uniform_texel_buffer_array_non_uniform_indexing_12 >();
    case ktl::api::feature::shader_storage_texel_buffer_array_non_uniform_indexing_12:
        return ktl::meta::feature_cast<
            ktl::api::feature::shader_storage_texel_buffer_array_non_uniform_indexing_12 >();
    case ktl::api::feature::descriptor_binding_uniform_buffer_update_after_bind_12:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_uniform_buffer_update_after_bind_12 >();
    case ktl::api::feature::descriptor_binding_sampled_image_update_after_bind_12:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_sampled_image_update_after_bind_12 >();
    case ktl::api::feature::descriptor_binding_storage_image_update_after_bind_12:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_storage_image_update_after_bind_12 >();
    case ktl::api::feature::descriptor_binding_storage_buffer_update_after_bind_12:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_storage_buffer_update_after_bind_12 >();
    case ktl::api::feature::descriptor_binding_uniform_texel_buffer_update_after_bind_12:
        return ktl::meta::feature_cast<
            ktl::api::feature::descriptor_binding_uniform_texel_buffer_update_after_bind_12 >();
    case ktl::api::feature::descriptor_binding_storage_texel_buffer_update_after_bind_12:
        return ktl::meta::feature_cast<
            ktl::api::feature::descriptor_binding_storage_texel_buffer_update_after_bind_12 >();
    case ktl::api::feature::descriptor_binding_update_unused_while_pending_12:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_update_unused_while_pending_12 >();
    case ktl::api::feature::descriptor_binding_partially_bound_12:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_partially_bound_12 >();
    case ktl::api::feature::descriptor_binding_variable_descriptor_count_12:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_variable_descriptor_count_12 >();
    case ktl::api::feature::runtime_descriptor_array_12:
        return ktl::meta::feature_cast< ktl::api::feature::runtime_descriptor_array_12 >();
    case ktl::api::feature::sampler_filter_minmax_12:
        return ktl::meta::feature_cast< ktl::api::feature::sampler_filter_minmax_12 >();
    case ktl::api::feature::scalar_block_layout_12:
        return ktl::meta::feature_cast< ktl::api::feature::scalar_block_layout_12 >();
    case ktl::api::feature::imageless_framebuffer_12:
        return ktl::meta::feature_cast< ktl::api::feature::imageless_framebuffer_12 >();
    case ktl::api::feature::uniform_buffer_standard_layout_12:
        return ktl::meta::feature_cast< ktl::api::feature::uniform_buffer_standard_layout_12 >();
    case ktl::api::feature::shader_subgroup_extended_types_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_subgroup_extended_types_12 >();
    case ktl::api::feature::separate_depth_stencil_layouts_12:
        return ktl::meta::feature_cast< ktl::api::feature::separate_depth_stencil_layouts_12 >();
    case ktl::api::feature::host_query_reset_12:
        return ktl::meta::feature_cast< ktl::api::feature::host_query_reset_12 >();
    case ktl::api::feature::timeline_semaphore_12:
        return ktl::meta::feature_cast< ktl::api::feature::timeline_semaphore_12 >();
    case ktl::api::feature::buffer_device_address_12:
        return ktl::meta::feature_cast< ktl::api::feature::buffer_device_address_12 >();
    case ktl::api::feature::buffer_device_address_capture_replay_12:
        return ktl::meta::feature_cast< ktl::api::feature::buffer_device_address_capture_replay_12 >();
    case ktl::api::feature::buffer_device_address_multi_device_12:
        return ktl::meta::feature_cast< ktl::api::feature::buffer_device_address_multi_device_12 >();
    case ktl::api::feature::vulkan_memory_model_12:
        return ktl::meta::feature_cast< ktl::api::feature::vulkan_memory_model_12 >();
    case ktl::api::feature::vulkan_memory_model_device_scope_12:
        return ktl::meta::feature_cast< ktl::api::feature::vulkan_memory_model_device_scope_12 >();
    case ktl::api::feature::vulkan_memory_model_availability_visibility_chains_12:
        return ktl::meta::feature_cast< ktl::api::feature::vulkan_memory_model_availability_visibility_chains_12 >();
    case ktl::api::feature::shader_output_viewport_index_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_output_viewport_index_12 >();
    case ktl::api::feature::shader_output_layer_12:
        return ktl::meta::feature_cast< ktl::api::feature::shader_output_layer_12 >();
    case ktl::api::feature::subgroup_broadcast_dynamic_id_12:
        return ktl::meta::feature_cast< ktl::api::feature::subgroup_broadcast_dynamic_id_12 >();
    case ktl::api::feature::robust_image_access_13:
        return ktl::meta::feature_cast< ktl::api::feature::robust_image_access_13 >();
    case ktl::api::feature::inline_uniform_block_13:
        return ktl::meta::feature_cast< ktl::api::feature::inline_uniform_block_13 >();
    case ktl::api::feature::descriptor_binding_inline_uniform_block_update_after_bind_13:
        return ktl::meta::feature_cast<
            ktl::api::feature::descriptor_binding_inline_uniform_block_update_after_bind_13 >();
    case ktl::api::feature::pipeline_creation_cache_control_13:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_creation_cache_control_13 >();
    case ktl::api::feature::private_data_13:
        return ktl::meta::feature_cast< ktl::api::feature::private_data_13 >();
    case ktl::api::feature::shader_demote_to_helper_invocation_13:
        return ktl::meta::feature_cast< ktl::api::feature::shader_demote_to_helper_invocation_13 >();
    case ktl::api::feature::shader_terminate_invocation_13:
        return ktl::meta::feature_cast< ktl::api::feature::shader_terminate_invocation_13 >();
    case ktl::api::feature::subgroup_size_control_13:
        return ktl::meta::feature_cast< ktl::api::feature::subgroup_size_control_13 >();
    case ktl::api::feature::compute_full_subgroups_13:
        return ktl::meta::feature_cast< ktl::api::feature::compute_full_subgroups_13 >();
    case ktl::api::feature::synchronization_213:
        return ktl::meta::feature_cast< ktl::api::feature::synchronization_213 >();
    case ktl::api::feature::texture_compression_astc_hdr_13:
        return ktl::meta::feature_cast< ktl::api::feature::texture_compression_astc_hdr_13 >();
    case ktl::api::feature::shader_zero_initialize_workgroup_memory_13:
        return ktl::meta::feature_cast< ktl::api::feature::shader_zero_initialize_workgroup_memory_13 >();
    case ktl::api::feature::dynamic_rendering_13:
        return ktl::meta::feature_cast< ktl::api::feature::dynamic_rendering_13 >();
    case ktl::api::feature::shader_integer_dot_product_13:
        return ktl::meta::feature_cast< ktl::api::feature::shader_integer_dot_product_13 >();
    case ktl::api::feature::maintenance_413:
        return ktl::meta::feature_cast< ktl::api::feature::maintenance_413 >();
    case ktl::api::feature::global_priority_query_14:
        return ktl::meta::feature_cast< ktl::api::feature::global_priority_query_14 >();
    case ktl::api::feature::shader_subgroup_rotate_14:
        return ktl::meta::feature_cast< ktl::api::feature::shader_subgroup_rotate_14 >();
    case ktl::api::feature::shader_subgroup_rotate_clustered_14:
        return ktl::meta::feature_cast< ktl::api::feature::shader_subgroup_rotate_clustered_14 >();
    case ktl::api::feature::shader_float_controls_214:
        return ktl::meta::feature_cast< ktl::api::feature::shader_float_controls_214 >();
    case ktl::api::feature::shader_expect_assume_14:
        return ktl::meta::feature_cast< ktl::api::feature::shader_expect_assume_14 >();
    case ktl::api::feature::rectangular_lines_14:
        return ktl::meta::feature_cast< ktl::api::feature::rectangular_lines_14 >();
    case ktl::api::feature::bresenham_lines_14:
        return ktl::meta::feature_cast< ktl::api::feature::bresenham_lines_14 >();
    case ktl::api::feature::smooth_lines_14:
        return ktl::meta::feature_cast< ktl::api::feature::smooth_lines_14 >();
    case ktl::api::feature::stippled_rectangular_lines_14:
        return ktl::meta::feature_cast< ktl::api::feature::stippled_rectangular_lines_14 >();
    case ktl::api::feature::stippled_bresenham_lines_14:
        return ktl::meta::feature_cast< ktl::api::feature::stippled_bresenham_lines_14 >();
    case ktl::api::feature::stippled_smooth_lines_14:
        return ktl::meta::feature_cast< ktl::api::feature::stippled_smooth_lines_14 >();
    case ktl::api::feature::vertex_attribute_instance_rate_divisor_14:
        return ktl::meta::feature_cast< ktl::api::feature::vertex_attribute_instance_rate_divisor_14 >();
    case ktl::api::feature::vertex_attribute_instance_rate_zero_divisor_14:
        return ktl::meta::feature_cast< ktl::api::feature::vertex_attribute_instance_rate_zero_divisor_14 >();
    case ktl::api::feature::index_type_uint_814:
        return ktl::meta::feature_cast< ktl::api::feature::index_type_uint_814 >();
    case ktl::api::feature::dynamic_rendering_local_read_14:
        return ktl::meta::feature_cast< ktl::api::feature::dynamic_rendering_local_read_14 >();
    case ktl::api::feature::maintenance_514:
        return ktl::meta::feature_cast< ktl::api::feature::maintenance_514 >();
    case ktl::api::feature::maintenance_614:
        return ktl::meta::feature_cast< ktl::api::feature::maintenance_614 >();
    case ktl::api::feature::pipeline_protected_access_14:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_protected_access_14 >();
    case ktl::api::feature::pipeline_robustness_14:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_robustness_14 >();
    case ktl::api::feature::host_image_copy_14:
        return ktl::meta::feature_cast< ktl::api::feature::host_image_copy_14 >();
    case ktl::api::feature::push_descriptor_14:
        return ktl::meta::feature_cast< ktl::api::feature::push_descriptor_14 >();
    case ktl::api::feature::device_coherent_memory_amd:
        return ktl::meta::feature_cast< ktl::api::feature::device_coherent_memory_amd >();
    case ktl::api::feature::perf_counters_amd:
        return ktl::meta::feature_cast< ktl::api::feature::perf_counters_amd >();
    case ktl::api::feature::streaming_perf_counters_amd:
        return ktl::meta::feature_cast< ktl::api::feature::streaming_perf_counters_amd >();
    case ktl::api::feature::sq_thread_tracing_amd:
        return ktl::meta::feature_cast< ktl::api::feature::sq_thread_tracing_amd >();
    case ktl::api::feature::clock_modes_amd:
        return ktl::meta::feature_cast< ktl::api::feature::clock_modes_amd >();
    case ktl::api::feature::custom_border_colors_ext:
        return ktl::meta::feature_cast< ktl::api::feature::custom_border_colors_ext >();
    case ktl::api::feature::custom_border_color_without_format_ext:
        return ktl::meta::feature_cast< ktl::api::feature::custom_border_color_without_format_ext >();
    case ktl::api::feature::border_color_swizzle_ext:
        return ktl::meta::feature_cast< ktl::api::feature::border_color_swizzle_ext >();
    case ktl::api::feature::border_color_swizzle_from_image_ext:
        return ktl::meta::feature_cast< ktl::api::feature::border_color_swizzle_from_image_ext >();
    case ktl::api::feature::extended_dynamic_state_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_ext >();
    case ktl::api::feature::extended_dynamic_state_2ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_2ext >();
    case ktl::api::feature::extended_dynamic_state_2logic_op_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_2logic_op_ext >();
    case ktl::api::feature::extended_dynamic_state_2patch_control_points_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_2patch_control_points_ext >();
    case ktl::api::feature::extended_dynamic_state_3tessellation_domain_origin_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3tessellation_domain_origin_ext >();
    case ktl::api::feature::extended_dynamic_state_3depth_clamp_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3depth_clamp_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3polygon_mode_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3polygon_mode_ext >();
    case ktl::api::feature::extended_dynamic_state_3rasterization_samples_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3rasterization_samples_ext >();
    case ktl::api::feature::extended_dynamic_state_3sample_mask_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3sample_mask_ext >();
    case ktl::api::feature::extended_dynamic_state_3alpha_to_coverage_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3alpha_to_coverage_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3alpha_to_one_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3alpha_to_one_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3logic_op_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3logic_op_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3color_blend_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3color_blend_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3color_blend_equation_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3color_blend_equation_ext >();
    case ktl::api::feature::extended_dynamic_state_3color_write_mask_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3color_write_mask_ext >();
    case ktl::api::feature::extended_dynamic_state_3rasterization_stream_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3rasterization_stream_ext >();
    case ktl::api::feature::extended_dynamic_state_3conservative_rasterization_mode_ext:
        return ktl::meta::feature_cast<
            ktl::api::feature::extended_dynamic_state_3conservative_rasterization_mode_ext >();
    case ktl::api::feature::extended_dynamic_state_3extra_primitive_overestimation_size_ext:
        return ktl::meta::feature_cast<
            ktl::api::feature::extended_dynamic_state_3extra_primitive_overestimation_size_ext >();
    case ktl::api::feature::extended_dynamic_state_3depth_clip_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3depth_clip_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3sample_locations_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3sample_locations_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3color_blend_advanced_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3color_blend_advanced_ext >();
    case ktl::api::feature::extended_dynamic_state_3provoking_vertex_mode_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3provoking_vertex_mode_ext >();
    case ktl::api::feature::extended_dynamic_state_3line_rasterization_mode_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3line_rasterization_mode_ext >();
    case ktl::api::feature::extended_dynamic_state_3line_stipple_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3line_stipple_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3depth_clip_negative_one_to_one_ext:
        return ktl::meta::feature_cast<
            ktl::api::feature::extended_dynamic_state_3depth_clip_negative_one_to_one_ext >();
    case ktl::api::feature::extended_dynamic_state_3viewport_w_scaling_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3viewport_w_scaling_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3viewport_swizzle_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3viewport_swizzle_ext >();
    case ktl::api::feature::extended_dynamic_state_3coverage_to_color_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3coverage_to_color_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3coverage_to_color_location_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3coverage_to_color_location_ext >();
    case ktl::api::feature::extended_dynamic_state_3coverage_modulation_mode_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3coverage_modulation_mode_ext >();
    case ktl::api::feature::extended_dynamic_state_3coverage_modulation_table_enable_ext:
        return ktl::meta::feature_cast<
            ktl::api::feature::extended_dynamic_state_3coverage_modulation_table_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3coverage_modulation_table_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3coverage_modulation_table_ext >();
    case ktl::api::feature::extended_dynamic_state_3coverage_reduction_mode_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3coverage_reduction_mode_ext >();
    case ktl::api::feature::extended_dynamic_state_3representative_fragment_test_enable_ext:
        return ktl::meta::feature_cast<
            ktl::api::feature::extended_dynamic_state_3representative_fragment_test_enable_ext >();
    case ktl::api::feature::extended_dynamic_state_3shading_rate_image_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::extended_dynamic_state_3shading_rate_image_enable_ext >();
    case ktl::api::feature::partitioned_acceleration_structure_nv:
        return ktl::meta::feature_cast< ktl::api::feature::partitioned_acceleration_structure_nv >();
    case ktl::api::feature::diagnostics_config_nv:
        return ktl::meta::feature_cast< ktl::api::feature::diagnostics_config_nv >();
    case ktl::api::feature::shader_zero_initialize_workgroup_memory:
        return ktl::meta::feature_cast< ktl::api::feature::shader_zero_initialize_workgroup_memory >();
    case ktl::api::feature::shader_subgroup_uniform_control_flow_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_subgroup_uniform_control_flow_khr >();
    case ktl::api::feature::robust_buffer_access_2khr:
        return ktl::meta::feature_cast< ktl::api::feature::robust_buffer_access_2khr >();
    case ktl::api::feature::robust_image_access_2khr:
        return ktl::meta::feature_cast< ktl::api::feature::robust_image_access_2khr >();
    case ktl::api::feature::null_descriptor_2khr:
        return ktl::meta::feature_cast< ktl::api::feature::null_descriptor_2khr >();
    case ktl::api::feature::robust_image_access:
        return ktl::meta::feature_cast< ktl::api::feature::robust_image_access >();
    case ktl::api::feature::workgroup_memory_explicit_layout_khr:
        return ktl::meta::feature_cast< ktl::api::feature::workgroup_memory_explicit_layout_khr >();
    case ktl::api::feature::workgroup_memory_explicit_layout_scalar_block_layout_khr:
        return ktl::meta::feature_cast< ktl::api::feature::workgroup_memory_explicit_layout_scalar_block_layout_khr >();
    case ktl::api::feature::workgroup_memory_explicit_layout_8bit_access_khr:
        return ktl::meta::feature_cast< ktl::api::feature::workgroup_memory_explicit_layout_8bit_access_khr >();
    case ktl::api::feature::workgroup_memory_explicit_layout_16bit_access_khr:
        return ktl::meta::feature_cast< ktl::api::feature::workgroup_memory_explicit_layout_16bit_access_khr >();
    case ktl::api::feature::constant_alpha_color_blend_factors_khr:
        return ktl::meta::feature_cast< ktl::api::feature::constant_alpha_color_blend_factors_khr >();
    case ktl::api::feature::events_khr:
        return ktl::meta::feature_cast< ktl::api::feature::events_khr >();
    case ktl::api::feature::image_view_format_reinterpretation_khr:
        return ktl::meta::feature_cast< ktl::api::feature::image_view_format_reinterpretation_khr >();
    case ktl::api::feature::image_view_format_swizzle_khr:
        return ktl::meta::feature_cast< ktl::api::feature::image_view_format_swizzle_khr >();
    case ktl::api::feature::image_view_2d_on_3d_image_khr:
        return ktl::meta::feature_cast< ktl::api::feature::image_view_2d_on_3d_image_khr >();
    case ktl::api::feature::multisample_array_image_khr:
        return ktl::meta::feature_cast< ktl::api::feature::multisample_array_image_khr >();
    case ktl::api::feature::mutable_comparison_samplers_khr:
        return ktl::meta::feature_cast< ktl::api::feature::mutable_comparison_samplers_khr >();
    case ktl::api::feature::point_polygons_khr:
        return ktl::meta::feature_cast< ktl::api::feature::point_polygons_khr >();
    case ktl::api::feature::sampler_mip_lod_bias_khr:
        return ktl::meta::feature_cast< ktl::api::feature::sampler_mip_lod_bias_khr >();
    case ktl::api::feature::separate_stencil_mask_ref_khr:
        return ktl::meta::feature_cast< ktl::api::feature::separate_stencil_mask_ref_khr >();
    case ktl::api::feature::shader_sample_rate_interpolation_functions_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_sample_rate_interpolation_functions_khr >();
    case ktl::api::feature::tessellation_isolines_khr:
        return ktl::meta::feature_cast< ktl::api::feature::tessellation_isolines_khr >();
    case ktl::api::feature::tessellation_point_mode_khr:
        return ktl::meta::feature_cast< ktl::api::feature::tessellation_point_mode_khr >();
    case ktl::api::feature::triangle_fans_khr:
        return ktl::meta::feature_cast< ktl::api::feature::triangle_fans_khr >();
    case ktl::api::feature::vertex_attribute_access_beyond_stride_khr:
        return ktl::meta::feature_cast< ktl::api::feature::vertex_attribute_access_beyond_stride_khr >();
    case ktl::api::feature::format_a_4r_4g_4b_44444ext:
        return ktl::meta::feature_cast< ktl::api::feature::format_a_4r_4g_4b_44444ext >();
    case ktl::api::feature::format_a_4b_4g_4r_44444ext:
        return ktl::meta::feature_cast< ktl::api::feature::format_a_4b_4g_4r_44444ext >();
    case ktl::api::feature::subpass_shading_huawei:
        return ktl::meta::feature_cast< ktl::api::feature::subpass_shading_huawei >();
    case ktl::api::feature::clusterculling_shader_huawei:
        return ktl::meta::feature_cast< ktl::api::feature::clusterculling_shader_huawei >();
    case ktl::api::feature::multiview_cluster_culling_shader_huawei:
        return ktl::meta::feature_cast< ktl::api::feature::multiview_cluster_culling_shader_huawei >();
    case ktl::api::feature::cluster_shading_rate_huawei:
        return ktl::meta::feature_cast< ktl::api::feature::cluster_shading_rate_huawei >();
    case ktl::api::feature::shader_image_int_64atomics_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_image_int_64atomics_ext >();
    case ktl::api::feature::sparse_image_int_64atomics_ext:
        return ktl::meta::feature_cast< ktl::api::feature::sparse_image_int_64atomics_ext >();
    case ktl::api::feature::pipeline_fragment_shading_rate_khr:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_fragment_shading_rate_khr >();
    case ktl::api::feature::primitive_fragment_shading_rate_khr:
        return ktl::meta::feature_cast< ktl::api::feature::primitive_fragment_shading_rate_khr >();
    case ktl::api::feature::attachment_fragment_shading_rate_khr:
        return ktl::meta::feature_cast< ktl::api::feature::attachment_fragment_shading_rate_khr >();
    case ktl::api::feature::shader_terminate_invocation:
        return ktl::meta::feature_cast< ktl::api::feature::shader_terminate_invocation >();
    case ktl::api::feature::fragment_shading_rate_enums_nv:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_shading_rate_enums_nv >();
    case ktl::api::feature::supersample_fragment_shading_rates_nv:
        return ktl::meta::feature_cast< ktl::api::feature::supersample_fragment_shading_rates_nv >();
    case ktl::api::feature::no_invocation_fragment_shading_rates_nv:
        return ktl::meta::feature_cast< ktl::api::feature::no_invocation_fragment_shading_rates_nv >();
    case ktl::api::feature::image_2d_view_of_3d_ext:
        return ktl::meta::feature_cast< ktl::api::feature::image_2d_view_of_3d_ext >();
    case ktl::api::feature::sampler_2d_view_of_3d_ext:
        return ktl::meta::feature_cast< ktl::api::feature::sampler_2d_view_of_3d_ext >();
    case ktl::api::feature::image_sliced_view_of_3d_ext:
        return ktl::meta::feature_cast< ktl::api::feature::image_sliced_view_of_3d_ext >();
    case ktl::api::feature::attachment_feedback_loop_dynamic_state_ext:
        return ktl::meta::feature_cast< ktl::api::feature::attachment_feedback_loop_dynamic_state_ext >();
    case ktl::api::feature::legacy_vertex_attributes_ext:
        return ktl::meta::feature_cast< ktl::api::feature::legacy_vertex_attributes_ext >();
    case ktl::api::feature::mutable_descriptor_type_ext:
        return ktl::meta::feature_cast< ktl::api::feature::mutable_descriptor_type_ext >();
    case ktl::api::feature::depth_clip_control_ext:
        return ktl::meta::feature_cast< ktl::api::feature::depth_clip_control_ext >();
    case ktl::api::feature::zero_initialize_device_memory_ext:
        return ktl::meta::feature_cast< ktl::api::feature::zero_initialize_device_memory_ext >();
    case ktl::api::feature::custom_resolve_ext:
        return ktl::meta::feature_cast< ktl::api::feature::custom_resolve_ext >();
    case ktl::api::feature::device_generated_commands_ext:
        return ktl::meta::feature_cast< ktl::api::feature::device_generated_commands_ext >();
    case ktl::api::feature::dynamic_generated_pipeline_layout_ext:
        return ktl::meta::feature_cast< ktl::api::feature::dynamic_generated_pipeline_layout_ext >();
    case ktl::api::feature::depth_clamp_control_ext:
        return ktl::meta::feature_cast< ktl::api::feature::depth_clamp_control_ext >();
    case ktl::api::feature::vertex_input_dynamic_state_ext:
        return ktl::meta::feature_cast< ktl::api::feature::vertex_input_dynamic_state_ext >();
    case ktl::api::feature::external_memory_rdma_nv:
        return ktl::meta::feature_cast< ktl::api::feature::external_memory_rdma_nv >();
    case ktl::api::feature::shader_relaxed_extended_instruction_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_relaxed_extended_instruction_khr >();
    case ktl::api::feature::color_write_enable_ext:
        return ktl::meta::feature_cast< ktl::api::feature::color_write_enable_ext >();
    case ktl::api::feature::synchronization_2:
        return ktl::meta::feature_cast< ktl::api::feature::synchronization_2 >();
    case ktl::api::feature::unified_image_layouts_khr:
        return ktl::meta::feature_cast< ktl::api::feature::unified_image_layouts_khr >();
    case ktl::api::feature::unified_image_layouts_video_khr:
        return ktl::meta::feature_cast< ktl::api::feature::unified_image_layouts_video_khr >();
    case ktl::api::feature::host_image_copy:
        return ktl::meta::feature_cast< ktl::api::feature::host_image_copy >();
    case ktl::api::feature::shader_atomic_instructions_10:
        return ktl::meta::feature_cast< ktl::api::feature::shader_atomic_instructions_10 >();
    case ktl::api::feature::primitives_generated_query_ext:
        return ktl::meta::feature_cast< ktl::api::feature::primitives_generated_query_ext >();
    case ktl::api::feature::primitives_generated_query_with_rasterizer_discard_ext:
        return ktl::meta::feature_cast< ktl::api::feature::primitives_generated_query_with_rasterizer_discard_ext >();
    case ktl::api::feature::primitives_generated_query_with_non_zero_streams_ext:
        return ktl::meta::feature_cast< ktl::api::feature::primitives_generated_query_with_non_zero_streams_ext >();
    case ktl::api::feature::legacy_dithering_ext:
        return ktl::meta::feature_cast< ktl::api::feature::legacy_dithering_ext >();
    case ktl::api::feature::multisampled_render_to_single_sampled_ext:
        return ktl::meta::feature_cast< ktl::api::feature::multisampled_render_to_single_sampled_ext >();
    case ktl::api::feature::pipeline_protected_access:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_protected_access >();
    case ktl::api::feature::inherited_viewport_scissor_2d_nv:
        return ktl::meta::feature_cast< ktl::api::feature::inherited_viewport_scissor_2d_nv >();
    case ktl::api::feature::ycbcr_2plane_444formats_ext:
        return ktl::meta::feature_cast< ktl::api::feature::ycbcr_2plane_444formats_ext >();
    case ktl::api::feature::provoking_vertex_last_ext:
        return ktl::meta::feature_cast< ktl::api::feature::provoking_vertex_last_ext >();
    case ktl::api::feature::transform_feedback_preserves_provoking_vertex_ext:
        return ktl::meta::feature_cast< ktl::api::feature::transform_feedback_preserves_provoking_vertex_ext >();
    case ktl::api::feature::descriptor_buffer_ext:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_buffer_ext >();
    case ktl::api::feature::descriptor_buffer_capture_replay_ext:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_buffer_capture_replay_ext >();
    case ktl::api::feature::descriptor_buffer_image_layout_ignored_ext:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_buffer_image_layout_ignored_ext >();
    case ktl::api::feature::descriptor_buffer_push_descriptors_ext:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_buffer_push_descriptors_ext >();
    case ktl::api::feature::shader_integer_dot_product:
        return ktl::meta::feature_cast< ktl::api::feature::shader_integer_dot_product >();
    case ktl::api::feature::fragment_shader_barycentric_khr:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_shader_barycentric_khr >();
    case ktl::api::feature::shader_fma_float_16khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_fma_float_16khr >();
    case ktl::api::feature::shader_fma_float_32khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_fma_float_32khr >();
    case ktl::api::feature::shader_fma_float_64khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_fma_float_64khr >();
    case ktl::api::feature::ray_tracing_motion_blur_nv:
        return ktl::meta::feature_cast< ktl::api::feature::ray_tracing_motion_blur_nv >();
    case ktl::api::feature::ray_tracing_motion_blur_pipeline_trace_rays_indirect_nv:
        return ktl::meta::feature_cast< ktl::api::feature::ray_tracing_motion_blur_pipeline_trace_rays_indirect_nv >();
    case ktl::api::feature::ray_tracing_validation_nv:
        return ktl::meta::feature_cast< ktl::api::feature::ray_tracing_validation_nv >();
    case ktl::api::feature::spheres_nv:
        return ktl::meta::feature_cast< ktl::api::feature::spheres_nv >();
    case ktl::api::feature::linear_swept_spheres_nv:
        return ktl::meta::feature_cast< ktl::api::feature::linear_swept_spheres_nv >();
    case ktl::api::feature::format_rgba_10x_6without_y_cb_cr_sampler_ext:
        return ktl::meta::feature_cast< ktl::api::feature::format_rgba_10x_6without_y_cb_cr_sampler_ext >();
    case ktl::api::feature::dynamic_rendering:
        return ktl::meta::feature_cast< ktl::api::feature::dynamic_rendering >();
    case ktl::api::feature::min_lod_ext:
        return ktl::meta::feature_cast< ktl::api::feature::min_lod_ext >();
    case ktl::api::feature::rasterization_order_color_attachment_access_ext:
        return ktl::meta::feature_cast< ktl::api::feature::rasterization_order_color_attachment_access_ext >();
    case ktl::api::feature::rasterization_order_depth_attachment_access_ext:
        return ktl::meta::feature_cast< ktl::api::feature::rasterization_order_depth_attachment_access_ext >();
    case ktl::api::feature::rasterization_order_stencil_attachment_access_ext:
        return ktl::meta::feature_cast< ktl::api::feature::rasterization_order_stencil_attachment_access_ext >();
    case ktl::api::feature::linear_color_attachment_nv:
        return ktl::meta::feature_cast< ktl::api::feature::linear_color_attachment_nv >();
    case ktl::api::feature::graphics_pipeline_library_ext:
        return ktl::meta::feature_cast< ktl::api::feature::graphics_pipeline_library_ext >();
    case ktl::api::feature::pipeline_binaries_khr:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_binaries_khr >();
    case ktl::api::feature::data_graph_neural_accelerator_statistics_arm:
        return ktl::meta::feature_cast< ktl::api::feature::data_graph_neural_accelerator_statistics_arm >();
    case ktl::api::feature::descriptor_set_host_mapping_valve:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_set_host_mapping_valve >();
    case ktl::api::feature::nested_command_buffer_ext:
        return ktl::meta::feature_cast< ktl::api::feature::nested_command_buffer_ext >();
    case ktl::api::feature::nested_command_buffer_rendering_ext:
        return ktl::meta::feature_cast< ktl::api::feature::nested_command_buffer_rendering_ext >();
    case ktl::api::feature::nested_command_buffer_simultaneous_use_ext:
        return ktl::meta::feature_cast< ktl::api::feature::nested_command_buffer_simultaneous_use_ext >();
    case ktl::api::feature::shader_module_identifier_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_module_identifier_ext >();
    case ktl::api::feature::image_compression_control_ext:
        return ktl::meta::feature_cast< ktl::api::feature::image_compression_control_ext >();
    case ktl::api::feature::image_compression_control_swapchain_ext:
        return ktl::meta::feature_cast< ktl::api::feature::image_compression_control_swapchain_ext >();
    case ktl::api::feature::subpass_merge_feedback_ext:
        return ktl::meta::feature_cast< ktl::api::feature::subpass_merge_feedback_ext >();
    case ktl::api::feature::micromap_khr:
        return ktl::meta::feature_cast< ktl::api::feature::micromap_khr >();
    case ktl::api::feature::micromap_ext:
        return ktl::meta::feature_cast< ktl::api::feature::micromap_ext >();
    case ktl::api::feature::micromap_capture_replay_ext:
        return ktl::meta::feature_cast< ktl::api::feature::micromap_capture_replay_ext >();
    case ktl::api::feature::micromap_host_commands_ext:
        return ktl::meta::feature_cast< ktl::api::feature::micromap_host_commands_ext >();
    case ktl::api::feature::displacement_micromap_nv:
        return ktl::meta::feature_cast< ktl::api::feature::displacement_micromap_nv >();
    case ktl::api::feature::pipeline_properties_identifier_ext:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_properties_identifier_ext >();
    case ktl::api::feature::shader_early_and_late_fragment_tests_amd:
        return ktl::meta::feature_cast< ktl::api::feature::shader_early_and_late_fragment_tests_amd >();
    case ktl::api::feature::non_seamless_cube_map_ext:
        return ktl::meta::feature_cast< ktl::api::feature::non_seamless_cube_map_ext >();
    case ktl::api::feature::pipeline_robustness:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_robustness >();
    case ktl::api::feature::shader_multiple_wait_queues_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::shader_multiple_wait_queues_qcom >();
    case ktl::api::feature::texture_sample_weighted_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::texture_sample_weighted_qcom >();
    case ktl::api::feature::texture_box_filter_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::texture_box_filter_qcom >();
    case ktl::api::feature::texture_block_match_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::texture_block_match_qcom >();
    case ktl::api::feature::tile_properties_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_properties_qcom >();
    case ktl::api::feature::amigo_profiling_sec:
        return ktl::meta::feature_cast< ktl::api::feature::amigo_profiling_sec >();
    case ktl::api::feature::attachment_feedback_loop_layout_ext:
        return ktl::meta::feature_cast< ktl::api::feature::attachment_feedback_loop_layout_ext >();
    case ktl::api::feature::report_address_binding_ext:
        return ktl::meta::feature_cast< ktl::api::feature::report_address_binding_ext >();
    case ktl::api::feature::optical_flow_nv:
        return ktl::meta::feature_cast< ktl::api::feature::optical_flow_nv >();
    case ktl::api::feature::device_fault_ext:
        return ktl::meta::feature_cast< ktl::api::feature::device_fault_ext >();
    case ktl::api::feature::device_fault_vendor_binary_ext:
        return ktl::meta::feature_cast< ktl::api::feature::device_fault_vendor_binary_ext >();
    case ktl::api::feature::device_fault_khr:
        return ktl::meta::feature_cast< ktl::api::feature::device_fault_khr >();
    case ktl::api::feature::device_fault_vendor_binary_khr:
        return ktl::meta::feature_cast< ktl::api::feature::device_fault_vendor_binary_khr >();
    case ktl::api::feature::device_fault_report_masked_khr:
        return ktl::meta::feature_cast< ktl::api::feature::device_fault_report_masked_khr >();
    case ktl::api::feature::device_fault_device_lost_on_masked_khr:
        return ktl::meta::feature_cast< ktl::api::feature::device_fault_device_lost_on_masked_khr >();
    case ktl::api::feature::pipeline_library_group_handles_ext:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_library_group_handles_ext >();
    case ktl::api::feature::shader_core_builtins_arm:
        return ktl::meta::feature_cast< ktl::api::feature::shader_core_builtins_arm >();
    case ktl::api::feature::frame_boundary_ext:
        return ktl::meta::feature_cast< ktl::api::feature::frame_boundary_ext >();
    case ktl::api::feature::dynamic_rendering_unused_attachments_ext:
        return ktl::meta::feature_cast< ktl::api::feature::dynamic_rendering_unused_attachments_ext >();
    case ktl::api::feature::internally_synchronized_queues_khr:
        return ktl::meta::feature_cast< ktl::api::feature::internally_synchronized_queues_khr >();
    case ktl::api::feature::swapchain_maintenance_1khr:
        return ktl::meta::feature_cast< ktl::api::feature::swapchain_maintenance_1khr >();
    case ktl::api::feature::depth_bias_control_ext:
        return ktl::meta::feature_cast< ktl::api::feature::depth_bias_control_ext >();
    case ktl::api::feature::least_representable_value_force_unorm_representation_ext:
        return ktl::meta::feature_cast< ktl::api::feature::least_representable_value_force_unorm_representation_ext >();
    case ktl::api::feature::float_representation_ext:
        return ktl::meta::feature_cast< ktl::api::feature::float_representation_ext >();
    case ktl::api::feature::depth_bias_exact_ext:
        return ktl::meta::feature_cast< ktl::api::feature::depth_bias_exact_ext >();
    case ktl::api::feature::ray_tracing_invocation_reorder_ext:
        return ktl::meta::feature_cast< ktl::api::feature::ray_tracing_invocation_reorder_ext >();
    case ktl::api::feature::ray_tracing_invocation_reorder_nv:
        return ktl::meta::feature_cast< ktl::api::feature::ray_tracing_invocation_reorder_nv >();
    case ktl::api::feature::extended_sparse_address_space_nv:
        return ktl::meta::feature_cast< ktl::api::feature::extended_sparse_address_space_nv >();
    case ktl::api::feature::multiview_per_view_viewports_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::multiview_per_view_viewports_qcom >();
    case ktl::api::feature::ray_tracing_position_fetch_khr:
        return ktl::meta::feature_cast< ktl::api::feature::ray_tracing_position_fetch_khr >();
    case ktl::api::feature::multiview_per_view_render_areas_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::multiview_per_view_render_areas_qcom >();
    case ktl::api::feature::shader_object_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_object_ext >();
    case ktl::api::feature::shader_tile_image_color_read_access_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_tile_image_color_read_access_ext >();
    case ktl::api::feature::shader_tile_image_depth_read_access_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_tile_image_depth_read_access_ext >();
    case ktl::api::feature::shader_tile_image_stencil_read_access_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_tile_image_stencil_read_access_ext >();
    case ktl::api::feature::screen_buffer_import_qnx:
        return ktl::meta::feature_cast< ktl::api::feature::screen_buffer_import_qnx >();
    case ktl::api::feature::cooperative_matrix_khr:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_khr >();
    case ktl::api::feature::cooperative_matrix_robust_buffer_access_khr:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_robust_buffer_access_khr >();
    case ktl::api::feature::cooperative_matrix_conversion_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_conversion_qcom >();
    case ktl::api::feature::shader_enqueue_amdx:
        return ktl::meta::feature_cast< ktl::api::feature::shader_enqueue_amdx >();
    case ktl::api::feature::shader_mesh_enqueue_amdx:
        return ktl::meta::feature_cast< ktl::api::feature::shader_mesh_enqueue_amdx >();
    case ktl::api::feature::anti_lag_amd:
        return ktl::meta::feature_cast< ktl::api::feature::anti_lag_amd >();
    case ktl::api::feature::tile_memory_heap_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_memory_heap_qcom >();
    case ktl::api::feature::cubic_range_clamp_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::cubic_range_clamp_qcom >();
    case ktl::api::feature::ycbcr_degamma_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::ycbcr_degamma_qcom >();
    case ktl::api::feature::selectable_cubic_weights_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::selectable_cubic_weights_qcom >();
    case ktl::api::feature::texture_block_match_2qcom:
        return ktl::meta::feature_cast< ktl::api::feature::texture_block_match_2qcom >();
    case ktl::api::feature::image_gather_linear_3qcom:
        return ktl::meta::feature_cast< ktl::api::feature::image_gather_linear_3qcom >();
    case ktl::api::feature::image_gather_extended_modes_3qcom:
        return ktl::meta::feature_cast< ktl::api::feature::image_gather_extended_modes_3qcom >();
    case ktl::api::feature::block_match_extended_clamp_to_edge_3qcom:
        return ktl::meta::feature_cast< ktl::api::feature::block_match_extended_clamp_to_edge_3qcom >();
    case ktl::api::feature::descriptor_pool_overallocation_nv:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_pool_overallocation_nv >();
    case ktl::api::feature::per_stage_descriptor_set_nv:
        return ktl::meta::feature_cast< ktl::api::feature::per_stage_descriptor_set_nv >();
    case ktl::api::feature::dynamic_pipeline_layout_nv:
        return ktl::meta::feature_cast< ktl::api::feature::dynamic_pipeline_layout_nv >();
    case ktl::api::feature::external_format_resolve_android:
        return ktl::meta::feature_cast< ktl::api::feature::external_format_resolve_android >();
    case ktl::api::feature::cuda_kernel_launch_features_nv:
        return ktl::meta::feature_cast< ktl::api::feature::cuda_kernel_launch_features_nv >();
    case ktl::api::feature::scheduling_controls_arm:
        return ktl::meta::feature_cast< ktl::api::feature::scheduling_controls_arm >();
    case ktl::api::feature::relaxed_line_rasterization_img:
        return ktl::meta::feature_cast< ktl::api::feature::relaxed_line_rasterization_img >();
    case ktl::api::feature::render_pass_striped_arm:
        return ktl::meta::feature_cast< ktl::api::feature::render_pass_striped_arm >();
    case ktl::api::feature::pipeline_opacity_micromap_arm:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_opacity_micromap_arm >();
    case ktl::api::feature::shader_maximal_reconvergence_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_maximal_reconvergence_khr >();
    case ktl::api::feature::shader_subgroup_rotate:
        return ktl::meta::feature_cast< ktl::api::feature::shader_subgroup_rotate >();
    case ktl::api::feature::shader_subgroup_rotate_clustered:
        return ktl::meta::feature_cast< ktl::api::feature::shader_subgroup_rotate_clustered >();
    case ktl::api::feature::shader_expect_assume:
        return ktl::meta::feature_cast< ktl::api::feature::shader_expect_assume >();
    case ktl::api::feature::shader_float_controls_2:
        return ktl::meta::feature_cast< ktl::api::feature::shader_float_controls_2 >();
    case ktl::api::feature::dynamic_rendering_local_read:
        return ktl::meta::feature_cast< ktl::api::feature::dynamic_rendering_local_read >();
    case ktl::api::feature::shader_quad_control_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_quad_control_khr >();
    case ktl::api::feature::shader_float_16vector_atomics_nv:
        return ktl::meta::feature_cast< ktl::api::feature::shader_float_16vector_atomics_nv >();
    case ktl::api::feature::memory_map_placed_ext:
        return ktl::meta::feature_cast< ktl::api::feature::memory_map_placed_ext >();
    case ktl::api::feature::memory_map_range_placed_ext:
        return ktl::meta::feature_cast< ktl::api::feature::memory_map_range_placed_ext >();
    case ktl::api::feature::memory_unmap_reserve_ext:
        return ktl::meta::feature_cast< ktl::api::feature::memory_unmap_reserve_ext >();
    case ktl::api::feature::shader_b_float_16type_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_b_float_16type_khr >();
    case ktl::api::feature::shader_b_float_16dot_product_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_b_float_16dot_product_khr >();
    case ktl::api::feature::shader_b_float_16cooperative_matrix_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_b_float_16cooperative_matrix_khr >();
    case ktl::api::feature::shader_raw_access_chains_nv:
        return ktl::meta::feature_cast< ktl::api::feature::shader_raw_access_chains_nv >();
    case ktl::api::feature::command_buffer_inheritance_nv:
        return ktl::meta::feature_cast< ktl::api::feature::command_buffer_inheritance_nv >();
    case ktl::api::feature::image_alignment_control_mesa:
        return ktl::meta::feature_cast< ktl::api::feature::image_alignment_control_mesa >();
    case ktl::api::feature::shader_replicated_composites_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_replicated_composites_ext >();
    case ktl::api::feature::present_mode_fifo_latest_ready_khr:
        return ktl::meta::feature_cast< ktl::api::feature::present_mode_fifo_latest_ready_khr >();
    case ktl::api::feature::cooperative_matrix_workgroup_scope_2nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_workgroup_scope_2nv >();
    case ktl::api::feature::cooperative_matrix_flexible_dimensions_2nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_flexible_dimensions_2nv >();
    case ktl::api::feature::cooperative_matrix_reductions_2nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_reductions_2nv >();
    case ktl::api::feature::cooperative_matrix_conversions_2nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_conversions_2nv >();
    case ktl::api::feature::cooperative_matrix_per_element_operations_2nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_per_element_operations_2nv >();
    case ktl::api::feature::cooperative_matrix_tensor_addressing_2nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_tensor_addressing_2nv >();
    case ktl::api::feature::cooperative_matrix_block_loads_2nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_block_loads_2nv >();
    case ktl::api::feature::cooperative_matrix_decode_vector_nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_matrix_decode_vector_nv >();
    case ktl::api::feature::hdr_vivid_huawei:
        return ktl::meta::feature_cast< ktl::api::feature::hdr_vivid_huawei >();
    case ktl::api::feature::vertex_attribute_robustness_ext:
        return ktl::meta::feature_cast< ktl::api::feature::vertex_attribute_robustness_ext >();
    case ktl::api::feature::dense_geometry_format_amdx:
        return ktl::meta::feature_cast< ktl::api::feature::dense_geometry_format_amdx >();
    case ktl::api::feature::depth_clamp_zero_one_khr:
        return ktl::meta::feature_cast< ktl::api::feature::depth_clamp_zero_one_khr >();
    case ktl::api::feature::cooperative_vector_nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_vector_nv >();
    case ktl::api::feature::cooperative_vector_training_nv:
        return ktl::meta::feature_cast< ktl::api::feature::cooperative_vector_training_nv >();
    case ktl::api::feature::tile_shading_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_qcom >();
    case ktl::api::feature::tile_shading_fragment_stage_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_fragment_stage_qcom >();
    case ktl::api::feature::tile_shading_color_attachments_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_color_attachments_qcom >();
    case ktl::api::feature::tile_shading_depth_attachments_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_depth_attachments_qcom >();
    case ktl::api::feature::tile_shading_stencil_attachments_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_stencil_attachments_qcom >();
    case ktl::api::feature::tile_shading_input_attachments_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_input_attachments_qcom >();
    case ktl::api::feature::tile_shading_sampled_attachments_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_sampled_attachments_qcom >();
    case ktl::api::feature::tile_shading_per_tile_draw_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_per_tile_draw_qcom >();
    case ktl::api::feature::tile_shading_per_tile_dispatch_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_per_tile_dispatch_qcom >();
    case ktl::api::feature::tile_shading_dispatch_tile_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_dispatch_tile_qcom >();
    case ktl::api::feature::tile_shading_apron_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_apron_qcom >();
    case ktl::api::feature::tile_shading_anisotropic_apron_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_anisotropic_apron_qcom >();
    case ktl::api::feature::tile_shading_atomic_ops_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_atomic_ops_qcom >();
    case ktl::api::feature::tile_shading_image_processing_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::tile_shading_image_processing_qcom >();
    case ktl::api::feature::fragment_density_map_layered_valve:
        return ktl::meta::feature_cast< ktl::api::feature::fragment_density_map_layered_valve >();
    case ktl::api::feature::present_metering_nv:
        return ktl::meta::feature_cast< ktl::api::feature::present_metering_nv >();
    case ktl::api::feature::shader_uniform_buffer_unsized_array_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_uniform_buffer_unsized_array_ext >();
    case ktl::api::feature::shader_mixed_float_dot_product_float_16acc_float_32valve:
        return ktl::meta::feature_cast< ktl::api::feature::shader_mixed_float_dot_product_float_16acc_float_32valve >();
    case ktl::api::feature::shader_mixed_float_dot_product_float_16acc_float_16valve:
        return ktl::meta::feature_cast< ktl::api::feature::shader_mixed_float_dot_product_float_16acc_float_16valve >();
    case ktl::api::feature::shader_mixed_float_dot_product_b_float_16acc_valve:
        return ktl::meta::feature_cast< ktl::api::feature::shader_mixed_float_dot_product_b_float_16acc_valve >();
    case ktl::api::feature::shader_mixed_float_dot_product_float_8acc_float_32valve:
        return ktl::meta::feature_cast< ktl::api::feature::shader_mixed_float_dot_product_float_8acc_float_32valve >();
    case ktl::api::feature::primitive_restart_index_ext:
        return ktl::meta::feature_cast< ktl::api::feature::primitive_restart_index_ext >();
    case ktl::api::feature::format_pack_arm:
        return ktl::meta::feature_cast< ktl::api::feature::format_pack_arm >();
    case ktl::api::feature::throttle_hint_sec:
        return ktl::meta::feature_cast< ktl::api::feature::throttle_hint_sec >();
    case ktl::api::feature::tensor_non_packed_arm:
        return ktl::meta::feature_cast< ktl::api::feature::tensor_non_packed_arm >();
    case ktl::api::feature::shader_tensor_access_arm:
        return ktl::meta::feature_cast< ktl::api::feature::shader_tensor_access_arm >();
    case ktl::api::feature::shader_storage_tensor_array_dynamic_indexing_arm:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_tensor_array_dynamic_indexing_arm >();
    case ktl::api::feature::shader_storage_tensor_array_non_uniform_indexing_arm:
        return ktl::meta::feature_cast< ktl::api::feature::shader_storage_tensor_array_non_uniform_indexing_arm >();
    case ktl::api::feature::descriptor_binding_storage_tensor_update_after_bind_arm:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_binding_storage_tensor_update_after_bind_arm >();
    case ktl::api::feature::tensors_arm:
        return ktl::meta::feature_cast< ktl::api::feature::tensors_arm >();
    case ktl::api::feature::descriptor_buffer_tensor_descriptors_arm:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_buffer_tensor_descriptors_arm >();
    case ktl::api::feature::shader_float_8ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_float_8ext >();
    case ktl::api::feature::shader_float_8cooperative_matrix_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_float_8cooperative_matrix_ext >();
    case ktl::api::feature::data_graph_arm:
        return ktl::meta::feature_cast< ktl::api::feature::data_graph_arm >();
    case ktl::api::feature::data_graph_update_after_bind_arm:
        return ktl::meta::feature_cast< ktl::api::feature::data_graph_update_after_bind_arm >();
    case ktl::api::feature::data_graph_specialization_constants_arm:
        return ktl::meta::feature_cast< ktl::api::feature::data_graph_specialization_constants_arm >();
    case ktl::api::feature::data_graph_descriptor_buffer_arm:
        return ktl::meta::feature_cast< ktl::api::feature::data_graph_descriptor_buffer_arm >();
    case ktl::api::feature::data_graph_shader_module_arm:
        return ktl::meta::feature_cast< ktl::api::feature::data_graph_shader_module_arm >();
    case ktl::api::feature::pipeline_cache_incremental_mode_sec:
        return ktl::meta::feature_cast< ktl::api::feature::pipeline_cache_incremental_mode_sec >();
    case ktl::api::feature::data_graph_model_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::data_graph_model_qcom >();
    case ktl::api::feature::shader_untyped_pointers_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_untyped_pointers_khr >();
    case ktl::api::feature::shader_64bit_indexing_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_64bit_indexing_ext >();
    case ktl::api::feature::queue_perf_hint_qcom:
        return ktl::meta::feature_cast< ktl::api::feature::queue_perf_hint_qcom >();
    case ktl::api::feature::performance_counters_by_region_arm:
        return ktl::meta::feature_cast< ktl::api::feature::performance_counters_by_region_arm >();
    case ktl::api::feature::compute_occupancy_priority_nv:
        return ktl::meta::feature_cast< ktl::api::feature::compute_occupancy_priority_nv >();
    case ktl::api::feature::long_vector_ext:
        return ktl::meta::feature_cast< ktl::api::feature::long_vector_ext >();
    case ktl::api::feature::texture_compression_astc_3d_ext:
        return ktl::meta::feature_cast< ktl::api::feature::texture_compression_astc_3d_ext >();
    case ktl::api::feature::shader_subgroup_partitioned_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_subgroup_partitioned_ext >();
    case ktl::api::feature::shader_split_barrier_ext:
        return ktl::meta::feature_cast< ktl::api::feature::shader_split_barrier_ext >();
    case ktl::api::feature::descriptor_heap_ext:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_heap_ext >();
    case ktl::api::feature::descriptor_heap_capture_replay_ext:
        return ktl::meta::feature_cast< ktl::api::feature::descriptor_heap_capture_replay_ext >();
    case ktl::api::feature::shader_instrumentation_arm:
        return ktl::meta::feature_cast< ktl::api::feature::shader_instrumentation_arm >();
    case ktl::api::feature::device_address_commands_khr:
        return ktl::meta::feature_cast< ktl::api::feature::device_address_commands_khr >();
    case ktl::api::feature::shader_constant_data_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_constant_data_khr >();
    case ktl::api::feature::shader_abort_khr:
        return ktl::meta::feature_cast< ktl::api::feature::shader_abort_khr >();
    case ktl::api::feature::data_graph_optical_flow_arm:
        return ktl::meta::feature_cast< ktl::api::feature::data_graph_optical_flow_arm >();
    }
}
} // namespace ktl::meta
#endif
