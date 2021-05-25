/*
** EPITECH PROJECT, 2020
** B-PSU-200-RUN-2-1-mysokoban-yann.joubert
** File description:
** check_coord.c
*/

#include "my.h"
#include "my_printf_funct.h"
#include "sokoban.h"
#include <ncurses.h>

int number_o(char **map)
{
    int x_map = 0;
    int y_map = 0;
    int count = 0;

    while (map[y_map] != NULL) {
        x_map = 0;
        while (map[y_map][x_map] != '\0') {
            if (map[y_map][x_map] == 'O')
                count = count + 1;
            x_map = x_map + 1;
        }
        y_map = y_map + 1;
    }
    return (count);
}

void init_end_o(coordo_t *coordo, int cases)
{
    coordo[cases].end = 1;
    coordo[cases].poso_x = 0;
    coordo[cases].poso_y = 0;
}

coordo_t *check_coord_o(char **map)
{
    coordo_t *coordo = malloc(sizeof(coordo_t) * (number_o(map) + 1));
    int y_map = 0;
    int x_map = 0;
    int cases = 0;

    while (map[y_map] != NULL) {
        x_map = 0;
        while (map[y_map][x_map] != '\0') {
            if (map[y_map][x_map] == 'O') {
                coordo[cases].poso_y = y_map;
                coordo[cases].poso_x = x_map;
                coordo[cases].end = 0;
                cases = cases + 1;
            }
            x_map = x_map + 1;
        }
        y_map = y_map + 1;
    }
    init_end_o(coordo, cases);
    return (coordo);
}

int number_x(char **map)
{
    int x_map = 0;
    int y_map = 0;
    int count = 0;

    while (map[y_map] != NULL) {
        x_map = 0;
        while (map[y_map][x_map] != '\0') {
            if (map[y_map][x_map] == 'X')
                count = count + 1;
            x_map = x_map + 1;
        }
        y_map = y_map + 1;
    }
    return (count);
}

vectorxy_t *get_pos_x(char **map)
{
    vectorxy_t *coordx = malloc(sizeof(vectorxy_t) * (number_x(map) + 1));
    int y_map = 0;
    int x_map = 0;
    int cases = 0;

    while (map[y_map] != NULL) {
        x_map = 0;
        while (map[y_map][x_map] != '\0') {
            if (map[y_map][x_map] == 'O') {
                coordx[cases].o = y_map;
                coordx[cases].x = x_map;
                cases = cases + 1;
            }
            x_map = x_map + 1;
        }
        y_map = y_map + 1;
    }
    return (coordx);
}
