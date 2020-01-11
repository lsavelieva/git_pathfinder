#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const char *tmp = s;

    for (unsigned long i = 0; i <= n; i++) {
        if (*tmp == c)
            return (void*)tmp;
        tmp++;
    }
    return NULL;
}

