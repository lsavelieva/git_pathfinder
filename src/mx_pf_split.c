#include "../inc/pathfinder.h"

// static int get_index(char *s, char c1, char c2) {
//     int index;

//     index = mx_get_char_index(s, c1);
//     if (index < 0)
//         index = mx_get_char_index(s, c2);
//     index = index == -1 ? mx_strlen(s) : index;
//     return index;
// }

// int mx_pf_count_word(char *s, const char *delim) {
//   char *p;
//   int counter = 0;

//   if (!s)
//     return -1;
//   p = mx_strtok(s, delim);
//   while (p != NULL) {
//     counter++;
//     p = mx_strtok(NULL, delim);
//   }
//   return counter;
// }

char **mx_pf_split(char *s) {//, const char *delim){
    char delim[5] = "-,";
    int size = mx_pf_count_word(s, delim);
    char **el = (char**)malloc((size + 1) * sizeof(char*));
    // char *p;
    int i = 0;

    el[i] = mx_strtok(s, delim);
    while (el[i] != NULL) {
        i++;
        el[i] = mx_strtok(NULL, delim);
    }
    el[size] = NULL;
    return el;
}
// char **mx_pf_split(char *s, char c1, char c2){
//     int size = mx_pf_count_word(s, "-,");
//     char **el = (char**)malloc((size + 1) * sizeof(char*));
//     int ind;

//     for (int i = 0, j = 0; i < mx_strlen(s); i++) {
//         ind = get_index(s, c1, c2);
//         if (ind)
//             el[j] = mx_strndup(s, ind);
//         s += mx_strlen(el[j]) - 1;
//         i += mx_strlen(el[j]) - 1;
//         j++;
//     s++;
//     }
//     //mx_print_strarr(el, "\t");
//     return el;
// }
