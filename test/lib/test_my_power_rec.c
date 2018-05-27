/*
** EPITECH PROJECT, 2017
** test power rec
** File description:
** power rec test
*/
#include <criterion/criterion.h>
#include "shell.h"
int my_compute_power_rec(int nb, int p);

Test(my_compute_power_rec, return_value_is_good)
{
	cr_assert_eq(my_compute_power_rec(4, 3), 64);
	cr_assert_eq(my_compute_power_rec(4, 0), 1);
	cr_assert_eq(my_compute_power_rec(4, -5), 0);
}
