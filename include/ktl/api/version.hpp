#ifndef KTL_API_VERSION_HPP
#define KTL_API_VERSION_HPP

#include <array>
#include <compare>
#include <format>
#include <functional>

#include <ktl/type.hpp>

namespace ktl::api
{
struct version
{
    ktl::u32 variant;
    ktl::u32 major;
    ktl::u32 minor;
    ktl::u32 patch;

    constexpr version() noexcept : variant(0), major(0), minor(0), patch(0) {}

    constexpr explicit version(ktl::u32 _version) noexcept
        : variant((_version >> 29U) & 0x7U), major((_version >> 22U) & 0x7FU), minor((_version >> 12U) & 0x3FFU),
          patch(_version & 0xFFFU)
    {
    }
    constexpr explicit version(ktl::u32 _variant, ktl::u32 _major, ktl::u32 _minor, ktl::u32 _patch) noexcept
        : variant(_variant), major(_major), minor(_minor), patch(_patch)
    {
    }

    constexpr ktl::u32
    operator()() const noexcept
    {
        return (variant << 29U) | (major << 22U) | (minor << 12U) | patch;
    }

    constexpr explicit
    operator ktl::u32() const noexcept
    {
        return operator()();
    }

    constexpr std::strong_ordering
    operator<=>(version _rhs) const noexcept
    {
        return operator()() <=> _rhs.operator()();
    }

    constexpr bool
    operator==(version _rhs) const noexcept
    {
        return operator()() == _rhs.operator()();
    }
};

static constexpr ktl::api::version                  version_1_0(0, 1, 0, 0);
static constexpr ktl::api::version                  version_1_1(0, 1, 1, 0);
static constexpr ktl::api::version                  version_1_2(0, 1, 2, 0);
static constexpr ktl::api::version                  version_1_3(0, 1, 3, 0);
static constexpr ktl::api::version                  version_1_4(0, 1, 4, 0);
static constexpr std::array< ktl::api::version, 5 > common_versions = {version_1_0, version_1_1, version_1_2,
                                                                       version_1_3, version_1_4};
} // namespace ktl::api

namespace std
{
template <>
struct hash< ktl::api::version >
{
    [[nodiscard]] ktl::usize
    operator()(ktl::api::version _version) const noexcept
    {
        return static_cast< ktl::usize >(_version());
    }
};

template <>
struct formatter< ktl::api::version, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::api::version _version, FormatContext & ctx) const
    {
        return std::format_to(ctx.out(), "{}.{}.{}", _version.major, _version.minor, _version.patch);
    }
};
} // namespace std

#endif
