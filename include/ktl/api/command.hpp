#ifndef KTL_API_COMMAND_HPP
#define KTL_API_COMMAND_HPP

#include <array>

#include <ktl/loader.hpp>
#include <ktl/api.hpp>


namespace ktl::api
{
static constexpr ktl::usize pfn_table_size = 841;
using pfn_table = std::array< ktl::loader::proc_type, pfn_table_size >;
inline thread_local pfn_table * ptable = nullptr;           

enum class command : ktl::u32
{
create_instance = 0,
destroy_instance = 1,
enumerate_physical_devices = 2,
get_device_proc_addr = 3,
get_instance_proc_addr = 4,
get_physical_device_properties = 5,
get_physical_device_queue_family_properties = 6,
get_physical_device_memory_properties = 7,
get_physical_device_features = 8,
get_physical_device_format_properties = 9,
get_physical_device_image_format_properties = 10,
create_device = 11,
destroy_device = 12,
enumerate_instance_version = 13,
enumerate_instance_layer_properties = 14,
enumerate_instance_extension_properties = 15,
enumerate_device_layer_properties = 16,
enumerate_device_extension_properties = 17,
get_device_queue = 18,
queue_submit = 19,
queue_wait_idle = 20,
device_wait_idle = 21,
allocate_memory = 22,
free_memory = 23,
map_memory = 24,
unmap_memory = 25,
flush_mapped_memory_ranges = 26,
invalidate_mapped_memory_ranges = 27,
get_device_memory_commitment = 28,
get_buffer_memory_requirements = 29,
bind_buffer_memory = 30,
get_image_memory_requirements = 31,
bind_image_memory = 32,
get_image_sparse_memory_requirements = 33,
get_physical_device_sparse_image_format_properties = 34,
queue_bind_sparse = 35,
create_fence = 36,
destroy_fence = 37,
reset_fences = 38,
get_fence_status = 39,
wait_for_fences = 40,
create_semaphore = 41,
destroy_semaphore = 42,
create_event = 43,
destroy_event = 44,
get_event_status = 45,
set_event = 46,
reset_event = 47,
create_query_pool = 48,
destroy_query_pool = 49,
get_query_pool_results = 50,
reset_query_pool = 51,
reset_query_pool_ext = reset_query_pool,
create_buffer = 53,
destroy_buffer = 54,
create_buffer_view = 55,
destroy_buffer_view = 56,
create_image = 57,
destroy_image = 58,
get_image_subresource_layout = 59,
create_image_view = 60,
destroy_image_view = 61,
create_shader_module = 62,
destroy_shader_module = 63,
create_pipeline_cache = 64,
destroy_pipeline_cache = 65,
get_pipeline_cache_data = 66,
merge_pipeline_caches = 67,
create_pipeline_binaries_khr = 68,
destroy_pipeline_binary_khr = 69,
get_pipeline_key_khr = 70,
get_pipeline_binary_data_khr = 71,
release_captured_pipeline_data_khr = 72,
create_graphics_pipelines = 73,
create_compute_pipelines = 74,
get_device_subpass_shading_max_workgroup_size_huawei = 75,
destroy_pipeline = 76,
create_pipeline_layout = 77,
destroy_pipeline_layout = 78,
create_sampler = 79,
destroy_sampler = 80,
create_descriptor_set_layout = 81,
destroy_descriptor_set_layout = 82,
create_descriptor_pool = 83,
destroy_descriptor_pool = 84,
reset_descriptor_pool = 85,
allocate_descriptor_sets = 86,
free_descriptor_sets = 87,
update_descriptor_sets = 88,
create_framebuffer = 89,
destroy_framebuffer = 90,
create_render_pass = 91,
destroy_render_pass = 92,
get_render_area_granularity = 93,
get_rendering_area_granularity = 94,
get_rendering_area_granularity_khr = get_rendering_area_granularity,
create_command_pool = 96,
destroy_command_pool = 97,
reset_command_pool = 98,
allocate_command_buffers = 99,
free_command_buffers = 100,
begin_command_buffer = 101,
end_command_buffer = 102,
reset_command_buffer = 103,
cmd_bind_pipeline = 104,
cmd_set_primitive_restart_index_ext = 105,
cmd_set_attachment_feedback_loop_enable_ext = 106,
cmd_set_viewport = 107,
cmd_set_scissor = 108,
cmd_set_line_width = 109,
cmd_set_depth_bias = 110,
cmd_set_blend_constants = 111,
cmd_set_depth_bounds = 112,
cmd_set_stencil_compare_mask = 113,
cmd_set_stencil_write_mask = 114,
cmd_set_stencil_reference = 115,
cmd_bind_descriptor_sets = 116,
cmd_bind_index_buffer = 117,
cmd_bind_vertex_buffers = 118,
cmd_draw = 119,
cmd_draw_indexed = 120,
cmd_draw_multi_ext = 121,
cmd_draw_multi_indexed_ext = 122,
cmd_draw_indirect = 123,
cmd_draw_indexed_indirect = 124,
cmd_dispatch = 125,
cmd_dispatch_indirect = 126,
cmd_subpass_shading_huawei = 127,
cmd_draw_cluster_huawei = 128,
cmd_draw_cluster_indirect_huawei = 129,
cmd_update_pipeline_indirect_buffer_nv = 130,
cmd_copy_buffer = 131,
cmd_copy_image = 132,
cmd_blit_image = 133,
cmd_copy_buffer_to_image = 134,
cmd_copy_image_to_buffer = 135,
cmd_copy_memory_indirect_nv = 136,
cmd_copy_memory_indirect_khr = 137,
cmd_copy_memory_to_image_indirect_nv = 138,
cmd_copy_memory_to_image_indirect_khr = 139,
cmd_update_buffer = 140,
cmd_fill_buffer = 141,
cmd_clear_color_image = 142,
cmd_clear_depth_stencil_image = 143,
cmd_clear_attachments = 144,
cmd_resolve_image = 145,
cmd_set_event = 146,
cmd_reset_event = 147,
cmd_wait_events = 148,
cmd_pipeline_barrier = 149,
cmd_begin_query = 150,
cmd_end_query = 151,
cmd_begin_conditional_rendering_ext = 152,
cmd_end_conditional_rendering_ext = 153,
cmd_begin_custom_resolve_ext = 154,
cmd_reset_query_pool = 155,
cmd_write_timestamp = 156,
cmd_copy_query_pool_results = 157,
cmd_push_constants = 158,
cmd_begin_render_pass = 159,
cmd_next_subpass = 160,
cmd_end_render_pass = 161,
cmd_execute_commands = 162,
create_android_surface_khr = 163,
create_surface_ohos = 164,
get_physical_device_display_properties_khr = 165,
get_physical_device_display_plane_properties_khr = 166,
get_display_plane_supported_displays_khr = 167,
get_display_mode_properties_khr = 168,
create_display_mode_khr = 169,
get_display_plane_capabilities_khr = 170,
create_display_plane_surface_khr = 171,
create_shared_swapchains_khr = 172,
destroy_surface_khr = 173,
get_physical_device_surface_support_khr = 174,
get_physical_device_surface_capabilities_khr = 175,
get_physical_device_surface_formats_khr = 176,
get_physical_device_surface_present_modes_khr = 177,
create_swapchain_khr = 178,
destroy_swapchain_khr = 179,
get_swapchain_images_khr = 180,
acquire_next_image_khr = 181,
queue_present_khr = 182,
create_vi_surface_nn = 183,
create_wayland_surface_khr = 184,
get_physical_device_wayland_presentation_support_khr = 185,
create_ubm_surface_sec = 186,
get_physical_device_ubm_presentation_support_sec = 187,
create_win_32surface_khr = 188,
get_physical_device_win_32presentation_support_khr = 189,
create_xlib_surface_khr = 190,
get_physical_device_xlib_presentation_support_khr = 191,
create_xcb_surface_khr = 192,
get_physical_device_xcb_presentation_support_khr = 193,
create_direct_fb_surface_ext = 194,
get_physical_device_direct_fb_presentation_support_ext = 195,
create_image_pipe_surface_fuchsia = 196,
create_stream_descriptor_surface_ggp = 197,
create_screen_surface_qnx = 198,
get_physical_device_screen_presentation_support_qnx = 199,
create_debug_report_callback_ext = 200,
destroy_debug_report_callback_ext = 201,
debug_report_message_ext = 202,
debug_marker_set_object_name_ext = 203,
debug_marker_set_object_tag_ext = 204,
cmd_debug_marker_begin_ext = 205,
cmd_debug_marker_end_ext = 206,
cmd_debug_marker_insert_ext = 207,
get_physical_device_external_image_format_properties_nv = 208,
get_memory_win_32handle_nv = 209,
cmd_execute_generated_commands_nv = 210,
cmd_preprocess_generated_commands_nv = 211,
cmd_bind_pipeline_shader_group_nv = 212,
get_generated_commands_memory_requirements_nv = 213,
create_indirect_commands_layout_nv = 214,
destroy_indirect_commands_layout_nv = 215,
cmd_execute_generated_commands_ext = 216,
cmd_preprocess_generated_commands_ext = 217,
get_generated_commands_memory_requirements_ext = 218,
create_indirect_commands_layout_ext = 219,
destroy_indirect_commands_layout_ext = 220,
create_indirect_execution_set_ext = 221,
destroy_indirect_execution_set_ext = 222,
update_indirect_execution_set_pipeline_ext = 223,
update_indirect_execution_set_shader_ext = 224,
get_physical_device_features_2 = 225,
get_physical_device_features_2khr = get_physical_device_features_2,
get_physical_device_properties_2 = 227,
get_physical_device_properties_2khr = get_physical_device_properties_2,
get_physical_device_format_properties_2 = 229,
get_physical_device_format_properties_2khr = get_physical_device_format_properties_2,
get_physical_device_image_format_properties_2 = 231,
get_physical_device_image_format_properties_2khr = get_physical_device_image_format_properties_2,
get_physical_device_queue_family_properties_2 = 233,
get_physical_device_queue_family_properties_2khr = get_physical_device_queue_family_properties_2,
get_physical_device_memory_properties_2 = 235,
get_physical_device_memory_properties_2khr = get_physical_device_memory_properties_2,
get_physical_device_sparse_image_format_properties_2 = 237,
get_physical_device_sparse_image_format_properties_2khr = get_physical_device_sparse_image_format_properties_2,
cmd_push_descriptor_set = 239,
cmd_push_descriptor_set_khr = cmd_push_descriptor_set,
trim_command_pool = 241,
trim_command_pool_khr = trim_command_pool,
get_physical_device_external_buffer_properties = 243,
get_physical_device_external_buffer_properties_khr = get_physical_device_external_buffer_properties,
get_memory_win_32handle_khr = 245,
get_memory_win_32handle_properties_khr = 246,
get_memory_fd_khr = 247,
get_memory_fd_properties_khr = 248,
get_memory_zircon_handle_fuchsia = 249,
get_memory_zircon_handle_properties_fuchsia = 250,
get_memory_remote_address_nv = 251,
get_memory_sci_buf_nv = 252,
get_physical_device_external_memory_sci_buf_properties_nv = 253,
get_physical_device_sci_buf_attributes_nv = 254,
get_physical_device_external_semaphore_properties = 255,
get_physical_device_external_semaphore_properties_khr = get_physical_device_external_semaphore_properties,
get_semaphore_win_32handle_khr = 257,
import_semaphore_win_32handle_khr = 258,
get_semaphore_fd_khr = 259,
import_semaphore_fd_khr = 260,
get_semaphore_zircon_handle_fuchsia = 261,
import_semaphore_zircon_handle_fuchsia = 262,
get_physical_device_external_fence_properties = 263,
get_physical_device_external_fence_properties_khr = get_physical_device_external_fence_properties,
get_fence_win_32handle_khr = 265,
import_fence_win_32handle_khr = 266,
get_fence_fd_khr = 267,
import_fence_fd_khr = 268,
get_fence_sci_sync_fence_nv = 269,
get_fence_sci_sync_obj_nv = 270,
import_fence_sci_sync_fence_nv = 271,
import_fence_sci_sync_obj_nv = 272,
get_semaphore_sci_sync_obj_nv = 273,
import_semaphore_sci_sync_obj_nv = 274,
get_physical_device_sci_sync_attributes_nv = 275,
create_semaphore_sci_sync_pool_nv = 276,
destroy_semaphore_sci_sync_pool_nv = 277,
release_display_ext = 278,
acquire_xlib_display_ext = 279,
get_rand_r_output_display_ext = 280,
acquire_winrt_display_nv = 281,
get_winrt_display_nv = 282,
display_power_control_ext = 283,
register_device_event_ext = 284,
register_display_event_ext = 285,
get_swapchain_counter_ext = 286,
get_physical_device_surface_capabilities_2ext = 287,
enumerate_physical_device_groups = 288,
enumerate_physical_device_groups_khr = enumerate_physical_device_groups,
get_device_group_peer_memory_features = 290,
get_device_group_peer_memory_features_khr = get_device_group_peer_memory_features,
bind_buffer_memory_2 = 292,
bind_buffer_memory_2khr = bind_buffer_memory_2,
bind_image_memory_2 = 294,
bind_image_memory_2khr = bind_image_memory_2,
cmd_set_device_mask = 296,
cmd_set_device_mask_khr = cmd_set_device_mask,
get_device_group_present_capabilities_khr = 298,
get_device_group_surface_present_modes_khr = 299,
acquire_next_image_2khr = 300,
cmd_dispatch_base = 301,
cmd_dispatch_base_khr = cmd_dispatch_base,
get_physical_device_present_rectangles_khr = 303,
create_descriptor_update_template = 304,
create_descriptor_update_template_khr = create_descriptor_update_template,
destroy_descriptor_update_template = 306,
destroy_descriptor_update_template_khr = destroy_descriptor_update_template,
update_descriptor_set_with_template = 308,
update_descriptor_set_with_template_khr = update_descriptor_set_with_template,
cmd_push_descriptor_set_with_template = 310,
cmd_push_descriptor_set_with_template_khr = cmd_push_descriptor_set_with_template,
set_hdr_metadata_ext = 312,
get_swapchain_status_khr = 313,
get_refresh_cycle_duration_google = 314,
get_past_presentation_timing_google = 315,
create_ios_surface_mvk = 316,
create_mac_os_surface_mvk = 317,
create_metal_surface_ext = 318,
cmd_set_viewport_w_scaling_nv = 319,
cmd_set_discard_rectangle_ext = 320,
cmd_set_discard_rectangle_enable_ext = 321,
cmd_set_discard_rectangle_mode_ext = 322,
cmd_set_sample_locations_ext = 323,
get_physical_device_multisample_properties_ext = 324,
get_physical_device_surface_capabilities_2khr = 325,
get_physical_device_surface_formats_2khr = 326,
get_physical_device_display_properties_2khr = 327,
get_physical_device_display_plane_properties_2khr = 328,
get_display_mode_properties_2khr = 329,
get_display_plane_capabilities_2khr = 330,
get_buffer_memory_requirements_2 = 331,
get_buffer_memory_requirements_2khr = get_buffer_memory_requirements_2,
get_image_memory_requirements_2 = 333,
get_image_memory_requirements_2khr = get_image_memory_requirements_2,
get_image_sparse_memory_requirements_2 = 335,
get_image_sparse_memory_requirements_2khr = get_image_sparse_memory_requirements_2,
get_device_buffer_memory_requirements = 337,
get_device_buffer_memory_requirements_khr = get_device_buffer_memory_requirements,
get_device_image_memory_requirements = 339,
get_device_image_memory_requirements_khr = get_device_image_memory_requirements,
get_device_image_sparse_memory_requirements = 341,
get_device_image_sparse_memory_requirements_khr = get_device_image_sparse_memory_requirements,
create_sampler_ycbcr_conversion = 343,
create_sampler_ycbcr_conversion_khr = create_sampler_ycbcr_conversion,
destroy_sampler_ycbcr_conversion = 345,
destroy_sampler_ycbcr_conversion_khr = destroy_sampler_ycbcr_conversion,
get_device_queue_2 = 347,
create_validation_cache_ext = 348,
destroy_validation_cache_ext = 349,
get_validation_cache_data_ext = 350,
merge_validation_caches_ext = 351,
get_descriptor_set_layout_support = 352,
get_descriptor_set_layout_support_khr = get_descriptor_set_layout_support,
get_swapchain_gralloc_usage_android = 354,
get_swapchain_gralloc_usage_2android = 355,
acquire_image_android = 356,
queue_signal_release_image_android = 357,
get_shader_info_amd = 358,
set_local_dimming_amd = 359,
get_physical_device_calibrateable_time_domains_khr = 360,
get_physical_device_calibrateable_time_domains_ext = get_physical_device_calibrateable_time_domains_khr,
get_calibrated_timestamps_khr = 362,
get_calibrated_timestamps_ext = get_calibrated_timestamps_khr,
set_debug_utils_object_name_ext = 364,
set_debug_utils_object_tag_ext = 365,
queue_begin_debug_utils_label_ext = 366,
queue_end_debug_utils_label_ext = 367,
queue_insert_debug_utils_label_ext = 368,
cmd_begin_debug_utils_label_ext = 369,
cmd_end_debug_utils_label_ext = 370,
cmd_insert_debug_utils_label_ext = 371,
create_debug_utils_messenger_ext = 372,
destroy_debug_utils_messenger_ext = 373,
submit_debug_utils_message_ext = 374,
get_memory_host_pointer_properties_ext = 375,
cmd_write_buffer_marker_amd = 376,
create_render_pass_2 = 377,
create_render_pass_2khr = create_render_pass_2,
cmd_begin_render_pass_2 = 379,
cmd_begin_render_pass_2khr = cmd_begin_render_pass_2,
cmd_next_subpass_2 = 381,
cmd_next_subpass_2khr = cmd_next_subpass_2,
cmd_end_render_pass_2 = 383,
cmd_end_render_pass_2khr = cmd_end_render_pass_2,
get_semaphore_counter_value = 385,
get_semaphore_counter_value_khr = get_semaphore_counter_value,
wait_semaphores = 387,
wait_semaphores_khr = wait_semaphores,
signal_semaphore = 389,
signal_semaphore_khr = signal_semaphore,
get_android_hardware_buffer_properties_android = 391,
get_memory_android_hardware_buffer_android = 392,
cmd_draw_indirect_count = 393,
cmd_draw_indirect_count_khr = cmd_draw_indirect_count,
cmd_draw_indirect_count_amd = cmd_draw_indirect_count,
cmd_draw_indexed_indirect_count = 396,
cmd_draw_indexed_indirect_count_khr = cmd_draw_indexed_indirect_count,
cmd_draw_indexed_indirect_count_amd = cmd_draw_indexed_indirect_count,
cmd_set_checkpoint_nv = 399,
get_queue_checkpoint_data_nv = 400,
cmd_bind_transform_feedback_buffers_ext = 401,
cmd_begin_transform_feedback_ext = 402,
cmd_end_transform_feedback_ext = 403,
cmd_begin_query_indexed_ext = 404,
cmd_end_query_indexed_ext = 405,
cmd_draw_indirect_byte_count_ext = 406,
cmd_set_exclusive_scissor_nv = 407,
cmd_set_exclusive_scissor_enable_nv = 408,
cmd_bind_shading_rate_image_nv = 409,
cmd_set_viewport_shading_rate_palette_nv = 410,
cmd_set_coarse_sample_order_nv = 411,
cmd_draw_mesh_tasks_nv = 412,
cmd_draw_mesh_tasks_indirect_nv = 413,
cmd_draw_mesh_tasks_indirect_count_nv = 414,
cmd_draw_mesh_tasks_ext = 415,
cmd_draw_mesh_tasks_indirect_ext = 416,
cmd_draw_mesh_tasks_indirect_count_ext = 417,
compile_deferred_nv = 418,
create_acceleration_structure_nv = 419,
cmd_bind_invocation_mask_huawei = 420,
destroy_acceleration_structure_khr = 421,
destroy_acceleration_structure_nv = 422,
get_acceleration_structure_memory_requirements_nv = 423,
bind_acceleration_structure_memory_nv = 424,
cmd_copy_acceleration_structure_nv = 425,
cmd_copy_acceleration_structure_khr = 426,
copy_acceleration_structure_khr = 427,
cmd_copy_acceleration_structure_to_memory_khr = 428,
copy_acceleration_structure_to_memory_khr = 429,
cmd_copy_memory_to_acceleration_structure_khr = 430,
copy_memory_to_acceleration_structure_khr = 431,
cmd_write_acceleration_structures_properties_khr = 432,
cmd_write_acceleration_structures_properties_nv = 433,
cmd_build_acceleration_structure_nv = 434,
write_acceleration_structures_properties_khr = 435,
cmd_trace_rays_khr = 436,
cmd_trace_rays_nv = 437,
get_ray_tracing_shader_group_handles_khr = 438,
get_ray_tracing_shader_group_handles_nv = get_ray_tracing_shader_group_handles_khr,
get_ray_tracing_capture_replay_shader_group_handles_khr = 440,
get_acceleration_structure_handle_nv = 441,
create_ray_tracing_pipelines_nv = 442,
create_ray_tracing_pipelines_khr = 443,
get_physical_device_cooperative_matrix_properties_nv = 444,
cmd_trace_rays_indirect_khr = 445,
cmd_trace_rays_indirect_2khr = 446,
get_cluster_acceleration_structure_build_sizes_nv = 447,
cmd_build_cluster_acceleration_structure_indirect_nv = 448,
get_device_acceleration_structure_compatibility_khr = 449,
get_ray_tracing_shader_group_stack_size_khr = 450,
cmd_set_ray_tracing_pipeline_stack_size_khr = 451,
get_image_view_handle_nvx = 452,
get_image_view_handle_64nvx = 453,
get_image_view_address_nvx = 454,
get_device_combined_image_sampler_index_nvx = 455,
get_physical_device_surface_present_modes_2ext = 456,
get_device_group_surface_present_modes_2ext = 457,
acquire_full_screen_exclusive_mode_ext = 458,
release_full_screen_exclusive_mode_ext = 459,
enumerate_physical_device_queue_family_performance_query_counters_khr = 460,
get_physical_device_queue_family_performance_query_passes_khr = 461,
acquire_profiling_lock_khr = 462,
release_profiling_lock_khr = 463,
get_image_drm_format_modifier_properties_ext = 464,
get_buffer_opaque_capture_address = 465,
get_buffer_opaque_capture_address_khr = get_buffer_opaque_capture_address,
get_buffer_device_address = 467,
get_buffer_device_address_khr = get_buffer_device_address,
get_buffer_device_address_ext = get_buffer_device_address,
create_headless_surface_ext = 470,
get_physical_device_supported_framebuffer_mixed_samples_combinations_nv = 471,
initialize_performance_api_intel = 472,
uninitialize_performance_api_intel = 473,
cmd_set_performance_marker_intel = 474,
cmd_set_performance_stream_marker_intel = 475,
cmd_set_performance_override_intel = 476,
acquire_performance_configuration_intel = 477,
release_performance_configuration_intel = 478,
queue_set_performance_configuration_intel = 479,
get_performance_parameter_intel = 480,
get_device_memory_opaque_capture_address = 481,
get_device_memory_opaque_capture_address_khr = get_device_memory_opaque_capture_address,
get_pipeline_executable_properties_khr = 483,
get_pipeline_executable_statistics_khr = 484,
get_pipeline_executable_internal_representations_khr = 485,
cmd_set_line_stipple = 486,
cmd_set_line_stipple_khr = cmd_set_line_stipple,
cmd_set_line_stipple_ext = cmd_set_line_stipple,
get_fault_data = 489,
get_physical_device_tool_properties = 490,
get_physical_device_tool_properties_ext = get_physical_device_tool_properties,
create_acceleration_structure_khr = 492,
cmd_build_acceleration_structures_khr = 493,
cmd_build_acceleration_structures_indirect_khr = 494,
build_acceleration_structures_khr = 495,
get_acceleration_structure_device_address_khr = 496,
create_deferred_operation_khr = 497,
destroy_deferred_operation_khr = 498,
get_deferred_operation_max_concurrency_khr = 499,
get_deferred_operation_result_khr = 500,
deferred_operation_join_khr = 501,
get_pipeline_indirect_memory_requirements_nv = 502,
get_pipeline_indirect_device_address_nv = 503,
anti_lag_update_amd = 504,
cmd_set_cull_mode = 505,
cmd_set_cull_mode_ext = cmd_set_cull_mode,
cmd_set_front_face = 507,
cmd_set_front_face_ext = cmd_set_front_face,
cmd_set_primitive_topology = 509,
cmd_set_primitive_topology_ext = cmd_set_primitive_topology,
cmd_set_viewport_with_count = 511,
cmd_set_viewport_with_count_ext = cmd_set_viewport_with_count,
cmd_set_scissor_with_count = 513,
cmd_set_scissor_with_count_ext = cmd_set_scissor_with_count,
cmd_bind_index_buffer_2 = 515,
cmd_bind_index_buffer_2khr = cmd_bind_index_buffer_2,
cmd_bind_vertex_buffers_2 = 517,
cmd_bind_vertex_buffers_2ext = cmd_bind_vertex_buffers_2,
cmd_set_depth_test_enable = 519,
cmd_set_depth_test_enable_ext = cmd_set_depth_test_enable,
cmd_set_depth_write_enable = 521,
cmd_set_depth_write_enable_ext = cmd_set_depth_write_enable,
cmd_set_depth_compare_op = 523,
cmd_set_depth_compare_op_ext = cmd_set_depth_compare_op,
cmd_set_depth_bounds_test_enable = 525,
cmd_set_depth_bounds_test_enable_ext = cmd_set_depth_bounds_test_enable,
cmd_set_stencil_test_enable = 527,
cmd_set_stencil_test_enable_ext = cmd_set_stencil_test_enable,
cmd_set_stencil_op = 529,
cmd_set_stencil_op_ext = cmd_set_stencil_op,
cmd_set_patch_control_points_ext = 531,
cmd_set_rasterizer_discard_enable = 532,
cmd_set_rasterizer_discard_enable_ext = cmd_set_rasterizer_discard_enable,
cmd_set_depth_bias_enable = 534,
cmd_set_depth_bias_enable_ext = cmd_set_depth_bias_enable,
cmd_set_logic_op_ext = 536,
cmd_set_primitive_restart_enable = 537,
cmd_set_primitive_restart_enable_ext = cmd_set_primitive_restart_enable,
cmd_set_tessellation_domain_origin_ext = 539,
cmd_set_depth_clamp_enable_ext = 540,
cmd_set_polygon_mode_ext = 541,
cmd_set_rasterization_samples_ext = 542,
cmd_set_sample_mask_ext = 543,
cmd_set_alpha_to_coverage_enable_ext = 544,
cmd_set_alpha_to_one_enable_ext = 545,
cmd_set_logic_op_enable_ext = 546,
cmd_set_color_blend_enable_ext = 547,
cmd_set_color_blend_equation_ext = 548,
cmd_set_color_write_mask_ext = 549,
cmd_set_rasterization_stream_ext = 550,
cmd_set_conservative_rasterization_mode_ext = 551,
cmd_set_extra_primitive_overestimation_size_ext = 552,
cmd_set_depth_clip_enable_ext = 553,
cmd_set_sample_locations_enable_ext = 554,
cmd_set_color_blend_advanced_ext = 555,
cmd_set_provoking_vertex_mode_ext = 556,
cmd_set_line_rasterization_mode_ext = 557,
cmd_set_line_stipple_enable_ext = 558,
cmd_set_depth_clip_negative_one_to_one_ext = 559,
cmd_set_viewport_w_scaling_enable_nv = 560,
cmd_set_viewport_swizzle_nv = 561,
cmd_set_coverage_to_color_enable_nv = 562,
cmd_set_coverage_to_color_location_nv = 563,
cmd_set_coverage_modulation_mode_nv = 564,
cmd_set_coverage_modulation_table_enable_nv = 565,
cmd_set_coverage_modulation_table_nv = 566,
cmd_set_shading_rate_image_enable_nv = 567,
cmd_set_coverage_reduction_mode_nv = 568,
cmd_set_representative_fragment_test_enable_nv = 569,
create_private_data_slot = 570,
create_private_data_slot_ext = create_private_data_slot,
destroy_private_data_slot = 572,
destroy_private_data_slot_ext = destroy_private_data_slot,
set_private_data = 574,
set_private_data_ext = set_private_data,
get_private_data = 576,
get_private_data_ext = get_private_data,
cmd_copy_buffer_2 = 578,
cmd_copy_buffer_2khr = cmd_copy_buffer_2,
cmd_copy_image_2 = 580,
cmd_copy_image_2khr = cmd_copy_image_2,
cmd_blit_image_2 = 582,
cmd_blit_image_2khr = cmd_blit_image_2,
cmd_copy_buffer_to_image_2 = 584,
cmd_copy_buffer_to_image_2khr = cmd_copy_buffer_to_image_2,
cmd_copy_image_to_buffer_2 = 586,
cmd_copy_image_to_buffer_2khr = cmd_copy_image_to_buffer_2,
cmd_resolve_image_2 = 588,
cmd_resolve_image_2khr = cmd_resolve_image_2,
cmd_refresh_objects_khr = 590,
get_physical_device_refreshable_object_types_khr = 591,
cmd_set_fragment_shading_rate_khr = 592,
get_physical_device_fragment_shading_rates_khr = 593,
cmd_set_fragment_shading_rate_enum_nv = 594,
get_acceleration_structure_build_sizes_khr = 595,
cmd_set_vertex_input_ext = 596,
cmd_set_color_write_enable_ext = 597,
cmd_set_event_2 = 598,
cmd_set_event_2khr = cmd_set_event_2,
cmd_reset_event_2 = 600,
cmd_reset_event_2khr = cmd_reset_event_2,
cmd_wait_events_2 = 602,
cmd_wait_events_2khr = cmd_wait_events_2,
cmd_pipeline_barrier_2 = 604,
cmd_pipeline_barrier_2khr = cmd_pipeline_barrier_2,
queue_submit_2 = 606,
queue_submit_2khr = queue_submit_2,
cmd_write_timestamp_2 = 608,
cmd_write_timestamp_2khr = cmd_write_timestamp_2,
cmd_write_buffer_marker_2amd = 610,
get_queue_checkpoint_data_2nv = 611,
copy_memory_to_image = 612,
copy_memory_to_image_ext = copy_memory_to_image,
copy_image_to_memory = 614,
copy_image_to_memory_ext = copy_image_to_memory,
copy_image_to_image = 616,
copy_image_to_image_ext = copy_image_to_image,
transition_image_layout = 618,
transition_image_layout_ext = transition_image_layout,
get_command_pool_memory_consumption = 620,
cmd_decompress_memory_nv = 621,
cmd_decompress_memory_indirect_count_nv = 622,
get_partitioned_acceleration_structures_build_sizes_nv = 623,
cmd_build_partitioned_acceleration_structures_nv = 624,
cmd_decompress_memory_ext = 625,
cmd_decompress_memory_indirect_count_ext = 626,
create_cu_module_nvx = 627,
create_cu_function_nvx = 628,
destroy_cu_module_nvx = 629,
destroy_cu_function_nvx = 630,
cmd_cu_launch_kernel_nvx = 631,
get_descriptor_set_layout_size_ext = 632,
get_descriptor_set_layout_binding_offset_ext = 633,
get_descriptor_ext = 634,
cmd_bind_descriptor_buffers_ext = 635,
cmd_set_descriptor_buffer_offsets_ext = 636,
cmd_bind_descriptor_buffer_embedded_samplers_ext = 637,
get_buffer_opaque_capture_descriptor_data_ext = 638,
get_image_opaque_capture_descriptor_data_ext = 639,
get_image_view_opaque_capture_descriptor_data_ext = 640,
get_sampler_opaque_capture_descriptor_data_ext = 641,
get_acceleration_structure_opaque_capture_descriptor_data_ext = 642,
set_device_memory_priority_ext = 643,
acquire_drm_display_ext = 644,
get_drm_display_ext = 645,
wait_for_present_2khr = 646,
wait_for_present_khr = 647,
create_buffer_collection_fuchsia = 648,
set_buffer_collection_buffer_constraints_fuchsia = 649,
set_buffer_collection_image_constraints_fuchsia = 650,
destroy_buffer_collection_fuchsia = 651,
get_buffer_collection_properties_fuchsia = 652,
create_cuda_module_nv = 653,
get_cuda_module_cache_nv = 654,
create_cuda_function_nv = 655,
destroy_cuda_module_nv = 656,
destroy_cuda_function_nv = 657,
cmd_cuda_launch_kernel_nv = 658,
cmd_begin_rendering = 659,
cmd_begin_rendering_khr = cmd_begin_rendering,
cmd_end_rendering = 661,
cmd_end_rendering_2khr = 662,
cmd_end_rendering_2ext = cmd_end_rendering_2khr,
cmd_end_rendering_khr = cmd_end_rendering,
get_descriptor_set_layout_host_mapping_info_valve = 665,
get_descriptor_set_host_mapping_valve = 666,
create_micromap_ext = 667,
cmd_build_micromaps_ext = 668,
build_micromaps_ext = 669,
destroy_micromap_ext = 670,
cmd_copy_micromap_ext = 671,
copy_micromap_ext = 672,
cmd_copy_micromap_to_memory_ext = 673,
copy_micromap_to_memory_ext = 674,
cmd_copy_memory_to_micromap_ext = 675,
copy_memory_to_micromap_ext = 676,
cmd_write_micromaps_properties_ext = 677,
write_micromaps_properties_ext = 678,
get_device_micromap_compatibility_ext = 679,
get_micromap_build_sizes_ext = 680,
get_shader_module_identifier_ext = 681,
get_shader_module_create_info_identifier_ext = 682,
get_image_subresource_layout_2 = 683,
get_image_subresource_layout_2khr = get_image_subresource_layout_2,
get_image_subresource_layout_2ext = get_image_subresource_layout_2,
get_pipeline_properties_ext = 686,
export_metal_objects_ext = 687,
cmd_bind_tile_memory_qcom = 688,
get_framebuffer_tile_properties_qcom = 689,
get_dynamic_rendering_tile_properties_qcom = 690,
get_physical_device_optical_flow_image_formats_nv = 691,
create_optical_flow_session_nv = 692,
destroy_optical_flow_session_nv = 693,
bind_optical_flow_session_image_nv = 694,
cmd_optical_flow_execute_nv = 695,
get_device_fault_info_ext = 696,
get_device_fault_reports_khr = 697,
get_device_fault_debug_info_khr = 698,
cmd_set_depth_bias_2ext = 699,
release_swapchain_images_khr = 700,
release_swapchain_images_ext = release_swapchain_images_khr,
get_device_image_subresource_layout = 702,
get_device_image_subresource_layout_khr = get_device_image_subresource_layout,
map_memory_2 = 704,
map_memory_2khr = map_memory_2,
unmap_memory_2 = 706,
unmap_memory_2khr = unmap_memory_2,
create_shaders_ext = 708,
destroy_shader_ext = 709,
get_shader_binary_data_ext = 710,
cmd_bind_shaders_ext = 711,
set_swapchain_present_timing_queue_size_ext = 712,
get_swapchain_timing_properties_ext = 713,
get_swapchain_time_domain_properties_ext = 714,
get_past_presentation_timing_ext = 715,
get_screen_buffer_properties_qnx = 716,
get_physical_device_cooperative_matrix_properties_khr = 717,
get_execution_graph_pipeline_scratch_size_amdx = 718,
get_execution_graph_pipeline_node_index_amdx = 719,
create_execution_graph_pipelines_amdx = 720,
cmd_initialize_graph_scratch_memory_amdx = 721,
cmd_dispatch_graph_amdx = 722,
cmd_dispatch_graph_indirect_amdx = 723,
cmd_dispatch_graph_indirect_count_amdx = 724,
create_gpa_session_amd = 725,
destroy_gpa_session_amd = 726,
set_gpa_device_clock_mode_amd = 727,
get_gpa_device_clock_info_amd = 728,
cmd_begin_gpa_session_amd = 729,
cmd_end_gpa_session_amd = 730,
cmd_begin_gpa_sample_amd = 731,
cmd_end_gpa_sample_amd = 732,
get_gpa_session_status_amd = 733,
get_gpa_session_results_amd = 734,
reset_gpa_session_amd = 735,
cmd_copy_gpa_session_results_amd = 736,
cmd_bind_descriptor_sets_2 = 737,
cmd_bind_descriptor_sets_2khr = cmd_bind_descriptor_sets_2,
cmd_push_constants_2 = 739,
cmd_push_constants_2khr = cmd_push_constants_2,
cmd_push_descriptor_set_2 = 741,
cmd_push_descriptor_set_2khr = cmd_push_descriptor_set_2,
cmd_push_descriptor_set_with_template_2 = 743,
cmd_push_descriptor_set_with_template_2khr = cmd_push_descriptor_set_with_template_2,
cmd_set_descriptor_buffer_offsets_2ext = 745,
cmd_bind_descriptor_buffer_embedded_samplers_2ext = 746,
set_latency_sleep_mode_nv = 747,
latency_sleep_nv = 748,
set_latency_marker_nv = 749,
get_latency_timings_nv = 750,
queue_notify_out_of_band_nv = 751,
cmd_set_rendering_attachment_locations = 752,
cmd_set_rendering_attachment_locations_khr = cmd_set_rendering_attachment_locations,
cmd_set_rendering_input_attachment_indices = 754,
cmd_set_rendering_input_attachment_indices_khr = cmd_set_rendering_input_attachment_indices,
cmd_set_depth_clamp_range_ext = 756,
get_physical_device_cooperative_matrix_flexible_dimensions_properties_nv = 757,
get_memory_metal_handle_ext = 758,
get_memory_metal_handle_properties_ext = 759,
get_physical_device_cooperative_vector_properties_nv = 760,
convert_cooperative_vector_matrix_nv = 761,
cmd_convert_cooperative_vector_matrix_nv = 762,
cmd_dispatch_tile_qcom = 763,
cmd_begin_per_tile_execution_qcom = 764,
cmd_end_per_tile_execution_qcom = 765,
create_external_compute_queue_nv = 766,
destroy_external_compute_queue_nv = 767,
get_external_compute_queue_data_nv = 768,
enumerate_physical_device_shader_instrumentation_metrics_arm = 769,
create_shader_instrumentation_arm = 770,
destroy_shader_instrumentation_arm = 771,
cmd_begin_shader_instrumentation_arm = 772,
cmd_end_shader_instrumentation_arm = 773,
get_shader_instrumentation_values_arm = 774,
clear_shader_instrumentation_metrics_arm = 775,
create_tensor_arm = 776,
destroy_tensor_arm = 777,
create_tensor_view_arm = 778,
destroy_tensor_view_arm = 779,
get_tensor_memory_requirements_arm = 780,
bind_tensor_memory_arm = 781,
get_device_tensor_memory_requirements_arm = 782,
cmd_copy_tensor_arm = 783,
get_tensor_opaque_capture_descriptor_data_arm = 784,
get_tensor_view_opaque_capture_descriptor_data_arm = 785,
get_physical_device_external_tensor_properties_arm = 786,
create_data_graph_pipelines_arm = 787,
create_data_graph_pipeline_session_arm = 788,
get_data_graph_pipeline_session_bind_point_requirements_arm = 789,
get_data_graph_pipeline_session_memory_requirements_arm = 790,
bind_data_graph_pipeline_session_memory_arm = 791,
destroy_data_graph_pipeline_session_arm = 792,
cmd_dispatch_data_graph_arm = 793,
get_data_graph_pipeline_available_properties_arm = 794,
get_data_graph_pipeline_properties_arm = 795,
get_physical_device_queue_family_data_graph_properties_arm = 796,
get_physical_device_queue_family_data_graph_processing_engine_properties_arm = 797,
get_native_buffer_properties_ohos = 798,
get_memory_native_buffer_ohos = 799,
get_swapchain_gralloc_usage_ohos = 800,
acquire_image_ohos = 801,
queue_signal_release_image_ohos = 802,
queue_set_perf_hint_qcom = 803,
enumerate_physical_device_queue_family_performance_counters_by_region_arm = 804,
cmd_set_compute_occupancy_priority_nv = 805,
write_sampler_descriptors_ext = 806,
write_resource_descriptors_ext = 807,
cmd_bind_sampler_heap_ext = 808,
cmd_bind_resource_heap_ext = 809,
cmd_push_data_ext = 810,
register_custom_border_color_ext = 811,
unregister_custom_border_color_ext = 812,
get_image_opaque_capture_data_ext = 813,
get_physical_device_descriptor_size_ext = 814,
get_tensor_opaque_capture_data_arm = 815,
cmd_copy_memory_khr = 816,
cmd_copy_memory_to_image_khr = 817,
cmd_copy_image_to_memory_khr = 818,
cmd_update_memory_khr = 819,
cmd_fill_memory_khr = 820,
cmd_copy_query_pool_results_to_memory_khr = 821,
cmd_begin_conditional_rendering_2ext = 822,
cmd_bind_transform_feedback_buffers_2ext = 823,
cmd_begin_transform_feedback_2ext = 824,
cmd_end_transform_feedback_2ext = 825,
cmd_draw_indirect_byte_count_2ext = 826,
cmd_write_marker_to_memory_amd = 827,
cmd_bind_index_buffer_3khr = 828,
cmd_bind_vertex_buffers_3khr = 829,
cmd_draw_indirect_2khr = 830,
cmd_draw_indexed_indirect_2khr = 831,
cmd_draw_indirect_count_2khr = 832,
cmd_draw_indexed_indirect_count_2khr = 833,
cmd_draw_mesh_tasks_indirect_2ext = 834,
cmd_draw_mesh_tasks_indirect_count_2ext = 835,
cmd_dispatch_indirect_2khr = 836,
create_acceleration_structure_2khr = 837,
get_physical_device_queue_family_data_graph_engine_operation_properties_arm = 838,
cmd_set_dispatch_parameters_arm = 839,
get_physical_device_queue_family_data_graph_optical_flow_image_formats_arm = 840,
};

inline ktl::api::result create_instance(const ktl::api::instance_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::instance * _p_instance)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_instance)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_instance)ptr)(_p_create_info, _p_allocator, _p_instance);
}

