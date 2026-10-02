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
import platforms
from cpp_meta import VERSION_META, VERSION_STD


def make_header_guard(_filename: str) -> str:
    if not _filename:
        raise ValueError("header file name is empty")
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

    with open(_filename, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <ktl/type.hpp>
""")

        platforms.fill_definition(file)
        constants.fill_definition(file, _constants)
        basetypes.fill_definition(file)
        enums.fill_definition(file, _enums)
        handles.fill_definition(file, _handles)
        structs.fill_definition(file, _structs)
        bitmasks.fill_definition(file, _bitmasks)
        pointers.fill_definition(file, _pointers)
        commands.fill_definition(file, _commands)

        file.write("\n#endif\n")


def fill_enums(_common_include: str,
               _filename: str,
               _enums: list) -> None:
    header_guard = make_header_guard(_filename)

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

    with open(_filename, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <cstdint>
#include <format>
#include <type_traits>

#include <ktl/{_api_include}>

""")
        handles.fill_meta(file, _handles)
        file.write("\n#endif\n")


def fill_structs(_common_include: str,
                 _enums_include: str,
                 _filename: str,
                 _structs: list) -> None:
    header_guard = make_header_guard(_filename)

    with open(_filename, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <ktl/{_common_include}>
#include <ktl/{_enums_include}>

""")
        structs.fill_implementation(file, _structs)
        file.write("\n#endif\n")


def fill_formats(_api: str,
                 _meta_file: str,
                 _formats: list) -> None:
    header_guard = make_header_guard(_meta_file)

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
    
    with open(_api_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <array>
#include <cstdlib>

#include <ktl/loader.hpp>
#include <ktl/{_api_include}>

""")
        commands.fill_implementation(file, _commands)
        file.write("\n#endif\n")

    header_guard = make_header_guard(_meta_file)
    
    with open(_meta_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <cstdlib>
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

    with open(_api_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <ktl/type.hpp>

""")
        features.fill_implementation(file, _features)
        file.write("\n#endif\n")

    header_guard = make_header_guard(_meta_file)

    with open(_meta_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include <cstddef>
#include <cstdlib>

#include <ktl/{_api_include}>
""")
        features.fill_meta(file, _features)
        file.write("\n#endif\n")


def fill_extensions(_api_include: str,
                    _api_file: str,
                    _meta_file: str,
                    _extensions: list) -> None:
    api_header_guard = make_header_guard(_api_file)
    with open(_api_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {api_header_guard}
#define {api_header_guard}

#include <ktl/type.hpp>

""")
        extensions.fill_implementation(file, _extensions)
        file.write("\n#endif\n")

    meta_header_guard = make_header_guard(_meta_file)
    with open(_meta_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {meta_header_guard}
#define {meta_header_guard}

#include <array>
#include <optional>
#include <span>
#include <string_view>

#include <ktl/{_api_include}>
#include <ktl/meta/dependency.hpp>
#include <ktl/api/version.hpp>

""")
        extensions.fill_meta(file, _extensions)
        file.write("\n#endif\n")


def fill_version(_api_include: str,
                 _api_file: str,
                 _meta_file: str,
                 _version_commands: dict) -> None:
    # api/version.hpp: ktl::api::version and the vulkan versions of vk.xml
    api_header_guard = make_header_guard(_api_file)
    with open(_api_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {api_header_guard}
#define {api_header_guard}

#include <array>
#include <compare>
#include <format>
#include <functional>

#include <ktl/type.hpp>

namespace ktl::api
{{
{VERSION_META}

""")
        commands.fill_versions(file, list(_version_commands))
        file.write(f"""}} // namespace ktl::api

{VERSION_STD}

#endif
""")

    meta_header_guard = make_header_guard(_meta_file)
    with open(_meta_file, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {meta_header_guard}
#define {meta_header_guard}

#include <array>
#include <span>

#include <ktl/{_api_include}>
#include <ktl/{_api_file}>

""")
        commands.fill_meta(file, _version_commands)
        file.write("\n#endif\n")


def fill_api(_filename,
             _common_include,
             _enums_include,
             _structs_include,
             _commands_include,
             _features_include,
             _extensions_include,
             _version_include,
             _layers_include) -> None:
    header_guard = make_header_guard(_filename)

    # layer.hpp is written by hand, the generator only includes it
    with open(_filename, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include "{_common_include}"
#include "{_enums_include}"
#include "{_structs_include}"
#include "{_commands_include}"
#include "{_features_include}"
#include "{_extensions_include}"
#include "{_version_include}"
#include "{_layers_include}"

#endif
""")
  
def fill_meta(_filename: str,
              _meta_extension: str,
              _meta_feature: str,
              _meta_format: str,
              _meta_handle: str,
              _meta_command: str,
              _meta_version: str,
              _meta_layer: str) -> None:
    header_guard = make_header_guard(_filename)

    # layer.hpp is written by hand, the generator only includes it
    with open(_filename, "w", encoding="utf-8") as file:
        file.write(f"""#ifndef {header_guard}
#define {header_guard}

#include "{_meta_extension}"
#include "{_meta_feature}"
#include "{_meta_format}"
#include "{_meta_handle}"
#include "{_meta_command}"
#include "{_meta_version}"
#include "{_meta_layer}"

#endif
""")
