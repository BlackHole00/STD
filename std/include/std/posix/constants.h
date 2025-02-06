#ifndef _STD_POSIXCONSTANTS_INCLUDED
#define _STD_POSIXCONSTANTS_INCLUDED

#include <std/base/constant_symbols.h>
#ifdef STD_PLATFORM_POSIX

#define STD_POSIX_MMAP_PROT_NONE 0x0000
#define STD_POSIX_MMAP_PROT_READ 0x0001
#define STD_POSIX_MMAP_PROT_WRITE 0x0002
#define STD_POSIX_MMAP_PROT_EXEC 0x0004

#define STD_POSIX_MMAP_SHARED 0x0001
#define STD_POSIX_MMAP_ANON 0x1000

#define STD_POSIX_MMAP_FAILED (void*)-1

#endif
#endif

