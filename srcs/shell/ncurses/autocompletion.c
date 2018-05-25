/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** autocompletion
*/

#include "line.h"
#include "ncurses_define.h"
#include "define.h"
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static void	rewrite_prompt_and_line(int size, char *save, const char *prompt,
char *line)
{
	cursorbackward(size);
	printf("%s", save);
	printf("\n");
	cursorbackward(size);
	fflush(stdout);
	write(1, prompt, strlen(prompt));
	write(1, line, strlen(line));
}

static int	match_str(char **line, char *info, const char *prompt, int size)
{
	if (strlen(*line) == 0)
		return (SUCCESS);
	if (strncmp(*line, info, strlen(*line)) == 0) {
		free(*line);
		*line = malloc(sizeof(char) * (strlen(info) + 1));
		*line = strcpy(*line, info);
		cursorbackward(size);
		fflush(stdout);
		write(1, prompt, strlen(prompt));
		write(1, *line, strlen(*line));
		return (VALID);
	}
	return (SUCCESS);
}

static int	auto_completion_from_history(t_history **hist_list, char **line,
const char *prompt, int size)
{
	char	*save = NULL;

	if ((save = history_completion(*hist_list, *line, prompt)) != NULL) {
		free(*line);
		*line = strdup(save);
		cursorbackward(size);
		fflush(stdout);
		write(1, prompt, strlen(prompt));
		write(1, *line, strlen(*line));
		return (VALID);
	}
	return (SUCCESS);
}

int	auto_completion(__attribute((unused)) char **line,
__attribute((unused)) const char *prompt,
__attribute((unused)) t_history **hist_list)
{
	int		size = strlen(*line) + strlen(prompt) + 1;
	DIR		*dir = opendir(".");
	struct dirent	*red;
	char		*save = NULL;

	if (auto_completion_from_history(hist_list, line, prompt, size) == 1)
		return (1);
	save = malloc(sizeof(char));
	printf("\n");
	save[0] = '\0';
	while ((red = readdir(dir)) != NULL) {
		if (match_str(line, red->d_name, prompt, size) == 1)
			return (1);
		size += strlen(red->d_name) + 1;
		save = realloc(save, size);
		strcat(save, red->d_name);
		strcat(save, " ");
	}
	rewrite_prompt_and_line(size, save, prompt, *line);
	return (SUCCESS);
}