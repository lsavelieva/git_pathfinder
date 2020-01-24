#include "../inc/pathfinder.h"

void mx_del_intarr(int **arr, int size){
    int i = -1;

    while (++i < size) {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
}
