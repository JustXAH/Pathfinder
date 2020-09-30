#include "pathfinder.h"

void mx_output_path(t_parse *parse, t_matrix *mx) {
    mx_printstr("Path: ");
    mx_printstr(parse->islands_save[mx->way[1]]);
    mx_printstr(" -> ");
    mx_printstr(parse->islands_save[mx->way[mx->waypoints]]);
    mx_printstr("\n");
}
