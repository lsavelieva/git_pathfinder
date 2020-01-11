#include "../inc/libmx.h"

static int file_size(const char *file) {
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

char *mx_file_to_str(const char *file) {
    int fd;
    char buf[1];
    char *new;
    int size = 0;

    fd = open(file, O_RDWR);
    if (fd < 0)
        return NULL;
    size = file_size(file);
    new = mx_strnew(size);
    for (int i = 0; read(fd, buf, 1); i++)
        new[i] = *buf;
    if (close(fd) < 0)
        return NULL;
    return new;
}

