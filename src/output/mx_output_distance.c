#include "pathfinder.h"

void mx_output_distance(t_matrix *matrix, int col, int row) {
    mx_printstr("Distance:  ");
    mx_printint((int)matrix->table[col][row]);
    mx_printstr(" + ");
    mx_printint((int)matrix->table[col][row]);
    mx_printstr(" = ");
    mx_printint((int)matrix->table[col][row]);
    mx_printstr("\n");
}
