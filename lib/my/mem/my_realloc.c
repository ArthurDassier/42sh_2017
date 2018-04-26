/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** my_realloc_str
*/
#include "my.h"

void	*my_realloc(void *data, int size)
{
	char	*new;

	new = malloc(sizeof(char) * (size));
	if (new == NULL)
		return (NULL);
	my_memcpy(data, new, size);
	my_free(data);
	return (new);
}