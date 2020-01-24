#include "../inc/pathfinder.h"

int mx_file_size(const char *file) {
    int fd;
    char buf[1];
    int res = 0;

    fd = open(file, O_RDWR);
    if (fd < 0)
        return -1;
    while (read(fd, buf, 1))
        res++;
    if (close(fd) < 0)
        return -1;
    return res;
}

/* function that return sum of unique islands from first line of file*/
int mx_first_line(char *tempstr) {
    // char *tempstr = mx_file_to_str(file);
    char *ps;
    size_t n;
    int isl_count;

    n = mx_get_char_index(tempstr, '\n');
    ps = mx_strndup(tempstr, n);
    isl_count = mx_atoi(ps);
    // mx_strdel(&tempstr);
    return isl_count;
}

char *mx_file_content(const char *file) {
    char *s = mx_file_to_str(file);

    return s;
}
