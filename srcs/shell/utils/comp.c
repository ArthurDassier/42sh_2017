/*
** EPITECH PROJECT, 2018
** comp.c
** File description:
** comp function
*/
#include "42sh.h"

int	cmp(void *data, void *data_cmp)
{
	t_save *tmp = (t_save *)data;
	char *tmp_2 = (char *)data_cmp;

	if (my_strcmp(tmp->name, tmp_2) == SUCCESS)
		return (VALID);
	return (SUCCESS);
}