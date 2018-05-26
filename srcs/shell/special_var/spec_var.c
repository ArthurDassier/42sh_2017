/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** spec_var
*/

#include "special_var.h"
#include <stdlib.h>
#include <string.h>

void spec_var(t_save *tmp, char *line_two)
{
	if (line_two != NULL)
		tmp->content = strdup(line_two);
	else
		tmp->content = NULL;
}
