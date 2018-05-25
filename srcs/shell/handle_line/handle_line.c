/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** handle_line
*/

#include "quotes.h"
#include "inhibitors.h"
#include "globbings.h"
#include <string.h>

char	**handle_line(char **line, char *s, t_node **env_list, list_var *spec)
{
	line = quotes(line, s, env_list, spec);
	if (line != NULL)
		line = handle_backslash(line);
	if (line != NULL)
		line = globbings(line);
	if (line == NULL)
		return (NULL);
	return (line);
}
