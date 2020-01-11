#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    int sub_len;

    if (str == NULL || sub == NULL)
        return -1;
    sub_len = mx_strlen(sub);
    while (*str != '\0') {
        if (mx_strncmp(str, sub, sub_len) == 0) {
            count++;
            str = str + sub_len;
        }
        else
            str++;
    }
    return count;
}

