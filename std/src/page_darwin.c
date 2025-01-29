#ifdef STD_PLATFORM_DARWIN

#include <std/page.h>

#include <std/constant_symbols.h>
#include <std/syscalls.h>

#define STD_POSIX_MMAP_PROT_NONE 0x0000
#define STD_POSIX_MMAP_PROT_READ 0x0001
#define STD_POSIX_MMAP_PROT_WRITE 0x0002
#define STD_POSIX_MMAP_PROT_EXEC 0x0004

#define STD_POSIX_MMAP_SHARED 0x0001
#define STD_POSIX_MMAP_ANON 0x1000

#define STD_POSIX_MMAP_FAILED (void*)-1

static i32 std_pageprotection_to_posix(std_PageProtection protection) {
	/* NOTE: Happens to be in the same posix order :-) */
	return (i32)protection;
}

std_PageResult _std_page_create_impl(std_Page* page) {
	i32 posix_flags = STD_POSIX_MMAP_ANON | STD_POSIX_MMAP_SHARED;

	void* result = std_syscall_mmap(
		page->address,
		page->size,
		std_pageprotection_to_posix(page->protection),
		posix_flags,
		-1,
		0
	);
	if (result == STD_POSIX_MMAP_FAILED) {
		return STD_PAGERESULT_MAP_OPERATION_FAILED;
	}

	if (page->address != result) {
		page->address = result;
	}

	return STD_PAGERESULT_SUCCESS;
}

void _std_page_destroy_impl(std_Page page) {
	std_syscall_munmap(page.address, page.size);
}

#endif

