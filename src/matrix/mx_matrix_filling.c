#include "pathfinder.h"

static void get_island_index(t_parse *parse, char *tmp_island, int *index) {

    for (int i = 0 ; i < parse->islands_num; i++)
        if (!mx_strcmp(tmp_island, parse->islands_save[i])) {
            (*index) = i;
            return;
        }
}

void mx_matrix_filling(t_parse *parse, t_matrix *mx) {
    int col = 0;
    int row = 0;
    char **tmp_islands = NULL;

    for (int i = 0; i < parse->bridge_num; i++) {
        tmp_islands = mx_strsplit(parse->e_bridge_save[i], '-');
        get_island_index(parse, tmp_islands[0], &col);
        get_island_index(parse, tmp_islands[1], &row);
        mx->adj_table[col][row] = parse->bridge_value[i];
        mx->adj_table[row][col] = parse->bridge_value[i];
        mx_del_strarr(&tmp_islands);
    }
}
