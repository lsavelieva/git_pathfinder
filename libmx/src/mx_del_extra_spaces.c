#include "../inc/libmx.h"

static char *del_wspaces(const char *str) {
    char *tmp;
    char *t;
    int i = 0;
    int j = 0;
    int size = mx_strlen(str);

    tmp = mx_strnew(size);
    while (str[i] != '\0') {
        while (mx_isspace(str[i]) == 0 && (str[i] != '\0'))
            tmp[j++] = str[i++];
        while (mx_isspace(str[i]) == 1 && (str[i] != '\0'))
            i++;
        tmp[j] = ' ';
        j++;
    }
    t = mx_strtrim(tmp);
    free(tmp);
    return t;
}

char *mx_del_extra_spaces(const char *str) {
    char *res;

    if (!str)
        return NULL;
    res = del_wspaces(str);
    return res;
}

