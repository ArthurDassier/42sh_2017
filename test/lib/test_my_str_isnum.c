/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_str_isnum
*/
#include <criterion/criterion.h>
#include "42sh.h"

int my_str_isnum(const char *str);

Test(my_str_isnum, return_value_is_good)
{
	cr_expect_eq(my_str_isnum("45678"), 1);
	cr_expect_eq(my_str_isnum("hello6789"), 0);
	cr_expect_eq(my_str_isnum("HELLO"), 0);
	cr_expect_eq(my_str_isnum("HEL---LO"), 0);
}