/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** utils functions
*/
#include "printf.h"

int verif_flag(char const *str, int size, int check)
{
	int	j;

	for (j = 0; j < NB_FLAGS
		&& my_strncmp((tab[j].flag) + check, str, size) != 0; ++j);
	return (j);
}

int counting(int nb)
{
	int	i = 0;

	while (nb) {
		nb = nb / 10;
		++i;
	}
	return (i);
}

int get_flag(char const *str)
{
	int	i = 0;

	for (i = 0; str[i] && my_char_is_alpha(str[i]) == 0; ++i);
	return (i);
}