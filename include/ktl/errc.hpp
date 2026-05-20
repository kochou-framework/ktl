#ifndef KTL_ERRC_HPP
#define KTL_ERRC_HPP

#include <format>

#include <ktl/api/enum.hpp>

namespace ktl
{
enum class errc
{
    // vulkan api
    success,
    not_ready,
    timeout,
    event_set,
    incomplete,
    out_of_host_memory,
    out_of_device_memory,
    initialization_failed,
    device_lost,
    memory_map_failed,
    layer_not_present,
    extension_not_present,
    feature_not_present,
    incompatible_driver,
    too_many_objects,
    format_not_supported,
    fragmented_pool,
    unknown,
    error_extension_specific,

    // cpp
    unspecified,
    invalid_argument,
    out_of_range,
    no_memory,
    overflow,
    underflow,

    // kochou
    unspecified_api_error,
    extension_wrong_value,
    extension_not_provides,
    extension_is_deprecated,
    feature_wrong_value,
    feature_not_provides,
    feature_is_deprecated,
    bad_vk_api_version,
    unknown_vk_api_version,
    queue_wrong_value,
    queue_not_provides,
    queue_not_dedicated,
    layer_wrong_value,
    layer_not_provides,
    compute_failed,
    pfn_load_failed,
    unsupported_format,
    unsupported_present_mode
};

inline ktl::errc
cast_api_result(ktl::api::result _result)
{
    switch (_result)
    {
    case ktl::api::result::v_success:
        return ktl::errc::success;
    case ktl::api::result::v_not_ready:
        return ktl::errc::not_ready;
    case ktl::api::result::v_timeout:
        return ktl::errc::timeout;
    case ktl::api::result::v_event_set:
        return ktl::errc::event_set;
    case ktl::api::result::v_incomplete:
        return ktl::errc::incomplete;
    case ktl::api::result::v_error_out_of_host_memory:
        return ktl::errc::out_of_host_memory;
    case ktl::api::result::v_error_out_of_device_memory:
        return ktl::errc::out_of_device_memory;
    case ktl::api::result::v_error_initialization_failed:
        return ktl::errc::initialization_failed;
    case ktl::api::result::v_error_device_lost:
        return ktl::errc::device_lost;
    case ktl::api::result::v_error_memory_map_failed:
        return ktl::errc::memory_map_failed;
    case ktl::api::result::v_error_layer_not_present:
        return ktl::errc::layer_not_present;
    case ktl::api::result::v_error_extension_not_present:
        return ktl::errc::extension_not_present;
    case ktl::api::result::v_error_feature_not_present:
        return ktl::errc::feature_not_present;
    case ktl::api::result::v_error_incompatible_driver:
        return ktl::errc::incompatible_driver;
    case ktl::api::result::v_error_too_many_objects:
        return ktl::errc::too_many_objects;
    case ktl::api::result::v_error_format_not_supported:
        return ktl::errc::format_not_supported;
    case ktl::api::result::v_error_fragmented_pool:
        return ktl::errc::fragmented_pool;
    case ktl::api::result::v_error_unknown:
        return ktl::errc::unknown;
    default:
        return ktl::errc::error_extension_specific;
    }
}
} // namespace ktl

