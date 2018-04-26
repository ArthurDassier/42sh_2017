/*
** EPITECH PROJECT, 2017
** my_realloc_nb.c
** File description:
** realloc nb
*/
#include "my.h"

int	*my_realloc_nb(int *nb, int size)
{
	int	*new;

	new = my_malloc(sizeof(char) * (size + 1));
	new = nb;
	my_free(nb);
	return (new);
}
