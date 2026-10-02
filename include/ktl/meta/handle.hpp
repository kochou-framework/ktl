#ifndef KTL_META_HANDLE_HPP
#define KTL_META_HANDLE_HPP

#include <cstdint>
#include <format>
#include <type_traits>

#include <ktl/api.hpp>

namespace ktl::meta
{
template < typename T >
struct handle_meta
{
    using parent = T::parent;
    using type   = T::type;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = 0
    };
};

template <>
struct handle_meta< ktl::api::instance >
{
    using parent = void;
    using type   = ktl::api::opaque_instance;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_instance)
    };
};

template <>
struct handle_meta< ktl::api::physical_device >
{
    using parent = ktl::api::opaque_instance;
    using type   = ktl::api::opaque_physical_device;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_physical_device)
    };
};

template <>
struct handle_meta< ktl::api::device >
{
    using parent = ktl::api::opaque_physical_device;
    using type   = ktl::api::opaque_device;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_device)
    };
};

template <>
struct handle_meta< ktl::api::queue >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_queue;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_queue)
    };
};

template <>
struct handle_meta< ktl::api::command_buffer >
{
    using parent = ktl::api::opaque_command_pool;
    using type   = ktl::api::opaque_command_buffer;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_command_buffer)
    };
};

template <>
struct handle_meta< ktl::api::device_memory >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_device_memory;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_device_memory)
    };
};

template <>
struct handle_meta< ktl::api::command_pool >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_command_pool;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_command_pool)
    };
};

template <>
struct handle_meta< ktl::api::buffer >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_buffer;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_buffer)
    };
};

template <>
struct handle_meta< ktl::api::buffer_view >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_buffer_view;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_buffer_view)
    };
};

template <>
struct handle_meta< ktl::api::image >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_image;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_image)
    };
};

template <>
struct handle_meta< ktl::api::image_view >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_image_view;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_image_view)
    };
};

template <>
struct handle_meta< ktl::api::shader_module >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_shader_module;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_shader_module)
    };
};

template <>
struct handle_meta< ktl::api::pipeline >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_pipeline;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_pipeline)
    };
};

template <>
struct handle_meta< ktl::api::pipeline_layout >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_pipeline_layout;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_pipeline_layout)
    };
};

template <>
struct handle_meta< ktl::api::sampler >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_sampler;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_sampler)
    };
};

template <>
struct handle_meta< ktl::api::descriptor_set >
{
    using parent = ktl::api::opaque_descriptor_pool;
    using type   = ktl::api::opaque_descriptor_set;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_descriptor_set)
    };
};

template <>
struct handle_meta< ktl::api::descriptor_set_layout >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_descriptor_set_layout;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_descriptor_set_layout)
    };
};

template <>
struct handle_meta< ktl::api::descriptor_pool >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_descriptor_pool;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_descriptor_pool)
    };
};

template <>
struct handle_meta< ktl::api::fence >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_fence;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_fence)
    };
};

template <>
struct handle_meta< ktl::api::semaphore >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_semaphore;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_semaphore)
    };
};

template <>
struct handle_meta< ktl::api::event >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_event;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_event)
    };
};

template <>
struct handle_meta< ktl::api::query_pool >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_query_pool;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_query_pool)
    };
};

template <>
struct handle_meta< ktl::api::framebuffer >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_framebuffer;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_framebuffer)
    };
};

template <>
struct handle_meta< ktl::api::render_pass >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_render_pass;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_render_pass)
    };
};

template <>
struct handle_meta< ktl::api::pipeline_cache >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_pipeline_cache;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_pipeline_cache)
    };
};

template <>
struct handle_meta< ktl::api::pipeline_binary_khr >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_pipeline_binary_khr;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_pipeline_binary_khr)
    };
};

template <>
struct handle_meta< ktl::api::indirect_commands_layout_nv >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_indirect_commands_layout_nv;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_indirect_commands_layout_nv)
    };
};

template <>
struct handle_meta< ktl::api::indirect_commands_layout_ext >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_indirect_commands_layout_ext;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_indirect_commands_layout_ext)
    };
};

