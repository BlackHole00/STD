#ifndef _STD_PAGE_INCLUDED
#define _STD_PAGE_INCLUDED

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

#include <std/constant_symbols.h>
#include <std/types.h>
#include <std/slice.h>

typedef enum std_PageResult {
	STD_PAGERESULT_NO_PERMISSION_PROVIDED = -1,
	STD_PAGERESULT_SUCCESS = 0,
	STD_PAGERESULT_INVALID_DESCRIPTOR,
	STD_PAGERESULT_MAP_OPERATION_FAILED
} std_PageResult;

typedef enum std_PageProtectionFlag {
	/** @brief The contents of the page can be read */
	STD_PAGEPROTECTION_READ = 0x1,
	/** @brief The contents of the page can be rewritten */
	STD_PAGEPROTECTION_WRITE = 0x2,
	/** @brief The contetns of the page can be executed */
	STD_PAGEPROTECTION_EXECUTE = 0x4
} std_PageProtectionFlag;
typedef u8 std_PageProtection; /* bitfield of std_PageProcetionFlag */

typedef struct std_PageDescriptor {
	void* page_address;
	usize page_size;
	std_PageProtection protection;
} std_PageDescriptor;

/**
	@struct std_Page
	@brief an abstraction over a memory page requested with mmap (*nix) or
		VirtualAlloc (windows)
	@note the page is not ment to map to a file, it is intended to be kept 
		local to the process
*/
typedef struct std_Page {
	void* address;
	usize size;
	std_PageProtection protection;
} std_Page;


std_PageResult std_page_create(std_Page* page, std_PageDescriptor descriptor);
void std_page_destroy(std_Page page);

std_Slice std_page_as_byte_slice(std_Page page);
std_Slice std_page_as_slice(std_Page page, u32 element_size);

#ifndef STD_DISALLOW_GLOBAL_NAMESPACE
	#define Page std_Page
	#define PageDescriptor std_PageDescriptor
	#define PageProcetionFlag std_PageProcetionFlag
	#define PageProtection std_PageProtection
	#define page_create std_page_create
	#define page_destroy std_page_destroy
	#define page_as_slice std_page_as_slice
#endif

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif
