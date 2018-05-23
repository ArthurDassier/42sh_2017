/*
** EPITECH PROJECT, 2018
** special_var_utils.c
** File description:
** Arthur
*/

#include "42sh.h"

int	alphabetic_order(char *line_one, char *line_two)
{
	int	i = 0;

	while (line_one[i] != '\0' && line_two[i] != '\0') {
		if (line_one[i] < line_two[i])
			return (0);
		if (line_one[i] > line_two[i])
			return (1);
		++i;
	}
	if (line_one[i] == '\0' && line_two[i] != '\0')
		return (0);
	return (1);
}
