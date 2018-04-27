/*
** EPITECH PROJECT, 2018
** globbings.c
** File description:
** Arthur
*/

#include "42sh.h"
#include <glob.h>
#include <string.h>

char **copy_line(char **line)
{
	int	i = 0;
	int	j = 0;
	char	**tmp;

	while (line[i] != NULL)
		++i;
	tmp = malloc(sizeof(char *) * (i + 1));
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

char **add_glob(char **tmp, char **line, char **globs, int j)
{
	int	i = 0;
	int	u = 0;
	int	x = 0;
	char	**tab = malloc(sizeof(char *) * alloc_tab(tmp, globs));

	while (tmp[i] != NULL) {
		if (i == j)
			++i;
		if (tmp[i] == NULL)
			break;
		tab[x] = strdup(tmp[i]);
		++x;
		++i;
	}
	while (globs[u] != NULL) {
		tab[x] = strdup(globs[u]);
		++x;
		++u;
	}
	tab[x] = NULL;
	for (int a = 0; tab[a] == NULL; a++) {
	}
	return (tab);
}

char **globbings(char **line)
{
	glob_t	globlist;
	int	j = 0;
	char	**tmp = copy_line(line);

	while (line[j] != NULL) {
		if (glob(line[j], 0, NULL, &globlist) == 0) {
			tmp = add_glob(tmp, line, globlist.gl_pathv, j);
			globfree(&globlist);
		}
		++j;
	}
	return (tmp);
}
