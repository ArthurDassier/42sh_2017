/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history_completion
*/

#include "history.h"
#include "line.h"
#include "ncurses_define.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*history_completion(t_history *hist_list, char *line)
{
	t_history	*tmp = hist_list;
	int		len = 0;

	if (tmp == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->prev != NULL) {
		if (strncmp(line, tmp->line, strlen(line)) == 0) {
			len = strlen(line);
			cursorbackward(len);
			printf("%s", tmp->line);
			len = strlen(tmp->line) - strlen(line) - 1;
			cursorbackward(len);
			fflush(stdout);
			return (tmp->line);
		}
		tmp = tmp->prev;
	}
	return (NULL);
}