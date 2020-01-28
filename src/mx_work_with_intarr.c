#include "../inc/pathfinder.h"

void mx_del_intarr(int **arr, int size){
    int i = -1;

    while (++i < size) {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
}

int **mx_copy_int_arr(int **src, int size) {
    int **arr = NULL;
    int i;
    int j;

    if (src == NULL)
        return NULL;
    arr = (int**)malloc(size * sizeof(int*));
    for (i = 0; i < size; i++) {
        arr[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            arr[i][j] = src[i][j];
        }
    }
    return arr;
}

void mx_print_intarr(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mx_printint(arr[i][j]);
            mx_printstr("\t\t\t");
        }
    mx_printchar('\n');
    }
}
