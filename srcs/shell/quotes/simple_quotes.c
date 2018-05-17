/*
** EPITECH PROJECT, 2018
** simple_quotes.c
** File description:
** Arthur
*/

#include "42sh.h"

char **simple_tab(char **line)
{
	int	i = 0;
	int	j = 0;
	int	size = 2;

	while (line[i][0] != '\'')
		++i;
	for (j = i + 1; line[j][0] != '\''; ++j)
		size += strlen(line[j]);
	line[i] = malloc(sizeof(char) * size);
	line[i][0] = '\0';
	for (j = i + 1; line[j][0] != '\''; ++j)
		line[i] = strcat(line[i], line[j]);
	for (i = i + 1; line[++j] != NULL;) {
		line[i] = strdup(line[j]);
		free(line[j]);
		++i;
	}
	line[i] = NULL;
	return (line);
}

char	**simple_quotes(char **line)
{
	int	i = 0;
	int	nb_quote = 0;

	while (line[i] != NULL) {
		if (line[i][0] == '\'')
			++nb_quote;
		++i;
	}
	if (nb_quote > 0) {
		if (nb_quote % 2 != 0) {
			my_putstr("Unmatched \'\'\'.\n");
			return (NULL);
		}
		return (simple_tab(line));
	}
	return (line);
}
