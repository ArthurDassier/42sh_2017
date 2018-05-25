/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_str_isalpha
*/
#include <criterion/criterion.h>
#include "42sh.h"

int my_str_isalpha(const char *str);

Test(my_str_isalpha, return_value_is_good)
{
	cr_expect_eq(my_str_isalpha("Hello"), 1);
	cr_expect_eq(my_str_isalpha("Hello6789"), 0);
	cr_expect_eq(my_str_isalpha("Hell+++o6"), 0);
}