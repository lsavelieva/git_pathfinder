#include "../inc/pathfinder.h"

int main(int argc, char **argv) {
    char **arr = NULL;
    char *string = NULL;
    int isl_count;

    if(argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        return 0;
    }
    if (mx_err_handling(argv[1]) < 0)
        return 0;
    string = mx_file_content(argv[1]);
    mx_check_line(string);
    isl_count = mx_first_line(string);
    mx_printstr("=== i am valid :) ===\n=== go to check_unique_island! ===\n");

    arr = mx_get_strarr(string, isl_count);
    mx_print_strarr(arr, " ; ");
    // int f = mx_get_arr_size(arr); printf("%d\n", f);



    // char s[20] = "Greenland-Bananal,8";
    // char delim[10] = "-,";
    // int size = mx_pf_count_word(s, delim);
    // printf("size from strtok > %d\n", size);
    // printf("arr[0] > %s\n", arr[0]);
    // mx_printint(size);mx_printchar('\n');
    mx_strdel(arr);
    mx_printstr("=== i am full check valid :) ===\n=== go to work? ===\n");


    system("leaks -q pathfinder");
    return 0;
}
