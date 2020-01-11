#include "../inc/libmx.h"

bool mx_isspace(char s) {
    if ((s >= 9 && s <= 13) || s == 32)
        return true;
    else
        return false;
}

