#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n) {
    char *tmp1 = (char*)dst;
    const char *tmp2 = (const char*)src;
    size_t i = 0;

    while (i < n && *tmp2 != c) {
        *tmp1++ = *tmp2++;
        i++;
    }
    if (*tmp2 == c) {
        *tmp1++ = *tmp2++;
        return tmp1;
    }
    return NULL;
}

