/*
** EPITECH PROJECT, 2017
** my_strlowcase.c
** File description:
** checks if lowercase
*/
#include "my.h"

char *my_strlowcase(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		++i;
	}
	return (str);
}