inline void destroy_instance(ktl::api::instance _instance, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_instance)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_instance)ptr)(_instance, _p_allocator);
}

inline ktl::api::result enumerate_physical_devices(ktl::api::instance _instance, ktl::u32 * _p_physical_device_count, ktl::api::physical_device * _p_physical_devices)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::enumerate_physical_devices)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_enumerate_physical_devices)ptr)(_instance, _p_physical_device_count, _p_physical_devices);
}

inline ktl::api::pfn_void_function get_device_proc_addr(ktl::api::device _device, const char * _p_name)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_proc_addr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_proc_addr)ptr)(_device, _p_name);
}

inline ktl::api::pfn_void_function get_instance_proc_addr(ktl::api::instance _instance, const char * _p_name)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_instance_proc_addr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_instance_proc_addr)ptr)(_instance, _p_name);
}

inline void get_physical_device_properties(ktl::api::physical_device _physical_device, ktl::api::physical_device_properties * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_properties)ptr)(_physical_device, _p_properties);
}

inline void get_physical_device_queue_family_properties(ktl::api::physical_device _physical_device, ktl::u32 * _p_queue_family_property_count, ktl::api::queue_family_properties * _p_queue_family_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_queue_family_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_queue_family_properties)ptr)(_physical_device, _p_queue_family_property_count, _p_queue_family_properties);
}

inline void get_physical_device_memory_properties(ktl::api::physical_device _physical_device, ktl::api::physical_device_memory_properties * _p_memory_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_memory_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_memory_properties)ptr)(_physical_device, _p_memory_properties);
}

inline void get_physical_device_features(ktl::api::physical_device _physical_device, ktl::api::physical_device_features * _p_features)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_features)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_features)ptr)(_physical_device, _p_features);
}

inline void get_physical_device_format_properties(ktl::api::physical_device _physical_device, ktl::api::format _format, ktl::api::format_properties * _p_format_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_format_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_format_properties)ptr)(_physical_device, _format, _p_format_properties);
}

inline ktl::api::result get_physical_device_image_format_properties(ktl::api::physical_device _physical_device, ktl::api::format _format, ktl::api::image_type _type, ktl::api::image_tiling _tiling, ktl::api::image_usage_flags _usage, ktl::api::image_create_flags _flags, ktl::api::image_format_properties * _p_image_format_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_image_format_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_image_format_properties)ptr)(_physical_device, _format, _type, _tiling, _usage, _flags, _p_image_format_properties);
}

inline ktl::api::result create_device(ktl::api::physical_device _physical_device, const ktl::api::device_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::device * _p_device)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_device)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_device)ptr)(_physical_device, _p_create_info, _p_allocator, _p_device);
}

inline void destroy_device(ktl::api::device _device, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_device)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_device)ptr)(_device, _p_allocator);
}

inline ktl::api::result enumerate_instance_version(ktl::u32 * _p_api_version)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::enumerate_instance_version)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_enumerate_instance_version)ptr)(_p_api_version);
}

inline ktl::api::result enumerate_instance_layer_properties(ktl::u32 * _p_property_count, ktl::api::layer_properties * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::enumerate_instance_layer_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_enumerate_instance_layer_properties)ptr)(_p_property_count, _p_properties);
}

inline ktl::api::result enumerate_instance_extension_properties(const char * _p_layer_name, ktl::u32 * _p_property_count, ktl::api::extension_properties * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::enumerate_instance_extension_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_enumerate_instance_extension_properties)ptr)(_p_layer_name, _p_property_count, _p_properties);
}

inline ktl::api::result enumerate_device_layer_properties(ktl::api::physical_device _physical_device, ktl::u32 * _p_property_count, ktl::api::layer_properties * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::enumerate_device_layer_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_enumerate_device_layer_properties)ptr)(_physical_device, _p_property_count, _p_properties);
}

inline ktl::api::result enumerate_device_extension_properties(ktl::api::physical_device _physical_device, const char * _p_layer_name, ktl::u32 * _p_property_count, ktl::api::extension_properties * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::enumerate_device_extension_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_enumerate_device_extension_properties)ptr)(_physical_device, _p_layer_name, _p_property_count, _p_properties);
}

inline void get_device_queue(ktl::api::device _device, ktl::u32 _queue_family_index, ktl::u32 _queue_index, ktl::api::queue * _p_queue)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_queue)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_queue)ptr)(_device, _queue_family_index, _queue_index, _p_queue);
}

inline ktl::api::result queue_submit(ktl::api::queue _queue, ktl::u32 _submit_count, const ktl::api::submit_info * _p_submits, ktl::api::fence _fence)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_submit)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_submit)ptr)(_queue, _submit_count, _p_submits, _fence);
}

inline ktl::api::result queue_wait_idle(ktl::api::queue _queue)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_wait_idle)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_wait_idle)ptr)(_queue);
}

inline ktl::api::result device_wait_idle(ktl::api::device _device)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::device_wait_idle)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_device_wait_idle)ptr)(_device);
}

inline ktl::api::result allocate_memory(ktl::api::device _device, const ktl::api::memory_allocate_info * _p_allocate_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::device_memory * _p_memory)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::allocate_memory)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_allocate_memory)ptr)(_device, _p_allocate_info, _p_allocator, _p_memory);
}

inline void free_memory(ktl::api::device _device, ktl::api::device_memory _memory, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::free_memory)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_free_memory)ptr)(_device, _memory, _p_allocator);
}

inline ktl::api::result map_memory(ktl::api::device _device, ktl::api::device_memory _memory, ktl::api::dvsize _offset, ktl::api::dvsize _size, ktl::api::memory_map_flags _flags, void * _pp_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::map_memory)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_map_memory)ptr)(_device, _memory, _offset, _size, _flags, _pp_data);
}

inline void unmap_memory(ktl::api::device _device, ktl::api::device_memory _memory)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::unmap_memory)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_unmap_memory)ptr)(_device, _memory);
}

inline ktl::api::result flush_mapped_memory_ranges(ktl::api::device _device, ktl::u32 _memory_range_count, const ktl::api::mapped_memory_range * _p_memory_ranges)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::flush_mapped_memory_ranges)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_flush_mapped_memory_ranges)ptr)(_device, _memory_range_count, _p_memory_ranges);
}

inline ktl::api::result invalidate_mapped_memory_ranges(ktl::api::device _device, ktl::u32 _memory_range_count, const ktl::api::mapped_memory_range * _p_memory_ranges)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::invalidate_mapped_memory_ranges)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_invalidate_mapped_memory_ranges)ptr)(_device, _memory_range_count, _p_memory_ranges);
}

inline void get_device_memory_commitment(ktl::api::device _device, ktl::api::device_memory _memory, ktl::api::dvsize * _p_committed_memory_in_bytes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_memory_commitment)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_memory_commitment)ptr)(_device, _memory, _p_committed_memory_in_bytes);
}

inline void get_buffer_memory_requirements(ktl::api::device _device, ktl::api::buffer _buffer, ktl::api::memory_requirements * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_buffer_memory_requirements)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_buffer_memory_requirements)ptr)(_device, _buffer, _p_memory_requirements);
}

inline ktl::api::result bind_buffer_memory(ktl::api::device _device, ktl::api::buffer _buffer, ktl::api::device_memory _memory, ktl::api::dvsize _memory_offset)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::bind_buffer_memory)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_bind_buffer_memory)ptr)(_device, _buffer, _memory, _memory_offset);
}

inline void get_image_memory_requirements(ktl::api::device _device, ktl::api::image _image, ktl::api::memory_requirements * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_memory_requirements)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_memory_requirements)ptr)(_device, _image, _p_memory_requirements);
}

inline ktl::api::result bind_image_memory(ktl::api::device _device, ktl::api::image _image, ktl::api::device_memory _memory, ktl::api::dvsize _memory_offset)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::bind_image_memory)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_bind_image_memory)ptr)(_device, _image, _memory, _memory_offset);
}

inline void get_image_sparse_memory_requirements(ktl::api::device _device, ktl::api::image _image, ktl::u32 * _p_sparse_memory_requirement_count, ktl::api::sparse_image_memory_requirements * _p_sparse_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_sparse_memory_requirements)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_sparse_memory_requirements)ptr)(_device, _image, _p_sparse_memory_requirement_count, _p_sparse_memory_requirements);
}

inline void get_physical_device_sparse_image_format_properties(ktl::api::physical_device _physical_device, ktl::api::format _format, ktl::api::image_type _type, ktl::api::sample_count_flag_bits _samples, ktl::api::image_usage_flags _usage, ktl::api::image_tiling _tiling, ktl::u32 * _p_property_count, ktl::api::sparse_image_format_properties * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_sparse_image_format_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_sparse_image_format_properties)ptr)(_physical_device, _format, _type, _samples, _usage, _tiling, _p_property_count, _p_properties);
}

inline ktl::api::result queue_bind_sparse(ktl::api::queue _queue, ktl::u32 _bind_info_count, const ktl::api::bind_sparse_info * _p_bind_info, ktl::api::fence _fence)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_bind_sparse)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_bind_sparse)ptr)(_queue, _bind_info_count, _p_bind_info, _fence);
}

inline ktl::api::result create_fence(ktl::api::device _device, const ktl::api::fence_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::fence * _p_fence)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_fence)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_fence)ptr)(_device, _p_create_info, _p_allocator, _p_fence);
}

inline void destroy_fence(ktl::api::device _device, ktl::api::fence _fence, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_fence)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_fence)ptr)(_device, _fence, _p_allocator);
}

inline ktl::api::result reset_fences(ktl::api::device _device, ktl::u32 _fence_count, const ktl::api::fence * _p_fences)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::reset_fences)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_reset_fences)ptr)(_device, _fence_count, _p_fences);
}

inline ktl::api::result get_fence_status(ktl::api::device _device, ktl::api::fence _fence)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_fence_status)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_fence_status)ptr)(_device, _fence);
}

inline ktl::api::result wait_for_fences(ktl::api::device _device, ktl::u32 _fence_count, const ktl::api::fence * _p_fences, ktl::api::bool32 _wait_all, ktl::u64 _timeout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::wait_for_fences)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_wait_for_fences)ptr)(_device, _fence_count, _p_fences, _wait_all, _timeout);
}

inline ktl::api::result create_semaphore(ktl::api::device _device, const ktl::api::semaphore_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::semaphore * _p_semaphore)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_semaphore)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_semaphore)ptr)(_device, _p_create_info, _p_allocator, _p_semaphore);
}

inline void destroy_semaphore(ktl::api::device _device, ktl::api::semaphore _semaphore, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_semaphore)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_semaphore)ptr)(_device, _semaphore, _p_allocator);
}

inline ktl::api::result create_event(ktl::api::device _device, const ktl::api::event_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::event * _p_event)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_event)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_event)ptr)(_device, _p_create_info, _p_allocator, _p_event);
}

inline void destroy_event(ktl::api::device _device, ktl::api::event _event, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_event)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_event)ptr)(_device, _event, _p_allocator);
}

inline ktl::api::result get_event_status(ktl::api::device _device, ktl::api::event _event)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_event_status)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_event_status)ptr)(_device, _event);
}

inline ktl::api::result set_event(ktl::api::device _device, ktl::api::event _event)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_event)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_event)ptr)(_device, _event);
}

inline ktl::api::result reset_event(ktl::api::device _device, ktl::api::event _event)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::reset_event)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_reset_event)ptr)(_device, _event);
}

inline ktl::api::result create_query_pool(ktl::api::device _device, const ktl::api::query_pool_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::query_pool * _p_query_pool)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_query_pool)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_query_pool)ptr)(_device, _p_create_info, _p_allocator, _p_query_pool);
}

inline void destroy_query_pool(ktl::api::device _device, ktl::api::query_pool _query_pool, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_query_pool)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_query_pool)ptr)(_device, _query_pool, _p_allocator);
}

inline ktl::api::result get_query_pool_results(ktl::api::device _device, ktl::api::query_pool _query_pool, ktl::u32 _first_query, ktl::u32 _query_count, ktl::usize _data_size, void * _p_data, ktl::api::dvsize _stride, ktl::api::query_result_flags _flags)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_query_pool_results)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_query_pool_results)ptr)(_device, _query_pool, _first_query, _query_count, _data_size, _p_data, _stride, _flags);
}

inline void reset_query_pool(ktl::api::device _device, ktl::api::query_pool _query_pool, ktl::u32 _first_query, ktl::u32 _query_count)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::reset_query_pool)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_reset_query_pool)ptr)(_device, _query_pool, _first_query, _query_count);
}

inline ktl::api::result create_buffer(ktl::api::device _device, const ktl::api::buffer_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::buffer * _p_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_buffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_buffer)ptr)(_device, _p_create_info, _p_allocator, _p_buffer);
}

inline void destroy_buffer(ktl::api::device _device, ktl::api::buffer _buffer, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_buffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_buffer)ptr)(_device, _buffer, _p_allocator);
}

inline ktl::api::result create_buffer_view(ktl::api::device _device, const ktl::api::buffer_view_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::buffer_view * _p_view)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_buffer_view)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_buffer_view)ptr)(_device, _p_create_info, _p_allocator, _p_view);
}

inline void destroy_buffer_view(ktl::api::device _device, ktl::api::buffer_view _buffer_view, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_buffer_view)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_buffer_view)ptr)(_device, _buffer_view, _p_allocator);
}

inline ktl::api::result create_image(ktl::api::device _device, const ktl::api::image_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::image * _p_image)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_image)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_image)ptr)(_device, _p_create_info, _p_allocator, _p_image);
}

inline void destroy_image(ktl::api::device _device, ktl::api::image _image, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_image)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_image)ptr)(_device, _image, _p_allocator);
}

inline void get_image_subresource_layout(ktl::api::device _device, ktl::api::image _image, const ktl::api::image_subresource * _p_subresource, ktl::api::subresource_layout * _p_layout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_subresource_layout)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_subresource_layout)ptr)(_device, _image, _p_subresource, _p_layout);
}

inline ktl::api::result create_image_view(ktl::api::device _device, const ktl::api::image_view_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::image_view * _p_view)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_image_view)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_image_view)ptr)(_device, _p_create_info, _p_allocator, _p_view);
}

inline void destroy_image_view(ktl::api::device _device, ktl::api::image_view _image_view, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_image_view)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_image_view)ptr)(_device, _image_view, _p_allocator);
}

inline ktl::api::result create_shader_module(ktl::api::device _device, const ktl::api::shader_module_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::shader_module * _p_shader_module)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_shader_module)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_shader_module)ptr)(_device, _p_create_info, _p_allocator, _p_shader_module);
}

inline void destroy_shader_module(ktl::api::device _device, ktl::api::shader_module _shader_module, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_shader_module)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_shader_module)ptr)(_device, _shader_module, _p_allocator);
}

inline ktl::api::result create_pipeline_cache(ktl::api::device _device, const ktl::api::pipeline_cache_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::pipeline_cache * _p_pipeline_cache)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_pipeline_cache)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_pipeline_cache)ptr)(_device, _p_create_info, _p_allocator, _p_pipeline_cache);
}

inline void destroy_pipeline_cache(ktl::api::device _device, ktl::api::pipeline_cache _pipeline_cache, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_pipeline_cache)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_pipeline_cache)ptr)(_device, _pipeline_cache, _p_allocator);
}

inline ktl::api::result get_pipeline_cache_data(ktl::api::device _device, ktl::api::pipeline_cache _pipeline_cache, ktl::usize * _p_data_size, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_pipeline_cache_data)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_pipeline_cache_data)ptr)(_device, _pipeline_cache, _p_data_size, _p_data);
}

inline ktl::api::result merge_pipeline_caches(ktl::api::device _device, ktl::api::pipeline_cache _dst_cache, ktl::u32 _src_cache_count, const ktl::api::pipeline_cache * _p_src_caches)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::merge_pipeline_caches)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_merge_pipeline_caches)ptr)(_device, _dst_cache, _src_cache_count, _p_src_caches);
}

inline ktl::api::result create_pipeline_binaries_khr(ktl::api::device _device, const ktl::api::pipeline_binary_create_info_khr * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::pipeline_binary_handles_info_khr * _p_binaries)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_pipeline_binaries_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_pipeline_binaries_khr)ptr)(_device, _p_create_info, _p_allocator, _p_binaries);
}

inline void destroy_pipeline_binary_khr(ktl::api::device _device, ktl::api::pipeline_binary_khr _pipeline_binary, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_pipeline_binary_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_pipeline_binary_khr)ptr)(_device, _pipeline_binary, _p_allocator);
}

inline ktl::api::result get_pipeline_key_khr(ktl::api::device _device, const ktl::api::pipeline_create_info_khr * _p_pipeline_create_info, ktl::api::pipeline_binary_key_khr * _p_pipeline_key)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_pipeline_key_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_pipeline_key_khr)ptr)(_device, _p_pipeline_create_info, _p_pipeline_key);
}

inline ktl::api::result get_pipeline_binary_data_khr(ktl::api::device _device, const ktl::api::pipeline_binary_data_info_khr * _p_info, ktl::api::pipeline_binary_key_khr * _p_pipeline_binary_key, ktl::usize * _p_pipeline_binary_data_size, void * _p_pipeline_binary_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_pipeline_binary_data_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_pipeline_binary_data_khr)ptr)(_device, _p_info, _p_pipeline_binary_key, _p_pipeline_binary_data_size, _p_pipeline_binary_data);
}

inline ktl::api::result release_captured_pipeline_data_khr(ktl::api::device _device, const ktl::api::release_captured_pipeline_data_info_khr * _p_info, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::release_captured_pipeline_data_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_release_captured_pipeline_data_khr)ptr)(_device, _p_info, _p_allocator);
}

inline ktl::api::result create_graphics_pipelines(ktl::api::device _device, ktl::api::pipeline_cache _pipeline_cache, ktl::u32 _create_info_count, const ktl::api::graphics_pipeline_create_info * _p_create_infos, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::pipeline * _p_pipelines)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_graphics_pipelines)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_graphics_pipelines)ptr)(_device, _pipeline_cache, _create_info_count, _p_create_infos, _p_allocator, _p_pipelines);
}

inline ktl::api::result create_compute_pipelines(ktl::api::device _device, ktl::api::pipeline_cache _pipeline_cache, ktl::u32 _create_info_count, const ktl::api::compute_pipeline_create_info * _p_create_infos, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::pipeline * _p_pipelines)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_compute_pipelines)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_compute_pipelines)ptr)(_device, _pipeline_cache, _create_info_count, _p_create_infos, _p_allocator, _p_pipelines);
}

inline ktl::api::result get_device_subpass_shading_max_workgroup_size_huawei(ktl::api::device _device, ktl::api::render_pass _renderpass, ktl::api::extent_2d * _p_max_workgroup_size)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_subpass_shading_max_workgroup_size_huawei)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_subpass_shading_max_workgroup_size_huawei)ptr)(_device, _renderpass, _p_max_workgroup_size);
}

inline void destroy_pipeline(ktl::api::device _device, ktl::api::pipeline _pipeline, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_pipeline)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_pipeline)ptr)(_device, _pipeline, _p_allocator);
}

inline ktl::api::result create_pipeline_layout(ktl::api::device _device, const ktl::api::pipeline_layout_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::pipeline_layout * _p_pipeline_layout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_pipeline_layout)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_pipeline_layout)ptr)(_device, _p_create_info, _p_allocator, _p_pipeline_layout);
}

inline void destroy_pipeline_layout(ktl::api::device _device, ktl::api::pipeline_layout _pipeline_layout, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_pipeline_layout)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_pipeline_layout)ptr)(_device, _pipeline_layout, _p_allocator);
}

inline ktl::api::result create_sampler(ktl::api::device _device, const ktl::api::sampler_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::sampler * _p_sampler)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_sampler)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_sampler)ptr)(_device, _p_create_info, _p_allocator, _p_sampler);
}

inline void destroy_sampler(ktl::api::device _device, ktl::api::sampler _sampler, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_sampler)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_sampler)ptr)(_device, _sampler, _p_allocator);
}

inline ktl::api::result create_descriptor_set_layout(ktl::api::device _device, const ktl::api::descriptor_set_layout_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::descriptor_set_layout * _p_set_layout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_descriptor_set_layout)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_descriptor_set_layout)ptr)(_device, _p_create_info, _p_allocator, _p_set_layout);
}

inline void destroy_descriptor_set_layout(ktl::api::device _device, ktl::api::descriptor_set_layout _descriptor_set_layout, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_descriptor_set_layout)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_descriptor_set_layout)ptr)(_device, _descriptor_set_layout, _p_allocator);
}

inline ktl::api::result create_descriptor_pool(ktl::api::device _device, const ktl::api::descriptor_pool_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::descriptor_pool * _p_descriptor_pool)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_descriptor_pool)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_descriptor_pool)ptr)(_device, _p_create_info, _p_allocator, _p_descriptor_pool);
}

inline void destroy_descriptor_pool(ktl::api::device _device, ktl::api::descriptor_pool _descriptor_pool, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_descriptor_pool)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_descriptor_pool)ptr)(_device, _descriptor_pool, _p_allocator);
}

inline ktl::api::result reset_descriptor_pool(ktl::api::device _device, ktl::api::descriptor_pool _descriptor_pool, ktl::api::descriptor_pool_reset_flags _flags)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::reset_descriptor_pool)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_reset_descriptor_pool)ptr)(_device, _descriptor_pool, _flags);
}

inline ktl::api::result allocate_descriptor_sets(ktl::api::device _device, const ktl::api::descriptor_set_allocate_info * _p_allocate_info, ktl::api::descriptor_set * _p_descriptor_sets)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::allocate_descriptor_sets)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_allocate_descriptor_sets)ptr)(_device, _p_allocate_info, _p_descriptor_sets);
}

inline ktl::api::result free_descriptor_sets(ktl::api::device _device, ktl::api::descriptor_pool _descriptor_pool, ktl::u32 _descriptor_set_count, const ktl::api::descriptor_set * _p_descriptor_sets)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::free_descriptor_sets)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_free_descriptor_sets)ptr)(_device, _descriptor_pool, _descriptor_set_count, _p_descriptor_sets);
}

inline void update_descriptor_sets(ktl::api::device _device, ktl::u32 _descriptor_write_count, const ktl::api::write_descriptor_set * _p_descriptor_writes, ktl::u32 _descriptor_copy_count, const ktl::api::copy_descriptor_set * _p_descriptor_copies)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::update_descriptor_sets)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_update_descriptor_sets)ptr)(_device, _descriptor_write_count, _p_descriptor_writes, _descriptor_copy_count, _p_descriptor_copies);
}

inline ktl::api::result create_framebuffer(ktl::api::device _device, const ktl::api::framebuffer_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::framebuffer * _p_framebuffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_framebuffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_framebuffer)ptr)(_device, _p_create_info, _p_allocator, _p_framebuffer);
}

inline void destroy_framebuffer(ktl::api::device _device, ktl::api::framebuffer _framebuffer, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_framebuffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_framebuffer)ptr)(_device, _framebuffer, _p_allocator);
}

inline ktl::api::result create_render_pass(ktl::api::device _device, const ktl::api::render_pass_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::render_pass * _p_render_pass)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_render_pass)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_render_pass)ptr)(_device, _p_create_info, _p_allocator, _p_render_pass);
}

inline void destroy_render_pass(ktl::api::device _device, ktl::api::render_pass _render_pass, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_render_pass)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_render_pass)ptr)(_device, _render_pass, _p_allocator);
}

inline void get_render_area_granularity(ktl::api::device _device, ktl::api::render_pass _render_pass, ktl::api::extent_2d * _p_granularity)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_render_area_granularity)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_render_area_granularity)ptr)(_device, _render_pass, _p_granularity);
}

inline void get_rendering_area_granularity(ktl::api::device _device, const ktl::api::rendering_area_info * _p_rendering_area_info, ktl::api::extent_2d * _p_granularity)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_rendering_area_granularity)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_rendering_area_granularity)ptr)(_device, _p_rendering_area_info, _p_granularity);
}

inline ktl::api::result create_command_pool(ktl::api::device _device, const ktl::api::command_pool_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::command_pool * _p_command_pool)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_command_pool)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_command_pool)ptr)(_device, _p_create_info, _p_allocator, _p_command_pool);
}

inline void destroy_command_pool(ktl::api::device _device, ktl::api::command_pool _command_pool, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_command_pool)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_command_pool)ptr)(_device, _command_pool, _p_allocator);
}

inline ktl::api::result reset_command_pool(ktl::api::device _device, ktl::api::command_pool _command_pool, ktl::api::command_pool_reset_flags _flags)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::reset_command_pool)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_reset_command_pool)ptr)(_device, _command_pool, _flags);
}

inline ktl::api::result allocate_command_buffers(ktl::api::device _device, const ktl::api::command_buffer_allocate_info * _p_allocate_info, ktl::api::command_buffer * _p_command_buffers)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::allocate_command_buffers)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_allocate_command_buffers)ptr)(_device, _p_allocate_info, _p_command_buffers);
}

inline void free_command_buffers(ktl::api::device _device, ktl::api::command_pool _command_pool, ktl::u32 _command_buffer_count, const ktl::api::command_buffer * _p_command_buffers)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::free_command_buffers)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_free_command_buffers)ptr)(_device, _command_pool, _command_buffer_count, _p_command_buffers);
}

