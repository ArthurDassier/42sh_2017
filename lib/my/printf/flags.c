/*
** EPITECH PROJECT, 2017
** flags.c
** File description:
** flags printf
*/
#include "printf.h"

int flag_s(va_list ap, char const *str)
{
	char	*string = va_arg(ap, char *);
	int	i;

	(void)str;
	if (string == 0) {
		my_putstr("(null)");
		return (6);
	}
	i = my_strlen(string);
	my_putstr(string);
	return (i);
}

int flag_d(va_list ap, char const *str)
{
	int	nb = va_arg(ap, int);
	int	i = counting(nb);

	(void)str;
	my_put_nbr(nb);
	return (i);
}

int flag_i(va_list ap, char const *str)
{
	int	nb = va_arg(ap, int);
	int	i = counting(nb);

	(void)str;
	my_put_nbr(nb);
	return (i);
}

int flag_c(va_list ap, char const *str)
{
	char	c = va_arg(ap, int);

	(void)str;
	my_putchar(c);
	return (1);
}