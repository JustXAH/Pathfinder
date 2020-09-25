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

#define INT_MAX 2147483647

typedef struct file_parse {
    char *file_content;
    char **file_line;
    char *temp;
    char **temp_hyphen;
    char **temp_comma;
    char **e_bridge_save;
    char **islands_save;
    long long int *bridge_value;
    int islands_num;
}              f_parse;

typedef struct matrix_struct {
    long int **table;
}              s_matrix;

/*
 * Initialization
 */
void mx_structure_initialization(f_parse *parse, s_matrix *matrix);

/*
 * Error handling
 */
void mx_error_handling(int argc, char **argv, f_parse *parse);
void mx_error_num_arguments(int argc);
void mx_error_file_exist(char *file);
void mx_error_file_empty(char *file);
void mx_error_first_line(char **str, int *line);
void mx_error_line_validation(char **str, int *line);
void mx_error_output_line_invalid(int line);
void mx_error_parsing(f_parse *parse); //AUDITOR!!!
void mx_error_free_memory(f_parse **parse);
void mx_error_number_of_islands_validation(f_parse *parse,
                                           int unique_islands_num, int line);
void mx_error_bridge_duplicate(f_parse *parse, int len);
void mx_error_value_sum_validation(f_parse *parse, int size);

/*
 * Matrix and Parsing
 */
void mx_matrix_creator(f_parse *parse, s_matrix *matrix);
//t_list *mx_parse(f_parse *parse, char *file_name);


