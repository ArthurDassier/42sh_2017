/*
** EPITECH PROJECT, 2017
** my_str_isupper.c
** File description:
** str is upper
*/
#include "my.h"

int my_str_isupper(char const *str)
{
	int	i = 0;

	while (str[i]) {
		if (!(str[i] >= 65 && str[i] <= 90))
			return (0);
		i++;
	}
	return (1);
}