/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** get_builtins
*/
#include "shell.h"
#include "const_values.h"
#include <string.h>

int	get_builtins(t_node **lexer_list, char *line)
{
	if (strcmp(line, "cd") == SUCCESS || strcmp(line, "setenv") == SUCCESS
	|| strcmp(line, "unsetenv") == SUCCESS ||
	strcmp(line, "env") == SUCCESS || strcmp(line, "env") == SUCCESS ||
	strcmp(line, "exit") == SUCCESS || strcmp(line, "alias") == SUCCESS
	|| strcmp(line, "set") == 0 || strcmp(line, "history") == SUCCESS) {
		add_node(lexer_list, BUILTIN, line);
		return (SUCCESS);
	}
	return (FAILURE);
}
