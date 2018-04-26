/*
** EPITECH PROJECT, 2017
** my_compute_factorial_it.c
** File description:
** compute factorial
*/
#include "my.h"

int my_compute_factorial_it(int nb)
{
	int	res = 1;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 1) {
		res *= nb;
		--nb;
	}
	return (res);
}