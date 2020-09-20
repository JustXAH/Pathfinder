#include "libmx.h"

static int line_len(unsigned long tmp_nbr, int l) {
    while (tmp_nbr > 0) {
        tmp_nbr /= 16;
        l++;
    }
    return l;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    int len = 0;
    int temp = 0;
    char *hex_s = NULL;

    if (nbr == 0) {
        hex_s = mx_strnew(1);
        hex_s[0] = '0';
        return hex_s;
    }
    len = line_len(nbr, len);
    hex_s = mx_strnew(len);
    for(int i = len - 1; i >= 0; i--) {
        temp = nbr % 16;
        nbr /= 16;
        if (temp < 10)
            hex_s[i] = temp + 48;
        else
            hex_s[i] = temp + 87;
    }
    return hex_s;
}
