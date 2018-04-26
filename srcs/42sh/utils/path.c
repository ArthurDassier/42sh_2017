/*
** EPITECH PROJECT, 2018
** path.c
** File description:
** path functions
*/
#include "42sh.h"

char	**get_path(t_node *head)
{
	t_node	*tmp = head;
	t_save	*content;
	char		**path;

	if (head == NULL)
		return (NULL);
	do {
		content = (t_save *)tmp->data;
		tmp = tmp->next;
		if (my_strcmp(content->name, "PATH") == 0)
			break;
	} while (tmp != head);
	path = my_str_to_wordtab_delim(content->content, ":");
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
		save = malloc(sizeof(char) * (my_strlen(path[i])
		+ my_strlen(line[0]) + 2));
		my_strcpy(save, path[i]);
		my_strcat(save, "/");
		my_strcat(save, line[0]);
		free(path[i]);
		path[i] = save;
	}
}