#include <std/base/constant_symbols.h>
#ifdef STD_PLATFORM_WINDOWS

#include <std/mem/page.h>
#include <std/windows/constants.h>
#include <std/windows/kernel32.h>
#include "page_implementation.h"

static const u32 PAGEPROTECTION_TO_POSIX_LOOKUP[8] = {
	/* 0                                                                               */
	STD_WINDOWS_PAGE_NOACCESS,
	/* STD_PAGEPROTECTION_READ                                                         */
	STD_WINDOWS_PAGE_READONLY,
	/* STD_PAGEPROTECTION_WRITE                                                        */
	STD_WINDOWS_PAGE_READWRITE,
	/* STD_PAGEPROTECTION_READ | STD_PAGEPROTECTION_WRITE                              */
	STD_WINDOWS_PAGE_READWRITE,
	/* STD_PAGEPROTECTION_EXECUTE                                                      */
	STD_WINDOWS_PAGE_EXECUTE,
	/* STD_PAGEPROTECTION_EXECUTE | STD_PAGEPROTECTION_READ                            */
	STD_WINDOWS_PAGE_EXECUTE_READ,
	/* STD_PAGEPROTECTION_EXECUTE | PAGE_READWRITE                                     */
	STD_WINDOWS_PAGE_EXECUTE_READWRITE,
	/* STD_PAGEPROTECTION_EXECUTE | STD_PAGEPROTECTION_READ | STD_PAGEPROTECTION_WRITE */ 
	STD_WINDOWS_PAGE_EXECUTE_READWRITE,
};

static u32 std_pageprotection_to_windows(std_PageProtection protection) {
	if (protection >= 8) {
		return 0;
	} else {
		return PAGEPROTECTION_TO_POSIX_LOOKUP[protection];
	}
}

std_PageResult _std_page_create_impl(std_Page* page) {
	/* TODO: Support large pages */
	void* result = VirtualAlloc(
		page->address,
		page->size,
		STD_WINDOWS_MEM_COMMIT,
		std_pageprotection_to_windows(page->protection)
	);
	if (result == null) {
		return STD_PAGERESULT_MAP_OPERATION_FAILED;
	}

	if (page->address != result) {
		page->address = result;
	}

	return STD_PAGERESULT_SUCCESS;
}

void _std_page_destroy_impl(std_Page page) {
	VirtualFree(page.address, 0, STD_WINDOWS_MEM_RELEASE);
}

#endif


