#ifndef KTL_META_EXTENSION_HPP
#define KTL_META_EXTENSION_HPP

#include <span>

#include <ktl/api.hpp>
#include <ktl/api/version.hpp>
#include <ktl/meta/dependency.hpp>

namespace ktl::meta
{
template < ktl::api::extension >
struct extension
{
    static constexpr std::string_view      raw_name    = {};
    static constexpr bool                  is_instance = {};
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
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
    return {extension::raw_name, extension::is_instance, extension::promoted, extension::commands, extension::deps};
}

template <>
struct extension< ktl::api::extension::khr_surface >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 5 > commands = {
        ktl::api::command::destroy_surface_khr, ktl::api::command::get_physical_device_surface_support_khr,
        ktl::api::command::get_physical_device_surface_capabilities_khr,
        ktl::api::command::get_physical_device_surface_formats_khr,
        ktl::api::command::get_physical_device_surface_present_modes_khr};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::khr_swapchain >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_swapchain";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 9 > commands = {
        ktl::api::command::create_swapchain_khr,
        ktl::api::command::destroy_swapchain_khr,
        ktl::api::command::get_swapchain_images_khr,
        ktl::api::command::acquire_next_image_khr,
        ktl::api::command::queue_present_khr,
        ktl::api::command::get_device_group_present_capabilities_khr,
        ktl::api::command::get_device_group_surface_present_modes_khr,
        ktl::api::command::get_physical_device_present_rectangles_khr,
        ktl::api::command::acquire_next_image_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_display >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_display";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 7 > commands = {
        ktl::api::command::get_physical_device_display_properties_khr,
        ktl::api::command::get_physical_device_display_plane_properties_khr,
        ktl::api::command::get_display_plane_supported_displays_khr,
        ktl::api::command::get_display_mode_properties_khr,
        ktl::api::command::create_display_mode_khr,
        ktl::api::command::get_display_plane_capabilities_khr,
        ktl::api::command::create_display_plane_surface_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_display_swapchain >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_display_swapchain";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::create_shared_swapchains_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_display}},
         {ktl::api::version_1_1, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_display}},
         {ktl::api::version_1_2, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_display}},
         {ktl::api::version_1_3, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_display}},
         {ktl::api::version_1_4, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_display}}}};
};

template <>
struct extension< ktl::api::extension::khr_xlib_surface >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_xlib_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::create_xlib_surface_khr,
        ktl::api::command::get_physical_device_xlib_presentation_support_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_xcb_surface >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_xcb_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::create_xcb_surface_khr, ktl::api::command::get_physical_device_xcb_presentation_support_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_wayland_surface >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_wayland_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::create_wayland_surface_khr,
        ktl::api::command::get_physical_device_wayland_presentation_support_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_mir_surface >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_mir_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_android_surface >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_android_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::create_android_surface_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_win_32surface >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_win32_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::create_win_32surface_khr,
        ktl::api::command::get_physical_device_win_32presentation_support_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::android_native_buffer >
{
    static constexpr std::string_view      raw_name    = "VK_ANDROID_native_buffer";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::get_swapchain_gralloc_usage_android, ktl::api::command::acquire_image_android,
        ktl::api::command::queue_signal_release_image_android, ktl::api::command::get_swapchain_gralloc_usage_2android};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::ext_debug_report >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_debug_report";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::create_debug_report_callback_ext, ktl::api::command::destroy_debug_report_callback_ext,
        ktl::api::command::debug_report_message_ext};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::nv_glsl_shader >
{
    static constexpr std::string_view      raw_name    = "VK_NV_glsl_shader";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_depth_range_unrestricted >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_depth_range_unrestricted";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_sampler_mirror_clamp_to_edge >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_sampler_mirror_clamp_to_edge";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::img_filter_cubic >
{
    static constexpr std::string_view      raw_name    = "VK_IMG_filter_cubic";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_17 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_17";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_18 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_18";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_rasterization_order >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_rasterization_order";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_20 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_20";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_shader_trinary_minmax >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_shader_trinary_minmax";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_shader_explicit_vertex_parameter >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_shader_explicit_vertex_parameter";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_debug_marker >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_debug_marker";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::ext_debug_utils};

    static constexpr std::array< ktl::api::command, 5 > commands = {
        ktl::api::command::debug_marker_set_object_tag_ext, ktl::api::command::debug_marker_set_object_name_ext,
        ktl::api::command::cmd_debug_marker_begin_ext, ktl::api::command::cmd_debug_marker_end_ext,
        ktl::api::command::cmd_debug_marker_insert_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_debug_report}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_debug_report}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_debug_report}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_debug_report}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_debug_report}}}};
};

template <>
struct extension< ktl::api::extension::khr_video_queue >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_video_queue";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, false, 1, {}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_synchronization_2}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_synchronization_2}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_gcn_shader >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_gcn_shader";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_dedicated_allocation >
{
    static constexpr std::string_view      raw_name    = "VK_NV_dedicated_allocation";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_28 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_28";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_transform_feedback >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_transform_feedback";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 6 > commands = {
        ktl::api::command::cmd_bind_transform_feedback_buffers_ext,
        ktl::api::command::cmd_begin_transform_feedback_ext,
        ktl::api::command::cmd_end_transform_feedback_ext,
        ktl::api::command::cmd_begin_query_indexed_ext,
        ktl::api::command::cmd_end_query_indexed_ext,
        ktl::api::command::cmd_draw_indirect_byte_count_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nvx_binary_import >
{
    static constexpr std::string_view      raw_name    = "VK_NVX_binary_import";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 5 > commands = {
        ktl::api::command::create_cu_module_nvx, ktl::api::command::create_cu_function_nvx,
        ktl::api::command::destroy_cu_module_nvx, ktl::api::command::destroy_cu_function_nvx,
        ktl::api::command::cmd_cu_launch_kernel_nvx};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::nvx_image_view_handle >
{
    static constexpr std::string_view      raw_name    = "VK_NVX_image_view_handle";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::get_image_view_handle_nvx, ktl::api::command::get_image_view_handle_64nvx,
        ktl::api::command::get_image_view_address_nvx, ktl::api::command::get_device_combined_image_sampler_index_nvx};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_32 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_32";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_33 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_33";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_draw_indirect_count >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_draw_indirect_count";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_draw_indirect_count};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_draw_indirect_count_amd, ktl::api::command::cmd_draw_indexed_indirect_count_amd};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_35 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_35";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_negative_viewport_height >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_negative_viewport_height";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_gpu_shader_half_float >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_gpu_shader_half_float";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_shader_ballot >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_shader_ballot";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_texture_gather_bias_lod >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_texture_gather_bias_lod";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_shader_info >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_shader_info";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::get_shader_info_amd};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_44 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_44";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_dynamic_rendering >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_dynamic_rendering";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 2 >       commands = {ktl::api::command::cmd_begin_rendering_khr,
                                                                          ktl::api::command::cmd_end_rendering_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_depth_stencil_resolve}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_depth_stencil_resolve}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_46 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_46";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_shader_image_load_store_lod >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_shader_image_load_store_lod";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nvx_extension_48 >
{
    static constexpr std::string_view      raw_name    = "VK_NVX_extension_48";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::google_extension_49 >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_extension_49";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ggp_stream_descriptor_surface >
{
    static constexpr std::string_view      raw_name    = "VK_GGP_stream_descriptor_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::create_stream_descriptor_surface_ggp};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::nv_corner_sampled_image >
{
    static constexpr std::string_view      raw_name    = "VK_NV_corner_sampled_image";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_private_vendor_info >
{
    static constexpr std::string_view      raw_name    = "VK_NV_private_vendor_info";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_extension_53 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_53";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_multiview >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_multiview";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::img_format_pvrtc >
{
    static constexpr std::string_view      raw_name    = "VK_IMG_format_pvrtc";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_external_memory_capabilities >
{
    static constexpr std::string_view      raw_name    = "VK_NV_external_memory_capabilities";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_physical_device_external_image_format_properties_nv};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::nv_external_memory >
{
    static constexpr std::string_view      raw_name    = "VK_NV_external_memory";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::nv_external_memory_capabilities}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::nv_external_memory_capabilities}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::nv_external_memory_capabilities}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::nv_external_memory_capabilities}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::nv_external_memory_capabilities}}}};
};

template <>
struct extension< ktl::api::extension::nv_external_memory_win_32 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_external_memory_win32";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::get_memory_win_32handle_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::nv_external_memory}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::nv_external_memory}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::nv_external_memory}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::nv_external_memory}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::nv_external_memory}}}};
};

template <>
struct extension< ktl::api::extension::nv_win_32keyed_mutex >
{
    static constexpr std::string_view      raw_name    = "VK_NV_win32_keyed_mutex";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_win_32keyed_mutex};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::nv_external_memory_win_32}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::nv_external_memory_win_32}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::nv_external_memory_win_32}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::nv_external_memory_win_32}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::nv_external_memory_win_32}}}};
};

template <>
struct extension< ktl::api::extension::khr_get_physical_device_properties_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_get_physical_device_properties2";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 7 > commands = {
        ktl::api::command::get_physical_device_features_2khr,
        ktl::api::command::get_physical_device_properties_2khr,
        ktl::api::command::get_physical_device_format_properties_2khr,
        ktl::api::command::get_physical_device_image_format_properties_2khr,
        ktl::api::command::get_physical_device_queue_family_properties_2khr,
        ktl::api::command::get_physical_device_memory_properties_2khr,
        ktl::api::command::get_physical_device_sparse_image_format_properties_2khr};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::khr_device_group >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_device_group";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 7 > commands = {
        ktl::api::command::get_device_group_peer_memory_features_khr,
        ktl::api::command::cmd_set_device_mask_khr,
        ktl::api::command::cmd_dispatch_base_khr,
        ktl::api::command::get_device_group_present_capabilities_khr,
        ktl::api::command::get_device_group_surface_present_modes_khr,
        ktl::api::command::get_physical_device_present_rectangles_khr,
        ktl::api::command::acquire_next_image_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_device_group_creation}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_device_group_creation}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_device_group_creation}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_device_group_creation}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_device_group_creation}}}};
};

template <>
struct extension< ktl::api::extension::ext_validation_flags >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_validation_flags";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nn_vi_surface >
{
    static constexpr std::string_view      raw_name    = "VK_NN_vi_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::create_vi_surface_nn};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_draw_parameters >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_draw_parameters";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_shader_subgroup_ballot >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_subgroup_ballot";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_shader_subgroup_vote >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_subgroup_vote";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_texture_compression_astc_hdr >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_texture_compression_astc_hdr";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_astc_decode_mode >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_astc_decode_mode";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_pipeline_robustness >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_pipeline_robustness";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_maintenance_1 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_maintenance1";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::trim_command_pool_khr};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_device_group_creation >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_device_group_creation";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::enumerate_physical_device_groups_khr};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::khr_external_memory_capabilities >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_memory_capabilities";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_physical_device_external_buffer_properties_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_external_memory >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_memory";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_memory_capabilities}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_external_memory_win_32 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_memory_win32";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_memory_win_32handle_khr, ktl::api::command::get_memory_win_32handle_properties_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_memory}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_external_memory_fd >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_memory_fd";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 >       commands = {ktl::api::command::get_memory_fd_khr,
                                                                          ktl::api::command::get_memory_fd_properties_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_memory}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_win_32keyed_mutex >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_win32_keyed_mutex";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_memory_win_32}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_external_memory_win_32}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_external_memory_win_32}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_external_memory_win_32}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_external_memory_win_32}}}};
};

template <>
struct extension< ktl::api::extension::khr_external_semaphore_capabilities >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_semaphore_capabilities";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_physical_device_external_semaphore_properties_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_external_semaphore >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_semaphore";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_semaphore_capabilities}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_external_semaphore_capabilities}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_external_semaphore_capabilities}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_external_semaphore_capabilities}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_external_semaphore_capabilities}}}};
};

template <>
struct extension< ktl::api::extension::khr_external_semaphore_win_32 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_semaphore_win32";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::import_semaphore_win_32handle_khr, ktl::api::command::get_semaphore_win_32handle_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_semaphore}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_external_semaphore}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_external_semaphore}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_external_semaphore}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_external_semaphore}}}};
};

template <>
struct extension< ktl::api::extension::khr_external_semaphore_fd >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_semaphore_fd";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 >       commands = {ktl::api::command::import_semaphore_fd_khr,
                                                                          ktl::api::command::get_semaphore_fd_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_semaphore}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_push_descriptor >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_push_descriptor";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_push_descriptor_set_khr, ktl::api::command::cmd_push_descriptor_set_with_template_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_conditional_rendering >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_conditional_rendering";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_begin_conditional_rendering_ext, ktl::api::command::cmd_end_conditional_rendering_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_float_16int_8 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_float16_int8";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_16bit_storage >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_16bit_storage";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2,
               ktl::api::extension::khr_storage_buffer_storage_class}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_incremental_present >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_incremental_present";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::khr_descriptor_update_template >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_descriptor_update_template";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::create_descriptor_update_template_khr,
        ktl::api::command::destroy_descriptor_update_template_khr,
        ktl::api::command::update_descriptor_set_with_template_khr,
        ktl::api::command::cmd_push_descriptor_set_with_template_khr};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::nvx_device_generated_commands >
{
    static constexpr std::string_view      raw_name    = "VK_NVX_device_generated_commands";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_clip_space_w_scaling >
{
    static constexpr std::string_view      raw_name    = "VK_NV_clip_space_w_scaling";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::cmd_set_viewport_w_scaling_nv};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::ext_direct_mode_display >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_direct_mode_display";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::release_display_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_display}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_display}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_display}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_display}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_display}}}};
};

template <>
struct extension< ktl::api::extension::ext_acquire_xlib_display >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_acquire_xlib_display";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 >       commands = {ktl::api::command::acquire_xlib_display_ext,
                                                                          ktl::api::command::get_rand_r_output_display_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_direct_mode_display}}}};
};

template <>
struct extension< ktl::api::extension::ext_display_surface_counter >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_display_surface_counter";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_physical_device_surface_capabilities_2ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_display}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_display}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_display}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_display}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_display}}}};
};

template <>
struct extension< ktl::api::extension::ext_display_control >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_display_control";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::display_power_control_ext, ktl::api::command::register_device_event_ext,
        ktl::api::command::register_display_event_ext, ktl::api::command::get_swapchain_counter_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::ext_display_surface_counter, ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::ext_display_surface_counter, ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_2,
          true,
          2,
          {ktl::api::extension::ext_display_surface_counter, ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_3,
          true,
          2,
          {ktl::api::extension::ext_display_surface_counter, ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_4,
          true,
          2,
          {ktl::api::extension::ext_display_surface_counter, ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::google_display_timing >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_display_timing";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_refresh_cycle_duration_google, ktl::api::command::get_past_presentation_timing_google};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::reserved_do_not_use_94 >
{
    static constexpr std::string_view      raw_name    = "VK_RESERVED_do_not_use_94";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_sample_mask_override_coverage >
{
    static constexpr std::string_view      raw_name    = "VK_NV_sample_mask_override_coverage";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_geometry_shader_passthrough >
{
    static constexpr std::string_view      raw_name    = "VK_NV_geometry_shader_passthrough";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_viewport_array_2 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_viewport_array2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nvx_multiview_per_view_attributes >
{
    static constexpr std::string_view      raw_name    = "VK_NVX_multiview_per_view_attributes";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_multiview}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_viewport_swizzle >
{
    static constexpr std::string_view      raw_name    = "VK_NV_viewport_swizzle";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_discard_rectangles >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_discard_rectangles";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::cmd_set_discard_rectangle_ext, ktl::api::command::cmd_set_discard_rectangle_enable_ext,
        ktl::api::command::cmd_set_discard_rectangle_mode_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_101 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_101";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_conservative_rasterization >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_conservative_rasterization";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_depth_clip_enable >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_depth_clip_enable";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_104 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_104";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_swapchain_colorspace >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_swapchain_colorspace";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::ext_hdr_metadata >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_hdr_metadata";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::set_hdr_metadata_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::img_extension_107 >
{
    static constexpr std::string_view      raw_name    = "VK_IMG_extension_107";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::img_extension_108 >
{
    static constexpr std::string_view      raw_name    = "VK_IMG_extension_108";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_imageless_framebuffer >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_imageless_framebuffer";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              3,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_maintenance_2,
               ktl::api::extension::khr_image_format_list}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_image_format_list}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_create_renderpass_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_create_renderpass2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::create_render_pass_2khr, ktl::api::command::cmd_begin_render_pass_2khr,
        ktl::api::command::cmd_next_subpass_2khr, ktl::api::command::cmd_end_render_pass_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 2, {ktl::api::extension::khr_multiview, ktl::api::extension::khr_maintenance_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::img_relaxed_line_rasterization >
{
    static constexpr std::string_view      raw_name    = "VK_IMG_relaxed_line_rasterization";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_shared_presentable_image >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shared_presentable_image";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::get_swapchain_status_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              3,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_get_surface_capabilities_2,
               ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_3,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_4,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_get_surface_capabilities_2}}}};
};

template <>
struct extension< ktl::api::extension::khr_external_fence_capabilities >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_fence_capabilities";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_physical_device_external_fence_properties_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_external_fence >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_fence";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_fence_capabilities}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_external_fence_capabilities}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_external_fence_capabilities}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_external_fence_capabilities}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_external_fence_capabilities}}}};
};

template <>
struct extension< ktl::api::extension::khr_external_fence_win_32 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_fence_win32";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands   = {ktl::api::command::import_fence_win_32handle_khr,
                                                                      ktl::api::command::get_fence_win_32handle_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_fence}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_external_fence}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_external_fence}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_external_fence}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_external_fence}}}};
};

template <>
struct extension< ktl::api::extension::khr_external_fence_fd >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_external_fence_fd";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 >       commands = {ktl::api::command::import_fence_fd_khr,
                                                                          ktl::api::command::get_fence_fd_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_fence}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_performance_query >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_performance_query";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::enumerate_physical_device_queue_family_performance_query_counters_khr,
        ktl::api::command::get_physical_device_queue_family_performance_query_passes_khr,
        ktl::api::command::acquire_profiling_lock_khr, ktl::api::command::release_profiling_lock_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_maintenance_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_maintenance2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_119 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_119";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_get_surface_capabilities_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_get_surface_capabilities2";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_physical_device_surface_capabilities_2khr,
        ktl::api::command::get_physical_device_surface_formats_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_variable_pointers >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_variable_pointers";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2,
               ktl::api::extension::khr_storage_buffer_storage_class}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_get_display_properties_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_get_display_properties2";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::get_physical_device_display_properties_2khr,
        ktl::api::command::get_physical_device_display_plane_properties_2khr,
        ktl::api::command::get_display_mode_properties_2khr, ktl::api::command::get_display_plane_capabilities_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_display}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_display}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_display}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_display}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_display}}}};
};

template <>
struct extension< ktl::api::extension::mvk_ios_surface >
{
    static constexpr std::string_view      raw_name    = "VK_MVK_ios_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::create_ios_surface_mvk};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::mvk_macos_surface >
{
    static constexpr std::string_view      raw_name    = "VK_MVK_macos_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::create_mac_os_surface_mvk};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::mvk_moltenvk >
{
    static constexpr std::string_view      raw_name    = "VK_MVK_moltenvk";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_external_memory_dma_buf >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_external_memory_dma_buf";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_memory_fd}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_external_memory_fd}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_external_memory_fd}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_external_memory_fd}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_external_memory_fd}}}};
};

template <>
struct extension< ktl::api::extension::ext_queue_family_foreign >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_queue_family_foreign";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_memory}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_dedicated_allocation >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_dedicated_allocation";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_memory_requirements_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_debug_utils >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_debug_utils";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 11 > commands = {
        ktl::api::command::set_debug_utils_object_name_ext,    ktl::api::command::set_debug_utils_object_tag_ext,
        ktl::api::command::queue_begin_debug_utils_label_ext,  ktl::api::command::queue_end_debug_utils_label_ext,
        ktl::api::command::queue_insert_debug_utils_label_ext, ktl::api::command::cmd_begin_debug_utils_label_ext,
        ktl::api::command::cmd_end_debug_utils_label_ext,      ktl::api::command::cmd_insert_debug_utils_label_ext,
        ktl::api::command::create_debug_utils_messenger_ext,   ktl::api::command::destroy_debug_utils_messenger_ext,
        ktl::api::command::submit_debug_utils_message_ext};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::android_external_memory_android_hardware_buffer >
{
    static constexpr std::string_view      raw_name    = "VK_ANDROID_external_memory_android_hardware_buffer";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_android_hardware_buffer_properties_android,
        ktl::api::command::get_memory_android_hardware_buffer_android};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          4,
          {ktl::api::extension::khr_sampler_ycbcr_conversion, ktl::api::extension::khr_external_memory,
           ktl::api::extension::khr_dedicated_allocation, ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_queue_family_foreign}}}};
};

template <>
struct extension< ktl::api::extension::ext_sampler_filter_minmax >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_sampler_filter_minmax";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_storage_buffer_storage_class >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_storage_buffer_storage_class";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_gpu_shader_int_16 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_gpu_shader_int16";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_gpa_interface >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_gpa_interface";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 12 > commands = {
        ktl::api::command::create_gpa_session_amd,        ktl::api::command::destroy_gpa_session_amd,
        ktl::api::command::set_gpa_device_clock_mode_amd, ktl::api::command::get_gpa_device_clock_info_amd,
        ktl::api::command::cmd_begin_gpa_session_amd,     ktl::api::command::cmd_end_gpa_session_amd,
        ktl::api::command::cmd_begin_gpa_sample_amd,      ktl::api::command::cmd_end_gpa_sample_amd,
        ktl::api::command::get_gpa_session_status_amd,    ktl::api::command::get_gpa_session_results_amd,
        ktl::api::command::reset_gpa_session_amd,         ktl::api::command::cmd_copy_gpa_session_results_amd};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amdx_shader_enqueue >
{
    static constexpr std::string_view      raw_name    = "VK_AMDX_shader_enqueue";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 7 > commands = {
        ktl::api::command::create_execution_graph_pipelines_amdx,
        ktl::api::command::get_execution_graph_pipeline_scratch_size_amdx,
        ktl::api::command::get_execution_graph_pipeline_node_index_amdx,
        ktl::api::command::cmd_initialize_graph_scratch_memory_amdx,
        ktl::api::command::cmd_dispatch_graph_amdx,
        ktl::api::command::cmd_dispatch_graph_indirect_amdx,
        ktl::api::command::cmd_dispatch_graph_indirect_count_amdx};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          5,
          {ktl::api::extension::khr_synchronization_2, ktl::api::extension::khr_spirv_14,
           ktl::api::extension::ext_extended_dynamic_state, ktl::api::extension::khr_maintenance_5,
           ktl::api::extension::khr_pipeline_library}},
         {ktl::api::version_1_1,
          true,
          5,
          {ktl::api::extension::khr_synchronization_2, ktl::api::extension::khr_spirv_14,
           ktl::api::extension::ext_extended_dynamic_state, ktl::api::extension::khr_maintenance_5,
           ktl::api::extension::khr_pipeline_library}},
         {ktl::api::version_1_2,
          true,
          5,
          {ktl::api::extension::khr_synchronization_2, ktl::api::extension::khr_spirv_14,
           ktl::api::extension::ext_extended_dynamic_state, ktl::api::extension::khr_maintenance_5,
           ktl::api::extension::khr_pipeline_library}},
         {ktl::api::version_1_3,
          true,
          2,
          {ktl::api::extension::khr_maintenance_5, ktl::api::extension::khr_pipeline_library}},
         {ktl::api::version_1_4,
          true,
          2,
          {ktl::api::extension::khr_maintenance_5, ktl::api::extension::khr_pipeline_library}}}};
};

template <>
struct extension< ktl::api::extension::ext_descriptor_heap >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_descriptor_heap";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 10 > commands = {
        ktl::api::command::write_sampler_descriptors_ext,
        ktl::api::command::write_resource_descriptors_ext,
        ktl::api::command::cmd_bind_sampler_heap_ext,
        ktl::api::command::cmd_bind_resource_heap_ext,
        ktl::api::command::cmd_push_data_ext,
        ktl::api::command::get_image_opaque_capture_data_ext,
        ktl::api::command::get_physical_device_descriptor_size_ext,
        ktl::api::command::register_custom_border_color_ext,
        ktl::api::command::unregister_custom_border_color_ext,
        ktl::api::command::get_tensor_opaque_capture_data_arm};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_maintenance_5, ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_maintenance_5, ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_maintenance_5}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_maintenance_5}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_maintenance_5}}}};
};

template <>
struct extension< ktl::api::extension::amd_mixed_attachment_samples >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_mixed_attachment_samples";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_shader_fragment_mask >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_shader_fragment_mask";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_inline_uniform_block >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_inline_uniform_block";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_maintenance_1}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_140 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_140";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_shader_stencil_export >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_stencil_export";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_shader_bfloat_16 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_bfloat16";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_143 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_143";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_sample_locations >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_sample_locations";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_set_sample_locations_ext,
        ktl::api::command::get_physical_device_multisample_properties_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_relaxed_block_layout >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_relaxed_block_layout";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::reserved_do_not_use_146 >
{
    static constexpr std::string_view      raw_name    = "VK_RESERVED_do_not_use_146";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_get_memory_requirements_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_get_memory_requirements2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::get_image_memory_requirements_2khr, ktl::api::command::get_buffer_memory_requirements_2khr,
        ktl::api::command::get_image_sparse_memory_requirements_2khr};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::khr_image_format_list >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_image_format_list";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_blend_operation_advanced >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_blend_operation_advanced";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_fragment_coverage_to_color >
{
    static constexpr std::string_view      raw_name    = "VK_NV_fragment_coverage_to_color";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_acceleration_structure >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_acceleration_structure";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 16 > commands = {
        ktl::api::command::create_acceleration_structure_khr,
        ktl::api::command::destroy_acceleration_structure_khr,
        ktl::api::command::cmd_build_acceleration_structures_khr,
        ktl::api::command::cmd_build_acceleration_structures_indirect_khr,
        ktl::api::command::build_acceleration_structures_khr,
        ktl::api::command::copy_acceleration_structure_khr,
        ktl::api::command::copy_acceleration_structure_to_memory_khr,
        ktl::api::command::copy_memory_to_acceleration_structure_khr,
        ktl::api::command::write_acceleration_structures_properties_khr,
        ktl::api::command::cmd_copy_acceleration_structure_khr,
        ktl::api::command::cmd_copy_acceleration_structure_to_memory_khr,
        ktl::api::command::cmd_copy_memory_to_acceleration_structure_khr,
        ktl::api::command::get_acceleration_structure_device_address_khr,
        ktl::api::command::cmd_write_acceleration_structures_properties_khr,
        ktl::api::command::get_device_acceleration_structure_compatibility_khr,
        ktl::api::command::get_acceleration_structure_build_sizes_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, false, 1, {}},
         {ktl::api::version_1_1,
          true,
          3,
          {ktl::api::extension::ext_descriptor_indexing, ktl::api::extension::khr_buffer_device_address,
           ktl::api::extension::khr_deferred_host_operations}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_deferred_host_operations}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_deferred_host_operations}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_deferred_host_operations}}}};
};

template <>
struct extension< ktl::api::extension::khr_ray_tracing_pipeline >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_ray_tracing_pipeline";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 7 > commands = {
        ktl::api::command::cmd_trace_rays_khr,
        ktl::api::command::create_ray_tracing_pipelines_khr,
        ktl::api::command::get_ray_tracing_shader_group_handles_khr,
        ktl::api::command::get_ray_tracing_capture_replay_shader_group_handles_khr,
        ktl::api::command::cmd_trace_rays_indirect_khr,
        ktl::api::command::get_ray_tracing_shader_group_stack_size_khr,
        ktl::api::command::cmd_set_ray_tracing_pipeline_stack_size_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_spirv_14, ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_spirv_14, ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_acceleration_structure}}}};
};

template <>
struct extension< ktl::api::extension::khr_ray_query >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_ray_query";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_spirv_14, ktl::api::extension::khr_acceleration_structure}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_spirv_14, ktl::api::extension::khr_acceleration_structure}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_acceleration_structure}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_acceleration_structure}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_acceleration_structure}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_152 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_152";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_framebuffer_mixed_samples >
{
    static constexpr std::string_view      raw_name    = "VK_NV_framebuffer_mixed_samples";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_fill_rectangle >
{
    static constexpr std::string_view      raw_name    = "VK_NV_fill_rectangle";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_shader_sm_builtins >
{
    static constexpr std::string_view      raw_name    = "VK_NV_shader_sm_builtins";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, true, 0, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_post_depth_coverage >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_post_depth_coverage";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_sampler_ycbcr_conversion >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_sampler_ycbcr_conversion";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::create_sampler_ycbcr_conversion_khr,
        ktl::api::command::destroy_sampler_ycbcr_conversion_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          4,
          {ktl::api::extension::khr_maintenance_1, ktl::api::extension::khr_bind_memory_2,
           ktl::api::extension::khr_get_memory_requirements_2,
           ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_bind_memory_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_bind_memory2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 2 >       commands = {ktl::api::command::bind_buffer_memory_2khr,
                                                                          ktl::api::command::bind_image_memory_2khr};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_image_drm_format_modifier >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_image_drm_format_modifier";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_image_drm_format_modifier_properties_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          4,
          {ktl::api::extension::khr_bind_memory_2, ktl::api::extension::khr_get_physical_device_properties_2,
           ktl::api::extension::khr_sampler_ycbcr_conversion, ktl::api::extension::khr_image_format_list}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_image_format_list}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_160 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_160";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_validation_cache >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_validation_cache";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::create_validation_cache_ext, ktl::api::command::destroy_validation_cache_ext,
        ktl::api::command::merge_validation_caches_ext, ktl::api::command::get_validation_cache_data_ext};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::ext_descriptor_indexing >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_descriptor_indexing";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_maintenance_3}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_shader_viewport_index_layer >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_viewport_index_layer";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_portability_subset >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_portability_subset";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_shading_rate_image >
{
    static constexpr std::string_view      raw_name    = "VK_NV_shading_rate_image";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::cmd_bind_shading_rate_image_nv, ktl::api::command::cmd_set_viewport_shading_rate_palette_nv,
        ktl::api::command::cmd_set_coarse_sample_order_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_ray_tracing >
{
    static constexpr std::string_view      raw_name    = "VK_NV_ray_tracing";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 12 > commands = {
        ktl::api::command::create_acceleration_structure_nv,
        ktl::api::command::destroy_acceleration_structure_nv,
        ktl::api::command::get_acceleration_structure_memory_requirements_nv,
        ktl::api::command::bind_acceleration_structure_memory_nv,
        ktl::api::command::cmd_build_acceleration_structure_nv,
        ktl::api::command::cmd_copy_acceleration_structure_nv,
        ktl::api::command::cmd_trace_rays_nv,
        ktl::api::command::create_ray_tracing_pipelines_nv,
        ktl::api::command::get_ray_tracing_shader_group_handles_nv,
        ktl::api::command::get_acceleration_structure_handle_nv,
        ktl::api::command::cmd_write_acceleration_structures_properties_nv,
        ktl::api::command::compile_deferred_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2,
           ktl::api::extension::khr_get_memory_requirements_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_representative_fragment_test >
{
    static constexpr std::string_view      raw_name    = "VK_NV_representative_fragment_test";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_168 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_168";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_maintenance_3 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_maintenance3";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_1};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_descriptor_set_layout_support_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_draw_indirect_count >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_draw_indirect_count";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_draw_indirect_count_khr, ktl::api::command::cmd_draw_indexed_indirect_count_khr};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::ext_filter_cubic >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_filter_cubic";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::qcom_render_pass_shader_resolve >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_render_pass_shader_resolve";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::ext_custom_resolve};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::qcom_cooperative_matrix_conversion >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_cooperative_matrix_conversion";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_cooperative_matrix}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_cooperative_matrix}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_cooperative_matrix}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_cooperative_matrix}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_cooperative_matrix}}}};
};

template <>
struct extension< ktl::api::extension::qcom_elapsed_timer_query >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_elapsed_timer_query";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_global_priority >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_global_priority";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_global_priority};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_shader_subgroup_extended_types >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_subgroup_extended_types";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, true, 0, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_177 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_177";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_8bit_storage >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_8bit_storage";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2,
               ktl::api::extension::khr_storage_buffer_storage_class}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_external_memory_host >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_external_memory_host";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_memory_host_pointer_properties_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_memory}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_buffer_marker >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_buffer_marker";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands   = {ktl::api::command::cmd_write_buffer_marker_amd,
                                                                      ktl::api::command::cmd_write_buffer_marker_2amd};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::khr_shader_atomic_int_64 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_atomic_int64";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_clock >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_clock";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_183 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_183";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_pipeline_compiler_control >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_pipeline_compiler_control";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_calibrated_timestamps >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_calibrated_timestamps";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_calibrated_timestamps};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_physical_device_calibrateable_time_domains_ext,
        ktl::api::command::get_calibrated_timestamps_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_shader_core_properties >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_shader_core_properties";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_187 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_187";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_global_priority >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_global_priority";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_memory_overallocation_behavior >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_memory_overallocation_behavior";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_vertex_attribute_divisor >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_vertex_attribute_divisor";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_vertex_attribute_divisor};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ggp_frame_token >
{
    static constexpr std::string_view      raw_name    = "VK_GGP_frame_token";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::ggp_stream_descriptor_surface}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::ggp_stream_descriptor_surface}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::ggp_stream_descriptor_surface}},
             {ktl::api::version_1_3,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::ggp_stream_descriptor_surface}},
             {ktl::api::version_1_4,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::ggp_stream_descriptor_surface}}}};
};

template <>
struct extension< ktl::api::extension::ext_pipeline_creation_feedback >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_pipeline_creation_feedback";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::google_extension_194 >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_extension_194";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::google_extension_195 >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_extension_195";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::google_extension_196 >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_extension_196";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_driver_properties >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_driver_properties";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_float_controls >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_float_controls";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_shader_subgroup_partitioned >
{
    static constexpr std::string_view      raw_name    = "VK_NV_shader_subgroup_partitioned";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::ext_shader_subgroup_partitioned};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, true, 0, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_depth_stencil_resolve >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_depth_stencil_resolve";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_create_renderpass_2}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_create_renderpass_2}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_swapchain_mutable_format >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_swapchain_mutable_format";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              3,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_maintenance_2,
               ktl::api::extension::khr_image_format_list}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_image_format_list}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::nv_compute_shader_derivatives >
{
    static constexpr std::string_view      raw_name    = "VK_NV_compute_shader_derivatives";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_compute_shader_derivatives};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_mesh_shader >
{
    static constexpr std::string_view      raw_name    = "VK_NV_mesh_shader";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::cmd_draw_mesh_tasks_nv, ktl::api::command::cmd_draw_mesh_tasks_indirect_nv,
        ktl::api::command::cmd_draw_mesh_tasks_indirect_count_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_fragment_shader_barycentric >
{
    static constexpr std::string_view      raw_name    = "VK_NV_fragment_shader_barycentric";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_fragment_shader_barycentric};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_shader_image_footprint >
{
    static constexpr std::string_view      raw_name    = "VK_NV_shader_image_footprint";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_scissor_exclusive >
{
    static constexpr std::string_view      raw_name    = "VK_NV_scissor_exclusive";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_set_exclusive_scissor_enable_nv, ktl::api::command::cmd_set_exclusive_scissor_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_device_diagnostic_checkpoints >
{
    static constexpr std::string_view      raw_name    = "VK_NV_device_diagnostic_checkpoints";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 >       commands = {ktl::api::command::cmd_set_checkpoint_nv,
                                                                          ktl::api::command::get_queue_checkpoint_data_nv,
                                                                          ktl::api::command::get_queue_checkpoint_data_2nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_timeline_semaphore >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_timeline_semaphore";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 3 > commands = {ktl::api::command::get_semaphore_counter_value_khr,
                                                                    ktl::api::command::wait_semaphores_khr,
                                                                    ktl::api::command::signal_semaphore_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_present_timing >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_present_timing";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::set_swapchain_present_timing_queue_size_ext,
        ktl::api::command::get_swapchain_timing_properties_ext,
        ktl::api::command::get_swapchain_time_domain_properties_ext,
        ktl::api::command::get_past_presentation_timing_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          4,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id_2,
           ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_calibrated_timestamps}},
         {ktl::api::version_1_1,
          true,
          4,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id_2,
           ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_calibrated_timestamps}},
         {ktl::api::version_1_2,
          true,
          4,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id_2,
           ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_calibrated_timestamps}},
         {ktl::api::version_1_3,
          true,
          4,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id_2,
           ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_calibrated_timestamps}},
         {ktl::api::version_1_4,
          true,
          4,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id_2,
           ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_calibrated_timestamps}}}};
};

template <>
struct extension< ktl::api::extension::intel_shader_integer_functions_2 >
{
    static constexpr std::string_view      raw_name    = "VK_INTEL_shader_integer_functions2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::intel_performance_query >
{
    static constexpr std::string_view      raw_name    = "VK_INTEL_performance_query";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 9 > commands = {
        ktl::api::command::initialize_performance_api_intel,
        ktl::api::command::uninitialize_performance_api_intel,
        ktl::api::command::cmd_set_performance_marker_intel,
        ktl::api::command::cmd_set_performance_stream_marker_intel,
        ktl::api::command::cmd_set_performance_override_intel,
        ktl::api::command::acquire_performance_configuration_intel,
        ktl::api::command::release_performance_configuration_intel,
        ktl::api::command::queue_set_performance_configuration_intel,
        ktl::api::command::get_performance_parameter_intel};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::khr_vulkan_memory_model >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_vulkan_memory_model";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_pci_bus_info >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_pci_bus_info";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_display_native_hdr >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_display_native_hdr";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::set_local_dimming_amd};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              3,
              {ktl::api::extension::khr_get_physical_device_properties_2,
               ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_3,
              true,
              2,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_4,
              true,
              2,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::fuchsia_imagepipe_surface >
{
    static constexpr std::string_view      raw_name    = "VK_FUCHSIA_imagepipe_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::create_image_pipe_surface_fuchsia};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_terminate_invocation >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_terminate_invocation";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::google_extension_217 >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_extension_217";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_metal_surface >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_metal_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::create_metal_surface_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::ext_fragment_density_map >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_fragment_density_map";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_220 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_220";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_221 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_221";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_scalar_block_layout >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_scalar_block_layout";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_223 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_223";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::google_hlsl_functionality_1 >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_hlsl_functionality1";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::google_decorate_string >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_decorate_string";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_subgroup_size_control >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_subgroup_size_control";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, true, 0, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_fragment_shading_rate >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_fragment_shading_rate";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_physical_device_fragment_shading_rates_khr,
        ktl::api::command::cmd_set_fragment_shading_rate_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_create_renderpass_2}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_create_renderpass_2}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_shader_core_properties_2 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_shader_core_properties2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::amd_shader_core_properties}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::amd_shader_core_properties}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::amd_shader_core_properties}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::amd_shader_core_properties}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::amd_shader_core_properties}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_229 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_229";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_device_coherent_memory >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_device_coherent_memory";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_231 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_231";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_shader_constant_data >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_constant_data";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_dynamic_rendering_local_read >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_dynamic_rendering_local_read";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_set_rendering_attachment_locations_khr,
        ktl::api::command::cmd_set_rendering_input_attachment_indices_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_dynamic_rendering}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_dynamic_rendering}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_dynamic_rendering}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_abort >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_abort";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_device_fault, ktl::api::extension::khr_shader_constant_data}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_device_fault, ktl::api::extension::khr_shader_constant_data}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::khr_device_fault, ktl::api::extension::khr_shader_constant_data}},
             {ktl::api::version_1_3,
              true,
              2,
              {ktl::api::extension::khr_device_fault, ktl::api::extension::khr_shader_constant_data}},
             {ktl::api::version_1_4,
              true,
              2,
              {ktl::api::extension::khr_device_fault, ktl::api::extension::khr_shader_constant_data}}}};
};

