/*
** EPITECH PROJECT, 2017
** my_show_word_array.c
** File description:
** prints word array
*/
#include "my.h"

int my_show_word_array(char * const *tab)
{
	int	i = 0;

	while (tab[i] != NULL) {
		my_putstr(tab[i]);
		my_putchar('\n');
		++i;
	}
	return (0);
}
