#include "pathfinder.h"

static void duplicate_islands_name(t_list **islands_node, char *island) {
    t_list *buffer_node = (*islands_node);
    static int i = 0;

    if (buffer_node)
        while(buffer_node) {
            if (!mx_strcmp(buffer_node->data, island))
                return;
            buffer_node = buffer_node->next;
    }
    mx_push_back(islands_node, island);
}

t_list *mx_parse(f_parse *parse, char *file_name) {
    t_list *islands_node = NULL;
    char *file_content = mx_file_to_str(file_name);

    parse->file_line = mx_strsplit(file_content, '\n');
    for (int i = 1; parse->file_line[i] != NULL; i++) {
        parse->temp_hyphen = mx_strsplit(parse->file_line[i], '-');
        parse->temp = mx_strdup(parse->temp_hyphen[0]);
        duplicate_islands_name(&islands_node, parse->temp);
//        mx_push_back(&islands_node, parse->temp);

        parse->temp_comma = mx_strsplit(parse->temp_hyphen[1], ',');
        parse->temp = mx_strdup(parse->temp_comma[0]);
        duplicate_islands_name(&islands_node, parse->temp);
//        mx_push_back(&islands_node, parse->temp);
        mx_del_strarr(&parse->temp_hyphen);
        mx_del_strarr(&parse->temp_comma);
    }
//    while (islands_node) {
//        printf("\tislands_node->data is |%s|\n", (char *)islands_node->data);
//        islands_node = islands_node->next;
//    }
    mx_del_strarr(&parse->file_line);
    free(file_content);
    return islands_node;
}

//t_list *mx_parse(f_parse *parse, char *file_name) {
//    t_list *islands_node = NULL;
//    char *file_content = mx_file_to_str(file_name);
//    char **file_by_line = NULL;
//    char **temp_hyphen = NULL;
//    char **temp_comma = NULL;
//    char *temp = NULL;
//
//    file_by_line = mx_strsplit(file_content, '\n');
//    for (int i = 1; file_by_line[i] != NULL; i++) {
//        temp_hyphen = mx_strsplit(file_by_line[i], '-');
//        temp = mx_strdup(temp_hyphen[0]);
//        printf("Temp 1 is |%s|\n", temp);
//        mx_push_back(&islands_node, temp);
////        free(temp)
////        temp = NULL;
//
//        temp_comma = mx_strsplit(temp_hyphen[1], ',');
//        temp = mx_strdup(temp_comma[0]);
//        printf("Temp 2 is |%s|\n", temp);
//        mx_push_back(&islands_node, temp);
////        free(temp);
//        mx_del_strarr(&temp_hyphen);
//        mx_del_strarr(&temp_comma);
//        temp_hyphen = NULL;
//        temp_comma = NULL;
////        temp = NULL;
//    }
//    for (int i = 0; islands_node; i++) {
//             char *buf = (char *)islands_node->data;
//             mx_printstr("\""); mx_printstr(buf); mx_printstr("\""); mx_printstr(" ");
//             islands_node = islands_node->next;
//         }
//
//    mx_del_strarr(&file_by_line);
////    mx_del_strarr(&parse->temp_hyphen);
////    mx_del_strarr(&parse->temp_comma);
//
//    free(file_content);
//    return islands_node;
//}

//for (int i = 1; main->file->array[i] != NULL; i++) {
//ptr = mx_strsplit(main->file->array[i], '-');
//island1 = mx_graph_island_get(&main->islands, mx_strdup(ptr[0]));
//ptr1 = mx_strdup(ptr[1]);
//mx_del_strarr(&ptr);
//ptr = mx_strsplit(ptr1, ',');
//mx_strdel(&ptr1);
//island2 = mx_graph_island_get(&main->islands, mx_strdup(ptr[0]));
//weight = mx_atoi(ptr[1]);
//mx_del_strarr(&ptr);
//save_islands(island1, island2, weight, i);
//}
//mx_validation_num_islnd(main);



