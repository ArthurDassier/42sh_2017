/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history_functions
*/

#include "history.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	show_history(t_history *hist_list)
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
	return (1);
}

static int	recup_index(char *line)
{
	int	i = 0;

	while (line[i] != '\0') {
		line[i] = line[i + 1];
		++i;
	}
	return (atoi(line));
}

int	find_in_history(t_history *hist_list, char **line)
{
	t_history	*tmp = hist_list;
	int		index = recup_index(line[0]);

	if (index == -1)
		return (0);
	if (index > 0) {
		while (tmp->prev != NULL)
			tmp = tmp->prev;
		while (index >= 0 && tmp->next != NULL) {
			tmp = tmp->next;
			--index;
		}
		free(line[0]);
		line[0] = strdup(tmp->line);
		printf("%s\n", line[0]);
		return (1);
	} else if (index < 0) {
		while (tmp->next != NULL)
			tmp = tmp->next;
		while (index < 0 && tmp->prev != NULL) {
			tmp = tmp->prev;
			++index;
		}
		free(line[0]);
		line[0] = strdup(tmp->line);
		return (1);
	}
	return (0);
}