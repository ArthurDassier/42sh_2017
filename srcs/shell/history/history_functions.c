/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history_functions
*/

#include "history.h"
#include <stdlib.h>
#include <stdio.h>

void	show_history(t_history *hist_list)
{
	t_history	*tmp = hist_list;
	int		count = 1;

	while (tmp->prev != NULL)
		tmp = tmp->prev;
	while (tmp->next != NULL) {
		printf("%d\t", count++);
		printf("%s\t", tmp->line);
		printf("%s", tmp->timestamp);
		tmp = tmp->next;
	}
}

char	*find_in_history(t_history *hist_list, int index)
{
	t_history	*tmp = hist_list;

	if (index > 0) {
		while (index > 0 && tmp->next != NULL) {
			tmp = tmp->next;
			--index;
		}
		return (tmp->line);
	} else if (index < 0) {
		while (tmp->next != NULL)
			tmp = tmp->next;
		while (index < 0 && tmp->prev != NULL) {
			tmp = tmp->prev;
			++index;
		}
		return (tmp->line);
	}
	return (NULL);
}