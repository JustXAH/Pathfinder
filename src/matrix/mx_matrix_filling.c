#include "pathfinder.h"

static void get_island_index(f_parse *parse, char *tmp_island, int *index) {

    for (int i = 0 ; i < parse->islands_num; i++)
        if (!mx_strcmp(tmp_island, parse->islands_save[i])) {
            (*index) = i;
            return;
        }
}

void mx_matrix_filling(f_parse *parse, t_matrix *matrix) {
    int col = 0;
    int row = 0;
    char **tmp_islands = NULL;

    for (int i = 0; i < parse->bridge_num; i++) {
        tmp_islands = mx_strsplit(parse->e_bridge_save[i], '-');
        get_island_index(parse, tmp_islands[0], &col);
        get_island_index(parse, tmp_islands[1], &row);
        matrix->table[col][row] = parse->bridge_value[i];
        matrix->table[row][col] = parse->bridge_value[i];
        mx_del_strarr(&tmp_islands);
    }
}


//for (row = 0; row < parse->islands_num; row++) {
//            tmp_islands1 = mx_strsplit(parse->e_bridge_save[row], '-');
//            for (col = 0; col < parse->islands_num; col++) {
//            tmp_islands2 = mx_strsplit(parse->e_bridge_save[row], '-');
//                if (!mx_strcmp(tmp_islands1[0], parse->islands_save[row])
//                    && !mx_strcmp(tmp_islands1[1], parse->islands_save[col])) {
//                    matrix->table[row][col] = parse->bridge_value[row];
//                    matrix->table[col][row] = parse->bridge_value[row];
//                }
//            matrix->table[col][row] = INT_MAX;
//            mx_del_strarr(&tmp_islands2);
//            }
//            mx_del_strarr(&tmp_islands1);
//        }
//    }
//}
