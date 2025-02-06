#include <std/base/constant_symbols.h>
#ifdef STD_PLATFORM_DARWIN

#include <std/mem/page.h>
#include <std/posix/constants.h>
#include <std/posix/syscalls.h>
#include "page_implementation.h"

static i32 std_pageprotection_to_posix(std_PageProtection protection) {
	/* NOTE: Happens to be in the same order as posix :-) */
	return (i32)protection;
}

std_PageResult _std_page_create_impl(std_Page* page) {
	i32 posix_flags = STD_POSIX_MMAP_ANON | STD_POSIX_MMAP_SHARED;

	void* result = std_posix_syscall_mmap(
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
	std_posix_syscall_munmap(page.address, page.size);
}

#endif

