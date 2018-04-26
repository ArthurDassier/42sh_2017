/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strdup
*/
#include <criterion/criterion.h>
#include "minishell2.h"

char	*my_strdup(char const *src);

Test(my_strdup, return_value_is_good)
{
	cr_expect_str_eq(my_strdup("Hello"), "Hello");
	cr_expect_str_eq(my_strdup("Hello World"), "Hello World");
	cr_expect_str_eq(my_strdup("Hello32"), "Hello32");
}