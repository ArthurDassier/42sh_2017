/*
** EPITECH PROJECT, 2017
** square
** File description:
** cal root
*/
#include "my.h"

int my_compute_square_root(int nb)
{
	int	i = 1;

	while (i * i < nb)
		++i;
	if (i * i == nb)
		return (i);
	else
		return (0);
}