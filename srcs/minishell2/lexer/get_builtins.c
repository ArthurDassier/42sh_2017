/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** get_builtins
*/
#include "minishell2.h"

int	get_builtins(t_node **lexer_list, char *line)
{
	if (my_strcmp(line, "cd") == 0 || my_strcmp(line, "setenv") == 0
	|| my_strcmp(line, "unsetenv") == 0 || my_strcmp(line, "env") == 0
	|| my_strcmp(line, "env") == 0 || my_strcmp(line, "exit") == 0) {
		add_node(lexer_list, BUILTIN, line);
		return (SUCCESS);
	}
	return (FAILURE);
}