inline ktl::api::result begin_command_buffer(ktl::api::command_buffer _command_buffer, const ktl::api::command_buffer_begin_info * _p_begin_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::begin_command_buffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_begin_command_buffer)ptr)(_command_buffer, _p_begin_info);
}

inline ktl::api::result end_command_buffer(ktl::api::command_buffer _command_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::end_command_buffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_end_command_buffer)ptr)(_command_buffer);
}

inline ktl::api::result reset_command_buffer(ktl::api::command_buffer _command_buffer, ktl::api::command_buffer_reset_flags _flags)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::reset_command_buffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_reset_command_buffer)ptr)(_command_buffer, _flags);
}

inline void cmd_bind_pipeline(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_bind_point _pipeline_bind_point, ktl::api::pipeline _pipeline)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_pipeline)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_pipeline)ptr)(_command_buffer, _pipeline_bind_point, _pipeline);
}

inline void cmd_set_primitive_restart_index_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _primitive_restart_index)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_primitive_restart_index_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_primitive_restart_index_ext)ptr)(_command_buffer, _primitive_restart_index);
}

inline void cmd_set_attachment_feedback_loop_enable_ext(ktl::api::command_buffer _command_buffer, ktl::api::image_aspect_flags _aspect_mask)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_attachment_feedback_loop_enable_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_attachment_feedback_loop_enable_ext)ptr)(_command_buffer, _aspect_mask);
}

inline void cmd_set_viewport(ktl::api::command_buffer _command_buffer, ktl::u32 _first_viewport, ktl::u32 _viewport_count, const ktl::api::viewport * _p_viewports)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_viewport)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_viewport)ptr)(_command_buffer, _first_viewport, _viewport_count, _p_viewports);
}

inline void cmd_set_scissor(ktl::api::command_buffer _command_buffer, ktl::u32 _first_scissor, ktl::u32 _scissor_count, const ktl::api::rect_2d * _p_scissors)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_scissor)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_scissor)ptr)(_command_buffer, _first_scissor, _scissor_count, _p_scissors);
}

inline void cmd_set_line_width(ktl::api::command_buffer _command_buffer, float _line_width)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_line_width)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_line_width)ptr)(_command_buffer, _line_width);
}

inline void cmd_set_depth_bias(ktl::api::command_buffer _command_buffer, float _depth_bias_constant_factor, float _depth_bias_clamp, float _depth_bias_slope_factor)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_bias)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_bias)ptr)(_command_buffer, _depth_bias_constant_factor, _depth_bias_clamp, _depth_bias_slope_factor);
}

inline void cmd_set_blend_constants(ktl::api::command_buffer _command_buffer, const float _blend_constants[4])
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_blend_constants)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_blend_constants)ptr)(_command_buffer, _blend_constants);
}

inline void cmd_set_depth_bounds(ktl::api::command_buffer _command_buffer, float _min_depth_bounds, float _max_depth_bounds)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_bounds)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_bounds)ptr)(_command_buffer, _min_depth_bounds, _max_depth_bounds);
}

inline void cmd_set_stencil_compare_mask(ktl::api::command_buffer _command_buffer, ktl::api::stencil_face_flags _face_mask, ktl::u32 _compare_mask)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_stencil_compare_mask)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_stencil_compare_mask)ptr)(_command_buffer, _face_mask, _compare_mask);
}

inline void cmd_set_stencil_write_mask(ktl::api::command_buffer _command_buffer, ktl::api::stencil_face_flags _face_mask, ktl::u32 _write_mask)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_stencil_write_mask)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_stencil_write_mask)ptr)(_command_buffer, _face_mask, _write_mask);
}

inline void cmd_set_stencil_reference(ktl::api::command_buffer _command_buffer, ktl::api::stencil_face_flags _face_mask, ktl::u32 _reference)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_stencil_reference)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_stencil_reference)ptr)(_command_buffer, _face_mask, _reference);
}

inline void cmd_bind_descriptor_sets(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_bind_point _pipeline_bind_point, ktl::api::pipeline_layout _layout, ktl::u32 _first_set, ktl::u32 _descriptor_set_count, const ktl::api::descriptor_set * _p_descriptor_sets, ktl::u32 _dynamic_offset_count, const ktl::u32 * _p_dynamic_offsets)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_descriptor_sets)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_descriptor_sets)ptr)(_command_buffer, _pipeline_bind_point, _layout, _first_set, _descriptor_set_count, _p_descriptor_sets, _dynamic_offset_count, _p_dynamic_offsets);
}

inline void cmd_bind_index_buffer(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset, ktl::api::index_type _index_type)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_index_buffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_index_buffer)ptr)(_command_buffer, _buffer, _offset, _index_type);
}

inline void cmd_bind_vertex_buffers(ktl::api::command_buffer _command_buffer, ktl::u32 _first_binding, ktl::u32 _binding_count, const ktl::api::buffer * _p_buffers, const ktl::api::dvsize * _p_offsets)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_vertex_buffers)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_vertex_buffers)ptr)(_command_buffer, _first_binding, _binding_count, _p_buffers, _p_offsets);
}

inline void cmd_draw(ktl::api::command_buffer _command_buffer, ktl::u32 _vertex_count, ktl::u32 _instance_count, ktl::u32 _first_vertex, ktl::u32 _first_instance)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw)ptr)(_command_buffer, _vertex_count, _instance_count, _first_vertex, _first_instance);
}

inline void cmd_draw_indexed(ktl::api::command_buffer _command_buffer, ktl::u32 _index_count, ktl::u32 _instance_count, ktl::u32 _first_index, ktl::i32 _vertex_offset, ktl::u32 _first_instance)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_indexed)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_indexed)ptr)(_command_buffer, _index_count, _instance_count, _first_index, _vertex_offset, _first_instance);
}

inline void cmd_draw_multi_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _draw_count, const ktl::api::multi_draw_info_ext * _p_vertex_info, ktl::u32 _instance_count, ktl::u32 _first_instance, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_multi_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_multi_ext)ptr)(_command_buffer, _draw_count, _p_vertex_info, _instance_count, _first_instance, _stride);
}

inline void cmd_draw_multi_indexed_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _draw_count, const ktl::api::multi_draw_indexed_info_ext * _p_index_info, ktl::u32 _instance_count, ktl::u32 _first_instance, ktl::u32 _stride, const ktl::i32 * _p_vertex_offset)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_multi_indexed_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_multi_indexed_ext)ptr)(_command_buffer, _draw_count, _p_index_info, _instance_count, _first_instance, _stride, _p_vertex_offset);
}

inline void cmd_draw_indirect(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset, ktl::u32 _draw_count, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_indirect)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_indirect)ptr)(_command_buffer, _buffer, _offset, _draw_count, _stride);
}

inline void cmd_draw_indexed_indirect(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset, ktl::u32 _draw_count, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_indexed_indirect)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_indexed_indirect)ptr)(_command_buffer, _buffer, _offset, _draw_count, _stride);
}

inline void cmd_dispatch(ktl::api::command_buffer _command_buffer, ktl::u32 _group_count_x, ktl::u32 _group_count_y, ktl::u32 _group_count_z)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_dispatch)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_dispatch)ptr)(_command_buffer, _group_count_x, _group_count_y, _group_count_z);
}

inline void cmd_dispatch_indirect(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_dispatch_indirect)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_dispatch_indirect)ptr)(_command_buffer, _buffer, _offset);
}

inline void cmd_subpass_shading_huawei(ktl::api::command_buffer _command_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_subpass_shading_huawei)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_subpass_shading_huawei)ptr)(_command_buffer);
}

inline void cmd_draw_cluster_huawei(ktl::api::command_buffer _command_buffer, ktl::u32 _group_count_x, ktl::u32 _group_count_y, ktl::u32 _group_count_z)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_cluster_huawei)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_cluster_huawei)ptr)(_command_buffer, _group_count_x, _group_count_y, _group_count_z);
}

inline void cmd_draw_cluster_indirect_huawei(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_cluster_indirect_huawei)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_cluster_indirect_huawei)ptr)(_command_buffer, _buffer, _offset);
}

inline void cmd_update_pipeline_indirect_buffer_nv(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_bind_point _pipeline_bind_point, ktl::api::pipeline _pipeline)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_update_pipeline_indirect_buffer_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_update_pipeline_indirect_buffer_nv)ptr)(_command_buffer, _pipeline_bind_point, _pipeline);
}

inline void cmd_copy_buffer(ktl::api::command_buffer _command_buffer, ktl::api::buffer _src_buffer, ktl::api::buffer _dst_buffer, ktl::u32 _region_count, const ktl::api::buffer_copy * _p_regions)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_buffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_buffer)ptr)(_command_buffer, _src_buffer, _dst_buffer, _region_count, _p_regions);
}

inline void cmd_copy_image(ktl::api::command_buffer _command_buffer, ktl::api::image _src_image, ktl::api::image_layout _src_image_layout, ktl::api::image _dst_image, ktl::api::image_layout _dst_image_layout, ktl::u32 _region_count, const ktl::api::image_copy * _p_regions)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_image)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_image)ptr)(_command_buffer, _src_image, _src_image_layout, _dst_image, _dst_image_layout, _region_count, _p_regions);
}

inline void cmd_blit_image(ktl::api::command_buffer _command_buffer, ktl::api::image _src_image, ktl::api::image_layout _src_image_layout, ktl::api::image _dst_image, ktl::api::image_layout _dst_image_layout, ktl::u32 _region_count, const ktl::api::image_blit * _p_regions, ktl::api::filter _filter)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_blit_image)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_blit_image)ptr)(_command_buffer, _src_image, _src_image_layout, _dst_image, _dst_image_layout, _region_count, _p_regions, _filter);
}

inline void cmd_copy_buffer_to_image(ktl::api::command_buffer _command_buffer, ktl::api::buffer _src_buffer, ktl::api::image _dst_image, ktl::api::image_layout _dst_image_layout, ktl::u32 _region_count, const ktl::api::buffer_image_copy * _p_regions)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_buffer_to_image)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_buffer_to_image)ptr)(_command_buffer, _src_buffer, _dst_image, _dst_image_layout, _region_count, _p_regions);
}

inline void cmd_copy_image_to_buffer(ktl::api::command_buffer _command_buffer, ktl::api::image _src_image, ktl::api::image_layout _src_image_layout, ktl::api::buffer _dst_buffer, ktl::u32 _region_count, const ktl::api::buffer_image_copy * _p_regions)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_image_to_buffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_image_to_buffer)ptr)(_command_buffer, _src_image, _src_image_layout, _dst_buffer, _region_count, _p_regions);
}

inline void cmd_copy_memory_indirect_nv(ktl::api::command_buffer _command_buffer, ktl::api::dvaddr _copy_buffer_address, ktl::u32 _copy_count, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_memory_indirect_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_memory_indirect_nv)ptr)(_command_buffer, _copy_buffer_address, _copy_count, _stride);
}

inline void cmd_copy_memory_indirect_khr(ktl::api::command_buffer _command_buffer, const ktl::api::copy_memory_indirect_info_khr * _p_copy_memory_indirect_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_memory_indirect_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_memory_indirect_khr)ptr)(_command_buffer, _p_copy_memory_indirect_info);
}

inline void cmd_copy_memory_to_image_indirect_nv(ktl::api::command_buffer _command_buffer, ktl::api::dvaddr _copy_buffer_address, ktl::u32 _copy_count, ktl::u32 _stride, ktl::api::image _dst_image, ktl::api::image_layout _dst_image_layout, const ktl::api::image_subresource_layers * _p_image_subresources)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_memory_to_image_indirect_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_memory_to_image_indirect_nv)ptr)(_command_buffer, _copy_buffer_address, _copy_count, _stride, _dst_image, _dst_image_layout, _p_image_subresources);
}

inline void cmd_copy_memory_to_image_indirect_khr(ktl::api::command_buffer _command_buffer, const ktl::api::copy_memory_to_image_indirect_info_khr * _p_copy_memory_to_image_indirect_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_memory_to_image_indirect_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_memory_to_image_indirect_khr)ptr)(_command_buffer, _p_copy_memory_to_image_indirect_info);
}

inline void cmd_update_buffer(ktl::api::command_buffer _command_buffer, ktl::api::buffer _dst_buffer, ktl::api::dvsize _dst_offset, ktl::api::dvsize _data_size, const void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_update_buffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_update_buffer)ptr)(_command_buffer, _dst_buffer, _dst_offset, _data_size, _p_data);
}

inline void cmd_fill_buffer(ktl::api::command_buffer _command_buffer, ktl::api::buffer _dst_buffer, ktl::api::dvsize _dst_offset, ktl::api::dvsize _size, ktl::u32 _data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_fill_buffer)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_fill_buffer)ptr)(_command_buffer, _dst_buffer, _dst_offset, _size, _data);
}

inline void cmd_clear_color_image(ktl::api::command_buffer _command_buffer, ktl::api::image _image, ktl::api::image_layout _image_layout, const ktl::api::clear_color_value * _p_color, ktl::u32 _range_count, const ktl::api::image_subresource_range * _p_ranges)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_clear_color_image)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_clear_color_image)ptr)(_command_buffer, _image, _image_layout, _p_color, _range_count, _p_ranges);
}

inline void cmd_clear_depth_stencil_image(ktl::api::command_buffer _command_buffer, ktl::api::image _image, ktl::api::image_layout _image_layout, const ktl::api::clear_depth_stencil_value * _p_depth_stencil, ktl::u32 _range_count, const ktl::api::image_subresource_range * _p_ranges)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_clear_depth_stencil_image)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_clear_depth_stencil_image)ptr)(_command_buffer, _image, _image_layout, _p_depth_stencil, _range_count, _p_ranges);
}

inline void cmd_clear_attachments(ktl::api::command_buffer _command_buffer, ktl::u32 _attachment_count, const ktl::api::clear_attachment * _p_attachments, ktl::u32 _rect_count, const ktl::api::clear_rect * _p_rects)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_clear_attachments)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_clear_attachments)ptr)(_command_buffer, _attachment_count, _p_attachments, _rect_count, _p_rects);
}

inline void cmd_resolve_image(ktl::api::command_buffer _command_buffer, ktl::api::image _src_image, ktl::api::image_layout _src_image_layout, ktl::api::image _dst_image, ktl::api::image_layout _dst_image_layout, ktl::u32 _region_count, const ktl::api::image_resolve * _p_regions)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_resolve_image)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_resolve_image)ptr)(_command_buffer, _src_image, _src_image_layout, _dst_image, _dst_image_layout, _region_count, _p_regions);
}

inline void cmd_set_event(ktl::api::command_buffer _command_buffer, ktl::api::event _event, ktl::api::pipeline_stage_flags _stage_mask)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_event)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_event)ptr)(_command_buffer, _event, _stage_mask);
}

inline void cmd_reset_event(ktl::api::command_buffer _command_buffer, ktl::api::event _event, ktl::api::pipeline_stage_flags _stage_mask)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_reset_event)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_reset_event)ptr)(_command_buffer, _event, _stage_mask);
}

inline void cmd_wait_events(ktl::api::command_buffer _command_buffer, ktl::u32 _event_count, const ktl::api::event * _p_events, ktl::api::pipeline_stage_flags _src_stage_mask, ktl::api::pipeline_stage_flags _dst_stage_mask, ktl::u32 _memory_barrier_count, const ktl::api::memory_barrier * _p_memory_barriers, ktl::u32 _buffer_memory_barrier_count, const ktl::api::buffer_memory_barrier * _p_buffer_memory_barriers, ktl::u32 _image_memory_barrier_count, const ktl::api::image_memory_barrier * _p_image_memory_barriers)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_wait_events)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_wait_events)ptr)(_command_buffer, _event_count, _p_events, _src_stage_mask, _dst_stage_mask, _memory_barrier_count, _p_memory_barriers, _buffer_memory_barrier_count, _p_buffer_memory_barriers, _image_memory_barrier_count, _p_image_memory_barriers);
}

inline void cmd_pipeline_barrier(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_stage_flags _src_stage_mask, ktl::api::pipeline_stage_flags _dst_stage_mask, ktl::api::dependency_flags _dependency_flags, ktl::u32 _memory_barrier_count, const ktl::api::memory_barrier * _p_memory_barriers, ktl::u32 _buffer_memory_barrier_count, const ktl::api::buffer_memory_barrier * _p_buffer_memory_barriers, ktl::u32 _image_memory_barrier_count, const ktl::api::image_memory_barrier * _p_image_memory_barriers)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_pipeline_barrier)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_pipeline_barrier)ptr)(_command_buffer, _src_stage_mask, _dst_stage_mask, _dependency_flags, _memory_barrier_count, _p_memory_barriers, _buffer_memory_barrier_count, _p_buffer_memory_barriers, _image_memory_barrier_count, _p_image_memory_barriers);
}

inline void cmd_begin_query(ktl::api::command_buffer _command_buffer, ktl::api::query_pool _query_pool, ktl::u32 _query, ktl::api::query_control_flags _flags)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_query)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_query)ptr)(_command_buffer, _query_pool, _query, _flags);
}

inline void cmd_end_query(ktl::api::command_buffer _command_buffer, ktl::api::query_pool _query_pool, ktl::u32 _query)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_query)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_query)ptr)(_command_buffer, _query_pool, _query);
}

inline void cmd_begin_conditional_rendering_ext(ktl::api::command_buffer _command_buffer, const ktl::api::conditional_rendering_begin_info_ext * _p_conditional_rendering_begin)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_conditional_rendering_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_conditional_rendering_ext)ptr)(_command_buffer, _p_conditional_rendering_begin);
}

inline void cmd_end_conditional_rendering_ext(ktl::api::command_buffer _command_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_conditional_rendering_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_conditional_rendering_ext)ptr)(_command_buffer);
}

inline void cmd_begin_custom_resolve_ext(ktl::api::command_buffer _command_buffer, const ktl::api::begin_custom_resolve_info_ext * _p_begin_custom_resolve_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_custom_resolve_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_custom_resolve_ext)ptr)(_command_buffer, _p_begin_custom_resolve_info);
}

inline void cmd_reset_query_pool(ktl::api::command_buffer _command_buffer, ktl::api::query_pool _query_pool, ktl::u32 _first_query, ktl::u32 _query_count)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_reset_query_pool)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_reset_query_pool)ptr)(_command_buffer, _query_pool, _first_query, _query_count);
}

inline void cmd_write_timestamp(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_stage_flag_bits _pipeline_stage, ktl::api::query_pool _query_pool, ktl::u32 _query)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_write_timestamp)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_write_timestamp)ptr)(_command_buffer, _pipeline_stage, _query_pool, _query);
}

inline void cmd_copy_query_pool_results(ktl::api::command_buffer _command_buffer, ktl::api::query_pool _query_pool, ktl::u32 _first_query, ktl::u32 _query_count, ktl::api::buffer _dst_buffer, ktl::api::dvsize _dst_offset, ktl::api::dvsize _stride, ktl::api::query_result_flags _flags)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_query_pool_results)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_query_pool_results)ptr)(_command_buffer, _query_pool, _first_query, _query_count, _dst_buffer, _dst_offset, _stride, _flags);
}

inline void cmd_push_constants(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_layout _layout, ktl::api::shader_stage_flags _stage_flags, ktl::u32 _offset, ktl::u32 _size, const void * _p_values)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_push_constants)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_push_constants)ptr)(_command_buffer, _layout, _stage_flags, _offset, _size, _p_values);
}

inline void cmd_begin_render_pass(ktl::api::command_buffer _command_buffer, const ktl::api::render_pass_begin_info * _p_render_pass_begin, ktl::api::subpass_contents _contents)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_render_pass)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_render_pass)ptr)(_command_buffer, _p_render_pass_begin, _contents);
}

inline void cmd_next_subpass(ktl::api::command_buffer _command_buffer, ktl::api::subpass_contents _contents)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_next_subpass)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_next_subpass)ptr)(_command_buffer, _contents);
}

inline void cmd_end_render_pass(ktl::api::command_buffer _command_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_render_pass)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_render_pass)ptr)(_command_buffer);
}

inline void cmd_execute_commands(ktl::api::command_buffer _command_buffer, ktl::u32 _command_buffer_count, const ktl::api::command_buffer * _p_command_buffers)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_execute_commands)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_execute_commands)ptr)(_command_buffer, _command_buffer_count, _p_command_buffers);
}

inline ktl::api::result create_android_surface_khr(ktl::api::instance _instance, const ktl::api::android_surface_create_info_khr * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_android_surface_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_android_surface_khr)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::result create_surface_ohos(ktl::api::instance _instance, const ktl::api::surface_create_info_ohos * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_surface_ohos)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_surface_ohos)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::result get_physical_device_display_properties_khr(ktl::api::physical_device _physical_device, ktl::u32 * _p_property_count, ktl::api::display_properties_khr * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_display_properties_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_display_properties_khr)ptr)(_physical_device, _p_property_count, _p_properties);
}

inline ktl::api::result get_physical_device_display_plane_properties_khr(ktl::api::physical_device _physical_device, ktl::u32 * _p_property_count, ktl::api::display_plane_properties_khr * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_display_plane_properties_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_display_plane_properties_khr)ptr)(_physical_device, _p_property_count, _p_properties);
}

inline ktl::api::result get_display_plane_supported_displays_khr(ktl::api::physical_device _physical_device, ktl::u32 _plane_index, ktl::u32 * _p_display_count, ktl::api::display_khr * _p_displays)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_display_plane_supported_displays_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_display_plane_supported_displays_khr)ptr)(_physical_device, _plane_index, _p_display_count, _p_displays);
}

inline ktl::api::result get_display_mode_properties_khr(ktl::api::physical_device _physical_device, ktl::api::display_khr _display, ktl::u32 * _p_property_count, ktl::api::display_mode_properties_khr * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_display_mode_properties_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_display_mode_properties_khr)ptr)(_physical_device, _display, _p_property_count, _p_properties);
}

inline ktl::api::result create_display_mode_khr(ktl::api::physical_device _physical_device, ktl::api::display_khr _display, const ktl::api::display_mode_create_info_khr * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::display_mode_khr * _p_mode)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_display_mode_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_display_mode_khr)ptr)(_physical_device, _display, _p_create_info, _p_allocator, _p_mode);
}

inline ktl::api::result get_display_plane_capabilities_khr(ktl::api::physical_device _physical_device, ktl::api::display_mode_khr _mode, ktl::u32 _plane_index, ktl::api::display_plane_capabilities_khr * _p_capabilities)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_display_plane_capabilities_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_display_plane_capabilities_khr)ptr)(_physical_device, _mode, _plane_index, _p_capabilities);
}

inline ktl::api::result create_display_plane_surface_khr(ktl::api::instance _instance, const ktl::api::display_surface_create_info_khr * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_display_plane_surface_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_display_plane_surface_khr)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::result create_shared_swapchains_khr(ktl::api::device _device, ktl::u32 _swapchain_count, const ktl::api::swapchain_create_info_khr * _p_create_infos, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::swapchain_khr * _p_swapchains)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_shared_swapchains_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_shared_swapchains_khr)ptr)(_device, _swapchain_count, _p_create_infos, _p_allocator, _p_swapchains);
}

inline void destroy_surface_khr(ktl::api::instance _instance, ktl::api::surface_khr _surface, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_surface_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_surface_khr)ptr)(_instance, _surface, _p_allocator);
}

inline ktl::api::result get_physical_device_surface_support_khr(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, ktl::api::surface_khr _surface, ktl::api::bool32 * _p_supported)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_surface_support_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_surface_support_khr)ptr)(_physical_device, _queue_family_index, _surface, _p_supported);
}

inline ktl::api::result get_physical_device_surface_capabilities_khr(ktl::api::physical_device _physical_device, ktl::api::surface_khr _surface, ktl::api::surface_capabilities_khr * _p_surface_capabilities)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_surface_capabilities_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_surface_capabilities_khr)ptr)(_physical_device, _surface, _p_surface_capabilities);
}

inline ktl::api::result get_physical_device_surface_formats_khr(ktl::api::physical_device _physical_device, ktl::api::surface_khr _surface, ktl::u32 * _p_surface_format_count, ktl::api::surface_format_khr * _p_surface_formats)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_surface_formats_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_surface_formats_khr)ptr)(_physical_device, _surface, _p_surface_format_count, _p_surface_formats);
}

inline ktl::api::result get_physical_device_surface_present_modes_khr(ktl::api::physical_device _physical_device, ktl::api::surface_khr _surface, ktl::u32 * _p_present_mode_count, ktl::api::present_mode_khr * _p_present_modes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_surface_present_modes_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_surface_present_modes_khr)ptr)(_physical_device, _surface, _p_present_mode_count, _p_present_modes);
}

inline ktl::api::result create_swapchain_khr(ktl::api::device _device, const ktl::api::swapchain_create_info_khr * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::swapchain_khr * _p_swapchain)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_swapchain_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_swapchain_khr)ptr)(_device, _p_create_info, _p_allocator, _p_swapchain);
}

inline void destroy_swapchain_khr(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_swapchain_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_swapchain_khr)ptr)(_device, _swapchain, _p_allocator);
}

inline ktl::api::result get_swapchain_images_khr(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, ktl::u32 * _p_swapchain_image_count, ktl::api::image * _p_swapchain_images)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_swapchain_images_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_swapchain_images_khr)ptr)(_device, _swapchain, _p_swapchain_image_count, _p_swapchain_images);
}

inline ktl::api::result acquire_next_image_khr(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, ktl::u64 _timeout, ktl::api::semaphore _semaphore, ktl::api::fence _fence, ktl::u32 * _p_image_index)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::acquire_next_image_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_acquire_next_image_khr)ptr)(_device, _swapchain, _timeout, _semaphore, _fence, _p_image_index);
}

inline ktl::api::result queue_present_khr(ktl::api::queue _queue, const ktl::api::present_info_khr * _p_present_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_present_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_present_khr)ptr)(_queue, _p_present_info);
}

inline ktl::api::result create_vi_surface_nn(ktl::api::instance _instance, const ktl::api::vi_surface_create_info_nn * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_vi_surface_nn)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_vi_surface_nn)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::result create_wayland_surface_khr(ktl::api::instance _instance, const ktl::api::wayland_surface_create_info_khr * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_wayland_surface_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_wayland_surface_khr)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::bool32 get_physical_device_wayland_presentation_support_khr(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, wl_display * _display)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_wayland_presentation_support_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_wayland_presentation_support_khr)ptr)(_physical_device, _queue_family_index, _display);
}

inline ktl::api::result create_ubm_surface_sec(ktl::api::instance _instance, const ktl::api::ubm_surface_create_info_sec * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_ubm_surface_sec)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_ubm_surface_sec)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::bool32 get_physical_device_ubm_presentation_support_sec(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, ubm_device * _device)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_ubm_presentation_support_sec)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_ubm_presentation_support_sec)ptr)(_physical_device, _queue_family_index, _device);
}

inline ktl::api::result create_win_32surface_khr(ktl::api::instance _instance, const ktl::api::win_32surface_create_info_khr * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_win_32surface_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_win_32surface_khr)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::bool32 get_physical_device_win_32presentation_support_khr(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_win_32presentation_support_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_win_32presentation_support_khr)ptr)(_physical_device, _queue_family_index);
}

inline ktl::api::result create_xlib_surface_khr(ktl::api::instance _instance, const ktl::api::xlib_surface_create_info_khr * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_xlib_surface_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_xlib_surface_khr)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::bool32 get_physical_device_xlib_presentation_support_khr(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, Display * _dpy, VisualID _visual_id)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_xlib_presentation_support_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_xlib_presentation_support_khr)ptr)(_physical_device, _queue_family_index, _dpy, _visual_id);
}

inline ktl::api::result create_xcb_surface_khr(ktl::api::instance _instance, const ktl::api::xcb_surface_create_info_khr * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_xcb_surface_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_xcb_surface_khr)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::bool32 get_physical_device_xcb_presentation_support_khr(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, xcb_connection_t * _connection, xcb_visualid_t _visual_id)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_xcb_presentation_support_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_xcb_presentation_support_khr)ptr)(_physical_device, _queue_family_index, _connection, _visual_id);
}

inline ktl::api::result create_direct_fb_surface_ext(ktl::api::instance _instance, const ktl::api::direct_fb_surface_create_info_ext * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_direct_fb_surface_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_direct_fb_surface_ext)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::bool32 get_physical_device_direct_fb_presentation_support_ext(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, IDirectFB * _dfb)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_direct_fb_presentation_support_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_direct_fb_presentation_support_ext)ptr)(_physical_device, _queue_family_index, _dfb);
}

inline ktl::api::result create_image_pipe_surface_fuchsia(ktl::api::instance _instance, const ktl::api::image_pipe_surface_create_info_fuchsia * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_image_pipe_surface_fuchsia)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_image_pipe_surface_fuchsia)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::result create_stream_descriptor_surface_ggp(ktl::api::instance _instance, const ktl::api::stream_descriptor_surface_create_info_ggp * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_stream_descriptor_surface_ggp)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_stream_descriptor_surface_ggp)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::result create_screen_surface_qnx(ktl::api::instance _instance, const ktl::api::screen_surface_create_info_qnx * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_screen_surface_qnx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_screen_surface_qnx)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::bool32 get_physical_device_screen_presentation_support_qnx(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, _screen_window * _window)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_screen_presentation_support_qnx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_screen_presentation_support_qnx)ptr)(_physical_device, _queue_family_index, _window);
}

inline ktl::api::result create_debug_report_callback_ext(ktl::api::instance _instance, const ktl::api::debug_report_callback_create_info_ext * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::debug_report_callback_ext * _p_callback)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_debug_report_callback_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_debug_report_callback_ext)ptr)(_instance, _p_create_info, _p_allocator, _p_callback);
}

inline void destroy_debug_report_callback_ext(ktl::api::instance _instance, ktl::api::debug_report_callback_ext _callback, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_debug_report_callback_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_debug_report_callback_ext)ptr)(_instance, _callback, _p_allocator);
}

inline void debug_report_message_ext(ktl::api::instance _instance, ktl::api::debug_report_flags_ext _flags, ktl::api::debug_report_object_type_ext _object_type, ktl::u64 _object, ktl::usize _location, ktl::i32 _message_code, const char * _p_layer_prefix, const char * _p_message)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::debug_report_message_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_debug_report_message_ext)ptr)(_instance, _flags, _object_type, _object, _location, _message_code, _p_layer_prefix, _p_message);
}

inline ktl::api::result debug_marker_set_object_name_ext(ktl::api::device _device, const ktl::api::debug_marker_object_name_info_ext * _p_name_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::debug_marker_set_object_name_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_debug_marker_set_object_name_ext)ptr)(_device, _p_name_info);
}

inline ktl::api::result debug_marker_set_object_tag_ext(ktl::api::device _device, const ktl::api::debug_marker_object_tag_info_ext * _p_tag_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::debug_marker_set_object_tag_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_debug_marker_set_object_tag_ext)ptr)(_device, _p_tag_info);
}

inline void cmd_debug_marker_begin_ext(ktl::api::command_buffer _command_buffer, const ktl::api::debug_marker_marker_info_ext * _p_marker_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_debug_marker_begin_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_debug_marker_begin_ext)ptr)(_command_buffer, _p_marker_info);
}

inline void cmd_debug_marker_end_ext(ktl::api::command_buffer _command_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_debug_marker_end_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_debug_marker_end_ext)ptr)(_command_buffer);
}

inline void cmd_debug_marker_insert_ext(ktl::api::command_buffer _command_buffer, const ktl::api::debug_marker_marker_info_ext * _p_marker_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_debug_marker_insert_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_debug_marker_insert_ext)ptr)(_command_buffer, _p_marker_info);
}

inline ktl::api::result get_physical_device_external_image_format_properties_nv(ktl::api::physical_device _physical_device, ktl::api::format _format, ktl::api::image_type _type, ktl::api::image_tiling _tiling, ktl::api::image_usage_flags _usage, ktl::api::image_create_flags _flags, ktl::api::external_memory_handle_type_flags_nv _external_handle_type, ktl::api::external_image_format_properties_nv * _p_external_image_format_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_external_image_format_properties_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_external_image_format_properties_nv)ptr)(_physical_device, _format, _type, _tiling, _usage, _flags, _external_handle_type, _p_external_image_format_properties);
}

inline ktl::api::result get_memory_win_32handle_nv(ktl::api::device _device, ktl::api::device_memory _memory, ktl::api::external_memory_handle_type_flags_nv _handle_type, HANDLE * _p_handle)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_win_32handle_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_win_32handle_nv)ptr)(_device, _memory, _handle_type, _p_handle);
}

inline void cmd_execute_generated_commands_nv(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _is_preprocessed, const ktl::api::generated_commands_info_nv * _p_generated_commands_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_execute_generated_commands_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_execute_generated_commands_nv)ptr)(_command_buffer, _is_preprocessed, _p_generated_commands_info);
}

inline void cmd_preprocess_generated_commands_nv(ktl::api::command_buffer _command_buffer, const ktl::api::generated_commands_info_nv * _p_generated_commands_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_preprocess_generated_commands_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_preprocess_generated_commands_nv)ptr)(_command_buffer, _p_generated_commands_info);
}

inline void cmd_bind_pipeline_shader_group_nv(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_bind_point _pipeline_bind_point, ktl::api::pipeline _pipeline, ktl::u32 _group_index)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_pipeline_shader_group_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_pipeline_shader_group_nv)ptr)(_command_buffer, _pipeline_bind_point, _pipeline, _group_index);
}

inline void get_generated_commands_memory_requirements_nv(ktl::api::device _device, const ktl::api::generated_commands_memory_requirements_info_nv * _p_info, ktl::api::memory_requirements_2 * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_generated_commands_memory_requirements_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_generated_commands_memory_requirements_nv)ptr)(_device, _p_info, _p_memory_requirements);
}

