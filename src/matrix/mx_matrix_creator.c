#include "pathfinder.h"

void mx_matrix_creator(t_parse *parse, t_matrix *mx) {
    int col = 0;
    int row = 0;

    mx->adj_table = (long **)malloc(sizeof(long *) * parse->islands_num);
    for (int h = 0; h < parse->islands_num; h++)
        mx->adj_table[h] = (long *)malloc(sizeof(long) * parse->islands_num);

    for (col = 0; col < parse->islands_num; col++ && row++)
        for (row = 0; row < parse->islands_num; row++) {
            mx->adj_table[col][row] = INT_MAX;
            if (col == row)
                mx->adj_table[col][row] = 0;
        }
}
