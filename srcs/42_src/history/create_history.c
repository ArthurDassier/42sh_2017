/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** create_history
*/

#include "42sh.h"
#include <time.h>

static void add_history_info(t_history *history, char *line, int count)
{
	time_t	actuel = time(NULL);

	if (history == NULL)
		return;
	history->count = count;
	history->line = malloc(sizeof(char) * (my_strlen(line) + 1));
	if (history->line == NULL)
		return;
	my_strcpy(history->line, line);
	history->timestamp = malloc(sizeof(char) * (my_strlen(ctime(&actuel)) + 1));
	if (history->timestamp == NULL)
		return;
	my_strcpy(history->timestamp, ctime(&actuel));
}

void add_in_history(t_history_list *hist_list, char *line)
{
	t_history_list	*tmp = hist_list;
	static int	count = 1;
	int		fd = open(".42_src/history.txt", O_RDWR | O_APPEND);

	while (tmp != NULL)
		tmp = tmp->next;
	tmp = malloc(sizeof(t_history_list));
	tmp->history = malloc(sizeof(t_history));
	add_history_info(tmp->history, line, count);
	tmp->next = NULL;
	write(fd, my_itoa(tmp->history->count),
	my_strlen(my_itoa(tmp->history->count)));
	write(fd, "\t", 1);
	write(fd, tmp->history->line, my_strlen(tmp->history->line));
	write(fd, "\t", 1);
	write(fd, tmp->history->timestamp, my_strlen(tmp->history->timestamp));
	++count;
}
