#include "../inc/pathfinder.h"

// static int check_digit(const char *s, int n) {
//     char *f_line = mx_strnew(n);
//     int res = 0;

//     f_line = mx_strncpy(f_line, s, n);
//     res = mx_atoi(f_line);
//     if (res >= 0)
//         mx_printstr("\x1b[32mOK FOR CHECK_DIGIT\033[0m \n");
//     free(f_line);
//     return res;
// }

// static void error_invalid_line(int line) {
//     mx_printerr("error: line ");
//     mx_printerr(mx_itoa(line));
//     mx_printerr(" is not valid\n");
//     exit (-1);
// }

static char *cycle(char *s, int line_nbr, char c) {
    while (*s != c) {  //mx_printchar(*s);
        if (!(mx_isalpha(*s)))
            mx_error_invalid_line(line_nbr);
        s++;
    }
    //s++;
    return s;
}

static char *d_cycle(char *s, int line_nbr) {
    int digit = 0;

    while (*s != '\n') {   //x_printchar(*s);
        digit = mx_atoi(s);
        if (digit < 0 || (!(mx_isdigit((int)(*s)))))
            mx_error_invalid_line(line_nbr);
        s++;
    }
    return s;
}

static void check_next(char *s, int line_nbr) {
    int n = mx_get_char_index(s, '\n');
    // int digit = 0;

    s = s + n + 1; //printf("%s\n", s);
    line_nbr += 1;
    while (*s != '\0') {
        if (mx_get_char_index(s, 45) == 0
            || mx_get_char_index(s, 44) - mx_get_char_index(s, 45) == 1
            || mx_get_char_index(s, 10) - mx_get_char_index(s, 44) == 1)
            mx_error_invalid_line(line_nbr);
        s = cycle(s, line_nbr, '-') + 1;
        s = cycle(s, line_nbr, ',') + 1;
        // while (*s != '\n') {   //x_printchar(*s);
        //     digit = mx_atoi(s);
        //     if (digit < 0 || (!(mx_isdigit((int)(*s)))))
        //         mx_error_invalid_line(line_nbr);
        //     s++;
        // }
        s = d_cycle(s, line_nbr) + 1;
        s++;
        line_nbr += 1;
    }
    // printf("%d\n", line_nbr);
    mx_printstr("\x1b[33mRESULT OF MX_CHECK_LINE\033[0m \n");
}

int mx_check_line(const char *file) {
    char *str;
    int fl;
    int line_nbr = 1;
    int n;
    int end;

    str = mx_file_to_str(file);
    end = mx_strlen(str);
    n = mx_get_char_index(str, '\n');
    // fl = check_digit(str, n);
    fl = mx_check_digit(str, n, line_nbr);
    if (fl == 0 || fl < 0) {
        mx_printstr("\x1b[33mRESULT OF MX_CHECK_FIRST\033[0m \n");
        mx_error_invalid_line(line_nbr);
    }
    check_next(str, line_nbr);
    if ((str[end] == '\0') && (str[end - 1] != '\n'))
        mx_error_invalid_line(line_nbr);
    free(str);
    mx_printstr("\x1b[32mOK FOR MX_CHECK_LINE\033[0m \n");
    return 0;
}
