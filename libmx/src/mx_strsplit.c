#include "../inc/libmx.h"

static int wordlen(const char *s, char c) {
    int i = 0;
    char *temp = (char *)s;

    while (*temp++ != c) {
        i++;
    }
    return i;
}
static char **cycle(const char *s, char c, size_t count) {
    char *tmp = (char *)s;
    char **res;
    int wl = 0;
    int i = 0;

    res = (char **)malloc((count + 1) * sizeof(char *));
    while (*tmp && *tmp != '\0') {
        if (*tmp != c) {
            wl = wordlen(tmp, c);
            res[i] = mx_strnew(wordlen(tmp, c));
            res[i] = mx_strncpy(res[i], tmp, wl);
            i++;
            tmp += wl;
        }
        tmp++;
    }
    res[i] = NULL;
    return res;
}

char **mx_strsplit(const char *s, char c) {
    char **res = NULL;
    size_t count = 0;

    if (!s)
        return NULL;
    count = mx_count_words(s, c);
    res = cycle(s, c, count);
    return res;
}

