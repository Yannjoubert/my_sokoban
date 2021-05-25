/*
** EPITECH PROJECT, 2020
** B-PSU-101-RUN-1-1-minishell1-yann.joubert
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(const char *str)
{
    int i = 0;
    char *src = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i] != '\0') {
        src[i] = str[i];
        i = i + 1;
    }
    return (src);
}

char *my_strndup(const char *str, int n)
{
    int i = 0;
    char *src = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i] != '\0' && i != n) {
        src[i] = str[i];
        i = i + 1;
    }
    src[i] = '\0';
    return (src);
}