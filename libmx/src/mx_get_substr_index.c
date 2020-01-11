#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int ind = 0;
    int i = 0;

    if (str == NULL || sub == NULL)
        return ind = -2;
    for (; str[i] != '\0'; i++) {
        if (mx_strncmp(str, sub, mx_strlen(sub)) == 0)
            return ind = i;
        str++;
    }
    if (str[i] == '\0')
        return ind = -1;
    return ind;
}

