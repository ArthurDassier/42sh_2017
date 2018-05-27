/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_revstr
*/
#include <criterion/criterion.h>
#include "shell.h"

char *my_revstr(char *str);

Test(my_revstr, return_value_is_good)
{
	char	*str;

	str = strdup("hello");
	cr_expect_str_eq(my_revstr(str), "olleh");
}

Test(my_revstr, return_value_is_good_V2)
{
	char	*str;

	str = strdup("coucou");
	cr_expect_str_eq(my_revstr(str), "uocuoc");
}
