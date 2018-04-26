/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** reverse a string
*/
#include "my.h"

char *my_revstr(char *str)
{
	char	*i = &(str[0]);
	char	*j = &(str[my_strlen(str)]) - 1;
	int	tmp;

	while (i < j) {
		tmp = *i;
		*i = *j;
		*j = tmp;
		++i;
		--j;
	}
	return (str);
}