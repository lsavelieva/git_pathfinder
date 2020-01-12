#include "../inc/pathfinder.h"

static int check_digit(const char *s, int n) {
    // int n = mx_get_char_index(s, '\n');
    char *f_line = mx_strnew(n);
    int res = 0;

    f_line = mx_strncpy(f_line, s, n);
    res = mx_atoi(f_line);
    if (res >= 0)
        mx_printstr("\x1b[32mOK FOR CHECK_DIGIT\033[0m \n");
    free(f_line);
    return res;
}

static void error_invalid_line(int line) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(line));
    mx_printerr(" is not valid\n");
    exit (-1);
}
static void check_next(char *s, int line_nbr) {
    int n = mx_get_char_index(s, '\n');
    int digit = 0;

    s = s + n + 1; //printf("%s\n", s);
    line_nbr += 1;
    while (*s != '\0') {
        while (*s != 45) { mx_printchar(*s);
            if (!(mx_isalpha(*s)))
                error_invalid_line(line_nbr);
            s++;
        }
        s++;
        while (*s != 44) { mx_printchar(*s);
            if (!(mx_isalpha(*s)))
                error_invalid_line(line_nbr);
            s++;
        }
        s++;
        while (*s != '\n') { mx_printchar(*s);
            digit = mx_atoi(s);
            if (digit <= 0)
                error_invalid_line(line_nbr);
            s++;
        }
        s++;
        line_nbr += 1;
    }
    printf("%d\n", line_nbr);
    mx_printstr("\x1b[33mRESULT OF MX_CHECK_NEXT\033[0m \n");


}

// static void check_for_island(char *name, int line_nbr) {
//     while (*name != '\0') {
//         if (mx_isalpha(*name) == false) {
//             mx_print_invalid_line(line_nbr);
//         }
//     }
// }

int mx_check_line(const char *file) {
    char *content;
    int fl;
    int line_nbr = 1;
    int n;

    content = mx_file_to_str(file);
    n = mx_get_char_index(content, '\n');
    fl = check_digit(content, n);
    if (fl == 0 || fl < 0) {
        mx_printstr("\x1b[33mRESULT OF MX_CHECK_FIRST\033[0m \n");
        error_invalid_line(line_nbr);
    }
    check_next(content, line_nbr);
    free(content);
    mx_printstr("\x1b[32mOK FOR MX_CHECK_LINE\033[0m \n");
    return 0;
}
