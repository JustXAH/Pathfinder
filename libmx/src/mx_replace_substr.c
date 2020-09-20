#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub,
                        const char *replace) {
    int rep_len = mx_super_strlen(replace);
    int sub_len = mx_super_strlen(sub);
    int str_len = mx_super_strlen(str);
    char *new = NULL;

    if (!str || !sub || !replace)
        return NULL;
    new = mx_strnew(str_len + (rep_len - sub_len) * mx_count_substr(str, sub));
    for (int i = 0; *str != '\0'; i++) {
        if (!mx_strncmp(str, sub, mx_strlen(sub))) {
            mx_strcat(new, replace);
            i += rep_len - 1;
            str += sub_len;
        }
        else
            new[i] = *str++;
    }
    return new;
}
