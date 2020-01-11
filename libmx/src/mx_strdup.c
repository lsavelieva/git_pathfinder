#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
    int lenght;
    char *new;

    if (!str)
        return NULL;
    lenght = mx_strlen(str);
    new = mx_strnew(lenght);
    new = mx_strcpy(new, str);
    return new;
}

