#include "pathfinder.h"
//
//static void output_line_invalid(int line) {
//    char *line_number = mx_itoa(line);
//
//    mx_printerr("error: line ");
//    mx_printerr(line_number);
//    mx_printerr(" is not valid\n");
//    free(line_number);
//    exit(1);
//}

static void islands_and_value_exist_validation(char *str, int line) {

    for (int j = 0; str[j] != '\n'; j++) {
        if (str[j] == '-' && !mx_isalpha(str[j - 1]))
            mx_error_output_line_invalid(line);
        if (str[j] == '-' && !mx_isalpha(str[j + 1]))
            mx_error_output_line_invalid(line);
        if (str[j] == ',' && !mx_isdigit(str[j + 1]))
                mx_error_output_line_invalid(line);
    }
}

void mx_error_line_validation(char **str, int *line) {
    int i = 0;

    if ((**str) != '\0') {
        if ((*str)[i] == '\n')
            mx_error_output_line_invalid((*line));
        for (i = 0; (*str)[i] != '-'; i++)
            if (!mx_isalpha((*str)[i]))
                mx_error_output_line_invalid((*line));
        for (i += 1; (*str)[i] != ','; i++)
            if (!mx_isalpha((*str)[i]))
                mx_error_output_line_invalid((*line));
        for (i += 1; (*str)[i] != '\n'; i++) {
            if (!mx_isdigit((*str)[i]))
                mx_error_output_line_invalid((*line));
        }
        islands_and_value_exist_validation((*str), (*line));
        (*line) += 1;
        (*str) += i + 1;
        mx_error_line_validation(&(*str), &(*line));
    }
}
