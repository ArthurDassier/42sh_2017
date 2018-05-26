/*
** EPITECH PROJECT, 2018
** spec_var.c
** File description:
** spec_var
*/

#include "special_var.h"
#include "const_values.h"
#include <stdlib.h>
#include <string.h>

int	check_equal(char *line)
{
	int	i = 0;
	int	nb_equal = 0;

	while (line[i] != '\0') {
		if (line[i] == '=')
			++nb_equal;
		++i;
	}
	if (nb_equal > 1 || line[i - 1] == '=')
		return (SUCCESS);
	return (VALID);
}

void spec_var(t_save *tmp, char *line_two)
{
	if (line_two != NULL)
		tmp->content = strdup(line_two);
	else
		tmp->content = NULL;
}
