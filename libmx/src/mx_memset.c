#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    char *tmp = (char*)b;

    while (len-- > 0)
        *tmp++ = c;
    return b;
}

