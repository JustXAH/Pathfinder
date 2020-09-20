#include "pathfinder.h"

static void output_line_invalid(int line) {
    char *line_number = mx_itoa(line);

    mx_printerr("error: line ");
    mx_printerr(line_number);
    mx_printerr(" is not valid\n");
    free(line_number);
    exit(1);
}

void mx_error_line_validation(char **str, int *line) {
    int i = 0;

    if ((**str) != '\0') {
        if ((*str)[i] == '\n')
            output_line_invalid((*line));
        for (i = 0; (*str)[i] != '-'; i++)
            if (!mx_isalpha((*str)[i]))
                output_line_invalid((*line));
        for (i += 1; (*str)[i] != ','; i++)
            if (!mx_isalpha((*str)[i]))
                output_line_invalid((*line));
        for (i += 1; (*str)[i] != '\n'; i++)
            if (!mx_isdigit((*str)[i]))
                output_line_invalid((*line));
        (*line) += 1;
        (*str) += i + 1;
        mx_error_line_validation(&(*str), &(*line));
    }
}
