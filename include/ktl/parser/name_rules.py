import re
from utils import c_name_to_cpp
from type_cast import cast_type, DEFAULT_NEGATIVE_TYPE, DEFAULT_POSITIVE_TYPE


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


def make_underling_type(_src: str, _direction: bool) -> str | None:
    if not _src:
        return DEFAULT_POSITIVE_TYPE if _direction else DEFAULT_NEGATIVE_TYPE
    return cast_type(_src) if _direction else cast_type(f"-{_src}")


def make_type(_src: str) -> str | None:
    if _src is None:
        return None
    return cast_type(_src)


def make_bitpos(src: str, underling_type: str) -> str | None:
    if src is None:
        return None
    if underling_type in ("ktl::u32", "ktl::i32"):
        return f"(1U << {src})"
    if underling_type in ("ktl::u64", "ktl::i64"):
        return f"(1ULL << {src})"
    return None # non valid for vulkan spec


def make_constant(src: str) -> str | None:
    if src is None or not src.startswith("VK_"):
        return None
    return "KTL_API" + src[2:]
