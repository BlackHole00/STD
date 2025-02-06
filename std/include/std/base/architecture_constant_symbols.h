#ifndef _STD_BASEARCHITECTURECONSTANTSYMBOLS_INCLUDED
#define _STD_BASEARCHITECTURECONSTANTSYMBOLS_INCLUDED

#if defined(__x86_64__) || defined(_M_X64)
	#define STD_ARCHITECTURE_AMD64 1
	#define STD_ARCHITECTURE_BITS 64
	#define STD_ARCHITECTURE_64BITS 1

#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
	#define STD_ARCHITECTURE_I386 1
	#define STD_ARCHITECTURE_BITS 32
	#define STD_ARCHITECTURE_32BITS 1

#elif defined(__ARM_ARCH_2__   ) || defined(__ARM_ARCH_3__  ) || defined(__ARM_ARCH_3M__) || \
	defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T ) || defined(__ARM_ARCH_5_  ) || \
	defined(__ARM_ARCH_5E_ ) || defined(__ARM_ARCH_6T2_ ) || defined(__ARM_ARCH_6T2_) || \
	defined(__ARM_ARCH_6__ ) || defined(__ARM_ARCH_6J__ ) || defined(__ARM_ARCH_6K__) || \
	defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__) || defined(__ARM_ARCH_7__ ) || \
	defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__ ) || defined(__ARM_ARCH_7M__) || \
	defined(__ARM_ARCH_7S__) || defined(__ARM_ARCH_7A__ ) || defined(__ARM_ARCH_7R__) || \
	defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__ ) || defined(__ARM_ARCH_7R__) || \
	defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__ ) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
	#define STD_ARCHITECTURE_OLD_ARM 1
	/* TODO: Arm might be 16 or even 8 bits */
	#define STD_ARCHITECTURE_BITS 32
	#define STD_ARCHITECTURE_32BITS 1

#elif defined(__aarch64__) || defined(_M_ARM64)
	#define STD_ARCHITECTURE_ARM64 1
	#define STD_ARCHITECTURE_BITS 64
	#define STD_ARCHITECTURE_64BITS 1

#elif defined(mips) || defined(__mips__) || defined(__mips)
	#define STD_ARCHITECTURE_MIPS 1
	#define STD_ARCHITECTURE_BITS 32
	#define STD_ARCHITECTURE_32BITS 1

#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
	#define STD_ARCHITECTURE_PPC 1
	#define STD_ARCHITECTURE_BITS 32
	#define STD_ARCHITECTURE_32BITS 1

#elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
	#define STD_ARCHITECTURE_PPC64 1
	#define STD_ARCHITECTURE_BITS 64
	#define STD_ARCHITECTURE_64BITS 1

#elif defined(__sparc__) || defined(__sparc)
	#define STD_ARCHITECTURE_SPARK 1
	#define STD_ARCHITECTURE_BITS 32
	#define STD_ARCHITECTURE_32BITS 1

#elif defined(__m68k__)
	#define STD_ARCHITECTURE_M68K 1
	#define STD_ARCHITECTURE_BITS 32
	#define STD_ARCHITECTURE_32BITS 1

#else
	#define STD_ARCHITECTURE_UNKNOWN 1
#endif

#endif

