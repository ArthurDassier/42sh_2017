/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strlowcase
*/
#include <criterion/criterion.h>
#include "42sh.h"

char *my_strlowcase(char *str);

Test(my_strlowcase, return_value_is_good)
{
	char	*str;

	str = strdup("HELLO");
	cr_expect_str_eq(my_strlowcase(str), "hello");
}

Test(my_strlowcase, return_value_is_good_V2)
{
	char	*str;

	str = strdup("HEL1O Y");
	cr_expect_str_eq(my_strlowcase(str), "hel1o y");
}


Test(my_strlowcase, return_value_is_good_V3)
{
	char	*str;

	str = strdup("42WORDS");
	cr_expect_str_eq(my_strlowcase(str), "42words");
}
