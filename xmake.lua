set_xmakever("3.0.0")
set_project("ktl")
set_languages("c++23")

option("ktl_dylib_path")
    set_description("vulkan dynamic library path")
option_end()

option("ktl_platform")
    set_description("target platform")
option_end()

target("ktl")
    set_kind("phony")

    add_includedirs("include", {public = true})
    add_cxxflags("-Wall", "-Wextra", {force = false})

    on_config(function (target)
        local function get_required_config(name)
            local val = get_config(name)
            if not val or val == "" then
                raise("error: option '" .. name .. "' is not set! Define it via set_config() or 'xmake f --" .. name .. "=value'")
            end
            return val
        end

        local dylib_path = get_required_config("ktl_dylib_path")
        target:add('defines', 'KTL_DYLIB_PATH="' .. dylib_path .. '"', {public=true})

        local platform = get_required_config("ktl_platform")
        target:add('defines', 'KTL_PLATFORM_' .. platform:upper(), {public=true})
    end)
