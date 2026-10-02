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


def definition_name(_definition) -> str:
    # name is an attribute, a <name> child or, for funcpointer and command, <proto><name>
    return _definition.get("name") or _definition.findtext("name") or _definition.findtext("proto/name")


@functools.cache
def required_names(_root) -> frozenset:
    # types, commands and API constants that vulkan features and extensions require, with everything their definitions
    # refer to, as Khronos generates the headers: what nothing requires is not generated (empty VkSemaphoreCreateFlagBits),
    # the ones of vulkansc, disabled and video extensions neither (VK_MAX_VIDEO_AV1_REFERENCES_PER_FRAME_KHR)
    definitions = {definition_name(definition): definition
                   for definition in _root.find("types").findall("type") + _root.find("commands").findall("command")
                   if is_vulkan_api(definition)}
    names = set()
    for block in vulkan_features(_root) + vulkan_extensions(_root):
        for require in vulkan_requires(block):
            names.update(item.get(attribute) for item in require if item.tag in ("type", "command", "enum")
                         for attribute in ("name", "extends") if item.get(attribute))

    # alias target, FlagBits of a bitmask, parent handle, types of members and parameters, constants of array sizes
    unresolved = list(names)
    while unresolved:
        definition = definitions.get(unresolved.pop())
        if definition is None:
            continue
        references = {definition.get(attribute) for attribute in ("alias", "requires", "bitvalues", "parent")}
        references |= {child.text for child in definition.iter() if child is not definition and child.tag in ("type", "enum")}
        for reference in references - names - {None}:
            names.add(reference)
            unresolved.append(reference)
    return frozenset(names)


def is_vulkan_type(_root, _type) -> bool:
    return is_vulkan_api(_type) and definition_name(_type) in required_names(_root)
