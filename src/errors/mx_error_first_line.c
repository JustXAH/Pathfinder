#include "pathfinder.h"

void mx_error_first_line(char **str, int *line) {
    int i = 0;

    if ((*str)[0] == '\n') {
        mx_printerr("error: line 1 is not valid\n");
        free((*str));
        exit(1);
    }
    for (; (*str)[i] != '\n' && (*str)[i] != '\0'; i++) {
        if (mx_isdigit((*str)[i]) != 1) {
            mx_printerr("error: line 1 is not valid\n");
            free((*str));
            exit(1);
        }
    }
    (*str) += i + 1;
    *line += 1;
}
