/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** recup_aliases
*/

#include "42sh.h"

t_aliases_list	*recup_aliases_list(void)
{
	int		fd = open(".42_src/aliases.txt", O_RDONLY, O_APPEND);
	t_aliases_list	*list = malloc(sizeof(t_aliases_list));
	t_aliases_list	*tmp = list;

	tmp->alias = malloc(sizeof(t_aliases));
	while (read(fd, tmp->alias, sizeof(t_aliases)) != 0) {
		tmp->next = malloc(sizeof(t_aliases_list));
		tmp = tmp->next;
		tmp->alias = malloc(sizeof(t_aliases));
	}
	tmp->next = NULL;
	return (list);
}