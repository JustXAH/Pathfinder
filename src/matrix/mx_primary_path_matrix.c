#include "pathfinder.h"

void mx_primary_path_matrix(t_parse *parse, t_matrix *mx) {
    int col = 0;
    int row = 0;

    mx->primary_table = (long **)malloc(sizeof(long *) * parse->islands_num);
    for (int i = 0; i < parse->islands_num; i++) {
        mx->primary_table[i] = (long *) malloc(
                sizeof(long) * parse->islands_num);
    }
    for (col = 0; col < parse->islands_num; col++ && row++) {
        for (row = 0; row < parse->islands_num; row++) {
            mx->primary_table[col][row] = mx->adj_table[col][row];
        }
    }
}
