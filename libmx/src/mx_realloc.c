#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    size_t len = malloc_size(ptr);
    unsigned char *new_pointer = NULL;

    if ((int)size < 0)
        return NULL;
    if (size != 0 && len > size)
        return ptr;
    new_pointer = malloc(size);
    if (ptr != NULL && size != 0)
        new_pointer = mx_memcpy(new_pointer, ptr, size);
    free(ptr);
    return new_pointer;
}
