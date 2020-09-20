#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src,
                 int c, size_t n) {
    unsigned char *dst1 = (unsigned char *)dst;
    unsigned char *src1 = (unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        dst1[i] = src1[i];
        if (src1[i] == c)
            return dst1 + (i + 1);
    }
    return NULL;
}
