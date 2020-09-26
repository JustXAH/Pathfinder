#include "pathfinder.h"

static void unique_islands_save(f_parse *parse, int *count) {
    int i = 0;

    if ((*count) != 0) {
        for ( ; parse->islands_save[i] != NULL; i++) {
            if (!mx_strcmp(parse->islands_save[i], parse->temp))
                return;
        }
    }
    parse->islands_save[i] = mx_strdup(parse->temp);
    (*count) += 1;
}

void mx_error_parsing(f_parse *parse) {
//    t_list *islands_node = NULL;
    int i = 0;
    int count = 0;


    parse->file_line = mx_strsplit(parse->file_content, '\n');
    parse->islands_num = mx_atoi(parse->file_line[0]);
    for (i = 0; parse->file_line[i + 1] != NULL; i++)
        parse->bridge_num++;
    parse->e_bridge_save = (char **)malloc(sizeof(char *) * parse->bridge_num + 1);
    parse->bridge_value = (long long int *)malloc(sizeof(long long int) * parse->bridge_num);
    parse->islands_save = (char **)malloc(sizeof(char *) * parse->islands_num + 1);
    for (int j = 0; j <= parse->islands_num; j++)
        parse->islands_save[j] = NULL;
    for (i = 1; parse->file_line[i] != NULL; i++) {
        parse->temp_comma = mx_strsplit(parse->file_line[i], ',');
        parse->temp_hyphen = mx_strsplit(parse->temp_comma[0], '-');

        parse->e_bridge_save[i - 1] = mx_strdup(parse->temp_comma[0]);

        if (!mx_strcmp(parse->temp_hyphen[0], parse->temp_hyphen[1])) {
            mx_del_strarr(&parse->temp_hyphen);
            mx_del_strarr(&parse->temp_comma);
            mx_error_free_memory(&parse);
            mx_error_output_line_invalid(i + 1);
        }
        parse->bridge_value[i - 1] = mx_atoi_long(parse->temp_comma[1]);
        parse->temp = mx_strdup(parse->temp_hyphen[0]);
        unique_islands_save(parse, &count);
        free(parse->temp);
//        unique_islands_save(&islands_node, &parse->temp, &count);
        parse->temp = mx_strdup(parse->temp_hyphen[1]);
        unique_islands_save(parse, &count);
//        unique_islands_save(&islands_node, &parse->temp, &count);
        free(parse->temp);
        mx_del_strarr(&parse->temp_hyphen);
        mx_del_strarr(&parse->temp_comma);

    }
    mx_error_number_of_islands_validation(parse, count, parse->bridge_num);
    mx_error_bridge_duplicate(parse, i);
    mx_error_value_sum_validation(parse, parse->bridge_num);

    mx_del_strarr(&parse->file_line);
}


//static void unique_islands_save(t_list **islands_node, char **island,
//                                int *count) {
//    t_list *buffer_node = (*islands_node);
//    static int i = 0;
//
//    if (buffer_node) {
//        while (buffer_node) {
//            if (!mx_strcmp(buffer_node->data, (*island))) {
//                free((*island));
//                return;
//            }
//            buffer_node = buffer_node->next;
//        }
//    }
//    mx_push_back(islands_node, (*island));
//    (*count) += 1;
//}
