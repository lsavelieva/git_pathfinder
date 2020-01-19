#include "../inc/pathfinder.h"

int mx_pf_count_word(char *s, const char *delim) {
    char *p;
    int counter = 0;

    if (!s)
        return -1;
    p = mx_strtok(s, delim);
    while (p != NULL) {
        counter++;
        p = mx_strtok(NULL, delim);
    }
    free(p);
    return counter;
}