template <>
struct extension< ktl::api::extension::ext_shader_image_atomic_int_64 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_image_atomic_int64";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_quad_control >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_quad_control";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, false, 1, {}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_vulkan_memory_model, ktl::api::extension::khr_shader_maximal_reconvergence}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_shader_maximal_reconvergence}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_shader_maximal_reconvergence}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_shader_maximal_reconvergence}}}};
};

template <>
struct extension< ktl::api::extension::khr_spirv_14 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_spirv_1_4";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, false, 1, {}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_shader_float_controls}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_shader_float_controls}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_shader_float_controls}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_shader_float_controls}}}};
};

template <>
struct extension< ktl::api::extension::ext_memory_budget >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_memory_budget";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_memory_priority >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_memory_priority";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_surface_protected_capabilities >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_surface_protected_capabilities";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, false, 1, {}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_get_surface_capabilities_2}}}};
};

template <>
struct extension< ktl::api::extension::nv_dedicated_allocation_image_aliasing >
{
    static constexpr std::string_view      raw_name    = "VK_NV_dedicated_allocation_image_aliasing";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_dedicated_allocation, ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_separate_depth_stencil_layouts >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_separate_depth_stencil_layouts";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_create_renderpass_2}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_create_renderpass_2}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::intel_extension_243 >
{
    static constexpr std::string_view      raw_name    = "VK_INTEL_extension_243";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::mesa_extension_244 >
{
    static constexpr std::string_view      raw_name    = "VK_MESA_extension_244";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_buffer_device_address >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_buffer_device_address";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::get_buffer_device_address_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_tooling_info >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_tooling_info";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_physical_device_tool_properties_ext};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::ext_separate_stencil_usage >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_separate_stencil_usage";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_validation_features >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_validation_features";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_present_wait >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_present_wait";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::wait_for_present_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id}},
             {ktl::api::version_1_1, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id}},
             {ktl::api::version_1_2, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id}},
             {ktl::api::version_1_3, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id}},
             {ktl::api::version_1_4, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id}}}};
};

template <>
struct extension< ktl::api::extension::nv_cooperative_matrix >
{
    static constexpr std::string_view      raw_name    = "VK_NV_cooperative_matrix";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_physical_device_cooperative_matrix_properties_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_coverage_reduction_mode >
{
    static constexpr std::string_view      raw_name    = "VK_NV_coverage_reduction_mode";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_physical_device_supported_framebuffer_mixed_samples_combinations_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::nv_framebuffer_mixed_samples,
           ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::nv_framebuffer_mixed_samples}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::nv_framebuffer_mixed_samples}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::nv_framebuffer_mixed_samples}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::nv_framebuffer_mixed_samples}}}};
};

template <>
struct extension< ktl::api::extension::ext_fragment_shader_interlock >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_fragment_shader_interlock";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_ycbcr_image_arrays >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_ycbcr_image_arrays";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_sampler_ycbcr_conversion}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_uniform_buffer_standard_layout >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_uniform_buffer_standard_layout";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_provoking_vertex >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_provoking_vertex";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_full_screen_exclusive >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_full_screen_exclusive";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::get_physical_device_surface_present_modes_2ext,
        ktl::api::command::acquire_full_screen_exclusive_mode_ext,
        ktl::api::command::release_full_screen_exclusive_mode_ext,
        ktl::api::command::get_device_group_surface_present_modes_2ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          4,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_surface,
           ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_1,
          true,
          3,
          {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2,
           ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_2,
          true,
          3,
          {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2,
           ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_3,
          true,
          3,
          {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2,
           ktl::api::extension::khr_swapchain}},
         {ktl::api::version_1_4,
          true,
          3,
          {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2,
           ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::ext_headless_surface >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_headless_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::create_headless_surface_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_buffer_device_address >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_buffer_device_address";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::get_buffer_device_address_khr, ktl::api::command::get_buffer_opaque_capture_address_khr,
        ktl::api::command::get_device_memory_opaque_capture_address_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_device_group}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_259 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_259";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_line_rasterization >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_line_rasterization";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_line_rasterization};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::cmd_set_line_stipple_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_shader_atomic_float >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_atomic_float";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_host_query_reset >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_host_query_reset";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_2};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::reset_query_pool_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ggp_extension_263 >
{
    static constexpr std::string_view      raw_name    = "VK_GGP_extension_263";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::brcm_extension_264 >
{
    static constexpr std::string_view      raw_name    = "VK_BRCM_extension_264";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::brcm_extension_265 >
{
    static constexpr std::string_view      raw_name    = "VK_BRCM_extension_265";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_index_type_uint_8 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_index_type_uint8";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_index_type_uint_8};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_267 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_267";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extended_dynamic_state >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extended_dynamic_state";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 12 > commands = {
        ktl::api::command::cmd_set_cull_mode_ext,           ktl::api::command::cmd_set_front_face_ext,
        ktl::api::command::cmd_set_primitive_topology_ext,  ktl::api::command::cmd_set_viewport_with_count_ext,
        ktl::api::command::cmd_set_scissor_with_count_ext,  ktl::api::command::cmd_bind_vertex_buffers_2ext,
        ktl::api::command::cmd_set_depth_test_enable_ext,   ktl::api::command::cmd_set_depth_write_enable_ext,
        ktl::api::command::cmd_set_depth_compare_op_ext,    ktl::api::command::cmd_set_depth_bounds_test_enable_ext,
        ktl::api::command::cmd_set_stencil_test_enable_ext, ktl::api::command::cmd_set_stencil_op_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_deferred_host_operations >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_deferred_host_operations";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 5 > commands = {
        ktl::api::command::create_deferred_operation_khr, ktl::api::command::destroy_deferred_operation_khr,
        ktl::api::command::get_deferred_operation_max_concurrency_khr,
        ktl::api::command::get_deferred_operation_result_khr, ktl::api::command::deferred_operation_join_khr};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::khr_pipeline_executable_properties >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_pipeline_executable_properties";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::get_pipeline_executable_properties_khr,
        ktl::api::command::get_pipeline_executable_statistics_khr,
        ktl::api::command::get_pipeline_executable_internal_representations_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_host_image_copy >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_host_image_copy";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 5 > commands = {
        ktl::api::command::copy_memory_to_image_ext, ktl::api::command::copy_image_to_memory_ext,
        ktl::api::command::copy_image_to_image_ext, ktl::api::command::transition_image_layout_ext,
        ktl::api::command::get_image_subresource_layout_2ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          3,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_copy_commands_2,
           ktl::api::extension::khr_format_feature_flags_2}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_copy_commands_2, ktl::api::extension::khr_format_feature_flags_2}},
         {ktl::api::version_1_2,
          true,
          2,
          {ktl::api::extension::khr_copy_commands_2, ktl::api::extension::khr_format_feature_flags_2}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_map_memory_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_map_memory2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 2 >       commands = {ktl::api::command::map_memory_2khr,
                                                                          ktl::api::command::unmap_memory_2khr};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_map_memory_placed >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_map_memory_placed";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_map_memory_2}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_map_memory_2}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_map_memory_2}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_map_memory_2}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_shader_atomic_float_2 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_atomic_float2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_shader_atomic_float}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_shader_atomic_float}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_shader_atomic_float}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_shader_atomic_float}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_shader_atomic_float}}}};
};

template <>
struct extension< ktl::api::extension::ext_surface_maintenance_1 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_surface_maintenance1";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_surface_maintenance_1};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_3,
              true,
              2,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_4,
              true,
              2,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2}}}};
};

template <>
struct extension< ktl::api::extension::ext_swapchain_maintenance_1 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_swapchain_maintenance1";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_swapchain_maintenance_1};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::release_swapchain_images_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          3,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::ext_surface_maintenance_1,
           ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::ext_surface_maintenance_1}},
         {ktl::api::version_1_2,
          true,
          2,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::ext_surface_maintenance_1}},
         {ktl::api::version_1_3,
          true,
          2,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::ext_surface_maintenance_1}},
         {ktl::api::version_1_4,
          true,
          2,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::ext_surface_maintenance_1}}}};
};

template <>
struct extension< ktl::api::extension::ext_shader_demote_to_helper_invocation >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_demote_to_helper_invocation";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_device_generated_commands >
{
    static constexpr std::string_view      raw_name    = "VK_NV_device_generated_commands";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 6 > commands = {
        ktl::api::command::get_generated_commands_memory_requirements_nv,
        ktl::api::command::cmd_preprocess_generated_commands_nv,
        ktl::api::command::cmd_execute_generated_commands_nv,
        ktl::api::command::cmd_bind_pipeline_shader_group_nv,
        ktl::api::command::create_indirect_commands_layout_nv,
        ktl::api::command::destroy_indirect_commands_layout_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, false, 1, {}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_inherited_viewport_scissor >
{
    static constexpr std::string_view      raw_name    = "VK_NV_inherited_viewport_scissor";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_280 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_280";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_shader_integer_dot_product >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_integer_dot_product";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_texel_buffer_alignment >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_texel_buffer_alignment";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_render_pass_transform >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_render_pass_transform";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_depth_bias_control >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_depth_bias_control";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::cmd_set_depth_bias_2ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_device_memory_report >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_device_memory_report";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_acquire_drm_display >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_acquire_drm_display";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 >       commands = {ktl::api::command::acquire_drm_display_ext,
                                                                          ktl::api::command::get_drm_display_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_direct_mode_display}}}};
};

template <>
struct extension< ktl::api::extension::ext_robustness_2 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_robustness2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_robustness_2};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_custom_border_color >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_custom_border_color";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_texture_compression_astc_3d >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_texture_compression_astc_3d";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::google_user_type >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_user_type";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_pipeline_library >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_pipeline_library";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_extension_292 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_292";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_present_barrier >
{
    static constexpr std::string_view      raw_name    = "VK_NV_present_barrier";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              4,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_surface,
               ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_1,
              true,
              3,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2,
               ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_2,
              true,
              3,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2,
               ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_3,
              true,
              3,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2,
               ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_4,
              true,
              3,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2,
               ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_non_semantic_info >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_non_semantic_info";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_present_id >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_present_id";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::ext_private_data >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_private_data";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::create_private_data_slot_ext, ktl::api::command::destroy_private_data_slot_ext,
        ktl::api::command::set_private_data_ext, ktl::api::command::get_private_data_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_297 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_297";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_pipeline_creation_cache_control >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_pipeline_creation_cache_control";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_299 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_299";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_device_diagnostics_config >
{
    static constexpr std::string_view      raw_name    = "VK_NV_device_diagnostics_config";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_render_pass_store_ops >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_render_pass_store_ops";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::qcom_queue_perf_hint >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_queue_perf_hint";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::queue_set_perf_hint_qcom};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_image_processing_3 >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_image_processing3";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_shader_multiple_wait_queues >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_shader_multiple_wait_queues";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_shader_split_barrier >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_split_barrier";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_extension_307 >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_extension_307";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_cuda_kernel_launch >
{
    static constexpr std::string_view      raw_name    = "VK_NV_cuda_kernel_launch";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 6 > commands = {
        ktl::api::command::create_cuda_module_nv,    ktl::api::command::get_cuda_module_cache_nv,
        ktl::api::command::create_cuda_function_nv,  ktl::api::command::destroy_cuda_module_nv,
        ktl::api::command::destroy_cuda_function_nv, ktl::api::command::cmd_cuda_launch_kernel_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_object_refresh >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_object_refresh";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_refresh_objects_khr,
        ktl::api::command::get_physical_device_refreshable_object_types_khr};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::qcom_tile_shading >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_tile_shading";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::cmd_dispatch_tile_qcom, ktl::api::command::cmd_begin_per_tile_execution_qcom,
        ktl::api::command::cmd_end_per_tile_execution_qcom};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::qcom_tile_properties}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::qcom_tile_properties}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::qcom_tile_properties}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::qcom_tile_properties}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::qcom_tile_properties}}}};
};

template <>
struct extension< ktl::api::extension::nv_low_latency >
{
    static constexpr std::string_view      raw_name    = "VK_NV_low_latency";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_metal_objects >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_metal_objects";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::export_metal_objects_ext};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_313 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_313";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_314 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_314";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_synchronization_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_synchronization2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 6 > commands = {
        ktl::api::command::cmd_set_event_2khr,       ktl::api::command::cmd_reset_event_2khr,
        ktl::api::command::cmd_wait_events_2khr,     ktl::api::command::cmd_pipeline_barrier_2khr,
        ktl::api::command::cmd_write_timestamp_2khr, ktl::api::command::queue_submit_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_316 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_316";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_descriptor_buffer >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_descriptor_buffer";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 11 > commands = {
        ktl::api::command::get_descriptor_set_layout_size_ext,
        ktl::api::command::get_descriptor_set_layout_binding_offset_ext,
        ktl::api::command::get_descriptor_ext,
        ktl::api::command::cmd_bind_descriptor_buffers_ext,
        ktl::api::command::cmd_set_descriptor_buffer_offsets_ext,
        ktl::api::command::cmd_bind_descriptor_buffer_embedded_samplers_ext,
        ktl::api::command::get_buffer_opaque_capture_descriptor_data_ext,
        ktl::api::command::get_image_opaque_capture_descriptor_data_ext,
        ktl::api::command::get_image_view_opaque_capture_descriptor_data_ext,
        ktl::api::command::get_sampler_opaque_capture_descriptor_data_ext,
        ktl::api::command::get_acceleration_structure_opaque_capture_descriptor_data_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          4,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_buffer_device_address,
           ktl::api::extension::ext_descriptor_indexing, ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_1,
          true,
          3,
          {ktl::api::extension::khr_buffer_device_address, ktl::api::extension::ext_descriptor_indexing,
           ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_318 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_318";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_device_address_commands >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_device_address_commands";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 22 > commands = {
        ktl::api::command::cmd_bind_index_buffer_3khr,
        ktl::api::command::cmd_bind_vertex_buffers_3khr,
        ktl::api::command::cmd_draw_indirect_2khr,
        ktl::api::command::cmd_draw_indexed_indirect_2khr,
        ktl::api::command::cmd_dispatch_indirect_2khr,
        ktl::api::command::cmd_copy_memory_khr,
        ktl::api::command::cmd_copy_memory_to_image_khr,
        ktl::api::command::cmd_copy_image_to_memory_khr,
        ktl::api::command::cmd_update_memory_khr,
        ktl::api::command::cmd_fill_memory_khr,
        ktl::api::command::cmd_copy_query_pool_results_to_memory_khr,
        ktl::api::command::cmd_draw_indirect_count_2khr,
        ktl::api::command::cmd_draw_indexed_indirect_count_2khr,
        ktl::api::command::cmd_begin_conditional_rendering_2ext,
        ktl::api::command::cmd_bind_transform_feedback_buffers_2ext,
        ktl::api::command::cmd_begin_transform_feedback_2ext,
        ktl::api::command::cmd_end_transform_feedback_2ext,
        ktl::api::command::cmd_draw_indirect_byte_count_2ext,
        ktl::api::command::cmd_draw_mesh_tasks_indirect_2ext,
        ktl::api::command::cmd_draw_mesh_tasks_indirect_count_2ext,
        ktl::api::command::cmd_write_marker_to_memory_amd,
        ktl::api::command::create_acceleration_structure_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          4,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_buffer_device_address,
           ktl::api::extension::khr_synchronization_2, ktl::api::extension::ext_extended_dynamic_state}},
         {ktl::api::version_1_1,
          true,
          3,
          {ktl::api::extension::khr_buffer_device_address, ktl::api::extension::khr_synchronization_2,
           ktl::api::extension::ext_extended_dynamic_state}},
         {ktl::api::version_1_2,
          true,
          2,
          {ktl::api::extension::khr_synchronization_2, ktl::api::extension::ext_extended_dynamic_state}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_320 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_320";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_graphics_pipeline_library >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_graphics_pipeline_library";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_pipeline_library}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_pipeline_library}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_pipeline_library}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_pipeline_library}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_pipeline_library}}}};
};

template <>
struct extension< ktl::api::extension::amd_shader_early_and_late_fragment_tests >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_shader_early_and_late_fragment_tests";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_fragment_shader_barycentric >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_fragment_shader_barycentric";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_subgroup_uniform_control_flow >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_subgroup_uniform_control_flow";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, true, 0, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_325 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_325";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_zero_initialize_workgroup_memory >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_zero_initialize_workgroup_memory";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_fragment_shading_rate_enums >
{
    static constexpr std::string_view      raw_name    = "VK_NV_fragment_shading_rate_enums";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::cmd_set_fragment_shading_rate_enum_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_fragment_shading_rate}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_fragment_shading_rate}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_fragment_shading_rate}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_fragment_shading_rate}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_fragment_shading_rate}}}};
};

template <>
struct extension< ktl::api::extension::nv_ray_tracing_motion_blur >
{
    static constexpr std::string_view      raw_name    = "VK_NV_ray_tracing_motion_blur";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}}}};
};

template <>
struct extension< ktl::api::extension::ext_mesh_shader >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_mesh_shader";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::cmd_draw_mesh_tasks_ext, ktl::api::command::cmd_draw_mesh_tasks_indirect_ext,
        ktl::api::command::cmd_draw_mesh_tasks_indirect_count_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_spirv_14}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_spirv_14}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_330 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_330";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_ycbcr_2plane_444formats >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_ycbcr_2plane_444_formats";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_sampler_ycbcr_conversion}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_332 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_332";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_fragment_density_map_2 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_fragment_density_map2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_fragment_density_map}}}};
};

template <>
struct extension< ktl::api::extension::qcom_rotated_copy_commands >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_rotated_copy_commands";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_copy_commands_2}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_copy_commands_2}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_copy_commands_2}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_335 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_335";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_image_robustness >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_image_robustness";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_workgroup_memory_explicit_layout >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_workgroup_memory_explicit_layout";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_copy_commands_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_copy_commands2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 6 > commands = {
        ktl::api::command::cmd_copy_buffer_2khr,          ktl::api::command::cmd_copy_image_2khr,
        ktl::api::command::cmd_copy_buffer_to_image_2khr, ktl::api::command::cmd_copy_image_to_buffer_2khr,
        ktl::api::command::cmd_blit_image_2khr,           ktl::api::command::cmd_resolve_image_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_image_compression_control >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_image_compression_control";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_image_subresource_layout_2ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_attachment_feedback_loop_layout >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_attachment_feedback_loop_layout";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_4444formats >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_4444_formats";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_device_fault >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_device_fault";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_device_fault};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::get_device_fault_info_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::arm_rasterization_order_attachment_access >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_rasterization_order_attachment_access";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted = {ktl::api::extension::ext_rasterization_order_attachment_access};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::arm_extension_344 >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_extension_344";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_rgba_10x_6formats >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_rgba10x6_formats";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_sampler_ycbcr_conversion}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_acquire_winrt_display >
{
    static constexpr std::string_view      raw_name    = "VK_NV_acquire_winrt_display";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 >       commands = {ktl::api::command::acquire_winrt_display_nv,
                                                                          ktl::api::command::get_winrt_display_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_direct_mode_display}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_direct_mode_display}}}};
};

template <>
struct extension< ktl::api::extension::ext_directfb_surface >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_directfb_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::create_direct_fb_surface_ext,
        ktl::api::command::get_physical_device_direct_fb_presentation_support_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_350 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_350";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_extension_351 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_351";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::valve_mutable_descriptor_type >
{
    static constexpr std::string_view      raw_name    = "VK_VALVE_mutable_descriptor_type";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::ext_mutable_descriptor_type};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_maintenance_3}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_maintenance_3}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_maintenance_3}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_maintenance_3}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_maintenance_3}}}};
};

template <>
struct extension< ktl::api::extension::ext_vertex_input_dynamic_state >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_vertex_input_dynamic_state";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::cmd_set_vertex_input_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_physical_device_drm >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_physical_device_drm";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_device_address_binding_report >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_device_address_binding_report";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::ext_debug_utils}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_debug_utils}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_debug_utils}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_debug_utils}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_debug_utils}}}};
};

template <>
struct extension< ktl::api::extension::ext_depth_clip_control >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_depth_clip_control";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_primitive_topology_list_restart >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_primitive_topology_list_restart";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_358 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_358";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_359 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_359";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_360 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_360";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_format_feature_flags_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_format_feature_flags2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_present_mode_fifo_latest_ready >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_present_mode_fifo_latest_ready";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_present_mode_fifo_latest_ready};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_363 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_363";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::fuchsia_extension_364 >
{
    static constexpr std::string_view      raw_name    = "VK_FUCHSIA_extension_364";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::fuchsia_external_memory >
{
    static constexpr std::string_view      raw_name    = "VK_FUCHSIA_external_memory";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_memory_zircon_handle_fuchsia,
        ktl::api::command::get_memory_zircon_handle_properties_fuchsia};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_external_memory_capabilities, ktl::api::extension::khr_external_memory}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::fuchsia_external_semaphore >
{
    static constexpr std::string_view      raw_name    = "VK_FUCHSIA_external_semaphore";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::import_semaphore_zircon_handle_fuchsia,
        ktl::api::command::get_semaphore_zircon_handle_fuchsia};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_external_semaphore_capabilities, ktl::api::extension::khr_external_semaphore}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_external_semaphore_capabilities, ktl::api::extension::khr_external_semaphore}},
         {ktl::api::version_1_2,
          true,
          2,
          {ktl::api::extension::khr_external_semaphore_capabilities, ktl::api::extension::khr_external_semaphore}},
         {ktl::api::version_1_3,
          true,
          2,
          {ktl::api::extension::khr_external_semaphore_capabilities, ktl::api::extension::khr_external_semaphore}},
         {ktl::api::version_1_4,
          true,
          2,
          {ktl::api::extension::khr_external_semaphore_capabilities, ktl::api::extension::khr_external_semaphore}}}};
};

template <>
struct extension< ktl::api::extension::fuchsia_buffer_collection >
{
    static constexpr std::string_view      raw_name    = "VK_FUCHSIA_buffer_collection";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 5 > commands = {
        ktl::api::command::create_buffer_collection_fuchsia,
        ktl::api::command::set_buffer_collection_image_constraints_fuchsia,
        ktl::api::command::set_buffer_collection_buffer_constraints_fuchsia,
        ktl::api::command::destroy_buffer_collection_fuchsia,
        ktl::api::command::get_buffer_collection_properties_fuchsia};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::fuchsia_external_memory, ktl::api::extension::khr_sampler_ycbcr_conversion}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::fuchsia_external_memory}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::fuchsia_external_memory}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::fuchsia_external_memory}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::fuchsia_external_memory}}}};
};

template <>
struct extension< ktl::api::extension::fuchsia_extension_368 >
{
    static constexpr std::string_view      raw_name    = "VK_FUCHSIA_extension_368";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::qcom_extension_369 >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_extension_369";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::huawei_subpass_shading >
{
    static constexpr std::string_view      raw_name    = "VK_HUAWEI_subpass_shading";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_device_subpass_shading_max_workgroup_size_huawei,
        ktl::api::command::cmd_subpass_shading_huawei};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_create_renderpass_2, ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_create_renderpass_2, ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::huawei_invocation_mask >
{
    static constexpr std::string_view      raw_name    = "VK_HUAWEI_invocation_mask";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {ktl::api::command::cmd_bind_invocation_mask_huawei};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_ray_tracing_pipeline, ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_ray_tracing_pipeline, ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_2,
          true,
          2,
          {ktl::api::extension::khr_ray_tracing_pipeline, ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}}}};
};

template <>
struct extension< ktl::api::extension::nv_external_memory_rdma >
{
    static constexpr std::string_view      raw_name    = "VK_NV_external_memory_rdma";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::get_memory_remote_address_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_memory}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_pipeline_properties >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_pipeline_properties";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::get_pipeline_properties_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_external_sci_sync >
{
    static constexpr std::string_view      raw_name    = "VK_NV_external_sci_sync";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 7 > commands = {
        ktl::api::command::get_fence_sci_sync_fence_nv,
        ktl::api::command::get_fence_sci_sync_obj_nv,
        ktl::api::command::import_fence_sci_sync_fence_nv,
        ktl::api::command::import_fence_sci_sync_obj_nv,
        ktl::api::command::get_physical_device_sci_sync_attributes_nv,
        ktl::api::command::get_semaphore_sci_sync_obj_nv,
        ktl::api::command::import_semaphore_sci_sync_obj_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {{{ktl::api::version_1_0, false, 1, {}},
                                                                       {ktl::api::version_1_1, true, 0, {}},
                                                                       {ktl::api::version_1_2, true, 0, {}},
                                                                       {ktl::api::version_1_3, true, 0, {}},
                                                                       {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_external_memory_sci_buf >
{
    static constexpr std::string_view      raw_name    = "VK_NV_external_memory_sci_buf";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::get_memory_sci_buf_nv,
        ktl::api::command::get_physical_device_external_memory_sci_buf_properties_nv,
        ktl::api::command::get_physical_device_sci_buf_attributes_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {{{ktl::api::version_1_0, false, 1, {}},
                                                                       {ktl::api::version_1_1, true, 0, {}},
                                                                       {ktl::api::version_1_2, true, 0, {}},
                                                                       {ktl::api::version_1_3, true, 0, {}},
                                                                       {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_frame_boundary >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_frame_boundary";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_multisampled_render_to_single_sampled >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_multisampled_render_to_single_sampled";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_create_renderpass_2, ktl::api::extension::khr_depth_stencil_resolve}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_create_renderpass_2, ktl::api::extension::khr_depth_stencil_resolve}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extended_dynamic_state_2 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extended_dynamic_state2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 5 > commands = {
        ktl::api::command::cmd_set_patch_control_points_ext, ktl::api::command::cmd_set_rasterizer_discard_enable_ext,
        ktl::api::command::cmd_set_depth_bias_enable_ext, ktl::api::command::cmd_set_logic_op_ext,
        ktl::api::command::cmd_set_primitive_restart_enable_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qnx_screen_surface >
{
    static constexpr std::string_view      raw_name    = "VK_QNX_screen_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::create_screen_surface_qnx,
        ktl::api::command::get_physical_device_screen_presentation_support_qnx};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_380 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_380";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_381 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_381";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_color_write_enable >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_color_write_enable";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {ktl::api::command::cmd_set_color_write_enable_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_primitives_generated_query >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_primitives_generated_query";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_transform_feedback}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_transform_feedback}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_transform_feedback}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_transform_feedback}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_transform_feedback}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_384 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_384";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::mesa_extension_385 >
{
    static constexpr std::string_view      raw_name    = "VK_MESA_extension_385";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::google_extension_386 >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_extension_386";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_ray_tracing_maintenance_1 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_ray_tracing_maintenance1";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::cmd_trace_rays_indirect_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_acceleration_structure}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_untyped_pointers >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_untyped_pointers";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}}}};
};

template <>
struct extension< ktl::api::extension::ext_global_priority_query >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_global_priority_query";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_global_priority};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::ext_global_priority, ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_global_priority}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_global_priority}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_global_priority}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_global_priority}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_390 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_390";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_image_view_min_lod >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_image_view_min_lod";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_multi_draw >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_multi_draw";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 >       commands = {ktl::api::command::cmd_draw_multi_ext,
                                                                          ktl::api::command::cmd_draw_multi_indexed_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_image_2d_view_of_3d >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_image_2d_view_of_3d";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_maintenance_1, ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_portability_enumeration >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_portability_enumeration";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_shader_tile_image >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_tile_image";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, false, 1, {}},
                                                                           {ktl::api::version_1_2, false, 1, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_opacity_micromap >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_opacity_micromap";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_opacity_micromap};

    static constexpr std::array< ktl::api::command, 14 > commands = {
        ktl::api::command::create_micromap_ext,
        ktl::api::command::destroy_micromap_ext,
        ktl::api::command::cmd_build_micromaps_ext,
        ktl::api::command::build_micromaps_ext,
        ktl::api::command::copy_micromap_ext,
        ktl::api::command::copy_micromap_to_memory_ext,
        ktl::api::command::copy_memory_to_micromap_ext,
        ktl::api::command::write_micromaps_properties_ext,
        ktl::api::command::cmd_copy_micromap_ext,
        ktl::api::command::cmd_copy_micromap_to_memory_ext,
        ktl::api::command::cmd_copy_memory_to_micromap_ext,
        ktl::api::command::cmd_write_micromaps_properties_ext,
        ktl::api::command::get_device_micromap_compatibility_ext,
        ktl::api::command::get_micromap_build_sizes_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_2,
          true,
          2,
          {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_acceleration_structure}}}};
};

template <>
struct extension< ktl::api::extension::nv_displacement_micromap >
{
    static constexpr std::string_view      raw_name    = "VK_NV_displacement_micromap";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_opacity_micromap}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_opacity_micromap}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_opacity_micromap}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_opacity_micromap}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_opacity_micromap}}}};
};

template <>
struct extension< ktl::api::extension::juice_extension_399 >
{
    static constexpr std::string_view      raw_name    = "VK_JUICE_extension_399";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::juice_extension_400 >
{
    static constexpr std::string_view      raw_name    = "VK_JUICE_extension_400";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_load_store_op_none >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_load_store_op_none";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_load_store_op_none};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::fb_extension_402 >
{
    static constexpr std::string_view      raw_name    = "VK_FB_extension_402";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::fb_extension_403 >
{
    static constexpr std::string_view      raw_name    = "VK_FB_extension_403";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::fb_extension_404 >
{
    static constexpr std::string_view      raw_name    = "VK_FB_extension_404";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::huawei_cluster_culling_shader >
{
    static constexpr std::string_view      raw_name    = "VK_HUAWEI_cluster_culling_shader";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_draw_cluster_huawei, ktl::api::command::cmd_draw_cluster_indirect_huawei};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::huawei_extension_406 >
{
    static constexpr std::string_view      raw_name    = "VK_HUAWEI_extension_406";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ggp_extension_407 >
{
    static constexpr std::string_view      raw_name    = "VK_GGP_extension_407";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ggp_extension_408 >
{
    static constexpr std::string_view      raw_name    = "VK_GGP_extension_408";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ggp_extension_409 >
{
    static constexpr std::string_view      raw_name    = "VK_GGP_extension_409";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ggp_extension_410 >
{
    static constexpr std::string_view      raw_name    = "VK_GGP_extension_410";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ggp_extension_411 >
{
    static constexpr std::string_view      raw_name    = "VK_GGP_extension_411";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_border_color_swizzle >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_border_color_swizzle";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_custom_border_color}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_custom_border_color}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_custom_border_color}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_custom_border_color}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_custom_border_color}}}};
};

template <>
struct extension< ktl::api::extension::ext_pageable_device_local_memory >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_pageable_device_local_memory";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {ktl::api::command::set_device_memory_priority_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_memory_priority}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_memory_priority}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_memory_priority}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_memory_priority}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_memory_priority}}}};
};

template <>
struct extension< ktl::api::extension::khr_maintenance_4 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_maintenance4";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_3};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::get_device_buffer_memory_requirements_khr,
        ktl::api::command::get_device_image_memory_requirements_khr,
        ktl::api::command::get_device_image_sparse_memory_requirements_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {{{ktl::api::version_1_0, false, 1, {}},
                                                                       {ktl::api::version_1_1, true, 0, {}},
                                                                       {ktl::api::version_1_2, true, 0, {}},
                                                                       {ktl::api::version_1_3, true, 0, {}},
                                                                       {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::huawei_extension_415 >
{
    static constexpr std::string_view      raw_name    = "VK_HUAWEI_extension_415";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_shader_core_properties >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_shader_core_properties";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, true, 0, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_subgroup_rotate >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_subgroup_rotate";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::arm_scheduling_controls >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_scheduling_controls";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {ktl::api::command::cmd_set_dispatch_parameters_arm};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::arm_shader_core_builtins}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::arm_shader_core_builtins}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::arm_shader_core_builtins}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::arm_shader_core_builtins}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::arm_shader_core_builtins}}}};
};

template <>
struct extension< ktl::api::extension::ext_image_sliced_view_of_3d >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_image_sliced_view_of_3d";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_maintenance_1, ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_420 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_420";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::valve_descriptor_set_host_mapping >
{
    static constexpr std::string_view      raw_name    = "VK_VALVE_descriptor_set_host_mapping";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_descriptor_set_layout_host_mapping_info_valve,
        ktl::api::command::get_descriptor_set_host_mapping_valve};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_depth_clamp_zero_one >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_depth_clamp_zero_one";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_depth_clamp_zero_one};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_non_seamless_cube_map >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_non_seamless_cube_map";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::arm_extension_424 >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_extension_424";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_render_pass_striped >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_render_pass_striped";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_synchronization_2}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_synchronization_2}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_synchronization_2}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_fragment_density_map_offset >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_fragment_density_map_offset";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::ext_fragment_density_map_offset};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_fragment_density_map}}}};
};

template <>
struct extension< ktl::api::extension::nv_copy_memory_indirect >
{
    static constexpr std::string_view      raw_name    = "VK_NV_copy_memory_indirect";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_copy_memory_indirect};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_copy_memory_indirect_nv, ktl::api::command::cmd_copy_memory_to_image_indirect_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_memory_decompression >
{
    static constexpr std::string_view      raw_name    = "VK_NV_memory_decompression";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::ext_memory_decompression};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_decompress_memory_nv, ktl::api::command::cmd_decompress_memory_indirect_count_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_device_generated_commands_compute >
{
    static constexpr std::string_view      raw_name    = "VK_NV_device_generated_commands_compute";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::get_pipeline_indirect_memory_requirements_nv,
        ktl::api::command::cmd_update_pipeline_indirect_buffer_nv,
        ktl::api::command::get_pipeline_indirect_device_address_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::nv_device_generated_commands}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::nv_device_generated_commands}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::nv_device_generated_commands}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::nv_device_generated_commands}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::nv_device_generated_commands}}}};
};

template <>
struct extension< ktl::api::extension::nv_ray_tracing_linear_swept_spheres >
{
    static constexpr std::string_view      raw_name    = "VK_NV_ray_tracing_linear_swept_spheres";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}}}};
};

template <>
struct extension< ktl::api::extension::nv_linear_color_attachment >
{
    static constexpr std::string_view      raw_name    = "VK_NV_linear_color_attachment";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_432 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_432";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_extension_433 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_433";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::google_surfaceless_query >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_surfaceless_query";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_maximal_reconvergence >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_maximal_reconvergence";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, true, 0, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_application_parameters >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_application_parameters";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_437 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_437";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_image_compression_control_swapchain >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_image_compression_control_swapchain";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_image_compression_control}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_image_compression_control}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_image_compression_control}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_image_compression_control}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_image_compression_control}}}};
};

