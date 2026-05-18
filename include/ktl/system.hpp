#ifndef KTL_SYSTEM_HPP
#define KTL_SYSTEM_HPP

#include <cassert>

#include <ktl/type.hpp>

namespace ktl
{
enum class os_flag : ktl::u32
{
    linux,
    macos,
    windows
};

#ifdef KTL_PLATFORM_LINUX
static constexpr os_flag os_defined = os_flag::linux;

#elifdef KTL_PLATFORM_MACOS
static constexpr os_flag os_defined = os_flag::macos;

#elifdef KTL_PLATFORM_WIN32
static constexpr os_flag os_defined = os_flag::windows;

#else
static_assert("unknown os, not supported" && false);

#endif
} // namespace ktl

#endif
