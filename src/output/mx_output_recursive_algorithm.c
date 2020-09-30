#include "pathfinder.h"

static bool shortest_path_check(t_matrix *mx, int isl_n) {
    int i = mx->way[mx->waypoints];
    int j = mx->way[0];

    if (i != isl_n) {
        if (mx->primary_table[i][isl_n] ==
            mx->adj_table[j][i] - mx->adj_table[j][isl_n])
            return 1;
    }
    return 0;
}

void mx_output_recursive_algorithm(t_parse *parse, t_matrix *mx) {
    if (mx->way[mx->waypoints] == mx->way[0]) {
        mx_output_boundary();
        mx_output_path(parse, mx);
        mx_output_way(parse, mx);
        mx_output_distance(mx);
        mx_output_boundary();
    }
    else {
        for (int k = 0; k < parse->islands_num; k++)
            if (shortest_path_check(mx, k)) {
                if (mx->waypoints < parse->islands_num) {
                    mx->waypoints++;
                    mx->way[mx->waypoints] = k;
                }
                mx_output_recursive_algorithm(parse, mx);
                if (mx->waypoints > 1)
                    mx->waypoints--;
            }
    }
}
