# ktl - kochou template library
Library provides custom API Vulkan headers, some templates, noexept memory and reflection (waiting for normal C++ 26 compilers support)

## Namespaces
### ```ktl::api``` and ```ktl::meta```
Like a base C Vulkan headers, but contains language inside Vulkan entities metadata.
There are headers generator writen on Python that use vk.xml (API Vulkan spec) on input.
### ```ktl::reflection```
Some reflection methods that will be usefull in framework components.
### ```ktl::memory```
Noexcept memory. Will expand with some allocators later.
### common ```ktl```
Common templates and error codes. Also OS-depends dynamic library interface.
