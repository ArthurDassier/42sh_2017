/*
** EPITECH PROJECT, 2018
** env.c
** File description:
** env functions
*/
#include "42sh.h"

char	*get_env_name(t_node *head, char *name)
{
	t_node	*tmp = head;
	t_save	*content;

	if (head == NULL)
		return (NULL);
	do {
		content = (t_save *)tmp->data;
		tmp = tmp->next;
		if (my_strcmp(content->name, name) == 0)
			return (content->name);
	} while (tmp != head);
	return (NULL);
}

char	*get_env_content(t_node *head, char *name)
{
	t_node	*tmp = head;
	t_save	*content;

	if (head == NULL)
		return (NULL);
	do {
		content = (t_save *)tmp->data;
		tmp = tmp->next;
		if (my_strcmp(content->name, name) == 0)
			return (content->content);
	} while (tmp != head);
	return (NULL);
}

bool	check_env_name(t_node *head, char *name)
{
	t_node	*tmp = head;
	t_save	*content;

	if (head == NULL)
		return (false);
	do {
		content = (t_save *)tmp->data;
		tmp = tmp->next;
		if (my_strcmp(content->name, name) == 0)
			return (true);
	} while (tmp != head);
	return (false);
}