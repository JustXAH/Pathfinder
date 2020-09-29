#include "pathfinder.h"

void mx_output_path(t_parse *parse, t_path_output *out) {
    mx_printstr("Path: ");
    mx_printstr(parse->islands_save[out->way[1]]);
    mx_printstr(" -> ");
    mx_printstr(parse->islands_save[out->way[out->waypoints]]);
    mx_printstr("\n");
}
