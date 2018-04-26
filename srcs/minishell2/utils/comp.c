/*
** EPITECH PROJECT, 2018
** comp.c
** File description:
** comp function
*/
#include "minishell2.h"

int	cmp(void *data, void *data_cmp)
{
	t_save *tmp = (t_save *)data;
	char *tmp_2 = (char *)data_cmp;

	if (my_strcmp(tmp->name, tmp_2) == 0)
		return (1);
	return (0);
}