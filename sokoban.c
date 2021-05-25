/*
** EPITECH PROJECT, 2020
** B-PSU-200-RUN-2-1-mysokoban-yann.joubert
** File description:
** sokoban.c
*/

#include "my.h"
#include "my_printf_funct.h"
#include "sokoban.h"
#include <ncurses.h>

void check_coord_p(pos_t *pos, char **map)
{
    int y_map = 0;
    int x_map = 0;

    while (map[y_map] != NULL) {
        x_map = 0;
        while (map[y_map][x_map] != '\0') {
            if (map[y_map][x_map] == 'P') {
                pos->pos_y = y_map;
                pos->pos_x = x_map;
            }
            x_map = x_map + 1;
        }
        y_map = y_map + 1;
    }
}

vectorxy_t *init(char **map)
{
    vectorxy_t *vector = malloc(sizeof(vectorxy_t));

    check_coord_p(&vector->pos, map);
    vector->coordo = check_coord_o(map);
    return (vector);
}

void display_map(char **map)
{
    int i = 0;
    int lines = 0;

    while (map[i] != NULL) {
        mvprintw(lines, 0, map[i]);
        lines = lines + 1;
        i = i + 1;
    }
}

void move_vector(vectorxy_t *vector, char **map, int key)
{
    if (key == KEY_UP)
        move_p(vector, map, -1, 0);
    if (key == KEY_DOWN)
        move_p(vector, map, 1, 0);
    if (key == KEY_LEFT)
        move_p(vector, map, 0, -1);
    if (key == KEY_RIGHT)
        move_p(vector, map, 0, 1);
}

int print_sokoban(char **buffer)
{
    char *read = read_file(buffer);
    char **map = my_str_to_word_array1(read, '\n');
    vectorxy_t *vector = init(map);
    WINDOW *window = NULL;
    int key = 0;

    window = initscr();
    keypad(window, TRUE);
    while (1) {
        clear();
        if (key == 'q')
            break;
        move_vector(vector, map, key);
        display_map(map);
        key = getch();
        refresh();
    }
    endwin();
    delwin(window);
    return (EXIT_SUCCESS);
}