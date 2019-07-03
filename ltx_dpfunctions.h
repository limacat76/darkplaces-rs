#ifndef LTX_DPFUNCTIONS_H
#define LTX_DPFUNCTIONS_H

#if defined(__GNUC__) && (__GNUC__ > 2)
#define DP_FUNC_PRINTF(n) __attribute__ ((format (printf, n, n+1)))
#define DP_FUNC_PURE      __attribute__ ((pure))
#define DP_FUNC_NORETURN  __attribute__ ((noreturn))
#else
#define DP_FUNC_PRINTF(n)
#define DP_FUNC_PURE
#define DP_FUNC_NORETURN
#endif 

#endif