/*
** EPITECH PROJECT, 2017
** getnbr.c
** File description:
** return a nb from string
*/
#include "my.h"

static int neg(char const *str)
{
	int	check = 1;
	int	i = 0;

	while (str[i]) {
		if (str[i] == '-')
			check *= -1;
		else if (str[i] <= '9' && str[i] >= '0')
			break;
		++i;
	}
	return (check);
}

int my_getnbr(char const *str)
{
	int	i = 0;
	int	nb;
	int	count = 0;

	while (!(str[i] >= '0' && str[i] <= '9') && (str[i] == '-'
		|| str[i] == '+'))
			++i;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	nb = str[i] - 48;
	++i;
	while (str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10 + str[i] - 48;
		++count;
		++i;
	}
	if (count >= 10)
		return (0);
	if (neg(str) < 0)
		nb *= -1;
	return (nb);
}