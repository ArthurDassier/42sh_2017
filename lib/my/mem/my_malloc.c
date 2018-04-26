/*
** EPITECH PROJECT, 2017
** my_malloc.c
** File description:
** malloc function
*/
#include "my.h"

void	*my_malloc(int size)
{
	void	*str = malloc(size);

	if (str == NULL) {
		my_print_err("Error: null pointer\n");
		return (NULL);
	}
	return (str);
}