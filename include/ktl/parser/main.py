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
import versions
from model import Model
from api_filter import vulkan_versions


def main(_root):
    model = Model(vulkan_versions(_root), features.vulkan_vendors(_root))

    # load: vulkan entities of vk.xml, references between them are C names
    constants.load(_root, model)
    enums.load(_root, model)
    handles.load(_root, model)
    structs.load(_root, model)
    features.load(model)
    bitmasks.load(_root, model)
    formats.load(_root, model)
    pointers.load(_root, model)
    commands.load(_root, model)
    extensions.load(_root, model)
    versions.load(_root, model)

    # resolve: every reference is checked, what depends on other entities is completed
    enums.resolve(model)
    model.resolve_types()
    handles.resolve(model)
    structs.resolve(model)
    bitmasks.resolve(model)
    formats.resolve(model)
    pointers.resolve(model)
    commands.resolve(model)
    extensions.resolve(model)
    versions.resolve(model)

    # every file is generated before the first one is written
    for path, text in headers.generate(model).items():
        with open(path, "w", encoding="utf-8") as file:
            file.write(text)


if __name__ == "__main__":
    url = "https://raw.githubusercontent.com/KhronosGroup/Vulkan-Docs/main/xml/vk.xml"
    urllib.request.urlretrieve(url, "vk.xml")
    xml  = Path("vk.xml")
    root = ET.parse(xml).getroot()
    main(root)
