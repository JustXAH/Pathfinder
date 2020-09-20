#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long nbr = 0;
    unsigned long dec = 1;

    if (!hex)
        return 0;
    for (int i = 0;hex[i + 1]; i++)
        dec *= 16;
    for (int j = 0; hex[j]; j++) {
        if (hex[j] >= 48 && hex[j] <= 57)
            nbr += (hex[j] - 48) * dec;
        else if (hex[j] >= 65 && hex[j] <= 70)
            nbr += (hex[j] - 55) * dec;
        else if (hex[j] >= 97 && hex[j] <= 102)
                nbr += (hex[j] - 87) * dec;
        dec /= 16;
    }
    return nbr;
}
