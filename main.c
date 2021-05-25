/*
** EPITECH PROJECT, 2020
** B-PSU-200-RUN-2-1-mysokoban-yann.joubert
** File description:
** main.c
*/

#include "my.h"
#include "my_printf_funct.h"
#include "sokoban.h"
#include "unistd.h"
#include <ncurses.h>

// int main(int ac, char **av)
// {
//     char *help = NULL;

//     if (ac == 2) {
//         if (av[1][0] == '-' && av[1][1] == 'h') {
//             help = read_help("./test_txt/help.txt");
//             my_printf("%s", help);
//             my_printf("zebi\n");
//             free(help);
//             return 0;
//         } else {
//             read_file(av);
//             print_sokoban(av);
//         }
//     } else {
//         my_printf("Invalid file !\n");
//         return 84;
//     }
//     return 0;
// }

int main(int ac, char **av)
{
    (void)ac;
    char *help = NULL;

    help = read_help("help.txt");
    if (my_strcmp(av[1], "-h") == 0) {
        my_printf("%s", help);
        return (0);
    }
    else {
        print_sokoban(av);
        return (0);
    }
    error_binary(ac);
    return (0);
}