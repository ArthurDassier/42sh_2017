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

static void	rewrite_prompt_str(int size, char *save, const char *prompt,
char *str)
{
	cursorbackward(size);
	printf("%s", save);
	printf("\n");
	cursorbackward(size);
	fflush(stdout);
	write(1, prompt, strlen(prompt));
	write(1, str, strlen(str));
}

static int	match_str(char **str, char *info, const char *prompt, int size)
{
	if (strlen(*str) == 0)
		return (0);
	if (strncmp(*str, info, strlen(*str)) == 0) {
		free(*str);
		*str = malloc(sizeof(char) * (strlen(info) + 1));
		*str = strcpy(*str, info);
		cursorbackward(size);
		fflush(stdout);
		write(1, prompt, strlen(prompt));
		write(1, *str, strlen(*str));
		return (1);
	}
	return (0);
}

int	auto_completion(__attribute((unused)) char **str,
__attribute((unused)) const char *prompt)
{
	int		size = strlen(*str) + strlen(prompt);
	DIR		*dir = opendir(".");
	struct dirent	*red;
	char		*save = malloc(sizeof(char));

	printf("\n");
	save[0] = '\0';
	cursorbackward(size);
	while ((red = readdir(dir)) != NULL) {
		if (match_str(str, red->d_name, prompt, size) == 1)
			return (0);
		size += strlen(red->d_name) + 2;
		save = realloc(save, size);
		strcat(save, red->d_name);
		strcat(save, " ");
	}
	rewrite_prompt_str(size, save, prompt, *str);
	return (0);
}