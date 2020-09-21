#include "pathfinder.h"

int main(int argc, char *argv[]) {
    f_parse *parse = (f_parse *)malloc(sizeof(f_parse));
    t_list *main_node;

    mx_structure_initialization(parse);
    mx_error_handling(argc, argv);
    main_node = mx_parse(parse, argv[1]);

//    printf("File content:\n%s\n", parse->file_content);
//    while (main_node->next) {
//        printf("\tMain_node->data is |%s|\n", (char *)main_node->data);
//        main_node = main_node->next;
//    }

//    free((char *)parse->file_content);

//    t_list *buffer = main_node;
//    for (int i = 0; buffer; i++) {
//        char *buf = (char *)buffer->data;
//        mx_printstr("\""); mx_printstr(buf); mx_printstr("\""); mx_printstr(" ");
//        buffer = buffer->next;
//    }
    while (main_node) {
        free(main_node->data);
        mx_pop_front(&main_node);
    }
//    for (int j = 0; main_node; j++) {
//        char *buff = (char *) main_node->data;
//        mx_printstr("\"");
//        mx_printstr(buff);
//        mx_printstr("\"");
//        mx_printstr(" ");
//        main_node = main_node->next;
//    }
    free(parse);
    free(main_node);
//    free(&main_node);
    system("leaks -q pathfinder");
    return 0;
}
