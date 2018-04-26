/*
** EPITECH PROJECT, 2017
** create_list.c
** File description:
** circular doubly linked list
*/
#include "list.h"

//Inserts at the beginning.
static	void insert_begin(t_node **head, void *data)
{
	t_node	*new_node = malloc(sizeof(t_node));

	new_node->next = new_node->prev = new_node;
	new_node->data = data;
	*head = new_node;
}

//Inserts at the end.
void	insert_end(t_node **head, void *data)
{
	t_node	*new_node = malloc(sizeof(t_node));
	t_node	*last;

	if (*head == NULL)
		insert_begin(head, data);
	else {
		last = (*head)->prev;
		new_node->next = *head;
		(*head)->prev = new_node;
		new_node->prev = last;
		last->next = new_node;
		new_node->data = data;
	}
}