namespace std
{
template <>
struct formatter< ktl::errc, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::errc _errc, FormatContext & ctx) const
    {
        switch (_errc)
        {
        case ktl::errc::success:
            return std::format_to(ctx.out(), "success");
        case ktl::errc::not_ready:
            return std::format_to(ctx.out(), "not_ready");
        case ktl::errc::timeout:
            return std::format_to(ctx.out(), "timeout");
        case ktl::errc::event_set:
            return std::format_to(ctx.out(), "event_set");
        case ktl::errc::incomplete:
            return std::format_to(ctx.out(), "incomplete");
        case ktl::errc::out_of_host_memory:
            return std::format_to(ctx.out(), "out_of_host_memory");
        case ktl::errc::out_of_device_memory:
            return std::format_to(ctx.out(), "out_of_device_memory");
        case ktl::errc::initialization_failed:
            return std::format_to(ctx.out(), "initialization_failed");
        case ktl::errc::device_lost:
            return std::format_to(ctx.out(), "device_lost");
        case ktl::errc::memory_map_failed:
            return std::format_to(ctx.out(), "memory_map_failed");
        case ktl::errc::layer_not_present:
            return std::format_to(ctx.out(), "layer_not_present");
        case ktl::errc::extension_not_present:
            return std::format_to(ctx.out(), "extension_not_present");
        case ktl::errc::feature_not_present:
            return std::format_to(ctx.out(), "feature_not_present");
        case ktl::errc::incompatible_driver:
            return std::format_to(ctx.out(), "incompatible_driver");
        case ktl::errc::too_many_objects:
            return std::format_to(ctx.out(), "too_many_objects");
        case ktl::errc::format_not_supported:
            return std::format_to(ctx.out(), "format_not_supported");
        case ktl::errc::fragmented_pool:
            return std::format_to(ctx.out(), "fragmented_pool");
        case ktl::errc::unknown:
            return std::format_to(ctx.out(), "unknown");
        case ktl::errc::error_extension_specific:
            return std::format_to(ctx.out(), "error_extension_specific");
        case ktl::errc::unspecified:
            return std::format_to(ctx.out(), "unspecified");
        case ktl::errc::invalid_argument:
            return std::format_to(ctx.out(), "invalid_argument");
        case ktl::errc::out_of_range:
            return std::format_to(ctx.out(), "out_of_range");
        case ktl::errc::no_memory:
            return std::format_to(ctx.out(), "no_memory");
        case ktl::errc::overflow:
            return std::format_to(ctx.out(), "overflow");
        case ktl::errc::underflow:
            return std::format_to(ctx.out(), "underflow");
        case ktl::errc::unspecified_api_error:
            return std::format_to(ctx.out(), "unspecified_api_error");
        case ktl::errc::extension_wrong_value:
            return std::format_to(ctx.out(), "extension_wrong_value");
        case ktl::errc::extension_not_provides:
            return std::format_to(ctx.out(), "extension_not_provides");
        case ktl::errc::extension_is_deprecated:
            return std::format_to(ctx.out(), "extension_is_deprecated");
        case ktl::errc::feature_wrong_value:
            return std::format_to(ctx.out(), "feature_wrong_value");
        case ktl::errc::feature_not_provides:
            return std::format_to(ctx.out(), "feature_not_provides");
        case ktl::errc::feature_is_deprecated:
            return std::format_to(ctx.out(), "feature_is_deprecated");
        case ktl::errc::bad_vk_api_version:
            return std::format_to(ctx.out(), "bad_vk_api_version");
        case ktl::errc::unknown_vk_api_version:
            return std::format_to(ctx.out(), "unknown_vk_api_version");
        case ktl::errc::queue_wrong_value:
            return std::format_to(ctx.out(), "queue_wrong_value");
        case ktl::errc::queue_not_provides:
            return std::format_to(ctx.out(), "queue_not_provides");
        case ktl::errc::queue_not_dedicated:
            return std::format_to(ctx.out(), "queue_not_dedicated");
        case ktl::errc::layer_wrong_value:
            return std::format_to(ctx.out(), "layer_wrong_value");
        case ktl::errc::layer_not_provides:
            return std::format_to(ctx.out(), "layer_not_provides");
        case ktl::errc::compute_failed:
            return std::format_to(ctx.out(), "compute_failed");
        case ktl::errc::pfn_load_failed:
            return std::format_to(ctx.out(), "pfn_load_failed");
        case ktl::errc::unsupported_format:
            return std::format_to(ctx.out(), "unsupported_format");
        case ktl::errc::unsupported_present_mode:
            return std::format_to(ctx.out(), "unsupported_present_mode");
        }
        return std::format_to(ctx.out(), "FORMAT_ERROR");
    }
};
} // namespace std

#endif
