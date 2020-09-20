#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *back_list = mx_create_node(data);
    t_list *buffer = *list;

    if (*list == NULL)
        *list = back_list;
    else {
        while (buffer->next != NULL)
            buffer = buffer->next;
        buffer->next = back_list;
    }
}
