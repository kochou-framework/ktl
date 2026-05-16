import xml.etree.ElementTree as ET
from pathlib import Path
import urllib.request
import headers
import constants
import enums
import handles
import structs
import bitmasks
import formats
import pointers
import commands
import features
import extensions

API_DIR = "api/"
META_DIR = "meta/"

API_COMMON_HEADER_FILE     = f"{API_DIR}common.hpp"
API_ENUMS_HEADER_FILE      = f"{API_DIR}enum.hpp"
API_HANDLES_HEADER_FILE    = f"{API_DIR}handle.hpp"
API_STRUCTS_HEADER_FILE    = f"{API_DIR}struct.hpp"
API_FORMATS_HEADER_FILE    = f"{API_DIR}format.hpp"
API_COMMANDS_HEADER_FILE   = f"{API_DIR}command.hpp"
API_FEATURES_HEADER_FILE   = f"{API_DIR}feature.hpp"
API_EXTENSIONS_HEADER_FILE = f"{API_DIR}extension.hpp"
API_HEADER_FILE        = "api.hpp"

META_ENUMS_HEADER_FILE      = f"{META_DIR}enum.hpp"
META_HANDLES_HEADER_FILE    = f"{META_DIR}handle.hpp"
META_STRUCTS_HEADER_FILE    = f"{META_DIR}struct.hpp"
META_FORMATS_HEADER_FILE    = f"{META_DIR}format.hpp"
META_COMMANDS_HEADER_FILE   = f"{META_DIR}command.hpp"
META_FEATURES_HEADER_FILE   = f"{META_DIR}feature.hpp"
META_EXTENSIONS_HEADER_FILE = f"{META_DIR}extension.hpp"
META_VERSION_HEADER_FILE    = f"{META_DIR}version.hpp"
META_HEADER_FILE            = "meta.hpp"


def main(_root):
    CONSTANTS         = constants.extract(_root)
    ENUMS             = enums.extract(_root) + enums.extract_aliased(_root)
    HANDLES           = handles.extract(_root)
    STRUCTS, FEATURES = structs.extract(_root)
    BITMASKS          = bitmasks.extract(_root)
    FORMATS           = formats.extract(_root)
    POINTERS          = pointers.extract(_root) 
    COMMANDS          = commands.extract(_root)
    _          = features.extract(_root, ENUMS, COMMANDS)
    EXTENSIONS        = extensions.extract(_root, ENUMS)
    VERSION_COMMANDS  = commands.extract_version_commands(_root);

    headers.fill_common(API_COMMON_HEADER_FILE,
                        CONSTANTS,
                        ENUMS,
                        HANDLES,
                        STRUCTS,
                        BITMASKS,
                        POINTERS,
                        COMMANDS)
    headers.fill_enums(API_HEADER_FILE,
                       API_COMMON_HEADER_FILE,
                       API_ENUMS_HEADER_FILE,
                       ENUMS)
    headers.fill_handles(API_HEADER_FILE,
                         META_HANDLES_HEADER_FILE,
                         HANDLES)
    headers.fill_structs(API_HEADER_FILE,
                         API_COMMON_HEADER_FILE,
                         API_ENUMS_HEADER_FILE,
                         API_STRUCTS_HEADER_FILE,
                         STRUCTS)
    headers.fill_formats(API_HEADER_FILE,
                         API_FORMATS_HEADER_FILE,
                         META_FORMATS_HEADER_FILE,
                         FORMATS)
    headers.fill_commands(API_HEADER_FILE,
                          API_COMMANDS_HEADER_FILE,
                          META_COMMANDS_HEADER_FILE,
                          COMMANDS)
    headers.fill_features(API_HEADER_FILE,
                          API_FEATURES_HEADER_FILE,
                          META_FEATURES_HEADER_FILE,
                          FEATURES)
    headers.fill_extensions(API_HEADER_FILE,
                            API_EXTENSIONS_HEADER_FILE,
                            META_EXTENSIONS_HEADER_FILE,
                            EXTENSIONS)
    headers.fill_version(API_HEADER_FILE,
                         META_VERSION_HEADER_FILE,
                         VERSION_COMMANDS)
    headers.fill_api(API_HEADER_FILE,
                     API_COMMON_HEADER_FILE,
                     API_ENUMS_HEADER_FILE,
                     API_STRUCTS_HEADER_FILE,
                     API_COMMANDS_HEADER_FILE,
                     API_FEATURES_HEADER_FILE,
                     API_EXTENSIONS_HEADER_FILE)
    headers.fill_meta(META_HEADER_FILE,
                      META_EXTENSIONS_HEADER_FILE,
                      META_FEATURES_HEADER_FILE,
                      META_FORMATS_HEADER_FILE,
                      META_HANDLES_HEADER_FILE,
                      META_ENUMS_HEADER_FILE,
                      META_COMMANDS_HEADER_FILE,
                      META_VERSION_HEADER_FILE)


if __name__ == "__main__":
    url = "https://raw.githubusercontent.com/KhronosGroup/Vulkan-Docs/main/xml/vk.xml"
    urllib.request.urlretrieve(url, "vk.xml")
    xml  = Path("vk.xml")
    root = ET.parse(xml).getroot()
    main(root)
