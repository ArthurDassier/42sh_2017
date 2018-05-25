/*
** EPITECH PROJECT, 2017
** chainlist.c
** File description:
** blabla
*/

#include "42sh.h"

list_var *insert_end_var(list_var **first_elem, char *name, char *content)
{
	list_var	*new_elem = malloc(sizeof(list_var));
	list_var	*actual = (*first_elem);

	if (new_elem == NULL)
		return (NULL);
	new_elem->name = strdup(name);
	if (content != NULL)
		new_elem->content = strdup(content);
	else
		new_elem->content = NULL;
	new_elem->next = NULL;
	while (actual->next != NULL
	&& alphabetic_order(new_elem->name, actual->next->name) != SUCCESS)
		actual = actual->next;
	if (actual->next == NULL)
		actual->next = new_elem;
	else if (actual != (*first_elem)) {
		new_elem->next = actual->next;
		actual->next = new_elem;
	} else {
		new_elem->next = *first_elem;
		(*first_elem) = new_elem;
		return (new_elem);
	}
	return (actual);
}

void print_var(list_var *liste)
{
	list_var	*temp;

	temp = liste;
	while (temp != NULL) {
		my_printf("%s", temp->name);
		if (temp->content != NULL)
			my_printf("\t%s", temp->content);
		my_putchar('\n');
		temp = temp->next;
	}
}
