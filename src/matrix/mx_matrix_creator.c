#include "pathfinder.h"

void mx_matrix_creator(f_parse *parse, s_matrix *matrix) {
    int col = 0;
    int row = 0;

    matrix->table = (long **) malloc(sizeof(long *) * parse->islands_num);
    for (int k = 0; k < parse->islands_num; k++)
        matrix->table[k] = (long *) malloc(sizeof(long) * parse->islands_num);

    for (col = 0; col < parse->islands_num; col++ && row++)
        for (row = 0; row < parse->islands_num; row++) {
            matrix->table[col][row] = INT_MAX;
        }
}
