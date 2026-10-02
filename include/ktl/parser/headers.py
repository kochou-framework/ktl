import io
import platforms
import constants
import basetypes
import enums
import handles
import structs
import bitmasks
import funcpointers
import commands
import features
import extensions
import formats
import versions

# generated files relative to include/ktl: api/common.hpp declares everything, the other api/ headers define it,
# meta/ headers describe it; api/layer.hpp and meta/layer.hpp are written by hand, api.hpp and meta.hpp include them
API_COMMON     = "api/common.hpp"
API_ENUMS      = "api/enum.hpp"
API_STRUCTS    = "api/struct.hpp"
API_COMMANDS   = "api/command.hpp"
API_FEATURES   = "api/feature.hpp"
API_EXTENSIONS = "api/extension.hpp"
API_VERSION    = "api/version.hpp"
API_LAYERS     = "api/layer.hpp"
API            = "api.hpp"

META_EXTENSIONS = "meta/extension.hpp"
META_FEATURES   = "meta/feature.hpp"
META_FORMATS    = "meta/format.hpp"
META_HANDLES    = "meta/handle.hpp"
META_COMMANDS   = "meta/command.hpp"
META_VERSION    = "meta/version.hpp"
META_LAYERS     = "meta/layer.hpp"
META            = "meta.hpp"


def make_header_guard(_filename: str) -> str:
    return f"KTL_{_filename.replace('.', '_').replace('/', '_').upper()}"


def make_header(_filename: str, _includes: str, _model, *_writers) -> str:
    file = io.StringIO()
    header_guard = make_header_guard(_filename)
    file.write(f"#ifndef {header_guard}\n#define {header_guard}\n\n{_includes}")
    for write in _writers:
        write(file, _model)
    file.write("\n#endif\n")
    return file.getvalue()


def generate(_model) -> dict[str, str]:
    # path -> text of every generated file
    api_includes = "".join(f'#include "{include}"\n' for include in (API_COMMON, API_ENUMS, API_STRUCTS, API_COMMANDS,
                                                                     API_FEATURES, API_EXTENSIONS, API_VERSION, API_LAYERS))
    meta_includes = "".join(f'#include "{include}"\n' for include in (META_EXTENSIONS, META_FEATURES, META_FORMATS, META_HANDLES,
                                                                      META_COMMANDS, META_VERSION, META_LAYERS))
    return {
        API_COMMON: make_header(API_COMMON, "#include <ktl/type.hpp>\n", _model,
                                platforms.write_declarations,
                                constants.write_declarations,
                                basetypes.write_declarations,
                                enums.write_declarations,
                                handles.write_declarations,
                                structs.write_declarations,
                                bitmasks.write_declarations,
                                funcpointers.write_declarations,
                                commands.write_declarations),
        API_ENUMS: make_header(API_ENUMS, f"#include <ktl/{API_COMMON}>\n\n", _model, enums.write_definitions),
        META_HANDLES: make_header(META_HANDLES, f"""#include <cstdint>
#include <format>
#include <type_traits>

#include <ktl/{API}>

""", _model, handles.write_meta),
        API_STRUCTS: make_header(API_STRUCTS, f"""#include <ktl/{API_COMMON}>
#include <ktl/{API_ENUMS}>

""", _model, structs.write_definitions),
        META_FORMATS: make_header(META_FORMATS, f"""#include <array>

#include <ktl/{API}>

""", _model, formats.write_meta),
        API_COMMANDS: make_header(API_COMMANDS, f"""#include <array>
#include <cstdlib>

#include <ktl/loader.hpp>
#include <ktl/{API}>

""", _model, commands.write_definitions),
        META_COMMANDS: make_header(META_COMMANDS, f"""#include <cstdlib>
#include <string_view>

#include <ktl/{API}>

""", _model, commands.write_meta),
        API_FEATURES: make_header(API_FEATURES, "#include <ktl/type.hpp>\n\n", _model, features.write_definitions),
        META_FEATURES: make_header(META_FEATURES, f"""#include <cstddef>
#include <cstdlib>

#include <ktl/{API}>

""", _model, features.write_meta),
        API_EXTENSIONS: make_header(API_EXTENSIONS, "#include <ktl/type.hpp>\n\n", _model, extensions.write_definitions),
        META_EXTENSIONS: make_header(META_EXTENSIONS, f"""#include <array>
#include <cstdlib>
#include <optional>
#include <span>
#include <string_view>

#include <ktl/{API}>
#include <ktl/meta/dependency.hpp>
#include <ktl/{API_VERSION}>

""", _model, extensions.write_meta),
        API_VERSION: make_header(API_VERSION, """#include <array>
#include <compare>
#include <format>
#include <functional>

#include <ktl/type.hpp>

""", _model, versions.write_definitions),
        META_VERSION: make_header(META_VERSION, f"""#include <array>
#include <span>

#include <ktl/{API}>
#include <ktl/{API_VERSION}>

""", _model, versions.write_meta),
        API: make_header(API, api_includes, _model),
        META: make_header(META, meta_includes, _model),
    }
