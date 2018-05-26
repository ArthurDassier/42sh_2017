/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** recup_aliases
*/

#include "alias.h"
#include "my.h"
#include "list.h"
#include "define.h"
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_node	*recup_aliases(void)
{
	int		fd = open(".42_src/aliases.txt", O_RDONLY);
	t_node		*list = malloc(sizeof(t_node));
	t_node		*tmp = list;
	t_aliases	*alias_data = NULL;
	char		*buf = NULL;

	buf = get_next_line(fd);
	if ((tmp->data = malloc(sizeof(t_aliases))) == NULL)
		exit(FAILURE);
	alias_data = tmp->data;
	while ((alias_data->src = get_next_line(fd)) != NULL) {
		alias_data->dest = get_next_line(fd);
		if ((tmp->next = malloc(sizeof(t_node))) == NULL)
			exit(FAILURE);
		tmp = tmp->next;
		if ((tmp->data = malloc(sizeof(t_aliases))) == NULL)
			exit(FAILURE);
		alias_data = tmp->data;
		buf = get_next_line(fd);
	}
	tmp->next = NULL;
	free(buf);
	return (list);
}