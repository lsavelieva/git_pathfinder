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
