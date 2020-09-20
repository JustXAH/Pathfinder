#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *buf = (unsigned char *)s + mx_super_strlen(s);

    for ( ; n > 0; n--, buf--)
        if (*buf == c)
            return buf;
    return NULL;
}
