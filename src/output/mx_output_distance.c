#include "pathfinder.h"

void mx_output_distance(t_matrix *mx, t_path_output *out) {
    int distance_sum = 0;

    mx_printstr("Distance: ");
    for (int i = 1; i < out->waypoints; i++) {
        mx_printint((int) mx->primary_table[out->way[i]][out->way[i + 1]]);
        distance_sum += (int) mx->primary_table[out->way[i]][out->way[i + 1]];
        if (i < out->waypoints - 1)
            mx_printstr(" + ");
        else if (i != 1) {
            mx_printstr(" = ");
            mx_printint(distance_sum);
        }
    }
    mx_printstr("\n");
}
