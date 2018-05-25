/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_str_isupper
*/
#include <criterion/criterion.h>
#include <string.h>
#include "42sh.h"

int my_str_isupper(const char *str);

Test(my_str_isupper, return_value_is_good)
{
	cr_expect_eq(my_str_isupper("HELLO"), 1);
	cr_expect_eq(my_str_isupper("hello6789"), 0);
	cr_expect_eq(my_str_isupper("hello"), 0);
}