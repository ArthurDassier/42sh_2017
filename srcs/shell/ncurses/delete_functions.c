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
	int	j = strlen(line);
	int	tmp = *pos;

	if (*pos * -1 == j)
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