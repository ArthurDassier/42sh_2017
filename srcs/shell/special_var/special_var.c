/*
** EPITECH PROJECT, 2018
** special_var.c
** File description:
** Arthur
*/

#include "42sh.h"

void	change_var(char **line, list_var **spec)
{
	int	i = 1;

	while (line[i]) {
		if (line[i + 1][0] != '=') {
			insert_end_var(spec, line[i], NULL);
			++i;
		} else {
			insert_end_var(spec, line[i], line[i + 2]);
			i += 3;
		}
	}
}

int	special_var(char **line, list_var **spec)
{
	int	i = 0;

	while (line[i])
		++i;
	if (i == 1)
		print_var(*spec);
	else if (i > 1)
		change_var(line, spec);
	return (SUCCESS);
}
