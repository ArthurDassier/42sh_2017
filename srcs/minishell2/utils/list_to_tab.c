/*
** EPITECH PROJECT, 2018
** list_to_tab.c
** File description:
** transforms a linked list into an array
*/
#include "minishell2.h"

char	**list_to_tab(t_node *head)
{
	char		**tab = malloc(sizeof(*tab)
	* (get_size_list(head) + 1));
	t_node	*tmp = head;
	t_save	*data;
	int		i = 0;

	if (tab == NULL || head == NULL)
		return (NULL);
	do {
		data = (t_save *)tmp->data;
		tab[i] = malloc(sizeof(char) * (my_strlen(data->name)
		+ my_strlen(data->content) + 2));
		my_strcpy(tab[i], data->name);
		my_strcat(tab[i], "=");
		my_strcat(tab[i], data->content);
		tmp = tmp->next;
		++i;
	} while (tmp != head);
	tab[i] = 0;
	return (tab);
}