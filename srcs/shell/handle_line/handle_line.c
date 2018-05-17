/*
** EPITECH PROJECT, 2018
** handle_line.c
** File description:
** Arthur
*/

#include "42sh.h"

char	**handle_line(char *s)
{
	char **line = NULL;

	line = my_str_to_wordtab_delim(s, " \t\r");
	if (line != NULL)
		line = simple_quotes(line);
	if (line != NULL)
		line = handle_backslash(line, s);
	if (line != NULL)
		line = globbings(line);
	if (line == NULL)
		return (NULL);
	return (line);
}
