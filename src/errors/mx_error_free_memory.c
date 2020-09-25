#include "pathfinder.h"

void mx_error_free_memory(f_parse **parse) {
    mx_del_strarr(&(*parse)->file_line);
    mx_del_strarr(&(*parse)->e_bridge_save);
    mx_del_strarr(&(*parse)->islands_save);
    free((*parse)->file_content);
    free((*parse)->bridge_value);
    free((*parse));
}
