/*
** EPITECH PROJECT, 2018
** change_var.c
** File description:
** Arthur
*/

#include "42sh.h"
#include <stdlib.h>
#include <string.h>

void spec_var(t_save *tmp, char *line_two)
{
	if (line_two != NULL)
		tmp->content = strdup(line_two);
	else
		tmp->content = NULL;
}
