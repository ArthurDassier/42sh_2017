/*
** EPITECH PROJECT, 2017
** my_strarraylen.c
** File description:
** return array length
*/
#include "my.h"

int my_strarraylen(char **array)
{
	int	i = 0;

	if (array[i] == NULL)
		my_print_err("String pointer is NULL\n");
	while (array[i] != NULL)
		++i;
	return (i);
}
