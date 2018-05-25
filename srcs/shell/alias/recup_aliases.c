/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** recup_aliases
*/

#include "42sh.h"
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_aliases_list	*recup_aliases(void)
{
	int		fd = open(".42_src/aliases.txt", O_RDONLY);
	t_aliases_list	*list = malloc(sizeof(t_aliases_list));
	t_aliases_list	*tmp = list;
	char		*buf = NULL;

	buf = get_next_line(fd);
	tmp->alias = malloc(sizeof(t_aliases));
	while ((tmp->alias->src = get_next_line(fd)) != NULL) {
		tmp->alias->dest = get_next_line(fd);
		tmp->next = malloc(sizeof(t_aliases_list));
		tmp = tmp->next;
		tmp->alias = malloc(sizeof(t_aliases));
		buf = get_next_line(fd);
	}
	tmp->next = NULL;
	free(buf);
	return (list);
}