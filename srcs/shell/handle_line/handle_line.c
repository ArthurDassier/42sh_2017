/*
** EPITECH PROJECT, 2018
** handle_line.c
** File description:
** Arthur
*/

#include "42sh.h"

char	**handle_line(char **line, char *s, t_node **env_list)
{
	line = quotes(line, s, env_list);
	if (line != NULL)
		line = handle_backslash(line);
	if (line != NULL)
		line = globbings(line);
	if (line == NULL)
		return (NULL);
	return (line);
}
