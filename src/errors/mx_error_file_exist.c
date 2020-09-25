#include "pathfinder.h"

void mx_error_file_exist(char *file) {
    int fd = 0;

    fd = open(file, O_RDONLY);
    if (fd < 0) {
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" does not exist\n");
        close(fd);
        system("leaks -q pathfinder");
        exit(1);
    }
    close(fd);
}
