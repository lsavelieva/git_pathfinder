#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    char *p;
    size_t o_size;
    void *new = NULL;

    if (size == 0)
        free(ptr);
    if (ptr == NULL)
        return new;
    p = (char*)ptr;
    o_size = malloc_size(ptr);
    new = malloc(size);
    mx_memcpy(new, p, o_size);
    return (char*)new;
    free(new);
}

