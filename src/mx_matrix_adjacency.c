#include "../inc/pathfinder.h"

static void get_dist(int **mad, char **data, char **uniq, int size) {
    int ind1 = 0;
    int ind2 = 0;

    for (int i = 0; data[i] != NULL; i += 3) {
        for (int j = 0; j < size; j++) {
            ind1 = mx_get_index_uniq(data[i], uniq);
            ind2 = mx_get_index_uniq(data[i + 1], uniq);
            mad[ind1][ind2] = mad[ind2][ind1] = atoi(data[i + 2]);
        }
    }
}

int **mx_matrix_adjacency(char **data, char **uniq, int size) {
    int **mad = (int**)malloc(size * sizeof(int*));
    int i, j;

    for (i = 0; i < size; i++) {
        mad[i] = (int*)malloc(size * sizeof(int));
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == j)
                mad[i][j] = 0;
            else
                mad[i][j] = MX_INF;
        }
    }
    get_dist(mad, data, uniq, size);
    return mad;
}
