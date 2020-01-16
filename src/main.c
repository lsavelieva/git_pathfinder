#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
    // int temp;
    char **arr = NULL;

    if(argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 0;
    }
    if (mx_err_handling(argv[1]) < 0)
        return 0;
    mx_check_line(argv[1]);
    mx_printstr("=== i am valid :) ===\n=== go to check_unique_island! ===\n");
    // mx_check_unique_island(argv[1]);
    arr = mx_get_strarr(argv[1]);
    
    for (int i = 0; arr[i] != NULL; i++)
        mx_split(arr[i]);

// mx_printint(size);mx_printchar('\n');

    mx_printstr("=== i am full check valid :) ===\n=== go to work? ===\n");


    system("leaks -q pathfinder");
    return 0;
}
