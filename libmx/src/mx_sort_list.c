#include "../inc/libmx.h"
/*--- Function that sorts the list's contents in ascending order ---
  --- Function cmp returns true if a > b and false in other cases --- */

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    void *tmp;

    if (!lst || !cmp)
        return NULL;
    for (t_list*i = lst; i->next; i = i->next) {
        for (t_list *j = lst; j->next; j = j->next) {
            if (cmp(i->data, j->data)) {
                tmp = i->data;
                i->data = j->data;
                j->next = tmp;
            }
        }
    }
    return lst;
}

