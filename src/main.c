#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
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

    // int f = mx_get_arr_size(arr); printf("%d\n", f);

    char s[20] = "Greenland-Bananal,8";
    char delim[10] = "-,";
    int size = mx_pf_count_word(s, delim);
    printf("size from strtok > %d\n", size);
    printf("arr[0] > %s\n", arr[0]);
    char **temp = mx_pf_split(arr[0]);//, delim);
    // mx_print_strarr(temp, " >>> ");
    for (int i = 0; temp[i] != NULL; i++)
        printf("%s > \n", temp[i]);

// mx_printint(size);mx_printchar('\n');
    // mx_strdel(arr);
    mx_printstr("=== i am full check valid :) ===\n=== go to work? ===\n");


    system("leaks -q pathfinder");
    return 0;
}
