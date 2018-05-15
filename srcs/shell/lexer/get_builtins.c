/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** get_builtins
*/
#include "42sh.h"

int	get_builtins(t_node **lexer_list, char *line)
{
	if (strcmp(line, "cd") == 0 || strcmp(line, "setenv") == 0
	|| strcmp(line, "unsetenv") == 0 || strcmp(line, "env") == 0
	|| strcmp(line, "env") == 0 || strcmp(line, "exit") == 0) {
		add_node(lexer_list, BUILTIN, line);
		return (SUCCESS);
	}
	return (FAILURE);
}