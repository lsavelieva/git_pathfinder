#include "../inc/pathfinder.h"

int mx_get_arr_size(char **arr);
char **mx_get_strarr(const char *file);
char **mx_matrix_split(char **arr, int count);

/* function for split file as matrix */
char **mx_matrix_split(char **arr, int count){
    char **res = malloc(sizeof(char*) * ((count - 1) * 3 + 1));

    for(int i = 1, k = 0; i < count; i++){
        size_t def = mx_get_char_index(arr[i], '-');
        size_t coma = mx_get_char_index(arr[i], ',');
        size_t end = mx_get_char_index(arr[i], '\n');
        res[k] = mx_strndup(arr[i], def);
        res[k + 1] = mx_strndup(arr[i] + def + 1, coma - def - 1);
        res[k + 2] = mx_strndup(arr[i] + coma + 1, end - coma - 1);
        k += 3;
    }
    res[(count - 1) * 3] = NULL;
    return res;
}

/* function for move file in array of data */
char **mx_get_strarr(const char *file) {
    char *s = mx_file_to_str(file);
    char **tmp;
    char **arr;
    int isl_count;
    char **arr_uniq;
    // int count;

    tmp = mx_strsplit(s, '\n');//get array of string
    // count = mx_get_arr_size(tmp);//get N of the strings
    isl_count = mx_atoi(tmp[0]);//get M of the unique islands
    arr = mx_matrix_split(tmp, mx_get_arr_size(tmp));//count);//get unique elements

    arr_uniq = mx_arr_of_isl(arr, mx_get_arr_size(tmp), isl_count);
    mx_print_strarr(arr_uniq, " >>> ");

    mx_strdel(tmp);//del array of string
    return arr;
}

int mx_get_arr_size(char **arr) {
    int i;

    for (i = 0; arr[i] != NULL; i++)
        ;
    return i;
}
