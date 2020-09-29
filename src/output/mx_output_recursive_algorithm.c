#include "pathfinder.h"

static bool shortest_path_check(t_matrix *mx, t_path_output *out, int isl_n) {
    int i = out->way[out->waypoints];
    int j = out->way[0];

    if (i != isl_n) {
        if (mx->primary_table[i][isl_n] ==
            mx->adj_table[j][i] - mx->adj_table[j][isl_n])
            return 1;
    }
    return 0;
}

void mx_output_recursive_algorithm(t_parse *parse, t_matrix *mx,
                                   t_path_output *out) {

    if (out->way[out->waypoints] == out->way[0]) {
        mx_output_boundary();
        mx_output_path(parse, out);
        mx_output_way(parse, out);
        mx_output_distance(mx, out);
        mx_output_boundary();
    }
    else {
        for (int k = 0; k < parse->islands_num; k++)
            if (shortest_path_check(mx, out, k)) {
                if (out->waypoints < parse->islands_num) {
                    out->waypoints++;
                    out->way[out->waypoints] = k;
                }
                mx_output_recursive_algorithm(parse, mx, out);
                if (out->waypoints > 1)
                    out->waypoints--;
            }
    }
}
