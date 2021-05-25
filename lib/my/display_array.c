/*
** EPITECH PROJECT, 2020
** B-PSU-200-RUN-2-1-mysokoban-yann.joubert
** File description:
** display_array.c
*/

#include "my.h"
#include "my_printf_funct.h"
#include <stddef.h>

void display_array(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        my_printf("%s", array[i]);
        i = i + 1;
    }
}