/*
** EPITECH PROJECT, 2018
** globbings.c
** File description:
** Arthur
*/

#include "42sh.h"
#include <glob.h>
#include <string.h>

static void release_line(char **line, int i)
{
	while (i != 1) {
		free(line[i]);
		--i;
	}
	free(line);
}

static char **add_glob(char **line, char *str, int check)
{
	int	i = 0;
	char	**tmp;

	printf(">>> %s %d\n", str, check);
	while (line[i] != NULL)
		++i;
	tmp = malloc(sizeof(char *) * (i + 1));
	for (i = 0; line[i] != NULL; ++i)
		tmp[i] = strdup(line[i]);
	if (check == 0) {
		tmp[i - 1] = strdup(str);
		tmp[i] = NULL;
	} else {
		tmp[i] = strdup(str);
		tmp[i + 1] = NULL;
	}
	//release_line(line, i);
	return (tmp);
}

char **globbings(char **line)
{
	glob_t	globlist;
	int	i = 0;
	int	j = 1;

	while (line[j] != NULL) {
		if (!(glob(line[j], 0, NULL, &globlist) == GLOB_NOSPACE
		|| glob(line[j], 0, NULL, &globlist) == GLOB_NOMATCH
		|| glob(line[j], 0, NULL, &globlist) == GLOB_ABORTED)) {
			while (globlist.gl_pathv[i] != NULL) {
				line = add_glob(line, globlist.gl_pathv[i], i);
				++i;
			}
		}
		++j;
		i = 0;
	}
	globfree(&globlist);
	return (line);
}
