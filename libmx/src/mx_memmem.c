#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little,
                size_t little_len) {
    unsigned char *big_byte = (unsigned char *)big;
    unsigned char *little_byte = (unsigned char *)little;

    if (big_len >= little_len && (little_len && big_len) != 0)
        for ( ; *big_byte; big_byte++)
            if (*big_byte == *little_byte
                && !mx_memcmp(big_byte, little_byte, little_len))
                    return big_byte;
    return NULL;
}
