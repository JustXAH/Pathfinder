#include "pathfinder.h"

void mx_error_number_of_islands_validation(f_parse *parse,
                                           int unique_islands_num, int line) {
    if (parse->islands_num != unique_islands_num) {
        if (line > 2)
            mx_error_free_memory(&parse);
        mx_printerr("error: invalid number of islands\n");
        system("leaks -q pathfinder");
        exit(1);
    }
}
