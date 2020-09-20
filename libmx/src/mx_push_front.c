#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *front_list = mx_create_node(data);

    if (*list == NULL)
        *list = front_list;
    else {
        front_list->next = *list;
        *list = front_list;
    }
}
