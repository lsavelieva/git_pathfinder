#include "../inc/pathfinder.h"

int **mx_matrix_adjacency(char **mdata, int size) {
    int **mad = (int**)malloc(size * size * sizeof(int*));
    int i;
    int j;
    int k = 2;

    for (i = 0; i < size; i++)
        mad[i][i] = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            mad[i][j] = MX_INF;
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            mad[i][j] = mad[j][i] = mx_atoi(mdata[k]);
            k += 3;
        }
    }
    return mad;
}