template <>
struct handle_meta< ktl::api::indirect_execution_set_ext >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_indirect_execution_set_ext;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_indirect_execution_set_ext)
    };
};

template <>
struct handle_meta< ktl::api::descriptor_update_template >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_descriptor_update_template;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_descriptor_update_template)
    };
};

template <>
struct handle_meta< ktl::api::sampler_ycbcr_conversion >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_sampler_ycbcr_conversion;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_sampler_ycbcr_conversion)
    };
};

template <>
struct handle_meta< ktl::api::validation_cache_ext >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_validation_cache_ext;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_validation_cache_ext)
    };
};

template <>
struct handle_meta< ktl::api::acceleration_structure_khr >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_acceleration_structure_khr;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_acceleration_structure_khr)
    };
};

template <>
struct handle_meta< ktl::api::acceleration_structure_nv >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_acceleration_structure_nv;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_acceleration_structure_nv)
    };
};

template <>
struct handle_meta< ktl::api::performance_configuration_intel >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_performance_configuration_intel;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_performance_configuration_intel)
    };
};

template <>
struct handle_meta< ktl::api::buffer_collection_fuchsia >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_buffer_collection_fuchsia;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_buffer_collection_fuchsia)
    };
};

template <>
struct handle_meta< ktl::api::deferred_operation_khr >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_deferred_operation_khr;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_deferred_operation_khr)
    };
};

template <>
struct handle_meta< ktl::api::private_data_slot >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_private_data_slot;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_private_data_slot)
    };
};

template <>
struct handle_meta< ktl::api::cu_module_nvx >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_cu_module_nvx;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_cu_module_nvx)
    };
};

template <>
struct handle_meta< ktl::api::cu_function_nvx >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_cu_function_nvx;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_cu_function_nvx)
    };
};

template <>
struct handle_meta< ktl::api::optical_flow_session_nv >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_optical_flow_session_nv;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_optical_flow_session_nv)
    };
};

template <>
struct handle_meta< ktl::api::micromap_ext >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_micromap_ext;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_micromap_ext)
    };
};

template <>
struct handle_meta< ktl::api::shader_ext >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_shader_ext;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_shader_ext)
    };
};

template <>
struct handle_meta< ktl::api::tensor_arm >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_tensor_arm;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_tensor_arm)
    };
};

template <>
struct handle_meta< ktl::api::tensor_view_arm >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_tensor_view_arm;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_tensor_view_arm)
    };
};

template <>
struct handle_meta< ktl::api::data_graph_pipeline_session_arm >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_data_graph_pipeline_session_arm;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_data_graph_pipeline_session_arm)
    };
};

template <>
struct handle_meta< ktl::api::shader_instrumentation_arm >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_shader_instrumentation_arm;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_shader_instrumentation_arm)
    };
};

template <>
struct handle_meta< ktl::api::gpa_session_amd >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_gpa_session_amd;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_gpa_session_amd)
    };
};

template <>
struct handle_meta< ktl::api::display_khr >
{
    using parent = ktl::api::opaque_physical_device;
    using type   = ktl::api::opaque_display_khr;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_display_khr)
    };
};

template <>
struct handle_meta< ktl::api::display_mode_khr >
{
    using parent = ktl::api::opaque_display_khr;
    using type   = ktl::api::opaque_display_mode_khr;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_display_mode_khr)
    };
};

template <>
struct handle_meta< ktl::api::surface_khr >
{
    using parent = ktl::api::opaque_instance;
    using type   = ktl::api::opaque_surface_khr;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_surface_khr)
    };
};

template <>
struct handle_meta< ktl::api::swapchain_khr >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_swapchain_khr;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_swapchain_khr)
    };
};

template <>
struct handle_meta< ktl::api::debug_report_callback_ext >
{
    using parent = ktl::api::opaque_instance;
    using type   = ktl::api::opaque_debug_report_callback_ext;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_debug_report_callback_ext)
    };
};

