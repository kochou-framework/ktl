#ifndef KTL_API_POINTERS_HPP
#define KTL_API_POINTERS_HPP

#include <memory>

#include <ktl/memory/alloc.hpp>
#include <ktl/result.hpp>

namespace ktl::memory
{
// TODO
template < typename T >
using uptr = std::unique_ptr< T >;

template < typename T >
using sptr = std::shared_ptr< T >;

template < typename T, typename... ARGS >
ktl::result< ktl::memory::uptr< T >, ktl::errc >
make_unique(ARGS &&... args)
{
    return std::make_unique< T >(std::forward< ARGS >(args)...);
}

template < typename T, typename... ARGS >
ktl::result< ktl::memory::sptr< T >, ktl::errc >
make_shared(ARGS &&... args)
{
    return std::make_shared< T >(std::forward< ARGS >(args)...);
}
} // namespace ktl::memory

#endif
