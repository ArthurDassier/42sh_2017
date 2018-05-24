/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strncat
*/
#include <criterion/criterion.h>
#include "42sh.h"

char	*my_strncat(char *dest, char const *src, int nb);

Test(my_strncat, return_value_is_good)
{
	char *dest = strdup("");
	char *dest1 = strdup("Hello");
	char *dest2 = strdup("Hello");

	cr_expect_str_eq(my_strncat(dest, "Hello", 2), "He");
	cr_expect_str_eq(my_strncat(dest1, " World", 6), "Hello World");
	cr_expect_str_eq(my_strncat(dest2, "", 1), "Hello");
}