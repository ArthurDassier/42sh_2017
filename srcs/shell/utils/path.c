/*
** EPITECH PROJECT, 2018
** path.c
** File description:
** path functions
*/
#include "shell.h"
#include "const_values.h"
#include <stdlib.h>
#include <string.h>

static int check_double_slash(char **path)
{
	for (int i = 0; path[i]; ++i) {
		if (strncmp(path[i], "//", 2) == SUCCESS)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	check_path(char **line, char **path, t_node *env_list)
{
	int	i;

	for (i = 0; path != NULL && path[i] != 0; ++i) {
		add_com(path, line);
		if (check_double_slash(path) == FAILURE)
			return (FAILURE);
		exec_com(path, line, env_list);
	}
	return (i);
}

char	**get_path(t_node *head)
{
	t_node	*tmp = head;
	t_save	*content;
	char		**path;

	if (!head)
		return (NULL);
	do {
		content = (t_save *)tmp->data;
		tmp = tmp->next;
		if (strcmp(content->name, "PATH") == SUCCESS)
			break;
	} while (tmp != head);
	path = delim_lexem(content->content, ":");
	return (path);
}

void	exec_com(char **path, char **line, t_node *head)
{
	for (int i = 0; path != NULL && path[i] != NULL; ++i) {
		if (access(path[i], F_OK) != ERROR)
			check_perm(path, line, i, head);
	}
}

void	add_com(char **path, char **line)
{
	char	*save;

	for (int i = 0; path != NULL && path[i] != NULL; ++i) {
		save = malloc(sizeof(char) * (strlen(path[i])
		+ strlen(line[0]) + 2));
		strcpy(save, path[i]);
		strcat(save, "/");
		strcat(save, line[0]);
		free(path[i]);
		path[i] = save;
	}
}