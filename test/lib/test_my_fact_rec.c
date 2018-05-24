/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_fact_rec
*/
#include <criterion/criterion.h>
#include "42sh.h"

int my_compute_factorial_rec(int nb);

Test(my_compute_factorial_rec, return_value_is_good)
{
	cr_assert_eq(my_compute_factorial_rec(4), 24);
	cr_assert_eq(my_compute_factorial_rec(13), 0);
	cr_assert_eq(my_compute_factorial_rec(-6), 0);
}