inline ktl::api::result create_indirect_commands_layout_nv(ktl::api::device _device, const ktl::api::indirect_commands_layout_create_info_nv * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::indirect_commands_layout_nv * _p_indirect_commands_layout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_indirect_commands_layout_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_indirect_commands_layout_nv)ptr)(_device, _p_create_info, _p_allocator, _p_indirect_commands_layout);
}

inline void destroy_indirect_commands_layout_nv(ktl::api::device _device, ktl::api::indirect_commands_layout_nv _indirect_commands_layout, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_indirect_commands_layout_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_indirect_commands_layout_nv)ptr)(_device, _indirect_commands_layout, _p_allocator);
}

inline void cmd_execute_generated_commands_ext(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _is_preprocessed, const ktl::api::generated_commands_info_ext * _p_generated_commands_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_execute_generated_commands_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_execute_generated_commands_ext)ptr)(_command_buffer, _is_preprocessed, _p_generated_commands_info);
}

inline void cmd_preprocess_generated_commands_ext(ktl::api::command_buffer _command_buffer, const ktl::api::generated_commands_info_ext * _p_generated_commands_info, ktl::api::command_buffer _state_command_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_preprocess_generated_commands_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_preprocess_generated_commands_ext)ptr)(_command_buffer, _p_generated_commands_info, _state_command_buffer);
}

inline void get_generated_commands_memory_requirements_ext(ktl::api::device _device, const ktl::api::generated_commands_memory_requirements_info_ext * _p_info, ktl::api::memory_requirements_2 * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_generated_commands_memory_requirements_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_generated_commands_memory_requirements_ext)ptr)(_device, _p_info, _p_memory_requirements);
}

inline ktl::api::result create_indirect_commands_layout_ext(ktl::api::device _device, const ktl::api::indirect_commands_layout_create_info_ext * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::indirect_commands_layout_ext * _p_indirect_commands_layout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_indirect_commands_layout_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_indirect_commands_layout_ext)ptr)(_device, _p_create_info, _p_allocator, _p_indirect_commands_layout);
}

inline void destroy_indirect_commands_layout_ext(ktl::api::device _device, ktl::api::indirect_commands_layout_ext _indirect_commands_layout, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_indirect_commands_layout_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_indirect_commands_layout_ext)ptr)(_device, _indirect_commands_layout, _p_allocator);
}

inline ktl::api::result create_indirect_execution_set_ext(ktl::api::device _device, const ktl::api::indirect_execution_set_create_info_ext * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::indirect_execution_set_ext * _p_indirect_execution_set)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_indirect_execution_set_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_indirect_execution_set_ext)ptr)(_device, _p_create_info, _p_allocator, _p_indirect_execution_set);
}

inline void destroy_indirect_execution_set_ext(ktl::api::device _device, ktl::api::indirect_execution_set_ext _indirect_execution_set, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_indirect_execution_set_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_indirect_execution_set_ext)ptr)(_device, _indirect_execution_set, _p_allocator);
}

inline void update_indirect_execution_set_pipeline_ext(ktl::api::device _device, ktl::api::indirect_execution_set_ext _indirect_execution_set, ktl::u32 _execution_set_write_count, const ktl::api::write_indirect_execution_set_pipeline_ext * _p_execution_set_writes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::update_indirect_execution_set_pipeline_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_update_indirect_execution_set_pipeline_ext)ptr)(_device, _indirect_execution_set, _execution_set_write_count, _p_execution_set_writes);
}

inline void update_indirect_execution_set_shader_ext(ktl::api::device _device, ktl::api::indirect_execution_set_ext _indirect_execution_set, ktl::u32 _execution_set_write_count, const ktl::api::write_indirect_execution_set_shader_ext * _p_execution_set_writes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::update_indirect_execution_set_shader_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_update_indirect_execution_set_shader_ext)ptr)(_device, _indirect_execution_set, _execution_set_write_count, _p_execution_set_writes);
}

inline void get_physical_device_features_2(ktl::api::physical_device _physical_device, ktl::api::physical_device_features_2 * _p_features)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_features_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_features_2)ptr)(_physical_device, _p_features);
}

inline void get_physical_device_properties_2(ktl::api::physical_device _physical_device, ktl::api::physical_device_properties_2 * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_properties_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_properties_2)ptr)(_physical_device, _p_properties);
}

inline void get_physical_device_format_properties_2(ktl::api::physical_device _physical_device, ktl::api::format _format, ktl::api::format_properties_2 * _p_format_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_format_properties_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_format_properties_2)ptr)(_physical_device, _format, _p_format_properties);
}

inline ktl::api::result get_physical_device_image_format_properties_2(ktl::api::physical_device _physical_device, const ktl::api::physical_device_image_format_info_2 * _p_image_format_info, ktl::api::image_format_properties_2 * _p_image_format_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_image_format_properties_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_image_format_properties_2)ptr)(_physical_device, _p_image_format_info, _p_image_format_properties);
}

inline void get_physical_device_queue_family_properties_2(ktl::api::physical_device _physical_device, ktl::u32 * _p_queue_family_property_count, ktl::api::queue_family_properties_2 * _p_queue_family_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_queue_family_properties_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_queue_family_properties_2)ptr)(_physical_device, _p_queue_family_property_count, _p_queue_family_properties);
}

inline void get_physical_device_memory_properties_2(ktl::api::physical_device _physical_device, ktl::api::physical_device_memory_properties_2 * _p_memory_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_memory_properties_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_memory_properties_2)ptr)(_physical_device, _p_memory_properties);
}

inline void get_physical_device_sparse_image_format_properties_2(ktl::api::physical_device _physical_device, const ktl::api::physical_device_sparse_image_format_info_2 * _p_format_info, ktl::u32 * _p_property_count, ktl::api::sparse_image_format_properties_2 * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_sparse_image_format_properties_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_sparse_image_format_properties_2)ptr)(_physical_device, _p_format_info, _p_property_count, _p_properties);
}

inline void cmd_push_descriptor_set(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_bind_point _pipeline_bind_point, ktl::api::pipeline_layout _layout, ktl::u32 _set, ktl::u32 _descriptor_write_count, const ktl::api::write_descriptor_set * _p_descriptor_writes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_push_descriptor_set)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_push_descriptor_set)ptr)(_command_buffer, _pipeline_bind_point, _layout, _set, _descriptor_write_count, _p_descriptor_writes);
}

inline void trim_command_pool(ktl::api::device _device, ktl::api::command_pool _command_pool, ktl::api::command_pool_trim_flags _flags)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::trim_command_pool)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_trim_command_pool)ptr)(_device, _command_pool, _flags);
}

inline void get_physical_device_external_buffer_properties(ktl::api::physical_device _physical_device, const ktl::api::physical_device_external_buffer_info * _p_external_buffer_info, ktl::api::external_buffer_properties * _p_external_buffer_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_external_buffer_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_external_buffer_properties)ptr)(_physical_device, _p_external_buffer_info, _p_external_buffer_properties);
}

inline ktl::api::result get_memory_win_32handle_khr(ktl::api::device _device, const ktl::api::memory_get_win_32handle_info_khr * _p_get_win_32handle_info, HANDLE * _p_handle)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_win_32handle_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_win_32handle_khr)ptr)(_device, _p_get_win_32handle_info, _p_handle);
}

inline ktl::api::result get_memory_win_32handle_properties_khr(ktl::api::device _device, ktl::api::external_memory_handle_type_flag_bits _handle_type, HANDLE _handle, ktl::api::memory_win_32handle_properties_khr * _p_memory_win_32handle_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_win_32handle_properties_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_win_32handle_properties_khr)ptr)(_device, _handle_type, _handle, _p_memory_win_32handle_properties);
}

inline ktl::api::result get_memory_fd_khr(ktl::api::device _device, const ktl::api::memory_get_fd_info_khr * _p_get_fd_info, int * _p_fd)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_fd_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_fd_khr)ptr)(_device, _p_get_fd_info, _p_fd);
}

inline ktl::api::result get_memory_fd_properties_khr(ktl::api::device _device, ktl::api::external_memory_handle_type_flag_bits _handle_type, int _fd, ktl::api::memory_fd_properties_khr * _p_memory_fd_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_fd_properties_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_fd_properties_khr)ptr)(_device, _handle_type, _fd, _p_memory_fd_properties);
}

inline ktl::api::result get_memory_zircon_handle_fuchsia(ktl::api::device _device, const ktl::api::memory_get_zircon_handle_info_fuchsia * _p_get_zircon_handle_info, zx_handle_t * _p_zircon_handle)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_zircon_handle_fuchsia)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_zircon_handle_fuchsia)ptr)(_device, _p_get_zircon_handle_info, _p_zircon_handle);
}

inline ktl::api::result get_memory_zircon_handle_properties_fuchsia(ktl::api::device _device, ktl::api::external_memory_handle_type_flag_bits _handle_type, zx_handle_t _zircon_handle, ktl::api::memory_zircon_handle_properties_fuchsia * _p_memory_zircon_handle_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_zircon_handle_properties_fuchsia)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_zircon_handle_properties_fuchsia)ptr)(_device, _handle_type, _zircon_handle, _p_memory_zircon_handle_properties);
}

inline ktl::api::result get_memory_remote_address_nv(ktl::api::device _device, const ktl::api::memory_get_remote_address_info_nv * _p_memory_get_remote_address_info, ktl::api::remote_address_nv * _p_address)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_remote_address_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_remote_address_nv)ptr)(_device, _p_memory_get_remote_address_info, _p_address);
}

inline ktl::api::result get_memory_sci_buf_nv(ktl::api::device _device, const ktl::api::memory_get_sci_buf_info_nv * _p_get_sci_buf_info, NvSciBufObj * _p_handle)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_sci_buf_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_sci_buf_nv)ptr)(_device, _p_get_sci_buf_info, _p_handle);
}

inline ktl::api::result get_physical_device_external_memory_sci_buf_properties_nv(ktl::api::physical_device _physical_device, ktl::api::external_memory_handle_type_flag_bits _handle_type, NvSciBufObj _handle, ktl::api::memory_sci_buf_properties_nv * _p_memory_sci_buf_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_external_memory_sci_buf_properties_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_external_memory_sci_buf_properties_nv)ptr)(_physical_device, _handle_type, _handle, _p_memory_sci_buf_properties);
}

inline ktl::api::result get_physical_device_sci_buf_attributes_nv(ktl::api::physical_device _physical_device, NvSciBufAttrList _p_attributes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_sci_buf_attributes_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_sci_buf_attributes_nv)ptr)(_physical_device, _p_attributes);
}

inline void get_physical_device_external_semaphore_properties(ktl::api::physical_device _physical_device, const ktl::api::physical_device_external_semaphore_info * _p_external_semaphore_info, ktl::api::external_semaphore_properties * _p_external_semaphore_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_external_semaphore_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_external_semaphore_properties)ptr)(_physical_device, _p_external_semaphore_info, _p_external_semaphore_properties);
}

inline ktl::api::result get_semaphore_win_32handle_khr(ktl::api::device _device, const ktl::api::semaphore_get_win_32handle_info_khr * _p_get_win_32handle_info, HANDLE * _p_handle)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_semaphore_win_32handle_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_semaphore_win_32handle_khr)ptr)(_device, _p_get_win_32handle_info, _p_handle);
}

inline ktl::api::result import_semaphore_win_32handle_khr(ktl::api::device _device, const ktl::api::import_semaphore_win_32handle_info_khr * _p_import_semaphore_win_32handle_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::import_semaphore_win_32handle_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_import_semaphore_win_32handle_khr)ptr)(_device, _p_import_semaphore_win_32handle_info);
}

inline ktl::api::result get_semaphore_fd_khr(ktl::api::device _device, const ktl::api::semaphore_get_fd_info_khr * _p_get_fd_info, int * _p_fd)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_semaphore_fd_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_semaphore_fd_khr)ptr)(_device, _p_get_fd_info, _p_fd);
}

inline ktl::api::result import_semaphore_fd_khr(ktl::api::device _device, const ktl::api::import_semaphore_fd_info_khr * _p_import_semaphore_fd_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::import_semaphore_fd_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_import_semaphore_fd_khr)ptr)(_device, _p_import_semaphore_fd_info);
}

inline ktl::api::result get_semaphore_zircon_handle_fuchsia(ktl::api::device _device, const ktl::api::semaphore_get_zircon_handle_info_fuchsia * _p_get_zircon_handle_info, zx_handle_t * _p_zircon_handle)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_semaphore_zircon_handle_fuchsia)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_semaphore_zircon_handle_fuchsia)ptr)(_device, _p_get_zircon_handle_info, _p_zircon_handle);
}

inline ktl::api::result import_semaphore_zircon_handle_fuchsia(ktl::api::device _device, const ktl::api::import_semaphore_zircon_handle_info_fuchsia * _p_import_semaphore_zircon_handle_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::import_semaphore_zircon_handle_fuchsia)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_import_semaphore_zircon_handle_fuchsia)ptr)(_device, _p_import_semaphore_zircon_handle_info);
}

inline void get_physical_device_external_fence_properties(ktl::api::physical_device _physical_device, const ktl::api::physical_device_external_fence_info * _p_external_fence_info, ktl::api::external_fence_properties * _p_external_fence_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_external_fence_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_external_fence_properties)ptr)(_physical_device, _p_external_fence_info, _p_external_fence_properties);
}

inline ktl::api::result get_fence_win_32handle_khr(ktl::api::device _device, const ktl::api::fence_get_win_32handle_info_khr * _p_get_win_32handle_info, HANDLE * _p_handle)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_fence_win_32handle_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_fence_win_32handle_khr)ptr)(_device, _p_get_win_32handle_info, _p_handle);
}

inline ktl::api::result import_fence_win_32handle_khr(ktl::api::device _device, const ktl::api::import_fence_win_32handle_info_khr * _p_import_fence_win_32handle_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::import_fence_win_32handle_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_import_fence_win_32handle_khr)ptr)(_device, _p_import_fence_win_32handle_info);
}

inline ktl::api::result get_fence_fd_khr(ktl::api::device _device, const ktl::api::fence_get_fd_info_khr * _p_get_fd_info, int * _p_fd)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_fence_fd_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_fence_fd_khr)ptr)(_device, _p_get_fd_info, _p_fd);
}

inline ktl::api::result import_fence_fd_khr(ktl::api::device _device, const ktl::api::import_fence_fd_info_khr * _p_import_fence_fd_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::import_fence_fd_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_import_fence_fd_khr)ptr)(_device, _p_import_fence_fd_info);
}

inline ktl::api::result get_fence_sci_sync_fence_nv(ktl::api::device _device, const ktl::api::fence_get_sci_sync_info_nv * _p_get_sci_sync_handle_info, void * _p_handle)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_fence_sci_sync_fence_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_fence_sci_sync_fence_nv)ptr)(_device, _p_get_sci_sync_handle_info, _p_handle);
}

inline ktl::api::result get_fence_sci_sync_obj_nv(ktl::api::device _device, const ktl::api::fence_get_sci_sync_info_nv * _p_get_sci_sync_handle_info, void * _p_handle)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_fence_sci_sync_obj_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_fence_sci_sync_obj_nv)ptr)(_device, _p_get_sci_sync_handle_info, _p_handle);
}

inline ktl::api::result import_fence_sci_sync_fence_nv(ktl::api::device _device, const ktl::api::import_fence_sci_sync_info_nv * _p_import_fence_sci_sync_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::import_fence_sci_sync_fence_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_import_fence_sci_sync_fence_nv)ptr)(_device, _p_import_fence_sci_sync_info);
}

inline ktl::api::result import_fence_sci_sync_obj_nv(ktl::api::device _device, const ktl::api::import_fence_sci_sync_info_nv * _p_import_fence_sci_sync_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::import_fence_sci_sync_obj_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_import_fence_sci_sync_obj_nv)ptr)(_device, _p_import_fence_sci_sync_info);
}

inline ktl::api::result get_semaphore_sci_sync_obj_nv(ktl::api::device _device, const ktl::api::semaphore_get_sci_sync_info_nv * _p_get_sci_sync_info, void * _p_handle)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_semaphore_sci_sync_obj_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_semaphore_sci_sync_obj_nv)ptr)(_device, _p_get_sci_sync_info, _p_handle);
}

inline ktl::api::result import_semaphore_sci_sync_obj_nv(ktl::api::device _device, const ktl::api::import_semaphore_sci_sync_info_nv * _p_import_semaphore_sci_sync_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::import_semaphore_sci_sync_obj_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_import_semaphore_sci_sync_obj_nv)ptr)(_device, _p_import_semaphore_sci_sync_info);
}

inline ktl::api::result get_physical_device_sci_sync_attributes_nv(ktl::api::physical_device _physical_device, const ktl::api::sci_sync_attributes_info_nv * _p_sci_sync_attributes_info, NvSciSyncAttrList _p_attributes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_sci_sync_attributes_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_sci_sync_attributes_nv)ptr)(_physical_device, _p_sci_sync_attributes_info, _p_attributes);
}

inline ktl::api::result create_semaphore_sci_sync_pool_nv(ktl::api::device _device, const ktl::api::semaphore_sci_sync_pool_create_info_nv * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::semaphore_sci_sync_pool_nv * _p_semaphore_pool)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_semaphore_sci_sync_pool_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_semaphore_sci_sync_pool_nv)ptr)(_device, _p_create_info, _p_allocator, _p_semaphore_pool);
}

inline void destroy_semaphore_sci_sync_pool_nv(ktl::api::device _device, ktl::api::semaphore_sci_sync_pool_nv _semaphore_pool, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_semaphore_sci_sync_pool_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_semaphore_sci_sync_pool_nv)ptr)(_device, _semaphore_pool, _p_allocator);
}

inline ktl::api::result release_display_ext(ktl::api::physical_device _physical_device, ktl::api::display_khr _display)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::release_display_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_release_display_ext)ptr)(_physical_device, _display);
}

inline ktl::api::result acquire_xlib_display_ext(ktl::api::physical_device _physical_device, Display * _dpy, ktl::api::display_khr _display)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::acquire_xlib_display_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_acquire_xlib_display_ext)ptr)(_physical_device, _dpy, _display);
}

inline ktl::api::result get_rand_r_output_display_ext(ktl::api::physical_device _physical_device, Display * _dpy, RROutput _rr_output, ktl::api::display_khr * _p_display)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_rand_r_output_display_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_rand_r_output_display_ext)ptr)(_physical_device, _dpy, _rr_output, _p_display);
}

inline ktl::api::result acquire_winrt_display_nv(ktl::api::physical_device _physical_device, ktl::api::display_khr _display)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::acquire_winrt_display_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_acquire_winrt_display_nv)ptr)(_physical_device, _display);
}

inline ktl::api::result get_winrt_display_nv(ktl::api::physical_device _physical_device, ktl::u32 _device_relative_id, ktl::api::display_khr * _p_display)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_winrt_display_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_winrt_display_nv)ptr)(_physical_device, _device_relative_id, _p_display);
}

inline ktl::api::result display_power_control_ext(ktl::api::device _device, ktl::api::display_khr _display, const ktl::api::display_power_info_ext * _p_display_power_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::display_power_control_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_display_power_control_ext)ptr)(_device, _display, _p_display_power_info);
}

inline ktl::api::result register_device_event_ext(ktl::api::device _device, const ktl::api::device_event_info_ext * _p_device_event_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::fence * _p_fence)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::register_device_event_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_register_device_event_ext)ptr)(_device, _p_device_event_info, _p_allocator, _p_fence);
}

inline ktl::api::result register_display_event_ext(ktl::api::device _device, ktl::api::display_khr _display, const ktl::api::display_event_info_ext * _p_display_event_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::fence * _p_fence)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::register_display_event_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_register_display_event_ext)ptr)(_device, _display, _p_display_event_info, _p_allocator, _p_fence);
}

inline ktl::api::result get_swapchain_counter_ext(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, ktl::api::surface_counter_flag_bits_ext _counter, ktl::u64 * _p_counter_value)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_swapchain_counter_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_swapchain_counter_ext)ptr)(_device, _swapchain, _counter, _p_counter_value);
}

inline ktl::api::result get_physical_device_surface_capabilities_2ext(ktl::api::physical_device _physical_device, ktl::api::surface_khr _surface, ktl::api::surface_capabilities_2ext * _p_surface_capabilities)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_surface_capabilities_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_surface_capabilities_2ext)ptr)(_physical_device, _surface, _p_surface_capabilities);
}

inline ktl::api::result enumerate_physical_device_groups(ktl::api::instance _instance, ktl::u32 * _p_physical_device_group_count, ktl::api::physical_device_group_properties * _p_physical_device_group_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::enumerate_physical_device_groups)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_enumerate_physical_device_groups)ptr)(_instance, _p_physical_device_group_count, _p_physical_device_group_properties);
}

inline void get_device_group_peer_memory_features(ktl::api::device _device, ktl::u32 _heap_index, ktl::u32 _local_device_index, ktl::u32 _remote_device_index, ktl::api::peer_memory_feature_flags * _p_peer_memory_features)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_group_peer_memory_features)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_group_peer_memory_features)ptr)(_device, _heap_index, _local_device_index, _remote_device_index, _p_peer_memory_features);
}

inline ktl::api::result bind_buffer_memory_2(ktl::api::device _device, ktl::u32 _bind_info_count, const ktl::api::bind_buffer_memory_info * _p_bind_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::bind_buffer_memory_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_bind_buffer_memory_2)ptr)(_device, _bind_info_count, _p_bind_infos);
}

inline ktl::api::result bind_image_memory_2(ktl::api::device _device, ktl::u32 _bind_info_count, const ktl::api::bind_image_memory_info * _p_bind_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::bind_image_memory_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_bind_image_memory_2)ptr)(_device, _bind_info_count, _p_bind_infos);
}

inline void cmd_set_device_mask(ktl::api::command_buffer _command_buffer, ktl::u32 _device_mask)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_device_mask)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_device_mask)ptr)(_command_buffer, _device_mask);
}

inline ktl::api::result get_device_group_present_capabilities_khr(ktl::api::device _device, ktl::api::device_group_present_capabilities_khr * _p_device_group_present_capabilities)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_group_present_capabilities_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_group_present_capabilities_khr)ptr)(_device, _p_device_group_present_capabilities);
}

inline ktl::api::result get_device_group_surface_present_modes_khr(ktl::api::device _device, ktl::api::surface_khr _surface, ktl::api::device_group_present_mode_flags_khr * _p_modes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_group_surface_present_modes_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_group_surface_present_modes_khr)ptr)(_device, _surface, _p_modes);
}

inline ktl::api::result acquire_next_image_2khr(ktl::api::device _device, const ktl::api::acquire_next_image_info_khr * _p_acquire_info, ktl::u32 * _p_image_index)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::acquire_next_image_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_acquire_next_image_2khr)ptr)(_device, _p_acquire_info, _p_image_index);
}

inline void cmd_dispatch_base(ktl::api::command_buffer _command_buffer, ktl::u32 _base_group_x, ktl::u32 _base_group_y, ktl::u32 _base_group_z, ktl::u32 _group_count_x, ktl::u32 _group_count_y, ktl::u32 _group_count_z)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_dispatch_base)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_dispatch_base)ptr)(_command_buffer, _base_group_x, _base_group_y, _base_group_z, _group_count_x, _group_count_y, _group_count_z);
}

inline ktl::api::result get_physical_device_present_rectangles_khr(ktl::api::physical_device _physical_device, ktl::api::surface_khr _surface, ktl::u32 * _p_rect_count, ktl::api::rect_2d * _p_rects)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_present_rectangles_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_present_rectangles_khr)ptr)(_physical_device, _surface, _p_rect_count, _p_rects);
}

inline ktl::api::result create_descriptor_update_template(ktl::api::device _device, const ktl::api::descriptor_update_template_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::descriptor_update_template * _p_descriptor_update_template)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_descriptor_update_template)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_descriptor_update_template)ptr)(_device, _p_create_info, _p_allocator, _p_descriptor_update_template);
}

inline void destroy_descriptor_update_template(ktl::api::device _device, ktl::api::descriptor_update_template _descriptor_update_template, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_descriptor_update_template)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_descriptor_update_template)ptr)(_device, _descriptor_update_template, _p_allocator);
}

inline void update_descriptor_set_with_template(ktl::api::device _device, ktl::api::descriptor_set _descriptor_set, ktl::api::descriptor_update_template _descriptor_update_template, const void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::update_descriptor_set_with_template)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_update_descriptor_set_with_template)ptr)(_device, _descriptor_set, _descriptor_update_template, _p_data);
}

inline void cmd_push_descriptor_set_with_template(ktl::api::command_buffer _command_buffer, ktl::api::descriptor_update_template _descriptor_update_template, ktl::api::pipeline_layout _layout, ktl::u32 _set, const void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_push_descriptor_set_with_template)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_push_descriptor_set_with_template)ptr)(_command_buffer, _descriptor_update_template, _layout, _set, _p_data);
}

inline void set_hdr_metadata_ext(ktl::api::device _device, ktl::u32 _swapchain_count, const ktl::api::swapchain_khr * _p_swapchains, const ktl::api::hdr_metadata_ext * _p_metadata)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_hdr_metadata_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_hdr_metadata_ext)ptr)(_device, _swapchain_count, _p_swapchains, _p_metadata);
}

inline ktl::api::result get_swapchain_status_khr(ktl::api::device _device, ktl::api::swapchain_khr _swapchain)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_swapchain_status_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_swapchain_status_khr)ptr)(_device, _swapchain);
}

inline ktl::api::result get_refresh_cycle_duration_google(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, ktl::api::refresh_cycle_duration_google * _p_display_timing_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_refresh_cycle_duration_google)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_refresh_cycle_duration_google)ptr)(_device, _swapchain, _p_display_timing_properties);
}

inline ktl::api::result get_past_presentation_timing_google(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, ktl::u32 * _p_presentation_timing_count, ktl::api::past_presentation_timing_google * _p_presentation_timings)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_past_presentation_timing_google)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_past_presentation_timing_google)ptr)(_device, _swapchain, _p_presentation_timing_count, _p_presentation_timings);
}

inline ktl::api::result create_ios_surface_mvk(ktl::api::instance _instance, const ktl::api::ios_surface_create_info_mvk * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_ios_surface_mvk)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_ios_surface_mvk)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::result create_mac_os_surface_mvk(ktl::api::instance _instance, const ktl::api::mac_os_surface_create_info_mvk * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_mac_os_surface_mvk)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_mac_os_surface_mvk)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::result create_metal_surface_ext(ktl::api::instance _instance, const ktl::api::metal_surface_create_info_ext * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_metal_surface_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_metal_surface_ext)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline void cmd_set_viewport_w_scaling_nv(ktl::api::command_buffer _command_buffer, ktl::u32 _first_viewport, ktl::u32 _viewport_count, const ktl::api::viewport_w_scaling_nv * _p_viewport_w_scalings)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_viewport_w_scaling_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_viewport_w_scaling_nv)ptr)(_command_buffer, _first_viewport, _viewport_count, _p_viewport_w_scalings);
}

inline void cmd_set_discard_rectangle_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _first_discard_rectangle, ktl::u32 _discard_rectangle_count, const ktl::api::rect_2d * _p_discard_rectangles)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_discard_rectangle_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_discard_rectangle_ext)ptr)(_command_buffer, _first_discard_rectangle, _discard_rectangle_count, _p_discard_rectangles);
}

inline void cmd_set_discard_rectangle_enable_ext(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _discard_rectangle_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_discard_rectangle_enable_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_discard_rectangle_enable_ext)ptr)(_command_buffer, _discard_rectangle_enable);
}

inline void cmd_set_discard_rectangle_mode_ext(ktl::api::command_buffer _command_buffer, ktl::api::discard_rectangle_mode_ext _discard_rectangle_mode)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_discard_rectangle_mode_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_discard_rectangle_mode_ext)ptr)(_command_buffer, _discard_rectangle_mode);
}

inline void cmd_set_sample_locations_ext(ktl::api::command_buffer _command_buffer, const ktl::api::sample_locations_info_ext * _p_sample_locations_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_sample_locations_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_sample_locations_ext)ptr)(_command_buffer, _p_sample_locations_info);
}

inline void get_physical_device_multisample_properties_ext(ktl::api::physical_device _physical_device, ktl::api::sample_count_flag_bits _samples, ktl::api::multisample_properties_ext * _p_multisample_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_multisample_properties_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_multisample_properties_ext)ptr)(_physical_device, _samples, _p_multisample_properties);
}

inline ktl::api::result get_physical_device_surface_capabilities_2khr(ktl::api::physical_device _physical_device, const ktl::api::physical_device_surface_info_2khr * _p_surface_info, ktl::api::surface_capabilities_2khr * _p_surface_capabilities)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_surface_capabilities_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_surface_capabilities_2khr)ptr)(_physical_device, _p_surface_info, _p_surface_capabilities);
}

inline ktl::api::result get_physical_device_surface_formats_2khr(ktl::api::physical_device _physical_device, const ktl::api::physical_device_surface_info_2khr * _p_surface_info, ktl::u32 * _p_surface_format_count, ktl::api::surface_format_2khr * _p_surface_formats)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_surface_formats_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_surface_formats_2khr)ptr)(_physical_device, _p_surface_info, _p_surface_format_count, _p_surface_formats);
}

inline ktl::api::result get_physical_device_display_properties_2khr(ktl::api::physical_device _physical_device, ktl::u32 * _p_property_count, ktl::api::display_properties_2khr * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_display_properties_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_display_properties_2khr)ptr)(_physical_device, _p_property_count, _p_properties);
}

inline ktl::api::result get_physical_device_display_plane_properties_2khr(ktl::api::physical_device _physical_device, ktl::u32 * _p_property_count, ktl::api::display_plane_properties_2khr * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_display_plane_properties_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_display_plane_properties_2khr)ptr)(_physical_device, _p_property_count, _p_properties);
}

inline ktl::api::result get_display_mode_properties_2khr(ktl::api::physical_device _physical_device, ktl::api::display_khr _display, ktl::u32 * _p_property_count, ktl::api::display_mode_properties_2khr * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_display_mode_properties_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_display_mode_properties_2khr)ptr)(_physical_device, _display, _p_property_count, _p_properties);
}

inline ktl::api::result get_display_plane_capabilities_2khr(ktl::api::physical_device _physical_device, const ktl::api::display_plane_info_2khr * _p_display_plane_info, ktl::api::display_plane_capabilities_2khr * _p_capabilities)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_display_plane_capabilities_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_display_plane_capabilities_2khr)ptr)(_physical_device, _p_display_plane_info, _p_capabilities);
}

inline void get_buffer_memory_requirements_2(ktl::api::device _device, const ktl::api::buffer_memory_requirements_info_2 * _p_info, ktl::api::memory_requirements_2 * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_buffer_memory_requirements_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_buffer_memory_requirements_2)ptr)(_device, _p_info, _p_memory_requirements);
}

inline void get_image_memory_requirements_2(ktl::api::device _device, const ktl::api::image_memory_requirements_info_2 * _p_info, ktl::api::memory_requirements_2 * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_memory_requirements_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_memory_requirements_2)ptr)(_device, _p_info, _p_memory_requirements);
}

inline void get_image_sparse_memory_requirements_2(ktl::api::device _device, const ktl::api::image_sparse_memory_requirements_info_2 * _p_info, ktl::u32 * _p_sparse_memory_requirement_count, ktl::api::sparse_image_memory_requirements_2 * _p_sparse_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_sparse_memory_requirements_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_sparse_memory_requirements_2)ptr)(_device, _p_info, _p_sparse_memory_requirement_count, _p_sparse_memory_requirements);
}

inline void get_device_buffer_memory_requirements(ktl::api::device _device, const ktl::api::device_buffer_memory_requirements * _p_info, ktl::api::memory_requirements_2 * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_buffer_memory_requirements)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_buffer_memory_requirements)ptr)(_device, _p_info, _p_memory_requirements);
}

inline void get_device_image_memory_requirements(ktl::api::device _device, const ktl::api::device_image_memory_requirements * _p_info, ktl::api::memory_requirements_2 * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_image_memory_requirements)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_image_memory_requirements)ptr)(_device, _p_info, _p_memory_requirements);
}

inline void get_device_image_sparse_memory_requirements(ktl::api::device _device, const ktl::api::device_image_memory_requirements * _p_info, ktl::u32 * _p_sparse_memory_requirement_count, ktl::api::sparse_image_memory_requirements_2 * _p_sparse_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_image_sparse_memory_requirements)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_image_sparse_memory_requirements)ptr)(_device, _p_info, _p_sparse_memory_requirement_count, _p_sparse_memory_requirements);
}

inline ktl::api::result create_sampler_ycbcr_conversion(ktl::api::device _device, const ktl::api::sampler_ycbcr_conversion_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::sampler_ycbcr_conversion * _p_ycbcr_conversion)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_sampler_ycbcr_conversion)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_sampler_ycbcr_conversion)ptr)(_device, _p_create_info, _p_allocator, _p_ycbcr_conversion);
}

inline void destroy_sampler_ycbcr_conversion(ktl::api::device _device, ktl::api::sampler_ycbcr_conversion _ycbcr_conversion, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_sampler_ycbcr_conversion)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_sampler_ycbcr_conversion)ptr)(_device, _ycbcr_conversion, _p_allocator);
}

inline void get_device_queue_2(ktl::api::device _device, const ktl::api::device_queue_info_2 * _p_queue_info, ktl::api::queue * _p_queue)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_queue_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_queue_2)ptr)(_device, _p_queue_info, _p_queue);
}

inline ktl::api::result create_validation_cache_ext(ktl::api::device _device, const ktl::api::validation_cache_create_info_ext * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::validation_cache_ext * _p_validation_cache)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_validation_cache_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_validation_cache_ext)ptr)(_device, _p_create_info, _p_allocator, _p_validation_cache);
}

