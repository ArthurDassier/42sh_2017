/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_getnbr
*/
#include <criterion/criterion.h>
#include "42sh.h"

int my_getnbr(char const *str);

Test(my_getnbr, return_value_is_good)
{
	cr_assert_eq(my_getnbr("+---+--++---+---+---+-42"), -42);
	cr_assert_eq(my_getnbr("42a43"), 42);
	cr_assert_eq(my_getnbr("42-43"), 42);
	cr_assert_eq(my_getnbr("000000042"), 42);
	cr_assert_eq(my_getnbr("0"), 0);
	cr_assert_eq(my_getnbr("12"), 12);
	cr_assert_eq(my_getnbr("-12"), -12);
	cr_assert_eq(my_getnbr("11000000000000000000000042"), 0);
	cr_assert_eq(my_getnbr("−1000000000000000000000042"), 0);
}