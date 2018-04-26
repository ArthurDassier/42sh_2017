/*
** EPITECH PROJECT, 2017
** test power
** File description:
** power test
*/
#include <criterion/criterion.h>
#include "42sh.h"
int my_compute_power_it(int nb, int p);

Test(my_compute_power_it, return_value_is_good)
{
	cr_assert_eq(my_compute_power_it(4, 3), 64);
	cr_assert_eq(my_compute_power_it(4, 0), 1);
	cr_assert_eq(my_compute_power_it(4, -5), 0);
}
