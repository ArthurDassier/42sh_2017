/*
** EPITECH PROJECT, 2017
** find prime
** File description:
** cal prime
*/
#include "my.h"

static int my_find_prime(int nb)
{
	int	i = 2;
	int	divide = 0;

	if (nb == 0 || nb == 1 || nb < 0)
		return (0);
	while (i < nb) {
		if (divide > 0)
			return (0);
		if (nb % i == 0) {
			++divide;
			++i;
		} else {
			++i;
		}
	}
	return (nb);
}

int my_find_prime_sup(int nb)
{
	while (!(my_find_prime(nb))) {
		my_find_prime(nb);
		++nb;
	}
	return (nb);
}