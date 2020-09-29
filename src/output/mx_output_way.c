#include "pathfinder.h"

void mx_output_way(t_parse *parse, t_path_output *out) {
    mx_printstr("Route: ");
    for (int i = 1; i <= out->waypoints; i++) {
        mx_printstr(parse->islands_save[out->way[i]]);
        if (i < out->waypoints)
            mx_printstr(" -> ");
        else
            mx_printstr("\n");
    }
}
