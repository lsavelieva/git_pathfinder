#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int j;

    if (!s)
        return;
    j = mx_strlen(s);
    for (int i = 0; i != mx_strlen(s)/2; i++, j--) {
        mx_swap_char(&s[i], &s[j - 1]);
    }
}

