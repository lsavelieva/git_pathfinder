#include "../inc/pathfinder.h"

int mx_atoi(const char *str) {
    int num = 0;
    int i = 0;
    int sign = 1;

    if ((str[i] == '\t') || (str[i] == ' ') || (str[i] == '\n'))
        i++;
    if ((str[i] == '+') && (str[i + 1] != '-'))
        i++;
    if ((str[i] == '-') && (str[i + 1] != '+')) {
        sign = -1;
        i++;
    }
    while ((str[i] >= 48) && (str[i] <= 57)) {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return (num * sign);
}
