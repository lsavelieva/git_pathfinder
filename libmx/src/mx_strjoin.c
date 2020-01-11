#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    char *join;

    if (NULL == s2 && NULL == s1)
        return NULL;
    if (NULL == s2 || NULL == s1) {
        join = !s2 ? mx_strnew(mx_strlen(s1)) : mx_strnew(mx_strlen(s2));
        join = !s2 ? mx_strcpy(join, s1) : mx_strcpy(join, s2);
        return join;
    }
    join = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    join = mx_strcat(join, s1);
    join = mx_strcat(join, s2);
    return join;
}

