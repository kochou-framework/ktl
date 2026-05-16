import constants
import basetypes
import enums
import handles
import structs
import formats
import bitmasks
import pointers
import commands
import features
import extensions


def make_header_guard(_filename: str) -> str | None:
    if not _filename:
        return None
    return f"KTL_{_filename.replace('.', '_').replace('/', '_').upper()}"


def fill_common(_filename: str,
                _constants: list,
                _enums: list,
                _handles: list,
                _structs: list,
                _bitmasks: list,
                _pointers: list,
                _commands: list) -> None:
    header_guard = make_header_guard(_filename)
    if not header_guard:
        print("headers.fill_common header_guard is None")
        return

    with open(_filename, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <ktl/type.hpp>

#include "dummy_headers/X11/Xlib.h"
#include "dummy_headers/X11/extensions/Xrandr.h"
#include "dummy_headers/directfb.h"
#include "dummy_headers/ggp_c/vulkan_types.h"
#include "dummy_headers/nvscibuf.h"
#include "dummy_headers/nvscisync.h"
#include "dummy_headers/screen/screen.h"
#include "dummy_headers/ubm.h"
#include "dummy_headers/ubm_common.h"
#include "dummy_headers/wayland-client.h"
#include "dummy_headers/windows.h"
#include "dummy_headers/xcb/xcb.h"
#include "dummy_headers/zircon/types.h"

""")

        constants.fill_definition(file, _constants)
        basetypes.fill_definition(file)
        enums.fill_definition(file, _enums)
        handles.fill_definition(file, _handles)
        structs.fill_definition(file, _structs)
        bitmasks.fill_definition(file, _bitmasks)
        pointers.fill_definition(file, _pointers)
        commands.fill_definition(file, _commands)

        file.write("\n#endif\n")


def fill_enums(_api_include: str,
               _common_include: str,
               _filename: str,
               _enums: list) -> None:
    header_guard = make_header_guard(_filename)
    if not header_guard:
        print("headers.fill_enums header_guard is None")
        return
    api_guard = make_header_guard(_api_include)
    if not api_guard:
        print("headers.fill_enums api_guard is None")
        return

    with open(_filename, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <ktl/{_common_include}>

""")
        enums.fill_implementation(file, _enums)
        file.write("\n#endif\n")


def fill_handles(_api_include: str,
                 _filename: str,
                 _handles: list) -> None:
    # meta
    header_guard = make_header_guard(_filename)
    if not header_guard:
        print("headers.fill_handles header_guard is None")
        return

    with open(_filename, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <type_traits>

#include <ktl/{_api_include}>

""")
        handles.fill_meta(file, _handles)
        file.write("\n#endif\n")


def fill_structs(_api_include: str,
                 _common_include: str,
                 _enums_include: str,
                 _filename: str,
                 _structs: list) -> None:
    header_guard = make_header_guard(_filename)
    if not header_guard:
        print("headers.fill_structs header_guard is None")
        return
    api_guard = make_header_guard(_api_include)
    if not api_guard:
        print("headers.fill_structs api_guard is None")
        return
    
    with open(_filename, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#ifndef {api_guard}
#include "{_common_include}"
#include "{_enums_include}"
#endif

""")
        structs.fill_implementation(file, _structs)
        file.write("\n#endif\n")


def fill_formats(_api: str,
                 _api_file: str,
                 _meta_file: str,
                 _formats: list) -> None:
    # api
    # meta
    header_guard = make_header_guard(_meta_file)
    if not header_guard:
        print("headers.fill_formats header_guard is None")
        return
    api_guard = make_header_guard(_meta_file)
    if not api_guard:
        print("headers.fill_formats api_guard is None")
        return

    with open(_meta_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <array>

#include <ktl/{_api}>

""")
        formats.fill_meta(file, _formats)
        file.write("\n#endif\n")


def fill_commands(_api_include: str,
                  _api_file: str,
                  _meta_file: str,
                  _commands: list) -> None:
    header_guard = make_header_guard(_api_file)
    if not header_guard:
        print("headers.fill_commands header_guard is None")
        return
    
    with open(_api_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <array>

#include <ktl/loader.hpp>
#include <ktl/{_api_include}>

""")
        commands.fill_implementation(file, _commands)
        file.write("\n#endif\n")

    header_guard = make_header_guard(_meta_file)
    if not header_guard:
        print("headers.fill_commands header_guard is None")
        return
    
    with open(_meta_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <string_view>

#include <ktl/{_api_include}>

""")
        commands.fill_match(file, _commands)
        file.write("\n#endif\n")


def fill_features(_api_include: str,
                  _api_file: str,
                  _meta_file: str,
                  _features: list) -> None:
    header_guard = make_header_guard(_api_file)
    if not header_guard:
        print("headers.fill_features header_guard is None")
        return

    with open(_api_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}
""")
        features.fill_implementation(file, _features)
        file.write("\n#endif\n")

    header_guard = make_header_guard(_meta_file)
    if not header_guard:
        print("headers.fill_features header_guard is None")
        return

    with open(_meta_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <ktl/{_api_include}>
""")
        features.fill_meta(file, _features)
        file.write("\n#endif\n")


def fill_extensions(_api_include: str,
                    _api_file: str,
                    _meta_file: str,
                    _extensions: list) -> None:
    api_header_guard = make_header_guard(_api_file)
    if not api_header_guard:
        print("headers.fill_extensions api_header_guard is None")
        return
    with open(_api_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {api_header_guard}
#define {api_header_guard}
""")
        extensions.fill_implementation(file, _extensions)
        file.write("\n#endif\n")

    meta_header_guard = make_header_guard(_meta_file)
    if not meta_header_guard:
        print("headers.fill_extensions meta_header_guard is None")
        return
    with open(_meta_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {meta_header_guard}
#define {meta_header_guard}

#include <span>

#include <ktl/{_api_include}>
#include <ktl/meta/dependency.hpp>
#include <ktl/api/version.hpp>

""")
        extensions.fill_meta(file, _extensions)
        file.write("\n#endif\n")


def fill_version(_api_include: str,
                 _meta_file: str,
                 _version_commands: list) -> None:
    meta_header_guard = make_header_guard(_meta_file)
    if not meta_header_guard:
        print("headers.fill_extensions meta_header_guard is None")
        return
    with open(_meta_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {meta_header_guard}
#define {meta_header_guard}

#include <array>

#include <ktl/{_api_include}>
#include <ktl/api/version.hpp>

""")
        commands.fill_meta(file, _version_commands)
        file.write("\n#endif\n")


def fill_api(_filename,
             _common_include,
             _enums_include,
             _structs_include,
             _commands_include,
             _features_include,
             _extensions_include) -> None:
    header_guard = make_header_guard(_filename)
    if not header_guard:
        print("headers.fill_extensions header_guard is None")
        return

    with open(_filename, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include "{_common_include}"
#include "{_enums_include}"
#include "{_structs_include}"
#include "{_commands_include}"
#include "{_features_include}"
#include "{_extensions_include}"

#endif
""")
  
def fill_meta(_filename: str,
              _meta_extension: str,
              _meta_feature: str,
              _meta_format: str,
              _meta_handle: str,
              _meta_enum: str,
              _meta_command: str,
              _meta_version: str) -> None:
    header_guard = make_header_guard(_filename)
    if not header_guard:
        print("headers.fill_extensions header_guard is None")
        return

    with open(_filename, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include "{_meta_extension}"
#include "{_meta_feature}"
#include "{_meta_format}"
#include "{_meta_handle}"
// #include "{_meta_enum}"
#include "{_meta_command}"
#include "{_meta_version}"

#endif
""")
