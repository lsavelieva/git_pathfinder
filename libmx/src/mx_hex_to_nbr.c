#include "../inc/libmx.h"

static int st_len(const char *hex);
static long long st_pow(int a, int pow);
static unsigned int st_chartoin(char symb);

unsigned long mx_hex_to_nbr(const char *hex) {
    int size;
    unsigned long nbr = 0;

    if (!hex)
        return nbr;
    size = st_len(hex);
    for (int i = 0, j = size - 1; i < size; i++) {
        nbr += st_chartoin(hex[i]) * st_pow(16, j);
	    j--;
    }
    return nbr;
}

static int st_len(const char *hex) {
    int len = 0;

    while (hex[len] != '\0')
        len++;
    return len;
}

static long long st_pow(int a, int pow) {
    if (pow == 0)
        return 1;
    else if (a / 2 == 0)
        return st_pow(a * a, pow / 2);
    else
        return a * st_pow(a, pow - 1);
    return -1;
}

static unsigned int st_chartoin(char symb) {
    if ((symb >= '0') && (symb <= '9'))
        return symb - '0';
    else if ((symb >= 'A') && (symb <= 'F'))
        return symb - 55;
    else if ((symb >= 'a') && (symb <= 'f'))
        return symb - 87;
    return -1;
}

