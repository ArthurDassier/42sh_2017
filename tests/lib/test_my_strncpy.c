/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strncpy
*/
#include <criterion/criterion.h>
#include <string.h>
#include "minishell2.h"

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, return_value_is_good)
{
	char	*str;

	str = strdup("");
	cr_expect_str_eq(my_strncpy(str, "hello World", 8), "hello Wo");
}