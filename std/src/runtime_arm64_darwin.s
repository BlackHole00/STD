.global __stack_chk_fail
__stack_chk_fail:
	mov x0, #1
	ret

.global __stack_gnu_guard
__stack_gnu_guard:
	ret
