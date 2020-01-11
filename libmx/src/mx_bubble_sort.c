#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int count = 0;
    char *temp;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size;  j++) {
            if (mx_strcmp(arr[i], arr[j]) > 0) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                count++;
            }
        }
    }
    return count;
}

