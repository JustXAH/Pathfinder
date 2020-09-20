#include "libmx.h"

void mx_str_reverse(char *s) {
    int i = 0;
    int len = mx_super_strlen(s) - 1;

    if (s) {
        while (i < len) {
            mx_swap_char(&s[i], &s[len]);
            i++;
            len--;
        }
    }
}
