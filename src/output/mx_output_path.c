#include "pathfinder.h"

void mx_output_path(f_parse *parse, int f_isl, int s_isl) {
    mx_printstr("Path: ");
    mx_printstr(parse->islands_save[f_isl]);
    mx_printstr(" -> ");
    mx_printstr(parse->islands_save[s_isl]);
    mx_printstr("\n");
}
