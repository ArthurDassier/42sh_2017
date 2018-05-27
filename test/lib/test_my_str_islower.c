/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_str_islower
*/
#include <criterion/criterion.h>
#include "shell.h"

int my_str_islower(const char *str);

Test(my_str_islower, return_value_is_good)
{
	cr_expect_eq(my_str_islower("hello"), 1);
	cr_expect_eq(my_str_islower("hello6789"), 0);
	cr_expect_eq(my_str_islower("HELLO"), 0);
}