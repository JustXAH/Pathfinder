#include "pathfinder.h"

static void free_memory(t_parse *parse, t_matrix *mx) {
    for (int i = 0; i < parse->islands_num; i++) {
        free(mx->adj_table[i]);
        free(mx->primary_table[i]);
    }
    free(mx->adj_table);
    free(mx->primary_table);
    free(mx->way);
    free(mx);
    mx_del_strarr(&parse->e_bridge_save);
    mx_del_strarr(&parse->islands_save);
    free(parse->bridge_value);
    free(parse);
}

int main(int argc, char *argv[]) {
    t_parse *parse = (t_parse *)malloc(sizeof(t_parse));
    t_matrix *mx = (t_matrix *)malloc(sizeof(t_matrix));

    mx_structure_initialization(parse, mx);
    mx_error_handling(argc, argv, parse);
    mx_matrix_creator(parse, mx);
    mx_matrix_filling(parse, mx);
    mx_primary_path_matrix(parse, mx);
    mx_floyd_warshall_algorithm(parse, mx);

    mx->way = (int *)malloc(sizeof(int) * parse->islands_num);
    for (int i = 0; i < parse->islands_num; i++) {
        for (int j = i + 1; j < parse->islands_num; j++) {
                mx_output_generating(parse, mx, i, j);
        }
    }
    free_memory(parse, mx);
    return 0;
}
