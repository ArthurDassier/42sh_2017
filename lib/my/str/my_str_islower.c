/*
** EPITECH PROJECT, 2017
** my_str_islower.c
** File description:
** checks if str is lowercase
*/
#include "my.h"

int my_str_islower(char const *str)
{
	int i = 0;

	while (str[i]) {
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		++i;
	}
	return (1);
}