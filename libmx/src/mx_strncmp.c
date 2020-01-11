#include "../inc/libmx.h"

int mx_strncmp(const char *s1, const char *s2, size_t n) {
    size_t i = 0;

    while (i < n) {
        if (s1[i] == s2[i])
            i++;
        else
            return s1[i] - s2[i];
    }
    return 0;
}

