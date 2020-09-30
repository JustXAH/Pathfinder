#include "pathfinder.h"

void mx_output_way(t_parse *parse, t_matrix *mx) {
    mx_printstr("Route: ");
    for (int i = 1; i <= mx->waypoints; i++) {
        mx_printstr(parse->islands_save[mx->way[i]]);
        if (i < mx->waypoints)
            mx_printstr(" -> ");
        else
            mx_printstr("\n");
    }
}
