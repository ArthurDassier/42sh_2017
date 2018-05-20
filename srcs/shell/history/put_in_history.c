/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** put_in_history
*/

#include "my.h"
#include "history.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void	write_in_history(t_history *list)
{
	static int	count = 1;
	static char	ct = '\t';
	static int	fd = 0;

	if (fd == 0) {
		fd = open(".42_src/history.txt", O_WRONLY |
		O_CREAT, S_IWUSR | S_IRUSR);
	}
	write(fd, my_itoa(count), strlen(my_itoa(count)));
	write(fd, &ct, 1);
	write(fd, list->line, strlen(list->line));
	write(fd, &ct, 1);
	write(fd, list->timestamp, strlen(list->timestamp));
	++count;
}

static void	first_node(t_history **list, char *line, char *timestamp)
{
	t_history	*tmp = NULL;

	if ((*list = malloc(sizeof(t_history))) == NULL)
		exit (84);
	(*list)->line = strdup(line);
	(*list)->timestamp = strdup(timestamp);
	write_in_history(*list);
	(*list)->prev = NULL;
	(*list)->next = malloc(sizeof(t_history));
	tmp = *list;
	*list = (*list)->next;
	(*list)->next = NULL;
	(*list)->prev = tmp;
}

void	put_in_history(t_history **list, char *line)
{
	time_t		timestamp = time(NULL);
	t_history	*tmp = NULL;

	if (list == NULL) {
		first_node(list, line, ctime(&timestamp));
		return;
	}
	(*list)->line = strdup(line);
	(*list)->timestamp = strdup(ctime(&timestamp));
	write_in_history(*list);
	(*list)->next = malloc(sizeof(t_history));
	tmp = *list;
	*list = (*list)->next;
	(*list)->prev = tmp;
	(*list)->next = NULL;
}