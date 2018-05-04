/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** change_for_alias
*/

#include "42sh.h"

static t_aliases	*check_for_alias(t_aliases_list *list, char *line)
{
	t_aliases_list	*tmp = list;

	while (tmp != NULL) {
		if (my_strcmp(tmp->alias->src, line) == 0)
			break;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (NULL);
	return (tmp->alias);
}

static char	*new_str(t_aliases *alias, char	*line)
{
	if (alias == NULL)
		return (line);
	free(line);
	if ((line = malloc(sizeof(char) *
	(my_strlen(alias->dest) + 1))) == NULL)
		exit(84);
	my_strcpy(line, alias->dest);
	return (line);
}

void	change_for_alias(t_aliases_list *list, char **line)
{
	for (int i = 0; line[i] != NULL; ++i)
		line[i] = new_str(check_for_alias(list, line[i]), line[i]);
}
