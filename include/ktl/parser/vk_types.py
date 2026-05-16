from dataclasses import dataclass


@dataclass
class VkConstant:
    name: str
    tppe: str
    value: str

    def __hash__(self) -> int:
        return hash(self.name)

    def __eq__(self, other) -> bool:
        if not isinstance(other, VkEnumField):
            return True
        return self.name == other.name


@dataclass
class VkFunctionField:
    tppe: str
    name: str
    is_const: bool
    is_pointer: bool

    def __hash__(self) -> int:
        return hash(self.name)

    def __eq__(self, other) -> bool:
        if not isinstance(other, VkEnumField):
            return True
        return self.name == other.name


@dataclass
class VkFunction:
    pfn: str
    name: str
    tppe: str
    fields: list[VkFunctionField]
    alias: str | None


@dataclass
class VkFormatComponent:
    bits: str
    has_plane: str
    plane_index: str
    is_present: str


@dataclass
class VkFormatPlane:
    width_divisor: str
    height_divisor: str
    compatible: str


@dataclass
class VkFormat:
    name: str
    block_size: str
    texels_per_block: str
    packed: str
    chroma: str
    block_width: str
    block_height: str
    block_depth: str
    is_3d: str
    is_compressed: str

    r: VkFormatComponent
    g: VkFormatComponent
    b: VkFormatComponent
    a: VkFormatComponent
    planes_amount: str
    planes: list[VkFormatPlane]


@dataclass
class VkBitMask:
    name: str
    tppe: str


@dataclass
class VkHandle:
    name: str
    opaque: str
    pointer: str
    parent: str
    object: str
    alias: str | None


@dataclass
class VkStructField:
    tppe: str
    name: str
    is_optional: bool
    is_const: bool
    pointer_count: int
    default_value: str


@dataclass
class VkStruct:
    name: str
    fields: list[VkStructField]
    is_union: bool
    alias: str | None


@dataclass
class VkEnumField:
    name: str
    value: str
    is_alias: bool
    is_deprecated: bool

    def __hash__(self) -> int:
        return hash(self.name)

    def __eq__(self, other) -> bool:
        if not isinstance(other, VkEnumField):
            return True
        return self.name == other.name


@dataclass
class VkEnum:
    name: str
    fields: dict
    underling_type: str
    alias : str | None


@dataclass
class VkFeature:
    name: str
    stype: str
    struct: str


@dataclass
class VkDependency:
    """Представление зависимости: одно из полей будет заполнено."""
    feature: str | None
    extension: str | None
    version: str | None
    
    def is_version(self) -> bool:
        return self.version is not None
    
    def get_version_tuple(self):
        if not self.version:
            return None
        # "VK_VERSION_1_2" -> (1, 2)
        parts = self.version.replace("VK_VERSION_", "").split("_")
        return (int(parts[0]), int(parts[1]))
    
    def get_name(self):
        """Возвращает имя расширения или версии для отображения."""
        return self.extension or self.version or self.feature or ""


@dataclass
class VkEntension:
    name: str
    raw: str
    version: str
    is_instance: bool
    promoted: str | None
    deps: dict[str, list[VkDependency]]
    commands: list
