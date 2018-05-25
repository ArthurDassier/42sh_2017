/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history_completion
*/

#include "history.h"
#include "line.h"
#include "define.h"
#include "ncurses_define.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

static void	rewrite_prompt(char *line, const char *prompt)
{
	int		len = 0;

	len = strlen(line) + strlen(prompt) + 1;
	cursorbackward(len);
	fflush(stdout);
	write(1, prompt, strlen(prompt));
}

static void	print_cache(char *line)
{
	char	cache[] = "                                     ";
	int	len = 0;

	write(1, line, strlen(line));
	write(1, cache, strlen(cache));
	len = strlen(cache);
	cursorbackward(len);
	fflush(stdout);
}

char	*history_completion(t_history *hist_list, char *line, const char *prompt)
{
	t_history	*tmp = hist_list;
	int		len = 0;

	if (tmp == NULL)
		return (NULL);
	tmp = tmp->prev;
	while (tmp != NULL) {
		if (strncmp(line, tmp->line, strlen(line)) == 0) {
			rewrite_prompt(line, prompt);
			write(1, tmp->line, strlen(tmp->line));
			len = strlen(tmp->line) - strlen(line);
			cursorbackward(len);
			fflush(stdout);
			return (tmp->line);
		}
		tmp = tmp->prev;
	}
	rewrite_prompt(line, prompt);
	print_cache(line);
	return (NULL);
}