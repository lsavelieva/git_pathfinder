#include "../inc/libmx.h"

static void swap(char **s1, char **s2) {
    char *temp = *s1;

    *s1 = *s2;
    *s2 = temp;
}

int mx_quicksort(char **arr, int left, int right) {
    int res = 0;
    int i, j, pivot;

    if (arr == NULL)
        return -1;
    if (left < right) {
        pivot = left;
        i = left;
        j = right;
        while (i < j) {
            for (;mx_strcmp(arr[i], arr[pivot]) < 0 && i < right; i++);
            for (;mx_strcmp(arr[j], arr[pivot]) > 0; j--);
            if (i < j) {
                res++;
                swap(&arr[i], &arr[j]);
            }
        }
        mx_quicksort(arr, left, j - 1);
        mx_quicksort(arr, j + 1, right);
        }
    return res;
}

