#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    const char *buffer = str;

    if (str == NULL || sub == NULL)
        return -1;
    if (mx_strlen(str) == 0 || mx_strlen(sub) == 0)
        return 0;
    while ((buffer = mx_strstr(buffer, sub)) != 0) {
        buffer++;
        count++;
    }
    return count;
}
