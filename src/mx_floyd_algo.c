#include "../inc/pathfinder.h"

void mx_floyd_algo(int **mad, int size){
    int i;
    int j;

    for (int k = 0; k < size; ++k) {
        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                if (mad[i][k] + mad[k][j] < mad[i][j])
                    mad[i][j] = mad[i][k] + mad[k][j];
            }
        }
    }
}
