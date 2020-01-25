#include "../inc/pathfinder.h"

/* function to check summary number of unique islands
   and return array of unique islands  */
 static void sum_of_isl(char **arr, int isl_count){
    int count = 0; //real value of unique islands in file
    char *ptr = NULL;

    while (arr[++count]);
    for (int j = 0; j < count; j++) {
        for (int k = j + 1; k < count; k++){
            if (mx_strcmp(arr[j], arr[k]) == 0) {
                ptr = arr[k];
                for (int r = k; r < count; r++)
                    arr[r] = arr[r + 1];
                mx_strdel(&ptr);
                --count;
                k--;
            }
        }
    }
    if (isl_count != count) {
        mx_printstr("\x1b[33mRESULT OF MX_CHECK_UNIQUE_ISLANDS\033[0m \n");
        mx_error_invalid_number();
        } mx_printstr("\x1b[32mOK FOR CHECK_UNIQUE_ISLANDS\033[0m \n");
}

/* function that return only islands */
char **mx_arr_of_isl(char **arr, int count, int isl_count){
    char **isl_arr = malloc(sizeof(char*) * ((count - 1) * 2 + 1));
    int i;
    int j;

    for (i = 0, j = 0; i < (count - 1) * 3; i += 3, j += 2) {
        isl_arr[j] = strdup(arr[i]);
        isl_arr[j + 1] = strdup(arr[i + 1]);
    }
    isl_arr[(count - 1) * 2] = NULL;
    sum_of_isl(isl_arr, isl_count);
    return isl_arr;
}

/* function to only check summary number of unique islands */
//  static void sum_of_isl(char **arr, int isl_count){
//     int count = 0; //value of unique islands in file
//     int k;
//     int j;

//     for (j = 0; arr[j] != NULL; /*j <= sum;*/ j++) {
//         ++count;
//         for (k = 0; k < j; ++k){
//             if (mx_strcmp(arr[j], arr[k]) == 0) {
//                 --count;
//                 break;
//             }
//         }
//     }
//     if (isl_count != count) {
//         mx_printstr("\x1b[33mRESULT OF MX_CHECK_UNIQUE_ISLANDS\033[0m \n");
//         mx_error_invalid_number();
//         } mx_printstr("\x1b[32mOK FOR CHECK_UNIQUE_ISLANDS\033[0m \n");
// }
