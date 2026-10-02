from itertools import groupby
from typing import TextIO

# vulkan base types: (vk.xml name, ktl::api name, type)
BASETYPES = (
    ("VkBool32",          "bool32",            "ktl::u32"),
    ("VkFlags",           "flag32",            "ktl::u32"),
    ("VkFlags64",         "flag64",            "ktl::u64"),
    ("VkDeviceSize",      "dvsize",            "ktl::u64"),
    ("VkDeviceAddress",   "dvaddr",            "ktl::u64"),
    ("VkSampleMask",      "spmask",            "ktl::u32"),
    ("VkRemoteAddressNV", "remote_address_nv", "void *"),
)

# types of native headers that vk.xml uses by name: ktl declares them itself and uses them as they are,
# an Objective-C type has a stand-in outside of Objective-C: (name, declaration, stand-in or None)
NATIVE_TYPES = (
    ("ANativeWindow",      "struct ANativeWindow;",   None),
    ("AHardwareBuffer",    "struct AHardwareBuffer;", None),
    ("CAMetalLayer",       "@class CAMetalLayer;",    "void"),
    ("MTLDevice_id",       "@protocol MTLDevice;\ntypedef __unsafe_unretained id< MTLDevice > MTLDevice_id;", "void *"),
    ("MTLCommandQueue_id", "@protocol MTLCommandQueue;\ntypedef __unsafe_unretained id< MTLCommandQueue > MTLCommandQueue_id;", "void *"),
    ("MTLBuffer_id",       "@protocol MTLBuffer;\ntypedef __unsafe_unretained id< MTLBuffer > MTLBuffer_id;", "void *"),
    ("MTLTexture_id",      "@protocol MTLTexture;\ntypedef __unsafe_unretained id< MTLTexture > MTLTexture_id;", "void *"),
    ("MTLSharedEvent_id",  "@protocol MTLSharedEvent;\ntypedef __unsafe_unretained id< MTLSharedEvent > MTLSharedEvent_id;", "void *"),
    ("IOSurfaceRef",       "typedef struct __IOSurface * IOSurfaceRef;",  None),
    ("OHNativeWindow",     "typedef struct NativeWindow OHNativeWindow;", None),
    ("OHBufferHandle",     "struct OHBufferHandle;",  None),
    ("OH_NativeBuffer",    "struct OH_NativeBuffer;", None),
)


def write_declarations(_file: TextIO, _model) -> None:
    _file.write("""
namespace ktl::api
{
""")
    for _, name, tppe in BASETYPES:
        _file.write(f"using {name} = {tppe};\n")
    _file.write("}\n")

    # consecutive Objective-C types share one #ifdef __OBJC__
    for is_objc, group in groupby(NATIVE_TYPES, key=lambda native: native[2] is not None):
        group = list(group)
        _file.write("\n")
        if is_objc:
            width = max(len(name) for name, _, _ in group)
            _file.write("#ifdef __OBJC__\n")
            _file.write("".join(f"{declaration}\n" for _, declaration, _ in group))
            _file.write("#else\n")
            _file.write("".join(f"using {name:<{width}} = {standin};\n" for name, _, standin in group))
            _file.write("#endif\n")
        else:
            _file.write("".join(f"{declaration}\n" for _, declaration, _ in group))
