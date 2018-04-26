/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** get_cmd
*/
#include "minishell2.h"

static void add_cmd(char **path, char *line)
{
	char	*save;

	for (int i = 0; path != NULL && path[i] != NULL; ++i) {
		save = malloc(sizeof(char) * (my_strlen(path[i])
		+ my_strlen(line) + 2));
		my_strcpy(save, path[i]);
		my_strcat(save, "/");
		my_strcat(save, line);
		free(path[i]);
		path[i] = save;
	}
}

void	get_cmd(t_node **lexer, char *line, char **path)
{
	int	check = 0;

	add_cmd(path, line);
	for (int i = 0; path != NULL && path[i] != NULL; ++i) {
		if (access(path[i], F_OK) != -1) {
			add_node(lexer, CMD, line);
			check += 1;
			break;
		}
	}
	if (check == 0)
		add_node(lexer, WORD, line);
}