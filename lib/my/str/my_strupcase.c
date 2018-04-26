/*
** EPITECH PROJECT, 2017
** my_strupcase.c
** File description:
** puts in uppercase
*/
#include "my.h"

char	*my_strupcase(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		++i;
	}
	return (str);
}