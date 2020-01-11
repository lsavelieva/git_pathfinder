#include "../inc/libmx.h"

int mx_sqrt(int x) {
    int min = 1;
    int max;

    if (x < 0)
        return 0;
    if (x == 0 || x == 1)
        return x;
    max = x <= 46340 ? x : 46340;
    while (min <= max) {
        int mid = max + (min - max) / 2;
        if (mid * mid == x)
            return mid;
        if (mid * mid - x < 0)
            min = mid + 1;
        else
            max = mid - 1;
    }
    return 0;
}

