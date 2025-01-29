# Vicix'STD
STD is an alternative cross-platform standard library for C for modern systems and architectures.
STD is written in C89 and assembly. STD supports cpp compilers.  

STD plans to support posix systems (MacOS, Linux, BSDs) and Windows. Both on the AMD64 and ARM64 architectures.
Other targets might be added in the future.  

Please note that currently the project runs only on arm macs. Other platforms will be supported in the future.

## Philosophy
STD aims to be, over anything else, simple and readable. Its source code (both the headers and the implementation) will always be comprehensive and easy to understand.
This means that code in STD will keep macro usage to a minimum and avoid obscure C features (this includes macro-based generics).  

From a features standpoint, STD will not and does not aim to provide all the features that libc has. STD is opinionated in how things should and shouldn't be done.  

Memory management is manual, but STD will offer ways to easily handle the memory (like Arenas and custom allocators). Currently it does not support an alternative to malloc and free. This may even remain the case in the long term, as I personally believe that the majority of cases does not need traditional heap memory allocations and can (and should) be handled with other tools.

## Planned features for 0.1:
- [X] slices (in the limit of macro-less C)
- [X] strings (UTF8)
- [ ] custom allocators (malloc/free not included)
- [ ] good logging
- [ ] a type registry (RTTI at home)
- [ ] context system
- [ ] file manipulation
- [ ] support all the platforms
- [ ] ...

## Other planned features:
- [ ] dynamic linking
- [ ] os interface
- [ ] json serialization/deserialization
- [ ] toml (or ini?) serialization/deserialization
- [ ] binary serialization/deserialization
- [ ] threading and synchronization primitives
- [ ] task system (will be highly opinionated)
- [ ] ...

# Building
STD uses a unity build system. Just run `./build.sh` in the root of the project and the project will build.  
Other build scripts will come as long as more architectures are supported.

