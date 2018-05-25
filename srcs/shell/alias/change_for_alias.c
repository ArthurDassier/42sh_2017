/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** change_for_alias
*/

#include "alias.h"
#include "define.h"
#include <string.h>
#include <stdlib.h>

static t_aliases	*check_for_alias(t_aliases_list *list, char *line)
{
	t_aliases_list	*tmp = list;

	while (tmp->next != NULL) {
		if (strcmp(tmp->alias->src, line) == SUCCESS)
			break;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (NULL);
	return (tmp->alias);
}

static char	*new_str(t_aliases *alias, char	*line)
{
	if (!alias)
		return (line);
	free(line);
	if ((line = malloc(sizeof(char) *
	(strlen(alias->dest) + 1))) == NULL)
		exit(FAILURE);
	strcpy(line, alias->dest);
	return (line);
}

void	change_for_alias(t_aliases_list *list, char **line)
{
	for (int i = 0; line[i] != NULL; ++i)
		line[i] = new_str(check_for_alias(list, line[i]), line[i]);
}