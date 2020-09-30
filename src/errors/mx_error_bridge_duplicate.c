#include "pathfinder.h"

static void output_bridge_duplicate(t_parse *parse, char **tmp1,
                                    char **tmp2) {
    mx_del_strarr(&tmp1);
    mx_del_strarr(&tmp2);
    mx_error_free_memory(&parse);
    mx_printerr("error: duplicate bridges\n");
    exit(1);
}

void mx_error_bridge_duplicate(t_parse *parse, int len) {
    char **tmp_islands1 = NULL;
    char **tmp_islands2 = NULL;

    if (len > 1) {
        for (int i = 0; i < len - 1; i++) {
            tmp_islands1 = mx_strsplit(parse->e_bridge_save[i], '-');
            for (int j = i + 1; j < len - 1; j++) {
                tmp_islands2 = mx_strsplit(parse->e_bridge_save[j], '-');
                if (!mx_strcmp(parse->e_bridge_save[i],
                               parse->e_bridge_save[j]))
                    output_bridge_duplicate(parse, tmp_islands1, tmp_islands2);
                if (!mx_strcmp(tmp_islands1[0], tmp_islands2[1])
                    && !mx_strcmp(tmp_islands1[1], tmp_islands2[0]))
                    output_bridge_duplicate(parse, tmp_islands1, tmp_islands2);

                mx_del_strarr(&tmp_islands2);
            }
            mx_del_strarr(&tmp_islands1);
        }
    }
}
