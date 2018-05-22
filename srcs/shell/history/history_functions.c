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

static int	pos_index(t_history *tmp, char **line, int index)
{
	int		ind_tmp = index;

	while (tmp->prev != NULL)
		tmp = tmp->prev;
	while (index > 1) {
		if (tmp->next == NULL) {
			printf("%d: Event not found\n", ind_tmp);
			return (-1);
		}
		tmp = tmp->next;
		--index;
	}
	free(*line);
	*line = strdup(tmp->line);
	return (0);
}

static int	find_in_history(t_history *hist_list, char **line)
{
	t_history	*tmp = hist_list;
	int		index = recup_index(*line);
	int		ind_tmp = index;

	if (index > 0)
		return (pos_index(tmp, line, index));
	if (index < 0) {
		tmp = tmp->prev->prev;
		while (index < -1) {
			if (tmp == NULL) {
				printf("%d: Event not found\n", ind_tmp);
				return (-1);
			}
			tmp = tmp->prev;
			++index;
		}
		free(*line);
		*line = strdup(tmp->line);
	}
	return (0);
}

int	changes_from_history(t_history *hist_list, char **line)
{
	int	i = 0;
	int	tmp = 0;

	while (line[i] != NULL) {
		if (line[i][0] == '!' && line[i][1] != '\0')
			tmp  = find_in_history(hist_list, &line[i]);
		if (tmp == -1)
			return (-1);
		++i;
	}
	return (0);
}