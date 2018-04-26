/*
** EPITECH PROJECT, 2017
** flags_4.c
** File description:
** flags for printf
*/
#include "printf.h"

int flag_hash(va_list ap, char const *str)
{
	int	j;
	int	count;

	if (str[get_flag(str)] == 'o')
		my_putchar('0');
	if (str[get_flag(str)] == 'x')
		my_putstr("0x");
	if (str[get_flag(str)] == 'X')
		my_putstr("0X");
	j = verif_flag(str + get_flag(str), 1, 1);
	if (j != NB_FLAGS)
		count = (tab[j].ptr)(ap, str + get_flag(str));
	return (count);
}