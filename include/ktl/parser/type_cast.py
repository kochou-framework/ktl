from platforms import cast_platform_type
from utils import c_name_to_cpp

DEFAULT_POSITIVE_TYPE = "ktl::u32"
DEFAULT_NEGATIVE_TYPE = "ktl::i32"

def is_exception(_type: str) -> bool:
    if _type == "OHNativeWindow":
        return True
    if _type == "OHBufferHandle":
        return True
    if _type == "OH_NativeBuffer":
        return True
    if _type == "CAMetalLayer":
        return True
    if _type == "MTLDevice_id":
        return True
    if _type == "MTLCommandQueue_id":
        return True
    if _type == "MTLBuffer_id":
        return True
    if _type == "MTLTexture_id":
        return True
    if _type == "MTLSharedEvent_id":
        return True
    if _type == "IOSurfaceRef":
        return True
    if _type == "ANativeWindow":
        return True
    if _type == "AHardwareBuffer":
        return True

    if _type == "int":
        return True
    if _type == "void":
        return True
    if _type == "char":
        return True
    if _type == "float":
        return True
    if _type == "double":
        return True

    return False


def cast_type(_type : str) -> str | None:
    if is_exception(_type):
        return _type
    if platform_type := cast_platform_type(_type):
        return platform_type

    if _type == "int8_t" or _type == "std::int8_t":
        return "ktl::i8"
    if _type == "int16_t" or _type == "std::int16_t":
        return "ktl::i16"
    if _type == "int32_t" or _type == "std::int32_t":
        return "ktl::i32"
    if _type == "int64_t" or _type == "std::int64_t":
        return "ktl::i64"

    if _type == "uint8_t" or _type == "std::uint8_t":
        return "ktl::u8"
    if _type == "uint16_t" or _type == "std::uint16_t":
        return "ktl::u16"
    if _type == "uint32_t" or _type == "std::uint32_t":
        return "ktl::u32"
    if _type == "uint64_t" or _type == "std::uint64_t":
        return "ktl::u64"

    if _type == "8":
        return "ktl::u8"
    if _type == "16":
        return "ktl::u16"
    if _type == "32":
        return "ktl::u32"
    if _type == "64":
        return "ktl::u64"
    if _type == "-8":
        return "ktl::i8"
    if _type == "-16":
        return "ktl::i16"
    if _type == "-32":
        return "ktl::i32"
    if _type == "-64":
        return "ktl::i64"

    if _type == "size_t":
        return "ktl::usize"

    if _type == "VkResult":
        return "ktl::api::result"
    if _type == "VkSampleMask":
        return "ktl::api::spmask"
    if _type == "VkBool32":
        return "ktl::api::bool32"
    if _type == "VkFlags":
        return "ktl::api::flag32"
    if _type == "VkFlags64":
        return "ktl::api::flag64"
    if _type == "VkDeviceSize":
        return "ktl::api::dvsize"
    if _type == "VkDeviceAddress":
        return "ktl::api::dvaddr"
    if _type == "VkRemoteAddressNV":
        return "ktl::api::remote_address_nv"

    # funcpointers are declared by pointers.py as pfn_*: PFN_vkAllocationFunction -> ktl::api::pfn_allocation_function
    if _type.startswith("PFN_vk"):
        return f"ktl::api::pfn_{c_name_to_cpp(_type[6:])}"

    return None
