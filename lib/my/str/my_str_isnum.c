/*
** EPITECH PROJECT, 2017
** my_str_isnum.c
** File description:
** checks if str is only num
*/
#include "my.h"

int my_str_isnum(char const *str)
{
	int	i = 0;

	while (str[i]) {
		if (!((str[i] >= '0' && str[i] <= '9')
		|| (str[i] == '-' || str[i] == '+')))
			return (0);
		++i;
	}
	return (1);
}