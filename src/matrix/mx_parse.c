#include "pathfinder.h"

t_list *mx_parse(f_parse *parse, char *file_name) {
    t_list *new_node = NULL;
    char *file_content = mx_file_to_str(file_name);

    parse->file_line = mx_strsplit(file_content, '\n');
    for (int i = 1; parse->file_line[i] != NULL; i++) {
        parse->temp_hyphen = mx_strsplit(parse->file_line[i], '-');
//        printf("Temp_hyphen[0] is |%s|\n\n", parse->temp_hyphen[0]);
        parse->temp = mx_strdup(parse->temp_hyphen[0]);
//        printf("Temp is |%s|\n\n", parse->temp);
        mx_push_back(&new_node, parse->temp);
        mx_strdel(&parse->temp);

//        printf("Temp_hyphen[1] is |%s|\n\n", parse->temp_hyphen[1]);
        parse->temp_comma = mx_strsplit(parse->temp_hyphen[1], ',');
//        printf("Temp_comma[0] is |%s|\n\n", parse->temp_comma[0]);
        parse->temp = mx_strdup(parse->temp_comma[0]);
//        printf("Temp is |%s|\n\n", parse->temp);
        mx_push_back(&new_node, parse->temp);
        mx_strdel(&parse->temp);
    }

//    while (new_node->next != NULL) {
//        printf("\tnew_node->data is |%s|\n", (char *)new_node->data);
//        new_node = new_node->next;
//    }
//    mx_printstr("========================================\n");

    mx_del_strarr(&parse->temp_hyphen);
    mx_del_strarr(&parse->temp_comma);

    free(file_content);
    return new_node;
}
