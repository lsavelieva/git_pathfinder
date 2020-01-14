#include "../inc/pathfinder.h"

int mx_check_digit(const char *s, int n) {
    char *f_line = mx_strnew(n);
    int res = 0;

    f_line = mx_strncpy(f_line, s, n);
    res = mx_atoi(f_line);
    if (res >= 0)
        mx_printstr("\x1b[32mOK FOR CHECK_DIGIT\033[0m \n");
    free(f_line);
    return res;
}
