/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** autocompletion
*/

#include "line.h"
#include "ncurses_define.h"
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static void	rewrite_prompt_line(int size, char *save, const char *prompt,
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
		return (0);
	if (strncmp(*line, info, strlen(*line)) == 0) {
		free(*line);
		*line = malloc(sizeof(char) * (strlen(info) + 1));
		*line = strcpy(*line, info);
		cursorbackward(size);
		fflush(stdout);
		write(1, prompt, strlen(prompt));
		write(1, *line, strlen(*line));
		return (1);
	}
	return (0);
}

int	auto_completion(__attribute((unused)) char **line,
__attribute((unused)) const char *prompt,
__attribute((unused)) t_history *hist_list)
{
	int		size = strlen(*line) + strlen(prompt);
	DIR		*dir = opendir(".");
	struct dirent	*red;
	char		*save = NULL;

	if ((save = history_completion(hist_list, *line)) != NULL) {
		free(*line);
		*line = strdup(save);;
		cursorbackward(size);
		fflush(stdout);
		write(1, prompt, strlen(prompt));
		write(1, *line, strlen(*line));
		return (0);
	}
	save = malloc(sizeof(char));
	printf("\n");
	save[0] = '\0';
	cursorbackward(size);
	while ((red = readdir(dir)) != NULL) {
		if (match_str(line, red->d_name, prompt, size) == 1)
			return (0);
		size += strlen(red->d_name) + 2;
		save = realloc(save, size);
		strcat(save, red->d_name);
		strcat(save, " ");
	}
	rewrite_prompt_line(size, save, prompt, *line);
	return (0);
}