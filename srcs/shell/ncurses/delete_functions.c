/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** delete_functions
*/

#include "line.h"
#include "ncurses_define.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static void	rewrite_prompt_line(char *line, const char *prompt, int pos)
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

char	*del_char(int *pos, char *line, const char *prompt)
{
	int	j = strlen(line);
	int	tmp = *pos;

	if (*pos * -1 == j + 1)
		return (line);
	while (tmp <= 0) {
		--j;
		++tmp;
	}
	while (line[j] != '\0') {
		line[j] = line[j + 1];
		++j;
	}
	rewrite_prompt_line(line, prompt, (*pos * -1));
	return (line);
}

char	*suppr_char(int *pos, char *line, const char *prompt)
{
	int	j = strlen(line);
	int	tmp = *pos;

	if (*pos == 0)
		return (line);
	while (tmp < 0) {
		--j;
		++tmp;
	}
	while (line[j] != '\0') {
		line[j] = line[j + 1];
		++j;
	}
	rewrite_prompt_line(line, prompt, (*pos * -1 - 1));
	return (line);
}