/*
** EPITECH PROJECT, 2020
** B-PSU-200-RUN-2-1-mysokoban-yann.joubert
** File description:
** test_read_file.c
*/

#include "my.h"
#include "my_printf_funct.h"
#include <criterion/criterion.h>
#include "sokoban.h"
#include <stdio.h>

Test(read_file, first_test)
{
    char *av[] = {"", "tests/test_read_file.c"};
    char *buffer = read_file(av);
    char *expected = "/*\n** EPITECH PROJECT, 2020";

    cr_assert_eq(0, strncmp(expected, buffer, 26));
}