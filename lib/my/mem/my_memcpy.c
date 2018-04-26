/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** my_memcpy
*/
#include "my.h"

void	my_memcpy(void *cpy_from, void *cpy_to, size_t size)
{
	char	*cpf = cpy_from;
	char	*cpt = cpy_to;

	for (size_t i = 0; i < size; ++i)
		cpt[i] = cpf[i];
}