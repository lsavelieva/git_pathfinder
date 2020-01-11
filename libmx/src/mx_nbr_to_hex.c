#include "../inc/libmx.h"

static int length(unsigned long nbr) {
    int j = 0;

    while (nbr != 0) {
        j++;
        nbr = nbr / 16;
    }
    return j;
}

static char intochar(unsigned long n) {
    char symb;

    if (n >= 0 && n <= 9)
        return symb = n + '0';
    else if (n > 9 && n < 16)
        return symb = n + 39 + '0';
    return -1;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    int len = length(nbr);
    unsigned long dec;
    char *hex = mx_strnew(len);
    char *res = mx_strnew(len);
    int i = 0;

    while (nbr != 0) {
        dec = nbr - 16 * (nbr / 16);
        hex[i] = intochar(dec);
        nbr = nbr / 16;
        i++;
    }
    for (i = 0; i < len; i++) {
        res[i] = hex[len - i - 1];
    } 
    free(hex);
    free(res);
    return res;
}

