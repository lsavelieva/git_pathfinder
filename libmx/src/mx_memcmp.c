#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned long i = 0;
    const char *tmp1 = (const char*)s1;
    const char *tmp2 = (const char*)s2;

    while (i < n) {
        if (tmp1[i] == tmp2[i])
            i++;
        else
            return tmp1[i] - tmp2[i];
    }
    return 0;
}

