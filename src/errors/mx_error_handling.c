#include "pathfinder.h"

void mx_error_handling(int argc, char **argv) {
    int line = 1;
    char *file_content = NULL;
    char *buf = NULL;

    mx_error_num_arguments(argc);
    mx_error_file_exist(argv[1]);
    mx_error_file_empty(argv[1]);
    file_content = mx_file_to_str(argv[1]);
    buf = file_content;
    mx_error_first_line(&file_content, &line);
    mx_error_line_validation(&file_content, &line);
    file_content = buf;
    free(file_content);
}