inline void destroy_validation_cache_ext(ktl::api::device _device, ktl::api::validation_cache_ext _validation_cache, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_validation_cache_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_validation_cache_ext)ptr)(_device, _validation_cache, _p_allocator);
}

inline ktl::api::result get_validation_cache_data_ext(ktl::api::device _device, ktl::api::validation_cache_ext _validation_cache, ktl::usize * _p_data_size, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_validation_cache_data_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_validation_cache_data_ext)ptr)(_device, _validation_cache, _p_data_size, _p_data);
}

inline ktl::api::result merge_validation_caches_ext(ktl::api::device _device, ktl::api::validation_cache_ext _dst_cache, ktl::u32 _src_cache_count, const ktl::api::validation_cache_ext * _p_src_caches)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::merge_validation_caches_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_merge_validation_caches_ext)ptr)(_device, _dst_cache, _src_cache_count, _p_src_caches);
}

inline void get_descriptor_set_layout_support(ktl::api::device _device, const ktl::api::descriptor_set_layout_create_info * _p_create_info, ktl::api::descriptor_set_layout_support * _p_support)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_descriptor_set_layout_support)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_descriptor_set_layout_support)ptr)(_device, _p_create_info, _p_support);
}

inline ktl::api::result get_swapchain_gralloc_usage_android(ktl::api::device _device, ktl::api::format _format, ktl::api::image_usage_flags _image_usage, int * _gralloc_usage)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_swapchain_gralloc_usage_android)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_swapchain_gralloc_usage_android)ptr)(_device, _format, _image_usage, _gralloc_usage);
}

inline ktl::api::result get_swapchain_gralloc_usage_2android(ktl::api::device _device, ktl::api::format _format, ktl::api::image_usage_flags _image_usage, ktl::api::swapchain_image_usage_flags_android _swapchain_image_usage, ktl::u64 * _gralloc_consumer_usage, ktl::u64 * _gralloc_producer_usage)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_swapchain_gralloc_usage_2android)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_swapchain_gralloc_usage_2android)ptr)(_device, _format, _image_usage, _swapchain_image_usage, _gralloc_consumer_usage, _gralloc_producer_usage);
}

inline ktl::api::result acquire_image_android(ktl::api::device _device, ktl::api::image _image, int _native_fence_fd, ktl::api::semaphore _semaphore, ktl::api::fence _fence)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::acquire_image_android)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_acquire_image_android)ptr)(_device, _image, _native_fence_fd, _semaphore, _fence);
}

inline ktl::api::result queue_signal_release_image_android(ktl::api::queue _queue, ktl::u32 _wait_semaphore_count, const ktl::api::semaphore * _p_wait_semaphores, ktl::api::image _image, int * _p_native_fence_fd)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_signal_release_image_android)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_signal_release_image_android)ptr)(_queue, _wait_semaphore_count, _p_wait_semaphores, _image, _p_native_fence_fd);
}

inline ktl::api::result get_shader_info_amd(ktl::api::device _device, ktl::api::pipeline _pipeline, ktl::api::shader_stage_flag_bits _shader_stage, ktl::api::shader_info_type_amd _info_type, ktl::usize * _p_info_size, void * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_shader_info_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_shader_info_amd)ptr)(_device, _pipeline, _shader_stage, _info_type, _p_info_size, _p_info);
}

inline void set_local_dimming_amd(ktl::api::device _device, ktl::api::swapchain_khr _swap_chain, ktl::api::bool32 _local_dimming_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_local_dimming_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_local_dimming_amd)ptr)(_device, _swap_chain, _local_dimming_enable);
}

inline ktl::api::result get_physical_device_calibrateable_time_domains_khr(ktl::api::physical_device _physical_device, ktl::u32 * _p_time_domain_count, ktl::api::time_domain_khr * _p_time_domains)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_calibrateable_time_domains_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_calibrateable_time_domains_khr)ptr)(_physical_device, _p_time_domain_count, _p_time_domains);
}

inline ktl::api::result get_calibrated_timestamps_khr(ktl::api::device _device, ktl::u32 _timestamp_count, const ktl::api::calibrated_timestamp_info_khr * _p_timestamp_infos, ktl::u64 * _p_timestamps, ktl::u64 * _p_max_deviation)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_calibrated_timestamps_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_calibrated_timestamps_khr)ptr)(_device, _timestamp_count, _p_timestamp_infos, _p_timestamps, _p_max_deviation);
}

inline ktl::api::result set_debug_utils_object_name_ext(ktl::api::device _device, const ktl::api::debug_utils_object_name_info_ext * _p_name_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_debug_utils_object_name_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_debug_utils_object_name_ext)ptr)(_device, _p_name_info);
}

inline ktl::api::result set_debug_utils_object_tag_ext(ktl::api::device _device, const ktl::api::debug_utils_object_tag_info_ext * _p_tag_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_debug_utils_object_tag_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_debug_utils_object_tag_ext)ptr)(_device, _p_tag_info);
}

inline void queue_begin_debug_utils_label_ext(ktl::api::queue _queue, const ktl::api::debug_utils_label_ext * _p_label_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_begin_debug_utils_label_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_begin_debug_utils_label_ext)ptr)(_queue, _p_label_info);
}

inline void queue_end_debug_utils_label_ext(ktl::api::queue _queue)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_end_debug_utils_label_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_end_debug_utils_label_ext)ptr)(_queue);
}

inline void queue_insert_debug_utils_label_ext(ktl::api::queue _queue, const ktl::api::debug_utils_label_ext * _p_label_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_insert_debug_utils_label_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_insert_debug_utils_label_ext)ptr)(_queue, _p_label_info);
}

inline void cmd_begin_debug_utils_label_ext(ktl::api::command_buffer _command_buffer, const ktl::api::debug_utils_label_ext * _p_label_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_debug_utils_label_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_debug_utils_label_ext)ptr)(_command_buffer, _p_label_info);
}

inline void cmd_end_debug_utils_label_ext(ktl::api::command_buffer _command_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_debug_utils_label_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_debug_utils_label_ext)ptr)(_command_buffer);
}

inline void cmd_insert_debug_utils_label_ext(ktl::api::command_buffer _command_buffer, const ktl::api::debug_utils_label_ext * _p_label_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_insert_debug_utils_label_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_insert_debug_utils_label_ext)ptr)(_command_buffer, _p_label_info);
}

inline ktl::api::result create_debug_utils_messenger_ext(ktl::api::instance _instance, const ktl::api::debug_utils_messenger_create_info_ext * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::debug_utils_messenger_ext * _p_messenger)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_debug_utils_messenger_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_debug_utils_messenger_ext)ptr)(_instance, _p_create_info, _p_allocator, _p_messenger);
}

inline void destroy_debug_utils_messenger_ext(ktl::api::instance _instance, ktl::api::debug_utils_messenger_ext _messenger, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_debug_utils_messenger_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_debug_utils_messenger_ext)ptr)(_instance, _messenger, _p_allocator);
}

inline void submit_debug_utils_message_ext(ktl::api::instance _instance, ktl::api::debug_utils_message_severity_flag_bits_ext _message_severity, ktl::api::debug_utils_message_type_flags_ext _message_types, const ktl::api::debug_utils_messenger_callback_data_ext * _p_callback_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::submit_debug_utils_message_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_submit_debug_utils_message_ext)ptr)(_instance, _message_severity, _message_types, _p_callback_data);
}

inline ktl::api::result get_memory_host_pointer_properties_ext(ktl::api::device _device, ktl::api::external_memory_handle_type_flag_bits _handle_type, const void * _p_host_pointer, ktl::api::memory_host_pointer_properties_ext * _p_memory_host_pointer_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_host_pointer_properties_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_host_pointer_properties_ext)ptr)(_device, _handle_type, _p_host_pointer, _p_memory_host_pointer_properties);
}

inline void cmd_write_buffer_marker_amd(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_stage_flag_bits _pipeline_stage, ktl::api::buffer _dst_buffer, ktl::api::dvsize _dst_offset, ktl::u32 _marker)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_write_buffer_marker_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_write_buffer_marker_amd)ptr)(_command_buffer, _pipeline_stage, _dst_buffer, _dst_offset, _marker);
}

inline ktl::api::result create_render_pass_2(ktl::api::device _device, const ktl::api::render_pass_create_info_2 * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::render_pass * _p_render_pass)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_render_pass_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_render_pass_2)ptr)(_device, _p_create_info, _p_allocator, _p_render_pass);
}

inline void cmd_begin_render_pass_2(ktl::api::command_buffer _command_buffer, const ktl::api::render_pass_begin_info * _p_render_pass_begin, const ktl::api::subpass_begin_info * _p_subpass_begin_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_render_pass_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_render_pass_2)ptr)(_command_buffer, _p_render_pass_begin, _p_subpass_begin_info);
}

inline void cmd_next_subpass_2(ktl::api::command_buffer _command_buffer, const ktl::api::subpass_begin_info * _p_subpass_begin_info, const ktl::api::subpass_end_info * _p_subpass_end_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_next_subpass_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_next_subpass_2)ptr)(_command_buffer, _p_subpass_begin_info, _p_subpass_end_info);
}

inline void cmd_end_render_pass_2(ktl::api::command_buffer _command_buffer, const ktl::api::subpass_end_info * _p_subpass_end_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_render_pass_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_render_pass_2)ptr)(_command_buffer, _p_subpass_end_info);
}

inline ktl::api::result get_semaphore_counter_value(ktl::api::device _device, ktl::api::semaphore _semaphore, ktl::u64 * _p_value)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_semaphore_counter_value)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_semaphore_counter_value)ptr)(_device, _semaphore, _p_value);
}

inline ktl::api::result wait_semaphores(ktl::api::device _device, const ktl::api::semaphore_wait_info * _p_wait_info, ktl::u64 _timeout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::wait_semaphores)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_wait_semaphores)ptr)(_device, _p_wait_info, _timeout);
}

inline ktl::api::result signal_semaphore(ktl::api::device _device, const ktl::api::semaphore_signal_info * _p_signal_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::signal_semaphore)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_signal_semaphore)ptr)(_device, _p_signal_info);
}

inline ktl::api::result get_android_hardware_buffer_properties_android(ktl::api::device _device, const AHardwareBuffer * _buffer, ktl::api::android_hardware_buffer_properties_android * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_android_hardware_buffer_properties_android)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_android_hardware_buffer_properties_android)ptr)(_device, _buffer, _p_properties);
}

inline ktl::api::result get_memory_android_hardware_buffer_android(ktl::api::device _device, const ktl::api::memory_get_android_hardware_buffer_info_android * _p_info, AHardwareBuffer * _p_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_android_hardware_buffer_android)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_android_hardware_buffer_android)ptr)(_device, _p_info, _p_buffer);
}

inline void cmd_draw_indirect_count(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset, ktl::api::buffer _count_buffer, ktl::api::dvsize _count_buffer_offset, ktl::u32 _max_draw_count, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_indirect_count)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_indirect_count)ptr)(_command_buffer, _buffer, _offset, _count_buffer, _count_buffer_offset, _max_draw_count, _stride);
}

inline void cmd_draw_indexed_indirect_count(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset, ktl::api::buffer _count_buffer, ktl::api::dvsize _count_buffer_offset, ktl::u32 _max_draw_count, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_indexed_indirect_count)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_indexed_indirect_count)ptr)(_command_buffer, _buffer, _offset, _count_buffer, _count_buffer_offset, _max_draw_count, _stride);
}

inline void cmd_set_checkpoint_nv(ktl::api::command_buffer _command_buffer, const void * _p_checkpoint_marker)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_checkpoint_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_checkpoint_nv)ptr)(_command_buffer, _p_checkpoint_marker);
}

inline void get_queue_checkpoint_data_nv(ktl::api::queue _queue, ktl::u32 * _p_checkpoint_data_count, ktl::api::checkpoint_data_nv * _p_checkpoint_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_queue_checkpoint_data_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_queue_checkpoint_data_nv)ptr)(_queue, _p_checkpoint_data_count, _p_checkpoint_data);
}

inline void cmd_bind_transform_feedback_buffers_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _first_binding, ktl::u32 _binding_count, const ktl::api::buffer * _p_buffers, const ktl::api::dvsize * _p_offsets, const ktl::api::dvsize * _p_sizes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_transform_feedback_buffers_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_transform_feedback_buffers_ext)ptr)(_command_buffer, _first_binding, _binding_count, _p_buffers, _p_offsets, _p_sizes);
}

inline void cmd_begin_transform_feedback_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _first_counter_buffer, ktl::u32 _counter_buffer_count, const ktl::api::buffer * _p_counter_buffers, const ktl::api::dvsize * _p_counter_buffer_offsets)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_transform_feedback_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_transform_feedback_ext)ptr)(_command_buffer, _first_counter_buffer, _counter_buffer_count, _p_counter_buffers, _p_counter_buffer_offsets);
}

inline void cmd_end_transform_feedback_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _first_counter_buffer, ktl::u32 _counter_buffer_count, const ktl::api::buffer * _p_counter_buffers, const ktl::api::dvsize * _p_counter_buffer_offsets)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_transform_feedback_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_transform_feedback_ext)ptr)(_command_buffer, _first_counter_buffer, _counter_buffer_count, _p_counter_buffers, _p_counter_buffer_offsets);
}

inline void cmd_begin_query_indexed_ext(ktl::api::command_buffer _command_buffer, ktl::api::query_pool _query_pool, ktl::u32 _query, ktl::api::query_control_flags _flags, ktl::u32 _index)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_query_indexed_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_query_indexed_ext)ptr)(_command_buffer, _query_pool, _query, _flags, _index);
}

inline void cmd_end_query_indexed_ext(ktl::api::command_buffer _command_buffer, ktl::api::query_pool _query_pool, ktl::u32 _query, ktl::u32 _index)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_query_indexed_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_query_indexed_ext)ptr)(_command_buffer, _query_pool, _query, _index);
}

inline void cmd_draw_indirect_byte_count_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _instance_count, ktl::u32 _first_instance, ktl::api::buffer _counter_buffer, ktl::api::dvsize _counter_buffer_offset, ktl::u32 _counter_offset, ktl::u32 _vertex_stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_indirect_byte_count_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_indirect_byte_count_ext)ptr)(_command_buffer, _instance_count, _first_instance, _counter_buffer, _counter_buffer_offset, _counter_offset, _vertex_stride);
}

inline void cmd_set_exclusive_scissor_nv(ktl::api::command_buffer _command_buffer, ktl::u32 _first_exclusive_scissor, ktl::u32 _exclusive_scissor_count, const ktl::api::rect_2d * _p_exclusive_scissors)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_exclusive_scissor_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_exclusive_scissor_nv)ptr)(_command_buffer, _first_exclusive_scissor, _exclusive_scissor_count, _p_exclusive_scissors);
}

inline void cmd_set_exclusive_scissor_enable_nv(ktl::api::command_buffer _command_buffer, ktl::u32 _first_exclusive_scissor, ktl::u32 _exclusive_scissor_count, const ktl::api::bool32 * _p_exclusive_scissor_enables)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_exclusive_scissor_enable_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_exclusive_scissor_enable_nv)ptr)(_command_buffer, _first_exclusive_scissor, _exclusive_scissor_count, _p_exclusive_scissor_enables);
}

inline void cmd_bind_shading_rate_image_nv(ktl::api::command_buffer _command_buffer, ktl::api::image_view _image_view, ktl::api::image_layout _image_layout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_shading_rate_image_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_shading_rate_image_nv)ptr)(_command_buffer, _image_view, _image_layout);
}

inline void cmd_set_viewport_shading_rate_palette_nv(ktl::api::command_buffer _command_buffer, ktl::u32 _first_viewport, ktl::u32 _viewport_count, const ktl::api::shading_rate_palette_nv * _p_shading_rate_palettes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_viewport_shading_rate_palette_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_viewport_shading_rate_palette_nv)ptr)(_command_buffer, _first_viewport, _viewport_count, _p_shading_rate_palettes);
}

inline void cmd_set_coarse_sample_order_nv(ktl::api::command_buffer _command_buffer, ktl::api::coarse_sample_order_type_nv _sample_order_type, ktl::u32 _custom_sample_order_count, const ktl::api::coarse_sample_order_custom_nv * _p_custom_sample_orders)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_coarse_sample_order_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_coarse_sample_order_nv)ptr)(_command_buffer, _sample_order_type, _custom_sample_order_count, _p_custom_sample_orders);
}

inline void cmd_draw_mesh_tasks_nv(ktl::api::command_buffer _command_buffer, ktl::u32 _task_count, ktl::u32 _first_task)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_mesh_tasks_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_mesh_tasks_nv)ptr)(_command_buffer, _task_count, _first_task);
}

inline void cmd_draw_mesh_tasks_indirect_nv(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset, ktl::u32 _draw_count, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_mesh_tasks_indirect_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_mesh_tasks_indirect_nv)ptr)(_command_buffer, _buffer, _offset, _draw_count, _stride);
}

inline void cmd_draw_mesh_tasks_indirect_count_nv(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset, ktl::api::buffer _count_buffer, ktl::api::dvsize _count_buffer_offset, ktl::u32 _max_draw_count, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_mesh_tasks_indirect_count_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_mesh_tasks_indirect_count_nv)ptr)(_command_buffer, _buffer, _offset, _count_buffer, _count_buffer_offset, _max_draw_count, _stride);
}

inline void cmd_draw_mesh_tasks_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _group_count_x, ktl::u32 _group_count_y, ktl::u32 _group_count_z)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_mesh_tasks_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_mesh_tasks_ext)ptr)(_command_buffer, _group_count_x, _group_count_y, _group_count_z);
}

inline void cmd_draw_mesh_tasks_indirect_ext(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset, ktl::u32 _draw_count, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_mesh_tasks_indirect_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_mesh_tasks_indirect_ext)ptr)(_command_buffer, _buffer, _offset, _draw_count, _stride);
}

inline void cmd_draw_mesh_tasks_indirect_count_ext(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset, ktl::api::buffer _count_buffer, ktl::api::dvsize _count_buffer_offset, ktl::u32 _max_draw_count, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_mesh_tasks_indirect_count_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_mesh_tasks_indirect_count_ext)ptr)(_command_buffer, _buffer, _offset, _count_buffer, _count_buffer_offset, _max_draw_count, _stride);
}

inline ktl::api::result compile_deferred_nv(ktl::api::device _device, ktl::api::pipeline _pipeline, ktl::u32 _shader)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::compile_deferred_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_compile_deferred_nv)ptr)(_device, _pipeline, _shader);
}

inline ktl::api::result create_acceleration_structure_nv(ktl::api::device _device, const ktl::api::acceleration_structure_create_info_nv * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::acceleration_structure_nv * _p_acceleration_structure)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_acceleration_structure_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_acceleration_structure_nv)ptr)(_device, _p_create_info, _p_allocator, _p_acceleration_structure);
}

inline void cmd_bind_invocation_mask_huawei(ktl::api::command_buffer _command_buffer, ktl::api::image_view _image_view, ktl::api::image_layout _image_layout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_invocation_mask_huawei)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_invocation_mask_huawei)ptr)(_command_buffer, _image_view, _image_layout);
}

inline void destroy_acceleration_structure_khr(ktl::api::device _device, ktl::api::acceleration_structure_khr _acceleration_structure, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_acceleration_structure_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_acceleration_structure_khr)ptr)(_device, _acceleration_structure, _p_allocator);
}

inline void destroy_acceleration_structure_nv(ktl::api::device _device, ktl::api::acceleration_structure_nv _acceleration_structure, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_acceleration_structure_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_acceleration_structure_nv)ptr)(_device, _acceleration_structure, _p_allocator);
}

inline void get_acceleration_structure_memory_requirements_nv(ktl::api::device _device, const ktl::api::acceleration_structure_memory_requirements_info_nv * _p_info, ktl::api::memory_requirements_2 * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_acceleration_structure_memory_requirements_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_acceleration_structure_memory_requirements_nv)ptr)(_device, _p_info, _p_memory_requirements);
}

inline ktl::api::result bind_acceleration_structure_memory_nv(ktl::api::device _device, ktl::u32 _bind_info_count, const ktl::api::bind_acceleration_structure_memory_info_nv * _p_bind_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::bind_acceleration_structure_memory_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_bind_acceleration_structure_memory_nv)ptr)(_device, _bind_info_count, _p_bind_infos);
}

inline void cmd_copy_acceleration_structure_nv(ktl::api::command_buffer _command_buffer, ktl::api::acceleration_structure_nv _dst, ktl::api::acceleration_structure_nv _src, ktl::api::copy_acceleration_structure_mode_khr _mode)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_acceleration_structure_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_acceleration_structure_nv)ptr)(_command_buffer, _dst, _src, _mode);
}

inline void cmd_copy_acceleration_structure_khr(ktl::api::command_buffer _command_buffer, const ktl::api::copy_acceleration_structure_info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_acceleration_structure_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_acceleration_structure_khr)ptr)(_command_buffer, _p_info);
}

inline ktl::api::result copy_acceleration_structure_khr(ktl::api::device _device, ktl::api::deferred_operation_khr _deferred_operation, const ktl::api::copy_acceleration_structure_info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::copy_acceleration_structure_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_copy_acceleration_structure_khr)ptr)(_device, _deferred_operation, _p_info);
}

inline void cmd_copy_acceleration_structure_to_memory_khr(ktl::api::command_buffer _command_buffer, const ktl::api::copy_acceleration_structure_to_memory_info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_acceleration_structure_to_memory_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_acceleration_structure_to_memory_khr)ptr)(_command_buffer, _p_info);
}

inline ktl::api::result copy_acceleration_structure_to_memory_khr(ktl::api::device _device, ktl::api::deferred_operation_khr _deferred_operation, const ktl::api::copy_acceleration_structure_to_memory_info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::copy_acceleration_structure_to_memory_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_copy_acceleration_structure_to_memory_khr)ptr)(_device, _deferred_operation, _p_info);
}

inline void cmd_copy_memory_to_acceleration_structure_khr(ktl::api::command_buffer _command_buffer, const ktl::api::copy_memory_to_acceleration_structure_info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_memory_to_acceleration_structure_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_memory_to_acceleration_structure_khr)ptr)(_command_buffer, _p_info);
}

inline ktl::api::result copy_memory_to_acceleration_structure_khr(ktl::api::device _device, ktl::api::deferred_operation_khr _deferred_operation, const ktl::api::copy_memory_to_acceleration_structure_info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::copy_memory_to_acceleration_structure_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_copy_memory_to_acceleration_structure_khr)ptr)(_device, _deferred_operation, _p_info);
}

inline void cmd_write_acceleration_structures_properties_khr(ktl::api::command_buffer _command_buffer, ktl::u32 _acceleration_structure_count, const ktl::api::acceleration_structure_khr * _p_acceleration_structures, ktl::api::query_type _query_type, ktl::api::query_pool _query_pool, ktl::u32 _first_query)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_write_acceleration_structures_properties_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_write_acceleration_structures_properties_khr)ptr)(_command_buffer, _acceleration_structure_count, _p_acceleration_structures, _query_type, _query_pool, _first_query);
}

inline void cmd_write_acceleration_structures_properties_nv(ktl::api::command_buffer _command_buffer, ktl::u32 _acceleration_structure_count, const ktl::api::acceleration_structure_nv * _p_acceleration_structures, ktl::api::query_type _query_type, ktl::api::query_pool _query_pool, ktl::u32 _first_query)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_write_acceleration_structures_properties_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_write_acceleration_structures_properties_nv)ptr)(_command_buffer, _acceleration_structure_count, _p_acceleration_structures, _query_type, _query_pool, _first_query);
}

inline void cmd_build_acceleration_structure_nv(ktl::api::command_buffer _command_buffer, const ktl::api::acceleration_structure_info_nv * _p_info, ktl::api::buffer _instance_data, ktl::api::dvsize _instance_offset, ktl::api::bool32 _update, ktl::api::acceleration_structure_nv _dst, ktl::api::acceleration_structure_nv _src, ktl::api::buffer _scratch, ktl::api::dvsize _scratch_offset)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_build_acceleration_structure_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_build_acceleration_structure_nv)ptr)(_command_buffer, _p_info, _instance_data, _instance_offset, _update, _dst, _src, _scratch, _scratch_offset);
}

inline ktl::api::result write_acceleration_structures_properties_khr(ktl::api::device _device, ktl::u32 _acceleration_structure_count, const ktl::api::acceleration_structure_khr * _p_acceleration_structures, ktl::api::query_type _query_type, ktl::usize _data_size, void * _p_data, ktl::usize _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::write_acceleration_structures_properties_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_write_acceleration_structures_properties_khr)ptr)(_device, _acceleration_structure_count, _p_acceleration_structures, _query_type, _data_size, _p_data, _stride);
}

inline void cmd_trace_rays_khr(ktl::api::command_buffer _command_buffer, const ktl::api::strided_device_address_region_khr * _p_raygen_shader_binding_table, const ktl::api::strided_device_address_region_khr * _p_miss_shader_binding_table, const ktl::api::strided_device_address_region_khr * _p_hit_shader_binding_table, const ktl::api::strided_device_address_region_khr * _p_callable_shader_binding_table, ktl::u32 _width, ktl::u32 _height, ktl::u32 _depth)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_trace_rays_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_trace_rays_khr)ptr)(_command_buffer, _p_raygen_shader_binding_table, _p_miss_shader_binding_table, _p_hit_shader_binding_table, _p_callable_shader_binding_table, _width, _height, _depth);
}

inline void cmd_trace_rays_nv(ktl::api::command_buffer _command_buffer, ktl::api::buffer _raygen_shader_binding_table_buffer, ktl::api::dvsize _raygen_shader_binding_offset, ktl::api::buffer _miss_shader_binding_table_buffer, ktl::api::dvsize _miss_shader_binding_offset, ktl::api::dvsize _miss_shader_binding_stride, ktl::api::buffer _hit_shader_binding_table_buffer, ktl::api::dvsize _hit_shader_binding_offset, ktl::api::dvsize _hit_shader_binding_stride, ktl::api::buffer _callable_shader_binding_table_buffer, ktl::api::dvsize _callable_shader_binding_offset, ktl::api::dvsize _callable_shader_binding_stride, ktl::u32 _width, ktl::u32 _height, ktl::u32 _depth)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_trace_rays_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_trace_rays_nv)ptr)(_command_buffer, _raygen_shader_binding_table_buffer, _raygen_shader_binding_offset, _miss_shader_binding_table_buffer, _miss_shader_binding_offset, _miss_shader_binding_stride, _hit_shader_binding_table_buffer, _hit_shader_binding_offset, _hit_shader_binding_stride, _callable_shader_binding_table_buffer, _callable_shader_binding_offset, _callable_shader_binding_stride, _width, _height, _depth);
}

inline ktl::api::result get_ray_tracing_shader_group_handles_khr(ktl::api::device _device, ktl::api::pipeline _pipeline, ktl::u32 _first_group, ktl::u32 _group_count, ktl::usize _data_size, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_ray_tracing_shader_group_handles_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_ray_tracing_shader_group_handles_khr)ptr)(_device, _pipeline, _first_group, _group_count, _data_size, _p_data);
}

inline ktl::api::result get_ray_tracing_capture_replay_shader_group_handles_khr(ktl::api::device _device, ktl::api::pipeline _pipeline, ktl::u32 _first_group, ktl::u32 _group_count, ktl::usize _data_size, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_ray_tracing_capture_replay_shader_group_handles_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_ray_tracing_capture_replay_shader_group_handles_khr)ptr)(_device, _pipeline, _first_group, _group_count, _data_size, _p_data);
}

inline ktl::api::result get_acceleration_structure_handle_nv(ktl::api::device _device, ktl::api::acceleration_structure_nv _acceleration_structure, ktl::usize _data_size, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_acceleration_structure_handle_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_acceleration_structure_handle_nv)ptr)(_device, _acceleration_structure, _data_size, _p_data);
}

inline ktl::api::result create_ray_tracing_pipelines_nv(ktl::api::device _device, ktl::api::pipeline_cache _pipeline_cache, ktl::u32 _create_info_count, const ktl::api::ray_tracing_pipeline_create_info_nv * _p_create_infos, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::pipeline * _p_pipelines)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_ray_tracing_pipelines_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_ray_tracing_pipelines_nv)ptr)(_device, _pipeline_cache, _create_info_count, _p_create_infos, _p_allocator, _p_pipelines);
}

inline ktl::api::result create_ray_tracing_pipelines_khr(ktl::api::device _device, ktl::api::deferred_operation_khr _deferred_operation, ktl::api::pipeline_cache _pipeline_cache, ktl::u32 _create_info_count, const ktl::api::ray_tracing_pipeline_create_info_khr * _p_create_infos, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::pipeline * _p_pipelines)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_ray_tracing_pipelines_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_ray_tracing_pipelines_khr)ptr)(_device, _deferred_operation, _pipeline_cache, _create_info_count, _p_create_infos, _p_allocator, _p_pipelines);
}

inline ktl::api::result get_physical_device_cooperative_matrix_properties_nv(ktl::api::physical_device _physical_device, ktl::u32 * _p_property_count, ktl::api::cooperative_matrix_properties_nv * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_cooperative_matrix_properties_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_cooperative_matrix_properties_nv)ptr)(_physical_device, _p_property_count, _p_properties);
}

inline void cmd_trace_rays_indirect_khr(ktl::api::command_buffer _command_buffer, const ktl::api::strided_device_address_region_khr * _p_raygen_shader_binding_table, const ktl::api::strided_device_address_region_khr * _p_miss_shader_binding_table, const ktl::api::strided_device_address_region_khr * _p_hit_shader_binding_table, const ktl::api::strided_device_address_region_khr * _p_callable_shader_binding_table, ktl::api::dvaddr _indirect_device_address)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_trace_rays_indirect_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_trace_rays_indirect_khr)ptr)(_command_buffer, _p_raygen_shader_binding_table, _p_miss_shader_binding_table, _p_hit_shader_binding_table, _p_callable_shader_binding_table, _indirect_device_address);
}

inline void cmd_trace_rays_indirect_2khr(ktl::api::command_buffer _command_buffer, ktl::api::dvaddr _indirect_device_address)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_trace_rays_indirect_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_trace_rays_indirect_2khr)ptr)(_command_buffer, _indirect_device_address);
}

inline void get_cluster_acceleration_structure_build_sizes_nv(ktl::api::device _device, const ktl::api::cluster_acceleration_structure_input_info_nv * _p_info, ktl::api::acceleration_structure_build_sizes_info_khr * _p_size_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_cluster_acceleration_structure_build_sizes_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_cluster_acceleration_structure_build_sizes_nv)ptr)(_device, _p_info, _p_size_info);
}

inline void cmd_build_cluster_acceleration_structure_indirect_nv(ktl::api::command_buffer _command_buffer, const ktl::api::cluster_acceleration_structure_commands_info_nv * _p_command_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_build_cluster_acceleration_structure_indirect_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_build_cluster_acceleration_structure_indirect_nv)ptr)(_command_buffer, _p_command_infos);
}

inline void get_device_acceleration_structure_compatibility_khr(ktl::api::device _device, const ktl::api::acceleration_structure_version_info_khr * _p_version_info, ktl::api::acceleration_structure_compatibility_khr * _p_compatibility)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_acceleration_structure_compatibility_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_acceleration_structure_compatibility_khr)ptr)(_device, _p_version_info, _p_compatibility);
}

inline ktl::api::dvsize get_ray_tracing_shader_group_stack_size_khr(ktl::api::device _device, ktl::api::pipeline _pipeline, ktl::u32 _group, ktl::api::shader_group_shader_khr _group_shader)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_ray_tracing_shader_group_stack_size_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_ray_tracing_shader_group_stack_size_khr)ptr)(_device, _pipeline, _group, _group_shader);
}

inline void cmd_set_ray_tracing_pipeline_stack_size_khr(ktl::api::command_buffer _command_buffer, ktl::u32 _pipeline_stack_size)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_ray_tracing_pipeline_stack_size_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_ray_tracing_pipeline_stack_size_khr)ptr)(_command_buffer, _pipeline_stack_size);
}

inline ktl::u32 get_image_view_handle_nvx(ktl::api::device _device, const ktl::api::image_view_handle_info_nvx * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_view_handle_nvx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_view_handle_nvx)ptr)(_device, _p_info);
}

inline ktl::u64 get_image_view_handle_64nvx(ktl::api::device _device, const ktl::api::image_view_handle_info_nvx * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_view_handle_64nvx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_view_handle_64nvx)ptr)(_device, _p_info);
}

inline ktl::api::result get_image_view_address_nvx(ktl::api::device _device, ktl::api::image_view _image_view, ktl::api::image_view_address_properties_nvx * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_view_address_nvx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_view_address_nvx)ptr)(_device, _image_view, _p_properties);
}

inline ktl::u64 get_device_combined_image_sampler_index_nvx(ktl::api::device _device, ktl::u64 _image_view_index, ktl::u64 _sampler_index)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_combined_image_sampler_index_nvx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_combined_image_sampler_index_nvx)ptr)(_device, _image_view_index, _sampler_index);
}

inline ktl::api::result get_physical_device_surface_present_modes_2ext(ktl::api::physical_device _physical_device, const ktl::api::physical_device_surface_info_2khr * _p_surface_info, ktl::u32 * _p_present_mode_count, ktl::api::present_mode_khr * _p_present_modes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_surface_present_modes_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_surface_present_modes_2ext)ptr)(_physical_device, _p_surface_info, _p_present_mode_count, _p_present_modes);
}

inline ktl::api::result get_device_group_surface_present_modes_2ext(ktl::api::device _device, const ktl::api::physical_device_surface_info_2khr * _p_surface_info, ktl::api::device_group_present_mode_flags_khr * _p_modes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_group_surface_present_modes_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_group_surface_present_modes_2ext)ptr)(_device, _p_surface_info, _p_modes);
}

