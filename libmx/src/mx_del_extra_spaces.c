#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *buf_str = NULL;
    char *new = NULL;
    int j = 0;

    if (NULL == str)
        return NULL;
    buf_str = mx_strnew(mx_strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i]) == 0) {
            buf_str[j] = str[i];
            j++;
        }
        if (mx_isspace(str[i]) == 0 && mx_isspace(str[i + 1]) == 1) {
            buf_str[j] = ' ';
            j++;
        }
    }
    new = mx_strtrim(buf_str);
    mx_strdel(&buf_str);
    return new;
}
