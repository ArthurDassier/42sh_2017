/*
** EPITECH PROJECT, 2018
** find_node.c
** File description:
** return the node found
*/
#include "list.h"

t_node	*find_node(t_node *head, int (*cmp)(void *data,
	void *data_cmp), void *to_find)
{
	t_node *tmp = head;

	do {
		if (cmp(tmp->data, to_find) == 1)
			return (tmp);
		tmp = tmp->next;
	} while (tmp != head);
	return (NULL);
}