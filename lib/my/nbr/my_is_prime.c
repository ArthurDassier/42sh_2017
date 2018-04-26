/*
** EPITECH PROJECT, 2017
** is prime
** File description:
** cal is prime
*/
#include "my.h"

int my_is_prime(int nb)
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
	return (1);
}