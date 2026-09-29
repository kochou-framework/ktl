#ifndef KTL_SYSTEM_HPP
#define KTL_SYSTEM_HPP

#include <cassert>

#include <ktl/type.hpp>

namespace ktl
{
enum class os_flag : ktl::u32
{
    linux   = 0,
    macos   = 1,
    windows = 2
};

#ifdef KTL_PLATFORM_LINUX
static constexpr os_flag  os_defined    = os_flag::linux;
static constexpr ktl::u32 cpu_line_size = 64;
static constexpr ktl::u32 gpu_line_size = 128;

#elifdef KTL_PLATFORM_MACOS
static constexpr os_flag  os_defined    = os_flag::macos;
static constexpr ktl::u32 cpu_line_size = 128;
static constexpr ktl::u32 gpu_line_size = 128;

#elifdef KTL_PLATFORM_WIN32
static constexpr os_flag  os_defined    = os_flag::windows;
static constexpr ktl::u32 cpu_line_size = 64;
static constexpr ktl::u32 gpu_line_size = 128;

#else
static_assert("unknown os, not supported" && false);

#endif
} // namespace ktl

#endif
