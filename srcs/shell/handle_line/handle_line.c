/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** handle_line
*/

#include "shell.h"
#include "quotes.h"
#include "inhibitors.h"
#include "globbings.h"
#include <string.h>

char	**handle_line(char **line, char *s, t_node **env_list, t_node **spec)
{
	line = delim_lexem(s, " \t\r");
	line = quotes(line, s, env_list, spec);
	if (line != NULL)
		line = handle_backslash(line);
	if (line != NULL)
		line = globbings(line);
	return (line);
}
