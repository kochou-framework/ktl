#ifndef KTL_MEMORY_ALLOC_HPP
#define KTL_MEMORY_ALLOC_HPP

#include <concepts>
#include <cstddef>
#include <cstdlib>
#include <limits>
#include <memory>
#include <new>
#include <type_traits>

#include <ktl/errc.hpp>
#include <ktl/result.hpp>

namespace ktl::memory::details
{
template < typename T >
constexpr bool
is_size_overflow(ktl::usize _amount) noexcept
{
    return _amount > std::numeric_limits< ktl::usize >::max() / sizeof(T);
}
} // namespace ktl::memory::details

namespace ktl::memory
{
template < typename T >
[[nodiscard]]
ktl::result< T *, ktl::errc >
malloc(ktl::usize _amount) noexcept
{
    if (_amount == 0) [[unlikely]]
    {
        return nullptr;
    }
    if (details::is_size_overflow< T >(_amount)) [[unlikely]]
    {
        return ktl::err(ktl::errc::overflow);
    }

    constexpr ktl::usize align = alignof(T);
    const ktl::usize     size  = sizeof(T) * _amount;

    void * ptr = ::operator new[](size, std::align_val_t(align), std::nothrow);
    if (!ptr) [[unlikely]]
    {
        return ktl::err(ktl::errc::no_memory);
    }

    return static_cast< T * >(ptr);
}

template < typename T >
void
free(T * _ptr, ktl::usize _amount) noexcept
{
    if (!_ptr) [[unlikely]]
    {
        return;
    }

    constexpr ktl::usize align = alignof(T);
    const ktl::usize     size  = sizeof(T) * _amount;

    ::operator delete[](_ptr, size, std::align_val_t(align));
}

// every element is constructed from the same arguments, so they are passed as lvalues (copied, never moved)
template < typename T, typename... Args >
    requires std::is_nothrow_constructible_v< T, Args &... >
[[nodiscard]]
ktl::result< T *, ktl::errc >
palloc(ktl::usize _amount, Args &&... _args) noexcept
{
    if (_amount == 0) [[unlikely]]
    {
        return nullptr;
    }
    if (details::is_size_overflow< T >(_amount)) [[unlikely]]
    {
        return ktl::err(ktl::errc::overflow);
    }

    constexpr ktl::usize align = alignof(T);
    const ktl::usize     size  = sizeof(T) * _amount;

    void * ptr = ::operator new[](size, std::align_val_t(align), std::nothrow);
    if (!ptr) [[unlikely]]
    {
        return ktl::err(ktl::errc::no_memory);
    }

    auto * typed = static_cast< T * >(ptr);
    for (ktl::usize i = 0; i < _amount; ++i)
    {
        ::new (static_cast< void * >(typed + i)) T(_args...);
    }

    return typed;
}

template < typename T >
    requires std::is_nothrow_destructible_v< T >
void
pfree(T * _ptr, ktl::usize _amount) noexcept
{
    if (!_ptr) [[unlikely]]
    {
        return;
    }

    if constexpr (!std::is_trivially_destructible_v< T >)
    {
        for (ktl::usize i = 0; i < _amount; ++i)
        {
            _ptr[i].~T();
        }
    }

    constexpr ktl::usize align = alignof(T);
    const ktl::usize     size  = sizeof(T) * _amount;

    ::operator delete[](_ptr, size, std::align_val_t(align));
}
} // namespace ktl::memory

#endif
