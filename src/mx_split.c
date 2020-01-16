#include "../inc/pathfinder.h"

static int get_index(char *s, char c1, char c2) {
    int index;

    index = mx_get_char_index(s, c1);
    if (index == -1)
        index = mx_get_char_index(s, c2);
    return index;
}

char mx_split(char *line, char c1, char c2){
    int size = mx_get_arr_size(arr);
    char **element = (char**)malloc((size + 1) * sizeof(char*));
    int i;
}
