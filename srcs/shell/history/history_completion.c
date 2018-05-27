/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history_completion
*/

#include "history.h"
#include "line.h"
#include "const_values.h"
#include "list.h"
#include "ncurses_define.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

static void	rewrite_prompt(char *line, const char *prompt,
t_history *hist_data, int flag)
{
	int		len = 0;

	len = strlen(line) + strlen(prompt) + 1;
	cursorbackward(len);
	fflush(stdout);
	write(1, prompt, strlen(prompt));
	if (flag == 0)
		write(1, hist_data->line, strlen(hist_data->line));
}

static void	print_cache(char *line)
{
	static char	cache[] = "                                          ";
	int	len = 0;

	write(1, line, strlen(line));
	write(1, cache, strlen(cache));
	len = strlen(cache);
	cursorbackward(len);
	fflush(stdout);
}

static void	rewrite_print(char *line, const char *prompt,
t_history *hist_data)
{
	rewrite_prompt(line, prompt, hist_data, 1);
	print_cache(line);
}

char	*history_completion(t_node *hist_list, char *line, const char *prompt)
{
	t_node		*tmp = hist_list;
	t_history	*hist_data = NULL;
	int		len = 0;

	if (tmp == NULL)
		return (NULL);
	tmp = tmp->prev;
	while (tmp != NULL) {
		hist_data = (t_history *)tmp->data;
		if (strncmp(line, hist_data->line, strlen(line)) == 0) {
			rewrite_prompt(line, prompt, hist_data, 0);
			len = strlen(hist_data->line) - strlen(line);
			cursorbackward(len);
			fflush(stdout);
			return (hist_data->line);
		}
		tmp = tmp->prev;
	}
	rewrite_print(line, prompt, hist_data);
	return (NULL);
}