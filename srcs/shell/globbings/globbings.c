/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** globbings
*/

#include "globbings.h"
#include "define.h"
#include <glob.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int	analyse_globbings(char *tmp)
{
	int	i = 0;

	while (tmp[i] != '\0') {
		if ((tmp[i] == '*' || tmp[i] == '?' || tmp[i] == '['
		|| tmp[i] == '{' || tmp[i] == '^')
		&& (back_slash(i, tmp) == VALID))
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

static int	check_glob(char **tmp)
{
	int	i = 0;

	while (tmp[i] != NULL) {
		if (analyse_globbings(tmp[i]) == ERROR)
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}

static char	**add_glob(char **tmp, char **globs)
{
	int	i = 0;
	int	nb = 0;
	int	count = 0;
	char	**tab = malloc(sizeof(char *) * alloc_tab(tmp, globs));

	if (!tab)
		return (NULL);
	while (tmp[i] != NULL && analyse_globbings(tmp[i]) != ERROR)
		tab[nb++] = strdup(tmp[i++]);
	while (globs[count] != NULL)
		tab[nb++] = strdup(globs[count++]);
	while (tmp[++i] != NULL)
		tab[nb++] = strdup(tmp[i]);
	tab[nb] = NULL;
	release_tmp(tmp);
	return (tab);
}

static char	**my_glob(char *line, char **tmp)
{
	glob_t	globlist;

	if (analyse_globbings(line) == ERROR
	&& glob(line, 0, NULL, &globlist) == SUCCESS) {
		tmp = add_glob(tmp, globlist.gl_pathv);
		if (tmp == NULL)
			return (NULL);
		globfree(&globlist);
	}
	return (tmp);
}

char	**globbings(char **line)
{
	char	**tmp = copy_line(line);

	if (tmp == NULL)
		return (NULL);
	if (check_glob(tmp) != ERROR) {
		release_tmp(tmp);
		return (line);
	}
	for (int j = 0; line[j] != NULL; ++j) {
		tmp = my_glob(line[j], tmp);
		if (tmp == NULL)
			return (NULL);
	}
	release_tmp(line);
	if (check_glob(tmp) == -1 && strcmp("set", line[0]) == SUCCESS) {
		printf("%s: No match.\n", tmp[0]);
		release_tmp(tmp);
		return (NULL);
	}
	return (tmp);
}