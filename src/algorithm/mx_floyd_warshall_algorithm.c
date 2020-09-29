#include "pathfinder.h"

void mx_floyd_warshall_algorithm(t_parse *parse, t_matrix *mx) {
    for (int k = 0; k < parse->islands_num; k++) {
        for (int i = 0; i < parse->islands_num; i++) {
            for (int j = 0; j < parse->islands_num; j++) {
                if (mx->adj_table[i][k] != INT_MAX
                    && mx->adj_table[k][j] != INT_MAX
                    && mx->adj_table[i][j] > mx->adj_table[i][k]
                                           + mx->adj_table[k][j]) {
                    mx->adj_table[i][j] = mx->adj_table[i][k]
                                        + mx->adj_table[k][j];
                    mx->adj_table[j][i] = mx->adj_table[i][j];
                }
            }
        }
    }
}
