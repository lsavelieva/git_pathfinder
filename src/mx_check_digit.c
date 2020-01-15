#include "../inc/pathfinder.h"

int mx_check_digit(const char *s, int n, int line_nbr) {
    char *f_line = mx_strnew(n);
    int res = 0;
    int digit = 0;

    f_line = mx_strncpy(f_line, s, n);
    while (*s != '\n') {
        digit = mx_atoi(s);
        if (digit < 0 || (!(mx_isdigit((int)(*s)))))
            mx_error_invalid_line(line_nbr);
        s++;
    }
    res = mx_atoi(f_line);
    if (res >= 0)
        mx_printstr("\x1b[32mOK FOR CHECK_DIGIT\033[0m \n");
    free(f_line);
    return res;
}
