#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len,
const void *little, size_t little_len) {
    char *res = (char*)big;

    if (!big_len || !little_len || big_len < little_len)
        return NULL;
    for (size_t i = 0; i <= big_len - little_len; i++) {
        if (mx_memcmp(res, little, little_len) == 0)
            return (char*)res;
        res++;
    }
    return NULL;
}
