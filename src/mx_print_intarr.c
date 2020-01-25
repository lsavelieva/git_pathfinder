#include "../inc/pathfinder.h"

void mx_print_intarr(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mx_printint(arr[i][j]);
            mx_printstr("\t\t\t");
        }
    mx_printchar('\n');
    }
}
