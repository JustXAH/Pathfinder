#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int len2 = mx_strlen(needle);
    int ptr = 0;

    while (*haystack != 0) {
        ptr = *haystack;
        if (mx_strncmp(haystack, needle, len2) == 0)
            return mx_strchr(haystack, ptr);
        haystack++;
    }
    return 0;
}
