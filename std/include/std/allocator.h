#ifndef _STD_ALLOCATOR_INCLUDED
#define _STD_ALLOCATOR_INCLUDED

#include <std/constant_symbols.h>
#include <std/types.h>

#ifdef STD_LANGUAGE_CPP
extern "C" {
#endif

typedef enum std_AllocatorResult {
	STD_ALLOCATOR_RESULT_SUCCESS = 0,
	STD_ALLOCATOR_RESULT_UNSUPPORTED_OPERATION,
	STD_ALLOCATOR_RESULT_INVALID_PARAMETER,
	STD_ALLOCATOR_RESULT_ALLOCATION_FAILED
} std_AllocatorResult;

typedef std_AllocatorResult (*std_AllocatorAllocProc)(void* allocator_data, usize size, void** new_pointer);
typedef std_AllocatorResult (*std_AllocatorDeallocProc)(void* allocator_data, void* pointer);
typedef std_AllocatorResult (*std_AllocatorReallocProc)(
	void* allocator_data,
	void* old_pointer,
	usize size,
	void** new_pointer
);
typedef std_AllocatorResult (*std_AllocatorDeallocAllProc)(void* allocator_data);

typedef struct std_AllocatorProcTable {
	std_AllocatorAllocProc alloc;
	std_AllocatorDeallocProc dealloc;
	std_AllocatorReallocProc realloc;
	std_AllocatorDeallocAllProc dealloc_all;
} std_AllocatorProcTable;

typedef struct std_Allocator {
	void* data;
	std_AllocatorProcTable* proc_table;
} std_Allocator;

std_AllocatorResult std_allocator_alloc(std_Allocator allocator, usize size, void** new_pointer);
std_AllocatorResult std_allocator_dealloc(std_Allocator allocator, void* pointer);
std_AllocatorResult std_allocator_realloc(std_Allocator allocator, void* old_pointer, usize size, void** new_pointer);
std_AllocatorResult std_allocator_dealloc_all(std_Allocator allocator);

#ifdef STD_LANGUAGE_CPP
}
#endif

#endif

