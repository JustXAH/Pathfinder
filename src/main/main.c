#include "pathfinder.h"

int main(int argc, char *argv[]) {
    f_parse *parse = (f_parse *)malloc(sizeof(f_parse));
    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));

    mx_structure_initialization(parse, matrix);
    mx_error_handling(argc, argv, parse);
    mx_matrix_creator(parse, matrix);
    mx_matrix_filling(parse, matrix);



//    for (int j = 0; parse->islands_save[j] != NULL; j++)
//        printf("    |%s|\t  ", parse->islands_save[j]);
//
//    printf("\n");
//    for (int i = 0; i < parse->islands_num; i++) {
//        printf("\n");
//        for (int j = 0; j < parse->islands_num; j++)
//            printf("\t|%ld|\t", matrix->table[i][j]);
//    }
//    printf("\n\n\n");



//    for (int j = 0; parse->islands_save[j] != NULL; j++)
//        printf("    |%s|\t  ", parse->islands_save[j]);

    for (int i = 0; i < parse->islands_num; i++) {
        printf("\n");
        printf("|%s|", parse->islands_save[i]);
        for (int j = 0; j < parse->islands_num; j++)
            printf("\t|%ld|\t", matrix->table[i][j]);
    }
    printf("\n\n\n");

    mx_floyd_warshall_algorithm(parse, matrix);

//    for (int j = 0; parse->islands_save[j] != NULL; j++)
//        printf("    |%s|\t  ", parse->islands_save[j]);

    for (int i = 0; i < parse->islands_num; i++) {
        printf("\n");
        printf("|%s|", parse->islands_save[i]);
        for (int j = 0; j < parse->islands_num; j++)
            printf("\t|%ld|\t", matrix->table[i][j]);
    }
    printf("\n\n\n");
//    Checking save elements from file (bridges, islands and bridges value)
//    for (int i = 0; parse->e_bridge_save[i] != NULL; i++) {
//        printf("Bridge #|%d| is |%s|\n", i, parse->e_bridge_save[i]);
//        printf("Bridge value is |%lld|\n\n", parse->bridge_value[i]);
//    }
//    for (int j = 0; parse->islands_save[j] != NULL; j++)
//        printf("Unique island #|%d| is |%s|\n", j, parse->islands_save[j]);
//
//    printf("\n");




//    main_node = mx_parse(parse, argv[1]);

//    printf("File content:\n%s\n", parse->file_content);
//    while (main_node->next) {
//        printf("\tMain_node->data is |%s|\n", (char *)main_node->data);
//        main_node = main_node->next;
//    }

//    free((char *)parse->file_content);

//    t_list *buffer = main_node;
//    for (int i = 0; buffer; i++) {
//        char *buf = (char *)buffer->data;
//        printf("Unique island #|%d| is |%s|\n", i + 1, buf);
//        buffer = buffer->next;
//    }
//    while (main_node) {
//        free(main_node->data);
//        mx_pop_front(&main_node);
//    }
//    for (int j = 0; main_node; j++) {
//        char *buff = (char *) main_node->data;
//        mx_printstr("\"");
//        mx_printstr(buff);
//        mx_printstr("\"");
//        mx_printstr(" ");
//        main_node = main_node->next;
//    }
//    free(parse->temp);

    for (int h = 0; h < parse->islands_num; h++)
        free(matrix->table[h]);
    free(matrix->table);
    free(matrix);
    mx_del_strarr(&parse->e_bridge_save);
    mx_del_strarr(&parse->islands_save);
    free(parse->bridge_value);
    free(parse->file_content);
    free(parse);


    system("leaks -q pathfinder");
    return 0;
}
