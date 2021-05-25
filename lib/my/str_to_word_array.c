/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** str_to_word_array.c
*/

#include <stdlib.h>
#include "my.h"

int compt_letter(char *str, char h)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != h) {
        i = i + 1;
    }
    return (i);
}

int compt_spaces(char *str, char h)
{
    int i = 0;
    int stock = 0;

    while (str[i] != '\0') {
        if (str[i] == h) {
            stock = stock + 1;
            i = i + 1;
        }
        i = i + 1;
    }
    stock = stock + 1;
    return (stock);
}

char **all_malloc(char *str, char h)
{
    int i = 0;
    char **tab = NULL;
    int num = 0;
    int nxt = 0;

    tab = malloc(sizeof(char *) * (compt_spaces(str, h) + 1));
    while (str[i] != '\0') {
        if (str[i] == h) {
            tab[num] = malloc(sizeof(char) * (compt_letter(str + nxt, h) + 1));
            i = i + 1;
            num = num + 1;
            nxt = nxt + compt_letter(str + nxt, h) + 1;
        }
        i = i + 1;
    }
    tab[num] = malloc(sizeof(char) * (compt_letter(str + nxt, h) + 1));
    tab[compt_spaces(str, h)] = NULL;
    return (tab);
}

char **copy_tab(char *str, char h, char **tab)
{
    int i = 0;
    int num = 0;
    int next = 0;

    while (str[i] != '\0') {
        if (str[i] == h) {
            tab[num][next] = '\0';
            i = i + 1;
            num = num + 1;
            next = 0;
        }
        tab[num][next] = str[i];
        i = i + 1;
        next = next + 1;
    }
    tab[num][next] = '\0';
    return (tab);
}

char **str_to_word_array(char *str, char h)
{
    char **tab;

    tab = all_malloc(str, h);
    tab = copy_tab(str, h, tab);
    return (tab);
}