from dataclasses import dataclass


@dataclass
class VkConstant:
    name: str
    tppe: str
    value: str

    def __hash__(self) -> int:
        return hash(self.name)

    def __eq__(self, other) -> bool:
        if not isinstance(other, VkConstant):
            return NotImplemented
        return self.name == other.name


@dataclass
class VkFunctionField:
    tppe: str
    name: str
    const: list[bool]
    array: list[str]


@dataclass
class VkFunction:
    pfn: str
    name: str
    tppe: str
    fields: list[VkFunctionField]
    alias: str | None
    level: str | None = None # global, instance, physical_device or device; commands only


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
    d: VkFormatComponent # depth
    s: VkFormatComponent # stencil
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
    const: list[bool]
    array: list[str]
    bitfield: str | None
    default_value: str

    @property
    def pointer_count(self) -> int:
        return len(self.const) - 1


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
            return NotImplemented
        return self.name == other.name


@dataclass
class VkEnum:
    name: str
    fields: list
    underling_type: str
    alias : str | None


@dataclass
class VkFeature:
    name: str
    stype: str
    struct: str


@dataclass
class VkExtension:
    name: str
    raw: str
    is_instance: bool
    promoted: str | None
    depends: list[list[str]] # any of the requirements, every dependency of a requirement
    commands: list[str]
    conditional_commands: list[tuple[str, list[list[str]]]]
