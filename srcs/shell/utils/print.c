/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** print function
*/
#include "42sh.h"

void	print_list(void *data)
{
	t_save *tmp = (t_save *)data;

	my_printf("%s=%s\n", tmp->name, tmp->content);
}

void	print_list_with_null(void *data)
{
	t_save *tmp = (t_save *)data;

	my_printf("%s=%s", tmp->name, tmp->content);
}