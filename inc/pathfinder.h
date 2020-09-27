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
    int bridge_num;
}              f_parse;

typedef struct the_matrix {
    long int **table;
}              t_matrix;

/*
 * Initialization
 */
void mx_structure_initialization(f_parse *parse, t_matrix *matrix);

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
void mx_matrix_creator(f_parse *parse, t_matrix *matrix);
void mx_matrix_filling(f_parse *parse, t_matrix *matrix);

/*
 * Algorithm
 */
void mx_floyd_warshall_algorithm(f_parse *parse, t_matrix *matrix);

/*
 * Output
 */
void mx_output_generating(f_parse *parse, t_matrix *matrix);
void mx_output_boundary(void);
void mx_output_path(f_parse *parse, int f_isl, int s_isl);
void mx_output_route(f_parse *parse, t_matrix *matrix, int f_isl, int s_isl);
void mx_output_distance(t_matrix *matrix, int col, int row);
