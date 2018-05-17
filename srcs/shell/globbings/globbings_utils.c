/*
** EPITECH PROJECT, 2018
** globbings_utils.c
** File description:
** Arthur
*/

#include "42sh.h"

int back_slash(int i, char *tmp)
{
	if (i == 0 || tmp[i - 1] != '\\')
		return (1);
	return (0);
}

void release_tmp(char **tmp)
{
	int	i = 0;

	while (tmp[i] != NULL) {
		free(tmp[i]);
		++i;
	}
	free(tmp);
}

char **copy_line(char **line)
{
	int	i = 0;
	int	j = 0;
	char	**tmp;

	while (line[i] != NULL)
		++i;
	tmp = malloc(sizeof(char *) * (i + 1));
	if (tmp == NULL)
		return (NULL);
	while (line[j] != NULL) {
		tmp[j] = strdup(line[j]);
		++j;
	}
	tmp[j] = NULL;
	return (tmp);
}

int alloc_tab(char **tmp, char **globs)
{
	int	i = 0;
	int	j = 0;

	while (tmp[i] != NULL)
		++i;
	while(globs[j] != NULL)
		++j;
	return (j + i + 2);
}

int	count_glob(char **globs)
{
	int i = 0;

	while (globs[i])
		++i;
	return (i);
}
