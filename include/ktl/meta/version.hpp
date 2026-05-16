#ifndef KTL_META_VERSION_HPP
#define KTL_META_VERSION_HPP

#include <array>

#include <ktl/api.hpp>
#include <ktl/api/version.hpp>


namespace ktl::meta
{
template < ktl::api::version >
struct version
{
};

template <>
struct version< ktl::api::version_1_0 >
{
    static constexpr std::array< ktl::api::command, 137 > commands = {
ktl::api::command::create_instance,ktl::api::command::destroy_instance,ktl::api::command::enumerate_physical_devices,ktl::api::command::get_physical_device_features,ktl::api::command::get_physical_device_format_properties,ktl::api::command::get_physical_device_image_format_properties,ktl::api::command::get_physical_device_properties,ktl::api::command::get_physical_device_queue_family_properties,ktl::api::command::get_physical_device_memory_properties,ktl::api::command::get_instance_proc_addr,ktl::api::command::get_device_proc_addr,ktl::api::command::create_device,ktl::api::command::destroy_device,ktl::api::command::enumerate_instance_extension_properties,ktl::api::command::enumerate_device_extension_properties,ktl::api::command::enumerate_instance_layer_properties,ktl::api::command::enumerate_device_layer_properties,ktl::api::command::get_device_queue,ktl::api::command::queue_submit,ktl::api::command::queue_wait_idle,ktl::api::command::device_wait_idle,ktl::api::command::allocate_memory,ktl::api::command::free_memory,ktl::api::command::map_memory,ktl::api::command::unmap_memory,ktl::api::command::flush_mapped_memory_ranges,ktl::api::command::invalidate_mapped_memory_ranges,ktl::api::command::get_device_memory_commitment,ktl::api::command::bind_buffer_memory,ktl::api::command::bind_image_memory,ktl::api::command::get_buffer_memory_requirements,ktl::api::command::get_image_memory_requirements,ktl::api::command::get_image_sparse_memory_requirements,ktl::api::command::get_physical_device_sparse_image_format_properties,ktl::api::command::queue_bind_sparse,ktl::api::command::create_fence,ktl::api::command::destroy_fence,ktl::api::command::reset_fences,ktl::api::command::get_fence_status,ktl::api::command::wait_for_fences,ktl::api::command::create_semaphore,ktl::api::command::destroy_semaphore,ktl::api::command::create_query_pool,ktl::api::command::destroy_query_pool,ktl::api::command::get_query_pool_results,ktl::api::command::create_buffer,ktl::api::command::destroy_buffer,ktl::api::command::create_image,ktl::api::command::destroy_image,ktl::api::command::get_image_subresource_layout,ktl::api::command::create_image_view,ktl::api::command::destroy_image_view,ktl::api::command::create_command_pool,ktl::api::command::destroy_command_pool,ktl::api::command::reset_command_pool,ktl::api::command::allocate_command_buffers,ktl::api::command::free_command_buffers,ktl::api::command::begin_command_buffer,ktl::api::command::end_command_buffer,ktl::api::command::reset_command_buffer,ktl::api::command::cmd_copy_buffer,ktl::api::command::cmd_copy_image,ktl::api::command::cmd_copy_buffer_to_image,ktl::api::command::cmd_copy_image_to_buffer,ktl::api::command::cmd_update_buffer,ktl::api::command::cmd_fill_buffer,ktl::api::command::cmd_pipeline_barrier,ktl::api::command::cmd_begin_query,ktl::api::command::cmd_end_query,ktl::api::command::cmd_reset_query_pool,ktl::api::command::cmd_write_timestamp,ktl::api::command::cmd_copy_query_pool_results,ktl::api::command::cmd_execute_commands,ktl::api::command::create_event,ktl::api::command::destroy_event,ktl::api::command::get_event_status,ktl::api::command::set_event,ktl::api::command::reset_event,ktl::api::command::create_buffer_view,ktl::api::command::destroy_buffer_view,ktl::api::command::create_shader_module,ktl::api::command::destroy_shader_module,ktl::api::command::create_pipeline_cache,ktl::api::command::destroy_pipeline_cache,ktl::api::command::get_pipeline_cache_data,ktl::api::command::merge_pipeline_caches,ktl::api::command::create_compute_pipelines,ktl::api::command::destroy_pipeline,ktl::api::command::create_pipeline_layout,ktl::api::command::destroy_pipeline_layout,ktl::api::command::create_sampler,ktl::api::command::destroy_sampler,ktl::api::command::create_descriptor_set_layout,ktl::api::command::destroy_descriptor_set_layout,ktl::api::command::create_descriptor_pool,ktl::api::command::destroy_descriptor_pool,ktl::api::command::reset_descriptor_pool,ktl::api::command::allocate_descriptor_sets,ktl::api::command::free_descriptor_sets,ktl::api::command::update_descriptor_sets,ktl::api::command::cmd_bind_pipeline,ktl::api::command::cmd_bind_descriptor_sets,ktl::api::command::cmd_clear_color_image,ktl::api::command::cmd_dispatch,ktl::api::command::cmd_dispatch_indirect,ktl::api::command::cmd_set_event,ktl::api::command::cmd_reset_event,ktl::api::command::cmd_wait_events,ktl::api::command::cmd_push_constants,ktl::api::command::create_graphics_pipelines,ktl::api::command::create_framebuffer,ktl::api::command::destroy_framebuffer,ktl::api::command::create_render_pass,ktl::api::command::destroy_render_pass,ktl::api::command::get_render_area_granularity,ktl::api::command::cmd_set_viewport,ktl::api::command::cmd_set_scissor,ktl::api::command::cmd_set_line_width,ktl::api::command::cmd_set_depth_bias,ktl::api::command::cmd_set_blend_constants,ktl::api::command::cmd_set_depth_bounds,ktl::api::command::cmd_set_stencil_compare_mask,ktl::api::command::cmd_set_stencil_write_mask,ktl::api::command::cmd_set_stencil_reference,ktl::api::command::cmd_bind_index_buffer,ktl::api::command::cmd_bind_vertex_buffers,ktl::api::command::cmd_draw,ktl::api::command::cmd_draw_indexed,ktl::api::command::cmd_draw_indirect,ktl::api::command::cmd_draw_indexed_indirect,ktl::api::command::cmd_blit_image,ktl::api::command::cmd_clear_depth_stencil_image,ktl::api::command::cmd_clear_attachments,ktl::api::command::cmd_resolve_image,ktl::api::command::cmd_begin_render_pass,ktl::api::command::cmd_next_subpass,ktl::api::command::cmd_end_render_pass};};

template <>
struct version< ktl::api::version_1_1 >
{
    static constexpr std::array< ktl::api::command, 28 > commands = {
ktl::api::command::enumerate_instance_version,ktl::api::command::bind_buffer_memory_2,ktl::api::command::bind_image_memory_2,ktl::api::command::get_device_group_peer_memory_features,ktl::api::command::cmd_set_device_mask,ktl::api::command::enumerate_physical_device_groups,ktl::api::command::get_image_memory_requirements_2,ktl::api::command::get_buffer_memory_requirements_2,ktl::api::command::get_image_sparse_memory_requirements_2,ktl::api::command::get_physical_device_features_2,ktl::api::command::get_physical_device_properties_2,ktl::api::command::get_physical_device_format_properties_2,ktl::api::command::get_physical_device_image_format_properties_2,ktl::api::command::get_physical_device_queue_family_properties_2,ktl::api::command::get_physical_device_memory_properties_2,ktl::api::command::get_physical_device_sparse_image_format_properties_2,ktl::api::command::trim_command_pool,ktl::api::command::get_device_queue_2,ktl::api::command::get_physical_device_external_buffer_properties,ktl::api::command::get_physical_device_external_fence_properties,ktl::api::command::get_physical_device_external_semaphore_properties,ktl::api::command::cmd_dispatch_base,ktl::api::command::create_descriptor_update_template,ktl::api::command::destroy_descriptor_update_template,ktl::api::command::update_descriptor_set_with_template,ktl::api::command::get_descriptor_set_layout_support,ktl::api::command::create_sampler_ycbcr_conversion,ktl::api::command::destroy_sampler_ycbcr_conversion};};

template <>
struct version< ktl::api::version_1_2 >
{
    static constexpr std::array< ktl::api::command, 13 > commands = {
ktl::api::command::reset_query_pool,ktl::api::command::get_semaphore_counter_value,ktl::api::command::wait_semaphores,ktl::api::command::signal_semaphore,ktl::api::command::get_buffer_device_address,ktl::api::command::get_buffer_opaque_capture_address,ktl::api::command::get_device_memory_opaque_capture_address,ktl::api::command::cmd_draw_indirect_count,ktl::api::command::cmd_draw_indexed_indirect_count,ktl::api::command::create_render_pass_2,ktl::api::command::cmd_begin_render_pass_2,ktl::api::command::cmd_next_subpass_2,ktl::api::command::cmd_end_render_pass_2};};

template <>
struct version< ktl::api::version_1_3 >
{
    static constexpr std::array< ktl::api::command, 37 > commands = {
ktl::api::command::get_physical_device_tool_properties,ktl::api::command::create_private_data_slot,ktl::api::command::destroy_private_data_slot,ktl::api::command::set_private_data,ktl::api::command::get_private_data,ktl::api::command::cmd_pipeline_barrier_2,ktl::api::command::cmd_write_timestamp_2,ktl::api::command::queue_submit_2,ktl::api::command::cmd_copy_buffer_2,ktl::api::command::cmd_copy_image_2,ktl::api::command::cmd_copy_buffer_to_image_2,ktl::api::command::cmd_copy_image_to_buffer_2,ktl::api::command::get_device_buffer_memory_requirements,ktl::api::command::get_device_image_memory_requirements,ktl::api::command::get_device_image_sparse_memory_requirements,ktl::api::command::cmd_set_event_2,ktl::api::command::cmd_reset_event_2,ktl::api::command::cmd_wait_events_2,ktl::api::command::cmd_blit_image_2,ktl::api::command::cmd_resolve_image_2,ktl::api::command::cmd_begin_rendering,ktl::api::command::cmd_end_rendering,ktl::api::command::cmd_set_cull_mode,ktl::api::command::cmd_set_front_face,ktl::api::command::cmd_set_primitive_topology,ktl::api::command::cmd_set_viewport_with_count,ktl::api::command::cmd_set_scissor_with_count,ktl::api::command::cmd_bind_vertex_buffers_2,ktl::api::command::cmd_set_depth_test_enable,ktl::api::command::cmd_set_depth_write_enable,ktl::api::command::cmd_set_depth_compare_op,ktl::api::command::cmd_set_depth_bounds_test_enable,ktl::api::command::cmd_set_stencil_test_enable,ktl::api::command::cmd_set_stencil_op,ktl::api::command::cmd_set_rasterizer_discard_enable,ktl::api::command::cmd_set_depth_bias_enable,ktl::api::command::cmd_set_primitive_restart_enable};};

template <>
struct version< ktl::api::version_1_4 >
{
    static constexpr std::array< ktl::api::command, 19 > commands = {
ktl::api::command::map_memory_2,ktl::api::command::unmap_memory_2,ktl::api::command::get_device_image_subresource_layout,ktl::api::command::get_image_subresource_layout_2,ktl::api::command::copy_memory_to_image,ktl::api::command::copy_image_to_memory,ktl::api::command::copy_image_to_image,ktl::api::command::transition_image_layout,ktl::api::command::cmd_push_descriptor_set,ktl::api::command::cmd_push_descriptor_set_with_template,ktl::api::command::cmd_bind_descriptor_sets_2,ktl::api::command::cmd_push_constants_2,ktl::api::command::cmd_push_descriptor_set_2,ktl::api::command::cmd_push_descriptor_set_with_template_2,ktl::api::command::cmd_set_line_stipple,ktl::api::command::cmd_bind_index_buffer_2,ktl::api::command::get_rendering_area_granularity,ktl::api::command::cmd_set_rendering_attachment_locations,ktl::api::command::cmd_set_rendering_input_attachment_indices};};

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
}
#endif
