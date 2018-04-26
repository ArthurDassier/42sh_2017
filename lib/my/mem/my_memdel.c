/*
** EPITECH PROJECT, 2018
** my_memdel.c
** File description:
** memdel.c
*/
#include "my.h"

void	my_memdel(void **ap)
{
	if (ap && *ap) {
		free(*ap);
		*ap = NULL;
	}
}
