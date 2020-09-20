#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double p_num = 1;

    if (pow != 0) {
        while (pow != 0) {
            p_num *= n;
            pow--;
        }
    }
    return p_num;
}
