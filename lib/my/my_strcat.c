/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** concatenates two strings
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;
    char *res = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);

    while (dest[i] != '\0') {
        res[i] = dest[i];
        i = i + 1;
    }
    while (src[a] != '\0') {
        res[i] = src[a];
        a = a + 1;
        i = i + 1;
    }
    return (res);
}
