/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** my_printf function
*/
#include "printf.h"

struct s_flag tab[NB_FLAGS] = {
	{"%s", &flag_s},
	{"%d", &flag_d},
	{"%c", &flag_c},
	{"%i", &flag_i},
	{"%b", &flag_b},
	{"%S", &flag_s_capitalize},
	{"%x", &flag_hexa},
	{"%X", &flag_hexa_capitalize},
	{"%o", &flag_o},
	{"%u", &flag_u},
	{"%p", &flag_p},
	{"%%", &flag_modulo},
	{"%+", &flag_plus},
	{"% ", &flag_space},
	{"%#", &flag_hash}
};

int my_printf(char const *str, ...)
{
	int	j;
	int	count = 0;
	va_list	ap;

	va_start(ap, str);
	for (int i = 0; str[i]; ++i) {
		j = verif_flag(str + i, 2, 0);
		if (j != NB_FLAGS) {
			count = (tab[j].ptr)(ap, str + i++);
			if (j >= 12) {
				i++;
			}
		}
		else
			my_putchar(str[i]);
	}
	va_end(ap);
	return (count);
}