#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *last = *list;
    t_list *node = mx_create_node(data);

    if (last == NULL)
        *list = node;
    else {
        while (last->next != NULL)
            last = last->next;
        last->next = node;
    }
}

