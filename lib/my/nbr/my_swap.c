/*
** EPITECH PROJECT, 2017
** my_swap.c
** File description:
** swap values
*/
#include "my.h"

void my_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}