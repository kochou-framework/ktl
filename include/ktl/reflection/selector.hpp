#ifndef KTL_REFLECTION_SELECTOR_HPP
#define KTL_REFLECTION_SELECTOR_HPP

#include <concepts>

namespace ktl::reflection::details
{
template < template < typename > typename CONDITION, typename... VARIANTS >
struct first_or_void;

template < template < typename > typename CONDITION >
struct first_or_void< CONDITION >
{
    using type = void;
};

template < template < typename > typename CONDITION, typename LHS, typename... RHS >
struct first_or_void< CONDITION, LHS, RHS... >
{
    using type =
        std::conditional_t< (CONDITION< LHS >::value), LHS, typename first_or_void< CONDITION, RHS... >::type >;
};
} // namespace

namespace ktl::reflection
{
/**
 * @brief compile time type selector
 * 
 * returns first `type` that satisfy condition or `void`
 */
template < template < typename > typename CONDITION, typename... VARIANTS >
using selector = typename details::first_or_void< CONDITION, VARIANTS... >::type;
} // namespace ktl::reflection

#endif
