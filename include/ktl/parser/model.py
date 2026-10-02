from dataclasses import dataclass, field
from decl import make_declaration
from naming import FIXED_TYPES, make_field_name

# vulkan part of vk.xml: every entity by its C name in the order of vk.xml.
# load reads the entities, their own names are C++ already, references to other entities are C names
# (a feature keeps the C++ name of the struct it is made of, it is not a reference to resolve);
# resolve checks every reference and completes what depends on other entities;
# write_* print C++ only, names of references are made by naming


@dataclass
class Constant:
    name: str                  # KTL_API_UUID_SIZE
    tppe: str                  # ktl::u32, orders the constants
    value: str                 # (~0U), or the name of the aliased constant


@dataclass
class EnumValue:
    name: str                  # v_r8g8b8a8_unorm
    value: str                 # number, bit (1U << 3), or the name of the aliased value
    is_alias: bool
    is_deprecated: bool


@dataclass
class Enum:
    name: str
    values: list[EnumValue]    # resolve: one per name, an alias names the final value
    underlying_type: str | None  # resolve: signed when a value is negative
    alias: str | None          # C name


@dataclass
class Handle:
    name: str
    parent: str | None         # C name
    object: str | None         # C name of the VkObjectType value
    is_dispatchable: bool
    alias: str | None          # C name


@dataclass
class Member:                  # of a struct, parameter or return type of a command or a funcpointer
    name: str
    tppe: str                  # C type
    const: list[bool]          # const of the type and of every pointer
    array: list[str]           # sizes: numbers or C names of constants
    bitfield: str | None = None
    is_optional: bool = False  # = {} for a member
    values: str | None = None  # C name of the value of sType

    @property
    def pointer_count(self) -> int:
        return len(self.const) - 1


@dataclass
class Struct:
    name: str
    members: list[Member]
    is_union: bool
    is_feature: bool           # chained into VkPhysicalDeviceFeatures2, or VkPhysicalDeviceFeatures itself
    alias: str | None          # C name


@dataclass
class Feature:
    name: str
    struct: str                # C++ name of the struct the feature is made of
    stype: str | None          # C name of the sType value, None for VkPhysicalDeviceFeatures


@dataclass
class Bitmask:
    name: str
    tppe: str | None           # C type: VkFlags or VkFlags64; resolve: the type of the target for an alias
    alias: str | None          # C name


@dataclass
class Function:                # command or funcpointer
    name: str                  # create_instance, pfn_ is added for its type
    raw: str                   # vkCreateInstance
    result: Member | None      # resolve: the ones of the target for an alias
    params: list[Member]
    alias: str | None          # C name
    level: str | None = None   # resolve: global, instance, physical_device or device; commands only


@dataclass
class Extension:
    name: str
    raw: str
    is_instance: bool
    promoted: tuple[int, int] | str | None  # version or C name of an extension
    # any of the requirements, every dependency of a requirement: version or C name of an extension
    depends: list[list[tuple[int, int] | str]]
    commands: list[str]        # C names, commands of <require> without depends
    conditional_commands: list[tuple[str, list[list[tuple[int, int] | str]]]]  # of <require depends="...">


@dataclass
class FormatComponent:
    bits: str
    has_plane: str
    plane_index: str
    is_present: str


@dataclass
class FormatPlane:
    width_divisor: str
    height_divisor: str
    compatible: str            # C name of the format


@dataclass
class Format:
    block_size: str
    texels_per_block: str
    packed: str
    chroma: str
    block_width: str
    block_height: str
    block_depth: str
    is_3d: str
    is_compressed: str

    r: FormatComponent
    g: FormatComponent
    b: FormatComponent
    a: FormatComponent
    d: FormatComponent # depth
    s: FormatComponent # stencil
    planes_amount: str
    planes: list[FormatPlane]


@dataclass
class Model:
    versions: tuple            # (major, minor) of every vulkan version, ascending
    vendors: tuple             # vendor suffixes of names: khr, ext, ...
    constants: dict[str, Constant] = field(default_factory=dict)
    enums: dict[str, Enum] = field(default_factory=dict)
    handles: dict[str, Handle] = field(default_factory=dict)
    structs: dict[str, Struct] = field(default_factory=dict)  # resolve: in the order of definitions
    features: dict[str, Feature] = field(default_factory=dict)  # by the C++ name of the feature
    bitmasks: dict[str, Bitmask] = field(default_factory=dict)
    funcpointers: dict[str, Function] = field(default_factory=dict)
    commands: dict[str, Function] = field(default_factory=dict)
    extensions: dict[str, Extension] = field(default_factory=dict)
    formats: dict[str, Format] = field(default_factory=dict)
    version_commands: dict[tuple[int, int], list[str]] = field(default_factory=dict)  # C names added by a version
    types: dict[str, str] = field(default_factory=dict)  # resolve_types: C type -> its C++ spelling
    _value_names: dict[str, set[str]] = field(default_factory=dict, repr=False)

    def find[T](self, _table: dict[str, T], _name: str | None, _what: str, _where: str) -> T:
        if _name not in _table:
            raise ValueError(f"{_where} refers to unknown {_what} {_name}")
        return _table[_name]

    def resolve_types(self) -> None:
        # every type that can be used by a member or a parameter: fixed and generated ones,
        # different C types must not become one C++ type
        types = dict(FIXED_TYPES)
        generated = [(table, "ktl::api::{}") for table in (self.enums, self.handles, self.structs, self.bitmasks)]
        for table, spelling in generated + [(self.funcpointers, "ktl::api::pfn_{}")]:
            for c_name, item in table.items():
                if c_name in types:
                    raise ValueError(f"type {c_name} is declared twice")
                types[c_name] = spelling.format(item.name)
        spellings = {}
        for c_name, spelling in types.items():
            if (other := spellings.setdefault(spelling, c_name)) != c_name:
                raise ValueError(f"types {other} and {c_name} are both {spelling}")
        self.types = types

    def check_member(self, _member: Member, _where: str) -> None:
        self.find(self.types, _member.tppe, "type", _where)
        for size in _member.array:
            if not size.isdigit():
                self.find(self.constants, size, "constant", _where)

    def check_value(self, _enum: str, _value: str | None, _where: str) -> None:
        # after enums.resolve: the value is one of the final values of the enum
        if _enum not in self._value_names:
            enum = self.find(self.enums, _enum, "enum", _where)
            self._value_names[_enum] = {value.name for value in enum.values}
        if self.value_name(_enum, _value) not in self._value_names[_enum]:
            raise ValueError(f"{_where} refers to unknown value {_value} of {_enum}")

    def value_name(self, _enum: str, _value: str) -> str:
        return make_field_name(_value, self.enums[_enum].name)

    def value_ref(self, _enum: str, _value: str) -> str:
        return f"ktl::api::{self.enums[_enum].name}::{self.value_name(_enum, _value)}"

    def declare(self, _member: Member) -> str:
        return make_declaration(self.types[_member.tppe], _member.const, _member.name, _member.array, _member.bitfield)
