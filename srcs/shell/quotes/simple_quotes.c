/*
** EPITECH PROJECT, 2018
** simple_quotes.c
** File description:
** Arthur
*/

#include "42sh.h"

char	*my_cat(char *line_one, char *line_two, char *s)
{
	char	*find = strstr(s, line_one);
	int	i = 0;
	int	j = strlen(line_one);

	for (unsigned int nb = 0; nb != strlen(line_one); ++nb)
		++find;
	while (line_one[0] != '\0' && find[i] != line_two[0]) {
		line_one[j] = find[i];
		++j;
		++i;
	}
	if (line_one[0] != '\0')
		line_one[j] = '\0';
	line_one = strcat(line_one, line_two);
	return (line_one);
}

char	**simple_tab(char **line, char *s)
{
	int	i = 0;
	int	j = 0;

	while (line[i][0] != '\'')
		++i;
	line[i] = malloc(sizeof(char) * strlen(s));
	if (line[i] == NULL)
		return (NULL);
	line[i][0] = '\0';
	for (j = i + 1; line[j][0] != '\''; ++j)
		line[i] = my_cat(line[i], line[j], s);
	for (i = i + 1; line[++j] != NULL;) {
		line[i] = strdup(line[j]);
		free(line[j]);
		++i;
	}
	line[i] = NULL;
	return (line);
}

char	**simple_quotes(char **line, char *s)
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
		return (simple_tab(line, s));
	}
	return (line);
}
