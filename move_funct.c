/*
** EPITECH PROJECT, 2020
** B-PSU-200-RUN-2-1-mysokoban-yann.joubert
** File description:
** move_funct.c
*/

#include "my.h"
#include "my_printf_funct.h"
#include "sokoban.h"
#include <ncurses.h>
#include <stdbool.h>

bool reput_o(coordo_t *coordo, pos_t *pos)
{
    int i = 0;

    while (coordo[i].end != 1) {
        if (coordo[i].poso_y == pos->pos_y &&
        coordo[i].poso_x == pos->pos_x)
            return true;
        i = i + 1;
    }
    return false;
}

void move_x(vectorxy_t *vector, char **map, int mv_y, int mv_x)
{
    int new_y = vector->pos.pos_y + mv_y;
    int new_x = vector->pos.pos_x + mv_x;
    int coordx_y = new_y + mv_y;
    int coordx_x = new_x + mv_x;

    if (map[new_y][new_x] == 'X') {
        if (map[coordx_y][coordx_x] == ' ' || map[coordx_y][coordx_x] == 'O') {
            if (reput_o(vector->coordo, &vector->pos) == true)
                map[vector->pos.pos_y][vector->pos.pos_x] = 'O';
            else
                map[vector->pos.pos_y][vector->pos.pos_x] = ' ';
            map[coordx_y][coordx_x] = 'X';
            map[new_y][new_x] = 'P';
            vector->pos.pos_y = new_y;
            vector->pos.pos_x = new_x;
        }
    }
}

void move_p(vectorxy_t *vector, char **map, int mv_y, int mv_x)
{
    int new_y = vector->pos.pos_y + mv_y;
    int new_x = vector->pos.pos_x + mv_x;

    if (map[new_y][new_x] == ' ' || map[new_y][new_x] == 'O') {
        if (reput_o(vector->coordo, &vector->pos) == true)
            map[vector->pos.pos_y][vector->pos.pos_x] = 'O';
        else
            map[vector->pos.pos_y][vector->pos.pos_x] = ' ';
        map[new_y][new_x] = 'P';
        vector->pos.pos_y = new_y;
        vector->pos.pos_x = new_x;
    }
    else
        move_x(vector, map, mv_y, mv_x);
}