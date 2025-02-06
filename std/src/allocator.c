#include <std/mem/allocator.h>

std_AllocatorResult std_allocator_alloc(std_Allocator allocator, usize size, void** new_pointer) {
	return allocator.proc_table->alloc(allocator.data, size, new_pointer);
}

std_AllocatorResult std_allocator_dealloc(std_Allocator allocator, void* pointer) {
	return allocator.proc_table->dealloc(allocator.data, pointer);
}

std_AllocatorResult std_allocator_realloc(std_Allocator allocator, void* old_pointer, usize size, void** new_pointer) {
	return allocator.proc_table->realloc(allocator.data, old_pointer, size, new_pointer);
}

std_AllocatorResult std_allocator_dealloc_all(std_Allocator allocator) {
	return allocator.proc_table->dealloc_all(allocator.data);
}


