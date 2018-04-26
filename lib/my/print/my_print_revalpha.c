/*
** EPITECH PROJECT, 2017
** my_print_revalpha.c
** File description:
** prints rev alphabet
*/
#include "my.h"

int my_print_revalpha(void)
{
	int	letter = 'z';

	while (letter >= 'a') {
		my_putchar(letter);
		--letter;
	}
	return (0);
}
