#include "pathfinder.h"

void mx_output_generating(t_parse *parse, t_matrix *mx, int i, int j) {
    int way_beginning = i;
    int way_end = j;

    for (int k = 0; k < parse->islands_num; k++)
        mx->way[k] = 0;

    mx->waypoints = 1;
    mx->way[0] = way_end;
    mx->way[1] = way_beginning;

    mx_output_recursive_algorithm(parse, mx);
}
