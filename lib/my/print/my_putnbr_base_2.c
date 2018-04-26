/*
** EPITECH PROJECT, 2017
** my_putnbr_base_2.c
** File description:
** 2nd version of my_putnbr_base
*/
#include "printf.h"

int my_putnbr_base_2(unsigned long nbr, char const *base)
{
	unsigned long	i;
	unsigned long	len_str;

	len_str = my_strlen(base);
	i = nbr % len_str;
	nbr = nbr / len_str;
	if (nbr > 0)
		my_putnbr_base_2(nbr, base);
	my_putchar(base[i]);
	return (0);
}