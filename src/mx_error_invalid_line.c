#include "../inc/pathfinder.h"

void mx_error_invalid_line(int line) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(line));
    mx_printerr(" is not valid\n");
    exit (-1);
}
