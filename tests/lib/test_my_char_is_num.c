/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_char_is_num
*/
#include <criterion/criterion.h>
#include "minishell2.h"

int my_char_is_num(char);

Test(my_char_is_num, return_value_is_good)
{
	cr_assert_eq(my_char_is_num('a'), 0);
	cr_assert_eq(my_char_is_num('9'), 1);
	cr_assert_eq(my_char_is_num('*'), 0);
}