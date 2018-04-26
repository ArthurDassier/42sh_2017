/*
** EPITECH PROJECT, 2017
** my_compute_factorial_rec.c
** File description:
** compute factorial
*/
#include "my.h"

int my_compute_factorial_rec(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb > 1)
		return (nb * my_compute_factorial_rec(nb - 1));
	else
		return (1);
}