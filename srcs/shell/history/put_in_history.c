/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** put_in_history
*/

#include "my.h"
#include "history.h"
#include "const_values.h"
#include "list.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void	write_in_history(t_history *hist_data)
{
	static int	count = 1;
	static char	ct = '\t';
	static int	fd = 0;

	if (fd == SUCCESS) {
		fd = open(".shell_src/history.txt", O_WRONLY |
		O_CREAT, S_IWUSR | S_IRUSR);
	}
	write(fd, my_itoa(count), strlen(my_itoa(count)));
	write(fd, &ct, 1);
	if (hist_data->line != NULL)
		write(fd, hist_data->line, strlen(hist_data->line));
	write(fd, &ct, 1);
	write(fd, hist_data->timestamp, strlen(hist_data->timestamp));
	++count;
}

static void	first_node(t_node **list, char *line, char *timestamp)
{
	t_node		*tmp = NULL;
	t_history	*hist_data = NULL;

	if ((*list = malloc(sizeof(t_node))) == NULL)
		exit(FAILURE);
	if (((*list)->data = malloc(sizeof(t_history))) == NULL)
		exit(FAILURE);
	hist_data = (t_history *)(*list)->data;
	hist_data->line = strdup(line);
	hist_data->timestamp = strdup(timestamp);
	write_in_history(hist_data);
	(*list)->prev = NULL;
	if (((*list)->next = malloc(sizeof(t_node))) == NULL)
		exit(FAILURE);
	tmp = *list;
	*list = (*list)->next;
	(*list)->next = NULL;
	(*list)->prev = tmp;
}

void	put_in_history(t_node **list, char *line)
{
	time_t		timestamp = time(NULL);
	t_node		*tmp = NULL;
	t_history	*hist_data = NULL;

	if (*list == NULL) {
		first_node(list, line, ctime(&timestamp));
		return;
	}
	if (line == NULL)
		return;
	(*list)->data = malloc(sizeof(t_history));
	hist_data = (t_history *)(*list)->data;
	hist_data->line = strdup(line);
	hist_data->timestamp = strdup(ctime(&timestamp));
	write_in_history(hist_data);
	(*list)->next = malloc(sizeof(t_node));
	tmp = *list;
	*list = (*list)->next;
	(*list)->prev = tmp;
	(*list)->next = NULL;
}