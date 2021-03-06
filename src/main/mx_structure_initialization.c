#include "pathfinder.h"

void mx_structure_initialization(t_parse *parse, t_matrix *mx) {
    parse->file_content = NULL;
    parse->file_line = NULL;
    parse->temp = NULL;
    parse->temp_hyphen = NULL;
    parse->temp_comma = NULL;
    parse->e_bridge_save = NULL;
    parse->islands_save = NULL;
    parse->bridge_value = NULL;
    parse->islands_num = 0;
    parse->bridge_num = 0;

    mx->adj_table = NULL;
    mx->primary_table = NULL;
    mx->way = NULL;
    mx->way = 0;
}
