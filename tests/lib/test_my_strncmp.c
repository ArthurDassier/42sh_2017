/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strncmp
*/
#include <criterion/criterion.h>
#include <string.h>
#include "42sh.h"

int my_strncmp(const char *s1, const char *s2, int n);

Test(my_strncmp, return_value_is_good)
{
	cr_expect_eq(my_strncmp("rani", "ranita", 5), -116);
	cr_expect_eq(strncmp("ranita", "ranita", 3), 0);
	cr_expect_eq(strncmp("ranita", "ra", 3), 110);
}