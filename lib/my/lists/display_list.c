/*
** EPITECH PROJECT, 2017
** display_list.c
** File description:
** displas list
*/
#include "list.h"
#include <stdio.h>
//Displays the list.
void	display_list(t_node *head, void (*ptr)(void *data))
{
	t_node	*tmp = head;

	if (head == NULL)
		return;
	do {
		ptr(tmp->data);
		tmp = tmp->next;
	} while (tmp != head);
}

//Displays the list in reverse order.
void	display_reverse(t_node *head, void (*ptr)(void *data))
{
	t_node	*tmp = head->prev;

	do {
		ptr(tmp->data);
		tmp = tmp->prev;
	} while (tmp != head);
}