/*
** EPITECH PROJECT, 2017
** my_print_alpha.c
** File description:
** prints alphabet
*/
#include "my.h"

int my_print_alpha(void)
{
	int	letter = 'a';

	while (letter <= 'z')
		my_putchar(letter++);
	return (0);
}