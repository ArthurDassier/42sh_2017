/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** quotes
*/

#include "quotes.h"
#include "my.h"
#include "inhibitors.h"
#include "define.h"
#include <string.h>
#include <stdlib.h>

static char	*my_cat_double(char *line_one, char *line_two,
char *s, t_quotes *quotes_st)
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
	if (line_one[0] == '\0')
		line_one = inc_space(line_one, s, '"');
	else
		line_one[j] = '\0';
	line_one = strcat(line_one, line_two);
	line_one = delete_special(line_one);
	line_one = handle_dollars(line_one, quotes_st);
	return (line_one);
}

static char	**double_tab(char **line, char *s, t_quotes *quotes_st, int i)
{
	int	j = 0;

	while (line[i][0] != '\"')
		++i;
	line[i] = malloc(sizeof(char) * strlen(s));
	if (line[i] == NULL)
		return (NULL);
	line[i][0] = '\0';
	for (j = i + 1; line[j][0] != '\"'; ++j) {
		line[i] = my_cat_double(line[i], line[j], s, quotes_st);
		if (line[i] == NULL)
			break;
		line[i] = find_endspace(line[i], s, '"');
	}
	if (line[i] == NULL)
		return (NULL);
	for (i = i + 1; line[++j] != NULL; ++i)
		line[i] = strdup(line[j]);
	line[i] = NULL;
	return (line);
}

static char	**double_quotes(char **line, char *s, t_quotes *quotes_st)
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
			line = double_tab(line, s, quotes_st, 0);
		return (line);
	}
	return (line);
}

char	**quotes_commands(char **line, char *s, t_quotes *quotes_st, int i)
{
	if (line[i][0] == '\'') {
		line = simple_quotes(line, s);
		if (line == NULL)
			return (NULL);
	} else if (line[i][0] == '\"') {
		line = double_quotes(line, s, quotes_st);
		if (line == NULL)
			return (NULL);
	} else {
		line[i] = delete_backslash(line[i]);
		line[i] = handle_dollars(line[i], quotes_st);
	}
	return (line);
}

char	**quotes(char **line, char *s, t_node **env_list, t_node **spec)
{
	int		i = 0;
	t_quotes	*quotes_st = malloc(sizeof(t_quotes));

	quotes_st->new_env = env_list;
	quotes_st->spec_var_list = spec;
	while (line[i] != NULL) {
		line = quotes_commands(line, s, quotes_st, i);
		if (line == NULL)
			return (NULL);
		++i;
	}
	return (line);
}
