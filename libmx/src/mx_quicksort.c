#include "libmx.h"

static void sorting_static(char **arr, int i, int j) {
    char *buffer = NULL;

    buffer = arr[i];
    arr[i] = arr[j];
    arr[j] = buffer;
}

int mx_quicksort(char **arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = (right + left) / 2;
    int count = 0;

    if (!arr)
        return -1;
    if (left < right) {
        for ( ; mx_strlen(arr[i]) < mx_strlen(arr[pivot]); i++);
        for ( ; mx_strlen(arr[j]) > mx_strlen(arr[pivot]); j--);
        if (i < j && mx_strlen(arr[i]) != mx_strlen(arr[j])) {
            sorting_static(arr, i, j);
            count++;
        }
        ++i < right ? count += mx_quicksort(arr, i, right) : i;
        --j > left ? count += mx_quicksort(arr, left, j) : j;
    }
    return count;
}
