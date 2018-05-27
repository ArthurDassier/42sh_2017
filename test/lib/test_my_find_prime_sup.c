/*
** EPITECH PROJECT, 2017
** prime test
** File description:
** test prime
*/
#include <criterion/criterion.h>
#include "shell.h"

int my_find_prime_sup(int nb);

Test(my_find_prime_sup, return_value_is_good)
{
	cr_expect_eq(my_find_prime_sup(11), 11);
	cr_expect_eq(my_find_prime_sup(591), 593);
	cr_assert_eq(my_find_prime_sup(908), 911);
}
