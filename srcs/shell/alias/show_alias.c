/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** show_alias
*/

#include "list.h"
#include "alias.h"
#include "const_values.h"
#include <stdio.h>

int	show_alias(t_node *list)
{
	t_node		*tmp = list;
	t_aliases	*aliases_data = NULL;

	if (tmp == NULL)
		return (SUCCESS);
	while (tmp->next != NULL) {
		aliases_data = (t_aliases *)tmp->data;
		printf("%s\t%s\n", aliases_data->src, aliases_data->dest);
		tmp = tmp->next;
	}
	return (SUCCESS);
}