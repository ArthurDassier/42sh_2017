/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** alias_cmd
*/

#include "42sh.h"

static void	create_aliase(t_aliases_list *tmp, char **line)
{
	tmp->next = malloc(sizeof(t_aliases_list));
	tmp = tmp->next;
	tmp->alias = malloc(sizeof(t_aliases));
	tmp->alias->src = malloc(sizeof(char) * (my_strlen(line[1]) + 1));
	tmp->alias->dest = malloc(sizeof(char) * (my_strlen(line[2]) + 1));
	my_strcpy(tmp->alias->src, line[1]);
	my_strcpy(tmp->alias->dest, line[2]);
	tmp->next = NULL;
}

static void	change_alias(t_aliases_list *tmp, char *line)
{
	free(tmp->alias->dest);
	tmp->alias->dest = malloc(sizeof(char) * (my_strlen(line) + 1));
	my_strcpy(tmp->alias->dest, line);
}

int	alias_cmd(t_aliases_list *list, char **line)
{
	int		fd = open(".42_src/aliases.txt", O_RDWR | O_APPEND);
	t_aliases_list	*tmp = list;

	while (my_strcmp(tmp->alias->src, line[1]) != 0 || tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->next == NULL)
		create_aliase(tmp, line);
	else
		change_alias(tmp, line[2]);
	tmp = list;
	while (tmp->next != NULL) {
		write(fd, tmp->alias, sizeof(t_aliases));
		tmp = tmp->next;
	}
	return (SUCCESS);
}