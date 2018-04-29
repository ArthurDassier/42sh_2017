/*
** EPITECH PROJECT, 2018
** globbings.c
** File description:
** Arthur
*/

#include "42sh.h"
#include <glob.h>
#include <string.h>

char **add_glob(char **tmp, char **globs, int j)
{
	int	i = 0;
	int	count = 0;
	int	nb = 0;
	char	**tab = malloc(sizeof(char *) * alloc_tab(tmp, globs));

	if (tab == NULL)
		return(NULL);
	while (tmp[i] != NULL) {
		if (i == j)
			++i;
		if (tmp[i] == NULL)
			break;
		tab[nb++] = strdup(tmp[i++]);
	}
	while (globs[count] != NULL)
		tab[nb++] = strdup(globs[count++]);
	tab[nb] = NULL;
	release_tmp(tmp);
	return (tab);
}

char **my_glob(char *line, int j, char ** tmp)
{
	glob_t	globlist;

	if (glob(line, 0, NULL, &globlist) == 0) {
		tmp = add_glob(tmp, globlist.gl_pathv, j);
		if (tmp == NULL)
			return (NULL);
		globfree(&globlist);
	}
	return (tmp);
}

char **globbings(char **line)
{
	int	j = 0;
	char	**tmp = copy_line(line);

	if (tmp == NULL)
		return (NULL);
	while (line[j] != NULL) {
		tmp = my_glob(line[j], j, tmp);
		if (tmp == NULL)
			return (NULL);
		++j;
	}
	return (tmp);
}
