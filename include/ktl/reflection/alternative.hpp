#ifndef KTL_REFLECTION_ALTERNATIVE_HPP
#define KTL_REFLECTION_ALTERNATIVE_HPP

#include <variant>
#include <type_traits>

namespace ktl::reflection::details
{
template < typename T, typename VARIANT >
struct is_alternative_of;

template < typename T, typename... ARGS >
struct is_alternative_of< T, std::variant< ARGS... > > : std::bool_constant< (std::is_same_v< T, ARGS > || ...) >
{
};
} // namespace

namespace ktl::reflection
{
/**
 * @brief a bool value that's 
 */
template < typename T, typename VARIANT >
inline constexpr bool is_alternative = details::is_alternative_of< T, VARIANT >::value;
} // namespace ktl::reflection

#endif
