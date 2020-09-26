#include "pathfinder.h"

void mx_floyd_warshall_algorithm(f_parse *parse, t_matrix *matrix) {
    for (int k = 0; k < parse->islands_num; k++) {
        for (int i = 0; i < parse->islands_num; i++) {
            for (int j = 0; j < parse->islands_num; j++) {
                if (matrix->table[i][k] != INT_MAX &&
                    matrix->table[k][j] != INT_MAX &&
                    matrix->table[i][j] >
                    matrix->table[i][k] + matrix->table[k][j]) {
                    matrix->table[i][j] = matrix->table[i][k] + matrix->table[k][j];
                }
            }
        }
    }

}
