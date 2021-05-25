/*
** EPITECH PROJECT, 2020
** B-PSU-200-RUN-2-1-mysokoban-yann.joubert
** File description:
** sokoban.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

typedef struct coordo_s {
    int poso_x;
    int poso_y;
    int end;
} coordo_t;

typedef struct pos_s {
    int pos_x;
    int pos_y;
} pos_t;

typedef struct vectorxy {
    int o;
    int x;
    pos_t pos;
    coordo_t *coordo;
} vectorxy_t;

char *read_file(char **av);
int error_system(int fd, int size);
int usage(void);
void check_coord_p(pos_t *pos, char **map);
int print_sokoban(char **buffer);
void error_binary(int ac);
char *read_help(char *buffer);
long int get_size(char *buffer);
void move_vector(vectorxy_t *vector, char **map, int key);
void move_p(vectorxy_t *vector, char **map, int mv_y, int mv_x);
vectorxy_t *init(char **map);
void display_map(char **map);
int number_o(char **map);
coordo_t *check_coord_o(char **map);
void init_end_o(coordo_t * coordo, int cases);
bool reput_o(coordo_t *coordo, pos_t *pos);
void move_x(vectorxy_t *vector, char **map, int mv_y, int mv_x);
void rm_side_spc(char **str);
void regular_space(char **str);
int next_sep(char *str, char sep);
int count_word(char *str, char sep);
char **my_str_to_word_array(char *src, char sep);
char **my_str_to_word_array1(char *str, char sep);
int number_x(char **map);

#endif