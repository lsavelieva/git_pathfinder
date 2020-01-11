#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (!lineptr || !delim)
        return -2;
    if (buf_size <= 0)
        return -2;
    lineptr = NULL;
    if (EOF && lineptr == NULL)
        return -1;
    if (fd < 0)
        return -2;
    return 0;
}
