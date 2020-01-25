#include "../inc/pathfinder.h"

int mx_get_index(char *s, char c1, char c2) {
    int index;

    index = mx_get_char_index(s, c1);
    if (index < 0)
        index = mx_get_char_index(s, c2);
    index = index == -1 ? mx_strlen(s) : index;
    return index;
}

int mx_get_index_uniq(char *vertex, char **uniq) {
    for (int i = 0; uniq[i]; i++)
        if (mx_strcmp(uniq[i], vertex) == 0)
            return i;
    return -1;
}
