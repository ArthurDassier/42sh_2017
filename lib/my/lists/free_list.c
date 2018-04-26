/*
** EPITECH PROJECT, 2017
** free_list.c
** File description:
** function to free the list
*/
#include "list.h"

//Frees the circular doubly linked list.
void	free_list(t_node *list, void (*ptr)(void *data))
{
	t_node	*tmp = list;
	t_node	*next;
	int		size = get_size_list(list);

	for (int i = 0; i < size; ++i) {
		ptr(tmp->data);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}