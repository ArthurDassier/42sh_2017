/*
** EPITECH PROJECT, 2017
** flags_3.c
** File description:
** flags for printf
*/
#include "printf.h"

int flag_u(va_list ap, char const *str)
{
	unsigned int	nb = va_arg(ap, unsigned int);
	int		i = 0;

	(void)str;
	i = counting(my_putnbr_base(nb, "0123456789"));
	return (i);
}

int flag_p(va_list ap, char const *str)
{
	unsigned long	string = va_arg(ap, unsigned long);
	int	i = 0;

	(void)str;
	my_putstr("0x");
	i = counting(my_putnbr_base_2(string, "0123456789abcdef"));
	return (i);
}

int flag_modulo(va_list ap, char const *str)
{
	(void)str;
	ap = ap + 1;
	my_putchar('%');
	return (1);
}

int flag_plus(va_list ap, char const *str)
{
	int	nb;
	int	j;
	int	count;
	va_list	aq;

	va_copy(aq, ap);
	nb = va_arg(aq, int);
	if (nb > 0)
		my_putchar('+');
	j = verif_flag(str + get_flag(str), 1, 1);
	if (j != NB_FLAGS)
		count = (tab[j].ptr)(ap, str + get_flag(str));

	va_end(aq);
	return (count + 1);
}

int flag_space(va_list ap, char const *str)
{
	int	j;
	int	count;

	my_putchar(' ');
	j = verif_flag(str + get_flag(str), 1, 1);
	if (j != NB_FLAGS)
		count = (tab[j].ptr)(ap, str + get_flag(str));
	return (count);
}