template <>
struct extension< ktl::api::extension::sec_extension_439 >
{
    static constexpr std::string_view      raw_name    = "VK_SEC_extension_439";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::qcom_extension_440 >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_extension_440";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::qcom_image_processing >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_image_processing";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_format_feature_flags_2}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_format_feature_flags_2}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_format_feature_flags_2}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::coreavi_extension_442 >
{
    static constexpr std::string_view      raw_name    = "VK_COREAVI_extension_442";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::coreavi_extension_443 >
{
    static constexpr std::string_view      raw_name    = "VK_COREAVI_extension_443";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::coreavi_extension_444 >
{
    static constexpr std::string_view      raw_name    = "VK_COREAVI_extension_444";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::coreavi_extension_445 >
{
    static constexpr std::string_view      raw_name    = "VK_COREAVI_extension_445";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::coreavi_extension_446 >
{
    static constexpr std::string_view      raw_name    = "VK_COREAVI_extension_446";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::coreavi_extension_447 >
{
    static constexpr std::string_view      raw_name    = "VK_COREAVI_extension_447";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::sec_extension_448 >
{
    static constexpr std::string_view      raw_name    = "VK_SEC_extension_448";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::sec_extension_449 >
{
    static constexpr std::string_view      raw_name    = "VK_SEC_extension_449";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::sec_extension_450 >
{
    static constexpr std::string_view      raw_name    = "VK_SEC_extension_450";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::sec_extension_451 >
{
    static constexpr std::string_view      raw_name    = "VK_SEC_extension_451";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_nested_command_buffer >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_nested_command_buffer";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ohos_external_memory >
{
    static constexpr std::string_view      raw_name    = "VK_OHOS_external_memory";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_native_buffer_properties_ohos, ktl::api::command::get_memory_native_buffer_ohos};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          4,
          {ktl::api::extension::khr_sampler_ycbcr_conversion, ktl::api::extension::khr_external_memory,
           ktl::api::extension::khr_dedicated_allocation, ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_queue_family_foreign}}}};
};

template <>
struct extension< ktl::api::extension::ext_external_memory_acquire_unmodified >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_external_memory_acquire_unmodified";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_memory}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::google_extension_455 >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_extension_455";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extended_dynamic_state_3 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extended_dynamic_state3";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 31 > commands = {
        ktl::api::command::cmd_set_depth_clamp_enable_ext,
        ktl::api::command::cmd_set_polygon_mode_ext,
        ktl::api::command::cmd_set_rasterization_samples_ext,
        ktl::api::command::cmd_set_sample_mask_ext,
        ktl::api::command::cmd_set_alpha_to_coverage_enable_ext,
        ktl::api::command::cmd_set_alpha_to_one_enable_ext,
        ktl::api::command::cmd_set_logic_op_enable_ext,
        ktl::api::command::cmd_set_color_blend_enable_ext,
        ktl::api::command::cmd_set_color_blend_equation_ext,
        ktl::api::command::cmd_set_color_write_mask_ext,
        ktl::api::command::cmd_set_tessellation_domain_origin_ext,
        ktl::api::command::cmd_set_rasterization_stream_ext,
        ktl::api::command::cmd_set_conservative_rasterization_mode_ext,
        ktl::api::command::cmd_set_extra_primitive_overestimation_size_ext,
        ktl::api::command::cmd_set_depth_clip_enable_ext,
        ktl::api::command::cmd_set_sample_locations_enable_ext,
        ktl::api::command::cmd_set_color_blend_advanced_ext,
        ktl::api::command::cmd_set_provoking_vertex_mode_ext,
        ktl::api::command::cmd_set_line_rasterization_mode_ext,
        ktl::api::command::cmd_set_line_stipple_enable_ext,
        ktl::api::command::cmd_set_depth_clip_negative_one_to_one_ext,
        ktl::api::command::cmd_set_viewport_w_scaling_enable_nv,
        ktl::api::command::cmd_set_viewport_swizzle_nv,
        ktl::api::command::cmd_set_coverage_to_color_enable_nv,
        ktl::api::command::cmd_set_coverage_to_color_location_nv,
        ktl::api::command::cmd_set_coverage_modulation_mode_nv,
        ktl::api::command::cmd_set_coverage_modulation_table_enable_nv,
        ktl::api::command::cmd_set_coverage_modulation_table_nv,
        ktl::api::command::cmd_set_shading_rate_image_enable_nv,
        ktl::api::command::cmd_set_representative_fragment_test_enable_nv,
        ktl::api::command::cmd_set_coverage_reduction_mode_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_457 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_457";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_458 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_458";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_subpass_merge_feedback >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_subpass_merge_feedback";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::lunarg_direct_driver_loading >
{
    static constexpr std::string_view      raw_name    = "VK_LUNARG_direct_driver_loading";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_tensors >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_tensors";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 11 > commands = {
        ktl::api::command::create_tensor_arm,
        ktl::api::command::destroy_tensor_arm,
        ktl::api::command::create_tensor_view_arm,
        ktl::api::command::destroy_tensor_view_arm,
        ktl::api::command::get_tensor_memory_requirements_arm,
        ktl::api::command::bind_tensor_memory_arm,
        ktl::api::command::get_device_tensor_memory_requirements_arm,
        ktl::api::command::cmd_copy_tensor_arm,
        ktl::api::command::get_physical_device_external_tensor_properties_arm,
        ktl::api::command::get_tensor_opaque_capture_descriptor_data_arm,
        ktl::api::command::get_tensor_view_opaque_capture_descriptor_data_arm};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {{{ktl::api::version_1_0, false, 1, {}},
                                                                       {ktl::api::version_1_1, false, 1, {}},
                                                                       {ktl::api::version_1_2, false, 1, {}},
                                                                       {ktl::api::version_1_3, true, 0, {}},
                                                                       {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_462 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_462";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_shader_module_identifier >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_module_identifier";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_shader_module_identifier_ext,
        ktl::api::command::get_shader_module_create_info_identifier_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2,
           ktl::api::extension::ext_pipeline_creation_cache_control}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_pipeline_creation_cache_control}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_pipeline_creation_cache_control}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_rasterization_order_attachment_access >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_rasterization_order_attachment_access";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_optical_flow >
{
    static constexpr std::string_view      raw_name    = "VK_NV_optical_flow";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 5 > commands = {
        ktl::api::command::get_physical_device_optical_flow_image_formats_nv,
        ktl::api::command::create_optical_flow_session_nv, ktl::api::command::destroy_optical_flow_session_nv,
        ktl::api::command::bind_optical_flow_session_image_nv, ktl::api::command::cmd_optical_flow_execute_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          3,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_format_feature_flags_2,
           ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_format_feature_flags_2, ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_2,
          true,
          2,
          {ktl::api::extension::khr_format_feature_flags_2, ktl::api::extension::khr_synchronization_2}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_legacy_dithering >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_legacy_dithering";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_pipeline_protected_access >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_pipeline_protected_access";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_468 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_468";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::android_external_format_resolve >
{
    static constexpr std::string_view      raw_name    = "VK_ANDROID_external_format_resolve";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::android_external_memory_android_hardware_buffer}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::android_external_memory_android_hardware_buffer}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::android_external_memory_android_hardware_buffer}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::android_external_memory_android_hardware_buffer}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::android_external_memory_android_hardware_buffer}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_470 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_470";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_maintenance_5 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_maintenance5";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 4 > commands = {
        ktl::api::command::cmd_bind_index_buffer_2khr, ktl::api::command::get_rendering_area_granularity_khr,
        ktl::api::command::get_device_image_subresource_layout_khr,
        ktl::api::command::get_image_subresource_layout_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, false, 1, {}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_dynamic_rendering}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_dynamic_rendering}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_472 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_472";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_473 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_473";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_474 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_474";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_475 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_475";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_476 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_476";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_anti_lag >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_anti_lag";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::anti_lag_update_amd};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::amd_extension_478 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_478";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amdx_dense_geometry_format >
{
    static constexpr std::string_view      raw_name    = "VK_AMDX_dense_geometry_format";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_maintenance_5}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_maintenance_5}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_maintenance_5}},
             {ktl::api::version_1_3,
              true,
              2,
              {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_maintenance_5}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_acceleration_structure}}}};
};

template <>
struct extension< ktl::api::extension::khr_present_id_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_present_id2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              3,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_surface,
               ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_1,
              true,
              3,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_surface,
               ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_2,
              true,
              3,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_surface,
               ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_3,
              true,
              3,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_surface,
               ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_4,
              true,
              3,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_surface,
               ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::khr_present_wait_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_present_wait2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::wait_for_present_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              4,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_surface,
               ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id_2}},
             {ktl::api::version_1_1,
              true,
              4,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_surface,
               ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id_2}},
             {ktl::api::version_1_2,
              true,
              4,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_surface,
               ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id_2}},
             {ktl::api::version_1_3,
              true,
              4,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_surface,
               ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id_2}},
             {ktl::api::version_1_4,
              true,
              4,
              {ktl::api::extension::khr_get_surface_capabilities_2, ktl::api::extension::khr_surface,
               ktl::api::extension::khr_swapchain, ktl::api::extension::khr_present_id_2}}}};
};

template <>
struct extension< ktl::api::extension::khr_ray_tracing_position_fetch >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_ray_tracing_position_fetch";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_acceleration_structure}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_acceleration_structure}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_acceleration_structure}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_acceleration_structure}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_acceleration_structure}}}};
};

template <>
struct extension< ktl::api::extension::ext_shader_object >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_object";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 54 > commands = {
        ktl::api::command::create_shaders_ext,
        ktl::api::command::destroy_shader_ext,
        ktl::api::command::get_shader_binary_data_ext,
        ktl::api::command::cmd_bind_shaders_ext,
        ktl::api::command::cmd_set_cull_mode_ext,
        ktl::api::command::cmd_set_front_face_ext,
        ktl::api::command::cmd_set_primitive_topology_ext,
        ktl::api::command::cmd_set_viewport_with_count_ext,
        ktl::api::command::cmd_set_scissor_with_count_ext,
        ktl::api::command::cmd_bind_vertex_buffers_2ext,
        ktl::api::command::cmd_set_depth_test_enable_ext,
        ktl::api::command::cmd_set_depth_write_enable_ext,
        ktl::api::command::cmd_set_depth_compare_op_ext,
        ktl::api::command::cmd_set_depth_bounds_test_enable_ext,
        ktl::api::command::cmd_set_stencil_test_enable_ext,
        ktl::api::command::cmd_set_stencil_op_ext,
        ktl::api::command::cmd_set_vertex_input_ext,
        ktl::api::command::cmd_set_patch_control_points_ext,
        ktl::api::command::cmd_set_rasterizer_discard_enable_ext,
        ktl::api::command::cmd_set_depth_bias_enable_ext,
        ktl::api::command::cmd_set_logic_op_ext,
        ktl::api::command::cmd_set_primitive_restart_enable_ext,
        ktl::api::command::cmd_set_tessellation_domain_origin_ext,
        ktl::api::command::cmd_set_depth_clamp_enable_ext,
        ktl::api::command::cmd_set_polygon_mode_ext,
        ktl::api::command::cmd_set_rasterization_samples_ext,
        ktl::api::command::cmd_set_sample_mask_ext,
        ktl::api::command::cmd_set_alpha_to_coverage_enable_ext,
        ktl::api::command::cmd_set_alpha_to_one_enable_ext,
        ktl::api::command::cmd_set_logic_op_enable_ext,
        ktl::api::command::cmd_set_color_blend_enable_ext,
        ktl::api::command::cmd_set_color_blend_equation_ext,
        ktl::api::command::cmd_set_color_write_mask_ext,
        ktl::api::command::cmd_set_rasterization_stream_ext,
        ktl::api::command::cmd_set_conservative_rasterization_mode_ext,
        ktl::api::command::cmd_set_extra_primitive_overestimation_size_ext,
        ktl::api::command::cmd_set_depth_clip_enable_ext,
        ktl::api::command::cmd_set_sample_locations_enable_ext,
        ktl::api::command::cmd_set_color_blend_advanced_ext,
        ktl::api::command::cmd_set_provoking_vertex_mode_ext,
        ktl::api::command::cmd_set_line_rasterization_mode_ext,
        ktl::api::command::cmd_set_line_stipple_enable_ext,
        ktl::api::command::cmd_set_depth_clip_negative_one_to_one_ext,
        ktl::api::command::cmd_set_viewport_w_scaling_enable_nv,
        ktl::api::command::cmd_set_viewport_swizzle_nv,
        ktl::api::command::cmd_set_coverage_to_color_enable_nv,
        ktl::api::command::cmd_set_coverage_to_color_location_nv,
        ktl::api::command::cmd_set_coverage_modulation_mode_nv,
        ktl::api::command::cmd_set_coverage_modulation_table_enable_nv,
        ktl::api::command::cmd_set_coverage_modulation_table_nv,
        ktl::api::command::cmd_set_shading_rate_image_enable_nv,
        ktl::api::command::cmd_set_representative_fragment_test_enable_nv,
        ktl::api::command::cmd_set_coverage_reduction_mode_nv,
        ktl::api::command::cmd_set_depth_clamp_range_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_dynamic_rendering}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_dynamic_rendering}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_dynamic_rendering}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_pipeline_binary >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_pipeline_binary";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 5 > commands = {
        ktl::api::command::create_pipeline_binaries_khr, ktl::api::command::destroy_pipeline_binary_khr,
        ktl::api::command::get_pipeline_key_khr, ktl::api::command::get_pipeline_binary_data_khr,
        ktl::api::command::release_captured_pipeline_data_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_maintenance_5}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_maintenance_5}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_maintenance_5}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_maintenance_5}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_tile_properties >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_tile_properties";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_framebuffer_tile_properties_qcom,
        ktl::api::command::get_dynamic_rendering_tile_properties_qcom};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::sec_amigo_profiling >
{
    static constexpr std::string_view      raw_name    = "VK_SEC_amigo_profiling";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_surface_maintenance_1 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_surface_maintenance1";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_3,
              true,
              2,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2}},
             {ktl::api::version_1_4,
              true,
              2,
              {ktl::api::extension::khr_surface, ktl::api::extension::khr_get_surface_capabilities_2}}}};
};

template <>
struct extension< ktl::api::extension::khr_swapchain_maintenance_1 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_swapchain_maintenance1";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::release_swapchain_images_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          3,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_surface_maintenance_1,
           ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_surface_maintenance_1}},
         {ktl::api::version_1_2,
          true,
          2,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_surface_maintenance_1}},
         {ktl::api::version_1_3,
          true,
          2,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_surface_maintenance_1}},
         {ktl::api::version_1_4,
          true,
          2,
          {ktl::api::extension::khr_swapchain, ktl::api::extension::khr_surface_maintenance_1}}}};
};

template <>
struct extension< ktl::api::extension::qcom_multiview_per_view_viewports >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_multiview_per_view_viewports";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_external_sci_sync_2 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_external_sci_sync2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 7 > commands = {
        ktl::api::command::create_semaphore_sci_sync_pool_nv,
        ktl::api::command::destroy_semaphore_sci_sync_pool_nv,
        ktl::api::command::get_fence_sci_sync_fence_nv,
        ktl::api::command::get_fence_sci_sync_obj_nv,
        ktl::api::command::import_fence_sci_sync_fence_nv,
        ktl::api::command::import_fence_sci_sync_obj_nv,
        ktl::api::command::get_physical_device_sci_sync_attributes_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {{{ktl::api::version_1_0, false, 1, {}},
                                                                       {ktl::api::version_1_1, true, 0, {}},
                                                                       {ktl::api::version_1_2, true, 0, {}},
                                                                       {ktl::api::version_1_3, true, 0, {}},
                                                                       {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_ray_tracing_invocation_reorder >
{
    static constexpr std::string_view      raw_name    = "VK_NV_ray_tracing_invocation_reorder";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::ext_ray_tracing_invocation_reorder};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}}}};
};

template <>
struct extension< ktl::api::extension::nv_cooperative_vector >
{
    static constexpr std::string_view      raw_name    = "VK_NV_cooperative_vector";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::get_physical_device_cooperative_vector_properties_nv,
        ktl::api::command::convert_cooperative_vector_matrix_nv,
        ktl::api::command::cmd_convert_cooperative_vector_matrix_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_extended_sparse_address_space >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extended_sparse_address_space";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_494 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_494";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_mutable_descriptor_type >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_mutable_descriptor_type";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_maintenance_3}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_legacy_vertex_attributes >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_legacy_vertex_attributes";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_vertex_input_dynamic_state}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_vertex_input_dynamic_state}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_vertex_input_dynamic_state}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_vertex_input_dynamic_state}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_vertex_input_dynamic_state}}}};
};

template <>
struct extension< ktl::api::extension::ext_layer_settings >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_layer_settings";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_shader_core_builtins >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_shader_core_builtins";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_pipeline_library_group_handles >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_pipeline_library_group_handles";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_ray_tracing_pipeline, ktl::api::extension::khr_pipeline_library}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_ray_tracing_pipeline, ktl::api::extension::khr_pipeline_library}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::khr_ray_tracing_pipeline, ktl::api::extension::khr_pipeline_library}},
             {ktl::api::version_1_3,
              true,
              2,
              {ktl::api::extension::khr_ray_tracing_pipeline, ktl::api::extension::khr_pipeline_library}},
             {ktl::api::version_1_4,
              true,
              2,
              {ktl::api::extension::khr_ray_tracing_pipeline, ktl::api::extension::khr_pipeline_library}}}};
};

template <>
struct extension< ktl::api::extension::ext_dynamic_rendering_unused_attachments >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_dynamic_rendering_unused_attachments";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_dynamic_rendering}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_dynamic_rendering}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_dynamic_rendering}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_501 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_501";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_502 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_502";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_503 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_503";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_extension_504 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_504";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_internally_synchronized_queues >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_internally_synchronized_queues";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, true, 0, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_low_latency_2 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_low_latency2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 5 > commands = {
        ktl::api::command::set_latency_sleep_mode_nv, ktl::api::command::latency_sleep_nv,
        ktl::api::command::set_latency_marker_nv, ktl::api::command::get_latency_timings_nv,
        ktl::api::command::queue_notify_out_of_band_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_timeline_semaphore, ktl::api::extension::khr_present_id}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_timeline_semaphore, ktl::api::extension::khr_present_id}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_present_id}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_present_id}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_present_id}}}};
};

template <>
struct extension< ktl::api::extension::khr_cooperative_matrix >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_cooperative_matrix";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_physical_device_cooperative_matrix_properties_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::arm_data_graph >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_data_graph";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 11 > commands = {
        ktl::api::command::create_data_graph_pipelines_arm,
        ktl::api::command::create_data_graph_pipeline_session_arm,
        ktl::api::command::get_data_graph_pipeline_session_bind_point_requirements_arm,
        ktl::api::command::get_data_graph_pipeline_session_memory_requirements_arm,
        ktl::api::command::bind_data_graph_pipeline_session_memory_arm,
        ktl::api::command::destroy_data_graph_pipeline_session_arm,
        ktl::api::command::cmd_dispatch_data_graph_arm,
        ktl::api::command::get_data_graph_pipeline_available_properties_arm,
        ktl::api::command::get_data_graph_pipeline_properties_arm,
        ktl::api::command::get_physical_device_queue_family_data_graph_properties_arm,
        ktl::api::command::get_physical_device_queue_family_data_graph_processing_engine_properties_arm};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, false, 1, {}},
         {ktl::api::version_1_1, false, 1, {}},
         {ktl::api::version_1_2, false, 1, {}},
         {ktl::api::version_1_3,
          true,
          2,
          {ktl::api::extension::khr_maintenance_5, ktl::api::extension::khr_deferred_host_operations}},
         {ktl::api::version_1_4,
          true,
          2,
          {ktl::api::extension::khr_maintenance_5, ktl::api::extension::khr_deferred_host_operations}}}};
};

template <>
struct extension< ktl::api::extension::arm_data_graph_instruction_set_tosa >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_data_graph_instruction_set_tosa";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_physical_device_queue_family_data_graph_engine_operation_properties_arm};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::arm_data_graph}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::arm_data_graph}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::arm_data_graph}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::arm_data_graph}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::arm_data_graph}}}};
};

template <>
struct extension< ktl::api::extension::mesa_extension_510 >
{
    static constexpr std::string_view      raw_name    = "VK_MESA_extension_510";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::qcom_multiview_per_view_render_areas >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_multiview_per_view_render_areas";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_compute_shader_derivatives >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_compute_shader_derivatives";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_per_stage_descriptor_set >
{
    static constexpr std::string_view      raw_name    = "VK_NV_per_stage_descriptor_set";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_maintenance_6}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_maintenance_6}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_maintenance_6}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_maintenance_6}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::mesa_extension_518 >
{
    static constexpr std::string_view      raw_name    = "VK_MESA_extension_518";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::qcom_image_processing_2 >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_image_processing2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::qcom_image_processing}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::qcom_image_processing}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::qcom_image_processing}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::qcom_image_processing}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::qcom_image_processing}}}};
};

template <>
struct extension< ktl::api::extension::qcom_filter_cubic_weights >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_filter_cubic_weights";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_filter_cubic}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_filter_cubic}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_filter_cubic}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_filter_cubic}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_filter_cubic}}}};
};

template <>
struct extension< ktl::api::extension::qcom_ycbcr_degamma >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_ycbcr_degamma";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_filter_cubic_clamp >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_filter_cubic_clamp";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::ext_filter_cubic, ktl::api::extension::ext_sampler_filter_minmax}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::ext_filter_cubic, ktl::api::extension::ext_sampler_filter_minmax}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_filter_cubic}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_filter_cubic}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_filter_cubic}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_523 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_523";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_524 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_524";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_attachment_feedback_loop_dynamic_state >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_attachment_feedback_loop_dynamic_state";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::cmd_set_attachment_feedback_loop_enable_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2,
           ktl::api::extension::ext_attachment_feedback_loop_layout}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_attachment_feedback_loop_layout}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_attachment_feedback_loop_layout}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_attachment_feedback_loop_layout}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_attachment_feedback_loop_layout}}}};
};

template <>
struct extension< ktl::api::extension::khr_vertex_attribute_divisor >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_vertex_attribute_divisor";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_load_store_op_none >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_load_store_op_none";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_unified_image_layouts >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_unified_image_layouts";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_float_controls_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_float_controls2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, false, 1, {}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_shader_float_controls}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_shader_float_controls}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_shader_float_controls}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_shader_float_controls}}}};
};

template <>
struct extension< ktl::api::extension::qnx_external_memory_screen_buffer >
{
    static constexpr std::string_view      raw_name    = "VK_QNX_external_memory_screen_buffer";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_screen_buffer_properties_qnx};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          4,
          {ktl::api::extension::khr_sampler_ycbcr_conversion, ktl::api::extension::khr_external_memory,
           ktl::api::extension::khr_dedicated_allocation, ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_queue_family_foreign}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_queue_family_foreign}}}};
};

template <>
struct extension< ktl::api::extension::msft_layered_driver >
{
    static constexpr std::string_view      raw_name    = "VK_MSFT_layered_driver";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_532 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_532";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_533 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_533";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_index_type_uint_8 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_index_type_uint8";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_line_rasterization >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_line_rasterization";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::cmd_set_line_stipple_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_extension_536 >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_extension_536";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_537 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_537";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_538 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_538";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_539 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_539";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_540 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_540";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_541 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_541";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_542 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_542";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_543 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_543";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_calibrated_timestamps >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_calibrated_timestamps";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_physical_device_calibrateable_time_domains_khr,
        ktl::api::command::get_calibrated_timestamps_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_shader_expect_assume >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_expect_assume";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_maintenance_6 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_maintenance6";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::version_1_4};

    static constexpr std::array< ktl::api::command, 6 > commands = {
        ktl::api::command::cmd_bind_descriptor_sets_2khr,
        ktl::api::command::cmd_push_constants_2khr,
        ktl::api::command::cmd_push_descriptor_set_2khr,
        ktl::api::command::cmd_push_descriptor_set_with_template_2khr,
        ktl::api::command::cmd_set_descriptor_buffer_offsets_2ext,
        ktl::api::command::cmd_bind_descriptor_buffer_embedded_samplers_2ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {{{ktl::api::version_1_0, false, 1, {}},
                                                                       {ktl::api::version_1_1, true, 0, {}},
                                                                       {ktl::api::version_1_2, true, 0, {}},
                                                                       {ktl::api::version_1_3, true, 0, {}},
                                                                       {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_descriptor_pool_overallocation >
{
    static constexpr std::string_view      raw_name    = "VK_NV_descriptor_pool_overallocation";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, true, 0, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_tile_memory_heap >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_tile_memory_heap";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::cmd_bind_tile_memory_qcom};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_memory_requirements_2,
               ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_549 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_549";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_copy_memory_indirect >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_copy_memory_indirect";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_copy_memory_indirect_khr, ktl::api::command::cmd_copy_memory_to_image_indirect_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_memory_decompression >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_memory_decompression";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::cmd_decompress_memory_ext, ktl::api::command::cmd_decompress_memory_indirect_count_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_2,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_3,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_buffer_device_address}},
         {ktl::api::version_1_4,
          true,
          2,
          {ktl::api::extension::khr_get_physical_device_properties_2,
           ktl::api::extension::khr_buffer_device_address}}}};
};

template <>
struct extension< ktl::api::extension::nv_display_stereo >
{
    static constexpr std::string_view      raw_name    = "VK_NV_display_stereo";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_display, ktl::api::extension::khr_get_display_properties_2}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_display, ktl::api::extension::khr_get_display_properties_2}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::khr_display, ktl::api::extension::khr_get_display_properties_2}},
             {ktl::api::version_1_3,
              true,
              2,
              {ktl::api::extension::khr_display, ktl::api::extension::khr_get_display_properties_2}},
             {ktl::api::version_1_4,
              true,
              2,
              {ktl::api::extension::khr_display, ktl::api::extension::khr_get_display_properties_2}}}};
};

template <>
struct extension< ktl::api::extension::img_extension_555 >
{
    static constexpr std::string_view      raw_name    = "VK_IMG_extension_555";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_raw_access_chains >
{
    static constexpr std::string_view      raw_name    = "VK_NV_raw_access_chains";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_external_compute_queue >
{
    static constexpr std::string_view      raw_name    = "VK_NV_external_compute_queue";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {
        ktl::api::command::create_external_compute_queue_nv, ktl::api::command::destroy_external_compute_queue_nv,
        ktl::api::command::get_external_compute_queue_data_nv};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_558 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_558";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_shader_relaxed_extended_instruction >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_relaxed_extended_instruction";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_command_buffer_inheritance >
{
    static constexpr std::string_view      raw_name    = "VK_NV_command_buffer_inheritance";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_561 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_561";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_562 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_562";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_maintenance_7 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_maintenance7";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, true, 0, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_shader_atomic_float_16vector >
{
    static constexpr std::string_view      raw_name    = "VK_NV_shader_atomic_float16_vector";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_shader_replicated_composites >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_replicated_composites";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::arm_extension_566 >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_extension_566";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_extension_567 >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_extension_567";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_shader_float_8 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_float8";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_ray_tracing_validation >
{
    static constexpr std::string_view      raw_name    = "VK_NV_ray_tracing_validation";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_cluster_acceleration_structure >
{
    static constexpr std::string_view      raw_name    = "VK_NV_cluster_acceleration_structure";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_cluster_acceleration_structure_build_sizes_nv,
        ktl::api::command::cmd_build_cluster_acceleration_structure_indirect_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_acceleration_structure}}}};
};

template <>
struct extension< ktl::api::extension::nv_partitioned_acceleration_structure >
{
    static constexpr std::string_view      raw_name    = "VK_NV_partitioned_acceleration_structure";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_partitioned_acceleration_structures_build_sizes_nv,
        ktl::api::command::cmd_build_partitioned_acceleration_structures_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_acceleration_structure}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_acceleration_structure}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_572 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_572";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_device_generated_commands >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_device_generated_commands";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 9 > commands = {
        ktl::api::command::get_generated_commands_memory_requirements_ext,
        ktl::api::command::cmd_preprocess_generated_commands_ext,
        ktl::api::command::cmd_execute_generated_commands_ext,
        ktl::api::command::create_indirect_commands_layout_ext,
        ktl::api::command::destroy_indirect_commands_layout_ext,
        ktl::api::command::create_indirect_execution_set_ext,
        ktl::api::command::destroy_indirect_execution_set_ext,
        ktl::api::command::update_indirect_execution_set_pipeline_ext,
        ktl::api::command::update_indirect_execution_set_shader_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0,
          true,
          2,
          {ktl::api::extension::khr_buffer_device_address, ktl::api::extension::khr_maintenance_5}},
         {ktl::api::version_1_1,
          true,
          2,
          {ktl::api::extension::khr_buffer_device_address, ktl::api::extension::khr_maintenance_5}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_maintenance_5}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_device_fault >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_device_fault";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands   = {ktl::api::command::get_device_fault_reports_khr,
                                                                      ktl::api::command::get_device_fault_debug_info_khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_maintenance_8 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_maintenance8";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, true, 0, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::mesa_image_alignment_control >
{
    static constexpr std::string_view      raw_name    = "VK_MESA_image_alignment_control";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::huawei_extension_577 >
{
    static constexpr std::string_view      raw_name    = "VK_HUAWEI_extension_577";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_578 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_578";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_579 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_579";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_shader_fma >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_shader_fma";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_push_constant_bank >
{
    static constexpr std::string_view      raw_name    = "VK_NV_push_constant_bank";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_ray_tracing_invocation_reorder >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_ray_tracing_invocation_reorder";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_ray_tracing_pipeline}}}};
};

template <>
struct extension< ktl::api::extension::ext_depth_clamp_control >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_depth_clamp_control";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::cmd_set_depth_clamp_range_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_584 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_584";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_maintenance_9 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_maintenance9";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::img_extension_586 >
{
    static constexpr std::string_view      raw_name    = "VK_IMG_extension_586";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ohos_surface >
{
    static constexpr std::string_view      raw_name    = "VK_OHOS_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::create_surface_ohos};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::huawei_extension_686 >
{
    static constexpr std::string_view      raw_name    = "VK_HUAWEI_extension_686";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ohos_native_buffer >
{
    static constexpr std::string_view      raw_name    = "VK_OHOS_native_buffer";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 3 > commands = {ktl::api::command::get_swapchain_gralloc_usage_ohos,
                                                                    ktl::api::command::acquire_image_ohos,
                                                                    ktl::api::command::queue_signal_release_image_ohos};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps = {};
};

template <>
struct extension< ktl::api::extension::huawei_extension_590 >
{
    static constexpr std::string_view      raw_name    = "VK_HUAWEI_extension_590";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::huawei_hdr_vivid >
{
    static constexpr std::string_view      raw_name    = "VK_HUAWEI_hdr_vivid";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              3,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_swapchain,
               ktl::api::extension::ext_hdr_metadata}},
             {ktl::api::version_1_1, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::ext_hdr_metadata}},
             {ktl::api::version_1_2, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::ext_hdr_metadata}},
             {ktl::api::version_1_3, true, 2, {ktl::api::extension::khr_swapchain, ktl::api::extension::ext_hdr_metadata}},
             {ktl::api::version_1_4,
              true,
              2,
              {ktl::api::extension::khr_swapchain, ktl::api::extension::ext_hdr_metadata}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_592 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_592";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_extension_593 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_593";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_cooperative_matrix_2 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_cooperative_matrix2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::get_physical_device_cooperative_matrix_flexible_dimensions_properties_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_cooperative_matrix}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_cooperative_matrix}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_cooperative_matrix}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_cooperative_matrix}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_cooperative_matrix}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_595 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_595";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_596 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_596";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_pipeline_opacity_micromap >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_pipeline_opacity_micromap";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::ext_opacity_micromap}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::ext_opacity_micromap}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::ext_opacity_micromap}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_opacity_micromap}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_opacity_micromap}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_598 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_598";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_599 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_599";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::img_extension_600 >
{
    static constexpr std::string_view      raw_name    = "VK_IMG_extension_600";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::img_extension_601 >
{
    static constexpr std::string_view      raw_name    = "VK_IMG_extension_601";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_602 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_602";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_external_memory_metal >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_external_memory_metal";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_memory_metal_handle_ext, ktl::api::command::get_memory_metal_handle_properties_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_external_memory}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_604 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_604";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_depth_clamp_zero_one >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_depth_clamp_zero_one";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::arm_performance_counters_by_region >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_performance_counters_by_region";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::enumerate_physical_device_queue_family_performance_counters_by_region_arm};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_607 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_607";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_shader_instrumentation >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_shader_instrumentation";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 7 > commands = {
        ktl::api::command::enumerate_physical_device_shader_instrumentation_metrics_arm,
        ktl::api::command::create_shader_instrumentation_arm,
        ktl::api::command::destroy_shader_instrumentation_arm,
        ktl::api::command::cmd_begin_shader_instrumentation_arm,
        ktl::api::command::cmd_end_shader_instrumentation_arm,
        ktl::api::command::get_shader_instrumentation_values_arm,
        ktl::api::command::clear_shader_instrumentation_metrics_arm};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_vertex_attribute_robustness >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_vertex_attribute_robustness";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {ktl::api::extension::khr_maintenance_9};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::arm_format_pack >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_format_pack";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_extension_611 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_611";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::valve_fragment_density_map_layered >
{
    static constexpr std::string_view      raw_name    = "VK_VALVE_fragment_density_map_layered";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_maintenance_5, ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_maintenance_5, ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::khr_maintenance_5, ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_3,
              true,
              2,
              {ktl::api::extension::khr_maintenance_5, ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_fragment_density_map}}}};
};

template <>
struct extension< ktl::api::extension::khr_robustness_2 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_robustness2";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::nv_present_metering >
{
    static constexpr std::string_view      raw_name    = "VK_NV_present_metering";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_extension_615 >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_extension_615";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_616 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_616";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_617 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_617";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_618 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_618";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_fragment_density_map_offset >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_fragment_density_map_offset";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::cmd_end_rendering_2ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              4,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::ext_fragment_density_map,
               ktl::api::extension::khr_create_renderpass_2, ktl::api::extension::khr_dynamic_rendering}},
             {ktl::api::version_1_1,
              true,
              3,
              {ktl::api::extension::ext_fragment_density_map, ktl::api::extension::khr_create_renderpass_2,
               ktl::api::extension::khr_dynamic_rendering}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::ext_fragment_density_map, ktl::api::extension::khr_dynamic_rendering}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::ext_fragment_density_map}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::ext_fragment_density_map}}}};
};

template <>
struct extension< ktl::api::extension::ext_zero_initialize_device_memory >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_zero_initialize_device_memory";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_present_mode_fifo_latest_ready >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_present_mode_fifo_latest_ready";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_swapchain}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_swapchain}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_623 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_623";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_opacity_micromap >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_opacity_micromap";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_device_address_commands}},
             {ktl::api::version_1_1,
              true,
              2,
              {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_device_address_commands}},
             {ktl::api::version_1_2,
              true,
              2,
              {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_device_address_commands}},
             {ktl::api::version_1_3,
              true,
              2,
              {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_device_address_commands}},
             {ktl::api::version_1_4,
              true,
              2,
              {ktl::api::extension::khr_acceleration_structure, ktl::api::extension::khr_device_address_commands}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_625 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_625";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_626 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_626";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_extension_627 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_627";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_shader_64bit_indexing >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_64bit_indexing";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_custom_resolve >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_custom_resolve";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands   = {ktl::api::command::cmd_begin_custom_resolve_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::qcom_data_graph_model >
{
    static constexpr std::string_view      raw_name    = "VK_QCOM_data_graph_model";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::arm_data_graph}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::arm_data_graph}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::arm_data_graph}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::arm_data_graph}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::arm_data_graph}}}};
};

template <>
struct extension< ktl::api::extension::khr_maintenance_10 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_maintenance10";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 >       commands = {ktl::api::command::cmd_end_rendering_2khr};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::arm_data_graph_optical_flow >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_data_graph_optical_flow";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::get_physical_device_queue_family_data_graph_optical_flow_image_formats_arm,
        ktl::api::command::get_physical_device_queue_family_data_graph_engine_operation_properties_arm};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::arm_data_graph}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::arm_data_graph}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::arm_data_graph}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::arm_data_graph}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::arm_data_graph}}}};
};

