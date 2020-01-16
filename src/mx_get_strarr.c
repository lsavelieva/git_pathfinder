#include "../inc/pathfinder.h"

char **mx_get_strarr(const char *file) {
    char *s = mx_file_to_str(file);
    char **arr;

    s = s + mx_get_char_index(s, '\n') + 1;//cut 1 line
    arr = mx_strsplit(s, '\n');//get array of string
    // mx_print_strarr(arr, " > ");
    return arr;
}

int mx_get_arr_size(char **arr) {
    int i;

    for (i = 0; arr[i] != NULL; i++)
        ; printf("%d\n", i);
    return i;
}
