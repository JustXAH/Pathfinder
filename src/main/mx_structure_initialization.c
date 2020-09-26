#include "pathfinder.h"

void mx_structure_initialization(f_parse *parse, t_matrix *matrix) {
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
}
