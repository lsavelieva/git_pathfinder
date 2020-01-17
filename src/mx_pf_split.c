#include "../inc/pathfinder.h"

static int get_index(char *s, char c1, char c2) {
    int index;

    index = mx_get_char_index(s, c1);
    if (index == -1)
        index = mx_get_char_index(s, c2);
    return index;
}

char **mx_pf_split(char **arr, char c1, char c2){
    int size = mx_get_arr_size(arr);
    char **el = (char**)malloc((size + 1) * sizeof(char*));
    int ind;

    char *s;
    for (int i = 0; (s = arr[i]) != NULL; i++) {
        for (int j = 0; j < 3; j++) {
            ind = get_index(s, c1, c2);
            if (ind) {
                el[i][j] = *mx_strndup(s, ind);
            }
            s += ind + 1;
            el[i][j] = *mx_strdup(s);
        }
    } //mx_print_strarr(el, "\t");
    return el;
}
