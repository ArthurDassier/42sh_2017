/*
** EPITECH PROJECT, 2017
** my_print_digits.c
** File description:
** prints digits
*/
#include "my.h"

int my_print_digits(void)
{
	int n = 48;

	while (n <= 57)
		my_putchar(n++);
	return (0);
}