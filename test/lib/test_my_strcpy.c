/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strcpy
*/
#include <criterion/criterion.h>
#include "42sh.h"

char *my_strcpy(char *dest, char const *src);

Test(my_strcpy, return_value_is_good)
{
	char	*str;

	str = my_strdup("");
	cr_expect_str_eq(my_strcpy(str, "hello"), "hello");
}