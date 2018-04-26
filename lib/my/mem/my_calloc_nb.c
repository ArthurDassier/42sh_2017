/*
** EPITECH PROJECT, 2018
** Library
** File description:
** my_alloc_nb.
*/
#include "my.h"

int	*my_calloc_nb(int size)
{
	int	*new;

	if ((new = my_malloc(size)) == NULL)
		return (NULL);
	for (int i = 0; i < size; ++i)
		new[i] = 0;
	return (new);
}