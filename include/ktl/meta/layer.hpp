#ifndef KTL_META_LAYER_HPP
#define KTL_META_LAYER_HPP

#include <string_view>

#include <ktl/api.hpp>

namespace ktl::meta
{
inline std::string_view
raw_command(ktl::api::layer _layer) noexcept
{
    switch (_layer)
    {
    case ktl::api::layer::lunarg_api_dump:
        return "VK_LAYER_LUNARG_api_dump";
    case ktl::api::layer::lunarg_gfxreconstruct:
        return "VK_LAYER_LUNARG_gfxreconstruct";
    case ktl::api::layer::khronos_profiles:
        return "VK_LAYER_KHRONOS_profiles";
    case ktl::api::layer::khronos_validation:
        return "VK_LAYER_KHRONOS_validation";
    case ktl::api::layer::lunarg_screenshot:
        return "VK_LAYER_LUNARG_screenshot";
    case ktl::api::layer::khronos_synchronization2:
        return "VK_LAYER_KHRONOS_synchronization2";
    case ktl::api::layer::khronos_shader_object:
        return "VK_LAYER_KHRONOS_shader_object";
    }
    return "invalid layer";
}
} // namespace ktl::meta

#endif
