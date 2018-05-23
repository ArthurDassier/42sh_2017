/*
** EPITECH PROJECT, 2017
** flags_2.c
** File description:
** flags printf
*/
#include "printf.h"

int flag_b(va_list ap, char const *str)
{
	unsigned int	nb = va_arg(ap, unsigned int);
	int		i = 0;

	(void)str;
	i = counting(my_putnbr_base(nb, "01"));
	return (i);
}

int flag_s_capitalize(va_list ap, char const *str)
{
	char	*string = va_arg(ap, char *);
	int	i = my_strlen(string);

	(void)str;
	for (int j = 0; string[j]; ++j) {
		if (my_char_is_alphanum(string[j]) == 0) {
			my_putchar('\\');
			if ((int)string[j] >= 0 && (int)string[j] <= 7)
				my_putstr("00");
			else if ((int)string[j] >= 8 && (int)string[j] <= 63)
				my_putchar('0');
			my_putnbr_base((int)string[j], "01234567");
			++j;
		}
		my_putchar(string[j]);
	}
	return (i);
}

int flag_hexa(va_list ap, char const *str)
{
	unsigned int	nb = va_arg(ap, unsigned int);
	int		i = 0;

	(void)str;
	i = counting(my_putnbr_base(nb, "0123456789abcdef"));
	return (i);
}

int flag_hexa_capitalize(va_list ap, char const *str)
{
	unsigned int	nb = va_arg(ap, unsigned int);
	int		i = 0;

	(void)str;
	i = counting(my_putnbr_base(nb, "0123456789ABCDEF"));
	return (i);
}

int flag_o(va_list ap, char const *str)
{
	unsigned int	nb = va_arg(ap, unsigned int);
	int		i = 0;

	(void)str;
	i = counting(my_putnbr_base(nb, "01234567"));
	return (i);
}
