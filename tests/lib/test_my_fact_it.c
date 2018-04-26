/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_fact_it
*/
#include <criterion/criterion.h>
#include "42sh.h"

int my_compute_factorial_it(int nb);

Test(my_compute_factorial_it, return_value_is_good)
{
	cr_expect_eq(my_compute_factorial_it(4), 24);
	cr_expect_eq(my_compute_factorial_it(13), 0);
	cr_expect_eq(my_compute_factorial_it(-6), 0);
}