template <>
struct extension< ktl::api::extension::mtk_extension_633 >
{
    static constexpr std::string_view      raw_name    = "VK_MTK_extension_633";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_extension_634 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_634";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::mtk_extension_635 >
{
    static constexpr std::string_view      raw_name    = "VK_MTK_extension_635";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_shader_long_vector >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_long_vector";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {{{ktl::api::version_1_0, false, 1, {}},
                                                                           {ktl::api::version_1_1, false, 1, {}},
                                                                           {ktl::api::version_1_2, true, 0, {}},
                                                                           {ktl::api::version_1_3, true, 0, {}},
                                                                           {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_637 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_637";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::sec_pipeline_cache_incremental_mode >
{
    static constexpr std::string_view      raw_name    = "VK_SEC_pipeline_cache_incremental_mode";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_639 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_639";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_extension_640 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_640";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_641 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_641";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_642 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_642";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_shader_uniform_buffer_unsized_array >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_uniform_buffer_unsized_array";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_644 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_644";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_645 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_645";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_compute_occupancy_priority >
{
    static constexpr std::string_view      raw_name    = "VK_NV_compute_occupancy_priority";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::cmd_set_compute_occupancy_priority_nv};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::khr_extension_647 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_647";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_648 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_648";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_649 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_649";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_650 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_650";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_651 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_651";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_652 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_652";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_653 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_653";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::valve_extension_654 >
{
    static constexpr std::string_view      raw_name    = "VK_VALVE_extension_654";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_extension_655 >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_extension_655";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_extension_656 >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_extension_656";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_extension_657 >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_extension_657";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_maintenance_11 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_maintenance11";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::arm_extension_659 >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_extension_659";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_660 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_660";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_661 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_661";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::valve_extension_662 >
{
    static constexpr std::string_view      raw_name    = "VK_VALVE_extension_662";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_shader_subgroup_partitioned >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_shader_subgroup_partitioned";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
             {ktl::api::version_1_1, true, 0, {}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_664 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_664";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::sec_ubm_surface >
{
    static constexpr std::string_view      raw_name    = "VK_SEC_ubm_surface";
    static constexpr bool                  is_instance = true;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 2 > commands = {
        ktl::api::command::create_ubm_surface_sec, ktl::api::command::get_physical_device_ubm_presentation_support_sec};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_2, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_3, true, 1, {ktl::api::extension::khr_surface}},
         {ktl::api::version_1_4, true, 1, {ktl::api::extension::khr_surface}}}};
};

template <>
struct extension< ktl::api::extension::google_extension_666 >
{
    static constexpr std::string_view      raw_name    = "VK_GOOGLE_extension_666";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::huawei_extension_667 >
{
    static constexpr std::string_view      raw_name    = "VK_HUAWEI_extension_667";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_extension_668 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_668";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_669 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_669";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_extension_670 >
{
    static constexpr std::string_view      raw_name    = "VK_NV_extension_670";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_extension_671 >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_extension_671";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_672 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_672";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_673 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_673";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::valve_shader_mixed_float_dot_product >
{
    static constexpr std::string_view      raw_name    = "VK_VALVE_shader_mixed_float_dot_product";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0,
              true,
              2,
              {ktl::api::extension::khr_get_physical_device_properties_2, ktl::api::extension::khr_shader_float_16int_8}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::khr_shader_float_16int_8}},
             {ktl::api::version_1_2, true, 0, {}},
             {ktl::api::version_1_3, true, 0, {}},
             {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::sec_throttle_hint >
{
    static constexpr std::string_view      raw_name    = "VK_SEC_throttle_hint";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_676 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_676";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::arm_data_graph_neural_accelerator_statistics >
{
    static constexpr std::string_view      raw_name    = "VK_ARM_data_graph_neural_accelerator_statistics";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_678 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_678";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_primitive_restart_index >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_primitive_restart_index";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 1 > commands = {
        ktl::api::command::cmd_set_primitive_restart_index_ext};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::khr_get_physical_device_properties_2}},
         {ktl::api::version_1_1, true, 0, {}},
         {ktl::api::version_1_2, true, 0, {}},
         {ktl::api::version_1_3, true, 0, {}},
         {ktl::api::version_1_4, true, 0, {}}}};
};

template <>
struct extension< ktl::api::extension::ext_extension_680 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_680";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::khr_extension_681 >
{
    static constexpr std::string_view      raw_name    = "VK_KHR_extension_681";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::valve_extension_682 >
{
    static constexpr std::string_view      raw_name    = "VK_VALVE_extension_682";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_683 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_683";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_684 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_684";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_685 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_685";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_687 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_687";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_688 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_688";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::amd_extension_689 >
{
    static constexpr std::string_view      raw_name    = "VK_AMD_extension_689";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::nv_cooperative_matrix_decode_vector >
{
    static constexpr std::string_view      raw_name    = "VK_NV_cooperative_matrix_decode_vector";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 5 > deps     = {
        {{ktl::api::version_1_0, true, 1, {ktl::api::extension::nv_cooperative_matrix_2}},
             {ktl::api::version_1_1, true, 1, {ktl::api::extension::nv_cooperative_matrix_2}},
             {ktl::api::version_1_2, true, 1, {ktl::api::extension::nv_cooperative_matrix_2}},
             {ktl::api::version_1_3, true, 1, {ktl::api::extension::nv_cooperative_matrix_2}},
             {ktl::api::version_1_4, true, 1, {ktl::api::extension::nv_cooperative_matrix_2}}}};
};

template <>
struct extension< ktl::api::extension::mesa_fragment_coverage_mask >
{
    static constexpr std::string_view      raw_name    = "VK_MESA_fragment_coverage_mask";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_692 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_692";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

template <>
struct extension< ktl::api::extension::ext_extension_693 >
{
    static constexpr std::string_view      raw_name    = "VK_EXT_extension_693";
    static constexpr bool                  is_instance = false;
    static constexpr ktl::meta::dependency promoted    = {};

    static constexpr std::array< ktl::api::command, 0 >       commands = {};
    static constexpr std::array< ktl::meta::version_deps, 0 > deps     = {};
};

inline constexpr ktl::api::extension
extension_from_raw(std::string_view _extension)
{
    if (_extension == "VK_KHR_surface")
    {
        return ktl::api::extension::khr_surface;
    }
    if (_extension == "VK_KHR_swapchain")
    {
        return ktl::api::extension::khr_swapchain;
    }
    if (_extension == "VK_KHR_display")
    {
        return ktl::api::extension::khr_display;
    }
    if (_extension == "VK_KHR_display_swapchain")
    {
        return ktl::api::extension::khr_display_swapchain;
    }
    if (_extension == "VK_KHR_xlib_surface")
    {
        return ktl::api::extension::khr_xlib_surface;
    }
    if (_extension == "VK_KHR_xcb_surface")
    {
        return ktl::api::extension::khr_xcb_surface;
    }
    if (_extension == "VK_KHR_wayland_surface")
    {
        return ktl::api::extension::khr_wayland_surface;
    }
    if (_extension == "VK_KHR_mir_surface")
    {
        return ktl::api::extension::khr_mir_surface;
    }
    if (_extension == "VK_KHR_android_surface")
    {
        return ktl::api::extension::khr_android_surface;
    }
    if (_extension == "VK_KHR_win32_surface")
    {
        return ktl::api::extension::khr_win_32surface;
    }
    if (_extension == "VK_ANDROID_native_buffer")
    {
        return ktl::api::extension::android_native_buffer;
    }
    if (_extension == "VK_EXT_debug_report")
    {
        return ktl::api::extension::ext_debug_report;
    }
    if (_extension == "VK_NV_glsl_shader")
    {
        return ktl::api::extension::nv_glsl_shader;
    }
    if (_extension == "VK_EXT_depth_range_unrestricted")
    {
        return ktl::api::extension::ext_depth_range_unrestricted;
    }
    if (_extension == "VK_KHR_sampler_mirror_clamp_to_edge")
    {
        return ktl::api::extension::khr_sampler_mirror_clamp_to_edge;
    }
    if (_extension == "VK_IMG_filter_cubic")
    {
        return ktl::api::extension::img_filter_cubic;
    }
    if (_extension == "VK_AMD_extension_17")
    {
        return ktl::api::extension::amd_extension_17;
    }
    if (_extension == "VK_AMD_extension_18")
    {
        return ktl::api::extension::amd_extension_18;
    }
    if (_extension == "VK_AMD_rasterization_order")
    {
        return ktl::api::extension::amd_rasterization_order;
    }
    if (_extension == "VK_AMD_extension_20")
    {
        return ktl::api::extension::amd_extension_20;
    }
    if (_extension == "VK_AMD_shader_trinary_minmax")
    {
        return ktl::api::extension::amd_shader_trinary_minmax;
    }
    if (_extension == "VK_AMD_shader_explicit_vertex_parameter")
    {
        return ktl::api::extension::amd_shader_explicit_vertex_parameter;
    }
    if (_extension == "VK_EXT_debug_marker")
    {
        return ktl::api::extension::ext_debug_marker;
    }
    if (_extension == "VK_KHR_video_queue")
    {
        return ktl::api::extension::khr_video_queue;
    }
    if (_extension == "VK_AMD_gcn_shader")
    {
        return ktl::api::extension::amd_gcn_shader;
    }
    if (_extension == "VK_NV_dedicated_allocation")
    {
        return ktl::api::extension::nv_dedicated_allocation;
    }
    if (_extension == "VK_EXT_extension_28")
    {
        return ktl::api::extension::ext_extension_28;
    }
    if (_extension == "VK_EXT_transform_feedback")
    {
        return ktl::api::extension::ext_transform_feedback;
    }
    if (_extension == "VK_NVX_binary_import")
    {
        return ktl::api::extension::nvx_binary_import;
    }
    if (_extension == "VK_NVX_image_view_handle")
    {
        return ktl::api::extension::nvx_image_view_handle;
    }
    if (_extension == "VK_AMD_extension_32")
    {
        return ktl::api::extension::amd_extension_32;
    }
    if (_extension == "VK_AMD_extension_33")
    {
        return ktl::api::extension::amd_extension_33;
    }
    if (_extension == "VK_AMD_draw_indirect_count")
    {
        return ktl::api::extension::amd_draw_indirect_count;
    }
    if (_extension == "VK_AMD_extension_35")
    {
        return ktl::api::extension::amd_extension_35;
    }
    if (_extension == "VK_AMD_negative_viewport_height")
    {
        return ktl::api::extension::amd_negative_viewport_height;
    }
    if (_extension == "VK_AMD_gpu_shader_half_float")
    {
        return ktl::api::extension::amd_gpu_shader_half_float;
    }
    if (_extension == "VK_AMD_shader_ballot")
    {
        return ktl::api::extension::amd_shader_ballot;
    }
    if (_extension == "VK_AMD_texture_gather_bias_lod")
    {
        return ktl::api::extension::amd_texture_gather_bias_lod;
    }
    if (_extension == "VK_AMD_shader_info")
    {
        return ktl::api::extension::amd_shader_info;
    }
    if (_extension == "VK_AMD_extension_44")
    {
        return ktl::api::extension::amd_extension_44;
    }
    if (_extension == "VK_KHR_dynamic_rendering")
    {
        return ktl::api::extension::khr_dynamic_rendering;
    }
    if (_extension == "VK_AMD_extension_46")
    {
        return ktl::api::extension::amd_extension_46;
    }
    if (_extension == "VK_AMD_shader_image_load_store_lod")
    {
        return ktl::api::extension::amd_shader_image_load_store_lod;
    }
    if (_extension == "VK_NVX_extension_48")
    {
        return ktl::api::extension::nvx_extension_48;
    }
    if (_extension == "VK_GOOGLE_extension_49")
    {
        return ktl::api::extension::google_extension_49;
    }
    if (_extension == "VK_GGP_stream_descriptor_surface")
    {
        return ktl::api::extension::ggp_stream_descriptor_surface;
    }
    if (_extension == "VK_NV_corner_sampled_image")
    {
        return ktl::api::extension::nv_corner_sampled_image;
    }
    if (_extension == "VK_NV_private_vendor_info")
    {
        return ktl::api::extension::nv_private_vendor_info;
    }
    if (_extension == "VK_NV_extension_53")
    {
        return ktl::api::extension::nv_extension_53;
    }
    if (_extension == "VK_KHR_multiview")
    {
        return ktl::api::extension::khr_multiview;
    }
    if (_extension == "VK_IMG_format_pvrtc")
    {
        return ktl::api::extension::img_format_pvrtc;
    }
    if (_extension == "VK_NV_external_memory_capabilities")
    {
        return ktl::api::extension::nv_external_memory_capabilities;
    }
    if (_extension == "VK_NV_external_memory")
    {
        return ktl::api::extension::nv_external_memory;
    }
    if (_extension == "VK_NV_external_memory_win32")
    {
        return ktl::api::extension::nv_external_memory_win_32;
    }
    if (_extension == "VK_NV_win32_keyed_mutex")
    {
        return ktl::api::extension::nv_win_32keyed_mutex;
    }
    if (_extension == "VK_KHR_get_physical_device_properties2")
    {
        return ktl::api::extension::khr_get_physical_device_properties_2;
    }
    if (_extension == "VK_KHR_device_group")
    {
        return ktl::api::extension::khr_device_group;
    }
    if (_extension == "VK_EXT_validation_flags")
    {
        return ktl::api::extension::ext_validation_flags;
    }
    if (_extension == "VK_NN_vi_surface")
    {
        return ktl::api::extension::nn_vi_surface;
    }
    if (_extension == "VK_KHR_shader_draw_parameters")
    {
        return ktl::api::extension::khr_shader_draw_parameters;
    }
    if (_extension == "VK_EXT_shader_subgroup_ballot")
    {
        return ktl::api::extension::ext_shader_subgroup_ballot;
    }
    if (_extension == "VK_EXT_shader_subgroup_vote")
    {
        return ktl::api::extension::ext_shader_subgroup_vote;
    }
    if (_extension == "VK_EXT_texture_compression_astc_hdr")
    {
        return ktl::api::extension::ext_texture_compression_astc_hdr;
    }
    if (_extension == "VK_EXT_astc_decode_mode")
    {
        return ktl::api::extension::ext_astc_decode_mode;
    }
    if (_extension == "VK_EXT_pipeline_robustness")
    {
        return ktl::api::extension::ext_pipeline_robustness;
    }
    if (_extension == "VK_KHR_maintenance1")
    {
        return ktl::api::extension::khr_maintenance_1;
    }
    if (_extension == "VK_KHR_device_group_creation")
    {
        return ktl::api::extension::khr_device_group_creation;
    }
    if (_extension == "VK_KHR_external_memory_capabilities")
    {
        return ktl::api::extension::khr_external_memory_capabilities;
    }
    if (_extension == "VK_KHR_external_memory")
    {
        return ktl::api::extension::khr_external_memory;
    }
    if (_extension == "VK_KHR_external_memory_win32")
    {
        return ktl::api::extension::khr_external_memory_win_32;
    }
    if (_extension == "VK_KHR_external_memory_fd")
    {
        return ktl::api::extension::khr_external_memory_fd;
    }
    if (_extension == "VK_KHR_win32_keyed_mutex")
    {
        return ktl::api::extension::khr_win_32keyed_mutex;
    }
    if (_extension == "VK_KHR_external_semaphore_capabilities")
    {
        return ktl::api::extension::khr_external_semaphore_capabilities;
    }
    if (_extension == "VK_KHR_external_semaphore")
    {
        return ktl::api::extension::khr_external_semaphore;
    }
    if (_extension == "VK_KHR_external_semaphore_win32")
    {
        return ktl::api::extension::khr_external_semaphore_win_32;
    }
    if (_extension == "VK_KHR_external_semaphore_fd")
    {
        return ktl::api::extension::khr_external_semaphore_fd;
    }
    if (_extension == "VK_KHR_push_descriptor")
    {
        return ktl::api::extension::khr_push_descriptor;
    }
    if (_extension == "VK_EXT_conditional_rendering")
    {
        return ktl::api::extension::ext_conditional_rendering;
    }
    if (_extension == "VK_KHR_shader_float16_int8")
    {
        return ktl::api::extension::khr_shader_float_16int_8;
    }
    if (_extension == "VK_KHR_16bit_storage")
    {
        return ktl::api::extension::khr_16bit_storage;
    }
    if (_extension == "VK_KHR_incremental_present")
    {
        return ktl::api::extension::khr_incremental_present;
    }
    if (_extension == "VK_KHR_descriptor_update_template")
    {
        return ktl::api::extension::khr_descriptor_update_template;
    }
    if (_extension == "VK_NVX_device_generated_commands")
    {
        return ktl::api::extension::nvx_device_generated_commands;
    }
    if (_extension == "VK_NV_clip_space_w_scaling")
    {
        return ktl::api::extension::nv_clip_space_w_scaling;
    }
    if (_extension == "VK_EXT_direct_mode_display")
    {
        return ktl::api::extension::ext_direct_mode_display;
    }
    if (_extension == "VK_EXT_acquire_xlib_display")
    {
        return ktl::api::extension::ext_acquire_xlib_display;
    }
    if (_extension == "VK_EXT_display_surface_counter")
    {
        return ktl::api::extension::ext_display_surface_counter;
    }
    if (_extension == "VK_EXT_display_control")
    {
        return ktl::api::extension::ext_display_control;
    }
    if (_extension == "VK_GOOGLE_display_timing")
    {
        return ktl::api::extension::google_display_timing;
    }
    if (_extension == "VK_RESERVED_do_not_use_94")
    {
        return ktl::api::extension::reserved_do_not_use_94;
    }
    if (_extension == "VK_NV_sample_mask_override_coverage")
    {
        return ktl::api::extension::nv_sample_mask_override_coverage;
    }
    if (_extension == "VK_NV_geometry_shader_passthrough")
    {
        return ktl::api::extension::nv_geometry_shader_passthrough;
    }
    if (_extension == "VK_NV_viewport_array2")
    {
        return ktl::api::extension::nv_viewport_array_2;
    }
    if (_extension == "VK_NVX_multiview_per_view_attributes")
    {
        return ktl::api::extension::nvx_multiview_per_view_attributes;
    }
    if (_extension == "VK_NV_viewport_swizzle")
    {
        return ktl::api::extension::nv_viewport_swizzle;
    }
    if (_extension == "VK_EXT_discard_rectangles")
    {
        return ktl::api::extension::ext_discard_rectangles;
    }
    if (_extension == "VK_NV_extension_101")
    {
        return ktl::api::extension::nv_extension_101;
    }
    if (_extension == "VK_EXT_conservative_rasterization")
    {
        return ktl::api::extension::ext_conservative_rasterization;
    }
    if (_extension == "VK_EXT_depth_clip_enable")
    {
        return ktl::api::extension::ext_depth_clip_enable;
    }
    if (_extension == "VK_NV_extension_104")
    {
        return ktl::api::extension::nv_extension_104;
    }
    if (_extension == "VK_EXT_swapchain_colorspace")
    {
        return ktl::api::extension::ext_swapchain_colorspace;
    }
    if (_extension == "VK_EXT_hdr_metadata")
    {
        return ktl::api::extension::ext_hdr_metadata;
    }
    if (_extension == "VK_IMG_extension_107")
    {
        return ktl::api::extension::img_extension_107;
    }
    if (_extension == "VK_IMG_extension_108")
    {
        return ktl::api::extension::img_extension_108;
    }
    if (_extension == "VK_KHR_imageless_framebuffer")
    {
        return ktl::api::extension::khr_imageless_framebuffer;
    }
    if (_extension == "VK_KHR_create_renderpass2")
    {
        return ktl::api::extension::khr_create_renderpass_2;
    }
    if (_extension == "VK_IMG_relaxed_line_rasterization")
    {
        return ktl::api::extension::img_relaxed_line_rasterization;
    }
    if (_extension == "VK_KHR_shared_presentable_image")
    {
        return ktl::api::extension::khr_shared_presentable_image;
    }
    if (_extension == "VK_KHR_external_fence_capabilities")
    {
        return ktl::api::extension::khr_external_fence_capabilities;
    }
    if (_extension == "VK_KHR_external_fence")
    {
        return ktl::api::extension::khr_external_fence;
    }
    if (_extension == "VK_KHR_external_fence_win32")
    {
        return ktl::api::extension::khr_external_fence_win_32;
    }
    if (_extension == "VK_KHR_external_fence_fd")
    {
        return ktl::api::extension::khr_external_fence_fd;
    }
    if (_extension == "VK_KHR_performance_query")
    {
        return ktl::api::extension::khr_performance_query;
    }
    if (_extension == "VK_KHR_maintenance2")
    {
        return ktl::api::extension::khr_maintenance_2;
    }
    if (_extension == "VK_KHR_extension_119")
    {
        return ktl::api::extension::khr_extension_119;
    }
    if (_extension == "VK_KHR_get_surface_capabilities2")
    {
        return ktl::api::extension::khr_get_surface_capabilities_2;
    }
    if (_extension == "VK_KHR_variable_pointers")
    {
        return ktl::api::extension::khr_variable_pointers;
    }
    if (_extension == "VK_KHR_get_display_properties2")
    {
        return ktl::api::extension::khr_get_display_properties_2;
    }
    if (_extension == "VK_MVK_ios_surface")
    {
        return ktl::api::extension::mvk_ios_surface;
    }
    if (_extension == "VK_MVK_macos_surface")
    {
        return ktl::api::extension::mvk_macos_surface;
    }
    if (_extension == "VK_MVK_moltenvk")
    {
        return ktl::api::extension::mvk_moltenvk;
    }
    if (_extension == "VK_EXT_external_memory_dma_buf")
    {
        return ktl::api::extension::ext_external_memory_dma_buf;
    }
    if (_extension == "VK_EXT_queue_family_foreign")
    {
        return ktl::api::extension::ext_queue_family_foreign;
    }
    if (_extension == "VK_KHR_dedicated_allocation")
    {
        return ktl::api::extension::khr_dedicated_allocation;
    }
    if (_extension == "VK_EXT_debug_utils")
    {
        return ktl::api::extension::ext_debug_utils;
    }
    if (_extension == "VK_ANDROID_external_memory_android_hardware_buffer")
    {
        return ktl::api::extension::android_external_memory_android_hardware_buffer;
    }
    if (_extension == "VK_EXT_sampler_filter_minmax")
    {
        return ktl::api::extension::ext_sampler_filter_minmax;
    }
    if (_extension == "VK_KHR_storage_buffer_storage_class")
    {
        return ktl::api::extension::khr_storage_buffer_storage_class;
    }
    if (_extension == "VK_AMD_gpu_shader_int16")
    {
        return ktl::api::extension::amd_gpu_shader_int_16;
    }
    if (_extension == "VK_AMD_gpa_interface")
    {
        return ktl::api::extension::amd_gpa_interface;
    }
    if (_extension == "VK_AMDX_shader_enqueue")
    {
        return ktl::api::extension::amdx_shader_enqueue;
    }
    if (_extension == "VK_EXT_descriptor_heap")
    {
        return ktl::api::extension::ext_descriptor_heap;
    }
    if (_extension == "VK_AMD_mixed_attachment_samples")
    {
        return ktl::api::extension::amd_mixed_attachment_samples;
    }
    if (_extension == "VK_AMD_shader_fragment_mask")
    {
        return ktl::api::extension::amd_shader_fragment_mask;
    }
    if (_extension == "VK_EXT_inline_uniform_block")
    {
        return ktl::api::extension::ext_inline_uniform_block;
    }
    if (_extension == "VK_AMD_extension_140")
    {
        return ktl::api::extension::amd_extension_140;
    }
    if (_extension == "VK_EXT_shader_stencil_export")
    {
        return ktl::api::extension::ext_shader_stencil_export;
    }
    if (_extension == "VK_KHR_shader_bfloat16")
    {
        return ktl::api::extension::khr_shader_bfloat_16;
    }
    if (_extension == "VK_AMD_extension_143")
    {
        return ktl::api::extension::amd_extension_143;
    }
    if (_extension == "VK_EXT_sample_locations")
    {
        return ktl::api::extension::ext_sample_locations;
    }
    if (_extension == "VK_KHR_relaxed_block_layout")
    {
        return ktl::api::extension::khr_relaxed_block_layout;
    }
    if (_extension == "VK_RESERVED_do_not_use_146")
    {
        return ktl::api::extension::reserved_do_not_use_146;
    }
    if (_extension == "VK_KHR_get_memory_requirements2")
    {
        return ktl::api::extension::khr_get_memory_requirements_2;
    }
    if (_extension == "VK_KHR_image_format_list")
    {
        return ktl::api::extension::khr_image_format_list;
    }
    if (_extension == "VK_EXT_blend_operation_advanced")
    {
        return ktl::api::extension::ext_blend_operation_advanced;
    }
    if (_extension == "VK_NV_fragment_coverage_to_color")
    {
        return ktl::api::extension::nv_fragment_coverage_to_color;
    }
    if (_extension == "VK_KHR_acceleration_structure")
    {
        return ktl::api::extension::khr_acceleration_structure;
    }
    if (_extension == "VK_KHR_ray_tracing_pipeline")
    {
        return ktl::api::extension::khr_ray_tracing_pipeline;
    }
    if (_extension == "VK_KHR_ray_query")
    {
        return ktl::api::extension::khr_ray_query;
    }
    if (_extension == "VK_NV_extension_152")
    {
        return ktl::api::extension::nv_extension_152;
    }
    if (_extension == "VK_NV_framebuffer_mixed_samples")
    {
        return ktl::api::extension::nv_framebuffer_mixed_samples;
    }
    if (_extension == "VK_NV_fill_rectangle")
    {
        return ktl::api::extension::nv_fill_rectangle;
    }
    if (_extension == "VK_NV_shader_sm_builtins")
    {
        return ktl::api::extension::nv_shader_sm_builtins;
    }
    if (_extension == "VK_EXT_post_depth_coverage")
    {
        return ktl::api::extension::ext_post_depth_coverage;
    }
    if (_extension == "VK_KHR_sampler_ycbcr_conversion")
    {
        return ktl::api::extension::khr_sampler_ycbcr_conversion;
    }
    if (_extension == "VK_KHR_bind_memory2")
    {
        return ktl::api::extension::khr_bind_memory_2;
    }
    if (_extension == "VK_EXT_image_drm_format_modifier")
    {
        return ktl::api::extension::ext_image_drm_format_modifier;
    }
    if (_extension == "VK_EXT_extension_160")
    {
        return ktl::api::extension::ext_extension_160;
    }
    if (_extension == "VK_EXT_validation_cache")
    {
        return ktl::api::extension::ext_validation_cache;
    }
    if (_extension == "VK_EXT_descriptor_indexing")
    {
        return ktl::api::extension::ext_descriptor_indexing;
    }
    if (_extension == "VK_EXT_shader_viewport_index_layer")
    {
        return ktl::api::extension::ext_shader_viewport_index_layer;
    }
    if (_extension == "VK_KHR_portability_subset")
    {
        return ktl::api::extension::khr_portability_subset;
    }
    if (_extension == "VK_NV_shading_rate_image")
    {
        return ktl::api::extension::nv_shading_rate_image;
    }
    if (_extension == "VK_NV_ray_tracing")
    {
        return ktl::api::extension::nv_ray_tracing;
    }
    if (_extension == "VK_NV_representative_fragment_test")
    {
        return ktl::api::extension::nv_representative_fragment_test;
    }
    if (_extension == "VK_NV_extension_168")
    {
        return ktl::api::extension::nv_extension_168;
    }
    if (_extension == "VK_KHR_maintenance3")
    {
        return ktl::api::extension::khr_maintenance_3;
    }
    if (_extension == "VK_KHR_draw_indirect_count")
    {
        return ktl::api::extension::khr_draw_indirect_count;
    }
    if (_extension == "VK_EXT_filter_cubic")
    {
        return ktl::api::extension::ext_filter_cubic;
    }
    if (_extension == "VK_QCOM_render_pass_shader_resolve")
    {
        return ktl::api::extension::qcom_render_pass_shader_resolve;
    }
    if (_extension == "VK_QCOM_cooperative_matrix_conversion")
    {
        return ktl::api::extension::qcom_cooperative_matrix_conversion;
    }
    if (_extension == "VK_QCOM_elapsed_timer_query")
    {
        return ktl::api::extension::qcom_elapsed_timer_query;
    }
    if (_extension == "VK_EXT_global_priority")
    {
        return ktl::api::extension::ext_global_priority;
    }
    if (_extension == "VK_KHR_shader_subgroup_extended_types")
    {
        return ktl::api::extension::khr_shader_subgroup_extended_types;
    }
    if (_extension == "VK_EXT_extension_177")
    {
        return ktl::api::extension::ext_extension_177;
    }
    if (_extension == "VK_KHR_8bit_storage")
    {
        return ktl::api::extension::khr_8bit_storage;
    }
    if (_extension == "VK_EXT_external_memory_host")
    {
        return ktl::api::extension::ext_external_memory_host;
    }
    if (_extension == "VK_AMD_buffer_marker")
    {
        return ktl::api::extension::amd_buffer_marker;
    }
    if (_extension == "VK_KHR_shader_atomic_int64")
    {
        return ktl::api::extension::khr_shader_atomic_int_64;
    }
    if (_extension == "VK_KHR_shader_clock")
    {
        return ktl::api::extension::khr_shader_clock;
    }
    if (_extension == "VK_AMD_extension_183")
    {
        return ktl::api::extension::amd_extension_183;
    }
    if (_extension == "VK_AMD_pipeline_compiler_control")
    {
        return ktl::api::extension::amd_pipeline_compiler_control;
    }
    if (_extension == "VK_EXT_calibrated_timestamps")
    {
        return ktl::api::extension::ext_calibrated_timestamps;
    }
    if (_extension == "VK_AMD_shader_core_properties")
    {
        return ktl::api::extension::amd_shader_core_properties;
    }
    if (_extension == "VK_AMD_extension_187")
    {
        return ktl::api::extension::amd_extension_187;
    }
    if (_extension == "VK_KHR_global_priority")
    {
        return ktl::api::extension::khr_global_priority;
    }
    if (_extension == "VK_AMD_memory_overallocation_behavior")
    {
        return ktl::api::extension::amd_memory_overallocation_behavior;
    }
    if (_extension == "VK_EXT_vertex_attribute_divisor")
    {
        return ktl::api::extension::ext_vertex_attribute_divisor;
    }
    if (_extension == "VK_GGP_frame_token")
    {
        return ktl::api::extension::ggp_frame_token;
    }
    if (_extension == "VK_EXT_pipeline_creation_feedback")
    {
        return ktl::api::extension::ext_pipeline_creation_feedback;
    }
    if (_extension == "VK_GOOGLE_extension_194")
    {
        return ktl::api::extension::google_extension_194;
    }
    if (_extension == "VK_GOOGLE_extension_195")
    {
        return ktl::api::extension::google_extension_195;
    }
    if (_extension == "VK_GOOGLE_extension_196")
    {
        return ktl::api::extension::google_extension_196;
    }
    if (_extension == "VK_KHR_driver_properties")
    {
        return ktl::api::extension::khr_driver_properties;
    }
    if (_extension == "VK_KHR_shader_float_controls")
    {
        return ktl::api::extension::khr_shader_float_controls;
    }
    if (_extension == "VK_NV_shader_subgroup_partitioned")
    {
        return ktl::api::extension::nv_shader_subgroup_partitioned;
    }
    if (_extension == "VK_KHR_depth_stencil_resolve")
    {
        return ktl::api::extension::khr_depth_stencil_resolve;
    }
    if (_extension == "VK_KHR_swapchain_mutable_format")
    {
        return ktl::api::extension::khr_swapchain_mutable_format;
    }
    if (_extension == "VK_NV_compute_shader_derivatives")
    {
        return ktl::api::extension::nv_compute_shader_derivatives;
    }
    if (_extension == "VK_NV_mesh_shader")
    {
        return ktl::api::extension::nv_mesh_shader;
    }
    if (_extension == "VK_NV_fragment_shader_barycentric")
    {
        return ktl::api::extension::nv_fragment_shader_barycentric;
    }
    if (_extension == "VK_NV_shader_image_footprint")
    {
        return ktl::api::extension::nv_shader_image_footprint;
    }
    if (_extension == "VK_NV_scissor_exclusive")
    {
        return ktl::api::extension::nv_scissor_exclusive;
    }
    if (_extension == "VK_NV_device_diagnostic_checkpoints")
    {
        return ktl::api::extension::nv_device_diagnostic_checkpoints;
    }
    if (_extension == "VK_KHR_timeline_semaphore")
    {
        return ktl::api::extension::khr_timeline_semaphore;
    }
    if (_extension == "VK_EXT_present_timing")
    {
        return ktl::api::extension::ext_present_timing;
    }
    if (_extension == "VK_INTEL_shader_integer_functions2")
    {
        return ktl::api::extension::intel_shader_integer_functions_2;
    }
    if (_extension == "VK_INTEL_performance_query")
    {
        return ktl::api::extension::intel_performance_query;
    }
    if (_extension == "VK_KHR_vulkan_memory_model")
    {
        return ktl::api::extension::khr_vulkan_memory_model;
    }
    if (_extension == "VK_EXT_pci_bus_info")
    {
        return ktl::api::extension::ext_pci_bus_info;
    }
    if (_extension == "VK_AMD_display_native_hdr")
    {
        return ktl::api::extension::amd_display_native_hdr;
    }
    if (_extension == "VK_FUCHSIA_imagepipe_surface")
    {
        return ktl::api::extension::fuchsia_imagepipe_surface;
    }
    if (_extension == "VK_KHR_shader_terminate_invocation")
    {
        return ktl::api::extension::khr_shader_terminate_invocation;
    }
    if (_extension == "VK_GOOGLE_extension_217")
    {
        return ktl::api::extension::google_extension_217;
    }
    if (_extension == "VK_EXT_metal_surface")
    {
        return ktl::api::extension::ext_metal_surface;
    }
    if (_extension == "VK_EXT_fragment_density_map")
    {
        return ktl::api::extension::ext_fragment_density_map;
    }
    if (_extension == "VK_EXT_extension_220")
    {
        return ktl::api::extension::ext_extension_220;
    }
    if (_extension == "VK_KHR_extension_221")
    {
        return ktl::api::extension::khr_extension_221;
    }
    if (_extension == "VK_EXT_scalar_block_layout")
    {
        return ktl::api::extension::ext_scalar_block_layout;
    }
    if (_extension == "VK_EXT_extension_223")
    {
        return ktl::api::extension::ext_extension_223;
    }
    if (_extension == "VK_GOOGLE_hlsl_functionality1")
    {
        return ktl::api::extension::google_hlsl_functionality_1;
    }
    if (_extension == "VK_GOOGLE_decorate_string")
    {
        return ktl::api::extension::google_decorate_string;
    }
    if (_extension == "VK_EXT_subgroup_size_control")
    {
        return ktl::api::extension::ext_subgroup_size_control;
    }
    if (_extension == "VK_KHR_fragment_shading_rate")
    {
        return ktl::api::extension::khr_fragment_shading_rate;
    }
    if (_extension == "VK_AMD_shader_core_properties2")
    {
        return ktl::api::extension::amd_shader_core_properties_2;
    }
    if (_extension == "VK_AMD_extension_229")
    {
        return ktl::api::extension::amd_extension_229;
    }
    if (_extension == "VK_AMD_device_coherent_memory")
    {
        return ktl::api::extension::amd_device_coherent_memory;
    }
    if (_extension == "VK_AMD_extension_231")
    {
        return ktl::api::extension::amd_extension_231;
    }
    if (_extension == "VK_KHR_shader_constant_data")
    {
        return ktl::api::extension::khr_shader_constant_data;
    }
    if (_extension == "VK_KHR_dynamic_rendering_local_read")
    {
        return ktl::api::extension::khr_dynamic_rendering_local_read;
    }
    if (_extension == "VK_KHR_shader_abort")
    {
        return ktl::api::extension::khr_shader_abort;
    }
    if (_extension == "VK_EXT_shader_image_atomic_int64")
    {
        return ktl::api::extension::ext_shader_image_atomic_int_64;
    }
    if (_extension == "VK_KHR_shader_quad_control")
    {
        return ktl::api::extension::khr_shader_quad_control;
    }
    if (_extension == "VK_KHR_spirv_1_4")
    {
        return ktl::api::extension::khr_spirv_14;
    }
    if (_extension == "VK_EXT_memory_budget")
    {
        return ktl::api::extension::ext_memory_budget;
    }
    if (_extension == "VK_EXT_memory_priority")
    {
        return ktl::api::extension::ext_memory_priority;
    }
    if (_extension == "VK_KHR_surface_protected_capabilities")
    {
        return ktl::api::extension::khr_surface_protected_capabilities;
    }
    if (_extension == "VK_NV_dedicated_allocation_image_aliasing")
    {
        return ktl::api::extension::nv_dedicated_allocation_image_aliasing;
    }
    if (_extension == "VK_KHR_separate_depth_stencil_layouts")
    {
        return ktl::api::extension::khr_separate_depth_stencil_layouts;
    }
    if (_extension == "VK_INTEL_extension_243")
    {
        return ktl::api::extension::intel_extension_243;
    }
    if (_extension == "VK_MESA_extension_244")
    {
        return ktl::api::extension::mesa_extension_244;
    }
    if (_extension == "VK_EXT_buffer_device_address")
    {
        return ktl::api::extension::ext_buffer_device_address;
    }
    if (_extension == "VK_EXT_tooling_info")
    {
        return ktl::api::extension::ext_tooling_info;
    }
    if (_extension == "VK_EXT_separate_stencil_usage")
    {
        return ktl::api::extension::ext_separate_stencil_usage;
    }
    if (_extension == "VK_EXT_validation_features")
    {
        return ktl::api::extension::ext_validation_features;
    }
    if (_extension == "VK_KHR_present_wait")
    {
        return ktl::api::extension::khr_present_wait;
    }
    if (_extension == "VK_NV_cooperative_matrix")
    {
        return ktl::api::extension::nv_cooperative_matrix;
    }
    if (_extension == "VK_NV_coverage_reduction_mode")
    {
        return ktl::api::extension::nv_coverage_reduction_mode;
    }
    if (_extension == "VK_EXT_fragment_shader_interlock")
    {
        return ktl::api::extension::ext_fragment_shader_interlock;
    }
    if (_extension == "VK_EXT_ycbcr_image_arrays")
    {
        return ktl::api::extension::ext_ycbcr_image_arrays;
    }
    if (_extension == "VK_KHR_uniform_buffer_standard_layout")
    {
        return ktl::api::extension::khr_uniform_buffer_standard_layout;
    }
    if (_extension == "VK_EXT_provoking_vertex")
    {
        return ktl::api::extension::ext_provoking_vertex;
    }
    if (_extension == "VK_EXT_full_screen_exclusive")
    {
        return ktl::api::extension::ext_full_screen_exclusive;
    }
    if (_extension == "VK_EXT_headless_surface")
    {
        return ktl::api::extension::ext_headless_surface;
    }
    if (_extension == "VK_KHR_buffer_device_address")
    {
        return ktl::api::extension::khr_buffer_device_address;
    }
    if (_extension == "VK_EXT_extension_259")
    {
        return ktl::api::extension::ext_extension_259;
    }
    if (_extension == "VK_EXT_line_rasterization")
    {
        return ktl::api::extension::ext_line_rasterization;
    }
    if (_extension == "VK_EXT_shader_atomic_float")
    {
        return ktl::api::extension::ext_shader_atomic_float;
    }
    if (_extension == "VK_EXT_host_query_reset")
    {
        return ktl::api::extension::ext_host_query_reset;
    }
    if (_extension == "VK_GGP_extension_263")
    {
        return ktl::api::extension::ggp_extension_263;
    }
    if (_extension == "VK_BRCM_extension_264")
    {
        return ktl::api::extension::brcm_extension_264;
    }
    if (_extension == "VK_BRCM_extension_265")
    {
        return ktl::api::extension::brcm_extension_265;
    }
    if (_extension == "VK_EXT_index_type_uint8")
    {
        return ktl::api::extension::ext_index_type_uint_8;
    }
    if (_extension == "VK_EXT_extension_267")
    {
        return ktl::api::extension::ext_extension_267;
    }
    if (_extension == "VK_EXT_extended_dynamic_state")
    {
        return ktl::api::extension::ext_extended_dynamic_state;
    }
    if (_extension == "VK_KHR_deferred_host_operations")
    {
        return ktl::api::extension::khr_deferred_host_operations;
    }
    if (_extension == "VK_KHR_pipeline_executable_properties")
    {
        return ktl::api::extension::khr_pipeline_executable_properties;
    }
    if (_extension == "VK_EXT_host_image_copy")
    {
        return ktl::api::extension::ext_host_image_copy;
    }
    if (_extension == "VK_KHR_map_memory2")
    {
        return ktl::api::extension::khr_map_memory_2;
    }
    if (_extension == "VK_EXT_map_memory_placed")
    {
        return ktl::api::extension::ext_map_memory_placed;
    }
    if (_extension == "VK_EXT_shader_atomic_float2")
    {
        return ktl::api::extension::ext_shader_atomic_float_2;
    }
    if (_extension == "VK_EXT_surface_maintenance1")
    {
        return ktl::api::extension::ext_surface_maintenance_1;
    }
    if (_extension == "VK_EXT_swapchain_maintenance1")
    {
        return ktl::api::extension::ext_swapchain_maintenance_1;
    }
    if (_extension == "VK_EXT_shader_demote_to_helper_invocation")
    {
        return ktl::api::extension::ext_shader_demote_to_helper_invocation;
    }
    if (_extension == "VK_NV_device_generated_commands")
    {
        return ktl::api::extension::nv_device_generated_commands;
    }
    if (_extension == "VK_NV_inherited_viewport_scissor")
    {
        return ktl::api::extension::nv_inherited_viewport_scissor;
    }
    if (_extension == "VK_KHR_extension_280")
    {
        return ktl::api::extension::khr_extension_280;
    }
    if (_extension == "VK_KHR_shader_integer_dot_product")
    {
        return ktl::api::extension::khr_shader_integer_dot_product;
    }
    if (_extension == "VK_EXT_texel_buffer_alignment")
    {
        return ktl::api::extension::ext_texel_buffer_alignment;
    }
    if (_extension == "VK_QCOM_render_pass_transform")
    {
        return ktl::api::extension::qcom_render_pass_transform;
    }
    if (_extension == "VK_EXT_depth_bias_control")
    {
        return ktl::api::extension::ext_depth_bias_control;
    }
    if (_extension == "VK_EXT_device_memory_report")
    {
        return ktl::api::extension::ext_device_memory_report;
    }
    if (_extension == "VK_EXT_acquire_drm_display")
    {
        return ktl::api::extension::ext_acquire_drm_display;
    }
    if (_extension == "VK_EXT_robustness2")
    {
        return ktl::api::extension::ext_robustness_2;
    }
    if (_extension == "VK_EXT_custom_border_color")
    {
        return ktl::api::extension::ext_custom_border_color;
    }
    if (_extension == "VK_EXT_texture_compression_astc_3d")
    {
        return ktl::api::extension::ext_texture_compression_astc_3d;
    }
    if (_extension == "VK_GOOGLE_user_type")
    {
        return ktl::api::extension::google_user_type;
    }
    if (_extension == "VK_KHR_pipeline_library")
    {
        return ktl::api::extension::khr_pipeline_library;
    }
    if (_extension == "VK_NV_extension_292")
    {
        return ktl::api::extension::nv_extension_292;
    }
    if (_extension == "VK_NV_present_barrier")
    {
        return ktl::api::extension::nv_present_barrier;
    }
    if (_extension == "VK_KHR_shader_non_semantic_info")
    {
        return ktl::api::extension::khr_shader_non_semantic_info;
    }
    if (_extension == "VK_KHR_present_id")
    {
        return ktl::api::extension::khr_present_id;
    }
    if (_extension == "VK_EXT_private_data")
    {
        return ktl::api::extension::ext_private_data;
    }
    if (_extension == "VK_KHR_extension_297")
    {
        return ktl::api::extension::khr_extension_297;
    }
    if (_extension == "VK_EXT_pipeline_creation_cache_control")
    {
        return ktl::api::extension::ext_pipeline_creation_cache_control;
    }
    if (_extension == "VK_KHR_extension_299")
    {
        return ktl::api::extension::khr_extension_299;
    }
    if (_extension == "VK_NV_device_diagnostics_config")
    {
        return ktl::api::extension::nv_device_diagnostics_config;
    }
    if (_extension == "VK_QCOM_render_pass_store_ops")
    {
        return ktl::api::extension::qcom_render_pass_store_ops;
    }
    if (_extension == "VK_QCOM_queue_perf_hint")
    {
        return ktl::api::extension::qcom_queue_perf_hint;
    }
    if (_extension == "VK_QCOM_image_processing3")
    {
        return ktl::api::extension::qcom_image_processing_3;
    }
    if (_extension == "VK_QCOM_shader_multiple_wait_queues")
    {
        return ktl::api::extension::qcom_shader_multiple_wait_queues;
    }
    if (_extension == "VK_EXT_shader_split_barrier")
    {
        return ktl::api::extension::ext_shader_split_barrier;
    }
    if (_extension == "VK_QCOM_extension_307")
    {
        return ktl::api::extension::qcom_extension_307;
    }
    if (_extension == "VK_NV_cuda_kernel_launch")
    {
        return ktl::api::extension::nv_cuda_kernel_launch;
    }
    if (_extension == "VK_KHR_object_refresh")
    {
        return ktl::api::extension::khr_object_refresh;
    }
    if (_extension == "VK_QCOM_tile_shading")
    {
        return ktl::api::extension::qcom_tile_shading;
    }
    if (_extension == "VK_NV_low_latency")
    {
        return ktl::api::extension::nv_low_latency;
    }
    if (_extension == "VK_EXT_metal_objects")
    {
        return ktl::api::extension::ext_metal_objects;
    }
    if (_extension == "VK_EXT_extension_313")
    {
        return ktl::api::extension::ext_extension_313;
    }
    if (_extension == "VK_AMD_extension_314")
    {
        return ktl::api::extension::amd_extension_314;
    }
    if (_extension == "VK_KHR_synchronization2")
    {
        return ktl::api::extension::khr_synchronization_2;
    }
    if (_extension == "VK_AMD_extension_316")
    {
        return ktl::api::extension::amd_extension_316;
    }
    if (_extension == "VK_EXT_descriptor_buffer")
    {
        return ktl::api::extension::ext_descriptor_buffer;
    }
    if (_extension == "VK_AMD_extension_318")
    {
        return ktl::api::extension::amd_extension_318;
    }
    if (_extension == "VK_KHR_device_address_commands")
    {
        return ktl::api::extension::khr_device_address_commands;
    }
    if (_extension == "VK_AMD_extension_320")
    {
        return ktl::api::extension::amd_extension_320;
    }
    if (_extension == "VK_EXT_graphics_pipeline_library")
    {
        return ktl::api::extension::ext_graphics_pipeline_library;
    }
    if (_extension == "VK_AMD_shader_early_and_late_fragment_tests")
    {
        return ktl::api::extension::amd_shader_early_and_late_fragment_tests;
    }
    if (_extension == "VK_KHR_fragment_shader_barycentric")
    {
        return ktl::api::extension::khr_fragment_shader_barycentric;
    }
    if (_extension == "VK_KHR_shader_subgroup_uniform_control_flow")
    {
        return ktl::api::extension::khr_shader_subgroup_uniform_control_flow;
    }
    if (_extension == "VK_KHR_extension_325")
    {
        return ktl::api::extension::khr_extension_325;
    }
    if (_extension == "VK_KHR_zero_initialize_workgroup_memory")
    {
        return ktl::api::extension::khr_zero_initialize_workgroup_memory;
    }
    if (_extension == "VK_NV_fragment_shading_rate_enums")
    {
        return ktl::api::extension::nv_fragment_shading_rate_enums;
    }
    if (_extension == "VK_NV_ray_tracing_motion_blur")
    {
        return ktl::api::extension::nv_ray_tracing_motion_blur;
    }
    if (_extension == "VK_EXT_mesh_shader")
    {
        return ktl::api::extension::ext_mesh_shader;
    }
    if (_extension == "VK_NV_extension_330")
    {
        return ktl::api::extension::nv_extension_330;
    }
    if (_extension == "VK_EXT_ycbcr_2plane_444_formats")
    {
        return ktl::api::extension::ext_ycbcr_2plane_444formats;
    }
    if (_extension == "VK_NV_extension_332")
    {
        return ktl::api::extension::nv_extension_332;
    }
    if (_extension == "VK_EXT_fragment_density_map2")
    {
        return ktl::api::extension::ext_fragment_density_map_2;
    }
    if (_extension == "VK_QCOM_rotated_copy_commands")
    {
        return ktl::api::extension::qcom_rotated_copy_commands;
    }
    if (_extension == "VK_KHR_extension_335")
    {
        return ktl::api::extension::khr_extension_335;
    }
    if (_extension == "VK_EXT_image_robustness")
    {
        return ktl::api::extension::ext_image_robustness;
    }
    if (_extension == "VK_KHR_workgroup_memory_explicit_layout")
    {
        return ktl::api::extension::khr_workgroup_memory_explicit_layout;
    }
    if (_extension == "VK_KHR_copy_commands2")
    {
        return ktl::api::extension::khr_copy_commands_2;
    }
    if (_extension == "VK_EXT_image_compression_control")
    {
        return ktl::api::extension::ext_image_compression_control;
    }
    if (_extension == "VK_EXT_attachment_feedback_loop_layout")
    {
        return ktl::api::extension::ext_attachment_feedback_loop_layout;
    }
    if (_extension == "VK_EXT_4444_formats")
    {
        return ktl::api::extension::ext_4444formats;
    }
    if (_extension == "VK_EXT_device_fault")
    {
        return ktl::api::extension::ext_device_fault;
    }
    if (_extension == "VK_ARM_rasterization_order_attachment_access")
    {
        return ktl::api::extension::arm_rasterization_order_attachment_access;
    }
    if (_extension == "VK_ARM_extension_344")
    {
        return ktl::api::extension::arm_extension_344;
    }
    if (_extension == "VK_EXT_rgba10x6_formats")
    {
        return ktl::api::extension::ext_rgba_10x_6formats;
    }
    if (_extension == "VK_NV_acquire_winrt_display")
    {
        return ktl::api::extension::nv_acquire_winrt_display;
    }
    if (_extension == "VK_EXT_directfb_surface")
    {
        return ktl::api::extension::ext_directfb_surface;
    }
    if (_extension == "VK_KHR_extension_350")
    {
        return ktl::api::extension::khr_extension_350;
    }
    if (_extension == "VK_NV_extension_351")
    {
        return ktl::api::extension::nv_extension_351;
    }
    if (_extension == "VK_VALVE_mutable_descriptor_type")
    {
        return ktl::api::extension::valve_mutable_descriptor_type;
    }
    if (_extension == "VK_EXT_vertex_input_dynamic_state")
    {
        return ktl::api::extension::ext_vertex_input_dynamic_state;
    }
    if (_extension == "VK_EXT_physical_device_drm")
    {
        return ktl::api::extension::ext_physical_device_drm;
    }
    if (_extension == "VK_EXT_device_address_binding_report")
    {
        return ktl::api::extension::ext_device_address_binding_report;
    }
    if (_extension == "VK_EXT_depth_clip_control")
    {
        return ktl::api::extension::ext_depth_clip_control;
    }
    if (_extension == "VK_EXT_primitive_topology_list_restart")
    {
        return ktl::api::extension::ext_primitive_topology_list_restart;
    }
    if (_extension == "VK_KHR_extension_358")
    {
        return ktl::api::extension::khr_extension_358;
    }
    if (_extension == "VK_EXT_extension_359")
    {
        return ktl::api::extension::ext_extension_359;
    }
    if (_extension == "VK_EXT_extension_360")
    {
        return ktl::api::extension::ext_extension_360;
    }
    if (_extension == "VK_KHR_format_feature_flags2")
    {
        return ktl::api::extension::khr_format_feature_flags_2;
    }
    if (_extension == "VK_EXT_present_mode_fifo_latest_ready")
    {
        return ktl::api::extension::ext_present_mode_fifo_latest_ready;
    }
    if (_extension == "VK_EXT_extension_363")
    {
        return ktl::api::extension::ext_extension_363;
    }
    if (_extension == "VK_FUCHSIA_extension_364")
    {
        return ktl::api::extension::fuchsia_extension_364;
    }
    if (_extension == "VK_FUCHSIA_external_memory")
    {
        return ktl::api::extension::fuchsia_external_memory;
    }
    if (_extension == "VK_FUCHSIA_external_semaphore")
    {
        return ktl::api::extension::fuchsia_external_semaphore;
    }
    if (_extension == "VK_FUCHSIA_buffer_collection")
    {
        return ktl::api::extension::fuchsia_buffer_collection;
    }
    if (_extension == "VK_FUCHSIA_extension_368")
    {
        return ktl::api::extension::fuchsia_extension_368;
    }
    if (_extension == "VK_QCOM_extension_369")
    {
        return ktl::api::extension::qcom_extension_369;
    }
    if (_extension == "VK_HUAWEI_subpass_shading")
    {
        return ktl::api::extension::huawei_subpass_shading;
    }
    if (_extension == "VK_HUAWEI_invocation_mask")
    {
        return ktl::api::extension::huawei_invocation_mask;
    }
    if (_extension == "VK_NV_external_memory_rdma")
    {
        return ktl::api::extension::nv_external_memory_rdma;
    }
    if (_extension == "VK_EXT_pipeline_properties")
    {
        return ktl::api::extension::ext_pipeline_properties;
    }
    if (_extension == "VK_NV_external_sci_sync")
    {
        return ktl::api::extension::nv_external_sci_sync;
    }
    if (_extension == "VK_NV_external_memory_sci_buf")
    {
        return ktl::api::extension::nv_external_memory_sci_buf;
    }
    if (_extension == "VK_EXT_frame_boundary")
    {
        return ktl::api::extension::ext_frame_boundary;
    }
    if (_extension == "VK_EXT_multisampled_render_to_single_sampled")
    {
        return ktl::api::extension::ext_multisampled_render_to_single_sampled;
    }
    if (_extension == "VK_EXT_extended_dynamic_state2")
    {
        return ktl::api::extension::ext_extended_dynamic_state_2;
    }
    if (_extension == "VK_QNX_screen_surface")
    {
        return ktl::api::extension::qnx_screen_surface;
    }
    if (_extension == "VK_KHR_extension_380")
    {
        return ktl::api::extension::khr_extension_380;
    }
    if (_extension == "VK_KHR_extension_381")
    {
        return ktl::api::extension::khr_extension_381;
    }
    if (_extension == "VK_EXT_color_write_enable")
    {
        return ktl::api::extension::ext_color_write_enable;
    }
    if (_extension == "VK_EXT_primitives_generated_query")
    {
        return ktl::api::extension::ext_primitives_generated_query;
    }
    if (_extension == "VK_EXT_extension_384")
    {
        return ktl::api::extension::ext_extension_384;
    }
    if (_extension == "VK_MESA_extension_385")
    {
        return ktl::api::extension::mesa_extension_385;
    }
    if (_extension == "VK_GOOGLE_extension_386")
    {
        return ktl::api::extension::google_extension_386;
    }
    if (_extension == "VK_KHR_ray_tracing_maintenance1")
    {
        return ktl::api::extension::khr_ray_tracing_maintenance_1;
    }
    if (_extension == "VK_KHR_shader_untyped_pointers")
    {
        return ktl::api::extension::khr_shader_untyped_pointers;
    }
    if (_extension == "VK_EXT_global_priority_query")
    {
        return ktl::api::extension::ext_global_priority_query;
    }
    if (_extension == "VK_EXT_extension_390")
    {
        return ktl::api::extension::ext_extension_390;
    }
    if (_extension == "VK_EXT_image_view_min_lod")
    {
        return ktl::api::extension::ext_image_view_min_lod;
    }
    if (_extension == "VK_EXT_multi_draw")
    {
        return ktl::api::extension::ext_multi_draw;
    }
    if (_extension == "VK_EXT_image_2d_view_of_3d")
    {
        return ktl::api::extension::ext_image_2d_view_of_3d;
    }
    if (_extension == "VK_KHR_portability_enumeration")
    {
        return ktl::api::extension::khr_portability_enumeration;
    }
    if (_extension == "VK_EXT_shader_tile_image")
    {
        return ktl::api::extension::ext_shader_tile_image;
    }
    if (_extension == "VK_EXT_opacity_micromap")
    {
        return ktl::api::extension::ext_opacity_micromap;
    }
    if (_extension == "VK_NV_displacement_micromap")
    {
        return ktl::api::extension::nv_displacement_micromap;
    }
    if (_extension == "VK_JUICE_extension_399")
    {
        return ktl::api::extension::juice_extension_399;
    }
    if (_extension == "VK_JUICE_extension_400")
    {
        return ktl::api::extension::juice_extension_400;
    }
    if (_extension == "VK_EXT_load_store_op_none")
    {
        return ktl::api::extension::ext_load_store_op_none;
    }
    if (_extension == "VK_FB_extension_402")
    {
        return ktl::api::extension::fb_extension_402;
    }
    if (_extension == "VK_FB_extension_403")
    {
        return ktl::api::extension::fb_extension_403;
    }
    if (_extension == "VK_FB_extension_404")
    {
        return ktl::api::extension::fb_extension_404;
    }
    if (_extension == "VK_HUAWEI_cluster_culling_shader")
    {
        return ktl::api::extension::huawei_cluster_culling_shader;
    }
    if (_extension == "VK_HUAWEI_extension_406")
    {
        return ktl::api::extension::huawei_extension_406;
    }
    if (_extension == "VK_GGP_extension_407")
    {
        return ktl::api::extension::ggp_extension_407;
    }
    if (_extension == "VK_GGP_extension_408")
    {
        return ktl::api::extension::ggp_extension_408;
    }
    if (_extension == "VK_GGP_extension_409")
    {
        return ktl::api::extension::ggp_extension_409;
    }
    if (_extension == "VK_GGP_extension_410")
    {
        return ktl::api::extension::ggp_extension_410;
    }
    if (_extension == "VK_GGP_extension_411")
    {
        return ktl::api::extension::ggp_extension_411;
    }
    if (_extension == "VK_EXT_border_color_swizzle")
    {
        return ktl::api::extension::ext_border_color_swizzle;
    }
    if (_extension == "VK_EXT_pageable_device_local_memory")
    {
        return ktl::api::extension::ext_pageable_device_local_memory;
    }
    if (_extension == "VK_KHR_maintenance4")
    {
        return ktl::api::extension::khr_maintenance_4;
    }
    if (_extension == "VK_HUAWEI_extension_415")
    {
        return ktl::api::extension::huawei_extension_415;
    }
    if (_extension == "VK_ARM_shader_core_properties")
    {
        return ktl::api::extension::arm_shader_core_properties;
    }
    if (_extension == "VK_KHR_shader_subgroup_rotate")
    {
        return ktl::api::extension::khr_shader_subgroup_rotate;
    }
    if (_extension == "VK_ARM_scheduling_controls")
    {
        return ktl::api::extension::arm_scheduling_controls;
    }
    if (_extension == "VK_EXT_image_sliced_view_of_3d")
    {
        return ktl::api::extension::ext_image_sliced_view_of_3d;
    }
    if (_extension == "VK_EXT_extension_420")
    {
        return ktl::api::extension::ext_extension_420;
    }
    if (_extension == "VK_VALVE_descriptor_set_host_mapping")
    {
        return ktl::api::extension::valve_descriptor_set_host_mapping;
    }
    if (_extension == "VK_EXT_depth_clamp_zero_one")
    {
        return ktl::api::extension::ext_depth_clamp_zero_one;
    }
    if (_extension == "VK_EXT_non_seamless_cube_map")
    {
        return ktl::api::extension::ext_non_seamless_cube_map;
    }
    if (_extension == "VK_ARM_extension_424")
    {
        return ktl::api::extension::arm_extension_424;
    }
    if (_extension == "VK_ARM_render_pass_striped")
    {
        return ktl::api::extension::arm_render_pass_striped;
    }
    if (_extension == "VK_QCOM_fragment_density_map_offset")
    {
        return ktl::api::extension::qcom_fragment_density_map_offset;
    }
    if (_extension == "VK_NV_copy_memory_indirect")
    {
        return ktl::api::extension::nv_copy_memory_indirect;
    }
    if (_extension == "VK_NV_memory_decompression")
    {
        return ktl::api::extension::nv_memory_decompression;
    }
    if (_extension == "VK_NV_device_generated_commands_compute")
    {
        return ktl::api::extension::nv_device_generated_commands_compute;
    }
    if (_extension == "VK_NV_ray_tracing_linear_swept_spheres")
    {
        return ktl::api::extension::nv_ray_tracing_linear_swept_spheres;
    }
    if (_extension == "VK_NV_linear_color_attachment")
    {
        return ktl::api::extension::nv_linear_color_attachment;
    }
    if (_extension == "VK_NV_extension_432")
    {
        return ktl::api::extension::nv_extension_432;
    }
    if (_extension == "VK_NV_extension_433")
    {
        return ktl::api::extension::nv_extension_433;
    }
    if (_extension == "VK_GOOGLE_surfaceless_query")
    {
        return ktl::api::extension::google_surfaceless_query;
    }
    if (_extension == "VK_KHR_shader_maximal_reconvergence")
    {
        return ktl::api::extension::khr_shader_maximal_reconvergence;
    }
    if (_extension == "VK_EXT_application_parameters")
    {
        return ktl::api::extension::ext_application_parameters;
    }
    if (_extension == "VK_EXT_extension_437")
    {
        return ktl::api::extension::ext_extension_437;
    }
    if (_extension == "VK_EXT_image_compression_control_swapchain")
    {
        return ktl::api::extension::ext_image_compression_control_swapchain;
    }
    if (_extension == "VK_SEC_extension_439")
    {
        return ktl::api::extension::sec_extension_439;
    }
    if (_extension == "VK_QCOM_extension_440")
    {
        return ktl::api::extension::qcom_extension_440;
    }
    if (_extension == "VK_QCOM_image_processing")
    {
        return ktl::api::extension::qcom_image_processing;
    }
    if (_extension == "VK_COREAVI_extension_442")
    {
        return ktl::api::extension::coreavi_extension_442;
    }
    if (_extension == "VK_COREAVI_extension_443")
    {
        return ktl::api::extension::coreavi_extension_443;
    }
    if (_extension == "VK_COREAVI_extension_444")
    {
        return ktl::api::extension::coreavi_extension_444;
    }
    if (_extension == "VK_COREAVI_extension_445")
    {
        return ktl::api::extension::coreavi_extension_445;
    }
    if (_extension == "VK_COREAVI_extension_446")
    {
        return ktl::api::extension::coreavi_extension_446;
    }
    if (_extension == "VK_COREAVI_extension_447")
    {
        return ktl::api::extension::coreavi_extension_447;
    }
    if (_extension == "VK_SEC_extension_448")
    {
        return ktl::api::extension::sec_extension_448;
    }
    if (_extension == "VK_SEC_extension_449")
    {
        return ktl::api::extension::sec_extension_449;
    }
    if (_extension == "VK_SEC_extension_450")
    {
        return ktl::api::extension::sec_extension_450;
    }
    if (_extension == "VK_SEC_extension_451")
    {
        return ktl::api::extension::sec_extension_451;
    }
    if (_extension == "VK_EXT_nested_command_buffer")
    {
        return ktl::api::extension::ext_nested_command_buffer;
    }
    if (_extension == "VK_OHOS_external_memory")
    {
        return ktl::api::extension::ohos_external_memory;
    }
    if (_extension == "VK_EXT_external_memory_acquire_unmodified")
    {
        return ktl::api::extension::ext_external_memory_acquire_unmodified;
    }
    if (_extension == "VK_GOOGLE_extension_455")
    {
        return ktl::api::extension::google_extension_455;
    }
    if (_extension == "VK_EXT_extended_dynamic_state3")
    {
        return ktl::api::extension::ext_extended_dynamic_state_3;
    }
    if (_extension == "VK_EXT_extension_457")
    {
        return ktl::api::extension::ext_extension_457;
    }
    if (_extension == "VK_EXT_extension_458")
    {
        return ktl::api::extension::ext_extension_458;
    }
    if (_extension == "VK_EXT_subpass_merge_feedback")
    {
        return ktl::api::extension::ext_subpass_merge_feedback;
    }
    if (_extension == "VK_LUNARG_direct_driver_loading")
    {
        return ktl::api::extension::lunarg_direct_driver_loading;
    }
    if (_extension == "VK_ARM_tensors")
    {
        return ktl::api::extension::arm_tensors;
    }
    if (_extension == "VK_EXT_extension_462")
    {
        return ktl::api::extension::ext_extension_462;
    }
    if (_extension == "VK_EXT_shader_module_identifier")
    {
        return ktl::api::extension::ext_shader_module_identifier;
    }
    if (_extension == "VK_EXT_rasterization_order_attachment_access")
    {
        return ktl::api::extension::ext_rasterization_order_attachment_access;
    }
    if (_extension == "VK_NV_optical_flow")
    {
        return ktl::api::extension::nv_optical_flow;
    }
    if (_extension == "VK_EXT_legacy_dithering")
    {
        return ktl::api::extension::ext_legacy_dithering;
    }
    if (_extension == "VK_EXT_pipeline_protected_access")
    {
        return ktl::api::extension::ext_pipeline_protected_access;
    }
    if (_extension == "VK_EXT_extension_468")
    {
        return ktl::api::extension::ext_extension_468;
    }
    if (_extension == "VK_ANDROID_external_format_resolve")
    {
        return ktl::api::extension::android_external_format_resolve;
    }
    if (_extension == "VK_AMD_extension_470")
    {
        return ktl::api::extension::amd_extension_470;
    }
    if (_extension == "VK_KHR_maintenance5")
    {
        return ktl::api::extension::khr_maintenance_5;
    }
    if (_extension == "VK_AMD_extension_472")
    {
        return ktl::api::extension::amd_extension_472;
    }
    if (_extension == "VK_AMD_extension_473")
    {
        return ktl::api::extension::amd_extension_473;
    }
    if (_extension == "VK_AMD_extension_474")
    {
        return ktl::api::extension::amd_extension_474;
    }
    if (_extension == "VK_AMD_extension_475")
    {
        return ktl::api::extension::amd_extension_475;
    }
    if (_extension == "VK_AMD_extension_476")
    {
        return ktl::api::extension::amd_extension_476;
    }
    if (_extension == "VK_AMD_anti_lag")
    {
        return ktl::api::extension::amd_anti_lag;
    }
    if (_extension == "VK_AMD_extension_478")
    {
        return ktl::api::extension::amd_extension_478;
    }
    if (_extension == "VK_AMDX_dense_geometry_format")
    {
        return ktl::api::extension::amdx_dense_geometry_format;
    }
    if (_extension == "VK_KHR_present_id2")
    {
        return ktl::api::extension::khr_present_id_2;
    }
    if (_extension == "VK_KHR_present_wait2")
    {
        return ktl::api::extension::khr_present_wait_2;
    }
    if (_extension == "VK_KHR_ray_tracing_position_fetch")
    {
        return ktl::api::extension::khr_ray_tracing_position_fetch;
    }
    if (_extension == "VK_EXT_shader_object")
    {
        return ktl::api::extension::ext_shader_object;
    }
    if (_extension == "VK_KHR_pipeline_binary")
    {
        return ktl::api::extension::khr_pipeline_binary;
    }
    if (_extension == "VK_QCOM_tile_properties")
    {
        return ktl::api::extension::qcom_tile_properties;
    }
    if (_extension == "VK_SEC_amigo_profiling")
    {
        return ktl::api::extension::sec_amigo_profiling;
    }
    if (_extension == "VK_KHR_surface_maintenance1")
    {
        return ktl::api::extension::khr_surface_maintenance_1;
    }
    if (_extension == "VK_KHR_swapchain_maintenance1")
    {
        return ktl::api::extension::khr_swapchain_maintenance_1;
    }
    if (_extension == "VK_QCOM_multiview_per_view_viewports")
    {
        return ktl::api::extension::qcom_multiview_per_view_viewports;
    }
    if (_extension == "VK_NV_external_sci_sync2")
    {
        return ktl::api::extension::nv_external_sci_sync_2;
    }
    if (_extension == "VK_NV_ray_tracing_invocation_reorder")
    {
        return ktl::api::extension::nv_ray_tracing_invocation_reorder;
    }
    if (_extension == "VK_NV_cooperative_vector")
    {
        return ktl::api::extension::nv_cooperative_vector;
    }
    if (_extension == "VK_NV_extended_sparse_address_space")
    {
        return ktl::api::extension::nv_extended_sparse_address_space;
    }
    if (_extension == "VK_NV_extension_494")
    {
        return ktl::api::extension::nv_extension_494;
    }
    if (_extension == "VK_EXT_mutable_descriptor_type")
    {
        return ktl::api::extension::ext_mutable_descriptor_type;
    }
    if (_extension == "VK_EXT_legacy_vertex_attributes")
    {
        return ktl::api::extension::ext_legacy_vertex_attributes;
    }
    if (_extension == "VK_EXT_layer_settings")
    {
        return ktl::api::extension::ext_layer_settings;
    }
    if (_extension == "VK_ARM_shader_core_builtins")
    {
        return ktl::api::extension::arm_shader_core_builtins;
    }
    if (_extension == "VK_EXT_pipeline_library_group_handles")
    {
        return ktl::api::extension::ext_pipeline_library_group_handles;
    }
    if (_extension == "VK_EXT_dynamic_rendering_unused_attachments")
    {
        return ktl::api::extension::ext_dynamic_rendering_unused_attachments;
    }
    if (_extension == "VK_EXT_extension_501")
    {
        return ktl::api::extension::ext_extension_501;
    }
    if (_extension == "VK_EXT_extension_502")
    {
        return ktl::api::extension::ext_extension_502;
    }
    if (_extension == "VK_EXT_extension_503")
    {
        return ktl::api::extension::ext_extension_503;
    }
    if (_extension == "VK_NV_extension_504")
    {
        return ktl::api::extension::nv_extension_504;
    }
    if (_extension == "VK_KHR_internally_synchronized_queues")
    {
        return ktl::api::extension::khr_internally_synchronized_queues;
    }
    if (_extension == "VK_NV_low_latency2")
    {
        return ktl::api::extension::nv_low_latency_2;
    }
    if (_extension == "VK_KHR_cooperative_matrix")
    {
        return ktl::api::extension::khr_cooperative_matrix;
    }
    if (_extension == "VK_ARM_data_graph")
    {
        return ktl::api::extension::arm_data_graph;
    }
    if (_extension == "VK_ARM_data_graph_instruction_set_tosa")
    {
        return ktl::api::extension::arm_data_graph_instruction_set_tosa;
    }
    if (_extension == "VK_MESA_extension_510")
    {
        return ktl::api::extension::mesa_extension_510;
    }
    if (_extension == "VK_QCOM_multiview_per_view_render_areas")
    {
        return ktl::api::extension::qcom_multiview_per_view_render_areas;
    }
    if (_extension == "VK_KHR_compute_shader_derivatives")
    {
        return ktl::api::extension::khr_compute_shader_derivatives;
    }
    if (_extension == "VK_NV_per_stage_descriptor_set")
    {
        return ktl::api::extension::nv_per_stage_descriptor_set;
    }
    if (_extension == "VK_MESA_extension_518")
    {
        return ktl::api::extension::mesa_extension_518;
    }
    if (_extension == "VK_QCOM_image_processing2")
    {
        return ktl::api::extension::qcom_image_processing_2;
    }
    if (_extension == "VK_QCOM_filter_cubic_weights")
    {
        return ktl::api::extension::qcom_filter_cubic_weights;
    }
    if (_extension == "VK_QCOM_ycbcr_degamma")
    {
        return ktl::api::extension::qcom_ycbcr_degamma;
    }
    if (_extension == "VK_QCOM_filter_cubic_clamp")
    {
        return ktl::api::extension::qcom_filter_cubic_clamp;
    }
    if (_extension == "VK_EXT_extension_523")
    {
        return ktl::api::extension::ext_extension_523;
    }
    if (_extension == "VK_EXT_extension_524")
    {
        return ktl::api::extension::ext_extension_524;
    }
    if (_extension == "VK_EXT_attachment_feedback_loop_dynamic_state")
    {
        return ktl::api::extension::ext_attachment_feedback_loop_dynamic_state;
    }
    if (_extension == "VK_KHR_vertex_attribute_divisor")
    {
        return ktl::api::extension::khr_vertex_attribute_divisor;
    }
    if (_extension == "VK_KHR_load_store_op_none")
    {
        return ktl::api::extension::khr_load_store_op_none;
    }
    if (_extension == "VK_KHR_unified_image_layouts")
    {
        return ktl::api::extension::khr_unified_image_layouts;
    }
    if (_extension == "VK_KHR_shader_float_controls2")
    {
        return ktl::api::extension::khr_shader_float_controls_2;
    }
    if (_extension == "VK_QNX_external_memory_screen_buffer")
    {
        return ktl::api::extension::qnx_external_memory_screen_buffer;
    }
    if (_extension == "VK_MSFT_layered_driver")
    {
        return ktl::api::extension::msft_layered_driver;
    }
    if (_extension == "VK_KHR_extension_532")
    {
        return ktl::api::extension::khr_extension_532;
    }
    if (_extension == "VK_EXT_extension_533")
    {
        return ktl::api::extension::ext_extension_533;
    }
    if (_extension == "VK_KHR_index_type_uint8")
    {
        return ktl::api::extension::khr_index_type_uint_8;
    }
    if (_extension == "VK_KHR_line_rasterization")
    {
        return ktl::api::extension::khr_line_rasterization;
    }
    if (_extension == "VK_QCOM_extension_536")
    {
        return ktl::api::extension::qcom_extension_536;
    }
    if (_extension == "VK_EXT_extension_537")
    {
        return ktl::api::extension::ext_extension_537;
    }
    if (_extension == "VK_EXT_extension_538")
    {
        return ktl::api::extension::ext_extension_538;
    }
    if (_extension == "VK_EXT_extension_539")
    {
        return ktl::api::extension::ext_extension_539;
    }
    if (_extension == "VK_EXT_extension_540")
    {
        return ktl::api::extension::ext_extension_540;
    }
    if (_extension == "VK_EXT_extension_541")
    {
        return ktl::api::extension::ext_extension_541;
    }
    if (_extension == "VK_EXT_extension_542")
    {
        return ktl::api::extension::ext_extension_542;
    }
    if (_extension == "VK_EXT_extension_543")
    {
        return ktl::api::extension::ext_extension_543;
    }
    if (_extension == "VK_KHR_calibrated_timestamps")
    {
        return ktl::api::extension::khr_calibrated_timestamps;
    }
    if (_extension == "VK_KHR_shader_expect_assume")
    {
        return ktl::api::extension::khr_shader_expect_assume;
    }
    if (_extension == "VK_KHR_maintenance6")
    {
        return ktl::api::extension::khr_maintenance_6;
    }
    if (_extension == "VK_NV_descriptor_pool_overallocation")
    {
        return ktl::api::extension::nv_descriptor_pool_overallocation;
    }
    if (_extension == "VK_QCOM_tile_memory_heap")
    {
        return ktl::api::extension::qcom_tile_memory_heap;
    }
    if (_extension == "VK_NV_extension_549")
    {
        return ktl::api::extension::nv_extension_549;
    }
    if (_extension == "VK_KHR_copy_memory_indirect")
    {
        return ktl::api::extension::khr_copy_memory_indirect;
    }
    if (_extension == "VK_EXT_memory_decompression")
    {
        return ktl::api::extension::ext_memory_decompression;
    }
    if (_extension == "VK_NV_display_stereo")
    {
        return ktl::api::extension::nv_display_stereo;
    }
    if (_extension == "VK_IMG_extension_555")
    {
        return ktl::api::extension::img_extension_555;
    }
    if (_extension == "VK_NV_raw_access_chains")
    {
        return ktl::api::extension::nv_raw_access_chains;
    }
    if (_extension == "VK_NV_external_compute_queue")
    {
        return ktl::api::extension::nv_external_compute_queue;
    }
    if (_extension == "VK_KHR_extension_558")
    {
        return ktl::api::extension::khr_extension_558;
    }
    if (_extension == "VK_KHR_shader_relaxed_extended_instruction")
    {
        return ktl::api::extension::khr_shader_relaxed_extended_instruction;
    }
    if (_extension == "VK_NV_command_buffer_inheritance")
    {
        return ktl::api::extension::nv_command_buffer_inheritance;
    }
    if (_extension == "VK_EXT_extension_561")
    {
        return ktl::api::extension::ext_extension_561;
    }
    if (_extension == "VK_KHR_extension_562")
    {
        return ktl::api::extension::khr_extension_562;
    }
    if (_extension == "VK_KHR_maintenance7")
    {
        return ktl::api::extension::khr_maintenance_7;
    }
    if (_extension == "VK_NV_shader_atomic_float16_vector")
    {
        return ktl::api::extension::nv_shader_atomic_float_16vector;
    }
    if (_extension == "VK_EXT_shader_replicated_composites")
    {
        return ktl::api::extension::ext_shader_replicated_composites;
    }
    if (_extension == "VK_ARM_extension_566")
    {
        return ktl::api::extension::arm_extension_566;
    }
    if (_extension == "VK_ARM_extension_567")
    {
        return ktl::api::extension::arm_extension_567;
    }
    if (_extension == "VK_EXT_shader_float8")
    {
        return ktl::api::extension::ext_shader_float_8;
    }
    if (_extension == "VK_NV_ray_tracing_validation")
    {
        return ktl::api::extension::nv_ray_tracing_validation;
    }
    if (_extension == "VK_NV_cluster_acceleration_structure")
    {
        return ktl::api::extension::nv_cluster_acceleration_structure;
    }
    if (_extension == "VK_NV_partitioned_acceleration_structure")
    {
        return ktl::api::extension::nv_partitioned_acceleration_structure;
    }
    if (_extension == "VK_NV_extension_572")
    {
        return ktl::api::extension::nv_extension_572;
    }
    if (_extension == "VK_EXT_device_generated_commands")
    {
        return ktl::api::extension::ext_device_generated_commands;
    }
    if (_extension == "VK_KHR_device_fault")
    {
        return ktl::api::extension::khr_device_fault;
    }
    if (_extension == "VK_KHR_maintenance8")
    {
        return ktl::api::extension::khr_maintenance_8;
    }
    if (_extension == "VK_MESA_image_alignment_control")
    {
        return ktl::api::extension::mesa_image_alignment_control;
    }
    if (_extension == "VK_HUAWEI_extension_577")
    {
        return ktl::api::extension::huawei_extension_577;
    }
    if (_extension == "VK_EXT_extension_578")
    {
        return ktl::api::extension::ext_extension_578;
    }
    if (_extension == "VK_EXT_extension_579")
    {
        return ktl::api::extension::ext_extension_579;
    }
    if (_extension == "VK_KHR_shader_fma")
    {
        return ktl::api::extension::khr_shader_fma;
    }
    if (_extension == "VK_NV_push_constant_bank")
    {
        return ktl::api::extension::nv_push_constant_bank;
    }
    if (_extension == "VK_EXT_ray_tracing_invocation_reorder")
    {
        return ktl::api::extension::ext_ray_tracing_invocation_reorder;
    }
    if (_extension == "VK_EXT_depth_clamp_control")
    {
        return ktl::api::extension::ext_depth_clamp_control;
    }
    if (_extension == "VK_EXT_extension_584")
    {
        return ktl::api::extension::ext_extension_584;
    }
    if (_extension == "VK_KHR_maintenance9")
    {
        return ktl::api::extension::khr_maintenance_9;
    }
    if (_extension == "VK_IMG_extension_586")
    {
        return ktl::api::extension::img_extension_586;
    }
    if (_extension == "VK_OHOS_surface")
    {
        return ktl::api::extension::ohos_surface;
    }
    if (_extension == "VK_HUAWEI_extension_686")
    {
        return ktl::api::extension::huawei_extension_686;
    }
    if (_extension == "VK_OHOS_native_buffer")
    {
        return ktl::api::extension::ohos_native_buffer;
    }
    if (_extension == "VK_HUAWEI_extension_590")
    {
        return ktl::api::extension::huawei_extension_590;
    }
    if (_extension == "VK_HUAWEI_hdr_vivid")
    {
        return ktl::api::extension::huawei_hdr_vivid;
    }
    if (_extension == "VK_NV_extension_592")
    {
        return ktl::api::extension::nv_extension_592;
    }
    if (_extension == "VK_NV_extension_593")
    {
        return ktl::api::extension::nv_extension_593;
    }
    if (_extension == "VK_NV_cooperative_matrix2")
    {
        return ktl::api::extension::nv_cooperative_matrix_2;
    }
    if (_extension == "VK_NV_extension_595")
    {
        return ktl::api::extension::nv_extension_595;
    }
    if (_extension == "VK_KHR_extension_596")
    {
        return ktl::api::extension::khr_extension_596;
    }
    if (_extension == "VK_ARM_pipeline_opacity_micromap")
    {
        return ktl::api::extension::arm_pipeline_opacity_micromap;
    }
    if (_extension == "VK_KHR_extension_598")
    {
        return ktl::api::extension::khr_extension_598;
    }
    if (_extension == "VK_KHR_extension_599")
    {
        return ktl::api::extension::khr_extension_599;
    }
    if (_extension == "VK_IMG_extension_600")
    {
        return ktl::api::extension::img_extension_600;
    }
    if (_extension == "VK_IMG_extension_601")
    {
        return ktl::api::extension::img_extension_601;
    }
    if (_extension == "VK_EXT_extension_602")
    {
        return ktl::api::extension::ext_extension_602;
    }
    if (_extension == "VK_EXT_external_memory_metal")
    {
        return ktl::api::extension::ext_external_memory_metal;
    }
    if (_extension == "VK_EXT_extension_604")
    {
        return ktl::api::extension::ext_extension_604;
    }
    if (_extension == "VK_KHR_depth_clamp_zero_one")
    {
        return ktl::api::extension::khr_depth_clamp_zero_one;
    }
    if (_extension == "VK_ARM_performance_counters_by_region")
    {
        return ktl::api::extension::arm_performance_counters_by_region;
    }
    if (_extension == "VK_KHR_extension_607")
    {
        return ktl::api::extension::khr_extension_607;
    }
    if (_extension == "VK_ARM_shader_instrumentation")
    {
        return ktl::api::extension::arm_shader_instrumentation;
    }
    if (_extension == "VK_EXT_vertex_attribute_robustness")
    {
        return ktl::api::extension::ext_vertex_attribute_robustness;
    }
    if (_extension == "VK_ARM_format_pack")
    {
        return ktl::api::extension::arm_format_pack;
    }
    if (_extension == "VK_NV_extension_611")
    {
        return ktl::api::extension::nv_extension_611;
    }
    if (_extension == "VK_VALVE_fragment_density_map_layered")
    {
        return ktl::api::extension::valve_fragment_density_map_layered;
    }
    if (_extension == "VK_KHR_robustness2")
    {
        return ktl::api::extension::khr_robustness_2;
    }
    if (_extension == "VK_NV_present_metering")
    {
        return ktl::api::extension::nv_present_metering;
    }
    if (_extension == "VK_QCOM_extension_615")
    {
        return ktl::api::extension::qcom_extension_615;
    }
    if (_extension == "VK_EXT_extension_616")
    {
        return ktl::api::extension::ext_extension_616;
    }
    if (_extension == "VK_EXT_extension_617")
    {
        return ktl::api::extension::ext_extension_617;
    }
    if (_extension == "VK_EXT_extension_618")
    {
        return ktl::api::extension::ext_extension_618;
    }
    if (_extension == "VK_EXT_fragment_density_map_offset")
    {
        return ktl::api::extension::ext_fragment_density_map_offset;
    }
    if (_extension == "VK_EXT_zero_initialize_device_memory")
    {
        return ktl::api::extension::ext_zero_initialize_device_memory;
    }
    if (_extension == "VK_KHR_present_mode_fifo_latest_ready")
    {
        return ktl::api::extension::khr_present_mode_fifo_latest_ready;
    }
    if (_extension == "VK_EXT_extension_623")
    {
        return ktl::api::extension::ext_extension_623;
    }
    if (_extension == "VK_KHR_opacity_micromap")
    {
        return ktl::api::extension::khr_opacity_micromap;
    }
    if (_extension == "VK_KHR_extension_625")
    {
        return ktl::api::extension::khr_extension_625;
    }
    if (_extension == "VK_EXT_extension_626")
    {
        return ktl::api::extension::ext_extension_626;
    }
    if (_extension == "VK_NV_extension_627")
    {
        return ktl::api::extension::nv_extension_627;
    }
    if (_extension == "VK_EXT_shader_64bit_indexing")
    {
        return ktl::api::extension::ext_shader_64bit_indexing;
    }
    if (_extension == "VK_EXT_custom_resolve")
    {
        return ktl::api::extension::ext_custom_resolve;
    }
    if (_extension == "VK_QCOM_data_graph_model")
    {
        return ktl::api::extension::qcom_data_graph_model;
    }
    if (_extension == "VK_KHR_maintenance10")
    {
        return ktl::api::extension::khr_maintenance_10;
    }
    if (_extension == "VK_ARM_data_graph_optical_flow")
    {
        return ktl::api::extension::arm_data_graph_optical_flow;
    }
    if (_extension == "VK_MTK_extension_633")
    {
        return ktl::api::extension::mtk_extension_633;
    }
    if (_extension == "VK_NV_extension_634")
    {
        return ktl::api::extension::nv_extension_634;
    }
    if (_extension == "VK_MTK_extension_635")
    {
        return ktl::api::extension::mtk_extension_635;
    }
    if (_extension == "VK_EXT_shader_long_vector")
    {
        return ktl::api::extension::ext_shader_long_vector;
    }
    if (_extension == "VK_EXT_extension_637")
    {
        return ktl::api::extension::ext_extension_637;
    }
    if (_extension == "VK_SEC_pipeline_cache_incremental_mode")
    {
        return ktl::api::extension::sec_pipeline_cache_incremental_mode;
    }
    if (_extension == "VK_EXT_extension_639")
    {
        return ktl::api::extension::ext_extension_639;
    }
    if (_extension == "VK_NV_extension_640")
    {
        return ktl::api::extension::nv_extension_640;
    }
    if (_extension == "VK_EXT_extension_641")
    {
        return ktl::api::extension::ext_extension_641;
    }
    if (_extension == "VK_EXT_extension_642")
    {
        return ktl::api::extension::ext_extension_642;
    }
    if (_extension == "VK_EXT_shader_uniform_buffer_unsized_array")
    {
        return ktl::api::extension::ext_shader_uniform_buffer_unsized_array;
    }
    if (_extension == "VK_EXT_extension_644")
    {
        return ktl::api::extension::ext_extension_644;
    }
    if (_extension == "VK_EXT_extension_645")
    {
        return ktl::api::extension::ext_extension_645;
    }
    if (_extension == "VK_NV_compute_occupancy_priority")
    {
        return ktl::api::extension::nv_compute_occupancy_priority;
    }
    if (_extension == "VK_KHR_extension_647")
    {
        return ktl::api::extension::khr_extension_647;
    }
    if (_extension == "VK_KHR_extension_648")
    {
        return ktl::api::extension::khr_extension_648;
    }
    if (_extension == "VK_AMD_extension_649")
    {
        return ktl::api::extension::amd_extension_649;
    }
    if (_extension == "VK_AMD_extension_650")
    {
        return ktl::api::extension::amd_extension_650;
    }
    if (_extension == "VK_AMD_extension_651")
    {
        return ktl::api::extension::amd_extension_651;
    }
    if (_extension == "VK_AMD_extension_652")
    {
        return ktl::api::extension::amd_extension_652;
    }
    if (_extension == "VK_AMD_extension_653")
    {
        return ktl::api::extension::amd_extension_653;
    }
    if (_extension == "VK_VALVE_extension_654")
    {
        return ktl::api::extension::valve_extension_654;
    }
    if (_extension == "VK_ARM_extension_655")
    {
        return ktl::api::extension::arm_extension_655;
    }
    if (_extension == "VK_ARM_extension_656")
    {
        return ktl::api::extension::arm_extension_656;
    }
    if (_extension == "VK_ARM_extension_657")
    {
        return ktl::api::extension::arm_extension_657;
    }
    if (_extension == "VK_KHR_maintenance11")
    {
        return ktl::api::extension::khr_maintenance_11;
    }
    if (_extension == "VK_ARM_extension_659")
    {
        return ktl::api::extension::arm_extension_659;
    }
    if (_extension == "VK_EXT_extension_660")
    {
        return ktl::api::extension::ext_extension_660;
    }
    if (_extension == "VK_KHR_extension_661")
    {
        return ktl::api::extension::khr_extension_661;
    }
    if (_extension == "VK_VALVE_extension_662")
    {
        return ktl::api::extension::valve_extension_662;
    }
    if (_extension == "VK_EXT_shader_subgroup_partitioned")
    {
        return ktl::api::extension::ext_shader_subgroup_partitioned;
    }
    if (_extension == "VK_EXT_extension_664")
    {
        return ktl::api::extension::ext_extension_664;
    }
    if (_extension == "VK_SEC_ubm_surface")
    {
        return ktl::api::extension::sec_ubm_surface;
    }
    if (_extension == "VK_GOOGLE_extension_666")
    {
        return ktl::api::extension::google_extension_666;
    }
    if (_extension == "VK_HUAWEI_extension_667")
    {
        return ktl::api::extension::huawei_extension_667;
    }
    if (_extension == "VK_NV_extension_668")
    {
        return ktl::api::extension::nv_extension_668;
    }
    if (_extension == "VK_KHR_extension_669")
    {
        return ktl::api::extension::khr_extension_669;
    }
    if (_extension == "VK_NV_extension_670")
    {
        return ktl::api::extension::nv_extension_670;
    }
    if (_extension == "VK_ARM_extension_671")
    {
        return ktl::api::extension::arm_extension_671;
    }
    if (_extension == "VK_KHR_extension_672")
    {
        return ktl::api::extension::khr_extension_672;
    }
    if (_extension == "VK_EXT_extension_673")
    {
        return ktl::api::extension::ext_extension_673;
    }
    if (_extension == "VK_VALVE_shader_mixed_float_dot_product")
    {
        return ktl::api::extension::valve_shader_mixed_float_dot_product;
    }
    if (_extension == "VK_SEC_throttle_hint")
    {
        return ktl::api::extension::sec_throttle_hint;
    }
    if (_extension == "VK_EXT_extension_676")
    {
        return ktl::api::extension::ext_extension_676;
    }
    if (_extension == "VK_ARM_data_graph_neural_accelerator_statistics")
    {
        return ktl::api::extension::arm_data_graph_neural_accelerator_statistics;
    }
    if (_extension == "VK_EXT_extension_678")
    {
        return ktl::api::extension::ext_extension_678;
    }
    if (_extension == "VK_EXT_primitive_restart_index")
    {
        return ktl::api::extension::ext_primitive_restart_index;
    }
    if (_extension == "VK_EXT_extension_680")
    {
        return ktl::api::extension::ext_extension_680;
    }
    if (_extension == "VK_KHR_extension_681")
    {
        return ktl::api::extension::khr_extension_681;
    }
    if (_extension == "VK_VALVE_extension_682")
    {
        return ktl::api::extension::valve_extension_682;
    }
    if (_extension == "VK_EXT_extension_683")
    {
        return ktl::api::extension::ext_extension_683;
    }
    if (_extension == "VK_AMD_extension_684")
    {
        return ktl::api::extension::amd_extension_684;
    }
    if (_extension == "VK_AMD_extension_685")
    {
        return ktl::api::extension::amd_extension_685;
    }
    if (_extension == "VK_AMD_extension_687")
    {
        return ktl::api::extension::amd_extension_687;
    }
    if (_extension == "VK_AMD_extension_688")
    {
        return ktl::api::extension::amd_extension_688;
    }
    if (_extension == "VK_AMD_extension_689")
    {
        return ktl::api::extension::amd_extension_689;
    }
    if (_extension == "VK_NV_cooperative_matrix_decode_vector")
    {
        return ktl::api::extension::nv_cooperative_matrix_decode_vector;
    }
    if (_extension == "VK_MESA_fragment_coverage_mask")
    {
        return ktl::api::extension::mesa_fragment_coverage_mask;
    }
    if (_extension == "VK_EXT_extension_692")
    {
        return ktl::api::extension::ext_extension_692;
    }
    if (_extension == "VK_EXT_extension_693")
    {
        return ktl::api::extension::ext_extension_693;
    }
    return ktl::api::extension{};
}

inline constexpr ktl::meta::any_extension
extension_cast(ktl::api::extension _extension)
{
    if (_extension == ktl::api::extension::khr_surface)
    {
        return extension_cast< ktl::api::extension::khr_surface >();
    }
    if (_extension == ktl::api::extension::khr_swapchain)
    {
        return extension_cast< ktl::api::extension::khr_swapchain >();
    }
    if (_extension == ktl::api::extension::khr_display)
    {
        return extension_cast< ktl::api::extension::khr_display >();
    }
    if (_extension == ktl::api::extension::khr_display_swapchain)
    {
        return extension_cast< ktl::api::extension::khr_display_swapchain >();
    }
    if (_extension == ktl::api::extension::khr_xlib_surface)
    {
        return extension_cast< ktl::api::extension::khr_xlib_surface >();
    }
    if (_extension == ktl::api::extension::khr_xcb_surface)
    {
        return extension_cast< ktl::api::extension::khr_xcb_surface >();
    }
    if (_extension == ktl::api::extension::khr_wayland_surface)
    {
        return extension_cast< ktl::api::extension::khr_wayland_surface >();
    }
    if (_extension == ktl::api::extension::khr_mir_surface)
    {
        return extension_cast< ktl::api::extension::khr_mir_surface >();
    }
    if (_extension == ktl::api::extension::khr_android_surface)
    {
        return extension_cast< ktl::api::extension::khr_android_surface >();
    }
    if (_extension == ktl::api::extension::khr_win_32surface)
    {
        return extension_cast< ktl::api::extension::khr_win_32surface >();
    }
    if (_extension == ktl::api::extension::android_native_buffer)
    {
        return extension_cast< ktl::api::extension::android_native_buffer >();
    }
    if (_extension == ktl::api::extension::ext_debug_report)
    {
        return extension_cast< ktl::api::extension::ext_debug_report >();
    }
    if (_extension == ktl::api::extension::nv_glsl_shader)
    {
        return extension_cast< ktl::api::extension::nv_glsl_shader >();
    }
    if (_extension == ktl::api::extension::ext_depth_range_unrestricted)
    {
        return extension_cast< ktl::api::extension::ext_depth_range_unrestricted >();
    }
    if (_extension == ktl::api::extension::khr_sampler_mirror_clamp_to_edge)
    {
        return extension_cast< ktl::api::extension::khr_sampler_mirror_clamp_to_edge >();
    }
    if (_extension == ktl::api::extension::img_filter_cubic)
    {
        return extension_cast< ktl::api::extension::img_filter_cubic >();
    }
    if (_extension == ktl::api::extension::amd_extension_17)
    {
        return extension_cast< ktl::api::extension::amd_extension_17 >();
    }
    if (_extension == ktl::api::extension::amd_extension_18)
    {
        return extension_cast< ktl::api::extension::amd_extension_18 >();
    }
    if (_extension == ktl::api::extension::amd_rasterization_order)
    {
        return extension_cast< ktl::api::extension::amd_rasterization_order >();
    }
    if (_extension == ktl::api::extension::amd_extension_20)
    {
        return extension_cast< ktl::api::extension::amd_extension_20 >();
    }
    if (_extension == ktl::api::extension::amd_shader_trinary_minmax)
    {
        return extension_cast< ktl::api::extension::amd_shader_trinary_minmax >();
    }
    if (_extension == ktl::api::extension::amd_shader_explicit_vertex_parameter)
    {
        return extension_cast< ktl::api::extension::amd_shader_explicit_vertex_parameter >();
    }
    if (_extension == ktl::api::extension::ext_debug_marker)
    {
        return extension_cast< ktl::api::extension::ext_debug_marker >();
    }
    if (_extension == ktl::api::extension::khr_video_queue)
    {
        return extension_cast< ktl::api::extension::khr_video_queue >();
    }
    if (_extension == ktl::api::extension::amd_gcn_shader)
    {
        return extension_cast< ktl::api::extension::amd_gcn_shader >();
    }
    if (_extension == ktl::api::extension::nv_dedicated_allocation)
    {
        return extension_cast< ktl::api::extension::nv_dedicated_allocation >();
    }
    if (_extension == ktl::api::extension::ext_extension_28)
    {
        return extension_cast< ktl::api::extension::ext_extension_28 >();
    }
    if (_extension == ktl::api::extension::ext_transform_feedback)
    {
        return extension_cast< ktl::api::extension::ext_transform_feedback >();
    }
    if (_extension == ktl::api::extension::nvx_binary_import)
    {
        return extension_cast< ktl::api::extension::nvx_binary_import >();
    }
    if (_extension == ktl::api::extension::nvx_image_view_handle)
    {
        return extension_cast< ktl::api::extension::nvx_image_view_handle >();
    }
    if (_extension == ktl::api::extension::amd_extension_32)
    {
        return extension_cast< ktl::api::extension::amd_extension_32 >();
    }
    if (_extension == ktl::api::extension::amd_extension_33)
    {
        return extension_cast< ktl::api::extension::amd_extension_33 >();
    }
    if (_extension == ktl::api::extension::amd_draw_indirect_count)
    {
        return extension_cast< ktl::api::extension::amd_draw_indirect_count >();
    }
    if (_extension == ktl::api::extension::amd_extension_35)
    {
        return extension_cast< ktl::api::extension::amd_extension_35 >();
    }
    if (_extension == ktl::api::extension::amd_negative_viewport_height)
    {
        return extension_cast< ktl::api::extension::amd_negative_viewport_height >();
    }
    if (_extension == ktl::api::extension::amd_gpu_shader_half_float)
    {
        return extension_cast< ktl::api::extension::amd_gpu_shader_half_float >();
    }
    if (_extension == ktl::api::extension::amd_shader_ballot)
    {
        return extension_cast< ktl::api::extension::amd_shader_ballot >();
    }
    if (_extension == ktl::api::extension::amd_texture_gather_bias_lod)
    {
        return extension_cast< ktl::api::extension::amd_texture_gather_bias_lod >();
    }
    if (_extension == ktl::api::extension::amd_shader_info)
    {
        return extension_cast< ktl::api::extension::amd_shader_info >();
    }
    if (_extension == ktl::api::extension::amd_extension_44)
    {
        return extension_cast< ktl::api::extension::amd_extension_44 >();
    }
    if (_extension == ktl::api::extension::khr_dynamic_rendering)
    {
        return extension_cast< ktl::api::extension::khr_dynamic_rendering >();
    }
    if (_extension == ktl::api::extension::amd_extension_46)
    {
        return extension_cast< ktl::api::extension::amd_extension_46 >();
    }
    if (_extension == ktl::api::extension::amd_shader_image_load_store_lod)
    {
        return extension_cast< ktl::api::extension::amd_shader_image_load_store_lod >();
    }
    if (_extension == ktl::api::extension::nvx_extension_48)
    {
        return extension_cast< ktl::api::extension::nvx_extension_48 >();
    }
    if (_extension == ktl::api::extension::google_extension_49)
    {
        return extension_cast< ktl::api::extension::google_extension_49 >();
    }
    if (_extension == ktl::api::extension::ggp_stream_descriptor_surface)
    {
        return extension_cast< ktl::api::extension::ggp_stream_descriptor_surface >();
    }
    if (_extension == ktl::api::extension::nv_corner_sampled_image)
    {
        return extension_cast< ktl::api::extension::nv_corner_sampled_image >();
    }
    if (_extension == ktl::api::extension::nv_private_vendor_info)
    {
        return extension_cast< ktl::api::extension::nv_private_vendor_info >();
    }
    if (_extension == ktl::api::extension::nv_extension_53)
    {
        return extension_cast< ktl::api::extension::nv_extension_53 >();
    }
    if (_extension == ktl::api::extension::khr_multiview)
    {
        return extension_cast< ktl::api::extension::khr_multiview >();
    }
    if (_extension == ktl::api::extension::img_format_pvrtc)
    {
        return extension_cast< ktl::api::extension::img_format_pvrtc >();
    }
    if (_extension == ktl::api::extension::nv_external_memory_capabilities)
    {
        return extension_cast< ktl::api::extension::nv_external_memory_capabilities >();
    }
    if (_extension == ktl::api::extension::nv_external_memory)
    {
        return extension_cast< ktl::api::extension::nv_external_memory >();
    }
    if (_extension == ktl::api::extension::nv_external_memory_win_32)
    {
        return extension_cast< ktl::api::extension::nv_external_memory_win_32 >();
    }
    if (_extension == ktl::api::extension::nv_win_32keyed_mutex)
    {
        return extension_cast< ktl::api::extension::nv_win_32keyed_mutex >();
    }
    if (_extension == ktl::api::extension::khr_get_physical_device_properties_2)
    {
        return extension_cast< ktl::api::extension::khr_get_physical_device_properties_2 >();
    }
    if (_extension == ktl::api::extension::khr_device_group)
    {
        return extension_cast< ktl::api::extension::khr_device_group >();
    }
    if (_extension == ktl::api::extension::ext_validation_flags)
    {
        return extension_cast< ktl::api::extension::ext_validation_flags >();
    }
    if (_extension == ktl::api::extension::nn_vi_surface)
    {
        return extension_cast< ktl::api::extension::nn_vi_surface >();
    }
    if (_extension == ktl::api::extension::khr_shader_draw_parameters)
    {
        return extension_cast< ktl::api::extension::khr_shader_draw_parameters >();
    }
    if (_extension == ktl::api::extension::ext_shader_subgroup_ballot)
    {
        return extension_cast< ktl::api::extension::ext_shader_subgroup_ballot >();
    }
    if (_extension == ktl::api::extension::ext_shader_subgroup_vote)
    {
        return extension_cast< ktl::api::extension::ext_shader_subgroup_vote >();
    }
    if (_extension == ktl::api::extension::ext_texture_compression_astc_hdr)
    {
        return extension_cast< ktl::api::extension::ext_texture_compression_astc_hdr >();
    }
    if (_extension == ktl::api::extension::ext_astc_decode_mode)
    {
        return extension_cast< ktl::api::extension::ext_astc_decode_mode >();
    }
    if (_extension == ktl::api::extension::ext_pipeline_robustness)
    {
        return extension_cast< ktl::api::extension::ext_pipeline_robustness >();
    }
    if (_extension == ktl::api::extension::khr_maintenance_1)
    {
        return extension_cast< ktl::api::extension::khr_maintenance_1 >();
    }
    if (_extension == ktl::api::extension::khr_device_group_creation)
    {
        return extension_cast< ktl::api::extension::khr_device_group_creation >();
    }
    if (_extension == ktl::api::extension::khr_external_memory_capabilities)
    {
        return extension_cast< ktl::api::extension::khr_external_memory_capabilities >();
    }
    if (_extension == ktl::api::extension::khr_external_memory)
    {
        return extension_cast< ktl::api::extension::khr_external_memory >();
    }
    if (_extension == ktl::api::extension::khr_external_memory_win_32)
    {
        return extension_cast< ktl::api::extension::khr_external_memory_win_32 >();
    }
    if (_extension == ktl::api::extension::khr_external_memory_fd)
    {
        return extension_cast< ktl::api::extension::khr_external_memory_fd >();
    }
    if (_extension == ktl::api::extension::khr_win_32keyed_mutex)
    {
        return extension_cast< ktl::api::extension::khr_win_32keyed_mutex >();
    }
    if (_extension == ktl::api::extension::khr_external_semaphore_capabilities)
    {
        return extension_cast< ktl::api::extension::khr_external_semaphore_capabilities >();
    }
    if (_extension == ktl::api::extension::khr_external_semaphore)
    {
        return extension_cast< ktl::api::extension::khr_external_semaphore >();
    }
    if (_extension == ktl::api::extension::khr_external_semaphore_win_32)
    {
        return extension_cast< ktl::api::extension::khr_external_semaphore_win_32 >();
    }
    if (_extension == ktl::api::extension::khr_external_semaphore_fd)
    {
        return extension_cast< ktl::api::extension::khr_external_semaphore_fd >();
    }
    if (_extension == ktl::api::extension::khr_push_descriptor)
    {
        return extension_cast< ktl::api::extension::khr_push_descriptor >();
    }
    if (_extension == ktl::api::extension::ext_conditional_rendering)
    {
        return extension_cast< ktl::api::extension::ext_conditional_rendering >();
    }
    if (_extension == ktl::api::extension::khr_shader_float_16int_8)
    {
        return extension_cast< ktl::api::extension::khr_shader_float_16int_8 >();
    }
    if (_extension == ktl::api::extension::khr_16bit_storage)
    {
        return extension_cast< ktl::api::extension::khr_16bit_storage >();
    }
    if (_extension == ktl::api::extension::khr_incremental_present)
    {
        return extension_cast< ktl::api::extension::khr_incremental_present >();
    }
    if (_extension == ktl::api::extension::khr_descriptor_update_template)
    {
        return extension_cast< ktl::api::extension::khr_descriptor_update_template >();
    }
    if (_extension == ktl::api::extension::nvx_device_generated_commands)
    {
        return extension_cast< ktl::api::extension::nvx_device_generated_commands >();
    }
    if (_extension == ktl::api::extension::nv_clip_space_w_scaling)
    {
        return extension_cast< ktl::api::extension::nv_clip_space_w_scaling >();
    }
    if (_extension == ktl::api::extension::ext_direct_mode_display)
    {
        return extension_cast< ktl::api::extension::ext_direct_mode_display >();
    }
    if (_extension == ktl::api::extension::ext_acquire_xlib_display)
    {
        return extension_cast< ktl::api::extension::ext_acquire_xlib_display >();
    }
    if (_extension == ktl::api::extension::ext_display_surface_counter)
    {
        return extension_cast< ktl::api::extension::ext_display_surface_counter >();
    }
    if (_extension == ktl::api::extension::ext_display_control)
    {
        return extension_cast< ktl::api::extension::ext_display_control >();
    }
    if (_extension == ktl::api::extension::google_display_timing)
    {
        return extension_cast< ktl::api::extension::google_display_timing >();
    }
    if (_extension == ktl::api::extension::reserved_do_not_use_94)
    {
        return extension_cast< ktl::api::extension::reserved_do_not_use_94 >();
    }
    if (_extension == ktl::api::extension::nv_sample_mask_override_coverage)
    {
        return extension_cast< ktl::api::extension::nv_sample_mask_override_coverage >();
    }
    if (_extension == ktl::api::extension::nv_geometry_shader_passthrough)
    {
        return extension_cast< ktl::api::extension::nv_geometry_shader_passthrough >();
    }
    if (_extension == ktl::api::extension::nv_viewport_array_2)
    {
        return extension_cast< ktl::api::extension::nv_viewport_array_2 >();
    }
    if (_extension == ktl::api::extension::nvx_multiview_per_view_attributes)
    {
        return extension_cast< ktl::api::extension::nvx_multiview_per_view_attributes >();
    }
    if (_extension == ktl::api::extension::nv_viewport_swizzle)
    {
        return extension_cast< ktl::api::extension::nv_viewport_swizzle >();
    }
    if (_extension == ktl::api::extension::ext_discard_rectangles)
    {
        return extension_cast< ktl::api::extension::ext_discard_rectangles >();
    }
    if (_extension == ktl::api::extension::nv_extension_101)
    {
        return extension_cast< ktl::api::extension::nv_extension_101 >();
    }
    if (_extension == ktl::api::extension::ext_conservative_rasterization)
    {
        return extension_cast< ktl::api::extension::ext_conservative_rasterization >();
    }
    if (_extension == ktl::api::extension::ext_depth_clip_enable)
    {
        return extension_cast< ktl::api::extension::ext_depth_clip_enable >();
    }
    if (_extension == ktl::api::extension::nv_extension_104)
    {
        return extension_cast< ktl::api::extension::nv_extension_104 >();
    }
    if (_extension == ktl::api::extension::ext_swapchain_colorspace)
    {
        return extension_cast< ktl::api::extension::ext_swapchain_colorspace >();
    }
    if (_extension == ktl::api::extension::ext_hdr_metadata)
    {
        return extension_cast< ktl::api::extension::ext_hdr_metadata >();
    }
    if (_extension == ktl::api::extension::img_extension_107)
    {
        return extension_cast< ktl::api::extension::img_extension_107 >();
    }
    if (_extension == ktl::api::extension::img_extension_108)
    {
        return extension_cast< ktl::api::extension::img_extension_108 >();
    }
    if (_extension == ktl::api::extension::khr_imageless_framebuffer)
    {
        return extension_cast< ktl::api::extension::khr_imageless_framebuffer >();
    }
    if (_extension == ktl::api::extension::khr_create_renderpass_2)
    {
        return extension_cast< ktl::api::extension::khr_create_renderpass_2 >();
    }
    if (_extension == ktl::api::extension::img_relaxed_line_rasterization)
    {
        return extension_cast< ktl::api::extension::img_relaxed_line_rasterization >();
    }
    if (_extension == ktl::api::extension::khr_shared_presentable_image)
    {
        return extension_cast< ktl::api::extension::khr_shared_presentable_image >();
    }
    if (_extension == ktl::api::extension::khr_external_fence_capabilities)
    {
        return extension_cast< ktl::api::extension::khr_external_fence_capabilities >();
    }
    if (_extension == ktl::api::extension::khr_external_fence)
    {
        return extension_cast< ktl::api::extension::khr_external_fence >();
    }
    if (_extension == ktl::api::extension::khr_external_fence_win_32)
    {
        return extension_cast< ktl::api::extension::khr_external_fence_win_32 >();
    }
    if (_extension == ktl::api::extension::khr_external_fence_fd)
    {
        return extension_cast< ktl::api::extension::khr_external_fence_fd >();
    }
    if (_extension == ktl::api::extension::khr_performance_query)
    {
        return extension_cast< ktl::api::extension::khr_performance_query >();
    }
    if (_extension == ktl::api::extension::khr_maintenance_2)
    {
        return extension_cast< ktl::api::extension::khr_maintenance_2 >();
    }
    if (_extension == ktl::api::extension::khr_extension_119)
    {
        return extension_cast< ktl::api::extension::khr_extension_119 >();
    }
    if (_extension == ktl::api::extension::khr_get_surface_capabilities_2)
    {
        return extension_cast< ktl::api::extension::khr_get_surface_capabilities_2 >();
    }
    if (_extension == ktl::api::extension::khr_variable_pointers)
    {
        return extension_cast< ktl::api::extension::khr_variable_pointers >();
    }
    if (_extension == ktl::api::extension::khr_get_display_properties_2)
    {
        return extension_cast< ktl::api::extension::khr_get_display_properties_2 >();
    }
    if (_extension == ktl::api::extension::mvk_ios_surface)
    {
        return extension_cast< ktl::api::extension::mvk_ios_surface >();
    }
    if (_extension == ktl::api::extension::mvk_macos_surface)
    {
        return extension_cast< ktl::api::extension::mvk_macos_surface >();
    }
    if (_extension == ktl::api::extension::mvk_moltenvk)
    {
        return extension_cast< ktl::api::extension::mvk_moltenvk >();
    }
    if (_extension == ktl::api::extension::ext_external_memory_dma_buf)
    {
        return extension_cast< ktl::api::extension::ext_external_memory_dma_buf >();
    }
    if (_extension == ktl::api::extension::ext_queue_family_foreign)
    {
        return extension_cast< ktl::api::extension::ext_queue_family_foreign >();
    }
    if (_extension == ktl::api::extension::khr_dedicated_allocation)
    {
        return extension_cast< ktl::api::extension::khr_dedicated_allocation >();
    }
    if (_extension == ktl::api::extension::ext_debug_utils)
    {
        return extension_cast< ktl::api::extension::ext_debug_utils >();
    }
    if (_extension == ktl::api::extension::android_external_memory_android_hardware_buffer)
    {
        return extension_cast< ktl::api::extension::android_external_memory_android_hardware_buffer >();
    }
    if (_extension == ktl::api::extension::ext_sampler_filter_minmax)
    {
        return extension_cast< ktl::api::extension::ext_sampler_filter_minmax >();
    }
    if (_extension == ktl::api::extension::khr_storage_buffer_storage_class)
    {
        return extension_cast< ktl::api::extension::khr_storage_buffer_storage_class >();
    }
    if (_extension == ktl::api::extension::amd_gpu_shader_int_16)
    {
        return extension_cast< ktl::api::extension::amd_gpu_shader_int_16 >();
    }
    if (_extension == ktl::api::extension::amd_gpa_interface)
    {
        return extension_cast< ktl::api::extension::amd_gpa_interface >();
    }
    if (_extension == ktl::api::extension::amdx_shader_enqueue)
    {
        return extension_cast< ktl::api::extension::amdx_shader_enqueue >();
    }
    if (_extension == ktl::api::extension::ext_descriptor_heap)
    {
        return extension_cast< ktl::api::extension::ext_descriptor_heap >();
    }
    if (_extension == ktl::api::extension::amd_mixed_attachment_samples)
    {
        return extension_cast< ktl::api::extension::amd_mixed_attachment_samples >();
    }
    if (_extension == ktl::api::extension::amd_shader_fragment_mask)
    {
        return extension_cast< ktl::api::extension::amd_shader_fragment_mask >();
    }
    if (_extension == ktl::api::extension::ext_inline_uniform_block)
    {
        return extension_cast< ktl::api::extension::ext_inline_uniform_block >();
    }
    if (_extension == ktl::api::extension::amd_extension_140)
    {
        return extension_cast< ktl::api::extension::amd_extension_140 >();
    }
    if (_extension == ktl::api::extension::ext_shader_stencil_export)
    {
        return extension_cast< ktl::api::extension::ext_shader_stencil_export >();
    }
    if (_extension == ktl::api::extension::khr_shader_bfloat_16)
    {
        return extension_cast< ktl::api::extension::khr_shader_bfloat_16 >();
    }
    if (_extension == ktl::api::extension::amd_extension_143)
    {
        return extension_cast< ktl::api::extension::amd_extension_143 >();
    }
    if (_extension == ktl::api::extension::ext_sample_locations)
    {
        return extension_cast< ktl::api::extension::ext_sample_locations >();
    }
    if (_extension == ktl::api::extension::khr_relaxed_block_layout)
    {
        return extension_cast< ktl::api::extension::khr_relaxed_block_layout >();
    }
    if (_extension == ktl::api::extension::reserved_do_not_use_146)
    {
        return extension_cast< ktl::api::extension::reserved_do_not_use_146 >();
    }
    if (_extension == ktl::api::extension::khr_get_memory_requirements_2)
    {
        return extension_cast< ktl::api::extension::khr_get_memory_requirements_2 >();
    }
    if (_extension == ktl::api::extension::khr_image_format_list)
    {
        return extension_cast< ktl::api::extension::khr_image_format_list >();
    }
    if (_extension == ktl::api::extension::ext_blend_operation_advanced)
    {
        return extension_cast< ktl::api::extension::ext_blend_operation_advanced >();
    }
    if (_extension == ktl::api::extension::nv_fragment_coverage_to_color)
    {
        return extension_cast< ktl::api::extension::nv_fragment_coverage_to_color >();
    }
    if (_extension == ktl::api::extension::khr_acceleration_structure)
    {
        return extension_cast< ktl::api::extension::khr_acceleration_structure >();
    }
    if (_extension == ktl::api::extension::khr_ray_tracing_pipeline)
    {
        return extension_cast< ktl::api::extension::khr_ray_tracing_pipeline >();
    }
    if (_extension == ktl::api::extension::khr_ray_query)
    {
        return extension_cast< ktl::api::extension::khr_ray_query >();
    }
    if (_extension == ktl::api::extension::nv_extension_152)
    {
        return extension_cast< ktl::api::extension::nv_extension_152 >();
    }
    if (_extension == ktl::api::extension::nv_framebuffer_mixed_samples)
    {
        return extension_cast< ktl::api::extension::nv_framebuffer_mixed_samples >();
    }
    if (_extension == ktl::api::extension::nv_fill_rectangle)
    {
        return extension_cast< ktl::api::extension::nv_fill_rectangle >();
    }
    if (_extension == ktl::api::extension::nv_shader_sm_builtins)
    {
        return extension_cast< ktl::api::extension::nv_shader_sm_builtins >();
    }
    if (_extension == ktl::api::extension::ext_post_depth_coverage)
    {
        return extension_cast< ktl::api::extension::ext_post_depth_coverage >();
    }
    if (_extension == ktl::api::extension::khr_sampler_ycbcr_conversion)
    {
        return extension_cast< ktl::api::extension::khr_sampler_ycbcr_conversion >();
    }
    if (_extension == ktl::api::extension::khr_bind_memory_2)
    {
        return extension_cast< ktl::api::extension::khr_bind_memory_2 >();
    }
    if (_extension == ktl::api::extension::ext_image_drm_format_modifier)
    {
        return extension_cast< ktl::api::extension::ext_image_drm_format_modifier >();
    }
    if (_extension == ktl::api::extension::ext_extension_160)
    {
        return extension_cast< ktl::api::extension::ext_extension_160 >();
    }
    if (_extension == ktl::api::extension::ext_validation_cache)
    {
        return extension_cast< ktl::api::extension::ext_validation_cache >();
    }
    if (_extension == ktl::api::extension::ext_descriptor_indexing)
    {
        return extension_cast< ktl::api::extension::ext_descriptor_indexing >();
    }
    if (_extension == ktl::api::extension::ext_shader_viewport_index_layer)
    {
        return extension_cast< ktl::api::extension::ext_shader_viewport_index_layer >();
    }
    if (_extension == ktl::api::extension::khr_portability_subset)
    {
        return extension_cast< ktl::api::extension::khr_portability_subset >();
    }
    if (_extension == ktl::api::extension::nv_shading_rate_image)
    {
        return extension_cast< ktl::api::extension::nv_shading_rate_image >();
    }
    if (_extension == ktl::api::extension::nv_ray_tracing)
    {
        return extension_cast< ktl::api::extension::nv_ray_tracing >();
    }
    if (_extension == ktl::api::extension::nv_representative_fragment_test)
    {
        return extension_cast< ktl::api::extension::nv_representative_fragment_test >();
    }
    if (_extension == ktl::api::extension::nv_extension_168)
    {
        return extension_cast< ktl::api::extension::nv_extension_168 >();
    }
    if (_extension == ktl::api::extension::khr_maintenance_3)
    {
        return extension_cast< ktl::api::extension::khr_maintenance_3 >();
    }
    if (_extension == ktl::api::extension::khr_draw_indirect_count)
    {
        return extension_cast< ktl::api::extension::khr_draw_indirect_count >();
    }
    if (_extension == ktl::api::extension::ext_filter_cubic)
    {
        return extension_cast< ktl::api::extension::ext_filter_cubic >();
    }
    if (_extension == ktl::api::extension::qcom_render_pass_shader_resolve)
    {
        return extension_cast< ktl::api::extension::qcom_render_pass_shader_resolve >();
    }
    if (_extension == ktl::api::extension::qcom_cooperative_matrix_conversion)
    {
        return extension_cast< ktl::api::extension::qcom_cooperative_matrix_conversion >();
    }
    if (_extension == ktl::api::extension::qcom_elapsed_timer_query)
    {
        return extension_cast< ktl::api::extension::qcom_elapsed_timer_query >();
    }
    if (_extension == ktl::api::extension::ext_global_priority)
    {
        return extension_cast< ktl::api::extension::ext_global_priority >();
    }
    if (_extension == ktl::api::extension::khr_shader_subgroup_extended_types)
    {
        return extension_cast< ktl::api::extension::khr_shader_subgroup_extended_types >();
    }
    if (_extension == ktl::api::extension::ext_extension_177)
    {
        return extension_cast< ktl::api::extension::ext_extension_177 >();
    }
    if (_extension == ktl::api::extension::khr_8bit_storage)
    {
        return extension_cast< ktl::api::extension::khr_8bit_storage >();
    }
    if (_extension == ktl::api::extension::ext_external_memory_host)
    {
        return extension_cast< ktl::api::extension::ext_external_memory_host >();
    }
    if (_extension == ktl::api::extension::amd_buffer_marker)
    {
        return extension_cast< ktl::api::extension::amd_buffer_marker >();
    }
    if (_extension == ktl::api::extension::khr_shader_atomic_int_64)
    {
        return extension_cast< ktl::api::extension::khr_shader_atomic_int_64 >();
    }
    if (_extension == ktl::api::extension::khr_shader_clock)
    {
        return extension_cast< ktl::api::extension::khr_shader_clock >();
    }
    if (_extension == ktl::api::extension::amd_extension_183)
    {
        return extension_cast< ktl::api::extension::amd_extension_183 >();
    }
    if (_extension == ktl::api::extension::amd_pipeline_compiler_control)
    {
        return extension_cast< ktl::api::extension::amd_pipeline_compiler_control >();
    }
    if (_extension == ktl::api::extension::ext_calibrated_timestamps)
    {
        return extension_cast< ktl::api::extension::ext_calibrated_timestamps >();
    }
    if (_extension == ktl::api::extension::amd_shader_core_properties)
    {
        return extension_cast< ktl::api::extension::amd_shader_core_properties >();
    }
    if (_extension == ktl::api::extension::amd_extension_187)
    {
        return extension_cast< ktl::api::extension::amd_extension_187 >();
    }
    if (_extension == ktl::api::extension::khr_global_priority)
    {
        return extension_cast< ktl::api::extension::khr_global_priority >();
    }
    if (_extension == ktl::api::extension::amd_memory_overallocation_behavior)
    {
        return extension_cast< ktl::api::extension::amd_memory_overallocation_behavior >();
    }
    if (_extension == ktl::api::extension::ext_vertex_attribute_divisor)
    {
        return extension_cast< ktl::api::extension::ext_vertex_attribute_divisor >();
    }
    if (_extension == ktl::api::extension::ggp_frame_token)
    {
        return extension_cast< ktl::api::extension::ggp_frame_token >();
    }
    if (_extension == ktl::api::extension::ext_pipeline_creation_feedback)
    {
        return extension_cast< ktl::api::extension::ext_pipeline_creation_feedback >();
    }
    if (_extension == ktl::api::extension::google_extension_194)
    {
        return extension_cast< ktl::api::extension::google_extension_194 >();
    }
    if (_extension == ktl::api::extension::google_extension_195)
    {
        return extension_cast< ktl::api::extension::google_extension_195 >();
    }
    if (_extension == ktl::api::extension::google_extension_196)
    {
        return extension_cast< ktl::api::extension::google_extension_196 >();
    }
    if (_extension == ktl::api::extension::khr_driver_properties)
    {
        return extension_cast< ktl::api::extension::khr_driver_properties >();
    }
    if (_extension == ktl::api::extension::khr_shader_float_controls)
    {
        return extension_cast< ktl::api::extension::khr_shader_float_controls >();
    }
    if (_extension == ktl::api::extension::nv_shader_subgroup_partitioned)
    {
        return extension_cast< ktl::api::extension::nv_shader_subgroup_partitioned >();
    }
    if (_extension == ktl::api::extension::khr_depth_stencil_resolve)
    {
        return extension_cast< ktl::api::extension::khr_depth_stencil_resolve >();
    }
    if (_extension == ktl::api::extension::khr_swapchain_mutable_format)
    {
        return extension_cast< ktl::api::extension::khr_swapchain_mutable_format >();
    }
    if (_extension == ktl::api::extension::nv_compute_shader_derivatives)
    {
        return extension_cast< ktl::api::extension::nv_compute_shader_derivatives >();
    }
    if (_extension == ktl::api::extension::nv_mesh_shader)
    {
        return extension_cast< ktl::api::extension::nv_mesh_shader >();
    }
    if (_extension == ktl::api::extension::nv_fragment_shader_barycentric)
    {
        return extension_cast< ktl::api::extension::nv_fragment_shader_barycentric >();
    }
    if (_extension == ktl::api::extension::nv_shader_image_footprint)
    {
        return extension_cast< ktl::api::extension::nv_shader_image_footprint >();
    }
    if (_extension == ktl::api::extension::nv_scissor_exclusive)
    {
        return extension_cast< ktl::api::extension::nv_scissor_exclusive >();
    }
    if (_extension == ktl::api::extension::nv_device_diagnostic_checkpoints)
    {
        return extension_cast< ktl::api::extension::nv_device_diagnostic_checkpoints >();
    }
    if (_extension == ktl::api::extension::khr_timeline_semaphore)
    {
        return extension_cast< ktl::api::extension::khr_timeline_semaphore >();
    }
    if (_extension == ktl::api::extension::ext_present_timing)
    {
        return extension_cast< ktl::api::extension::ext_present_timing >();
    }
    if (_extension == ktl::api::extension::intel_shader_integer_functions_2)
    {
        return extension_cast< ktl::api::extension::intel_shader_integer_functions_2 >();
    }
    if (_extension == ktl::api::extension::intel_performance_query)
    {
        return extension_cast< ktl::api::extension::intel_performance_query >();
    }
    if (_extension == ktl::api::extension::khr_vulkan_memory_model)
    {
        return extension_cast< ktl::api::extension::khr_vulkan_memory_model >();
    }
    if (_extension == ktl::api::extension::ext_pci_bus_info)
    {
        return extension_cast< ktl::api::extension::ext_pci_bus_info >();
    }
    if (_extension == ktl::api::extension::amd_display_native_hdr)
    {
        return extension_cast< ktl::api::extension::amd_display_native_hdr >();
    }
    if (_extension == ktl::api::extension::fuchsia_imagepipe_surface)
    {
        return extension_cast< ktl::api::extension::fuchsia_imagepipe_surface >();
    }
    if (_extension == ktl::api::extension::khr_shader_terminate_invocation)
    {
        return extension_cast< ktl::api::extension::khr_shader_terminate_invocation >();
    }
    if (_extension == ktl::api::extension::google_extension_217)
    {
        return extension_cast< ktl::api::extension::google_extension_217 >();
    }
    if (_extension == ktl::api::extension::ext_metal_surface)
    {
        return extension_cast< ktl::api::extension::ext_metal_surface >();
    }
    if (_extension == ktl::api::extension::ext_fragment_density_map)
    {
        return extension_cast< ktl::api::extension::ext_fragment_density_map >();
    }
    if (_extension == ktl::api::extension::ext_extension_220)
    {
        return extension_cast< ktl::api::extension::ext_extension_220 >();
    }
    if (_extension == ktl::api::extension::khr_extension_221)
    {
        return extension_cast< ktl::api::extension::khr_extension_221 >();
    }
    if (_extension == ktl::api::extension::ext_scalar_block_layout)
    {
        return extension_cast< ktl::api::extension::ext_scalar_block_layout >();
    }
    if (_extension == ktl::api::extension::ext_extension_223)
    {
        return extension_cast< ktl::api::extension::ext_extension_223 >();
    }
    if (_extension == ktl::api::extension::google_hlsl_functionality_1)
    {
        return extension_cast< ktl::api::extension::google_hlsl_functionality_1 >();
    }
    if (_extension == ktl::api::extension::google_decorate_string)
    {
        return extension_cast< ktl::api::extension::google_decorate_string >();
    }
    if (_extension == ktl::api::extension::ext_subgroup_size_control)
    {
        return extension_cast< ktl::api::extension::ext_subgroup_size_control >();
    }
    if (_extension == ktl::api::extension::khr_fragment_shading_rate)
    {
        return extension_cast< ktl::api::extension::khr_fragment_shading_rate >();
    }
    if (_extension == ktl::api::extension::amd_shader_core_properties_2)
    {
        return extension_cast< ktl::api::extension::amd_shader_core_properties_2 >();
    }
    if (_extension == ktl::api::extension::amd_extension_229)
    {
        return extension_cast< ktl::api::extension::amd_extension_229 >();
    }
    if (_extension == ktl::api::extension::amd_device_coherent_memory)
    {
        return extension_cast< ktl::api::extension::amd_device_coherent_memory >();
    }
    if (_extension == ktl::api::extension::amd_extension_231)
    {
        return extension_cast< ktl::api::extension::amd_extension_231 >();
    }
    if (_extension == ktl::api::extension::khr_shader_constant_data)
    {
        return extension_cast< ktl::api::extension::khr_shader_constant_data >();
    }
    if (_extension == ktl::api::extension::khr_dynamic_rendering_local_read)
    {
        return extension_cast< ktl::api::extension::khr_dynamic_rendering_local_read >();
    }
    if (_extension == ktl::api::extension::khr_shader_abort)
    {
        return extension_cast< ktl::api::extension::khr_shader_abort >();
    }
    if (_extension == ktl::api::extension::ext_shader_image_atomic_int_64)
    {
        return extension_cast< ktl::api::extension::ext_shader_image_atomic_int_64 >();
    }
    if (_extension == ktl::api::extension::khr_shader_quad_control)
    {
        return extension_cast< ktl::api::extension::khr_shader_quad_control >();
    }
    if (_extension == ktl::api::extension::khr_spirv_14)
    {
        return extension_cast< ktl::api::extension::khr_spirv_14 >();
    }
    if (_extension == ktl::api::extension::ext_memory_budget)
    {
        return extension_cast< ktl::api::extension::ext_memory_budget >();
    }
    if (_extension == ktl::api::extension::ext_memory_priority)
    {
        return extension_cast< ktl::api::extension::ext_memory_priority >();
    }
    if (_extension == ktl::api::extension::khr_surface_protected_capabilities)
    {
        return extension_cast< ktl::api::extension::khr_surface_protected_capabilities >();
    }
    if (_extension == ktl::api::extension::nv_dedicated_allocation_image_aliasing)
    {
        return extension_cast< ktl::api::extension::nv_dedicated_allocation_image_aliasing >();
    }
    if (_extension == ktl::api::extension::khr_separate_depth_stencil_layouts)
    {
        return extension_cast< ktl::api::extension::khr_separate_depth_stencil_layouts >();
    }
    if (_extension == ktl::api::extension::intel_extension_243)
    {
        return extension_cast< ktl::api::extension::intel_extension_243 >();
    }
    if (_extension == ktl::api::extension::mesa_extension_244)
    {
        return extension_cast< ktl::api::extension::mesa_extension_244 >();
    }
    if (_extension == ktl::api::extension::ext_buffer_device_address)
    {
        return extension_cast< ktl::api::extension::ext_buffer_device_address >();
    }
    if (_extension == ktl::api::extension::ext_tooling_info)
    {
        return extension_cast< ktl::api::extension::ext_tooling_info >();
    }
    if (_extension == ktl::api::extension::ext_separate_stencil_usage)
    {
        return extension_cast< ktl::api::extension::ext_separate_stencil_usage >();
    }
    if (_extension == ktl::api::extension::ext_validation_features)
    {
        return extension_cast< ktl::api::extension::ext_validation_features >();
    }
    if (_extension == ktl::api::extension::khr_present_wait)
    {
        return extension_cast< ktl::api::extension::khr_present_wait >();
    }
    if (_extension == ktl::api::extension::nv_cooperative_matrix)
    {
        return extension_cast< ktl::api::extension::nv_cooperative_matrix >();
    }
    if (_extension == ktl::api::extension::nv_coverage_reduction_mode)
    {
        return extension_cast< ktl::api::extension::nv_coverage_reduction_mode >();
    }
    if (_extension == ktl::api::extension::ext_fragment_shader_interlock)
    {
        return extension_cast< ktl::api::extension::ext_fragment_shader_interlock >();
    }
    if (_extension == ktl::api::extension::ext_ycbcr_image_arrays)
    {
        return extension_cast< ktl::api::extension::ext_ycbcr_image_arrays >();
    }
    if (_extension == ktl::api::extension::khr_uniform_buffer_standard_layout)
    {
        return extension_cast< ktl::api::extension::khr_uniform_buffer_standard_layout >();
    }
    if (_extension == ktl::api::extension::ext_provoking_vertex)
    {
        return extension_cast< ktl::api::extension::ext_provoking_vertex >();
    }
    if (_extension == ktl::api::extension::ext_full_screen_exclusive)
    {
        return extension_cast< ktl::api::extension::ext_full_screen_exclusive >();
    }
    if (_extension == ktl::api::extension::ext_headless_surface)
    {
        return extension_cast< ktl::api::extension::ext_headless_surface >();
    }
    if (_extension == ktl::api::extension::khr_buffer_device_address)
    {
        return extension_cast< ktl::api::extension::khr_buffer_device_address >();
    }
    if (_extension == ktl::api::extension::ext_extension_259)
    {
        return extension_cast< ktl::api::extension::ext_extension_259 >();
    }
    if (_extension == ktl::api::extension::ext_line_rasterization)
    {
        return extension_cast< ktl::api::extension::ext_line_rasterization >();
    }
    if (_extension == ktl::api::extension::ext_shader_atomic_float)
    {
        return extension_cast< ktl::api::extension::ext_shader_atomic_float >();
    }
    if (_extension == ktl::api::extension::ext_host_query_reset)
    {
        return extension_cast< ktl::api::extension::ext_host_query_reset >();
    }
    if (_extension == ktl::api::extension::ggp_extension_263)
    {
        return extension_cast< ktl::api::extension::ggp_extension_263 >();
    }
    if (_extension == ktl::api::extension::brcm_extension_264)
    {
        return extension_cast< ktl::api::extension::brcm_extension_264 >();
    }
    if (_extension == ktl::api::extension::brcm_extension_265)
    {
        return extension_cast< ktl::api::extension::brcm_extension_265 >();
    }
    if (_extension == ktl::api::extension::ext_index_type_uint_8)
    {
        return extension_cast< ktl::api::extension::ext_index_type_uint_8 >();
    }
    if (_extension == ktl::api::extension::ext_extension_267)
    {
        return extension_cast< ktl::api::extension::ext_extension_267 >();
    }
    if (_extension == ktl::api::extension::ext_extended_dynamic_state)
    {
        return extension_cast< ktl::api::extension::ext_extended_dynamic_state >();
    }
    if (_extension == ktl::api::extension::khr_deferred_host_operations)
    {
        return extension_cast< ktl::api::extension::khr_deferred_host_operations >();
    }
    if (_extension == ktl::api::extension::khr_pipeline_executable_properties)
    {
        return extension_cast< ktl::api::extension::khr_pipeline_executable_properties >();
    }
    if (_extension == ktl::api::extension::ext_host_image_copy)
    {
        return extension_cast< ktl::api::extension::ext_host_image_copy >();
    }
    if (_extension == ktl::api::extension::khr_map_memory_2)
    {
        return extension_cast< ktl::api::extension::khr_map_memory_2 >();
    }
    if (_extension == ktl::api::extension::ext_map_memory_placed)
    {
        return extension_cast< ktl::api::extension::ext_map_memory_placed >();
    }
    if (_extension == ktl::api::extension::ext_shader_atomic_float_2)
    {
        return extension_cast< ktl::api::extension::ext_shader_atomic_float_2 >();
    }
    if (_extension == ktl::api::extension::ext_surface_maintenance_1)
    {
        return extension_cast< ktl::api::extension::ext_surface_maintenance_1 >();
    }
    if (_extension == ktl::api::extension::ext_swapchain_maintenance_1)
    {
        return extension_cast< ktl::api::extension::ext_swapchain_maintenance_1 >();
    }
    if (_extension == ktl::api::extension::ext_shader_demote_to_helper_invocation)
    {
        return extension_cast< ktl::api::extension::ext_shader_demote_to_helper_invocation >();
    }
    if (_extension == ktl::api::extension::nv_device_generated_commands)
    {
        return extension_cast< ktl::api::extension::nv_device_generated_commands >();
    }
    if (_extension == ktl::api::extension::nv_inherited_viewport_scissor)
    {
        return extension_cast< ktl::api::extension::nv_inherited_viewport_scissor >();
    }
    if (_extension == ktl::api::extension::khr_extension_280)
    {
        return extension_cast< ktl::api::extension::khr_extension_280 >();
    }
    if (_extension == ktl::api::extension::khr_shader_integer_dot_product)
    {
        return extension_cast< ktl::api::extension::khr_shader_integer_dot_product >();
    }
    if (_extension == ktl::api::extension::ext_texel_buffer_alignment)
    {
        return extension_cast< ktl::api::extension::ext_texel_buffer_alignment >();
    }
    if (_extension == ktl::api::extension::qcom_render_pass_transform)
    {
        return extension_cast< ktl::api::extension::qcom_render_pass_transform >();
    }
    if (_extension == ktl::api::extension::ext_depth_bias_control)
    {
        return extension_cast< ktl::api::extension::ext_depth_bias_control >();
    }
    if (_extension == ktl::api::extension::ext_device_memory_report)
    {
        return extension_cast< ktl::api::extension::ext_device_memory_report >();
    }
    if (_extension == ktl::api::extension::ext_acquire_drm_display)
    {
        return extension_cast< ktl::api::extension::ext_acquire_drm_display >();
    }
    if (_extension == ktl::api::extension::ext_robustness_2)
    {
        return extension_cast< ktl::api::extension::ext_robustness_2 >();
    }
    if (_extension == ktl::api::extension::ext_custom_border_color)
    {
        return extension_cast< ktl::api::extension::ext_custom_border_color >();
    }
    if (_extension == ktl::api::extension::ext_texture_compression_astc_3d)
    {
        return extension_cast< ktl::api::extension::ext_texture_compression_astc_3d >();
    }
    if (_extension == ktl::api::extension::google_user_type)
    {
        return extension_cast< ktl::api::extension::google_user_type >();
    }
    if (_extension == ktl::api::extension::khr_pipeline_library)
    {
        return extension_cast< ktl::api::extension::khr_pipeline_library >();
    }
    if (_extension == ktl::api::extension::nv_extension_292)
    {
        return extension_cast< ktl::api::extension::nv_extension_292 >();
    }
    if (_extension == ktl::api::extension::nv_present_barrier)
    {
        return extension_cast< ktl::api::extension::nv_present_barrier >();
    }
    if (_extension == ktl::api::extension::khr_shader_non_semantic_info)
    {
        return extension_cast< ktl::api::extension::khr_shader_non_semantic_info >();
    }
    if (_extension == ktl::api::extension::khr_present_id)
    {
        return extension_cast< ktl::api::extension::khr_present_id >();
    }
    if (_extension == ktl::api::extension::ext_private_data)
    {
        return extension_cast< ktl::api::extension::ext_private_data >();
    }
    if (_extension == ktl::api::extension::khr_extension_297)
    {
        return extension_cast< ktl::api::extension::khr_extension_297 >();
    }
    if (_extension == ktl::api::extension::ext_pipeline_creation_cache_control)
    {
        return extension_cast< ktl::api::extension::ext_pipeline_creation_cache_control >();
    }
    if (_extension == ktl::api::extension::khr_extension_299)
    {
        return extension_cast< ktl::api::extension::khr_extension_299 >();
    }
    if (_extension == ktl::api::extension::nv_device_diagnostics_config)
    {
        return extension_cast< ktl::api::extension::nv_device_diagnostics_config >();
    }
    if (_extension == ktl::api::extension::qcom_render_pass_store_ops)
    {
        return extension_cast< ktl::api::extension::qcom_render_pass_store_ops >();
    }
    if (_extension == ktl::api::extension::qcom_queue_perf_hint)
    {
        return extension_cast< ktl::api::extension::qcom_queue_perf_hint >();
    }
    if (_extension == ktl::api::extension::qcom_image_processing_3)
    {
        return extension_cast< ktl::api::extension::qcom_image_processing_3 >();
    }
    if (_extension == ktl::api::extension::qcom_shader_multiple_wait_queues)
    {
        return extension_cast< ktl::api::extension::qcom_shader_multiple_wait_queues >();
    }
    if (_extension == ktl::api::extension::ext_shader_split_barrier)
    {
        return extension_cast< ktl::api::extension::ext_shader_split_barrier >();
    }
    if (_extension == ktl::api::extension::qcom_extension_307)
    {
        return extension_cast< ktl::api::extension::qcom_extension_307 >();
    }
    if (_extension == ktl::api::extension::nv_cuda_kernel_launch)
    {
        return extension_cast< ktl::api::extension::nv_cuda_kernel_launch >();
    }
    if (_extension == ktl::api::extension::khr_object_refresh)
    {
        return extension_cast< ktl::api::extension::khr_object_refresh >();
    }
    if (_extension == ktl::api::extension::qcom_tile_shading)
    {
        return extension_cast< ktl::api::extension::qcom_tile_shading >();
    }
    if (_extension == ktl::api::extension::nv_low_latency)
    {
        return extension_cast< ktl::api::extension::nv_low_latency >();
    }
    if (_extension == ktl::api::extension::ext_metal_objects)
    {
        return extension_cast< ktl::api::extension::ext_metal_objects >();
    }
    if (_extension == ktl::api::extension::ext_extension_313)
    {
        return extension_cast< ktl::api::extension::ext_extension_313 >();
    }
    if (_extension == ktl::api::extension::amd_extension_314)
    {
        return extension_cast< ktl::api::extension::amd_extension_314 >();
    }
    if (_extension == ktl::api::extension::khr_synchronization_2)
    {
        return extension_cast< ktl::api::extension::khr_synchronization_2 >();
    }
    if (_extension == ktl::api::extension::amd_extension_316)
    {
        return extension_cast< ktl::api::extension::amd_extension_316 >();
    }
    if (_extension == ktl::api::extension::ext_descriptor_buffer)
    {
        return extension_cast< ktl::api::extension::ext_descriptor_buffer >();
    }
    if (_extension == ktl::api::extension::amd_extension_318)
    {
        return extension_cast< ktl::api::extension::amd_extension_318 >();
    }
    if (_extension == ktl::api::extension::khr_device_address_commands)
    {
        return extension_cast< ktl::api::extension::khr_device_address_commands >();
    }
    if (_extension == ktl::api::extension::amd_extension_320)
    {
        return extension_cast< ktl::api::extension::amd_extension_320 >();
    }
    if (_extension == ktl::api::extension::ext_graphics_pipeline_library)
    {
        return extension_cast< ktl::api::extension::ext_graphics_pipeline_library >();
    }
    if (_extension == ktl::api::extension::amd_shader_early_and_late_fragment_tests)
    {
        return extension_cast< ktl::api::extension::amd_shader_early_and_late_fragment_tests >();
    }
    if (_extension == ktl::api::extension::khr_fragment_shader_barycentric)
    {
        return extension_cast< ktl::api::extension::khr_fragment_shader_barycentric >();
    }
    if (_extension == ktl::api::extension::khr_shader_subgroup_uniform_control_flow)
    {
        return extension_cast< ktl::api::extension::khr_shader_subgroup_uniform_control_flow >();
    }
    if (_extension == ktl::api::extension::khr_extension_325)
    {
        return extension_cast< ktl::api::extension::khr_extension_325 >();
    }
    if (_extension == ktl::api::extension::khr_zero_initialize_workgroup_memory)
    {
        return extension_cast< ktl::api::extension::khr_zero_initialize_workgroup_memory >();
    }
    if (_extension == ktl::api::extension::nv_fragment_shading_rate_enums)
    {
        return extension_cast< ktl::api::extension::nv_fragment_shading_rate_enums >();
    }
    if (_extension == ktl::api::extension::nv_ray_tracing_motion_blur)
    {
        return extension_cast< ktl::api::extension::nv_ray_tracing_motion_blur >();
    }
    if (_extension == ktl::api::extension::ext_mesh_shader)
    {
        return extension_cast< ktl::api::extension::ext_mesh_shader >();
    }
    if (_extension == ktl::api::extension::nv_extension_330)
    {
        return extension_cast< ktl::api::extension::nv_extension_330 >();
    }
    if (_extension == ktl::api::extension::ext_ycbcr_2plane_444formats)
    {
        return extension_cast< ktl::api::extension::ext_ycbcr_2plane_444formats >();
    }
    if (_extension == ktl::api::extension::nv_extension_332)
    {
        return extension_cast< ktl::api::extension::nv_extension_332 >();
    }
    if (_extension == ktl::api::extension::ext_fragment_density_map_2)
    {
        return extension_cast< ktl::api::extension::ext_fragment_density_map_2 >();
    }
    if (_extension == ktl::api::extension::qcom_rotated_copy_commands)
    {
        return extension_cast< ktl::api::extension::qcom_rotated_copy_commands >();
    }
    if (_extension == ktl::api::extension::khr_extension_335)
    {
        return extension_cast< ktl::api::extension::khr_extension_335 >();
    }
    if (_extension == ktl::api::extension::ext_image_robustness)
    {
        return extension_cast< ktl::api::extension::ext_image_robustness >();
    }
    if (_extension == ktl::api::extension::khr_workgroup_memory_explicit_layout)
    {
        return extension_cast< ktl::api::extension::khr_workgroup_memory_explicit_layout >();
    }
    if (_extension == ktl::api::extension::khr_copy_commands_2)
    {
        return extension_cast< ktl::api::extension::khr_copy_commands_2 >();
    }
    if (_extension == ktl::api::extension::ext_image_compression_control)
    {
        return extension_cast< ktl::api::extension::ext_image_compression_control >();
    }
    if (_extension == ktl::api::extension::ext_attachment_feedback_loop_layout)
    {
        return extension_cast< ktl::api::extension::ext_attachment_feedback_loop_layout >();
    }
    if (_extension == ktl::api::extension::ext_4444formats)
    {
        return extension_cast< ktl::api::extension::ext_4444formats >();
    }
    if (_extension == ktl::api::extension::ext_device_fault)
    {
        return extension_cast< ktl::api::extension::ext_device_fault >();
    }
    if (_extension == ktl::api::extension::arm_rasterization_order_attachment_access)
    {
        return extension_cast< ktl::api::extension::arm_rasterization_order_attachment_access >();
    }
    if (_extension == ktl::api::extension::arm_extension_344)
    {
        return extension_cast< ktl::api::extension::arm_extension_344 >();
    }
    if (_extension == ktl::api::extension::ext_rgba_10x_6formats)
    {
        return extension_cast< ktl::api::extension::ext_rgba_10x_6formats >();
    }
    if (_extension == ktl::api::extension::nv_acquire_winrt_display)
    {
        return extension_cast< ktl::api::extension::nv_acquire_winrt_display >();
    }
    if (_extension == ktl::api::extension::ext_directfb_surface)
    {
        return extension_cast< ktl::api::extension::ext_directfb_surface >();
    }
    if (_extension == ktl::api::extension::khr_extension_350)
    {
        return extension_cast< ktl::api::extension::khr_extension_350 >();
    }
    if (_extension == ktl::api::extension::nv_extension_351)
    {
        return extension_cast< ktl::api::extension::nv_extension_351 >();
    }
    if (_extension == ktl::api::extension::valve_mutable_descriptor_type)
    {
        return extension_cast< ktl::api::extension::valve_mutable_descriptor_type >();
    }
    if (_extension == ktl::api::extension::ext_vertex_input_dynamic_state)
    {
        return extension_cast< ktl::api::extension::ext_vertex_input_dynamic_state >();
    }
    if (_extension == ktl::api::extension::ext_physical_device_drm)
    {
        return extension_cast< ktl::api::extension::ext_physical_device_drm >();
    }
    if (_extension == ktl::api::extension::ext_device_address_binding_report)
    {
        return extension_cast< ktl::api::extension::ext_device_address_binding_report >();
    }
    if (_extension == ktl::api::extension::ext_depth_clip_control)
    {
        return extension_cast< ktl::api::extension::ext_depth_clip_control >();
    }
    if (_extension == ktl::api::extension::ext_primitive_topology_list_restart)
    {
        return extension_cast< ktl::api::extension::ext_primitive_topology_list_restart >();
    }
    if (_extension == ktl::api::extension::khr_extension_358)
    {
        return extension_cast< ktl::api::extension::khr_extension_358 >();
    }
    if (_extension == ktl::api::extension::ext_extension_359)
    {
        return extension_cast< ktl::api::extension::ext_extension_359 >();
    }
    if (_extension == ktl::api::extension::ext_extension_360)
    {
        return extension_cast< ktl::api::extension::ext_extension_360 >();
    }
    if (_extension == ktl::api::extension::khr_format_feature_flags_2)
    {
        return extension_cast< ktl::api::extension::khr_format_feature_flags_2 >();
    }
    if (_extension == ktl::api::extension::ext_present_mode_fifo_latest_ready)
    {
        return extension_cast< ktl::api::extension::ext_present_mode_fifo_latest_ready >();
    }
    if (_extension == ktl::api::extension::ext_extension_363)
    {
        return extension_cast< ktl::api::extension::ext_extension_363 >();
    }
    if (_extension == ktl::api::extension::fuchsia_extension_364)
    {
        return extension_cast< ktl::api::extension::fuchsia_extension_364 >();
    }
    if (_extension == ktl::api::extension::fuchsia_external_memory)
    {
        return extension_cast< ktl::api::extension::fuchsia_external_memory >();
    }
    if (_extension == ktl::api::extension::fuchsia_external_semaphore)
    {
        return extension_cast< ktl::api::extension::fuchsia_external_semaphore >();
    }
    if (_extension == ktl::api::extension::fuchsia_buffer_collection)
    {
        return extension_cast< ktl::api::extension::fuchsia_buffer_collection >();
    }
    if (_extension == ktl::api::extension::fuchsia_extension_368)
    {
        return extension_cast< ktl::api::extension::fuchsia_extension_368 >();
    }
    if (_extension == ktl::api::extension::qcom_extension_369)
    {
        return extension_cast< ktl::api::extension::qcom_extension_369 >();
    }
    if (_extension == ktl::api::extension::huawei_subpass_shading)
    {
        return extension_cast< ktl::api::extension::huawei_subpass_shading >();
    }
    if (_extension == ktl::api::extension::huawei_invocation_mask)
    {
        return extension_cast< ktl::api::extension::huawei_invocation_mask >();
    }
    if (_extension == ktl::api::extension::nv_external_memory_rdma)
    {
        return extension_cast< ktl::api::extension::nv_external_memory_rdma >();
    }
    if (_extension == ktl::api::extension::ext_pipeline_properties)
    {
        return extension_cast< ktl::api::extension::ext_pipeline_properties >();
    }
    if (_extension == ktl::api::extension::nv_external_sci_sync)
    {
        return extension_cast< ktl::api::extension::nv_external_sci_sync >();
    }
    if (_extension == ktl::api::extension::nv_external_memory_sci_buf)
    {
        return extension_cast< ktl::api::extension::nv_external_memory_sci_buf >();
    }
    if (_extension == ktl::api::extension::ext_frame_boundary)
    {
        return extension_cast< ktl::api::extension::ext_frame_boundary >();
    }
    if (_extension == ktl::api::extension::ext_multisampled_render_to_single_sampled)
    {
        return extension_cast< ktl::api::extension::ext_multisampled_render_to_single_sampled >();
    }
    if (_extension == ktl::api::extension::ext_extended_dynamic_state_2)
    {
        return extension_cast< ktl::api::extension::ext_extended_dynamic_state_2 >();
    }
    if (_extension == ktl::api::extension::qnx_screen_surface)
    {
        return extension_cast< ktl::api::extension::qnx_screen_surface >();
    }
    if (_extension == ktl::api::extension::khr_extension_380)
    {
        return extension_cast< ktl::api::extension::khr_extension_380 >();
    }
    if (_extension == ktl::api::extension::khr_extension_381)
    {
        return extension_cast< ktl::api::extension::khr_extension_381 >();
    }
    if (_extension == ktl::api::extension::ext_color_write_enable)
    {
        return extension_cast< ktl::api::extension::ext_color_write_enable >();
    }
    if (_extension == ktl::api::extension::ext_primitives_generated_query)
    {
        return extension_cast< ktl::api::extension::ext_primitives_generated_query >();
    }
    if (_extension == ktl::api::extension::ext_extension_384)
    {
        return extension_cast< ktl::api::extension::ext_extension_384 >();
    }
    if (_extension == ktl::api::extension::mesa_extension_385)
    {
        return extension_cast< ktl::api::extension::mesa_extension_385 >();
    }
    if (_extension == ktl::api::extension::google_extension_386)
    {
        return extension_cast< ktl::api::extension::google_extension_386 >();
    }
    if (_extension == ktl::api::extension::khr_ray_tracing_maintenance_1)
    {
        return extension_cast< ktl::api::extension::khr_ray_tracing_maintenance_1 >();
    }
    if (_extension == ktl::api::extension::khr_shader_untyped_pointers)
    {
        return extension_cast< ktl::api::extension::khr_shader_untyped_pointers >();
    }
    if (_extension == ktl::api::extension::ext_global_priority_query)
    {
        return extension_cast< ktl::api::extension::ext_global_priority_query >();
    }
    if (_extension == ktl::api::extension::ext_extension_390)
    {
        return extension_cast< ktl::api::extension::ext_extension_390 >();
    }
    if (_extension == ktl::api::extension::ext_image_view_min_lod)
    {
        return extension_cast< ktl::api::extension::ext_image_view_min_lod >();
    }
    if (_extension == ktl::api::extension::ext_multi_draw)
    {
        return extension_cast< ktl::api::extension::ext_multi_draw >();
    }
    if (_extension == ktl::api::extension::ext_image_2d_view_of_3d)
    {
        return extension_cast< ktl::api::extension::ext_image_2d_view_of_3d >();
    }
    if (_extension == ktl::api::extension::khr_portability_enumeration)
    {
        return extension_cast< ktl::api::extension::khr_portability_enumeration >();
    }
    if (_extension == ktl::api::extension::ext_shader_tile_image)
    {
        return extension_cast< ktl::api::extension::ext_shader_tile_image >();
    }
    if (_extension == ktl::api::extension::ext_opacity_micromap)
    {
        return extension_cast< ktl::api::extension::ext_opacity_micromap >();
    }
    if (_extension == ktl::api::extension::nv_displacement_micromap)
    {
        return extension_cast< ktl::api::extension::nv_displacement_micromap >();
    }
    if (_extension == ktl::api::extension::juice_extension_399)
    {
        return extension_cast< ktl::api::extension::juice_extension_399 >();
    }
    if (_extension == ktl::api::extension::juice_extension_400)
    {
        return extension_cast< ktl::api::extension::juice_extension_400 >();
    }
    if (_extension == ktl::api::extension::ext_load_store_op_none)
    {
        return extension_cast< ktl::api::extension::ext_load_store_op_none >();
    }
    if (_extension == ktl::api::extension::fb_extension_402)
    {
        return extension_cast< ktl::api::extension::fb_extension_402 >();
    }
    if (_extension == ktl::api::extension::fb_extension_403)
    {
        return extension_cast< ktl::api::extension::fb_extension_403 >();
    }
    if (_extension == ktl::api::extension::fb_extension_404)
    {
        return extension_cast< ktl::api::extension::fb_extension_404 >();
    }
    if (_extension == ktl::api::extension::huawei_cluster_culling_shader)
    {
        return extension_cast< ktl::api::extension::huawei_cluster_culling_shader >();
    }
    if (_extension == ktl::api::extension::huawei_extension_406)
    {
        return extension_cast< ktl::api::extension::huawei_extension_406 >();
    }
    if (_extension == ktl::api::extension::ggp_extension_407)
    {
        return extension_cast< ktl::api::extension::ggp_extension_407 >();
    }
    if (_extension == ktl::api::extension::ggp_extension_408)
    {
        return extension_cast< ktl::api::extension::ggp_extension_408 >();
    }
    if (_extension == ktl::api::extension::ggp_extension_409)
    {
        return extension_cast< ktl::api::extension::ggp_extension_409 >();
    }
    if (_extension == ktl::api::extension::ggp_extension_410)
    {
        return extension_cast< ktl::api::extension::ggp_extension_410 >();
    }
    if (_extension == ktl::api::extension::ggp_extension_411)
    {
        return extension_cast< ktl::api::extension::ggp_extension_411 >();
    }
    if (_extension == ktl::api::extension::ext_border_color_swizzle)
    {
        return extension_cast< ktl::api::extension::ext_border_color_swizzle >();
    }
    if (_extension == ktl::api::extension::ext_pageable_device_local_memory)
    {
        return extension_cast< ktl::api::extension::ext_pageable_device_local_memory >();
    }
    if (_extension == ktl::api::extension::khr_maintenance_4)
    {
        return extension_cast< ktl::api::extension::khr_maintenance_4 >();
    }
    if (_extension == ktl::api::extension::huawei_extension_415)
    {
        return extension_cast< ktl::api::extension::huawei_extension_415 >();
    }
    if (_extension == ktl::api::extension::arm_shader_core_properties)
    {
        return extension_cast< ktl::api::extension::arm_shader_core_properties >();
    }
    if (_extension == ktl::api::extension::khr_shader_subgroup_rotate)
    {
        return extension_cast< ktl::api::extension::khr_shader_subgroup_rotate >();
    }
    if (_extension == ktl::api::extension::arm_scheduling_controls)
    {
        return extension_cast< ktl::api::extension::arm_scheduling_controls >();
    }
    if (_extension == ktl::api::extension::ext_image_sliced_view_of_3d)
    {
        return extension_cast< ktl::api::extension::ext_image_sliced_view_of_3d >();
    }
    if (_extension == ktl::api::extension::ext_extension_420)
    {
        return extension_cast< ktl::api::extension::ext_extension_420 >();
    }
    if (_extension == ktl::api::extension::valve_descriptor_set_host_mapping)
    {
        return extension_cast< ktl::api::extension::valve_descriptor_set_host_mapping >();
    }
    if (_extension == ktl::api::extension::ext_depth_clamp_zero_one)
    {
        return extension_cast< ktl::api::extension::ext_depth_clamp_zero_one >();
    }
    if (_extension == ktl::api::extension::ext_non_seamless_cube_map)
    {
        return extension_cast< ktl::api::extension::ext_non_seamless_cube_map >();
    }
    if (_extension == ktl::api::extension::arm_extension_424)
    {
        return extension_cast< ktl::api::extension::arm_extension_424 >();
    }
    if (_extension == ktl::api::extension::arm_render_pass_striped)
    {
        return extension_cast< ktl::api::extension::arm_render_pass_striped >();
    }
    if (_extension == ktl::api::extension::qcom_fragment_density_map_offset)
    {
        return extension_cast< ktl::api::extension::qcom_fragment_density_map_offset >();
    }
    if (_extension == ktl::api::extension::nv_copy_memory_indirect)
    {
        return extension_cast< ktl::api::extension::nv_copy_memory_indirect >();
    }
    if (_extension == ktl::api::extension::nv_memory_decompression)
    {
        return extension_cast< ktl::api::extension::nv_memory_decompression >();
    }
    if (_extension == ktl::api::extension::nv_device_generated_commands_compute)
    {
        return extension_cast< ktl::api::extension::nv_device_generated_commands_compute >();
    }
    if (_extension == ktl::api::extension::nv_ray_tracing_linear_swept_spheres)
    {
        return extension_cast< ktl::api::extension::nv_ray_tracing_linear_swept_spheres >();
    }
    if (_extension == ktl::api::extension::nv_linear_color_attachment)
    {
        return extension_cast< ktl::api::extension::nv_linear_color_attachment >();
    }
    if (_extension == ktl::api::extension::nv_extension_432)
    {
        return extension_cast< ktl::api::extension::nv_extension_432 >();
    }
    if (_extension == ktl::api::extension::nv_extension_433)
    {
        return extension_cast< ktl::api::extension::nv_extension_433 >();
    }
    if (_extension == ktl::api::extension::google_surfaceless_query)
    {
        return extension_cast< ktl::api::extension::google_surfaceless_query >();
    }
    if (_extension == ktl::api::extension::khr_shader_maximal_reconvergence)
    {
        return extension_cast< ktl::api::extension::khr_shader_maximal_reconvergence >();
    }
    if (_extension == ktl::api::extension::ext_application_parameters)
    {
        return extension_cast< ktl::api::extension::ext_application_parameters >();
    }
    if (_extension == ktl::api::extension::ext_extension_437)
    {
        return extension_cast< ktl::api::extension::ext_extension_437 >();
    }
    if (_extension == ktl::api::extension::ext_image_compression_control_swapchain)
    {
        return extension_cast< ktl::api::extension::ext_image_compression_control_swapchain >();
    }
    if (_extension == ktl::api::extension::sec_extension_439)
    {
        return extension_cast< ktl::api::extension::sec_extension_439 >();
    }
    if (_extension == ktl::api::extension::qcom_extension_440)
    {
        return extension_cast< ktl::api::extension::qcom_extension_440 >();
    }
    if (_extension == ktl::api::extension::qcom_image_processing)
    {
        return extension_cast< ktl::api::extension::qcom_image_processing >();
    }
    if (_extension == ktl::api::extension::coreavi_extension_442)
    {
        return extension_cast< ktl::api::extension::coreavi_extension_442 >();
    }
    if (_extension == ktl::api::extension::coreavi_extension_443)
    {
        return extension_cast< ktl::api::extension::coreavi_extension_443 >();
    }
    if (_extension == ktl::api::extension::coreavi_extension_444)
    {
        return extension_cast< ktl::api::extension::coreavi_extension_444 >();
    }
    if (_extension == ktl::api::extension::coreavi_extension_445)
    {
        return extension_cast< ktl::api::extension::coreavi_extension_445 >();
    }
    if (_extension == ktl::api::extension::coreavi_extension_446)
    {
        return extension_cast< ktl::api::extension::coreavi_extension_446 >();
    }
    if (_extension == ktl::api::extension::coreavi_extension_447)
    {
        return extension_cast< ktl::api::extension::coreavi_extension_447 >();
    }
    if (_extension == ktl::api::extension::sec_extension_448)
    {
        return extension_cast< ktl::api::extension::sec_extension_448 >();
    }
    if (_extension == ktl::api::extension::sec_extension_449)
    {
        return extension_cast< ktl::api::extension::sec_extension_449 >();
    }
    if (_extension == ktl::api::extension::sec_extension_450)
    {
        return extension_cast< ktl::api::extension::sec_extension_450 >();
    }
    if (_extension == ktl::api::extension::sec_extension_451)
    {
        return extension_cast< ktl::api::extension::sec_extension_451 >();
    }
    if (_extension == ktl::api::extension::ext_nested_command_buffer)
    {
        return extension_cast< ktl::api::extension::ext_nested_command_buffer >();
    }
    if (_extension == ktl::api::extension::ohos_external_memory)
    {
        return extension_cast< ktl::api::extension::ohos_external_memory >();
    }
    if (_extension == ktl::api::extension::ext_external_memory_acquire_unmodified)
    {
        return extension_cast< ktl::api::extension::ext_external_memory_acquire_unmodified >();
    }
    if (_extension == ktl::api::extension::google_extension_455)
    {
        return extension_cast< ktl::api::extension::google_extension_455 >();
    }
    if (_extension == ktl::api::extension::ext_extended_dynamic_state_3)
    {
        return extension_cast< ktl::api::extension::ext_extended_dynamic_state_3 >();
    }
    if (_extension == ktl::api::extension::ext_extension_457)
    {
        return extension_cast< ktl::api::extension::ext_extension_457 >();
    }
    if (_extension == ktl::api::extension::ext_extension_458)
    {
        return extension_cast< ktl::api::extension::ext_extension_458 >();
    }
    if (_extension == ktl::api::extension::ext_subpass_merge_feedback)
    {
        return extension_cast< ktl::api::extension::ext_subpass_merge_feedback >();
    }
    if (_extension == ktl::api::extension::lunarg_direct_driver_loading)
    {
        return extension_cast< ktl::api::extension::lunarg_direct_driver_loading >();
    }
    if (_extension == ktl::api::extension::arm_tensors)
    {
        return extension_cast< ktl::api::extension::arm_tensors >();
    }
    if (_extension == ktl::api::extension::ext_extension_462)
    {
        return extension_cast< ktl::api::extension::ext_extension_462 >();
    }
    if (_extension == ktl::api::extension::ext_shader_module_identifier)
    {
        return extension_cast< ktl::api::extension::ext_shader_module_identifier >();
    }
    if (_extension == ktl::api::extension::ext_rasterization_order_attachment_access)
    {
        return extension_cast< ktl::api::extension::ext_rasterization_order_attachment_access >();
    }
    if (_extension == ktl::api::extension::nv_optical_flow)
    {
        return extension_cast< ktl::api::extension::nv_optical_flow >();
    }
    if (_extension == ktl::api::extension::ext_legacy_dithering)
    {
        return extension_cast< ktl::api::extension::ext_legacy_dithering >();
    }
    if (_extension == ktl::api::extension::ext_pipeline_protected_access)
    {
        return extension_cast< ktl::api::extension::ext_pipeline_protected_access >();
    }
    if (_extension == ktl::api::extension::ext_extension_468)
    {
        return extension_cast< ktl::api::extension::ext_extension_468 >();
    }
    if (_extension == ktl::api::extension::android_external_format_resolve)
    {
        return extension_cast< ktl::api::extension::android_external_format_resolve >();
    }
    if (_extension == ktl::api::extension::amd_extension_470)
    {
        return extension_cast< ktl::api::extension::amd_extension_470 >();
    }
    if (_extension == ktl::api::extension::khr_maintenance_5)
    {
        return extension_cast< ktl::api::extension::khr_maintenance_5 >();
    }
    if (_extension == ktl::api::extension::amd_extension_472)
    {
        return extension_cast< ktl::api::extension::amd_extension_472 >();
    }
    if (_extension == ktl::api::extension::amd_extension_473)
    {
        return extension_cast< ktl::api::extension::amd_extension_473 >();
    }
    if (_extension == ktl::api::extension::amd_extension_474)
    {
        return extension_cast< ktl::api::extension::amd_extension_474 >();
    }
    if (_extension == ktl::api::extension::amd_extension_475)
    {
        return extension_cast< ktl::api::extension::amd_extension_475 >();
    }
    if (_extension == ktl::api::extension::amd_extension_476)
    {
        return extension_cast< ktl::api::extension::amd_extension_476 >();
    }
    if (_extension == ktl::api::extension::amd_anti_lag)
    {
        return extension_cast< ktl::api::extension::amd_anti_lag >();
    }
    if (_extension == ktl::api::extension::amd_extension_478)
    {
        return extension_cast< ktl::api::extension::amd_extension_478 >();
    }
    if (_extension == ktl::api::extension::amdx_dense_geometry_format)
    {
        return extension_cast< ktl::api::extension::amdx_dense_geometry_format >();
    }
    if (_extension == ktl::api::extension::khr_present_id_2)
    {
        return extension_cast< ktl::api::extension::khr_present_id_2 >();
    }
    if (_extension == ktl::api::extension::khr_present_wait_2)
    {
        return extension_cast< ktl::api::extension::khr_present_wait_2 >();
    }
    if (_extension == ktl::api::extension::khr_ray_tracing_position_fetch)
    {
        return extension_cast< ktl::api::extension::khr_ray_tracing_position_fetch >();
    }
    if (_extension == ktl::api::extension::ext_shader_object)
    {
        return extension_cast< ktl::api::extension::ext_shader_object >();
    }
    if (_extension == ktl::api::extension::khr_pipeline_binary)
    {
        return extension_cast< ktl::api::extension::khr_pipeline_binary >();
    }
    if (_extension == ktl::api::extension::qcom_tile_properties)
    {
        return extension_cast< ktl::api::extension::qcom_tile_properties >();
    }
    if (_extension == ktl::api::extension::sec_amigo_profiling)
    {
        return extension_cast< ktl::api::extension::sec_amigo_profiling >();
    }
    if (_extension == ktl::api::extension::khr_surface_maintenance_1)
    {
        return extension_cast< ktl::api::extension::khr_surface_maintenance_1 >();
    }
    if (_extension == ktl::api::extension::khr_swapchain_maintenance_1)
    {
        return extension_cast< ktl::api::extension::khr_swapchain_maintenance_1 >();
    }
    if (_extension == ktl::api::extension::qcom_multiview_per_view_viewports)
    {
        return extension_cast< ktl::api::extension::qcom_multiview_per_view_viewports >();
    }
    if (_extension == ktl::api::extension::nv_external_sci_sync_2)
    {
        return extension_cast< ktl::api::extension::nv_external_sci_sync_2 >();
    }
    if (_extension == ktl::api::extension::nv_ray_tracing_invocation_reorder)
    {
        return extension_cast< ktl::api::extension::nv_ray_tracing_invocation_reorder >();
    }
    if (_extension == ktl::api::extension::nv_cooperative_vector)
    {
        return extension_cast< ktl::api::extension::nv_cooperative_vector >();
    }
    if (_extension == ktl::api::extension::nv_extended_sparse_address_space)
    {
        return extension_cast< ktl::api::extension::nv_extended_sparse_address_space >();
    }
    if (_extension == ktl::api::extension::nv_extension_494)
    {
        return extension_cast< ktl::api::extension::nv_extension_494 >();
    }
    if (_extension == ktl::api::extension::ext_mutable_descriptor_type)
    {
        return extension_cast< ktl::api::extension::ext_mutable_descriptor_type >();
    }
    if (_extension == ktl::api::extension::ext_legacy_vertex_attributes)
    {
        return extension_cast< ktl::api::extension::ext_legacy_vertex_attributes >();
    }
    if (_extension == ktl::api::extension::ext_layer_settings)
    {
        return extension_cast< ktl::api::extension::ext_layer_settings >();
    }
    if (_extension == ktl::api::extension::arm_shader_core_builtins)
    {
        return extension_cast< ktl::api::extension::arm_shader_core_builtins >();
    }
    if (_extension == ktl::api::extension::ext_pipeline_library_group_handles)
    {
        return extension_cast< ktl::api::extension::ext_pipeline_library_group_handles >();
    }
    if (_extension == ktl::api::extension::ext_dynamic_rendering_unused_attachments)
    {
        return extension_cast< ktl::api::extension::ext_dynamic_rendering_unused_attachments >();
    }
    if (_extension == ktl::api::extension::ext_extension_501)
    {
        return extension_cast< ktl::api::extension::ext_extension_501 >();
    }
    if (_extension == ktl::api::extension::ext_extension_502)
    {
        return extension_cast< ktl::api::extension::ext_extension_502 >();
    }
    if (_extension == ktl::api::extension::ext_extension_503)
    {
        return extension_cast< ktl::api::extension::ext_extension_503 >();
    }
    if (_extension == ktl::api::extension::nv_extension_504)
    {
        return extension_cast< ktl::api::extension::nv_extension_504 >();
    }
    if (_extension == ktl::api::extension::khr_internally_synchronized_queues)
    {
        return extension_cast< ktl::api::extension::khr_internally_synchronized_queues >();
    }
    if (_extension == ktl::api::extension::nv_low_latency_2)
    {
        return extension_cast< ktl::api::extension::nv_low_latency_2 >();
    }
    if (_extension == ktl::api::extension::khr_cooperative_matrix)
    {
        return extension_cast< ktl::api::extension::khr_cooperative_matrix >();
    }
    if (_extension == ktl::api::extension::arm_data_graph)
    {
        return extension_cast< ktl::api::extension::arm_data_graph >();
    }
    if (_extension == ktl::api::extension::arm_data_graph_instruction_set_tosa)
    {
        return extension_cast< ktl::api::extension::arm_data_graph_instruction_set_tosa >();
    }
    if (_extension == ktl::api::extension::mesa_extension_510)
    {
        return extension_cast< ktl::api::extension::mesa_extension_510 >();
    }
    if (_extension == ktl::api::extension::qcom_multiview_per_view_render_areas)
    {
        return extension_cast< ktl::api::extension::qcom_multiview_per_view_render_areas >();
    }
    if (_extension == ktl::api::extension::khr_compute_shader_derivatives)
    {
        return extension_cast< ktl::api::extension::khr_compute_shader_derivatives >();
    }
    if (_extension == ktl::api::extension::nv_per_stage_descriptor_set)
    {
        return extension_cast< ktl::api::extension::nv_per_stage_descriptor_set >();
    }
    if (_extension == ktl::api::extension::mesa_extension_518)
    {
        return extension_cast< ktl::api::extension::mesa_extension_518 >();
    }
    if (_extension == ktl::api::extension::qcom_image_processing_2)
    {
        return extension_cast< ktl::api::extension::qcom_image_processing_2 >();
    }
    if (_extension == ktl::api::extension::qcom_filter_cubic_weights)
    {
        return extension_cast< ktl::api::extension::qcom_filter_cubic_weights >();
    }
    if (_extension == ktl::api::extension::qcom_ycbcr_degamma)
    {
        return extension_cast< ktl::api::extension::qcom_ycbcr_degamma >();
    }
    if (_extension == ktl::api::extension::qcom_filter_cubic_clamp)
    {
        return extension_cast< ktl::api::extension::qcom_filter_cubic_clamp >();
    }
    if (_extension == ktl::api::extension::ext_extension_523)
    {
        return extension_cast< ktl::api::extension::ext_extension_523 >();
    }
    if (_extension == ktl::api::extension::ext_extension_524)
    {
        return extension_cast< ktl::api::extension::ext_extension_524 >();
    }
    if (_extension == ktl::api::extension::ext_attachment_feedback_loop_dynamic_state)
    {
        return extension_cast< ktl::api::extension::ext_attachment_feedback_loop_dynamic_state >();
    }
    if (_extension == ktl::api::extension::khr_vertex_attribute_divisor)
    {
        return extension_cast< ktl::api::extension::khr_vertex_attribute_divisor >();
    }
    if (_extension == ktl::api::extension::khr_load_store_op_none)
    {
        return extension_cast< ktl::api::extension::khr_load_store_op_none >();
    }
    if (_extension == ktl::api::extension::khr_unified_image_layouts)
    {
        return extension_cast< ktl::api::extension::khr_unified_image_layouts >();
    }
    if (_extension == ktl::api::extension::khr_shader_float_controls_2)
    {
        return extension_cast< ktl::api::extension::khr_shader_float_controls_2 >();
    }
    if (_extension == ktl::api::extension::qnx_external_memory_screen_buffer)
    {
        return extension_cast< ktl::api::extension::qnx_external_memory_screen_buffer >();
    }
    if (_extension == ktl::api::extension::msft_layered_driver)
    {
        return extension_cast< ktl::api::extension::msft_layered_driver >();
    }
    if (_extension == ktl::api::extension::khr_extension_532)
    {
        return extension_cast< ktl::api::extension::khr_extension_532 >();
    }
    if (_extension == ktl::api::extension::ext_extension_533)
    {
        return extension_cast< ktl::api::extension::ext_extension_533 >();
    }
    if (_extension == ktl::api::extension::khr_index_type_uint_8)
    {
        return extension_cast< ktl::api::extension::khr_index_type_uint_8 >();
    }
    if (_extension == ktl::api::extension::khr_line_rasterization)
    {
        return extension_cast< ktl::api::extension::khr_line_rasterization >();
    }
    if (_extension == ktl::api::extension::qcom_extension_536)
    {
        return extension_cast< ktl::api::extension::qcom_extension_536 >();
    }
    if (_extension == ktl::api::extension::ext_extension_537)
    {
        return extension_cast< ktl::api::extension::ext_extension_537 >();
    }
    if (_extension == ktl::api::extension::ext_extension_538)
    {
        return extension_cast< ktl::api::extension::ext_extension_538 >();
    }
    if (_extension == ktl::api::extension::ext_extension_539)
    {
        return extension_cast< ktl::api::extension::ext_extension_539 >();
    }
    if (_extension == ktl::api::extension::ext_extension_540)
    {
        return extension_cast< ktl::api::extension::ext_extension_540 >();
    }
    if (_extension == ktl::api::extension::ext_extension_541)
    {
        return extension_cast< ktl::api::extension::ext_extension_541 >();
    }
    if (_extension == ktl::api::extension::ext_extension_542)
    {
        return extension_cast< ktl::api::extension::ext_extension_542 >();
    }
    if (_extension == ktl::api::extension::ext_extension_543)
    {
        return extension_cast< ktl::api::extension::ext_extension_543 >();
    }
    if (_extension == ktl::api::extension::khr_calibrated_timestamps)
    {
        return extension_cast< ktl::api::extension::khr_calibrated_timestamps >();
    }
    if (_extension == ktl::api::extension::khr_shader_expect_assume)
    {
        return extension_cast< ktl::api::extension::khr_shader_expect_assume >();
    }
    if (_extension == ktl::api::extension::khr_maintenance_6)
    {
        return extension_cast< ktl::api::extension::khr_maintenance_6 >();
    }
    if (_extension == ktl::api::extension::nv_descriptor_pool_overallocation)
    {
        return extension_cast< ktl::api::extension::nv_descriptor_pool_overallocation >();
    }
    if (_extension == ktl::api::extension::qcom_tile_memory_heap)
    {
        return extension_cast< ktl::api::extension::qcom_tile_memory_heap >();
    }
    if (_extension == ktl::api::extension::nv_extension_549)
    {
        return extension_cast< ktl::api::extension::nv_extension_549 >();
    }
    if (_extension == ktl::api::extension::khr_copy_memory_indirect)
    {
        return extension_cast< ktl::api::extension::khr_copy_memory_indirect >();
    }
    if (_extension == ktl::api::extension::ext_memory_decompression)
    {
        return extension_cast< ktl::api::extension::ext_memory_decompression >();
    }
    if (_extension == ktl::api::extension::nv_display_stereo)
    {
        return extension_cast< ktl::api::extension::nv_display_stereo >();
    }
    if (_extension == ktl::api::extension::img_extension_555)
    {
        return extension_cast< ktl::api::extension::img_extension_555 >();
    }
    if (_extension == ktl::api::extension::nv_raw_access_chains)
    {
        return extension_cast< ktl::api::extension::nv_raw_access_chains >();
    }
    if (_extension == ktl::api::extension::nv_external_compute_queue)
    {
        return extension_cast< ktl::api::extension::nv_external_compute_queue >();
    }
    if (_extension == ktl::api::extension::khr_extension_558)
    {
        return extension_cast< ktl::api::extension::khr_extension_558 >();
    }
    if (_extension == ktl::api::extension::khr_shader_relaxed_extended_instruction)
    {
        return extension_cast< ktl::api::extension::khr_shader_relaxed_extended_instruction >();
    }
    if (_extension == ktl::api::extension::nv_command_buffer_inheritance)
    {
        return extension_cast< ktl::api::extension::nv_command_buffer_inheritance >();
    }
    if (_extension == ktl::api::extension::ext_extension_561)
    {
        return extension_cast< ktl::api::extension::ext_extension_561 >();
    }
    if (_extension == ktl::api::extension::khr_extension_562)
    {
        return extension_cast< ktl::api::extension::khr_extension_562 >();
    }
    if (_extension == ktl::api::extension::khr_maintenance_7)
    {
        return extension_cast< ktl::api::extension::khr_maintenance_7 >();
    }
    if (_extension == ktl::api::extension::nv_shader_atomic_float_16vector)
    {
        return extension_cast< ktl::api::extension::nv_shader_atomic_float_16vector >();
    }
    if (_extension == ktl::api::extension::ext_shader_replicated_composites)
    {
        return extension_cast< ktl::api::extension::ext_shader_replicated_composites >();
    }
    if (_extension == ktl::api::extension::arm_extension_566)
    {
        return extension_cast< ktl::api::extension::arm_extension_566 >();
    }
    if (_extension == ktl::api::extension::arm_extension_567)
    {
        return extension_cast< ktl::api::extension::arm_extension_567 >();
    }
    if (_extension == ktl::api::extension::ext_shader_float_8)
    {
        return extension_cast< ktl::api::extension::ext_shader_float_8 >();
    }
    if (_extension == ktl::api::extension::nv_ray_tracing_validation)
    {
        return extension_cast< ktl::api::extension::nv_ray_tracing_validation >();
    }
    if (_extension == ktl::api::extension::nv_cluster_acceleration_structure)
    {
        return extension_cast< ktl::api::extension::nv_cluster_acceleration_structure >();
    }
    if (_extension == ktl::api::extension::nv_partitioned_acceleration_structure)
    {
        return extension_cast< ktl::api::extension::nv_partitioned_acceleration_structure >();
    }
    if (_extension == ktl::api::extension::nv_extension_572)
    {
        return extension_cast< ktl::api::extension::nv_extension_572 >();
    }
    if (_extension == ktl::api::extension::ext_device_generated_commands)
    {
        return extension_cast< ktl::api::extension::ext_device_generated_commands >();
    }
    if (_extension == ktl::api::extension::khr_device_fault)
    {
        return extension_cast< ktl::api::extension::khr_device_fault >();
    }
    if (_extension == ktl::api::extension::khr_maintenance_8)
    {
        return extension_cast< ktl::api::extension::khr_maintenance_8 >();
    }
    if (_extension == ktl::api::extension::mesa_image_alignment_control)
    {
        return extension_cast< ktl::api::extension::mesa_image_alignment_control >();
    }
    if (_extension == ktl::api::extension::huawei_extension_577)
    {
        return extension_cast< ktl::api::extension::huawei_extension_577 >();
    }
    if (_extension == ktl::api::extension::ext_extension_578)
    {
        return extension_cast< ktl::api::extension::ext_extension_578 >();
    }
    if (_extension == ktl::api::extension::ext_extension_579)
    {
        return extension_cast< ktl::api::extension::ext_extension_579 >();
    }
    if (_extension == ktl::api::extension::khr_shader_fma)
    {
        return extension_cast< ktl::api::extension::khr_shader_fma >();
    }
    if (_extension == ktl::api::extension::nv_push_constant_bank)
    {
        return extension_cast< ktl::api::extension::nv_push_constant_bank >();
    }
    if (_extension == ktl::api::extension::ext_ray_tracing_invocation_reorder)
    {
        return extension_cast< ktl::api::extension::ext_ray_tracing_invocation_reorder >();
    }
    if (_extension == ktl::api::extension::ext_depth_clamp_control)
    {
        return extension_cast< ktl::api::extension::ext_depth_clamp_control >();
    }
    if (_extension == ktl::api::extension::ext_extension_584)
    {
        return extension_cast< ktl::api::extension::ext_extension_584 >();
    }
    if (_extension == ktl::api::extension::khr_maintenance_9)
    {
        return extension_cast< ktl::api::extension::khr_maintenance_9 >();
    }
    if (_extension == ktl::api::extension::img_extension_586)
    {
        return extension_cast< ktl::api::extension::img_extension_586 >();
    }
    if (_extension == ktl::api::extension::ohos_surface)
    {
        return extension_cast< ktl::api::extension::ohos_surface >();
    }
    if (_extension == ktl::api::extension::huawei_extension_686)
    {
        return extension_cast< ktl::api::extension::huawei_extension_686 >();
    }
    if (_extension == ktl::api::extension::ohos_native_buffer)
    {
        return extension_cast< ktl::api::extension::ohos_native_buffer >();
    }
    if (_extension == ktl::api::extension::huawei_extension_590)
    {
        return extension_cast< ktl::api::extension::huawei_extension_590 >();
    }
    if (_extension == ktl::api::extension::huawei_hdr_vivid)
    {
        return extension_cast< ktl::api::extension::huawei_hdr_vivid >();
    }
    if (_extension == ktl::api::extension::nv_extension_592)
    {
        return extension_cast< ktl::api::extension::nv_extension_592 >();
    }
    if (_extension == ktl::api::extension::nv_extension_593)
    {
        return extension_cast< ktl::api::extension::nv_extension_593 >();
    }
    if (_extension == ktl::api::extension::nv_cooperative_matrix_2)
    {
        return extension_cast< ktl::api::extension::nv_cooperative_matrix_2 >();
    }
    if (_extension == ktl::api::extension::nv_extension_595)
    {
        return extension_cast< ktl::api::extension::nv_extension_595 >();
    }
    if (_extension == ktl::api::extension::khr_extension_596)
    {
        return extension_cast< ktl::api::extension::khr_extension_596 >();
    }
    if (_extension == ktl::api::extension::arm_pipeline_opacity_micromap)
    {
        return extension_cast< ktl::api::extension::arm_pipeline_opacity_micromap >();
    }
    if (_extension == ktl::api::extension::khr_extension_598)
    {
        return extension_cast< ktl::api::extension::khr_extension_598 >();
    }
    if (_extension == ktl::api::extension::khr_extension_599)
    {
        return extension_cast< ktl::api::extension::khr_extension_599 >();
    }
    if (_extension == ktl::api::extension::img_extension_600)
    {
        return extension_cast< ktl::api::extension::img_extension_600 >();
    }
    if (_extension == ktl::api::extension::img_extension_601)
    {
        return extension_cast< ktl::api::extension::img_extension_601 >();
    }
    if (_extension == ktl::api::extension::ext_extension_602)
    {
        return extension_cast< ktl::api::extension::ext_extension_602 >();
    }
    if (_extension == ktl::api::extension::ext_external_memory_metal)
    {
        return extension_cast< ktl::api::extension::ext_external_memory_metal >();
    }
    if (_extension == ktl::api::extension::ext_extension_604)
    {
        return extension_cast< ktl::api::extension::ext_extension_604 >();
    }
    if (_extension == ktl::api::extension::khr_depth_clamp_zero_one)
    {
        return extension_cast< ktl::api::extension::khr_depth_clamp_zero_one >();
    }
    if (_extension == ktl::api::extension::arm_performance_counters_by_region)
    {
        return extension_cast< ktl::api::extension::arm_performance_counters_by_region >();
    }
    if (_extension == ktl::api::extension::khr_extension_607)
    {
        return extension_cast< ktl::api::extension::khr_extension_607 >();
    }
    if (_extension == ktl::api::extension::arm_shader_instrumentation)
    {
        return extension_cast< ktl::api::extension::arm_shader_instrumentation >();
    }
    if (_extension == ktl::api::extension::ext_vertex_attribute_robustness)
    {
        return extension_cast< ktl::api::extension::ext_vertex_attribute_robustness >();
    }
    if (_extension == ktl::api::extension::arm_format_pack)
    {
        return extension_cast< ktl::api::extension::arm_format_pack >();
    }
    if (_extension == ktl::api::extension::nv_extension_611)
    {
        return extension_cast< ktl::api::extension::nv_extension_611 >();
    }
    if (_extension == ktl::api::extension::valve_fragment_density_map_layered)
    {
        return extension_cast< ktl::api::extension::valve_fragment_density_map_layered >();
    }
    if (_extension == ktl::api::extension::khr_robustness_2)
    {
        return extension_cast< ktl::api::extension::khr_robustness_2 >();
    }
    if (_extension == ktl::api::extension::nv_present_metering)
    {
        return extension_cast< ktl::api::extension::nv_present_metering >();
    }
    if (_extension == ktl::api::extension::qcom_extension_615)
    {
        return extension_cast< ktl::api::extension::qcom_extension_615 >();
    }
    if (_extension == ktl::api::extension::ext_extension_616)
    {
        return extension_cast< ktl::api::extension::ext_extension_616 >();
    }
    if (_extension == ktl::api::extension::ext_extension_617)
    {
        return extension_cast< ktl::api::extension::ext_extension_617 >();
    }
    if (_extension == ktl::api::extension::ext_extension_618)
    {
        return extension_cast< ktl::api::extension::ext_extension_618 >();
    }
    if (_extension == ktl::api::extension::ext_fragment_density_map_offset)
    {
        return extension_cast< ktl::api::extension::ext_fragment_density_map_offset >();
    }
    if (_extension == ktl::api::extension::ext_zero_initialize_device_memory)
    {
        return extension_cast< ktl::api::extension::ext_zero_initialize_device_memory >();
    }
    if (_extension == ktl::api::extension::khr_present_mode_fifo_latest_ready)
    {
        return extension_cast< ktl::api::extension::khr_present_mode_fifo_latest_ready >();
    }
    if (_extension == ktl::api::extension::ext_extension_623)
    {
        return extension_cast< ktl::api::extension::ext_extension_623 >();
    }
    if (_extension == ktl::api::extension::khr_opacity_micromap)
    {
        return extension_cast< ktl::api::extension::khr_opacity_micromap >();
    }
    if (_extension == ktl::api::extension::khr_extension_625)
    {
        return extension_cast< ktl::api::extension::khr_extension_625 >();
    }
    if (_extension == ktl::api::extension::ext_extension_626)
    {
        return extension_cast< ktl::api::extension::ext_extension_626 >();
    }
    if (_extension == ktl::api::extension::nv_extension_627)
    {
        return extension_cast< ktl::api::extension::nv_extension_627 >();
    }
    if (_extension == ktl::api::extension::ext_shader_64bit_indexing)
    {
        return extension_cast< ktl::api::extension::ext_shader_64bit_indexing >();
    }
    if (_extension == ktl::api::extension::ext_custom_resolve)
    {
        return extension_cast< ktl::api::extension::ext_custom_resolve >();
    }
    if (_extension == ktl::api::extension::qcom_data_graph_model)
    {
        return extension_cast< ktl::api::extension::qcom_data_graph_model >();
    }
    if (_extension == ktl::api::extension::khr_maintenance_10)
    {
        return extension_cast< ktl::api::extension::khr_maintenance_10 >();
    }
    if (_extension == ktl::api::extension::arm_data_graph_optical_flow)
    {
        return extension_cast< ktl::api::extension::arm_data_graph_optical_flow >();
    }
    if (_extension == ktl::api::extension::mtk_extension_633)
    {
        return extension_cast< ktl::api::extension::mtk_extension_633 >();
    }
    if (_extension == ktl::api::extension::nv_extension_634)
    {
        return extension_cast< ktl::api::extension::nv_extension_634 >();
    }
    if (_extension == ktl::api::extension::mtk_extension_635)
    {
        return extension_cast< ktl::api::extension::mtk_extension_635 >();
    }
    if (_extension == ktl::api::extension::ext_shader_long_vector)
    {
        return extension_cast< ktl::api::extension::ext_shader_long_vector >();
    }
    if (_extension == ktl::api::extension::ext_extension_637)
    {
        return extension_cast< ktl::api::extension::ext_extension_637 >();
    }
    if (_extension == ktl::api::extension::sec_pipeline_cache_incremental_mode)
    {
        return extension_cast< ktl::api::extension::sec_pipeline_cache_incremental_mode >();
    }
    if (_extension == ktl::api::extension::ext_extension_639)
    {
        return extension_cast< ktl::api::extension::ext_extension_639 >();
    }
    if (_extension == ktl::api::extension::nv_extension_640)
    {
        return extension_cast< ktl::api::extension::nv_extension_640 >();
    }
    if (_extension == ktl::api::extension::ext_extension_641)
    {
        return extension_cast< ktl::api::extension::ext_extension_641 >();
    }
    if (_extension == ktl::api::extension::ext_extension_642)
    {
        return extension_cast< ktl::api::extension::ext_extension_642 >();
    }
    if (_extension == ktl::api::extension::ext_shader_uniform_buffer_unsized_array)
    {
        return extension_cast< ktl::api::extension::ext_shader_uniform_buffer_unsized_array >();
    }
    if (_extension == ktl::api::extension::ext_extension_644)
    {
        return extension_cast< ktl::api::extension::ext_extension_644 >();
    }
    if (_extension == ktl::api::extension::ext_extension_645)
    {
        return extension_cast< ktl::api::extension::ext_extension_645 >();
    }
    if (_extension == ktl::api::extension::nv_compute_occupancy_priority)
    {
        return extension_cast< ktl::api::extension::nv_compute_occupancy_priority >();
    }
    if (_extension == ktl::api::extension::khr_extension_647)
    {
        return extension_cast< ktl::api::extension::khr_extension_647 >();
    }
    if (_extension == ktl::api::extension::khr_extension_648)
    {
        return extension_cast< ktl::api::extension::khr_extension_648 >();
    }
    if (_extension == ktl::api::extension::amd_extension_649)
    {
        return extension_cast< ktl::api::extension::amd_extension_649 >();
    }
    if (_extension == ktl::api::extension::amd_extension_650)
    {
        return extension_cast< ktl::api::extension::amd_extension_650 >();
    }
    if (_extension == ktl::api::extension::amd_extension_651)
    {
        return extension_cast< ktl::api::extension::amd_extension_651 >();
    }
    if (_extension == ktl::api::extension::amd_extension_652)
    {
        return extension_cast< ktl::api::extension::amd_extension_652 >();
    }
    if (_extension == ktl::api::extension::amd_extension_653)
    {
        return extension_cast< ktl::api::extension::amd_extension_653 >();
    }
    if (_extension == ktl::api::extension::valve_extension_654)
    {
        return extension_cast< ktl::api::extension::valve_extension_654 >();
    }
    if (_extension == ktl::api::extension::arm_extension_655)
    {
        return extension_cast< ktl::api::extension::arm_extension_655 >();
    }
    if (_extension == ktl::api::extension::arm_extension_656)
    {
        return extension_cast< ktl::api::extension::arm_extension_656 >();
    }
    if (_extension == ktl::api::extension::arm_extension_657)
    {
        return extension_cast< ktl::api::extension::arm_extension_657 >();
    }
    if (_extension == ktl::api::extension::khr_maintenance_11)
    {
        return extension_cast< ktl::api::extension::khr_maintenance_11 >();
    }
    if (_extension == ktl::api::extension::arm_extension_659)
    {
        return extension_cast< ktl::api::extension::arm_extension_659 >();
    }
    if (_extension == ktl::api::extension::ext_extension_660)
    {
        return extension_cast< ktl::api::extension::ext_extension_660 >();
    }
    if (_extension == ktl::api::extension::khr_extension_661)
    {
        return extension_cast< ktl::api::extension::khr_extension_661 >();
    }
    if (_extension == ktl::api::extension::valve_extension_662)
    {
        return extension_cast< ktl::api::extension::valve_extension_662 >();
    }
    if (_extension == ktl::api::extension::ext_shader_subgroup_partitioned)
    {
        return extension_cast< ktl::api::extension::ext_shader_subgroup_partitioned >();
    }
    if (_extension == ktl::api::extension::ext_extension_664)
    {
        return extension_cast< ktl::api::extension::ext_extension_664 >();
    }
    if (_extension == ktl::api::extension::sec_ubm_surface)
    {
        return extension_cast< ktl::api::extension::sec_ubm_surface >();
    }
    if (_extension == ktl::api::extension::google_extension_666)
    {
        return extension_cast< ktl::api::extension::google_extension_666 >();
    }
    if (_extension == ktl::api::extension::huawei_extension_667)
    {
        return extension_cast< ktl::api::extension::huawei_extension_667 >();
    }
    if (_extension == ktl::api::extension::nv_extension_668)
    {
        return extension_cast< ktl::api::extension::nv_extension_668 >();
    }
    if (_extension == ktl::api::extension::khr_extension_669)
    {
        return extension_cast< ktl::api::extension::khr_extension_669 >();
    }
    if (_extension == ktl::api::extension::nv_extension_670)
    {
        return extension_cast< ktl::api::extension::nv_extension_670 >();
    }
    if (_extension == ktl::api::extension::arm_extension_671)
    {
        return extension_cast< ktl::api::extension::arm_extension_671 >();
    }
    if (_extension == ktl::api::extension::khr_extension_672)
    {
        return extension_cast< ktl::api::extension::khr_extension_672 >();
    }
    if (_extension == ktl::api::extension::ext_extension_673)
    {
        return extension_cast< ktl::api::extension::ext_extension_673 >();
    }
    if (_extension == ktl::api::extension::valve_shader_mixed_float_dot_product)
    {
        return extension_cast< ktl::api::extension::valve_shader_mixed_float_dot_product >();
    }
    if (_extension == ktl::api::extension::sec_throttle_hint)
    {
        return extension_cast< ktl::api::extension::sec_throttle_hint >();
    }
    if (_extension == ktl::api::extension::ext_extension_676)
    {
        return extension_cast< ktl::api::extension::ext_extension_676 >();
    }
    if (_extension == ktl::api::extension::arm_data_graph_neural_accelerator_statistics)
    {
        return extension_cast< ktl::api::extension::arm_data_graph_neural_accelerator_statistics >();
    }
    if (_extension == ktl::api::extension::ext_extension_678)
    {
        return extension_cast< ktl::api::extension::ext_extension_678 >();
    }
    if (_extension == ktl::api::extension::ext_primitive_restart_index)
    {
        return extension_cast< ktl::api::extension::ext_primitive_restart_index >();
    }
    if (_extension == ktl::api::extension::ext_extension_680)
    {
        return extension_cast< ktl::api::extension::ext_extension_680 >();
    }
    if (_extension == ktl::api::extension::khr_extension_681)
    {
        return extension_cast< ktl::api::extension::khr_extension_681 >();
    }
    if (_extension == ktl::api::extension::valve_extension_682)
    {
        return extension_cast< ktl::api::extension::valve_extension_682 >();
    }
    if (_extension == ktl::api::extension::ext_extension_683)
    {
        return extension_cast< ktl::api::extension::ext_extension_683 >();
    }
    if (_extension == ktl::api::extension::amd_extension_684)
    {
        return extension_cast< ktl::api::extension::amd_extension_684 >();
    }
    if (_extension == ktl::api::extension::amd_extension_685)
    {
        return extension_cast< ktl::api::extension::amd_extension_685 >();
    }
    if (_extension == ktl::api::extension::amd_extension_687)
    {
        return extension_cast< ktl::api::extension::amd_extension_687 >();
    }
    if (_extension == ktl::api::extension::amd_extension_688)
    {
        return extension_cast< ktl::api::extension::amd_extension_688 >();
    }
    if (_extension == ktl::api::extension::amd_extension_689)
    {
        return extension_cast< ktl::api::extension::amd_extension_689 >();
    }
    if (_extension == ktl::api::extension::nv_cooperative_matrix_decode_vector)
    {
        return extension_cast< ktl::api::extension::nv_cooperative_matrix_decode_vector >();
    }
    if (_extension == ktl::api::extension::mesa_fragment_coverage_mask)
    {
        return extension_cast< ktl::api::extension::mesa_fragment_coverage_mask >();
    }
    if (_extension == ktl::api::extension::ext_extension_692)
    {
        return extension_cast< ktl::api::extension::ext_extension_692 >();
    }
    if (_extension == ktl::api::extension::ext_extension_693)
    {
        return extension_cast< ktl::api::extension::ext_extension_693 >();
    }
    return ktl::meta::any_extension{};
}
} // namespace ktl::meta

#endif
