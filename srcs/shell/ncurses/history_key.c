/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history_key
*/

#include "history.h"
#include "line.h"
#include "ncurses_define.h"
#include "list.h"
#include "define.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	history_up(__attribute((unused)) char **line,
__attribute((unused)) const char *prompt,
__attribute((unused)) t_node **hist_list)
{
	static char	cache[] = "                                          ";
	int		len = 0;
	t_history	*hist_data = NULL;

	if (*hist_list == NULL || (*hist_list)->prev == NULL)
		return (SUCCESS);
	*hist_list = (*hist_list)->prev;
	len = strlen(prompt) + strlen(*line);
	cursorbackward(len);
	fflush(stdout);
	write(1, prompt, strlen(prompt));
	hist_data = (t_history *)(*hist_list)->data;
	write(1, hist_data->line, strlen(hist_data->line));
	write(1, cache, strlen(cache));
	len = strlen(cache);
	cursorbackward(len);
	fflush(stdout);
	free(*line);
	*line = strdup(hist_data->line);
	return (VALID);
}

int	history_down(__attribute((unused)) char **line,
__attribute((unused)) const char *prompt,
__attribute((unused)) t_node **hist_list)
{
	static char	cache[] = "                                          ";
	int		len = 0;
	t_history	*hist_data = NULL;

	if ((*hist_list)->next == NULL || (*hist_list)->next->next == NULL)
		return (SUCCESS);
	*hist_list = (*hist_list)->next;
	len = strlen(prompt) + strlen(*line);
	cursorbackward(len);
	fflush(stdout);
	write(1, prompt, strlen(prompt));
	hist_data = (t_history *)(*hist_list)->data;
	write(1, hist_data->line, strlen(hist_data->line));
	write(1, cache, strlen(cache));
	len = strlen(cache);
	cursorbackward(len);
	fflush(stdout);
	free(*line);
	*line = strdup(hist_data->line);
	return (VALID);
}