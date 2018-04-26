/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_char_is_alpha
*/
#include <criterion/criterion.h>
#include "42sh.h"

int my_char_is_alpha(char c);

Test(my_char_is_alpha, return_value_is_good)
{
	cr_assert_eq(my_char_is_alpha('a'), 1);
	cr_assert_eq(my_char_is_alpha('&'), 0);
	cr_assert_eq(my_char_is_alpha(' '), 0);
	cr_assert_eq(my_char_is_alpha('3'), 0);
}
