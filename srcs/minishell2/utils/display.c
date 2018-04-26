/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** display
*/
#include "minishell2.h"

void	display(void *data)
{
	t_parser *parser = (t_parser *)data;

	my_printf("token = %d & name = %s\n", parser->token, parser->name);
}