template <>
struct handle_meta< ktl::api::debug_utils_messenger_ext >
{
    using parent = ktl::api::opaque_instance;
    using type   = ktl::api::opaque_debug_utils_messenger_ext;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_debug_utils_messenger_ext)
    };
};

template <>
struct handle_meta< ktl::api::cuda_module_nv >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_cuda_module_nv;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_cuda_module_nv)
    };
};

template <>
struct handle_meta< ktl::api::cuda_function_nv >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_cuda_function_nv;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_cuda_function_nv)
    };
};

template <>
struct handle_meta< ktl::api::external_compute_queue_nv >
{
    using parent = ktl::api::opaque_device;
    using type   = ktl::api::opaque_external_compute_queue_nv;
    enum : std::underlying_type_t< ktl::api::object_type >
    {
        object = static_cast< std::underlying_type_t< ktl::api::object_type > >(ktl::api::object_type::v_external_compute_queue_nv)
    };
};
}
namespace std
{
template <>
struct formatter< ktl::api::instance, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::instance & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::physical_device, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::physical_device & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::device, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::device & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::queue, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::queue & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::command_buffer, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::command_buffer & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::device_memory, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::device_memory & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::command_pool, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::command_pool & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::buffer, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::buffer & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::buffer_view, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::buffer_view & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::image, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::image & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::image_view, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::image_view & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::shader_module, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::shader_module & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::pipeline, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::pipeline & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::pipeline_layout, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::pipeline_layout & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::sampler, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::sampler & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::descriptor_set, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::descriptor_set & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::descriptor_set_layout, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::descriptor_set_layout & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::descriptor_pool, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::descriptor_pool & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::fence, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::fence & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::semaphore, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::semaphore & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::event, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::event & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::query_pool, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::query_pool & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::framebuffer, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::framebuffer & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::render_pass, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::render_pass & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::pipeline_cache, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::pipeline_cache & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::pipeline_binary_khr, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::pipeline_binary_khr & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::indirect_commands_layout_nv, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::indirect_commands_layout_nv & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::indirect_commands_layout_ext, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::indirect_commands_layout_ext & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::indirect_execution_set_ext, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::indirect_execution_set_ext & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::descriptor_update_template, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::descriptor_update_template & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::sampler_ycbcr_conversion, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::sampler_ycbcr_conversion & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::validation_cache_ext, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::validation_cache_ext & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::acceleration_structure_khr, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::acceleration_structure_khr & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::acceleration_structure_nv, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::acceleration_structure_nv & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::performance_configuration_intel, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::performance_configuration_intel & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::buffer_collection_fuchsia, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::buffer_collection_fuchsia & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::deferred_operation_khr, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::deferred_operation_khr & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::private_data_slot, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::private_data_slot & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::cu_module_nvx, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::cu_module_nvx & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::cu_function_nvx, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::cu_function_nvx & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::optical_flow_session_nv, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::optical_flow_session_nv & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::micromap_ext, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::micromap_ext & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::shader_ext, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::shader_ext & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::tensor_arm, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::tensor_arm & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::tensor_view_arm, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::tensor_view_arm & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::data_graph_pipeline_session_arm, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::data_graph_pipeline_session_arm & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::shader_instrumentation_arm, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::shader_instrumentation_arm & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::gpa_session_amd, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::gpa_session_amd & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::display_khr, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::display_khr & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::display_mode_khr, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::display_mode_khr & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::surface_khr, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::surface_khr & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::swapchain_khr, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::swapchain_khr & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::debug_report_callback_ext, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::debug_report_callback_ext & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::debug_utils_messenger_ext, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::debug_utils_messenger_ext & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::cuda_module_nv, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::cuda_module_nv & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::cuda_function_nv, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::cuda_function_nv & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};
template <>
struct formatter< ktl::api::external_compute_queue_nv, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::external_compute_queue_nv & _handle, FormatContext & ctx) const
    {
        auto ptr = reinterpret_cast< std::uintptr_t >(_handle);
        return std::format_to(ctx.out(), "0x{:x}", ptr);
    }
};}
#endif
