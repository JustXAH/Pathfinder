#include "pathfinder.h"

void mx_error_handling(int argc, char **argv, t_parse *parse) {
    int line = 1;
    char *buf = NULL;

    mx_error_num_arguments(argc);
    mx_error_file_exist(argv[1]);
    mx_error_file_empty(argv[1]);
    parse->file_content = mx_file_to_str(argv[1]);
    buf = parse->file_content;
    mx_error_first_line(&parse->file_content, &line);
    mx_error_line_validation(&parse->file_content, &line);
    parse->file_content = buf;
    mx_error_parsing(parse);
    free(parse->file_content);
}
