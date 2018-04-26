/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_char_is_alphanum
*/
#include <criterion/criterion.h>
#include "minishell2.h"

int my_char_is_alphanum(char);

Test(my_char_is_alphanum, return_value_is_good)
{
	cr_assert_eq(my_char_is_alphanum('a'), 1);
	cr_assert_eq(my_char_is_alphanum('9'), 1);
	cr_assert_eq(my_char_is_alphanum('*'), 0);
}
