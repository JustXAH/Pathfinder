#include "pathfinder.h"

void mx_error_file_empty(char *file) {
    int fd = 0;
    char ch;
    int amount = 0;

    fd = open(file, O_RDONLY);
    for ( ; read(fd, &ch, 1); amount++);
    if (amount <= 0) {
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" is empty\n");
        close(fd);
        system("leaks -q pathfinder");
        exit(1);
    }
    close(fd);
}
