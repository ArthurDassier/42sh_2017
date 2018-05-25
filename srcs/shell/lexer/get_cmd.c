/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** get_cmd
*/
#include "42sh.h"
#include <string.h>
#include <stdlib.h>

static void add_cmd(char **path, char *line)
{
	char	*save;

	for (int i = 0; path != NULL && path[i] != NULL; ++i) {
		save = malloc(sizeof(char) * (strlen(path[i])
		+ strlen(line) + 2));
		if (!save)
			exit(FAILURE);
		strcpy(save, path[i]);
		strcat(save, "/");
		strcat(save, line);
		free(path[i]);
		path[i] = save;
	}
}

void	get_cmd(t_node **lexer, char *line, char **path)
{
	int	check = 0;

	add_cmd(path, line);
	for (int i = 0; path != NULL && path[i] != NULL; ++i) {
		if (access(path[i], F_OK) != ERROR) {
			add_node(lexer, CMD, line);
			check += 1;
			break;
		}
	}
	if (check == SUCCESS)
		add_node(lexer, WORD, line);
}