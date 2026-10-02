import re
from basetypes import BASETYPES, NATIVE_TYPES
from platforms import PLATFORM_TYPES

# C names of vk.xml -> C++ names of ktl


# words of a camel case name as Khronos splits them to build VK_STRUCTURE_TYPE_* from a struct name
# (SPECIAL_WORDS and MAIN_RE of Vulkan-Docs scripts/vkconventions.py): a number is a word of its own
# except the special words, leading lowercase word is a member name
_SPECIAL_WORDS = ("16Bit", "2D", "3D", "8Bit", "AABB", "ASTC", "D3D12", "Float16", "Bfloat16", "Float8", "ImagePipe",
                  "Int64", "Int8", "MacOS", "RGBA10X6", "Uint8", "Win32")
# ktl additions: DirectFB is the subpattern _DIRECT_FB_ -> _DIRECTFB_ of the same Khronos script,
# the others are in member and command names, Khronos does not build anything from them
_EXTRA_SPECIAL_WORDS = ("DirectFB", "Rgba10x6", "YCbCr", "RandR")
_WORD = re.compile("|".join([
    r"[A-Z]{2,}s(?![a-z])",                                # plural of an acronym: numAABBs -> aabbs
    r"(?:B?[Ff]loat|U?[Ii]nt)(?:4|6|8|16|32|64)(?![0-9])", # bit width stays with its type: shaderInt16 -> int16
    *(re.escape(word) for word in sorted(_SPECIAL_WORDS + _EXTRA_SPECIAL_WORDS)),
    # after the special words, otherwise D3D12 is split
    r"(?:[RGBA][0-9]+){2,}", r"E[0-9]+M[0-9]+",            # formats as in their value names: A4R4G4B4, E8M0
    r"[0-9]+x[0-9]+(?:Bit)?", r"[0-9]+D(?![a-z])",         # 4x8Bit, 1D as 2D and 3D
    r"[0-9]+k(?![a-z])", r"[A-Z][0-9]+(?=[A-Z]|$)",        # 64k, L1, T0
    r"[0-9]+", r"[A-Z][a-z]+", r"[A-Z][A-Z]*(?![a-z])", r"[a-z]+"]))


def c_name_to_cpp(name: str) -> str:
    if name in ("sType", "pNext"):
        return name.lower()
    if not re.search(r"[A-Z]", name): # already snake case
        return name

    words = []
    for part in name.split("_"): # textureCompressionASTC_LDR
        part_words = _WORD.findall(part)
        if "".join(part_words) != part:
            raise ValueError(f"unexpected character in name {name!r}")
        words += part_words
    # PhysicalDeviceVulkan11Features -> physical_device_vulkan_1_1_features as VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES
    return re.sub(r"(^|_)vulkan_(\d)(\d)(_|$)", r"\1vulkan_\2_\3\4", "_".join(word.lower() for word in words))


_VERSION = re.compile(r"VK_(?:BASE_|COMPUTE_|GRAPHICS_)?VERSION_(\d+)_(\d+)")


def parse_version(_src: str) -> tuple[int, int] | None:
    # VK_VERSION_1_3 and the parts of a version: VK_BASE_VERSION_1_3, VK_COMPUTE_VERSION_1_3, VK_GRAPHICS_VERSION_1_3
    match = _VERSION.fullmatch(_src)
    return (int(match.group(1)), int(match.group(2))) if match else None


def make_version(_version: tuple[int, int]) -> str:
    return f"ktl::api::version_{_version[0]}_{_version[1]}"


def make_cpp_name(src: str) -> str | None:
    if src is None:
        return None
    if src.startswith("Vk") or src.startswith("vk"):
        return c_name_to_cpp(src[2:])
    if src.startswith("PFN_"):
        return c_name_to_cpp(src[6:])
    if src.startswith("VK_"):
        # extension names are snake case already, Khronos spelling is kept: VK_KHR_maintenance5 -> khr_maintenance5
        return src[3:].lower()
    return c_name_to_cpp(src)


def make_field_name(src: str, cmp: str) -> str | None:
    if src is None or not src.startswith("VK_"):
        return None
    # strip common prefix by whole words: VK_CULL_MODE_FRONT_BIT + cull_mode_flag_bits -> front_bit
    words = src.lower()[3:].split('_')
    if cmp is not None:
        def match(_prefix: list[str]) -> int:
            common = 0
            while common < min(len(words), len(_prefix)) and words[common] == _prefix[common]:
                common += 1
            return common

        # VK_ACCESS_2_NONE + access_flag_bits_2 -> none: values of FlagBits2 have no FLAG_BITS words,
        # but FLAG can be a part of the prefix (VK_DEVICE_FAULT_FLAG_VENDOR_KHR), so the longest match wins;
        # digits glued to a word of the enum name (special words of c_name_to_cpp) are compared as words of their own
        prefix = re.findall(r"[a-z]+|\d+", cmp)
        common = max(match(prefix), match([word for word in prefix if word not in ("flag", "bits")]))
        words = words[common:] or words
    # value names keep Khronos spelling: VK_FORMAT_R8G8B8A8_UNORM -> v_r8g8b8a8_unorm
    return f"v_{'_'.join(words)}"


def make_constant(src: str) -> str | None:
    if src is None or not src.startswith("VK_"):
        return None
    return "KTL_API" + src[2:]


# C types that are not generated from vk.xml: primitive, vulkan base, platform and native types
FIXED_TYPES = {
    **{name: name for name in ("void", "char", "int", "float", "double")},
    "int8_t": "ktl::i8", "int16_t": "ktl::i16", "int32_t": "ktl::i32", "int64_t": "ktl::i64",
    "uint8_t": "ktl::u8", "uint16_t": "ktl::u16", "uint32_t": "ktl::u32", "uint64_t": "ktl::u64",
    "size_t": "ktl::usize",
    **{c_name: f"ktl::api::{name}" for c_name, name, _ in BASETYPES},
    **PLATFORM_TYPES,
    **{name: name for name, _, _ in NATIVE_TYPES},
}
