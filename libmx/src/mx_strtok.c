#include "../inc/libmx.h"

static char check(const char *del, char *p) {
/*first occurrence of a token*/
    while (mx_strchr(del, *p) && *p != 0)
        ++p;
    return *p == 0 ? 0 : *p;
}

char *mx_strtok(char *s, const char *delim) {
    static char *fin = 0;
    char *pos;
    char *start;

    if (s)
        fin = s;
    if (!fin || !(*fin))
        return NULL;
    pos = fin;
    check(delim, pos);
    start = pos;
    while (*pos && (mx_strchr(delim, *pos) == 0))
        ++pos;
    if (*pos == 0) {
        fin = pos;
        return start;
    }
    *pos = 0;
    fin = pos + 1;
    return start;
}
