/*
** EPITECH PROJECT, 2018
** Library
** File description:
** my_calloc.c
*/
#include "my.h"

void	*my_calloc(int size)
{
	char	*new;

	if ((new = my_malloc(size)) == NULL)
		return (NULL);
	for (int i = 0; i < size; ++i)
		new[i] = 0;
	return (new);
}