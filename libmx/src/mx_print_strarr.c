#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    int k = 0;

    if (*arr == NULL || delim == NULL)
        return;
    while (arr[k])
        k++;
    for (int i = 0; i < k; i++) {
        mx_printstr(arr[i]);
        if (i < k - 1)
            mx_printstr(delim);
    }
    mx_printchar('\n');
}