inline ktl::api::result acquire_full_screen_exclusive_mode_ext(ktl::api::device _device, ktl::api::swapchain_khr _swapchain)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::acquire_full_screen_exclusive_mode_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_acquire_full_screen_exclusive_mode_ext)ptr)(_device, _swapchain);
}

inline ktl::api::result release_full_screen_exclusive_mode_ext(ktl::api::device _device, ktl::api::swapchain_khr _swapchain)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::release_full_screen_exclusive_mode_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_release_full_screen_exclusive_mode_ext)ptr)(_device, _swapchain);
}

inline ktl::api::result enumerate_physical_device_queue_family_performance_query_counters_khr(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, ktl::u32 * _p_counter_count, ktl::api::performance_counter_khr * _p_counters, ktl::api::performance_counter_description_khr * _p_counter_descriptions)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::enumerate_physical_device_queue_family_performance_query_counters_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_enumerate_physical_device_queue_family_performance_query_counters_khr)ptr)(_physical_device, _queue_family_index, _p_counter_count, _p_counters, _p_counter_descriptions);
}

inline void get_physical_device_queue_family_performance_query_passes_khr(ktl::api::physical_device _physical_device, const ktl::api::query_pool_performance_create_info_khr * _p_performance_query_create_info, ktl::u32 * _p_num_passes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_queue_family_performance_query_passes_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_queue_family_performance_query_passes_khr)ptr)(_physical_device, _p_performance_query_create_info, _p_num_passes);
}

inline ktl::api::result acquire_profiling_lock_khr(ktl::api::device _device, const ktl::api::acquire_profiling_lock_info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::acquire_profiling_lock_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_acquire_profiling_lock_khr)ptr)(_device, _p_info);
}

inline void release_profiling_lock_khr(ktl::api::device _device)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::release_profiling_lock_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_release_profiling_lock_khr)ptr)(_device);
}

inline ktl::api::result get_image_drm_format_modifier_properties_ext(ktl::api::device _device, ktl::api::image _image, ktl::api::image_drm_format_modifier_properties_ext * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_drm_format_modifier_properties_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_drm_format_modifier_properties_ext)ptr)(_device, _image, _p_properties);
}

inline ktl::u64 get_buffer_opaque_capture_address(ktl::api::device _device, const ktl::api::buffer_device_address_info * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_buffer_opaque_capture_address)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_buffer_opaque_capture_address)ptr)(_device, _p_info);
}

inline ktl::api::dvaddr get_buffer_device_address(ktl::api::device _device, const ktl::api::buffer_device_address_info * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_buffer_device_address)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_buffer_device_address)ptr)(_device, _p_info);
}

inline ktl::api::result create_headless_surface_ext(ktl::api::instance _instance, const ktl::api::headless_surface_create_info_ext * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::surface_khr * _p_surface)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_headless_surface_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_headless_surface_ext)ptr)(_instance, _p_create_info, _p_allocator, _p_surface);
}

inline ktl::api::result get_physical_device_supported_framebuffer_mixed_samples_combinations_nv(ktl::api::physical_device _physical_device, ktl::u32 * _p_combination_count, ktl::api::framebuffer_mixed_samples_combination_nv * _p_combinations)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_supported_framebuffer_mixed_samples_combinations_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_supported_framebuffer_mixed_samples_combinations_nv)ptr)(_physical_device, _p_combination_count, _p_combinations);
}

inline ktl::api::result initialize_performance_api_intel(ktl::api::device _device, const ktl::api::initialize_performance_api_info_intel * _p_initialize_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::initialize_performance_api_intel)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_initialize_performance_api_intel)ptr)(_device, _p_initialize_info);
}

inline void uninitialize_performance_api_intel(ktl::api::device _device)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::uninitialize_performance_api_intel)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_uninitialize_performance_api_intel)ptr)(_device);
}

inline ktl::api::result cmd_set_performance_marker_intel(ktl::api::command_buffer _command_buffer, const ktl::api::performance_marker_info_intel * _p_marker_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_performance_marker_intel)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_performance_marker_intel)ptr)(_command_buffer, _p_marker_info);
}

inline ktl::api::result cmd_set_performance_stream_marker_intel(ktl::api::command_buffer _command_buffer, const ktl::api::performance_stream_marker_info_intel * _p_marker_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_performance_stream_marker_intel)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_performance_stream_marker_intel)ptr)(_command_buffer, _p_marker_info);
}

inline ktl::api::result cmd_set_performance_override_intel(ktl::api::command_buffer _command_buffer, const ktl::api::performance_override_info_intel * _p_override_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_performance_override_intel)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_performance_override_intel)ptr)(_command_buffer, _p_override_info);
}

inline ktl::api::result acquire_performance_configuration_intel(ktl::api::device _device, const ktl::api::performance_configuration_acquire_info_intel * _p_acquire_info, ktl::api::performance_configuration_intel * _p_configuration)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::acquire_performance_configuration_intel)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_acquire_performance_configuration_intel)ptr)(_device, _p_acquire_info, _p_configuration);
}

inline ktl::api::result release_performance_configuration_intel(ktl::api::device _device, ktl::api::performance_configuration_intel _configuration)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::release_performance_configuration_intel)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_release_performance_configuration_intel)ptr)(_device, _configuration);
}

inline ktl::api::result queue_set_performance_configuration_intel(ktl::api::queue _queue, ktl::api::performance_configuration_intel _configuration)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_set_performance_configuration_intel)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_set_performance_configuration_intel)ptr)(_queue, _configuration);
}

inline ktl::api::result get_performance_parameter_intel(ktl::api::device _device, ktl::api::performance_parameter_type_intel _parameter, ktl::api::performance_value_intel * _p_value)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_performance_parameter_intel)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_performance_parameter_intel)ptr)(_device, _parameter, _p_value);
}

inline ktl::u64 get_device_memory_opaque_capture_address(ktl::api::device _device, const ktl::api::device_memory_opaque_capture_address_info * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_memory_opaque_capture_address)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_memory_opaque_capture_address)ptr)(_device, _p_info);
}

inline ktl::api::result get_pipeline_executable_properties_khr(ktl::api::device _device, const ktl::api::pipeline_info_khr * _p_pipeline_info, ktl::u32 * _p_executable_count, ktl::api::pipeline_executable_properties_khr * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_pipeline_executable_properties_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_pipeline_executable_properties_khr)ptr)(_device, _p_pipeline_info, _p_executable_count, _p_properties);
}

inline ktl::api::result get_pipeline_executable_statistics_khr(ktl::api::device _device, const ktl::api::pipeline_executable_info_khr * _p_executable_info, ktl::u32 * _p_statistic_count, ktl::api::pipeline_executable_statistic_khr * _p_statistics)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_pipeline_executable_statistics_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_pipeline_executable_statistics_khr)ptr)(_device, _p_executable_info, _p_statistic_count, _p_statistics);
}

inline ktl::api::result get_pipeline_executable_internal_representations_khr(ktl::api::device _device, const ktl::api::pipeline_executable_info_khr * _p_executable_info, ktl::u32 * _p_internal_representation_count, ktl::api::pipeline_executable_internal_representation_khr * _p_internal_representations)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_pipeline_executable_internal_representations_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_pipeline_executable_internal_representations_khr)ptr)(_device, _p_executable_info, _p_internal_representation_count, _p_internal_representations);
}

inline void cmd_set_line_stipple(ktl::api::command_buffer _command_buffer, ktl::u32 _line_stipple_factor, ktl::u16 _line_stipple_pattern)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_line_stipple)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_line_stipple)ptr)(_command_buffer, _line_stipple_factor, _line_stipple_pattern);
}

inline ktl::api::result get_fault_data(ktl::api::device _device, ktl::api::fault_query_behavior _fault_query_behavior, ktl::api::bool32 * _p_unrecorded_faults, ktl::u32 * _p_fault_count, ktl::api::fault_data * _p_faults)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_fault_data)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_fault_data)ptr)(_device, _fault_query_behavior, _p_unrecorded_faults, _p_fault_count, _p_faults);
}

inline ktl::api::result get_physical_device_tool_properties(ktl::api::physical_device _physical_device, ktl::u32 * _p_tool_count, ktl::api::physical_device_tool_properties * _p_tool_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_tool_properties)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_tool_properties)ptr)(_physical_device, _p_tool_count, _p_tool_properties);
}

inline ktl::api::result create_acceleration_structure_khr(ktl::api::device _device, const ktl::api::acceleration_structure_create_info_khr * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::acceleration_structure_khr * _p_acceleration_structure)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_acceleration_structure_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_acceleration_structure_khr)ptr)(_device, _p_create_info, _p_allocator, _p_acceleration_structure);
}

inline void cmd_build_acceleration_structures_khr(ktl::api::command_buffer _command_buffer, ktl::u32 _info_count, const ktl::api::acceleration_structure_build_geometry_info_khr * _p_infos, const ktl::api::acceleration_structure_build_range_info_khr * _pp_build_range_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_build_acceleration_structures_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_build_acceleration_structures_khr)ptr)(_command_buffer, _info_count, _p_infos, _pp_build_range_infos);
}

inline void cmd_build_acceleration_structures_indirect_khr(ktl::api::command_buffer _command_buffer, ktl::u32 _info_count, const ktl::api::acceleration_structure_build_geometry_info_khr * _p_infos, const ktl::api::dvaddr * _p_indirect_device_addresses, const ktl::u32 * _p_indirect_strides, const ktl::u32 * _pp_max_primitive_counts)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_build_acceleration_structures_indirect_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_build_acceleration_structures_indirect_khr)ptr)(_command_buffer, _info_count, _p_infos, _p_indirect_device_addresses, _p_indirect_strides, _pp_max_primitive_counts);
}

inline ktl::api::result build_acceleration_structures_khr(ktl::api::device _device, ktl::api::deferred_operation_khr _deferred_operation, ktl::u32 _info_count, const ktl::api::acceleration_structure_build_geometry_info_khr * _p_infos, const ktl::api::acceleration_structure_build_range_info_khr * _pp_build_range_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::build_acceleration_structures_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_build_acceleration_structures_khr)ptr)(_device, _deferred_operation, _info_count, _p_infos, _pp_build_range_infos);
}

inline ktl::api::dvaddr get_acceleration_structure_device_address_khr(ktl::api::device _device, const ktl::api::acceleration_structure_device_address_info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_acceleration_structure_device_address_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_acceleration_structure_device_address_khr)ptr)(_device, _p_info);
}

inline ktl::api::result create_deferred_operation_khr(ktl::api::device _device, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::deferred_operation_khr * _p_deferred_operation)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_deferred_operation_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_deferred_operation_khr)ptr)(_device, _p_allocator, _p_deferred_operation);
}

inline void destroy_deferred_operation_khr(ktl::api::device _device, ktl::api::deferred_operation_khr _operation, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_deferred_operation_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_deferred_operation_khr)ptr)(_device, _operation, _p_allocator);
}

inline ktl::u32 get_deferred_operation_max_concurrency_khr(ktl::api::device _device, ktl::api::deferred_operation_khr _operation)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_deferred_operation_max_concurrency_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_deferred_operation_max_concurrency_khr)ptr)(_device, _operation);
}

inline ktl::api::result get_deferred_operation_result_khr(ktl::api::device _device, ktl::api::deferred_operation_khr _operation)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_deferred_operation_result_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_deferred_operation_result_khr)ptr)(_device, _operation);
}

inline ktl::api::result deferred_operation_join_khr(ktl::api::device _device, ktl::api::deferred_operation_khr _operation)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::deferred_operation_join_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_deferred_operation_join_khr)ptr)(_device, _operation);
}

inline void get_pipeline_indirect_memory_requirements_nv(ktl::api::device _device, const ktl::api::compute_pipeline_create_info * _p_create_info, ktl::api::memory_requirements_2 * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_pipeline_indirect_memory_requirements_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_pipeline_indirect_memory_requirements_nv)ptr)(_device, _p_create_info, _p_memory_requirements);
}

inline ktl::api::dvaddr get_pipeline_indirect_device_address_nv(ktl::api::device _device, const ktl::api::pipeline_indirect_device_address_info_nv * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_pipeline_indirect_device_address_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_pipeline_indirect_device_address_nv)ptr)(_device, _p_info);
}

inline void anti_lag_update_amd(ktl::api::device _device, const ktl::api::anti_lag_data_amd * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::anti_lag_update_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_anti_lag_update_amd)ptr)(_device, _p_data);
}

inline void cmd_set_cull_mode(ktl::api::command_buffer _command_buffer, ktl::api::cull_mode_flags _cull_mode)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_cull_mode)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_cull_mode)ptr)(_command_buffer, _cull_mode);
}

inline void cmd_set_front_face(ktl::api::command_buffer _command_buffer, ktl::api::front_face _front_face)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_front_face)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_front_face)ptr)(_command_buffer, _front_face);
}

inline void cmd_set_primitive_topology(ktl::api::command_buffer _command_buffer, ktl::api::primitive_topology _primitive_topology)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_primitive_topology)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_primitive_topology)ptr)(_command_buffer, _primitive_topology);
}

inline void cmd_set_viewport_with_count(ktl::api::command_buffer _command_buffer, ktl::u32 _viewport_count, const ktl::api::viewport * _p_viewports)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_viewport_with_count)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_viewport_with_count)ptr)(_command_buffer, _viewport_count, _p_viewports);
}

inline void cmd_set_scissor_with_count(ktl::api::command_buffer _command_buffer, ktl::u32 _scissor_count, const ktl::api::rect_2d * _p_scissors)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_scissor_with_count)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_scissor_with_count)ptr)(_command_buffer, _scissor_count, _p_scissors);
}

inline void cmd_bind_index_buffer_2(ktl::api::command_buffer _command_buffer, ktl::api::buffer _buffer, ktl::api::dvsize _offset, ktl::api::dvsize _size, ktl::api::index_type _index_type)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_index_buffer_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_index_buffer_2)ptr)(_command_buffer, _buffer, _offset, _size, _index_type);
}

inline void cmd_bind_vertex_buffers_2(ktl::api::command_buffer _command_buffer, ktl::u32 _first_binding, ktl::u32 _binding_count, const ktl::api::buffer * _p_buffers, const ktl::api::dvsize * _p_offsets, const ktl::api::dvsize * _p_sizes, const ktl::api::dvsize * _p_strides)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_vertex_buffers_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_vertex_buffers_2)ptr)(_command_buffer, _first_binding, _binding_count, _p_buffers, _p_offsets, _p_sizes, _p_strides);
}

inline void cmd_set_depth_test_enable(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _depth_test_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_test_enable)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_test_enable)ptr)(_command_buffer, _depth_test_enable);
}

inline void cmd_set_depth_write_enable(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _depth_write_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_write_enable)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_write_enable)ptr)(_command_buffer, _depth_write_enable);
}

inline void cmd_set_depth_compare_op(ktl::api::command_buffer _command_buffer, ktl::api::compare_op _depth_compare_op)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_compare_op)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_compare_op)ptr)(_command_buffer, _depth_compare_op);
}

inline void cmd_set_depth_bounds_test_enable(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _depth_bounds_test_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_bounds_test_enable)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_bounds_test_enable)ptr)(_command_buffer, _depth_bounds_test_enable);
}

inline void cmd_set_stencil_test_enable(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _stencil_test_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_stencil_test_enable)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_stencil_test_enable)ptr)(_command_buffer, _stencil_test_enable);
}

inline void cmd_set_stencil_op(ktl::api::command_buffer _command_buffer, ktl::api::stencil_face_flags _face_mask, ktl::api::stencil_op _fail_op, ktl::api::stencil_op _pass_op, ktl::api::stencil_op _depth_fail_op, ktl::api::compare_op _compare_op)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_stencil_op)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_stencil_op)ptr)(_command_buffer, _face_mask, _fail_op, _pass_op, _depth_fail_op, _compare_op);
}

inline void cmd_set_patch_control_points_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _patch_control_points)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_patch_control_points_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_patch_control_points_ext)ptr)(_command_buffer, _patch_control_points);
}

inline void cmd_set_rasterizer_discard_enable(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _rasterizer_discard_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_rasterizer_discard_enable)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_rasterizer_discard_enable)ptr)(_command_buffer, _rasterizer_discard_enable);
}

inline void cmd_set_depth_bias_enable(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _depth_bias_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_bias_enable)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_bias_enable)ptr)(_command_buffer, _depth_bias_enable);
}

inline void cmd_set_logic_op_ext(ktl::api::command_buffer _command_buffer, ktl::api::logic_op _logic_op)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_logic_op_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_logic_op_ext)ptr)(_command_buffer, _logic_op);
}

inline void cmd_set_primitive_restart_enable(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _primitive_restart_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_primitive_restart_enable)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_primitive_restart_enable)ptr)(_command_buffer, _primitive_restart_enable);
}

inline void cmd_set_tessellation_domain_origin_ext(ktl::api::command_buffer _command_buffer, ktl::api::tessellation_domain_origin _domain_origin)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_tessellation_domain_origin_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_tessellation_domain_origin_ext)ptr)(_command_buffer, _domain_origin);
}

inline void cmd_set_depth_clamp_enable_ext(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _depth_clamp_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_clamp_enable_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_clamp_enable_ext)ptr)(_command_buffer, _depth_clamp_enable);
}

inline void cmd_set_polygon_mode_ext(ktl::api::command_buffer _command_buffer, ktl::api::polygon_mode _polygon_mode)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_polygon_mode_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_polygon_mode_ext)ptr)(_command_buffer, _polygon_mode);
}

inline void cmd_set_rasterization_samples_ext(ktl::api::command_buffer _command_buffer, ktl::api::sample_count_flag_bits _rasterization_samples)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_rasterization_samples_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_rasterization_samples_ext)ptr)(_command_buffer, _rasterization_samples);
}

inline void cmd_set_sample_mask_ext(ktl::api::command_buffer _command_buffer, ktl::api::sample_count_flag_bits _samples, const ktl::api::spmask * _p_sample_mask)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_sample_mask_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_sample_mask_ext)ptr)(_command_buffer, _samples, _p_sample_mask);
}

inline void cmd_set_alpha_to_coverage_enable_ext(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _alpha_to_coverage_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_alpha_to_coverage_enable_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_alpha_to_coverage_enable_ext)ptr)(_command_buffer, _alpha_to_coverage_enable);
}

inline void cmd_set_alpha_to_one_enable_ext(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _alpha_to_one_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_alpha_to_one_enable_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_alpha_to_one_enable_ext)ptr)(_command_buffer, _alpha_to_one_enable);
}

inline void cmd_set_logic_op_enable_ext(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _logic_op_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_logic_op_enable_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_logic_op_enable_ext)ptr)(_command_buffer, _logic_op_enable);
}

inline void cmd_set_color_blend_enable_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _first_attachment, ktl::u32 _attachment_count, const ktl::api::bool32 * _p_color_blend_enables)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_color_blend_enable_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_color_blend_enable_ext)ptr)(_command_buffer, _first_attachment, _attachment_count, _p_color_blend_enables);
}

inline void cmd_set_color_blend_equation_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _first_attachment, ktl::u32 _attachment_count, const ktl::api::color_blend_equation_ext * _p_color_blend_equations)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_color_blend_equation_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_color_blend_equation_ext)ptr)(_command_buffer, _first_attachment, _attachment_count, _p_color_blend_equations);
}

inline void cmd_set_color_write_mask_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _first_attachment, ktl::u32 _attachment_count, const ktl::api::color_component_flags * _p_color_write_masks)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_color_write_mask_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_color_write_mask_ext)ptr)(_command_buffer, _first_attachment, _attachment_count, _p_color_write_masks);
}

inline void cmd_set_rasterization_stream_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _rasterization_stream)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_rasterization_stream_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_rasterization_stream_ext)ptr)(_command_buffer, _rasterization_stream);
}

inline void cmd_set_conservative_rasterization_mode_ext(ktl::api::command_buffer _command_buffer, ktl::api::conservative_rasterization_mode_ext _conservative_rasterization_mode)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_conservative_rasterization_mode_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_conservative_rasterization_mode_ext)ptr)(_command_buffer, _conservative_rasterization_mode);
}

inline void cmd_set_extra_primitive_overestimation_size_ext(ktl::api::command_buffer _command_buffer, float _extra_primitive_overestimation_size)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_extra_primitive_overestimation_size_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_extra_primitive_overestimation_size_ext)ptr)(_command_buffer, _extra_primitive_overestimation_size);
}

inline void cmd_set_depth_clip_enable_ext(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _depth_clip_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_clip_enable_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_clip_enable_ext)ptr)(_command_buffer, _depth_clip_enable);
}

inline void cmd_set_sample_locations_enable_ext(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _sample_locations_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_sample_locations_enable_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_sample_locations_enable_ext)ptr)(_command_buffer, _sample_locations_enable);
}

inline void cmd_set_color_blend_advanced_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _first_attachment, ktl::u32 _attachment_count, const ktl::api::color_blend_advanced_ext * _p_color_blend_advanced)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_color_blend_advanced_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_color_blend_advanced_ext)ptr)(_command_buffer, _first_attachment, _attachment_count, _p_color_blend_advanced);
}

inline void cmd_set_provoking_vertex_mode_ext(ktl::api::command_buffer _command_buffer, ktl::api::provoking_vertex_mode_ext _provoking_vertex_mode)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_provoking_vertex_mode_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_provoking_vertex_mode_ext)ptr)(_command_buffer, _provoking_vertex_mode);
}

inline void cmd_set_line_rasterization_mode_ext(ktl::api::command_buffer _command_buffer, ktl::api::line_rasterization_mode_ext _line_rasterization_mode)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_line_rasterization_mode_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_line_rasterization_mode_ext)ptr)(_command_buffer, _line_rasterization_mode);
}

inline void cmd_set_line_stipple_enable_ext(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _stippled_line_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_line_stipple_enable_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_line_stipple_enable_ext)ptr)(_command_buffer, _stippled_line_enable);
}

inline void cmd_set_depth_clip_negative_one_to_one_ext(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _negative_one_to_one)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_clip_negative_one_to_one_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_clip_negative_one_to_one_ext)ptr)(_command_buffer, _negative_one_to_one);
}

inline void cmd_set_viewport_w_scaling_enable_nv(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _viewport_w_scaling_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_viewport_w_scaling_enable_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_viewport_w_scaling_enable_nv)ptr)(_command_buffer, _viewport_w_scaling_enable);
}

inline void cmd_set_viewport_swizzle_nv(ktl::api::command_buffer _command_buffer, ktl::u32 _first_viewport, ktl::u32 _viewport_count, const ktl::api::viewport_swizzle_nv * _p_viewport_swizzles)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_viewport_swizzle_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_viewport_swizzle_nv)ptr)(_command_buffer, _first_viewport, _viewport_count, _p_viewport_swizzles);
}

inline void cmd_set_coverage_to_color_enable_nv(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _coverage_to_color_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_coverage_to_color_enable_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_coverage_to_color_enable_nv)ptr)(_command_buffer, _coverage_to_color_enable);
}

inline void cmd_set_coverage_to_color_location_nv(ktl::api::command_buffer _command_buffer, ktl::u32 _coverage_to_color_location)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_coverage_to_color_location_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_coverage_to_color_location_nv)ptr)(_command_buffer, _coverage_to_color_location);
}

inline void cmd_set_coverage_modulation_mode_nv(ktl::api::command_buffer _command_buffer, ktl::api::coverage_modulation_mode_nv _coverage_modulation_mode)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_coverage_modulation_mode_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_coverage_modulation_mode_nv)ptr)(_command_buffer, _coverage_modulation_mode);
}

inline void cmd_set_coverage_modulation_table_enable_nv(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _coverage_modulation_table_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_coverage_modulation_table_enable_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_coverage_modulation_table_enable_nv)ptr)(_command_buffer, _coverage_modulation_table_enable);
}

inline void cmd_set_coverage_modulation_table_nv(ktl::api::command_buffer _command_buffer, ktl::u32 _coverage_modulation_table_count, const float * _p_coverage_modulation_table)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_coverage_modulation_table_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_coverage_modulation_table_nv)ptr)(_command_buffer, _coverage_modulation_table_count, _p_coverage_modulation_table);
}

inline void cmd_set_shading_rate_image_enable_nv(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _shading_rate_image_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_shading_rate_image_enable_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_shading_rate_image_enable_nv)ptr)(_command_buffer, _shading_rate_image_enable);
}

inline void cmd_set_coverage_reduction_mode_nv(ktl::api::command_buffer _command_buffer, ktl::api::coverage_reduction_mode_nv _coverage_reduction_mode)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_coverage_reduction_mode_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_coverage_reduction_mode_nv)ptr)(_command_buffer, _coverage_reduction_mode);
}

inline void cmd_set_representative_fragment_test_enable_nv(ktl::api::command_buffer _command_buffer, ktl::api::bool32 _representative_fragment_test_enable)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_representative_fragment_test_enable_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_representative_fragment_test_enable_nv)ptr)(_command_buffer, _representative_fragment_test_enable);
}

inline ktl::api::result create_private_data_slot(ktl::api::device _device, const ktl::api::private_data_slot_create_info * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::private_data_slot * _p_private_data_slot)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_private_data_slot)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_private_data_slot)ptr)(_device, _p_create_info, _p_allocator, _p_private_data_slot);
}

inline void destroy_private_data_slot(ktl::api::device _device, ktl::api::private_data_slot _private_data_slot, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_private_data_slot)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_private_data_slot)ptr)(_device, _private_data_slot, _p_allocator);
}

inline ktl::api::result set_private_data(ktl::api::device _device, ktl::api::object_type _object_type, ktl::u64 _object_handle, ktl::api::private_data_slot _private_data_slot, ktl::u64 _data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_private_data)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_private_data)ptr)(_device, _object_type, _object_handle, _private_data_slot, _data);
}

inline void get_private_data(ktl::api::device _device, ktl::api::object_type _object_type, ktl::u64 _object_handle, ktl::api::private_data_slot _private_data_slot, ktl::u64 * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_private_data)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_private_data)ptr)(_device, _object_type, _object_handle, _private_data_slot, _p_data);
}

inline void cmd_copy_buffer_2(ktl::api::command_buffer _command_buffer, const ktl::api::copy_buffer_info_2 * _p_copy_buffer_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_buffer_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_buffer_2)ptr)(_command_buffer, _p_copy_buffer_info);
}

inline void cmd_copy_image_2(ktl::api::command_buffer _command_buffer, const ktl::api::copy_image_info_2 * _p_copy_image_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_image_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_image_2)ptr)(_command_buffer, _p_copy_image_info);
}

inline void cmd_blit_image_2(ktl::api::command_buffer _command_buffer, const ktl::api::blit_image_info_2 * _p_blit_image_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_blit_image_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_blit_image_2)ptr)(_command_buffer, _p_blit_image_info);
}

inline void cmd_copy_buffer_to_image_2(ktl::api::command_buffer _command_buffer, const ktl::api::copy_buffer_to_image_info_2 * _p_copy_buffer_to_image_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_buffer_to_image_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_buffer_to_image_2)ptr)(_command_buffer, _p_copy_buffer_to_image_info);
}

inline void cmd_copy_image_to_buffer_2(ktl::api::command_buffer _command_buffer, const ktl::api::copy_image_to_buffer_info_2 * _p_copy_image_to_buffer_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_image_to_buffer_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_image_to_buffer_2)ptr)(_command_buffer, _p_copy_image_to_buffer_info);
}

inline void cmd_resolve_image_2(ktl::api::command_buffer _command_buffer, const ktl::api::resolve_image_info_2 * _p_resolve_image_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_resolve_image_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_resolve_image_2)ptr)(_command_buffer, _p_resolve_image_info);
}

inline void cmd_refresh_objects_khr(ktl::api::command_buffer _command_buffer, const ktl::api::refresh_object_list_khr * _p_refresh_objects)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_refresh_objects_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_refresh_objects_khr)ptr)(_command_buffer, _p_refresh_objects);
}

inline ktl::api::result get_physical_device_refreshable_object_types_khr(ktl::api::physical_device _physical_device, ktl::u32 * _p_refreshable_object_type_count, ktl::api::object_type * _p_refreshable_object_types)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_refreshable_object_types_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_refreshable_object_types_khr)ptr)(_physical_device, _p_refreshable_object_type_count, _p_refreshable_object_types);
}

inline void cmd_set_fragment_shading_rate_khr(ktl::api::command_buffer _command_buffer, const ktl::api::extent_2d * _p_fragment_size, const ktl::api::fragment_shading_rate_combiner_op_khr _combiner_ops[2])
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_fragment_shading_rate_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_fragment_shading_rate_khr)ptr)(_command_buffer, _p_fragment_size, _combiner_ops);
}

inline ktl::api::result get_physical_device_fragment_shading_rates_khr(ktl::api::physical_device _physical_device, ktl::u32 * _p_fragment_shading_rate_count, ktl::api::physical_device_fragment_shading_rate_khr * _p_fragment_shading_rates)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_fragment_shading_rates_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_fragment_shading_rates_khr)ptr)(_physical_device, _p_fragment_shading_rate_count, _p_fragment_shading_rates);
}

inline void cmd_set_fragment_shading_rate_enum_nv(ktl::api::command_buffer _command_buffer, ktl::api::fragment_shading_rate_nv _shading_rate, const ktl::api::fragment_shading_rate_combiner_op_khr _combiner_ops[2])
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_fragment_shading_rate_enum_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_fragment_shading_rate_enum_nv)ptr)(_command_buffer, _shading_rate, _combiner_ops);
}

inline void get_acceleration_structure_build_sizes_khr(ktl::api::device _device, ktl::api::acceleration_structure_build_type_khr _build_type, const ktl::api::acceleration_structure_build_geometry_info_khr * _p_build_info, const ktl::u32 * _p_max_primitive_counts, ktl::api::acceleration_structure_build_sizes_info_khr * _p_size_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_acceleration_structure_build_sizes_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_acceleration_structure_build_sizes_khr)ptr)(_device, _build_type, _p_build_info, _p_max_primitive_counts, _p_size_info);
}

inline void cmd_set_vertex_input_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _vertex_binding_description_count, const ktl::api::vertex_input_binding_description_2ext * _p_vertex_binding_descriptions, ktl::u32 _vertex_attribute_description_count, const ktl::api::vertex_input_attribute_description_2ext * _p_vertex_attribute_descriptions)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_vertex_input_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_vertex_input_ext)ptr)(_command_buffer, _vertex_binding_description_count, _p_vertex_binding_descriptions, _vertex_attribute_description_count, _p_vertex_attribute_descriptions);
}

inline void cmd_set_color_write_enable_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _attachment_count, const ktl::api::bool32 * _p_color_write_enables)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_color_write_enable_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_color_write_enable_ext)ptr)(_command_buffer, _attachment_count, _p_color_write_enables);
}

inline void cmd_set_event_2(ktl::api::command_buffer _command_buffer, ktl::api::event _event, const ktl::api::dependency_info * _p_dependency_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_event_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_event_2)ptr)(_command_buffer, _event, _p_dependency_info);
}

inline void cmd_reset_event_2(ktl::api::command_buffer _command_buffer, ktl::api::event _event, ktl::api::pipeline_stage_flags_2 _stage_mask)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_reset_event_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_reset_event_2)ptr)(_command_buffer, _event, _stage_mask);
}

inline void cmd_wait_events_2(ktl::api::command_buffer _command_buffer, ktl::u32 _event_count, const ktl::api::event * _p_events, const ktl::api::dependency_info * _p_dependency_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_wait_events_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_wait_events_2)ptr)(_command_buffer, _event_count, _p_events, _p_dependency_infos);
}

inline void cmd_pipeline_barrier_2(ktl::api::command_buffer _command_buffer, const ktl::api::dependency_info * _p_dependency_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_pipeline_barrier_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_pipeline_barrier_2)ptr)(_command_buffer, _p_dependency_info);
}

inline ktl::api::result queue_submit_2(ktl::api::queue _queue, ktl::u32 _submit_count, const ktl::api::submit_info_2 * _p_submits, ktl::api::fence _fence)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_submit_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_submit_2)ptr)(_queue, _submit_count, _p_submits, _fence);
}

inline void cmd_write_timestamp_2(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_stage_flags_2 _stage, ktl::api::query_pool _query_pool, ktl::u32 _query)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_write_timestamp_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_write_timestamp_2)ptr)(_command_buffer, _stage, _query_pool, _query);
}

inline void cmd_write_buffer_marker_2amd(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_stage_flags_2 _stage, ktl::api::buffer _dst_buffer, ktl::api::dvsize _dst_offset, ktl::u32 _marker)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_write_buffer_marker_2amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_write_buffer_marker_2amd)ptr)(_command_buffer, _stage, _dst_buffer, _dst_offset, _marker);
}

inline void get_queue_checkpoint_data_2nv(ktl::api::queue _queue, ktl::u32 * _p_checkpoint_data_count, ktl::api::checkpoint_data_2nv * _p_checkpoint_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_queue_checkpoint_data_2nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_queue_checkpoint_data_2nv)ptr)(_queue, _p_checkpoint_data_count, _p_checkpoint_data);
}

inline ktl::api::result copy_memory_to_image(ktl::api::device _device, const ktl::api::copy_memory_to_image_info * _p_copy_memory_to_image_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::copy_memory_to_image)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_copy_memory_to_image)ptr)(_device, _p_copy_memory_to_image_info);
}

inline ktl::api::result copy_image_to_memory(ktl::api::device _device, const ktl::api::copy_image_to_memory_info * _p_copy_image_to_memory_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::copy_image_to_memory)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_copy_image_to_memory)ptr)(_device, _p_copy_image_to_memory_info);
}

inline ktl::api::result copy_image_to_image(ktl::api::device _device, const ktl::api::copy_image_to_image_info * _p_copy_image_to_image_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::copy_image_to_image)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_copy_image_to_image)ptr)(_device, _p_copy_image_to_image_info);
}

