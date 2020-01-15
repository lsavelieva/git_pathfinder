#include "../inc/pathfinder.h"

static char *take_word(char *pl, char c){
    int pp;
    char *word;

    pp = mx_get_char_index(pl, c);
    word = mx_strnew(pp);
    word = mx_strndup(pl, pp);
    return word;
}
// static int **arr_dist(const char *s, int size){
//     char **arr_d = (char**)malloc((size + 1) * sizeof(char*));
//     char *line;//line of file
//     int n;//pointer on the end of line
//     int i = 0;

//     while (*s != '\0'){
//         n = mx_get_char_index(s, '\n');
//         line = mx_strndup(s, n);
//         if (line) {
//             arr[i] = take_word(line, '-');
//             line = line + mx_get_char_index(line, '-') + 1; i += 1;
//             arr[i] = take_word(line, ',');
//             line = line + mx_get_char_index(line, ',') + 1; i += 1;
//             arr[i] = take_word(line, '\0');
//         }
//         s = s + n + 1;
//     }
//     arr[i] = NULL;
//     return arr_d;
// }

static char **arr_of_all(const char *s, int size){
    char **arr = (char**)malloc((size + 1) * sizeof(char*));
    char *line;//line of file
    int n;//pointer on the end of line
    int i = 0;

    while (*s != '\0'){
        n = mx_get_char_index(s, '\n');
        line = mx_strndup(s, n);
        if (line) {
            arr[i] = take_word(line, '-');
            line = line + mx_get_char_index(line, '-') + 1;
            i += 1;
            arr[i] = take_word(line, ',');
            line = line + mx_get_char_index(line, ',') + 1;
            i += 1;
            arr[i] = take_word(line, '\0');
            i += 1;
        }
        s = s + n + 1;
    }
    arr[i] = NULL;
    return arr;
}

static int sum_of_isl(char **arr, int sum){
    int count = 0; //value of unique islands in file
    int k;
    int j;

    for (j = 0; j <= sum; j++) {
        ++count;
        for (k = 0; k < j; ++k){
            if (mx_strcmp(arr[j], arr[k]) == 0) {
                --count;
                break;
            }
        }
    }printf("count --> %d\n", count);
    return count;
}

void mx_check_unique_island(const char *file) {
    char *s = mx_file_to_str(file);
    int sum = mx_check_digit(s, mx_get_char_index(s, '\n'), 1); //value of 1st line
    char **arr = NULL;
    int size = mx_count_words(s, '\n'); printf("size --> %d\n", size);

    s = s + mx_get_char_index(s, '\n') + 1; mx_printstr("arr_of_unique?\n");
    arr = arr_of_all(s, size);
    if (sum != sum_of_isl(arr, sum)) {
        mx_printstr("\x1b[33mRESULT OF MX_CHECK_UNIQUE_ISLANDS\033[0m \n");
        mx_printerr("error: invalid number of islands\n");
        exit(-1);
    }
    mx_printstr("\x1b[32mOK FOR CHECK_UNIQUE_ISLANDS\033[0m \n");
}
