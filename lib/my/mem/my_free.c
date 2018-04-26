/*
** EPITECH PROJECT, 2017
** my_free.c
** File description:
** free
*/
#include "my.h"

void	my_free(void *ptr)
{
	if (ptr == NULL)
		my_print_err("Cannot free NULL pointer\n");
	free(ptr);
}
