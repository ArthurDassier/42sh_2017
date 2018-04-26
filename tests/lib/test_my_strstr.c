/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strstr
*/
#include <criterion/criterion.h>
#include <string.h>
#include "minishell2.h"

char *my_strstr(char *s1, const char *to_find);

Test(my_strstr, return_value_is_good)
{
	cr_expect_str_eq(my_strstr("Hello World", "Hello W"), "Hello World");
	cr_expect_str_eq(my_strstr("hello", "hel"), "hello");
	cr_expect_str_eq(my_strstr("world 23abc", "abc"), "abc");
	cr_expect_str_eq(my_strstr("42words", "ords"), "ords");
}