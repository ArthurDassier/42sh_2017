/*
** EPITECH PROJECT, 2018
** path.c
** File description:
** path functions
*/
#include "42sh.h"
#include "define.h"
#include <stdlib.h>
#include <string.h>

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
		if (access(path[i], F_OK) != -1)
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