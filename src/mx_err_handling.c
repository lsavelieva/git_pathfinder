#include "../inc/pathfinder.h"

int mx_err_handling(const char *file) {
    int temp;
    int size;
    char *content;

    temp = open(file, O_RDONLY);
    if (temp < 0) {
        mx_printerr("error: file [filename] does not exist\n");
        return -1;
    }
    size = mx_file_size(file);
    content = mx_file_to_str(file);
    if (size == 0) {
       mx_printerr("error: file [filename] is empty\n");
       return -1;
    }
    free(content);
    if (size > 0)
        mx_printstr("\x1b[32mOK FOR MX_ERR_HANDLING\033[0m \n");
    if (close(temp) < 0)
        return -1;
    return 0;
}

void mx_printerr(const char *s) {
    write(2, s, mx_strlen(s));
}

void mx_error_invalid_line(int line) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(line));
    mx_printerr(" is not valid\n");
    exit (-1);
}

void mx_error_invalid_number(){
    mx_printerr("error: invalid number of islands\n");
    exit(-1);
}

void mx_error_filename(){
    mx_printerr("usage: ./pathfinder [filename]\n");
    exit(-1);
}
