/*
** EPITECH PROJECT, 2018
** my_strisalphanum.c
** File description:
** alphanum return
*/
#include "my.h"

int	my_strisalphanum(char *str)
{
	if (str[0] == 0)
		return (0);
	for (int i = 0; str[i]; ++i) {
		if (my_char_is_alphanum(str[i]) == 0)
			return (0);
	}
	return (1);
}
