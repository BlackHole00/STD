#ifndef _STD_BASEPLATFORMCONSTANTSYMBOLS_INCLUDED
#define _STD_BASEPLATFORMCONSTANTSYMBOLS_INCLUDED

#if defined(_WIN32) || defined(_WIN64)
	#define STD_PLATFORM_WINDOWS 1
	#define STD_SUBPLATFORM_WIN32 1
#elif defined(__CYGWIN__)
	#define STD_PLATFORM_WINDOWS 1
	#define STD_SUBPLATFORM_CYGWIN 1
	/*
		It is still possible to use Win32 API user Cygwin. Std will use
		them instead of posix. TODO: Decide to allow or disallow cygwin
	*/
	#define STD_SUBPLATFORM_WIN32 1

#elif defined(__linux__)
	#define STD_PLATFORM_POSIX 1
	#define STD_PLATFORM_LINUX 1
#elif defined(__linux) || defined(linux)
	#define STD_PLATFORM_OLD_LINUX 1

#elif defined(__unix__) || defined(__unix) || defined(unix)
	#define STD_PLATFORM_POSIX 1
	#define STD_PLATFORM_UNIX 1

#elif defined(__APPLE__)
	#ifdef __MACH__
		#define STD_PLATFORM_POSIX 1
		#define STD_PLATFORM_DARWIN 1
		#define STD_PLATFORM_UNIX 1
	#else
		#define STD_PLATFORM_OLD_MACOS 1
	#endif

#elif defined(__ANDROID__)
	#define STD_PLATFORM_POSIX 1
	#define STD_PLATFORM_ANDROID 1

#else
	#define STD_PLATFORM_UNKNOWN 1
#endif

#endif

