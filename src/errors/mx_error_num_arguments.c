#include "pathfinder.h"

void mx_error_num_arguments(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}
