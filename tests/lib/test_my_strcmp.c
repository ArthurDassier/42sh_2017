/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strcmp
*/
#include <criterion/criterion.h>
#include <string.h>
#include "minishell2.h"

int my_strcmp(const char *s1, const char *s2);

Test(my_strcmp, return_value_is_good)
{
	cr_expect_eq(my_strcmp("rani", "rani"), 0);
	cr_expect_eq(my_strcmp("rani", "ranita"), -116);
	cr_expect_eq(my_strcmp("ranicop", "ran"), 105);
}