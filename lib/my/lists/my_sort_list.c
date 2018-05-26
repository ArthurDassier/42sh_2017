/*
** EPITECH PROJECT, 2017
** sorting_linked_list.c
** File description:
** bubble sort for linked list
*/
#include "list.h"

//Swaps the content of two nodes.
static	void my_sort_swap(t_node *node_1, t_node *node_2)
{
	void	*tmp = node_1->data;

	node_1->data = node_2->data;
	node_2->data = tmp;

}

void sort_ptr(t_node *tmp, int (*ptr)(void *data, void *data_2), int *swap)
{
	if (ptr(tmp->data, tmp->next->data) == 1) {
		my_sort_swap(tmp, tmp->next);
		++*swap;
	}
}

//Bubble sort for linked list.
void	my_sort_list(t_node *list, int (*ptr)(void *data, void *data_2))
{
	int		i;
	int	 	size = get_size_list(list);
	int		swap = 1;
	t_node		*tmp;

	while (swap != 0) {
		swap = 0;
		i = 0;
		tmp = list;
		while (tmp->next != list && i + 1 < size) {
			sort_ptr(tmp, ptr, &swap);
			tmp = tmp->next;
			++i;
		}
	}
}
