#include "../inc/pathfinder.h"

// static void free_all_arr() {
// }


int main(int argc, char **argv) {
    char **arr = NULL;
    char *string = NULL;
    int isl_count = 0;

    if(argc != 2)
        mx_error_filename();
    if (mx_err_handling(argv[1]) < 0)
        return 0;
    string = mx_file_content(argv[1]);
    mx_check_line(string);
    isl_count = mx_first_line(string);
    mx_printstr("=== i am valid :) ===\n=== go to check unique! ===\n");

    arr = mx_get_strarr(string, isl_count);
    mx_print_strarr(arr, " | ");

    mx_printstr("=== i find matrix adjacency :) ===\n=== go to work with algorythm ===\n");




// ===================================================================
// free all unused arrays
// ===================================================================
    mx_del_strarr(&arr);
    mx_strdel(&string);
    // mx_del_intarr(arr_len, isl_count);

    mx_printstr("=== i clean memory :) end work  ===\n");
    mx_printstr("\x1b[32mOK FOR PATHFINDER\033[0m \n");

    system("leaks -q pathfinder");
    return 0;
}
