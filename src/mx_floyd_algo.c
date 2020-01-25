#include "../inc/pathfinder.h"

static int mx_min(int a, int b) {
    int min;

    min = (a < b) ? a : b;
    return min;
}

mx_floyd_algo(int **mad, int size){
    int **dist = (int**)malloc(size * sizeof(int*));
    int i;

    for (i = 0; i < size; i++) {
        dist[i] = (int*)malloc(size * sizeof(int));
    }
    for (int k = 0; k < size; ++k) {
        for (i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
