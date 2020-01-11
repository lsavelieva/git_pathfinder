#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    t_list *node = NULL;
    int count = 0;

    if (!list)
        return count;
    node = list;
    while (node) {
        count++;
        node = node->next;
    }
    return count;
}
