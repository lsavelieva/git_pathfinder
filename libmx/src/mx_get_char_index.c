#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
    int flag = 0;
    int i = 0;

    if (!str)
        return i = -2;
    for (; str[i] != '\0'; i++) {
        if (str[i] != c)
            i++;
        if (str[i] == c) {
            flag = 1;
            return i;
        }
    }
    if (str[i] == '\0' && flag == 0)
        return i = -1;
    return i;
}

