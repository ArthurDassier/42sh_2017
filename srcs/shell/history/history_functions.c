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
#include <unistd.h>

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

static void	change_in_history_from_ex(t_history **hist_list, char *buffer,
int flag)
{
	if (flag == 1) {
		free((*hist_list)->prev->line);
		(*hist_list)->prev->line = strdup(buffer);
		write(1, buffer, strlen(buffer));
		write(1, "\n", 1);
	}
}

int	changes_from_history(t_history **hist_list, char **line)
{
	t_history	*hist_tmp = *hist_list;
	int		i = 0;
	int		tmp = 0;
	char		*buffer = malloc(sizeof(char));
	int		flag = 0;

	buffer[0] = '\0';
	while (line[i] != NULL) {
		if (line[i][0] == '!' && line[i][1] != '\0') {
			if ((tmp  = find_in_history(hist_tmp, &line[i])) == -1)
				return (-1);
			flag = 1;
		}
		buffer = realloc(buffer,
		strlen(buffer) + strlen(line[i]) + 2);
		buffer = strcat(buffer, line[i]);
		buffer = strcat(buffer, " ");
		++i;
	}
	change_in_history_from_ex(hist_list, buffer, flag);
	return (0);
}