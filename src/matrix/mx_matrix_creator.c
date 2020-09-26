#include "pathfinder.h"

void mx_matrix_creator(f_parse *parse, t_matrix *matrix) {
    int col = 0;
    int row = 0;

    matrix->table = (long **) malloc(sizeof(long *) * parse->islands_num);
    for (int h = 0; h < parse->islands_num; h++)
        matrix->table[h] = (long *) malloc(sizeof(long) * parse->islands_num);

    for (col = 0; col < parse->islands_num; col++ && row++)
        for (row = 0; row < parse->islands_num; row++) {
            matrix->table[col][row] = INT_MAX;
            if (col == row)
                matrix->table[col][row] = 0;
//            matrix->table[col][row] = 101;
        }
}
