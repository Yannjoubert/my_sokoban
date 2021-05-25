/*
** EPITECH PROJECT, 2020
** B-PSU-200-RUN-2-1-mysokoban-yann.joubert
** File description:
** error.c
*/

#include "my.h"
#include "my_printf_funct.h"
#include "sokoban.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ncurses.h>

int error_system(int fd, int size)
{
    if (fd < 0)
        exit(84);
    if (size == 0) {
        write(2, "No Argument\n", 13);
        exit(84);
    }
    return (0);
}

void error_binary(int ac)
{
    if (ac != 2) {
        write(2, "Invalid size\n", 14);
        exit(84);
    }
}