#include "pathfinder.h"

void mx_error_output_line_invalid(int line) {
    char *line_number = mx_itoa(line);

    mx_printerr("error: line ");
    mx_printerr(line_number);
    mx_printerr(" is not valid\n");
    free(line_number);
    system("leaks -q pathfinder");
    exit(1);
}
