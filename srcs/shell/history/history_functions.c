/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history_functions
*/

#include "history.h"
#include "define.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	show_history(t_node *hist_list)
{
	t_node		*tmp = hist_list;
	t_history	*hist_data = NULL;
	int		count = 1;

	while (tmp->prev != NULL)
		tmp = tmp->prev;
	while (tmp->next != NULL) {
		hist_data = (t_history *)tmp->data;
		printf("%d\t", count++);
		printf("%s\t", hist_data->line);
		printf("%s", hist_data->timestamp);
		tmp = tmp->next;
	}
	return (VALID);
}


static int	pos_index(t_node *tmp, char **line, int index)
{
	int		ind_tmp = index;
	t_history	*hist_data = NULL;

	while (tmp->prev != NULL)
		tmp = tmp->prev;
	while (index > 1) {
		if (tmp->next == NULL) {
			printf("%d: Event not found\n", ind_tmp);
			return (ERROR);
		}
		tmp = tmp->next;
		--index;
	}
	free(*line);
	hist_data = (t_history *)tmp->data;
	*line = strdup(hist_data->line);
	return (SUCCESS);
}

static int	find_in_history(t_node *hist_list, char **line)
{
	t_node		*tmp = hist_list;
	t_history	*hist_data = NULL;
	int		index = recup_index(*line);
	int		ind_tmp = index;

	if (index > 0)
		return (pos_index(tmp, line, index));
	if (index == 0)
		return (print_no_event(ind_tmp));
	if (tmp->prev == NULL || (tmp = tmp->prev->prev) == NULL)
		return (print_no_event(ind_tmp));
	while (index < -1) {
		if (tmp == NULL || tmp->prev == NULL)
			return (print_no_event(ind_tmp));
		tmp = tmp->prev;
		++index;
	}
	free(*line);
	hist_data = (t_history *)tmp->data;
	*line = strdup(hist_data->line);
	return (SUCCESS);
}

static void	change_in_history_from_ex(t_node **hist_list, char *buffer,
int flag)
{
	t_history	*hist_data = NULL;

	if (flag == VALID) {
		hist_data = (t_history *)(*hist_list)->prev->data;
		free(hist_data->line);
		hist_data->line = strdup(buffer);
		write(1, buffer, strlen(buffer));
		write(1, "\n", 1);
	}
}

int	changes_from_history(t_node **hist_list, char **line)
{
	t_node		*hist_tmp = *hist_list;
	int		i = 0;
	int		tmp = 0;
	char		*buffer = malloc(sizeof(char));
	int		flag = 0;

	buffer[0] = '\0';
	while (line[i] != NULL) {
		if (line[i][0] == '!' && line[i][1] != '\0') {
			if ((tmp  = find_in_history(hist_tmp, &line[i])) == ERROR)
				return (ERROR);
			flag = 1;
		}
		buffer = realloc(buffer,
		strlen(buffer) + strlen(line[i]) + 2);
		buffer = strcat(buffer, line[i]);
		buffer = strcat(buffer, " ");
		++i;
	}
	change_in_history_from_ex(hist_list, buffer, flag);
	return (SUCCESS);
}