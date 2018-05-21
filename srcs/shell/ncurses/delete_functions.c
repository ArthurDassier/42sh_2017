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

char	*del_char(int *pos, char *line, const char *prompt)
{
	char	*save = strdup(line);
	int	j = strlen(line);
	int	len = 0;
	int	tmp = *pos;

	if (*pos * -1 == j + 1)
		return (line);
	while (tmp <= 0) {
		--j;
		++tmp;
	}
	while (save[j] != '\0') {
		line[j] = save[j + 1];
		++j;
	}
	free(save);
	len = strlen(prompt) + strlen(line);
	cursorbackward(len);
	fflush(stdout);
	write(1, prompt, strlen(prompt));
	write(1, line, strlen(line));
	len = strlen(line) - *pos;
	cursorbackward(len);
	fflush(stdout);
	return (line);
}