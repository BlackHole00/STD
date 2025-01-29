#include <std/page.h>
#include <std/memory_constants.h>

#include "page_implementation.h"

static std_PageResult pagedescriptor_is_valid(std_PageDescriptor descriptor) {
	/*
	TODO: Implement page size probing
	if ((descriptor.page_size % PAGE_SIZE) != 0) {
		return STD_PAGERESULT_INVALID_DESCRIPTOR;
	}
	*/
	if (descriptor.protection == 0) {
		return STD_PAGERESULT_NO_PERMISSION_PROVIDED;
	}

	return STD_PAGERESULT_SUCCESS;
}

std_PageResult std_page_create(std_Page* page, std_PageDescriptor descriptor) {
	std_PageResult descriptor_check_res = pagedescriptor_is_valid(descriptor);

	if (descriptor_check_res != STD_PAGERESULT_SUCCESS) {
		return descriptor_check_res;
	}

	page->address = descriptor.page_address;
	page->protection = descriptor.protection;
	page->size = descriptor.page_size;

	return _std_page_create_impl(page);
}

void std_page_destroy(std_Page page) {
	_std_page_destroy_impl(page);
}

std_Slice std_page_as_byte_slice(std_Page page) {
	return std_slice_create(page.address, page.size, 0);
}

std_Slice std_page_as_slice(std_Page page, u32 element_size) {
	usize element_count = page.size / element_size;
	return std_slice_create(page.address, element_count, element_size);
}