inline ktl::api::result transition_image_layout(ktl::api::device _device, ktl::u32 _transition_count, const ktl::api::host_image_layout_transition_info * _p_transitions)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::transition_image_layout)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_transition_image_layout)ptr)(_device, _transition_count, _p_transitions);
}

inline void get_command_pool_memory_consumption(ktl::api::device _device, ktl::api::command_pool _command_pool, ktl::api::command_buffer _command_buffer, ktl::api::command_pool_memory_consumption * _p_consumption)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_command_pool_memory_consumption)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_command_pool_memory_consumption)ptr)(_device, _command_pool, _command_buffer, _p_consumption);
}

inline void cmd_decompress_memory_nv(ktl::api::command_buffer _command_buffer, ktl::u32 _decompress_region_count, const ktl::api::decompress_memory_region_nv * _p_decompress_memory_regions)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_decompress_memory_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_decompress_memory_nv)ptr)(_command_buffer, _decompress_region_count, _p_decompress_memory_regions);
}

inline void cmd_decompress_memory_indirect_count_nv(ktl::api::command_buffer _command_buffer, ktl::api::dvaddr _indirect_commands_address, ktl::api::dvaddr _indirect_commands_count_address, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_decompress_memory_indirect_count_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_decompress_memory_indirect_count_nv)ptr)(_command_buffer, _indirect_commands_address, _indirect_commands_count_address, _stride);
}

inline void get_partitioned_acceleration_structures_build_sizes_nv(ktl::api::device _device, const ktl::api::partitioned_acceleration_structure_instances_input_nv * _p_info, ktl::api::acceleration_structure_build_sizes_info_khr * _p_size_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_partitioned_acceleration_structures_build_sizes_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_partitioned_acceleration_structures_build_sizes_nv)ptr)(_device, _p_info, _p_size_info);
}

inline void cmd_build_partitioned_acceleration_structures_nv(ktl::api::command_buffer _command_buffer, const ktl::api::build_partitioned_acceleration_structure_info_nv * _p_build_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_build_partitioned_acceleration_structures_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_build_partitioned_acceleration_structures_nv)ptr)(_command_buffer, _p_build_info);
}

inline void cmd_decompress_memory_ext(ktl::api::command_buffer _command_buffer, const ktl::api::decompress_memory_info_ext * _p_decompress_memory_info_ext)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_decompress_memory_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_decompress_memory_ext)ptr)(_command_buffer, _p_decompress_memory_info_ext);
}

inline void cmd_decompress_memory_indirect_count_ext(ktl::api::command_buffer _command_buffer, ktl::api::memory_decompression_method_flags_ext _decompression_method, ktl::api::dvaddr _indirect_commands_address, ktl::api::dvaddr _indirect_commands_count_address, ktl::u32 _max_decompression_count, ktl::u32 _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_decompress_memory_indirect_count_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_decompress_memory_indirect_count_ext)ptr)(_command_buffer, _decompression_method, _indirect_commands_address, _indirect_commands_count_address, _max_decompression_count, _stride);
}

inline ktl::api::result create_cu_module_nvx(ktl::api::device _device, const ktl::api::cu_module_create_info_nvx * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::cu_module_nvx * _p_module)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_cu_module_nvx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_cu_module_nvx)ptr)(_device, _p_create_info, _p_allocator, _p_module);
}

inline ktl::api::result create_cu_function_nvx(ktl::api::device _device, const ktl::api::cu_function_create_info_nvx * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::cu_function_nvx * _p_function)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_cu_function_nvx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_cu_function_nvx)ptr)(_device, _p_create_info, _p_allocator, _p_function);
}

inline void destroy_cu_module_nvx(ktl::api::device _device, ktl::api::cu_module_nvx _module, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_cu_module_nvx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_cu_module_nvx)ptr)(_device, _module, _p_allocator);
}

inline void destroy_cu_function_nvx(ktl::api::device _device, ktl::api::cu_function_nvx _function, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_cu_function_nvx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_cu_function_nvx)ptr)(_device, _function, _p_allocator);
}

inline void cmd_cu_launch_kernel_nvx(ktl::api::command_buffer _command_buffer, const ktl::api::cu_launch_info_nvx * _p_launch_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_cu_launch_kernel_nvx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_cu_launch_kernel_nvx)ptr)(_command_buffer, _p_launch_info);
}

inline void get_descriptor_set_layout_size_ext(ktl::api::device _device, ktl::api::descriptor_set_layout _layout, ktl::api::dvsize * _p_layout_size_in_bytes)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_descriptor_set_layout_size_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_descriptor_set_layout_size_ext)ptr)(_device, _layout, _p_layout_size_in_bytes);
}

inline void get_descriptor_set_layout_binding_offset_ext(ktl::api::device _device, ktl::api::descriptor_set_layout _layout, ktl::u32 _binding, ktl::api::dvsize * _p_offset)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_descriptor_set_layout_binding_offset_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_descriptor_set_layout_binding_offset_ext)ptr)(_device, _layout, _binding, _p_offset);
}

inline void get_descriptor_ext(ktl::api::device _device, const ktl::api::descriptor_get_info_ext * _p_descriptor_info, ktl::usize _data_size, void * _p_descriptor)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_descriptor_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_descriptor_ext)ptr)(_device, _p_descriptor_info, _data_size, _p_descriptor);
}

inline void cmd_bind_descriptor_buffers_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _buffer_count, const ktl::api::descriptor_buffer_binding_info_ext * _p_binding_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_descriptor_buffers_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_descriptor_buffers_ext)ptr)(_command_buffer, _buffer_count, _p_binding_infos);
}

inline void cmd_set_descriptor_buffer_offsets_ext(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_bind_point _pipeline_bind_point, ktl::api::pipeline_layout _layout, ktl::u32 _first_set, ktl::u32 _set_count, const ktl::u32 * _p_buffer_indices, const ktl::api::dvsize * _p_offsets)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_descriptor_buffer_offsets_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_descriptor_buffer_offsets_ext)ptr)(_command_buffer, _pipeline_bind_point, _layout, _first_set, _set_count, _p_buffer_indices, _p_offsets);
}

inline void cmd_bind_descriptor_buffer_embedded_samplers_ext(ktl::api::command_buffer _command_buffer, ktl::api::pipeline_bind_point _pipeline_bind_point, ktl::api::pipeline_layout _layout, ktl::u32 _set)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_descriptor_buffer_embedded_samplers_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_descriptor_buffer_embedded_samplers_ext)ptr)(_command_buffer, _pipeline_bind_point, _layout, _set);
}

inline ktl::api::result get_buffer_opaque_capture_descriptor_data_ext(ktl::api::device _device, const ktl::api::buffer_capture_descriptor_data_info_ext * _p_info, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_buffer_opaque_capture_descriptor_data_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_buffer_opaque_capture_descriptor_data_ext)ptr)(_device, _p_info, _p_data);
}

inline ktl::api::result get_image_opaque_capture_descriptor_data_ext(ktl::api::device _device, const ktl::api::image_capture_descriptor_data_info_ext * _p_info, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_opaque_capture_descriptor_data_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_opaque_capture_descriptor_data_ext)ptr)(_device, _p_info, _p_data);
}

inline ktl::api::result get_image_view_opaque_capture_descriptor_data_ext(ktl::api::device _device, const ktl::api::image_view_capture_descriptor_data_info_ext * _p_info, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_view_opaque_capture_descriptor_data_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_view_opaque_capture_descriptor_data_ext)ptr)(_device, _p_info, _p_data);
}

inline ktl::api::result get_sampler_opaque_capture_descriptor_data_ext(ktl::api::device _device, const ktl::api::sampler_capture_descriptor_data_info_ext * _p_info, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_sampler_opaque_capture_descriptor_data_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_sampler_opaque_capture_descriptor_data_ext)ptr)(_device, _p_info, _p_data);
}

inline ktl::api::result get_acceleration_structure_opaque_capture_descriptor_data_ext(ktl::api::device _device, const ktl::api::acceleration_structure_capture_descriptor_data_info_ext * _p_info, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_acceleration_structure_opaque_capture_descriptor_data_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_acceleration_structure_opaque_capture_descriptor_data_ext)ptr)(_device, _p_info, _p_data);
}

inline void set_device_memory_priority_ext(ktl::api::device _device, ktl::api::device_memory _memory, float _priority)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_device_memory_priority_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_device_memory_priority_ext)ptr)(_device, _memory, _priority);
}

inline ktl::api::result acquire_drm_display_ext(ktl::api::physical_device _physical_device, ktl::i32 _drm_fd, ktl::api::display_khr _display)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::acquire_drm_display_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_acquire_drm_display_ext)ptr)(_physical_device, _drm_fd, _display);
}

inline ktl::api::result get_drm_display_ext(ktl::api::physical_device _physical_device, ktl::i32 _drm_fd, ktl::u32 _connector_id, ktl::api::display_khr * _display)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_drm_display_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_drm_display_ext)ptr)(_physical_device, _drm_fd, _connector_id, _display);
}

inline ktl::api::result wait_for_present_2khr(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, const ktl::api::present_wait_2info_khr * _p_present_wait_2info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::wait_for_present_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_wait_for_present_2khr)ptr)(_device, _swapchain, _p_present_wait_2info);
}

inline ktl::api::result wait_for_present_khr(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, ktl::u64 _present_id, ktl::u64 _timeout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::wait_for_present_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_wait_for_present_khr)ptr)(_device, _swapchain, _present_id, _timeout);
}

inline ktl::api::result create_buffer_collection_fuchsia(ktl::api::device _device, const ktl::api::buffer_collection_create_info_fuchsia * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::buffer_collection_fuchsia * _p_collection)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_buffer_collection_fuchsia)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_buffer_collection_fuchsia)ptr)(_device, _p_create_info, _p_allocator, _p_collection);
}

inline ktl::api::result set_buffer_collection_buffer_constraints_fuchsia(ktl::api::device _device, ktl::api::buffer_collection_fuchsia _collection, const ktl::api::buffer_constraints_info_fuchsia * _p_buffer_constraints_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_buffer_collection_buffer_constraints_fuchsia)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_buffer_collection_buffer_constraints_fuchsia)ptr)(_device, _collection, _p_buffer_constraints_info);
}

inline ktl::api::result set_buffer_collection_image_constraints_fuchsia(ktl::api::device _device, ktl::api::buffer_collection_fuchsia _collection, const ktl::api::image_constraints_info_fuchsia * _p_image_constraints_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_buffer_collection_image_constraints_fuchsia)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_buffer_collection_image_constraints_fuchsia)ptr)(_device, _collection, _p_image_constraints_info);
}

inline void destroy_buffer_collection_fuchsia(ktl::api::device _device, ktl::api::buffer_collection_fuchsia _collection, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_buffer_collection_fuchsia)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_buffer_collection_fuchsia)ptr)(_device, _collection, _p_allocator);
}

inline ktl::api::result get_buffer_collection_properties_fuchsia(ktl::api::device _device, ktl::api::buffer_collection_fuchsia _collection, ktl::api::buffer_collection_properties_fuchsia * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_buffer_collection_properties_fuchsia)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_buffer_collection_properties_fuchsia)ptr)(_device, _collection, _p_properties);
}

inline ktl::api::result create_cuda_module_nv(ktl::api::device _device, const ktl::api::cuda_module_create_info_nv * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::cuda_module_nv * _p_module)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_cuda_module_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_cuda_module_nv)ptr)(_device, _p_create_info, _p_allocator, _p_module);
}

inline ktl::api::result get_cuda_module_cache_nv(ktl::api::device _device, ktl::api::cuda_module_nv _module, ktl::usize * _p_cache_size, void * _p_cache_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_cuda_module_cache_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_cuda_module_cache_nv)ptr)(_device, _module, _p_cache_size, _p_cache_data);
}

inline ktl::api::result create_cuda_function_nv(ktl::api::device _device, const ktl::api::cuda_function_create_info_nv * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::cuda_function_nv * _p_function)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_cuda_function_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_cuda_function_nv)ptr)(_device, _p_create_info, _p_allocator, _p_function);
}

inline void destroy_cuda_module_nv(ktl::api::device _device, ktl::api::cuda_module_nv _module, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_cuda_module_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_cuda_module_nv)ptr)(_device, _module, _p_allocator);
}

inline void destroy_cuda_function_nv(ktl::api::device _device, ktl::api::cuda_function_nv _function, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_cuda_function_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_cuda_function_nv)ptr)(_device, _function, _p_allocator);
}

inline void cmd_cuda_launch_kernel_nv(ktl::api::command_buffer _command_buffer, const ktl::api::cuda_launch_info_nv * _p_launch_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_cuda_launch_kernel_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_cuda_launch_kernel_nv)ptr)(_command_buffer, _p_launch_info);
}

inline void cmd_begin_rendering(ktl::api::command_buffer _command_buffer, const ktl::api::rendering_info * _p_rendering_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_rendering)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_rendering)ptr)(_command_buffer, _p_rendering_info);
}

inline void cmd_end_rendering(ktl::api::command_buffer _command_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_rendering)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_rendering)ptr)(_command_buffer);
}

inline void cmd_end_rendering_2khr(ktl::api::command_buffer _command_buffer, const ktl::api::rendering_end_info_khr * _p_rendering_end_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_rendering_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_rendering_2khr)ptr)(_command_buffer, _p_rendering_end_info);
}

inline void get_descriptor_set_layout_host_mapping_info_valve(ktl::api::device _device, const ktl::api::descriptor_set_binding_reference_valve * _p_binding_reference, ktl::api::descriptor_set_layout_host_mapping_info_valve * _p_host_mapping)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_descriptor_set_layout_host_mapping_info_valve)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_descriptor_set_layout_host_mapping_info_valve)ptr)(_device, _p_binding_reference, _p_host_mapping);
}

inline void get_descriptor_set_host_mapping_valve(ktl::api::device _device, ktl::api::descriptor_set _descriptor_set, void * _pp_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_descriptor_set_host_mapping_valve)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_descriptor_set_host_mapping_valve)ptr)(_device, _descriptor_set, _pp_data);
}

inline ktl::api::result create_micromap_ext(ktl::api::device _device, const ktl::api::micromap_create_info_ext * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::micromap_ext * _p_micromap)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_micromap_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_micromap_ext)ptr)(_device, _p_create_info, _p_allocator, _p_micromap);
}

inline void cmd_build_micromaps_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _info_count, const ktl::api::micromap_build_info_ext * _p_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_build_micromaps_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_build_micromaps_ext)ptr)(_command_buffer, _info_count, _p_infos);
}

inline ktl::api::result build_micromaps_ext(ktl::api::device _device, ktl::api::deferred_operation_khr _deferred_operation, ktl::u32 _info_count, const ktl::api::micromap_build_info_ext * _p_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::build_micromaps_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_build_micromaps_ext)ptr)(_device, _deferred_operation, _info_count, _p_infos);
}

inline void destroy_micromap_ext(ktl::api::device _device, ktl::api::micromap_ext _micromap, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_micromap_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_micromap_ext)ptr)(_device, _micromap, _p_allocator);
}

inline void cmd_copy_micromap_ext(ktl::api::command_buffer _command_buffer, const ktl::api::copy_micromap_info_ext * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_micromap_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_micromap_ext)ptr)(_command_buffer, _p_info);
}

inline ktl::api::result copy_micromap_ext(ktl::api::device _device, ktl::api::deferred_operation_khr _deferred_operation, const ktl::api::copy_micromap_info_ext * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::copy_micromap_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_copy_micromap_ext)ptr)(_device, _deferred_operation, _p_info);
}

inline void cmd_copy_micromap_to_memory_ext(ktl::api::command_buffer _command_buffer, const ktl::api::copy_micromap_to_memory_info_ext * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_micromap_to_memory_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_micromap_to_memory_ext)ptr)(_command_buffer, _p_info);
}

inline ktl::api::result copy_micromap_to_memory_ext(ktl::api::device _device, ktl::api::deferred_operation_khr _deferred_operation, const ktl::api::copy_micromap_to_memory_info_ext * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::copy_micromap_to_memory_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_copy_micromap_to_memory_ext)ptr)(_device, _deferred_operation, _p_info);
}

inline void cmd_copy_memory_to_micromap_ext(ktl::api::command_buffer _command_buffer, const ktl::api::copy_memory_to_micromap_info_ext * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_memory_to_micromap_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_memory_to_micromap_ext)ptr)(_command_buffer, _p_info);
}

inline ktl::api::result copy_memory_to_micromap_ext(ktl::api::device _device, ktl::api::deferred_operation_khr _deferred_operation, const ktl::api::copy_memory_to_micromap_info_ext * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::copy_memory_to_micromap_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_copy_memory_to_micromap_ext)ptr)(_device, _deferred_operation, _p_info);
}

inline void cmd_write_micromaps_properties_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _micromap_count, const ktl::api::micromap_ext * _p_micromaps, ktl::api::query_type _query_type, ktl::api::query_pool _query_pool, ktl::u32 _first_query)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_write_micromaps_properties_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_write_micromaps_properties_ext)ptr)(_command_buffer, _micromap_count, _p_micromaps, _query_type, _query_pool, _first_query);
}

inline ktl::api::result write_micromaps_properties_ext(ktl::api::device _device, ktl::u32 _micromap_count, const ktl::api::micromap_ext * _p_micromaps, ktl::api::query_type _query_type, ktl::usize _data_size, void * _p_data, ktl::usize _stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::write_micromaps_properties_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_write_micromaps_properties_ext)ptr)(_device, _micromap_count, _p_micromaps, _query_type, _data_size, _p_data, _stride);
}

inline void get_device_micromap_compatibility_ext(ktl::api::device _device, const ktl::api::micromap_version_info_ext * _p_version_info, ktl::api::acceleration_structure_compatibility_khr * _p_compatibility)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_micromap_compatibility_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_micromap_compatibility_ext)ptr)(_device, _p_version_info, _p_compatibility);
}

inline void get_micromap_build_sizes_ext(ktl::api::device _device, ktl::api::acceleration_structure_build_type_khr _build_type, const ktl::api::micromap_build_info_ext * _p_build_info, ktl::api::micromap_build_sizes_info_ext * _p_size_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_micromap_build_sizes_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_micromap_build_sizes_ext)ptr)(_device, _build_type, _p_build_info, _p_size_info);
}

inline void get_shader_module_identifier_ext(ktl::api::device _device, ktl::api::shader_module _shader_module, ktl::api::shader_module_identifier_ext * _p_identifier)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_shader_module_identifier_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_shader_module_identifier_ext)ptr)(_device, _shader_module, _p_identifier);
}

inline void get_shader_module_create_info_identifier_ext(ktl::api::device _device, const ktl::api::shader_module_create_info * _p_create_info, ktl::api::shader_module_identifier_ext * _p_identifier)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_shader_module_create_info_identifier_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_shader_module_create_info_identifier_ext)ptr)(_device, _p_create_info, _p_identifier);
}

inline void get_image_subresource_layout_2(ktl::api::device _device, ktl::api::image _image, const ktl::api::image_subresource_2 * _p_subresource, ktl::api::subresource_layout_2 * _p_layout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_subresource_layout_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_subresource_layout_2)ptr)(_device, _image, _p_subresource, _p_layout);
}

inline ktl::api::result get_pipeline_properties_ext(ktl::api::device _device, const ktl::api::pipeline_info_khr * _p_pipeline_info, ktl::api::base_out_structure * _p_pipeline_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_pipeline_properties_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_pipeline_properties_ext)ptr)(_device, _p_pipeline_info, _p_pipeline_properties);
}

inline void export_metal_objects_ext(ktl::api::device _device, ktl::api::export_metal_objects_info_ext * _p_metal_objects_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::export_metal_objects_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_export_metal_objects_ext)ptr)(_device, _p_metal_objects_info);
}

inline void cmd_bind_tile_memory_qcom(ktl::api::command_buffer _command_buffer, const ktl::api::tile_memory_bind_info_qcom * _p_tile_memory_bind_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_tile_memory_qcom)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_tile_memory_qcom)ptr)(_command_buffer, _p_tile_memory_bind_info);
}

inline ktl::api::result get_framebuffer_tile_properties_qcom(ktl::api::device _device, ktl::api::framebuffer _framebuffer, ktl::u32 * _p_properties_count, ktl::api::tile_properties_qcom * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_framebuffer_tile_properties_qcom)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_framebuffer_tile_properties_qcom)ptr)(_device, _framebuffer, _p_properties_count, _p_properties);
}

inline ktl::api::result get_dynamic_rendering_tile_properties_qcom(ktl::api::device _device, const ktl::api::rendering_info * _p_rendering_info, ktl::api::tile_properties_qcom * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_dynamic_rendering_tile_properties_qcom)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_dynamic_rendering_tile_properties_qcom)ptr)(_device, _p_rendering_info, _p_properties);
}

inline ktl::api::result get_physical_device_optical_flow_image_formats_nv(ktl::api::physical_device _physical_device, const ktl::api::optical_flow_image_format_info_nv * _p_optical_flow_image_format_info, ktl::u32 * _p_format_count, ktl::api::optical_flow_image_format_properties_nv * _p_image_format_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_optical_flow_image_formats_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_optical_flow_image_formats_nv)ptr)(_physical_device, _p_optical_flow_image_format_info, _p_format_count, _p_image_format_properties);
}

inline ktl::api::result create_optical_flow_session_nv(ktl::api::device _device, const ktl::api::optical_flow_session_create_info_nv * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::optical_flow_session_nv * _p_session)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_optical_flow_session_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_optical_flow_session_nv)ptr)(_device, _p_create_info, _p_allocator, _p_session);
}

inline void destroy_optical_flow_session_nv(ktl::api::device _device, ktl::api::optical_flow_session_nv _session, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_optical_flow_session_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_optical_flow_session_nv)ptr)(_device, _session, _p_allocator);
}

inline ktl::api::result bind_optical_flow_session_image_nv(ktl::api::device _device, ktl::api::optical_flow_session_nv _session, ktl::api::optical_flow_session_binding_point_nv _binding_point, ktl::api::image_view _view, ktl::api::image_layout _layout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::bind_optical_flow_session_image_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_bind_optical_flow_session_image_nv)ptr)(_device, _session, _binding_point, _view, _layout);
}

inline void cmd_optical_flow_execute_nv(ktl::api::command_buffer _command_buffer, ktl::api::optical_flow_session_nv _session, const ktl::api::optical_flow_execute_info_nv * _p_execute_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_optical_flow_execute_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_optical_flow_execute_nv)ptr)(_command_buffer, _session, _p_execute_info);
}

inline ktl::api::result get_device_fault_info_ext(ktl::api::device _device, ktl::api::device_fault_counts_ext * _p_fault_counts, ktl::api::device_fault_info_ext * _p_fault_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_fault_info_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_fault_info_ext)ptr)(_device, _p_fault_counts, _p_fault_info);
}

inline ktl::api::result get_device_fault_reports_khr(ktl::api::device _device, ktl::u64 _timeout, ktl::u32 * _p_fault_counts, ktl::api::device_fault_info_khr * _p_fault_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_fault_reports_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_fault_reports_khr)ptr)(_device, _timeout, _p_fault_counts, _p_fault_info);
}

inline ktl::api::result get_device_fault_debug_info_khr(ktl::api::device _device, ktl::api::device_fault_debug_info_khr * _p_debug_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_fault_debug_info_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_fault_debug_info_khr)ptr)(_device, _p_debug_info);
}

inline void cmd_set_depth_bias_2ext(ktl::api::command_buffer _command_buffer, const ktl::api::depth_bias_info_ext * _p_depth_bias_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_bias_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_bias_2ext)ptr)(_command_buffer, _p_depth_bias_info);
}

inline ktl::api::result release_swapchain_images_khr(ktl::api::device _device, const ktl::api::release_swapchain_images_info_khr * _p_release_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::release_swapchain_images_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_release_swapchain_images_khr)ptr)(_device, _p_release_info);
}

inline void get_device_image_subresource_layout(ktl::api::device _device, const ktl::api::device_image_subresource_info * _p_info, ktl::api::subresource_layout_2 * _p_layout)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_image_subresource_layout)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_image_subresource_layout)ptr)(_device, _p_info, _p_layout);
}

inline ktl::api::result map_memory_2(ktl::api::device _device, const ktl::api::memory_map_info * _p_memory_map_info, void * _pp_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::map_memory_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_map_memory_2)ptr)(_device, _p_memory_map_info, _pp_data);
}

inline ktl::api::result unmap_memory_2(ktl::api::device _device, const ktl::api::memory_unmap_info * _p_memory_unmap_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::unmap_memory_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_unmap_memory_2)ptr)(_device, _p_memory_unmap_info);
}

inline ktl::api::result create_shaders_ext(ktl::api::device _device, ktl::u32 _create_info_count, const ktl::api::shader_create_info_ext * _p_create_infos, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::shader_ext * _p_shaders)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_shaders_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_shaders_ext)ptr)(_device, _create_info_count, _p_create_infos, _p_allocator, _p_shaders);
}

inline void destroy_shader_ext(ktl::api::device _device, ktl::api::shader_ext _shader, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_shader_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_shader_ext)ptr)(_device, _shader, _p_allocator);
}

inline ktl::api::result get_shader_binary_data_ext(ktl::api::device _device, ktl::api::shader_ext _shader, ktl::usize * _p_data_size, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_shader_binary_data_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_shader_binary_data_ext)ptr)(_device, _shader, _p_data_size, _p_data);
}

inline void cmd_bind_shaders_ext(ktl::api::command_buffer _command_buffer, ktl::u32 _stage_count, const ktl::api::shader_stage_flag_bits * _p_stages, const ktl::api::shader_ext * _p_shaders)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_shaders_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_shaders_ext)ptr)(_command_buffer, _stage_count, _p_stages, _p_shaders);
}

inline ktl::api::result set_swapchain_present_timing_queue_size_ext(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, ktl::u32 _size)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_swapchain_present_timing_queue_size_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_swapchain_present_timing_queue_size_ext)ptr)(_device, _swapchain, _size);
}

inline ktl::api::result get_swapchain_timing_properties_ext(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, ktl::api::swapchain_timing_properties_ext * _p_swapchain_timing_properties, ktl::u64 * _p_swapchain_timing_properties_counter)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_swapchain_timing_properties_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_swapchain_timing_properties_ext)ptr)(_device, _swapchain, _p_swapchain_timing_properties, _p_swapchain_timing_properties_counter);
}

inline ktl::api::result get_swapchain_time_domain_properties_ext(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, ktl::api::swapchain_time_domain_properties_ext * _p_swapchain_time_domain_properties, ktl::u64 * _p_time_domains_counter)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_swapchain_time_domain_properties_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_swapchain_time_domain_properties_ext)ptr)(_device, _swapchain, _p_swapchain_time_domain_properties, _p_time_domains_counter);
}

inline ktl::api::result get_past_presentation_timing_ext(ktl::api::device _device, const ktl::api::past_presentation_timing_info_ext * _p_past_presentation_timing_info, ktl::api::past_presentation_timing_properties_ext * _p_past_presentation_timing_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_past_presentation_timing_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_past_presentation_timing_ext)ptr)(_device, _p_past_presentation_timing_info, _p_past_presentation_timing_properties);
}

inline ktl::api::result get_screen_buffer_properties_qnx(ktl::api::device _device, const _screen_buffer * _buffer, ktl::api::screen_buffer_properties_qnx * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_screen_buffer_properties_qnx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_screen_buffer_properties_qnx)ptr)(_device, _buffer, _p_properties);
}

inline ktl::api::result get_physical_device_cooperative_matrix_properties_khr(ktl::api::physical_device _physical_device, ktl::u32 * _p_property_count, ktl::api::cooperative_matrix_properties_khr * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_cooperative_matrix_properties_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_cooperative_matrix_properties_khr)ptr)(_physical_device, _p_property_count, _p_properties);
}

inline ktl::api::result get_execution_graph_pipeline_scratch_size_amdx(ktl::api::device _device, ktl::api::pipeline _execution_graph, ktl::api::execution_graph_pipeline_scratch_size_amdx * _p_size_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_execution_graph_pipeline_scratch_size_amdx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_execution_graph_pipeline_scratch_size_amdx)ptr)(_device, _execution_graph, _p_size_info);
}

inline ktl::api::result get_execution_graph_pipeline_node_index_amdx(ktl::api::device _device, ktl::api::pipeline _execution_graph, const ktl::api::pipeline_shader_stage_node_create_info_amdx * _p_node_info, ktl::u32 * _p_node_index)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_execution_graph_pipeline_node_index_amdx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_execution_graph_pipeline_node_index_amdx)ptr)(_device, _execution_graph, _p_node_info, _p_node_index);
}

inline ktl::api::result create_execution_graph_pipelines_amdx(ktl::api::device _device, ktl::api::pipeline_cache _pipeline_cache, ktl::u32 _create_info_count, const ktl::api::execution_graph_pipeline_create_info_amdx * _p_create_infos, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::pipeline * _p_pipelines)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_execution_graph_pipelines_amdx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_execution_graph_pipelines_amdx)ptr)(_device, _pipeline_cache, _create_info_count, _p_create_infos, _p_allocator, _p_pipelines);
}

inline void cmd_initialize_graph_scratch_memory_amdx(ktl::api::command_buffer _command_buffer, ktl::api::pipeline _execution_graph, ktl::api::dvaddr _scratch, ktl::api::dvsize _scratch_size)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_initialize_graph_scratch_memory_amdx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_initialize_graph_scratch_memory_amdx)ptr)(_command_buffer, _execution_graph, _scratch, _scratch_size);
}

inline void cmd_dispatch_graph_amdx(ktl::api::command_buffer _command_buffer, ktl::api::dvaddr _scratch, ktl::api::dvsize _scratch_size, const ktl::api::dispatch_graph_count_info_amdx * _p_count_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_dispatch_graph_amdx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_dispatch_graph_amdx)ptr)(_command_buffer, _scratch, _scratch_size, _p_count_info);
}

inline void cmd_dispatch_graph_indirect_amdx(ktl::api::command_buffer _command_buffer, ktl::api::dvaddr _scratch, ktl::api::dvsize _scratch_size, const ktl::api::dispatch_graph_count_info_amdx * _p_count_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_dispatch_graph_indirect_amdx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_dispatch_graph_indirect_amdx)ptr)(_command_buffer, _scratch, _scratch_size, _p_count_info);
}

inline void cmd_dispatch_graph_indirect_count_amdx(ktl::api::command_buffer _command_buffer, ktl::api::dvaddr _scratch, ktl::api::dvsize _scratch_size, ktl::api::dvaddr _count_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_dispatch_graph_indirect_count_amdx)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_dispatch_graph_indirect_count_amdx)ptr)(_command_buffer, _scratch, _scratch_size, _count_info);
}

inline ktl::api::result create_gpa_session_amd(ktl::api::device _device, const ktl::api::gpa_session_create_info_amd * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::gpa_session_amd * _p_gpa_session)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_gpa_session_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_gpa_session_amd)ptr)(_device, _p_create_info, _p_allocator, _p_gpa_session);
}

inline void destroy_gpa_session_amd(ktl::api::device _device, ktl::api::gpa_session_amd _gpa_session, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_gpa_session_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_gpa_session_amd)ptr)(_device, _gpa_session, _p_allocator);
}

inline ktl::api::result set_gpa_device_clock_mode_amd(ktl::api::device _device, ktl::api::gpa_device_clock_mode_info_amd * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_gpa_device_clock_mode_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_gpa_device_clock_mode_amd)ptr)(_device, _p_info);
}

inline ktl::api::result get_gpa_device_clock_info_amd(ktl::api::device _device, ktl::api::gpa_device_get_clock_info_amd * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_gpa_device_clock_info_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_gpa_device_clock_info_amd)ptr)(_device, _p_info);
}

inline ktl::api::result cmd_begin_gpa_session_amd(ktl::api::command_buffer _command_buffer, ktl::api::gpa_session_amd _gpa_session)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_gpa_session_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_gpa_session_amd)ptr)(_command_buffer, _gpa_session);
}

inline ktl::api::result cmd_end_gpa_session_amd(ktl::api::command_buffer _command_buffer, ktl::api::gpa_session_amd _gpa_session)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_gpa_session_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_gpa_session_amd)ptr)(_command_buffer, _gpa_session);
}

inline ktl::api::result cmd_begin_gpa_sample_amd(ktl::api::command_buffer _command_buffer, ktl::api::gpa_session_amd _gpa_session, const ktl::api::gpa_sample_begin_info_amd * _p_gpa_sample_begin_info, ktl::u32 * _p_sample_id)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_gpa_sample_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_gpa_sample_amd)ptr)(_command_buffer, _gpa_session, _p_gpa_sample_begin_info, _p_sample_id);
}

inline void cmd_end_gpa_sample_amd(ktl::api::command_buffer _command_buffer, ktl::api::gpa_session_amd _gpa_session, ktl::u32 _sample_id)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_gpa_sample_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_gpa_sample_amd)ptr)(_command_buffer, _gpa_session, _sample_id);
}

inline ktl::api::result get_gpa_session_status_amd(ktl::api::device _device, ktl::api::gpa_session_amd _gpa_session)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_gpa_session_status_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_gpa_session_status_amd)ptr)(_device, _gpa_session);
}

inline ktl::api::result get_gpa_session_results_amd(ktl::api::device _device, ktl::api::gpa_session_amd _gpa_session, ktl::u32 _sample_id, ktl::usize * _p_size_in_bytes, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_gpa_session_results_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_gpa_session_results_amd)ptr)(_device, _gpa_session, _sample_id, _p_size_in_bytes, _p_data);
}

inline ktl::api::result reset_gpa_session_amd(ktl::api::device _device, ktl::api::gpa_session_amd _gpa_session)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::reset_gpa_session_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_reset_gpa_session_amd)ptr)(_device, _gpa_session);
}

inline void cmd_copy_gpa_session_results_amd(ktl::api::command_buffer _command_buffer, ktl::api::gpa_session_amd _gpa_session)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_gpa_session_results_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_gpa_session_results_amd)ptr)(_command_buffer, _gpa_session);
}

inline void cmd_bind_descriptor_sets_2(ktl::api::command_buffer _command_buffer, const ktl::api::bind_descriptor_sets_info * _p_bind_descriptor_sets_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_descriptor_sets_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_descriptor_sets_2)ptr)(_command_buffer, _p_bind_descriptor_sets_info);
}

inline void cmd_push_constants_2(ktl::api::command_buffer _command_buffer, const ktl::api::push_constants_info * _p_push_constants_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_push_constants_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_push_constants_2)ptr)(_command_buffer, _p_push_constants_info);
}

inline void cmd_push_descriptor_set_2(ktl::api::command_buffer _command_buffer, const ktl::api::push_descriptor_set_info * _p_push_descriptor_set_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_push_descriptor_set_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_push_descriptor_set_2)ptr)(_command_buffer, _p_push_descriptor_set_info);
}

inline void cmd_push_descriptor_set_with_template_2(ktl::api::command_buffer _command_buffer, const ktl::api::push_descriptor_set_with_template_info * _p_push_descriptor_set_with_template_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_push_descriptor_set_with_template_2)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_push_descriptor_set_with_template_2)ptr)(_command_buffer, _p_push_descriptor_set_with_template_info);
}

inline void cmd_set_descriptor_buffer_offsets_2ext(ktl::api::command_buffer _command_buffer, const ktl::api::set_descriptor_buffer_offsets_info_ext * _p_set_descriptor_buffer_offsets_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_descriptor_buffer_offsets_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_descriptor_buffer_offsets_2ext)ptr)(_command_buffer, _p_set_descriptor_buffer_offsets_info);
}

inline void cmd_bind_descriptor_buffer_embedded_samplers_2ext(ktl::api::command_buffer _command_buffer, const ktl::api::bind_descriptor_buffer_embedded_samplers_info_ext * _p_bind_descriptor_buffer_embedded_samplers_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_descriptor_buffer_embedded_samplers_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_descriptor_buffer_embedded_samplers_2ext)ptr)(_command_buffer, _p_bind_descriptor_buffer_embedded_samplers_info);
}

inline ktl::api::result set_latency_sleep_mode_nv(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, const ktl::api::latency_sleep_mode_info_nv * _p_sleep_mode_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_latency_sleep_mode_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_latency_sleep_mode_nv)ptr)(_device, _swapchain, _p_sleep_mode_info);
}

inline ktl::api::result latency_sleep_nv(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, const ktl::api::latency_sleep_info_nv * _p_sleep_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::latency_sleep_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_latency_sleep_nv)ptr)(_device, _swapchain, _p_sleep_info);
}

inline void set_latency_marker_nv(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, const ktl::api::set_latency_marker_info_nv * _p_latency_marker_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::set_latency_marker_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_set_latency_marker_nv)ptr)(_device, _swapchain, _p_latency_marker_info);
}

inline void get_latency_timings_nv(ktl::api::device _device, ktl::api::swapchain_khr _swapchain, ktl::api::get_latency_marker_info_nv * _p_latency_marker_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_latency_timings_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_latency_timings_nv)ptr)(_device, _swapchain, _p_latency_marker_info);
}

inline void queue_notify_out_of_band_nv(ktl::api::queue _queue, const ktl::api::out_of_band_queue_type_info_nv * _p_queue_type_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_notify_out_of_band_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_notify_out_of_band_nv)ptr)(_queue, _p_queue_type_info);
}

inline void cmd_set_rendering_attachment_locations(ktl::api::command_buffer _command_buffer, const ktl::api::rendering_attachment_location_info * _p_location_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_rendering_attachment_locations)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_rendering_attachment_locations)ptr)(_command_buffer, _p_location_info);
}

inline void cmd_set_rendering_input_attachment_indices(ktl::api::command_buffer _command_buffer, const ktl::api::rendering_input_attachment_index_info * _p_input_attachment_index_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_rendering_input_attachment_indices)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_rendering_input_attachment_indices)ptr)(_command_buffer, _p_input_attachment_index_info);
}

inline void cmd_set_depth_clamp_range_ext(ktl::api::command_buffer _command_buffer, ktl::api::depth_clamp_mode_ext _depth_clamp_mode, const ktl::api::depth_clamp_range_ext * _p_depth_clamp_range)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_depth_clamp_range_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_depth_clamp_range_ext)ptr)(_command_buffer, _depth_clamp_mode, _p_depth_clamp_range);
}

inline ktl::api::result get_physical_device_cooperative_matrix_flexible_dimensions_properties_nv(ktl::api::physical_device _physical_device, ktl::u32 * _p_property_count, ktl::api::cooperative_matrix_flexible_dimensions_properties_nv * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_cooperative_matrix_flexible_dimensions_properties_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_cooperative_matrix_flexible_dimensions_properties_nv)ptr)(_physical_device, _p_property_count, _p_properties);
}

inline ktl::api::result get_memory_metal_handle_ext(ktl::api::device _device, const ktl::api::memory_get_metal_handle_info_ext * _p_get_metal_handle_info, void * _p_handle)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_metal_handle_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_metal_handle_ext)ptr)(_device, _p_get_metal_handle_info, _p_handle);
}

inline ktl::api::result get_memory_metal_handle_properties_ext(ktl::api::device _device, ktl::api::external_memory_handle_type_flag_bits _handle_type, const void * _p_handle, ktl::api::memory_metal_handle_properties_ext * _p_memory_metal_handle_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_metal_handle_properties_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_metal_handle_properties_ext)ptr)(_device, _handle_type, _p_handle, _p_memory_metal_handle_properties);
}

inline ktl::api::result get_physical_device_cooperative_vector_properties_nv(ktl::api::physical_device _physical_device, ktl::u32 * _p_property_count, ktl::api::cooperative_vector_properties_nv * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_cooperative_vector_properties_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_cooperative_vector_properties_nv)ptr)(_physical_device, _p_property_count, _p_properties);
}

inline ktl::api::result convert_cooperative_vector_matrix_nv(ktl::api::device _device, const ktl::api::convert_cooperative_vector_matrix_info_nv * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::convert_cooperative_vector_matrix_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_convert_cooperative_vector_matrix_nv)ptr)(_device, _p_info);
}

inline void cmd_convert_cooperative_vector_matrix_nv(ktl::api::command_buffer _command_buffer, ktl::u32 _info_count, const ktl::api::convert_cooperative_vector_matrix_info_nv * _p_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_convert_cooperative_vector_matrix_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_convert_cooperative_vector_matrix_nv)ptr)(_command_buffer, _info_count, _p_infos);
}

inline void cmd_dispatch_tile_qcom(ktl::api::command_buffer _command_buffer, const ktl::api::dispatch_tile_info_qcom * _p_dispatch_tile_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_dispatch_tile_qcom)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_dispatch_tile_qcom)ptr)(_command_buffer, _p_dispatch_tile_info);
}

inline void cmd_begin_per_tile_execution_qcom(ktl::api::command_buffer _command_buffer, const ktl::api::per_tile_begin_info_qcom * _p_per_tile_begin_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_per_tile_execution_qcom)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_per_tile_execution_qcom)ptr)(_command_buffer, _p_per_tile_begin_info);
}

inline void cmd_end_per_tile_execution_qcom(ktl::api::command_buffer _command_buffer, const ktl::api::per_tile_end_info_qcom * _p_per_tile_end_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_per_tile_execution_qcom)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_per_tile_execution_qcom)ptr)(_command_buffer, _p_per_tile_end_info);
}

inline ktl::api::result create_external_compute_queue_nv(ktl::api::device _device, const ktl::api::external_compute_queue_create_info_nv * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::external_compute_queue_nv * _p_external_queue)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_external_compute_queue_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_external_compute_queue_nv)ptr)(_device, _p_create_info, _p_allocator, _p_external_queue);
}

inline void destroy_external_compute_queue_nv(ktl::api::device _device, ktl::api::external_compute_queue_nv _external_queue, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_external_compute_queue_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_external_compute_queue_nv)ptr)(_device, _external_queue, _p_allocator);
}

inline void get_external_compute_queue_data_nv(ktl::api::external_compute_queue_nv _external_queue, ktl::api::external_compute_queue_data_params_nv * _params, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_external_compute_queue_data_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_external_compute_queue_data_nv)ptr)(_external_queue, _params, _p_data);
}

inline ktl::api::result enumerate_physical_device_shader_instrumentation_metrics_arm(ktl::api::physical_device _physical_device, ktl::u32 * _p_description_count, ktl::api::shader_instrumentation_metric_description_arm * _p_descriptions)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::enumerate_physical_device_shader_instrumentation_metrics_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_enumerate_physical_device_shader_instrumentation_metrics_arm)ptr)(_physical_device, _p_description_count, _p_descriptions);
}

inline ktl::api::result create_shader_instrumentation_arm(ktl::api::device _device, const ktl::api::shader_instrumentation_create_info_arm * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::shader_instrumentation_arm * _p_instrumentation)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_shader_instrumentation_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_shader_instrumentation_arm)ptr)(_device, _p_create_info, _p_allocator, _p_instrumentation);
}

inline void destroy_shader_instrumentation_arm(ktl::api::device _device, ktl::api::shader_instrumentation_arm _instrumentation, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_shader_instrumentation_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_shader_instrumentation_arm)ptr)(_device, _instrumentation, _p_allocator);
}

inline void cmd_begin_shader_instrumentation_arm(ktl::api::command_buffer _command_buffer, ktl::api::shader_instrumentation_arm _instrumentation)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_shader_instrumentation_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_shader_instrumentation_arm)ptr)(_command_buffer, _instrumentation);
}

inline void cmd_end_shader_instrumentation_arm(ktl::api::command_buffer _command_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_shader_instrumentation_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_shader_instrumentation_arm)ptr)(_command_buffer);
}

inline ktl::api::result get_shader_instrumentation_values_arm(ktl::api::device _device, ktl::api::shader_instrumentation_arm _instrumentation, ktl::u32 * _p_metric_block_count, void * _p_metric_values, ktl::api::shader_instrumentation_values_flags_arm _flags)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_shader_instrumentation_values_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_shader_instrumentation_values_arm)ptr)(_device, _instrumentation, _p_metric_block_count, _p_metric_values, _flags);
}

inline void clear_shader_instrumentation_metrics_arm(ktl::api::device _device, ktl::api::shader_instrumentation_arm _instrumentation)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::clear_shader_instrumentation_metrics_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_clear_shader_instrumentation_metrics_arm)ptr)(_device, _instrumentation);
}

inline ktl::api::result create_tensor_arm(ktl::api::device _device, const ktl::api::tensor_create_info_arm * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::tensor_arm * _p_tensor)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_tensor_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_tensor_arm)ptr)(_device, _p_create_info, _p_allocator, _p_tensor);
}

inline void destroy_tensor_arm(ktl::api::device _device, ktl::api::tensor_arm _tensor, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_tensor_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_tensor_arm)ptr)(_device, _tensor, _p_allocator);
}

inline ktl::api::result create_tensor_view_arm(ktl::api::device _device, const ktl::api::tensor_view_create_info_arm * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::tensor_view_arm * _p_view)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_tensor_view_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_tensor_view_arm)ptr)(_device, _p_create_info, _p_allocator, _p_view);
}

inline void destroy_tensor_view_arm(ktl::api::device _device, ktl::api::tensor_view_arm _tensor_view, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_tensor_view_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_tensor_view_arm)ptr)(_device, _tensor_view, _p_allocator);
}

inline void get_tensor_memory_requirements_arm(ktl::api::device _device, const ktl::api::tensor_memory_requirements_info_arm * _p_info, ktl::api::memory_requirements_2 * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_tensor_memory_requirements_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_tensor_memory_requirements_arm)ptr)(_device, _p_info, _p_memory_requirements);
}

inline ktl::api::result bind_tensor_memory_arm(ktl::api::device _device, ktl::u32 _bind_info_count, const ktl::api::bind_tensor_memory_info_arm * _p_bind_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::bind_tensor_memory_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_bind_tensor_memory_arm)ptr)(_device, _bind_info_count, _p_bind_infos);
}

inline void get_device_tensor_memory_requirements_arm(ktl::api::device _device, const ktl::api::device_tensor_memory_requirements_arm * _p_info, ktl::api::memory_requirements_2 * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_device_tensor_memory_requirements_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_device_tensor_memory_requirements_arm)ptr)(_device, _p_info, _p_memory_requirements);
}

inline void cmd_copy_tensor_arm(ktl::api::command_buffer _command_buffer, const ktl::api::copy_tensor_info_arm * _p_copy_tensor_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_tensor_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_tensor_arm)ptr)(_command_buffer, _p_copy_tensor_info);
}

inline ktl::api::result get_tensor_opaque_capture_descriptor_data_arm(ktl::api::device _device, const ktl::api::tensor_capture_descriptor_data_info_arm * _p_info, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_tensor_opaque_capture_descriptor_data_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_tensor_opaque_capture_descriptor_data_arm)ptr)(_device, _p_info, _p_data);
}

inline ktl::api::result get_tensor_view_opaque_capture_descriptor_data_arm(ktl::api::device _device, const ktl::api::tensor_view_capture_descriptor_data_info_arm * _p_info, void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_tensor_view_opaque_capture_descriptor_data_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_tensor_view_opaque_capture_descriptor_data_arm)ptr)(_device, _p_info, _p_data);
}

inline void get_physical_device_external_tensor_properties_arm(ktl::api::physical_device _physical_device, const ktl::api::physical_device_external_tensor_info_arm * _p_external_tensor_info, ktl::api::external_tensor_properties_arm * _p_external_tensor_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_external_tensor_properties_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_external_tensor_properties_arm)ptr)(_physical_device, _p_external_tensor_info, _p_external_tensor_properties);
}

inline ktl::api::result create_data_graph_pipelines_arm(ktl::api::device _device, ktl::api::deferred_operation_khr _deferred_operation, ktl::api::pipeline_cache _pipeline_cache, ktl::u32 _create_info_count, const ktl::api::data_graph_pipeline_create_info_arm * _p_create_infos, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::pipeline * _p_pipelines)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_data_graph_pipelines_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_data_graph_pipelines_arm)ptr)(_device, _deferred_operation, _pipeline_cache, _create_info_count, _p_create_infos, _p_allocator, _p_pipelines);
}

inline ktl::api::result create_data_graph_pipeline_session_arm(ktl::api::device _device, const ktl::api::data_graph_pipeline_session_create_info_arm * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::data_graph_pipeline_session_arm * _p_session)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_data_graph_pipeline_session_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_data_graph_pipeline_session_arm)ptr)(_device, _p_create_info, _p_allocator, _p_session);
}

inline ktl::api::result get_data_graph_pipeline_session_bind_point_requirements_arm(ktl::api::device _device, const ktl::api::data_graph_pipeline_session_bind_point_requirements_info_arm * _p_info, ktl::u32 * _p_bind_point_requirement_count, ktl::api::data_graph_pipeline_session_bind_point_requirement_arm * _p_bind_point_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_data_graph_pipeline_session_bind_point_requirements_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_data_graph_pipeline_session_bind_point_requirements_arm)ptr)(_device, _p_info, _p_bind_point_requirement_count, _p_bind_point_requirements);
}

inline void get_data_graph_pipeline_session_memory_requirements_arm(ktl::api::device _device, const ktl::api::data_graph_pipeline_session_memory_requirements_info_arm * _p_info, ktl::api::memory_requirements_2 * _p_memory_requirements)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_data_graph_pipeline_session_memory_requirements_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_data_graph_pipeline_session_memory_requirements_arm)ptr)(_device, _p_info, _p_memory_requirements);
}

inline ktl::api::result bind_data_graph_pipeline_session_memory_arm(ktl::api::device _device, ktl::u32 _bind_info_count, const ktl::api::bind_data_graph_pipeline_session_memory_info_arm * _p_bind_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::bind_data_graph_pipeline_session_memory_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_bind_data_graph_pipeline_session_memory_arm)ptr)(_device, _bind_info_count, _p_bind_infos);
}

inline void destroy_data_graph_pipeline_session_arm(ktl::api::device _device, ktl::api::data_graph_pipeline_session_arm _session, const ktl::api::allocation_callbacks * _p_allocator)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::destroy_data_graph_pipeline_session_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_destroy_data_graph_pipeline_session_arm)ptr)(_device, _session, _p_allocator);
}

inline void cmd_dispatch_data_graph_arm(ktl::api::command_buffer _command_buffer, ktl::api::data_graph_pipeline_session_arm _session, const ktl::api::data_graph_pipeline_dispatch_info_arm * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_dispatch_data_graph_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_dispatch_data_graph_arm)ptr)(_command_buffer, _session, _p_info);
}

inline ktl::api::result get_data_graph_pipeline_available_properties_arm(ktl::api::device _device, const ktl::api::data_graph_pipeline_info_arm * _p_pipeline_info, ktl::u32 * _p_properties_count, ktl::api::data_graph_pipeline_property_arm * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_data_graph_pipeline_available_properties_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_data_graph_pipeline_available_properties_arm)ptr)(_device, _p_pipeline_info, _p_properties_count, _p_properties);
}

inline ktl::api::result get_data_graph_pipeline_properties_arm(ktl::api::device _device, const ktl::api::data_graph_pipeline_info_arm * _p_pipeline_info, ktl::u32 _properties_count, ktl::api::data_graph_pipeline_property_query_result_arm * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_data_graph_pipeline_properties_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_data_graph_pipeline_properties_arm)ptr)(_device, _p_pipeline_info, _properties_count, _p_properties);
}

inline ktl::api::result get_physical_device_queue_family_data_graph_properties_arm(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, ktl::u32 * _p_queue_family_data_graph_property_count, ktl::api::queue_family_data_graph_properties_arm * _p_queue_family_data_graph_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_queue_family_data_graph_properties_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_queue_family_data_graph_properties_arm)ptr)(_physical_device, _queue_family_index, _p_queue_family_data_graph_property_count, _p_queue_family_data_graph_properties);
}

inline void get_physical_device_queue_family_data_graph_processing_engine_properties_arm(ktl::api::physical_device _physical_device, const ktl::api::physical_device_queue_family_data_graph_processing_engine_info_arm * _p_queue_family_data_graph_processing_engine_info, ktl::api::queue_family_data_graph_processing_engine_properties_arm * _p_queue_family_data_graph_processing_engine_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_queue_family_data_graph_processing_engine_properties_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_queue_family_data_graph_processing_engine_properties_arm)ptr)(_physical_device, _p_queue_family_data_graph_processing_engine_info, _p_queue_family_data_graph_processing_engine_properties);
}

inline ktl::api::result get_native_buffer_properties_ohos(ktl::api::device _device, const OH_NativeBuffer * _buffer, ktl::api::native_buffer_properties_ohos * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_native_buffer_properties_ohos)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_native_buffer_properties_ohos)ptr)(_device, _buffer, _p_properties);
}

inline ktl::api::result get_memory_native_buffer_ohos(ktl::api::device _device, const ktl::api::memory_get_native_buffer_info_ohos * _p_info, OH_NativeBuffer * _p_buffer)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_memory_native_buffer_ohos)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_memory_native_buffer_ohos)ptr)(_device, _p_info, _p_buffer);
}

inline ktl::api::result get_swapchain_gralloc_usage_ohos(ktl::api::device _device, ktl::api::format _format, ktl::api::image_usage_flags _image_usage, ktl::u64 * _gralloc_usage)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_swapchain_gralloc_usage_ohos)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_swapchain_gralloc_usage_ohos)ptr)(_device, _format, _image_usage, _gralloc_usage);
}

inline ktl::api::result acquire_image_ohos(ktl::api::device _device, ktl::api::image _image, ktl::i32 _native_fence_fd, ktl::api::semaphore _semaphore, ktl::api::fence _fence)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::acquire_image_ohos)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_acquire_image_ohos)ptr)(_device, _image, _native_fence_fd, _semaphore, _fence);
}

inline ktl::api::result queue_signal_release_image_ohos(ktl::api::queue _queue, ktl::u32 _wait_semaphore_count, const ktl::api::semaphore * _p_wait_semaphores, ktl::api::image _image, ktl::i32 * _p_native_fence_fd)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_signal_release_image_ohos)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_signal_release_image_ohos)ptr)(_queue, _wait_semaphore_count, _p_wait_semaphores, _image, _p_native_fence_fd);
}

inline ktl::api::result queue_set_perf_hint_qcom(ktl::api::queue _queue, const ktl::api::perf_hint_info_qcom * _p_perf_hint_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::queue_set_perf_hint_qcom)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_queue_set_perf_hint_qcom)ptr)(_queue, _p_perf_hint_info);
}

inline ktl::api::result enumerate_physical_device_queue_family_performance_counters_by_region_arm(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, ktl::u32 * _p_counter_count, ktl::api::performance_counter_arm * _p_counters, ktl::api::performance_counter_description_arm * _p_counter_descriptions)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::enumerate_physical_device_queue_family_performance_counters_by_region_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_enumerate_physical_device_queue_family_performance_counters_by_region_arm)ptr)(_physical_device, _queue_family_index, _p_counter_count, _p_counters, _p_counter_descriptions);
}

inline void cmd_set_compute_occupancy_priority_nv(ktl::api::command_buffer _command_buffer, const ktl::api::compute_occupancy_priority_parameters_nv * _p_parameters)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_compute_occupancy_priority_nv)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_compute_occupancy_priority_nv)ptr)(_command_buffer, _p_parameters);
}

inline ktl::api::result write_sampler_descriptors_ext(ktl::api::device _device, ktl::u32 _sampler_count, const ktl::api::sampler_create_info * _p_samplers, const ktl::api::host_address_range_ext * _p_descriptors)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::write_sampler_descriptors_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_write_sampler_descriptors_ext)ptr)(_device, _sampler_count, _p_samplers, _p_descriptors);
}

inline ktl::api::result write_resource_descriptors_ext(ktl::api::device _device, ktl::u32 _resource_count, const ktl::api::resource_descriptor_info_ext * _p_resources, const ktl::api::host_address_range_ext * _p_descriptors)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::write_resource_descriptors_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_write_resource_descriptors_ext)ptr)(_device, _resource_count, _p_resources, _p_descriptors);
}

inline void cmd_bind_sampler_heap_ext(ktl::api::command_buffer _command_buffer, const ktl::api::bind_heap_info_ext * _p_bind_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_sampler_heap_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_sampler_heap_ext)ptr)(_command_buffer, _p_bind_info);
}

inline void cmd_bind_resource_heap_ext(ktl::api::command_buffer _command_buffer, const ktl::api::bind_heap_info_ext * _p_bind_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_resource_heap_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_resource_heap_ext)ptr)(_command_buffer, _p_bind_info);
}

inline void cmd_push_data_ext(ktl::api::command_buffer _command_buffer, const ktl::api::push_data_info_ext * _p_push_data_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_push_data_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_push_data_ext)ptr)(_command_buffer, _p_push_data_info);
}

inline ktl::api::result register_custom_border_color_ext(ktl::api::device _device, const ktl::api::sampler_custom_border_color_create_info_ext * _p_border_color, ktl::api::bool32 _request_index, ktl::u32 * _p_index)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::register_custom_border_color_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_register_custom_border_color_ext)ptr)(_device, _p_border_color, _request_index, _p_index);
}

inline void unregister_custom_border_color_ext(ktl::api::device _device, ktl::u32 _index)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::unregister_custom_border_color_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_unregister_custom_border_color_ext)ptr)(_device, _index);
}

inline ktl::api::result get_image_opaque_capture_data_ext(ktl::api::device _device, ktl::u32 _image_count, const ktl::api::image * _p_images, ktl::api::host_address_range_ext * _p_datas)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_image_opaque_capture_data_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_image_opaque_capture_data_ext)ptr)(_device, _image_count, _p_images, _p_datas);
}

inline ktl::api::dvsize get_physical_device_descriptor_size_ext(ktl::api::physical_device _physical_device, ktl::api::descriptor_type _descriptor_type)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_descriptor_size_ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_descriptor_size_ext)ptr)(_physical_device, _descriptor_type);
}

inline ktl::api::result get_tensor_opaque_capture_data_arm(ktl::api::device _device, ktl::u32 _tensor_count, const ktl::api::tensor_arm * _p_tensors, ktl::api::host_address_range_ext * _p_datas)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_tensor_opaque_capture_data_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_tensor_opaque_capture_data_arm)ptr)(_device, _tensor_count, _p_tensors, _p_datas);
}

inline void cmd_copy_memory_khr(ktl::api::command_buffer _command_buffer, const ktl::api::copy_device_memory_info_khr * _p_copy_memory_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_memory_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_memory_khr)ptr)(_command_buffer, _p_copy_memory_info);
}

inline void cmd_copy_memory_to_image_khr(ktl::api::command_buffer _command_buffer, const ktl::api::copy_device_memory_image_info_khr * _p_copy_memory_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_memory_to_image_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_memory_to_image_khr)ptr)(_command_buffer, _p_copy_memory_info);
}

inline void cmd_copy_image_to_memory_khr(ktl::api::command_buffer _command_buffer, const ktl::api::copy_device_memory_image_info_khr * _p_copy_memory_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_image_to_memory_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_image_to_memory_khr)ptr)(_command_buffer, _p_copy_memory_info);
}

inline void cmd_update_memory_khr(ktl::api::command_buffer _command_buffer, const ktl::api::device_address_range_khr * _p_dst_range, ktl::api::address_command_flags_khr _dst_flags, ktl::api::dvsize _data_size, const void * _p_data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_update_memory_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_update_memory_khr)ptr)(_command_buffer, _p_dst_range, _dst_flags, _data_size, _p_data);
}

inline void cmd_fill_memory_khr(ktl::api::command_buffer _command_buffer, const ktl::api::device_address_range_khr * _p_dst_range, ktl::api::address_command_flags_khr _dst_flags, ktl::u32 _data)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_fill_memory_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_fill_memory_khr)ptr)(_command_buffer, _p_dst_range, _dst_flags, _data);
}

inline void cmd_copy_query_pool_results_to_memory_khr(ktl::api::command_buffer _command_buffer, ktl::api::query_pool _query_pool, ktl::u32 _first_query, ktl::u32 _query_count, const ktl::api::strided_device_address_range_khr * _p_dst_range, ktl::api::address_command_flags_khr _dst_flags, ktl::api::query_result_flags _query_result_flags)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_copy_query_pool_results_to_memory_khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_copy_query_pool_results_to_memory_khr)ptr)(_command_buffer, _query_pool, _first_query, _query_count, _p_dst_range, _dst_flags, _query_result_flags);
}

inline void cmd_begin_conditional_rendering_2ext(ktl::api::command_buffer _command_buffer, const ktl::api::conditional_rendering_begin_info_2ext * _p_conditional_rendering_begin)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_conditional_rendering_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_conditional_rendering_2ext)ptr)(_command_buffer, _p_conditional_rendering_begin);
}

inline void cmd_bind_transform_feedback_buffers_2ext(ktl::api::command_buffer _command_buffer, ktl::u32 _first_binding, ktl::u32 _binding_count, const ktl::api::bind_transform_feedback_buffer_2info_ext * _p_binding_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_transform_feedback_buffers_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_transform_feedback_buffers_2ext)ptr)(_command_buffer, _first_binding, _binding_count, _p_binding_infos);
}

inline void cmd_begin_transform_feedback_2ext(ktl::api::command_buffer _command_buffer, ktl::u32 _first_counter_range, ktl::u32 _counter_range_count, const ktl::api::bind_transform_feedback_buffer_2info_ext * _p_counter_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_begin_transform_feedback_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_begin_transform_feedback_2ext)ptr)(_command_buffer, _first_counter_range, _counter_range_count, _p_counter_infos);
}

inline void cmd_end_transform_feedback_2ext(ktl::api::command_buffer _command_buffer, ktl::u32 _first_counter_range, ktl::u32 _counter_range_count, const ktl::api::bind_transform_feedback_buffer_2info_ext * _p_counter_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_end_transform_feedback_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_end_transform_feedback_2ext)ptr)(_command_buffer, _first_counter_range, _counter_range_count, _p_counter_infos);
}

inline void cmd_draw_indirect_byte_count_2ext(ktl::api::command_buffer _command_buffer, ktl::u32 _instance_count, ktl::u32 _first_instance, const ktl::api::bind_transform_feedback_buffer_2info_ext * _p_counter_info, ktl::u32 _counter_offset, ktl::u32 _vertex_stride)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_indirect_byte_count_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_indirect_byte_count_2ext)ptr)(_command_buffer, _instance_count, _first_instance, _p_counter_info, _counter_offset, _vertex_stride);
}

inline void cmd_write_marker_to_memory_amd(ktl::api::command_buffer _command_buffer, const ktl::api::memory_marker_info_amd * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_write_marker_to_memory_amd)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_write_marker_to_memory_amd)ptr)(_command_buffer, _p_info);
}

inline void cmd_bind_index_buffer_3khr(ktl::api::command_buffer _command_buffer, const ktl::api::bind_index_buffer_3info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_index_buffer_3khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_index_buffer_3khr)ptr)(_command_buffer, _p_info);
}

inline void cmd_bind_vertex_buffers_3khr(ktl::api::command_buffer _command_buffer, ktl::u32 _first_binding, ktl::u32 _binding_count, const ktl::api::bind_vertex_buffer_3info_khr * _p_binding_infos)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_bind_vertex_buffers_3khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_bind_vertex_buffers_3khr)ptr)(_command_buffer, _first_binding, _binding_count, _p_binding_infos);
}

inline void cmd_draw_indirect_2khr(ktl::api::command_buffer _command_buffer, const ktl::api::draw_indirect_2info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_indirect_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_indirect_2khr)ptr)(_command_buffer, _p_info);
}

inline void cmd_draw_indexed_indirect_2khr(ktl::api::command_buffer _command_buffer, const ktl::api::draw_indirect_2info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_indexed_indirect_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_indexed_indirect_2khr)ptr)(_command_buffer, _p_info);
}

inline void cmd_draw_indirect_count_2khr(ktl::api::command_buffer _command_buffer, const ktl::api::draw_indirect_count_2info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_indirect_count_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_indirect_count_2khr)ptr)(_command_buffer, _p_info);
}

inline void cmd_draw_indexed_indirect_count_2khr(ktl::api::command_buffer _command_buffer, const ktl::api::draw_indirect_count_2info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_indexed_indirect_count_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_indexed_indirect_count_2khr)ptr)(_command_buffer, _p_info);
}

inline void cmd_draw_mesh_tasks_indirect_2ext(ktl::api::command_buffer _command_buffer, const ktl::api::draw_indirect_2info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_mesh_tasks_indirect_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_mesh_tasks_indirect_2ext)ptr)(_command_buffer, _p_info);
}

inline void cmd_draw_mesh_tasks_indirect_count_2ext(ktl::api::command_buffer _command_buffer, const ktl::api::draw_indirect_count_2info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_draw_mesh_tasks_indirect_count_2ext)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_draw_mesh_tasks_indirect_count_2ext)ptr)(_command_buffer, _p_info);
}

inline void cmd_dispatch_indirect_2khr(ktl::api::command_buffer _command_buffer, const ktl::api::dispatch_indirect_2info_khr * _p_info)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_dispatch_indirect_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_dispatch_indirect_2khr)ptr)(_command_buffer, _p_info);
}

inline ktl::api::result create_acceleration_structure_2khr(ktl::api::device _device, const ktl::api::acceleration_structure_create_info_2khr * _p_create_info, const ktl::api::allocation_callbacks * _p_allocator, ktl::api::acceleration_structure_khr * _p_acceleration_structure)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::create_acceleration_structure_2khr)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_create_acceleration_structure_2khr)ptr)(_device, _p_create_info, _p_allocator, _p_acceleration_structure);
}

inline ktl::api::result get_physical_device_queue_family_data_graph_engine_operation_properties_arm(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, const ktl::api::queue_family_data_graph_properties_arm * _p_queue_family_data_graph_properties, ktl::api::base_out_structure * _p_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_queue_family_data_graph_engine_operation_properties_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_queue_family_data_graph_engine_operation_properties_arm)ptr)(_physical_device, _queue_family_index, _p_queue_family_data_graph_properties, _p_properties);
}

inline void cmd_set_dispatch_parameters_arm(ktl::api::command_buffer _command_buffer, const ktl::api::dispatch_parameters_arm * _p_dispatch_parameters)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::cmd_set_dispatch_parameters_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_cmd_set_dispatch_parameters_arm)ptr)(_command_buffer, _p_dispatch_parameters);
}

inline ktl::api::result get_physical_device_queue_family_data_graph_optical_flow_image_formats_arm(ktl::api::physical_device _physical_device, ktl::u32 _queue_family_index, const ktl::api::queue_family_data_graph_properties_arm * _p_queue_family_data_graph_properties, const ktl::api::data_graph_optical_flow_image_format_info_arm * _p_optical_flow_image_format_info, ktl::u32 * _p_format_count, ktl::api::data_graph_optical_flow_image_format_properties_arm * _p_image_format_properties)
{
ktl::loader::proc_type ptr = (*ptable)[static_cast< ktl::u32 >(ktl::api::command::get_physical_device_queue_family_data_graph_optical_flow_image_formats_arm)];
if (ptr == ktl::loader::proc_null) [[unlikely]]
{
std::abort();
}
return ((pfn_get_physical_device_queue_family_data_graph_optical_flow_image_formats_arm)ptr)(_physical_device, _queue_family_index, _p_queue_family_data_graph_properties, _p_optical_flow_image_format_info, _p_format_count, _p_image_format_properties);
}

}

#endif
