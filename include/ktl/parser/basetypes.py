from typing import TextIO

# ktl::api names of vulkan base types (type_cast.cast_type maps VkBool32 and others to them), checked by decl.check_types
BASETYPES = (
    ("bool32", "ktl::u32"),
    ("flag32", "ktl::u32"),
    ("flag64", "ktl::u64"),
    ("dvsize", "ktl::u64"),
    ("dvaddr", "ktl::u64"),
    ("spmask", "ktl::u32"),
    ("remote_address_nv", "void *"),
)


def fill_definition(_file: TextIO,):
    _file.write("""
namespace ktl::api
{
""")
    for name, tppe in BASETYPES:
        _file.write(f"using {name} = {tppe};\n")
    _file.write("""}

struct ANativeWindow;
struct AHardwareBuffer;

#ifdef __OBJC__
@class CAMetalLayer;
@protocol MTLDevice;
typedef __unsafe_unretained id< MTLDevice > MTLDevice_id;
@protocol MTLCommandQueue;
typedef __unsafe_unretained id< MTLCommandQueue > MTLCommandQueue_id;
@protocol MTLBuffer;
typedef __unsafe_unretained id< MTLBuffer > MTLBuffer_id;
@protocol MTLTexture;
typedef __unsafe_unretained id< MTLTexture > MTLTexture_id;
@protocol MTLSharedEvent;
typedef __unsafe_unretained id< MTLSharedEvent > MTLSharedEvent_id;
#else
using CAMetalLayer       = void;
using MTLDevice_id       = void *;
using MTLCommandQueue_id = void *;
using MTLBuffer_id       = void *;
using MTLTexture_id      = void *;
using MTLSharedEvent_id  = void *;
#endif

typedef struct __IOSurface * IOSurfaceRef;
typedef struct NativeWindow OHNativeWindow;
struct OHBufferHandle;
struct OH_NativeBuffer;
""")


def fill_implementation():
    pass # nothing to do


def fill_meta():
    pass # nothing to do
