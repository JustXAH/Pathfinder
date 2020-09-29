#include "pathfinder.h"

void mx_error_value_sum_validation(t_parse *parse, int size) {
    long long int value_sum = 0;

    for (int i = 0; i < size; i++) {
        value_sum += parse->bridge_value[i];
        if (value_sum > INT_MAX) {
            mx_error_free_memory(&parse);
            mx_printerr("error: sum of bridges lengths is too big\n");
            system("leaks -q pathfinder");
            exit(1);
        }
    }
}
