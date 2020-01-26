#include "../inc/pathfinder.h"

// static int mx_min(int a, int b) {
//     int min;

//     min = (a < b) ? a : b;
//     return min;
// }
// static void get_short_path(i, j){
//     int c = u;

//     while (c != j) {
//         mx_printint(c);
//         c = vertix[c][j];
//     }
//     mx_printint(j);
// }

void mx_floyd_algo(int **mad, int size){
    // int **dist = (int**)malloc(size * sizeof(int*));
    int i; int j;
    // int **dist = mad;
    // int **vertix = (int**)malloc(size * sizeof(int*));

    // for (i = 0; i < size; i++) {
    //     vertix[i] = (int*)malloc(size * sizeof(int));
    // }
    for (int k = 0; k < size; ++k) {
        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                // dist[i][j] = mx_min (dist[i][j], dist[i][k] + dist[k][j]);
                // if (dist[i][k] + dist[k][j] < dist[i][j]) {
                //     dist[i][j] = dist[i][k] + dist[k][j];
                //     vertix[i][j] = vertix[i][k];
                // }
                if (mad[i][k] + mad[k][j] < mad[i][j])
                    mad[i][j] = mad[i][k] + mad[k][j];
            }
        }
    }//mx_print_intarr(vertix, size);
    // get_short_path(i, j);
}

// отсюда отправить в output dist + vertix ?
