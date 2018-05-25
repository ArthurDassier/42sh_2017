/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** simple_quotes_utils
*/

#include "quotes.h"
#include "define.h"
#include "inhibitors.h"

static char	*replace_bs(char *line, int *i)
{
	int	j = 0;
	char	*escape = "abtnvfr";

	while (escape[j] != '\0') {
		if (escape[j] == line[*i + 1])
			break;
		++j;
	}
	if (escape[j] == '\0')
		return (line);
	else {
		line[*i] = j + 7;
		line = decal_line(line, *i + 1);
		*i += 1;
	}
	return (line);
}

char	*delete_special(char *line)
{
	int	i = 0;

	while (line[i] != '\0') {
		if (line[i] == '\\')
			line = replace_bs(line, &i);
		++i;
	}
	return (line);
}