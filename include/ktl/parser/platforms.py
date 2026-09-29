from typing import TextIO

# window system / os types that vk.xml takes from native headers (<type requires="..."/>)
#
# by default ktl declares ABI-compatible stand-ins, so no native header is needed:
#   - value types get the native size
#   - types used only through a pointer become opaque structs
# with KTL_USE_PLATFORM_<NAME> defined ktl includes the native header and aliases native types
#
# (platform macro suffix, native headers, [(vk.xml name, ktl::api name, stand-in type or None for opaque struct)])
PLATFORMS = [
    ("XLIB", ["X11/Xlib.h"], [
        ("Display",  "xlib_display",   None),
        ("VisualID", "xlib_visual_id", "unsigned long"),
        ("Window",   "xlib_window",    "unsigned long"),
    ]),
    ("XLIB_XRANDR", ["X11/extensions/Xrandr.h"], [
        ("RROutput", "xlib_rr_output", "unsigned long"),
    ]),
    ("XCB", ["xcb/xcb.h"], [
        ("xcb_connection_t", "xcb_connection", None),
        ("xcb_visualid_t",   "xcb_visual_id",  "ktl::u32"),
        ("xcb_window_t",     "xcb_window",     "ktl::u32"),
    ]),
    ("WAYLAND", ["wayland-client.h"], [
        ("wl_display", "wayland_display", None),
        ("wl_surface", "wayland_surface", None),
    ]),
    ("UBM", ["ubm.h"], [
        ("ubm_device",  "ubm_device",  None),
        ("ubm_surface", "ubm_surface", None),
    ]),
    ("WIN32", ["windows.h"], [
        ("HINSTANCE",           "win32_hinstance",           "void *"),
        ("HWND",                "win32_hwnd",                "void *"),
        ("HMONITOR",            "win32_hmonitor",            "void *"),
        ("HANDLE",              "win32_handle",              "void *"),
        ("SECURITY_ATTRIBUTES", "win32_security_attributes", None),
        ("DWORD",               "win32_dword",               "ktl::u32"),
        ("LPCWSTR",             "win32_lpcwstr",             "const wchar_t *"),
    ]),
    ("DIRECTFB", ["directfb.h"], [
        ("IDirectFB",        "directfb",         None),
        ("IDirectFBSurface", "directfb_surface", None),
    ]),
    ("FUCHSIA", ["zircon/types.h"], [
        ("zx_handle_t", "zx_handle", "ktl::u32"),
    ]),
    ("GGP", ["ggp_c/vulkan_types.h"], [
        ("GgpStreamDescriptor", "ggp_stream_descriptor", "ktl::u32"),
        ("GgpFrameToken",       "ggp_frame_token",       "ktl::u64"),
    ]),
    ("SCREEN", ["screen/screen.h"], [
        ("_screen_context", "screen_context", None),
        ("_screen_window",  "screen_window",  None),
        ("_screen_buffer",  "screen_buffer",  None),
    ]),
    ("SCI", ["nvscisync.h", "nvscibuf.h"], [
        ("NvSciSyncAttrList", "nvsci_sync_attr_list", "struct nvsci_sync_attr_list_rec *"),
        ("NvSciSyncObj",      "nvsci_sync_obj",       "struct nvsci_sync_obj_rec *"),
        ("NvSciSyncFence",    "nvsci_sync_fence",     None),
        ("NvSciBufAttrList",  "nvsci_buf_attr_list",  "struct nvsci_buf_attr_list_rec *"),
        ("NvSciBufObj",       "nvsci_buf_obj",        "struct nvsci_buf_obj_rec *"),
    ]),
]

PLATFORM_TYPES = {native: f"ktl::api::{name}" for _, _, types in PLATFORMS for native, name, _ in types}


def cast_platform_type(_type: str) -> str | None:
    return PLATFORM_TYPES.get(_type)


def fill_definition(_file: TextIO) -> None:
    _file.write("""
// platform types: ABI-compatible stand-ins by default,
// define KTL_USE_PLATFORM_<NAME> to include the native header and use native types instead
""")
    for macro, headers, _ in PLATFORMS:
        _file.write(f"#ifdef KTL_USE_PLATFORM_{macro}\n")
        for header in headers:
            _file.write(f"#include <{header}>\n")
        _file.write("#endif\n")

    _file.write("\nnamespace ktl::api\n{\n")
    for macro, _, types in PLATFORMS:
        _file.write(f"#ifdef KTL_USE_PLATFORM_{macro}\n")
        for native, name, _ in types:
            _file.write(f"using {name} = ::{native};\n")
        _file.write("#else\n")
        for _, name, standin in types:
            if standin:
                _file.write(f"using {name} = {standin};\n")
            else:
                _file.write(f"struct {name};\n")
        _file.write("#endif\n")
    _file.write("} // namespace ktl::api\n")
