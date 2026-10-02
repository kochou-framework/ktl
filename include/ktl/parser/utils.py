from vk_types import VkStruct, VkStructField
from collections import defaultdict, deque


import re

# words of a camel case name as Khronos splits them to build VK_STRUCTURE_TYPE_* from a struct name
# (SPECIAL_WORDS and MAIN_RE of Vulkan-Docs scripts/vkconventions.py): a number is a word of its own
# except the special words, leading lowercase word is a member name
_SPECIAL_WORDS = ("16Bit", "2D", "3D", "8Bit", "AABB", "ASTC", "D3D12", "Float16", "Bfloat16", "Float8", "ImagePipe",
                  "Int64", "Int8", "MacOS", "RGBA10X6", "Uint8", "Win32")
# ktl additions for member and command names, Khronos does not build anything from them
_EXTRA_SPECIAL_WORDS = ("Rgba10x6", "YCbCr", "RandR")
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

def is_vulkan_video(name: str) -> bool: # vulkan-video is not supported now
    return "video" in name.lower()


def make_vulkan_value(_number: str, _offset: str, _direction: str | None = None) -> str:
    value = 1_000_000_000 + (int(_number) - 1) * 1000 + int(_offset)
    return str(-value if _direction == "-" else value)


_PRIMITIVES = frozenset({
    'int', 'uint', 'int8_t', 'uint8_t', 'int16_t', 'uint16_t',
    'int32_t', 'uint32_t', 'int64_t', 'uint64_t', 'size_t', 'ptrdiff_t',
    'void', 'bool', 'float', 'double', 'char', 'wchar_t', 'nullptr_t',
})


def _extract_type_name(tppe: str) -> str | None:
    """
    Извлекает базовое имя типа из «чистого» tppe (без *, const и т.д.).
    Примеры:
        'ktl::api::physical_device_limits' → 'physical_device_limits'
        'VkInstance' → 'VkInstance'
        'uint32_t' → None
    """
    if not tppe:
        return None
    
    tppe = tppe.strip()
    
    # Убираем префиксы пространства имён
    for prefix in ['const ', 'volatile ', 'struct ', 'class ', 'ktl::api::']:
        while tppe.startswith(prefix):
            tppe = tppe[len(prefix):]
    
    tppe = tppe.strip()
    if not tppe or tppe in _PRIMITIVES:
        return None
    
    # Если осталось ::, берём последнюю часть (базовое имя)
    if '::' in tppe:
        tppe = tppe.split('::')[-1]
    
    return tppe if tppe else None


def _get_dependencies(item: VkStruct) -> set[str]:
    """
    Собирает множество имён типов, от которых зависит item.
    Игнорирует:
    - примитивные типы
    - самоссылки через указатели (T* внутри T не требует полного определения)
    """
    deps = set()
    item_name = item.name

    # Зависимость от alias (using A = B требует, чтобы B был определён)
    if item.alias and isinstance(item.alias, str):
        if ref := _extract_type_name(item.alias):
            deps.add(ref)
    
    # Зависимости от полей
    for field in item.fields:
        if not isinstance(field, VkStructField) or not field.tppe:
            continue
        
        if ref := _extract_type_name(field.tppe):
            # ⚠️ Ключевое: если поле — указатель на САМ СЕБЯ, это не зависимость
            # (forward declaration достаточно для T*)
            if field.pointer_count > 0 and ref == item_name:
                continue
            deps.add(ref)
    
    return deps


def sort_by_dependencies(items: list[VkStruct]) -> list[VkStruct]:
    """
    Топологическая сортировка (алгоритм Кана).
    Типы, от которых зависят другие, будут идти раньше.
    """
    name_to_item: dict[str, VkStruct] = {it.name: it for it in items}
    in_degree: defaultdict[str, int] = defaultdict(int)
    graph: defaultdict[str, list[str]] = defaultdict(list)
    
    # Инициализируем in_degree для всех узлов
    for name in name_to_item:
        in_degree[name]  # создаёт запись со значением 0
    
    # Строим граф: edge A→B означает "B зависит от A"
    for item in items:
        deps = _get_dependencies(item)
        for dep in deps:
            if dep in name_to_item:  # только если тип есть в списке генерации
                graph[dep].append(item.name)
                in_degree[item.name] += 1
    
    # Алгоритм Кана: начинаем с узлов без входящих рёбер
    queue = deque([name for name in in_degree if in_degree[name] == 0])
    result: list[VkStruct] = []
    
    while queue:
        current = queue.popleft()
        result.append(name_to_item[current])
        
        for neighbor in graph[current]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)
    
    # Проверка на циклы
    if len(result) != len(items):
        processed = {it.name for it in result}
        remaining = [it.name for it in items if it.name not in processed]
        
        # Отладочный вывод зависимостей проблемных типов
        import sys
        print(f"\n=== UNRESOLVED: {remaining} ===", file=sys.stderr)
        for name in remaining:
            item = name_to_item[name]
            deps = _get_dependencies(item)
            print(f"{name} depends on: {deps}", file=sys.stderr)
            for f in item.fields:
                if isinstance(f, VkStructField):
                    #print(f"  field: {f.name} : {f.tppe} (ptr={f.is_pointer})", file=sys.stderr)
                    pass
        
        raise ValueError(f"Cyclic dependencies or unresolved types: {remaining}")
    
    return result
