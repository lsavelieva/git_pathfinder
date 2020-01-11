#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    double res = 1;

    if (pow <= 0)
        return 1;
    for (unsigned int i = 1; i <= pow; i++)
        res *= n;
    return res;
}

