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
}              t_parse;

typedef struct the_matrix {
    long int **adj_table;
    long int **primary_table;
    int *way;
    int waypoints;
}              t_matrix;

/*
 * Initialization
 */
void mx_structure_initialization(t_parse *parse, t_matrix *mx);

/*
 * Error handling
 */
void mx_error_handling(int argc, char **argv, t_parse *parse);
void mx_error_num_arguments(int argc);
void mx_error_file_exist(char *file);
void mx_error_file_empty(char *file);
void mx_error_first_line(char **str, int *line);
void mx_error_line_validation(char **str, int *line);
void mx_error_output_line_invalid(int line);
void mx_error_parsing(t_parse *parse); //AUDITOR!!!
void mx_error_free_memory(t_parse **parse);
void mx_error_number_of_islands_validation(t_parse *parse,
                                           int unique_islands_num, int line);
void mx_error_bridge_duplicate(t_parse *parse, int len);
void mx_error_value_sum_validation(t_parse *parse, int size);

/*
 * Matrix and Parsing
 */
void mx_matrix_creator(t_parse *parse, t_matrix *mx);
void mx_matrix_filling(t_parse *parse, t_matrix *mx);
void mx_primary_path_matrix(t_parse *parse, t_matrix *mx);

/*
 * Algorithm
 */
void mx_floyd_warshall_algorithm(t_parse *parse, t_matrix *mx);

/*
 * Output
 */
void mx_output_generating(t_parse *parse, t_matrix *mx, int i, int j);
void mx_output_recursive_algorithm(t_parse *parse, t_matrix *mx);
void mx_output_boundary(void);
void mx_output_path(t_parse *parse, t_matrix *mx);
void mx_output_way(t_parse *parse, t_matrix *mx);
void mx_output_distance(t_matrix *mx);
