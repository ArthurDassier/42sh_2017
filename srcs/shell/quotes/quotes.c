/*
** EPITECH PROJECT, 2018
** quotes.c
** File description:
** Arthur
*/

#include "42sh.h"

static char	*my_cat_double(char *line_one, char *line_two,
char *s, t_node **env_l)
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
	my_printf("- > %s|\n", line_one);
	line_one = delete_special(line_one);
	line_one = handle_dollars(line_one, env_l);
	return (line_one);
}

static char	**double_tab(char **line, char *s, t_node **env_list)
{
	int	i = 0;
	int	j = 0;

	while (line[i][0] != '\"')
		++i;
	line[i] = malloc(sizeof(char) * strlen(s));
	if (line[i] == NULL)
		return (NULL);
	line[i][0] = '\0';
	for (j = i + 1; line[j][0] != '\"'; ++j)
		line[i] = my_cat_double(line[i], line[j], s, env_list);
	if (line[i] == NULL)
		return (NULL);
	for (i = i + 1; line[++j] != NULL;) {
		line[i] = strdup(line[j]);
		free(line[j]);
		++i;
	}
	line[i] = NULL;
	return (line);
}

static char	**double_quotes(char **line, char *s, t_node **env_list)
{
	int	i = 0;
	int	nb_quote = 0;

	while (line[i] != NULL) {
		if (line[i][0] == '\"')
			++nb_quote;
		++i;
	}
	if (nb_quote > 0) {
		if (nb_quote % 2 != 0) {
			my_putstr("Unmatched \'\"\'.\n");
			return (NULL);
		}
		while (line != NULL && count_quotes(line, '\"'))
			line = double_tab(line, s, env_list);
		return (line);
	}
	return (line);
}

char	**quotes_commands(char **line, char *s, t_node **env_list, int i)
{
	if (line[i][0] == '\'') {
		line = simple_quotes(line, s);
		if (line == NULL)
			return (NULL);
	} else if (line[i][0] == '\"') {
		line = double_quotes(line, s, env_list);
		if (line == NULL)
			return (NULL);
	} else
		line[i] = delete_backslash(line[i]);
	return (line);
}

char	**quotes(char **line, char *s, t_node **env_list)
{
	int	i = 0;

	while (line[i] != NULL) {
		line = quotes_commands(line, s, env_list, i);
		if (line == NULL)
			return (NULL);
		++i;
	}
	return (line);
}
