/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** write_char
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "ncurses_define.h"

static void	remp_line(char *line, char *save, int j, char buf)
{
	line[j] = buf;
	while (save[j] != '\0') {
		line[j + 1] = save[j];
		++j;
	}
	line[j + 1] = '\0';
}

void	rewrite_prompt_line(char *line, const char *prompt, int pos)
{
	static char	cache[] = "                                          ";
	int		len = 0;

	len = strlen(prompt) + strlen(line) + 2;
	cursorbackward(len);
	fflush(stdout);
	write(1, prompt, strlen(prompt));
	write(1, line, strlen(line));
	write(1, cache, strlen(cache));
	len = strlen(cache) + pos;
	cursorbackward(len);
	fflush(stdout);
}

char	*write_char(char buf, int *pos, char *line, const char *prompt)
{
	char	*save = strdup(line);
	int	j = strlen(line);
	int	tmp = *pos;

	if (*pos == 0) {
		write(1, &buf, 1);
		line[j] = buf;
		line[j + 1] = '\0';
		return (line);
	}
	line = realloc(line, j + 2);
	while (tmp < 0) {
		--j;
		++tmp;
	}
	remp_line(line, save, j, buf);
	free(save);
	rewrite_prompt_line(line, prompt, (*pos * -1));
	return (line);
}