/*
** EPITECH PROJECT, 2018
** get_size_list.c
** File description:
** returns the size of the given list
*/
#include "list.h"

//Returns the size of the list.
int	get_size_list(t_node *head)
{
	int		i = 1;
	t_node		*tmp = head;

	if (tmp == NULL)
		return (0);
	while (tmp->next != head) {
		++i;
		tmp = tmp->next;
	}
	return (i);
}