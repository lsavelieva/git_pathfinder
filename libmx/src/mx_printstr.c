#include "../inc/libmx.h"

void mx_printstr(const char *s) {
    int len = mx_strlen(s);
    int i = 0;

    write(1, &s[i], len);
    return;
}

