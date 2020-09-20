#pragma once

#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

typedef struct file_parse {
    char *file_content;
    char **file_line;
    char *temp;
    char **temp_hyphen;
    char **temp_comma;

}              f_parse;

/*
 * Error handling
 */
void mx_error_handling(int argc, char **argv);
void mx_error_num_arguments(int argc);
void mx_error_file_exist(char *file);
void mx_error_file_empty(char *file);
void mx_error_first_line(char **str, int *line);
void mx_error_line_validation(char **str, int *line);

/*
 * Matrix and Parsing
 */
void mx_structure_initialization(f_parse *parse);
t_list *mx_parse(f_parse *parse, char *file_name);
void mx_create_matrix(f_parse *parse);

