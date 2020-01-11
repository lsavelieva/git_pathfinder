#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *tmp1 = (unsigned char*)dst;
    unsigned char *tmp2 = (unsigned char*)src;

    while (n-- > 0)
        *tmp1++ = *tmp2++;
    return dst;
}

