#include "pathfinder.h"

void mx_output_generating(f_parse *parse, t_matrix *matrix) {
    int i = 0;
    int j = 0;

    for (i = 0; i < parse->islands_num; i++) {
        for ( j = i + 1; j < parse->islands_num; j++) {
            mx_output_boundary();
            if (i != j) {
                mx_output_path(parse, i, j);
                mx_output_distance(matrix, i, j);
            }
            mx_output_boundary();
        }
    }
}
