#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    char *res;
    int n_len;

    if (!haystack || !needle)
        return NULL;
    res = (char*)haystack;
    n_len = mx_strlen(needle);
    if (mx_strlen(haystack) < n_len)
        return NULL;
    while (*res != '\0') {
        if (mx_strncmp(res, needle, n_len) == 0)
            return (char*)res;
        res++;
    }
    return NULL;
}

