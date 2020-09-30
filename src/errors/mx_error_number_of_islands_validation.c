#include "pathfinder.h"

void mx_error_number_of_islands_validation(t_parse *parse,
                                           int unique_islands_num, int line) {
    if (parse->islands_num != unique_islands_num) {
        if (line > 2) {
            mx_del_strarr(&parse->file_line);
            mx_del_strarr(&parse->e_bridge_save);
            free(parse->file_content);
            free(parse->bridge_value);
            free(parse);
        }
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}
