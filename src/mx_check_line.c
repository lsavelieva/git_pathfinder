#include "../inc/pathfinder.h"

static int check_digit(const char *s) {
    int n = mx_get_char_index(content, '\n');
    char *f_line = mx_strnew(n);
    int res = 0;

    f_line = mx_strncpy(f_line, s, n);
    res = mx_atoi(f_line);
    // if (res == 0 || res < 0) {
    //     mx_printstr("\x1b[33mRESULT OF MX_CHECK_FIRST\033[0m \n");
    //     mx_printerr("error: line 1 is not valid\n");
    // }
    free(f_line);
    return res;
}

static int check_next(const char *s, int line_nbr) {
    int n = mx_get_char_index(s, '\n');
    char *tmp;

    s = s + n;
    mx_printstr("\x1b[33mRESULT OF MX_CHECK_NEXT\033[0m \n");
    while (*s != '\0') {
        mx_printstr(s);
        n = mx_get_char_index(s, '\n');
        tmp = mx_strncpy(tmp, s, n); // cut the line
        check_for_island(tmp, line_nbr, '-');
        tmp = tmp + mx_get_char_index(tmp, '-') + 1;
        check_for_island(tmp, line_nbr, ',');
        tmp = tmp + mx_get_char_index(tmp, ',') + 1;
        if (check_digit(tmp) == 0 || check_digit(tmp) < 0)
            mx_print_invalid_line(line_nbr);
    }
    exit(0);
}

static void check_for_island(const char *line, int line_nbr, char c) {
    int p; // index of delim is '-' or ','
    char *p_word; // pointer to name or length_of_bridge
    int i;

    p = mx_get_char_index(s, c);
    p_word = mx_strnew(p);
    p_word = mx_strncpy(p_word, line, p); // cut the name of 1st island
    for (i = 0; mx_isalpha(tmp[i]) && tmp[i] != '\0'; i++)
        ;
    if (!(mx_isalpha(tmp[i]))) {
        mx_print_invalid_line(int line_nbr);
        exit(0);
    }
    free(p_word);
}

// static void check_for_bridge(const char *line, int line_nbr) {
// }

int mx_check_line(const char *file) {
    char *content;
    int fl;
    char *lptr;
    int line_nbr = 1;

    content = mx_file_to_str(file);
    fl = check_first(content);
    if (fl == 0 || fl < 0) {
        mx_printstr("\x1b[33mRESULT OF MX_CHECK_FIRST\033[0m \n");
        mx_printerr("error: line 1 is not valid\n");
    }
    line_nbr += 1;
    check_next(content, line_nbr);

    free(content);
    mx_printstr("\x1b[32mOK FOR MX_CHECK_LINE\033[0m \n");
    return 0;
}
