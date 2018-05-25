/*
** EPITECH PROJECT, 2018
** delete_node.c
** File description:
** function to delete a given node
*/
#include "42sh.h"
#include <stdlib.h>
#include <string.h>

void	delete_node(t_node **head, char *name)
{
	t_node *curr = *head;

	if (*head == NULL)
		return;
	curr = find_node(*head, &cmp, name);
	if (curr->next == *head && curr->prev == *head) {
		free(*head);
		*head = NULL;
		return;
	}
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	if (curr == *head)
		(*head) = curr->next;
	free(curr);
	return;
}