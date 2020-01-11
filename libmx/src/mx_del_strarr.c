#include "../inc/libmx.h"

void mx_del_strarr(char ***arr) {
    char **tmp = *arr;

    for (int i = 0; tmp[i] != NULL; i++) {
        free(tmp[i]);
        tmp[i] = NULL;
        // mx_strdel(&tmp[i]);
    }
    free(*arr);
    *arr = NULL;
}
