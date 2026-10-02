import re
from dataclasses import dataclass
from naming import make_constant


@dataclass
class CDecl:
    tppe: str             # raw C type, e.g. "VkInstanceCreateInfo", "uint32_t"
    name: str             # raw C name
    const: list[bool]     # const qualifier per level: [base type, 1st pointer, 2nd pointer, ...]
    array: list[str]      # array dimensions, e.g. ["3", "4"] or ["VK_UUID_SIZE"]
    bitfield: str | None  # bitfield width, e.g. "24"

    @property
    def pointer_count(self) -> int:
        return len(self.const) - 1


def parse_decl(_root) -> CDecl:
    """
    Parses C declaration from <member>, <param> or <proto>:
        const <type>char</type>* const* <name>ppEnabledLayerNames</name>
        <type>float</type> <name>matrix</name>[3][4]
        <type>uint32_t</type> <name>mask</name>:8
    <comment> is not a part of declaration and is skipped
    """
    tppe = None
    name = None
    prefix = [_root.text or ""]
    middle = []
    suffix = []
    current = prefix
    for child in _root:
        if child.tag == "type":
            tppe = child.text.strip()
            current = middle
        elif child.tag == "name":
            name = child.text.strip()
            current = suffix
        elif child.tag != "comment":
            current.append("".join(child.itertext()))
        current.append(child.tail or "")

    if tppe is None or name is None:
        raise ValueError(f"declaration without type or name: {''.join(_root.itertext())!r}")

    const = ["const" in re.findall(r"\w+", "".join(prefix))]
    for token in re.findall(r"\w+|\*", "".join(middle)):
        if token == "*":
            const.append(False)
        elif token == "const":
            const[-1] = True
        else:
            raise ValueError(f"unexpected token {token!r} in declaration of {name}")

    suffix = "".join(suffix)
    array = re.findall(r"\[\s*([^\]]+?)\s*\]", suffix)
    bitfield = re.search(r":\s*(\d+)", suffix)
    return CDecl(tppe, name, const, array, bitfield.group(1) if bitfield else None)


def make_array_size(_src: str) -> str:
    if _src.isdigit():
        return _src
    if size := make_constant(_src):
        return size
    raise ValueError(f"unexpected array size {_src!r}")


def make_declaration(_tppe: str, _const: list[bool], _name: str = "", _array: list[str] = (), _bitfield: str | None = None) -> str:
    result = f"const {_tppe}" if _const[0] else _tppe
    for is_const in _const[1:]:
        result += " *"
        if is_const:
            result += " const"
    if _name:
        result += f" {_name}"
    for size in _array:
        result += f"[{make_array_size(size)}]"
    if _bitfield:
        result += f" : {_bitfield}"
    return result
