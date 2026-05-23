#ifndef KTL_API_LAYER_HPP
#define KTL_API_LAYER_HPP

#include <ktl/type.hpp>

namespace ktl::api
{
enum class layer : ktl::u32
{
    lunarg_api_dump,
    lunarg_gfxreconstruct,
    khronos_profiles,
    khronos_validation,
    lunarg_screenshot,
    khronos_synchronization2,
    khronos_shader_object
};
} // namespace ktl::api

#endif
