/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strupcase
*/
#include <criterion/criterion.h>
#include <string.h>
#include "42sh.h"

char *my_strupcase(char *str);

Test(my_strupcase, return_value_is_good)
{
	char	*str;

	str = strdup("Hello");
	cr_expect_str_eq(my_strupcase(str), "HELLO");
}


Test(my_strupcase, return_value_is_good_V2)
{
	char	*str;

	str = strdup("hel1O y");
	cr_expect_str_eq(my_strupcase(str), "HEL1O Y");
}


Test(my_strupcase, return_value_is_good_V3)
{
	char	*str;

	str = strdup("42words");
	cr_expect_str_eq(my_strupcase(str), "42WORDS");
}

