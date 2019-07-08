#ifndef LTX_PLATFORM_H
#define LTX_PLATFORM_H

#include "cvar.h"
// END 010-quakedef.h.3

extern cvar_t sessionid;

#define STARTCONFIGFILENAME "quake.rc"
#define CONFIGFILENAME "config.cfg"

/* Preprocessor macros to identify platform
	DP_OS_NAME 	- "friendly" name of the OS, for humans to read
	DP_OS_STR	- "identifier" of the OS, more suited for code to use
	DP_ARCH_STR	- "identifier" of the processor architecture
 */
#if defined(__ANDROID__) /* must come first because it also defines linux */
# define DP_OS_NAME		"Android"
# define DP_OS_STR		"android"
# define USE_GLES2		1
# define USE_RWOPS		1
# define LINK_TO_ZLIB	1
# define LINK_TO_LIBVORBIS 1
# define DP_MOBILETOUCH	1
# define DP_FREETYPE_STATIC 1
#elif defined(__linux__)
# define DP_OS_NAME		"Linux"
# define DP_OS_STR		"linux"
#elif defined(_WIN64)
# define DP_OS_NAME		"Windows64"
# define DP_OS_STR		"win64"
#elif defined(WIN32)
# define DP_OS_NAME		"Windows"
# define DP_OS_STR		"win32"
#elif defined(__FreeBSD__)
# define DP_OS_NAME		"FreeBSD"
# define DP_OS_STR		"freebsd"
#elif defined(__NetBSD__)
# define DP_OS_NAME		"NetBSD"
# define DP_OS_STR		"netbsd"
#elif defined(__OpenBSD__)
# define DP_OS_NAME		"OpenBSD"
# define DP_OS_STR		"openbsd"
#elif defined(__MORPHOS__)
# define DP_OS_NAME		"MorphOS"
# define DP_OS_STR		"morphos"
#else
# define DP_OS_NAME		"Unknown"
# define DP_OS_STR		"unknown"
#endif

#if defined(__GNUC__)
# if defined(__i386__)
#  define DP_ARCH_STR		"686"
#  define SSE_POSSIBLE
#  ifdef __SSE__
#   define SSE_PRESENT
#  endif
#  ifdef __SSE2__
#   define SSE2_PRESENT
#  endif
# elif defined(__x86_64__)
#  define DP_ARCH_STR		"x86_64"
#  define SSE_PRESENT
#  define SSE2_PRESENT
# elif defined(__powerpc__)
#  define DP_ARCH_STR		"ppc"
# endif
#elif defined(_WIN64)
# define DP_ARCH_STR		"x86_64"
# define SSE_PRESENT
# define SSE2_PRESENT
#elif defined(WIN32)
# define DP_ARCH_STR		"x86"
# define SSE_POSSIBLE
#endif

#ifdef SSE_PRESENT
# define SSE_POSSIBLE
#endif

#ifdef NO_SSE
# undef SSE_PRESENT
# undef SSE_POSSIBLE
# undef SSE2_PRESENT
#endif

#ifdef SSE_POSSIBLE
 // runtime detection of SSE/SSE2 capabilities for x86
bool Sys_HaveSSE(void);
bool Sys_HaveSSE2(void);
#else
#define Sys_HaveSSE() false
#define Sys_HaveSSE2() false
#endif

void Sys_Shared_Init(void);

// Flag in size field of demos to indicate a client->server packet. Demo
// playback will ignore this, but it may be useful to make DP sniff packets to
// debug protocol exploits.
#define DEMOMSG_CLIENT_TO_SERVER 0x80000000

// In Quake, any char in 0..32 counts as whitespace
//#define ISWHITESPACE(ch) ((unsigned char) ch <= (unsigned char) ' ')
#define ISWHITESPACE(ch) (!(ch) || (ch) == ' ' || (ch) == '\t' || (ch) == '\r' || (ch) == '\n')

// This also includes extended characters, and ALL control chars
#define ISWHITESPACEORCONTROL(ch) ((signed char) (ch) <= (signed char) ' ')


#ifdef PRVM_64
#define FLOAT_IS_TRUE_FOR_INT(x) ((x) & 0x7FFFFFFFFFFFFFFF) // also match "negative zero" doubles of value 0x8000000000000000
#define FLOAT_LOSSLESS_FORMAT "%.17g"
#define VECTOR_LOSSLESS_FORMAT "%.17g %.17g %.17g"
#else
#define FLOAT_IS_TRUE_FOR_INT(x) ((x) & 0x7FFFFFFF) // also match "negative zero" floats of value 0x80000000
#define FLOAT_LOSSLESS_FORMAT "%.9g"
#define VECTOR_LOSSLESS_FORMAT "%.9g %.9g %.9g"
#endif

// originally this was _MSC_VER
// but here we want to test the system libc, which on win32 is borked, and NOT the compiler
#ifdef WIN32
#define INT_LOSSLESS_FORMAT_SIZE "I64"
#define INT_LOSSLESS_FORMAT_CONVERT_S(x) ((__int64)(x))
#define INT_LOSSLESS_FORMAT_CONVERT_U(x) ((unsigned __int64)(x))
#else
#define INT_LOSSLESS_FORMAT_SIZE "j"
#define INT_LOSSLESS_FORMAT_CONVERT_S(x) ((intmax_t)(x))
#define INT_LOSSLESS_FORMAT_CONVERT_U(x) ((uintmax_t)(x))
#endif

#endif