#include "../inc/libmx.h"

static int str_size(const char *str, const char *sub,
const char *replace, int count) {
    int size;
    int diff;
    int sub_l = mx_strlen(sub);
    int rep_l = mx_strlen(replace);

    diff = sub_l - rep_l;
    size = mx_strlen(str) + diff * count;
    return size;
}

static char *str_rep(const char *str, const char *sub,
const char *replace, int count) {
    int size = str_size(str, sub, replace, count);
    char *tmp = (char*)malloc((size + 1) * sizeof(char));
    int sub_l = mx_strlen(sub);
    char *ptr = tmp;
  
    while (*str != '\0') {
        if (!(mx_strncmp(str, sub, sub_l) == 0)) {
            *ptr++ = *str++;
        }
        if (mx_strncmp(str, sub, sub_l) == 0) {
            ptr = mx_strcat(ptr, replace);
            ptr = ptr + mx_strlen(replace);
            str = str + mx_strlen(sub);
        }
        *ptr = '\0';
    }
    return tmp;
}

char *mx_replace_substr(const char *str, const char *sub,
const char *replace) {
    char *res;
    int count;

    if (!str || !sub || !replace)
        return NULL;
    count = mx_count_substr(str, sub);
    res = str_rep(str, sub, replace, count);
    return res;
}

