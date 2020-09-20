#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    unsigned char *buf = (unsigned char *)s;

    for (size_t i = 0; i < n; i++, buf++)
        if (*buf == c)
            return buf;
    return NULL;
}
