/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** print function
*/
#include "minishell2.h"

void	print_list(void *data)
{
	t_save *tmp = (t_save *)data;

	my_printf("%s=%s\n", tmp->name, tmp->content);
}