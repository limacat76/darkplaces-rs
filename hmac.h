#ifndef HMAC_H
#define HMAC_H

#include <stdbool.h>
// END 010-quakedef.h.3

typedef void (*hashfunc_t) (unsigned char *out, const unsigned char *in, int n);
bool hmac(
	hashfunc_t hfunc, int hlen, int hblock,
	unsigned char *out,
	const unsigned char *in, int n,
	const unsigned char *key, int k
);

#define HMAC_MDFOUR_16BYTES(out, in, n, key, k) hmac(mdfour, 16, 64, out, in, n, key, k)
#define HMAC_SHA256_32BYTES(out, in, n, key, k) hmac(sha256, 32, 64, out, in, n, key, k)

#endif
