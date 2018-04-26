/*
** EPITECH PROJECT, 2017
** my_str_isprintable.c
** File description:
** checks if str is printable
*/
#include "my.h"

int	my_str_isprintable(char const *str)
{
	int	i = 0;

	while (str[i]) {
		if (!(str[i] > 32 && str[i] < 127))
			return (0);
		i++;
	}
	return (1);
}