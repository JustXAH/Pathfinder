#include "pathfinder.h"

void mx_output_distance(t_matrix *mx) {
    int distance_sum = 0;

    mx_printstr("Distance: ");
    for (int i = 1; i < mx->waypoints; i++) {
        mx_printint((int) mx->primary_table[mx->way[i]][mx->way[i + 1]]);
        distance_sum += (int) mx->primary_table[mx->way[i]][mx->way[i + 1]];
        if (i < mx->waypoints - 1)
            mx_printstr(" + ");
        else if (i != 1) {
            mx_printstr(" = ");
            mx_printint(distance_sum);
        }
    }
    mx_printstr("\n");
}
