/*
** EPITECH PROJECT, 2017
** prime
** File description:
** test prime
*/
#include <criterion/criterion.h>
#include "42sh.h"

int my_is_prime(int nb);

Test(my_is_prime, return_value_is_good)
{
	cr_assert_eq(my_is_prime(11), 1);
	cr_assert_eq(my_is_prime(1), 0);
	cr_assert_eq(my_is_prime(6), 0);
}
