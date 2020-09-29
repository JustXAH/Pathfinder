#include "pathfinder.h"

static void path_output_initialization(t_path_output *out,t_parse *parse,
                                       int way_beginning, int way_end) {

    out->way = (int *)malloc(sizeof(int) * parse->islands_num);
    for (int i = 0; i < parse->islands_num; i++)
        out->way[i] = 0;

    out->waypoints = 1;
    out->way[0] = way_end;
    out->way[1] = way_beginning;
//    free(out->way);
}

void mx_output_generating(t_parse *parse, t_matrix *mx, int i, int j) {
    t_path_output *out = (t_path_output *)malloc(sizeof(t_path_output));

    path_output_initialization(out, parse, i, j);
    mx_output_recursive_algorithm(parse, mx, out);

//    if (out->way != NULL)
    free(out->way); // CHECK!!!
    free(out);
}
