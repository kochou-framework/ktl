import functools

# vk.xml describes vulkan, vulkansc and vulkanbase, ktl is generated for vulkan only:
# api="..." of any element and supported="..." of an extension are comma-separated lists


def is_vulkan_video(name: str) -> bool: # vulkan-video is not supported now
    return "video" in name.lower()


def is_vulkan_api(_root) -> bool:
    return "vulkan" in (_root.get("api") or "vulkan").split(",")


def is_vulkan_extension(_root) -> bool:
    # vulkan video extensions are not generated: types and commands required only by them are excluded too
    return "vulkan" in _root.get("supported").split(",") and not is_vulkan_video(_root.get("name"))


def vulkan_features(_root) -> list:
    return [feature for feature in _root.findall("feature") if is_vulkan_api(feature)]


def feature_version(_feature) -> tuple[int, int]:
    # number="1.3" of VK_BASE_VERSION_1_3, VK_COMPUTE_VERSION_1_3, VK_GRAPHICS_VERSION_1_3 and VK_VERSION_1_3
    major, minor = _feature.get("number").split(".")
    return int(major), int(minor)


@functools.cache
def vulkan_versions(_root) -> tuple:
    # every vulkan version of vk.xml, ascending: ktl::api::version_X_Y, common_versions and meta::version<> are made of it
    return tuple(sorted({feature_version(feature) for feature in vulkan_features(_root)}))


def vulkan_extensions(_root) -> list:
    return [extension for extension in _root.find("extensions").findall("extension") if is_vulkan_extension(extension)]


def vulkan_requires(_block) -> list:
    return [require for require in _block.findall("require") if is_vulkan_api(require)]


@functools.cache
def excluded_names(_root) -> frozenset:
    # types and commands required only by vulkansc features or by vulkansc / disabled extensions
    vulkan = set()
    other = set()
    blocks = [(feature, is_vulkan_api(feature)) for feature in _root.findall("feature")]
    blocks += [(extension, is_vulkan_extension(extension)) for extension in _root.find("extensions").findall("extension")]
    for block, is_vulkan in blocks:
        for require in block.findall("require"):
            names = vulkan if is_vulkan and is_vulkan_api(require) else other
            names.update(item.get("name") for item in require if item.tag in ("type", "command"))
    return frozenset(other - vulkan)


def is_vulkan_type(_root, _type) -> bool:
    # name is an attribute, a <name> child or, for funcpointer, <proto><name>
    name = _type.get("name") or _type.findtext("name") or _type.findtext("proto/name")
    return is_vulkan_api(_type) and name not in excluded_names(_root)
