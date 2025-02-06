.global _std_posix_syscall_write
.global _std_posix_syscall_mmap
.global _std_posix_syscall_munmap

// @fn isize std_posix_syscall_write(u32 file_descriptor, const void* buffer, usize buffer_size)
// @brief Calls the write syscall
// @param file_descriptor x0
// @param buffer x1
// @param buffer_size x2
// @return the number of bytes written. -1 if an error occurred.
_std_posix_syscall_write:
	mov x16, #4
	movk x16, #512, lsl #16
	svc #0x80
	ret

// @fn void* std_posix_syscall_mmap(void* base_address, isize length, i32 protection, i32 flags, i32 file_descriptor, isize offset)
// @brief Calls the mmap syscall
// @param base_address x0
// @param length x1
// @param protection x2
// @param flags x3
// @param file_descriptor x4
// @param offset x5
// @return the address of the requested page
_std_posix_syscall_mmap:
	mov x16, #197
	movk x16, #512, lsl #16
	svc #0x80
	ret

_std_posix_syscall_munmap:
	mov x16, #73
	movk x16, #512, lsl #16
	svc #0x80
	ret

_std_posix_syscall_sysctl:
	mov x16, #202
	movk x16, #512, lsl #16
	svc #0x80

