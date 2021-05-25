/*
** EPITECH PROJECT, 2020
** Makfile_lib
** File description:
** my_str_to_word_array.c
*/

#include "my.h"
#include "unistd.h"
#include <stdlib.h>

int count_words(char *str, char sep)
{
    int i = 0;
    int stock_words = 0;

    while (str[i] != '\0') {
        if (str[i] == sep) {
            stock_words++;
            i++;
        }
        while (str[i] == sep && str[i] != '\0')
            i++;
        while (str[i] != sep && str[i] != '\0')
            i++;
    }
    return (stock_words + 1);
}

int count_letters(char *str, char sep, int i)
{
    int count_letters = 0;

    while (str[i] != '\0' && str[i] != sep) {
        count_letters++;
        i++;
    }
    return (count_letters);
}

char **my_str_to_word_array1(char *str, char sep)
{
    int e = 0;
    int add_tab = 0;
    char **tab = malloc(sizeof(char *) * (count_words(str, sep) + 1));

    for (int i = 0; str[i] != '\0'; e++) {
        for (;str[i] == sep && str[i] != '\0'; i++)
            continue;
        tab[e] = malloc(sizeof(char) * (count_letters(str, sep, i) + 1));
        for (;str[i] != sep && str[i] != '\0'; i++, add_tab++)
            tab[e][add_tab] = str[i];
        tab[e][add_tab] = '\0';
        add_tab = 0;
    }
    tab[e] = NULL;
    return (tab);
}