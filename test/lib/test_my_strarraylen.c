/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_strarraylen
*/
#include <criterion/criterion.h>
#include "42sh.h"

int my_strarraylen(char **array);

Test(my_strarraylen, return_value_is_good)
{
	char	tab[] = {"1", "2", "3", "4"};

	cr_assert_eq(my_strarraylen(tab), 4);
}