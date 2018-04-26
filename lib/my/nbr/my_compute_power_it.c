/*
** EPITECH PROJECT, 2017
** power
** File description:
** power cal
*/
#include "my.h"

int my_compute_power_it(int nb, int p)
{
	int	result = nb;

	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	if (p > 0) {
		while (p > 1) {
			result = nb * result;
			--p;
		}
	}
	return (result);
}