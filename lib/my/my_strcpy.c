/*
** EPITECH PROJECT, 2020
** B-PSU-200-RUN-2-1-mysokoban-yann.joubert
** File description:
** my_strcpy.c
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i])
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

void my_strcopy(char **dest, char *src)
{
    int i = 0;

    while (src[i])
        (*dest)[i] = src[i];
    (*dest)[i] = '\0';
}