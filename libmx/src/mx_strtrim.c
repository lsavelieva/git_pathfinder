#include "../inc/libmx.h"

static int start(const char *s) {
    int a = 0;

    for (; mx_isspace(s[a]) == 1; a++)
        ;
    return a;
}

static int end(const char *s) {
    int b = mx_strlen(s) - 1;

    for (; mx_isspace(s[b]);)
        b--;
    return b;
}

char *mx_strtrim(const char *str) {
    int k;
    int j;
    char *str1;

    if (str == NULL)
        return NULL;
    k = start(str);
    j = end(str);
    if (j == -1)
        return "\0";
    str1 = mx_strnew(j - k);
    str1 = mx_strncpy(str1, &str[k], j - k + 1);
    if (str1 == NULL)
        return NULL;
    return str1;
}
