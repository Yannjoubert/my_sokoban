/*
** EPITECH PROJECT, 2020
** B-PSU-200-RUN-2-1-mysokoban-yann.joubert
** File description:
** read_file.c
*/

#include "my.h"
#include "my_printf_funct.h"
#include "sokoban.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ncurses.h>

long int get_size(char *buffer)
{
    struct stat help_s;

    if (stat(buffer, &help_s) == 0)
        return (help_s.st_size);
    return 0;
}

char *read_help(char *buffer)
{
    int fd = open(buffer, O_RDONLY);
    size_t size = get_size(buffer);
    char *dest = NULL;

    if (fd < 0)
        return NULL;
    dest = malloc(sizeof(char) * (size + 1));
    read(fd, dest, size);
    dest[size] = '\0';
    close(fd);
    return dest;
}

char *read_file(char **av)
{
    struct stat sokoban_s;
    int fd = 0;

    stat(av[1], &sokoban_s);
    int size = sokoban_s.st_size;
    char *buffer = malloc(sizeof(char) * (size + 1));
    fd = open(av[1], O_RDONLY);
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    error_system(fd, size);
    return (buffer);
}