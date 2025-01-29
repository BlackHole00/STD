#ifndef _STD_SYSCALLS_INCLUDED
#define _STD_SYSCALLS_INCLUDED

#include <std/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
	@fn std_syscall_write
	@brief calls the write syscall
	@param file_descriptor
	@param buffer
	@param buffer_size
	@return the number of bytes written. -1 if an error occurred
*/
extern isize std_syscall_write(u32 file_descriptor, const void* buffer, usize buffer_size);

extern void* std_syscall_mmap(
	void* base_address,
	isize length,
	i32 protection,
	i32 flags,
	i32 file_descriptor,
	isize offset
);

extern i32 std_syscall_munmap(void* address, usize length);

#ifdef __cplusplus
}
#endif


#endif
