#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    t_list *work_node = NULL;
    t_list *prev_node = NULL;

    if (!head || !(*head))
        return;
    work_node = *head;
    while (work_node->next) {
        prev_node = work_node;
        work_node = work_node->next;
    }
    if (prev_node == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        free(work_node->next);
        prev_node->next = NULL;
   }
}
