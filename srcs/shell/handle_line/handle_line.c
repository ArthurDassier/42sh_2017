/*
** EPITECH PROJECT, 2018
** handle_line.c
** File description:
** Arthur
*/

#include "42sh.h"

char	**handle_line(char **line, char *s)
{
	line = simple_quotes(line, s);
	if (line != NULL)
		line = handle_backslash(line, s);
	if (line != NULL)
		line = globbings(line);
	if (line == NULL)
		return (NULL);
	return (line);
}
