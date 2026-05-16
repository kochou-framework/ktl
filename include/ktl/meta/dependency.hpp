#ifndef KTL_META_DEPENDENCY_HPP
#define KTL_META_DEPENDENCY_HPP

#include <compare>
#include <cstdlib>
#include <variant>

#include <ktl/api.hpp>
#include <ktl/api/version.hpp>

namespace ktl::meta
{
class dependency
{
public:
    constexpr dependency(ktl::api::extension _extension) noexcept : dependency_(_extension) {}
    constexpr dependency(ktl::api::feature _feature) noexcept : dependency_(_feature) {}
    constexpr dependency(ktl::api::version _version) noexcept : dependency_(_version) {}
    constexpr dependency() noexcept : dependency_(false) {}

    inline constexpr bool
    is_extension() const noexcept
    {
        return std::holds_alternative< ktl::api::extension >(dependency_);
    }
    inline constexpr ktl::api::extension
    extension() const noexcept
    {
        if (!is_extension())
        {
            std::abort();
        }
        return std::get< ktl::api::extension >(dependency_);
    }

    inline constexpr bool
    is_feature() const noexcept
    {
        return std::holds_alternative< ktl::api::feature >(dependency_);
    }
    inline constexpr ktl::api::feature
    feature() const noexcept
    {
        if (!is_feature())
        {
            std::abort();
        }
        return std::get< ktl::api::feature >(dependency_);
    }

    inline constexpr bool
    is_version() const noexcept
    {
        return std::holds_alternative< ktl::api::version >(dependency_);
    }
    inline constexpr ktl::api::version
    version() const noexcept
    {
        if (!is_version())
        {
            std::abort();
        }
        return std::get< ktl::api::version >(dependency_);
    }

    inline constexpr bool
    is_none() const noexcept
    {
        return std::holds_alternative< bool >(dependency_);
    }

    constexpr std::strong_ordering
    operator<=>(ktl::meta::dependency _rhs) const noexcept
    {
        return dependency_ <=> _rhs.dependency_;
    }

    constexpr bool
    operator==(ktl::meta::dependency _rhs) const noexcept
    {
        return dependency_ == _rhs.dependency_;
    }

private:
    std::variant< ktl::api::extension, ktl::api::feature, ktl::api::version, bool > dependency_;
};

struct version_deps
{
    ktl::api::version                        version;
    bool                                     is_allowed;
    ktl::usize                               deps_size;
    std::array< ktl::meta::dependency, 128 > deps;
};
} // namespace ktl::meta

namespace std
{
template <>
struct hash< ktl::meta::dependency >
{
    [[nodiscard]] ktl::usize
    operator()(ktl::meta::dependency _dependency) const noexcept
    {
        static constexpr ktl::usize extension_bit = 3;
        static constexpr ktl::usize feature_bit   = 2;
        static constexpr ktl::usize version_bit   = 1;

        ktl::usize tag   = 0;
        ktl::usize value = 0;
        if (_dependency.is_extension())
        {
            tag   = extension_bit;
            value = static_cast< ktl::usize >(_dependency.extension());
        }
        else if (_dependency.is_feature())
        {
            tag   = feature_bit;
            value = static_cast< ktl::usize >(_dependency.feature());
        }
        else if (_dependency.is_version())
        {
            tag   = version_bit;
            value = static_cast< ktl::usize >(_dependency.version()());
        }
        return (tag << 60) ^ value;
    }
};

template <>
struct formatter< ktl::meta::dependency, char >
{
    constexpr auto
    parse(format_parse_context & ctx)
    {
        return ctx.begin();
    }

    template < typename FormatContext >
    auto
    format(const ktl::meta::dependency _dependency, FormatContext & ctx) const
    {
        // TODO value
        std::string tag;
        std::string value;
        if (_dependency.is_extension())
        {
            tag   = "extension";
            value = std::to_string(static_cast< ktl::u32 >(_dependency.extension()));
        }
        else if (_dependency.is_feature())
        {
            tag   = "feature";
            value = std::to_string(static_cast< ktl::u32 >(_dependency.feature()));
        }
        else if (_dependency.is_version())
        {
            tag   = "version";
            value = std::format("{}", _dependency.version());
        }
        else
        {
            tag   = "none";
            value = "none";
        }
        return std::format_to(ctx.out(), "[tag:{}, value:{}]", tag, value);
    }
};
} // namespace std

#endif
