/*
** EPITECH PROJECT, 2017
** my_putnbr_base.c
** File description:
** print base
*/
#include "my.h"

int my_putnbr_base(int nbr, char const *base)
{
	int	i;
	int	len_str;

	if (nbr == -2147483648)
		return (nbr);
	if (nbr < 0) {
		my_putchar('-');
		nbr = nbr * -1;
	}
	len_str = my_strlen(base);
	i = nbr % len_str;
	nbr = nbr / len_str;
	if (nbr > 0)
		my_putnbr_base(nbr, base);
	my_putchar(base[i]);
	return (0);
}