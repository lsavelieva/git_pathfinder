#include "../inc/libmx.h"

char *mx_strchr(const char *s, int c) {
    int i = 0;

    while (s[i] && s[i] != c)
        ++i;
    return c == s[i] ? (char*)s + i : NULL;
}
