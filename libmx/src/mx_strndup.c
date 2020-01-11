#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *copy;
    size_t size;

    if (!s1)
        return NULL;
    size = mx_strlen(s1);
    copy = size < n ? mx_strnew(size) : mx_strnew(n);
    copy = size < n ? mx_strncpy(copy, s1, size) : mx_strncpy(copy, s1, n);
    return copy;
}

