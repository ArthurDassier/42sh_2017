/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** change_for_alias
*/

#include "alias.h"
#include "const_values.h"
#include "list.h"
#include <string.h>
#include <stdlib.h>

static t_aliases	*check_for_alias(t_node *list, char *line)
{
	t_node		*tmp = list;
	t_aliases	*alias_data = NULL;

	while (tmp->next != NULL) {
		alias_data = (t_aliases *)tmp->data;
		if (strcmp(alias_data->src, line) == SUCCESS)
			break;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (NULL);
	return (alias_data);
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

void	change_for_alias(t_node *list, char **line)
{
	for (int i = 0; line[i] != NULL; ++i)
		line[i] = new_str(check_for_alias(list, line[i]), line[i]);
}