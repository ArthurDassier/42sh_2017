/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strlen
*/
#include <criterion/criterion.h>
#include "42sh.h"

int my_strlen(const char *);

Test(my_strlen, return_value_is_good)
{
	cr_assert_eq(my_strlen("toto"), 4);
	cr_assert_eq(my_strlen("Hello World"), 11);
	cr_assert_eq(my_strlen(""), 0);
}
