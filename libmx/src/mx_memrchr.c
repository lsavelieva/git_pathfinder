#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    char *tmp = (char*)s;

    while (n--) {
        if (tmp[n] == c)
            return tmp + n;
    }
    return NULL;
}

