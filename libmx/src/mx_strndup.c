#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *dst = NULL;
    size_t len = 0;

    if (s1 == NULL && n == 0) {
        dst = mx_strnew(len);
        return dst;
    }
    dst = mx_strnew(n);
    mx_strncpy(dst, s1, n);
    return dst;
}
