/*
** EPITECH PROJECT, 2018
** globbings.c
** File description:
** Arthur
*/

#include "42sh.h"
#include <glob.h>
#include <string.h>

static int	analyse_globbings(char *tmp)
{
	int	i = 0;

	while (tmp[i] != '\0') {
		if ((tmp[i] == '*' || tmp[i] == '?' || tmp[i] == '['
		|| tmp[i] == '{' || tmp[i] == '^')
		&& (back_slash(i, tmp) == 1))
			return (-1);
		++i;
	}
	return (0);
}

static int	check_glob(char **tmp)
{
	int	i = 0;

	while (tmp[i] != NULL) {
		if (analyse_globbings(tmp[i]) == -1)
			return (-1);
		++i;
	}
	return (0);
}

static char	**add_glob(char **tmp, char **globs)
{
	int	i = 0;
	int	nb = 0;
	int	count = 0;
	char	**tab = malloc(sizeof(char *) * alloc_tab(tmp, globs));

	if (tab == NULL)
		return (NULL);
	while (tmp[i] != NULL && analyse_globbings(tmp[i]) != -1)
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

	if (analyse_globbings(line) == -1
	&& glob(line, 0, NULL, &globlist) == 0) {
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
	if (check_glob(tmp) != -1) {
		release_tmp(tmp);
		return (line);
	}
	for (int j = 0; line[j] != NULL; ++j) {
		tmp = my_glob(line[j], tmp);
		if (tmp == NULL)
			return (NULL);
	}
	release_tmp(line);
	if (check_glob(tmp) == -1) {
		my_printf("%s: No match.\n", tmp[0]);
		release_tmp(tmp);
		return (NULL);
	}
	return (tmp);
}
