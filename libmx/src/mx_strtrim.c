#include "libmx.h"

char *mx_strtrim(const char *str) {
    char *dst = NULL;
    int len = 0;

    if (NULL == str)
        return NULL;
    while(mx_isspace(*str))
        str++;
    len = mx_strlen(str);
    for (int i = len - 1; mx_isspace(str[i]); i--)
        len--;
    if (len < 0) {
        dst = mx_strnew(0);
        return dst;
    }
    dst = mx_strnew(len);
    dst = mx_strncpy(dst, str, len);
    return dst;
}
