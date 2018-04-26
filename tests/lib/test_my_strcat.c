/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strcat
*/
#include <criterion/criterion.h>
#include "minishell2.h"

char	*my_strcat(char *dest, char const *src);

Test(my_strcat, return_value_is_good)
{
	char *dest = strdup("");
	char *dest1 = strdup("Hello");
	char *dest2 = strdup("Hello");

	cr_expect_str_eq(my_strcat(dest, "Hello"), "Hello");
	cr_expect_str_eq(my_strcat(dest1, " World"), "Hello World");
	cr_expect_str_eq(my_strcat(dest2, ""), "Hello");
}