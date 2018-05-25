/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** handle_dollars
*/

#include "quotes.h"
#include "42sh.h"
#include <string.h>
#include <stdlib.h>

static char	*found_env(t_quotes *quotes, char *pathname)
{
	t_node		*tmp = (*quotes->new_env);
	t_save		*tmp_content;
	list_var	*var = quotes->spec_var_list;

	do {
		tmp_content = (t_save *)tmp->data;
		if (strcmp(tmp_content->name, pathname) == 0) {
			free(pathname);
			return (get_env_content(tmp, tmp_content->name));
		}
		tmp = tmp->next;
	} while (tmp != (*quotes->new_env));
	while (var != NULL) {
		if (strcmp(var->name, pathname) == 0)
			return (var->content);
		var = var->next;
	}
	my_putstr(pathname);
	my_putstr(": Undefined variable.\n");
	return (NULL);
}

static char	*replace_line(char *line_one, char *name, int i, int save)
{
	char	*tmp = malloc(sizeof(char)
	* (strlen(line_one) + strlen(name)));
	int	nb = 0;

	for (nb = 0; nb != save; ++nb)
		tmp[nb] = line_one[nb];
	for (int count = 0; name[count] != '\0'; ++count) {
		tmp[nb] = name[count];
		++nb;
	}
	while (line_one[i] != '\0') {
		tmp[nb] = line_one[i];
		++nb;
		++i;
	}
	tmp[nb] = '\0';
	free(line_one);
	return (tmp);
}

static char	*replace_the_dollar(char *line_one, t_quotes *quotes, int i)
{
	char	*pathname = malloc(sizeof(char) * strlen(line_one));
	char	*name;
	int	j = 0;
	int	save = i - 1;

	while (line_one[i] != '\0' && line_one[i] != ' '
	&& line_one[i] != '\t') {
		pathname[j] = line_one[i];
		++i;
		++j;
	}
	pathname[j] = '\0';
	name = found_env(quotes, pathname);
	if (name == NULL)
		return (NULL);
	return (replace_line(line_one, name, i, save));
}

char	*handle_dollars(char *line_one, t_quotes *quotes_st)
{
	int	i = 0;

	while (line_one[i] != '\0') {
		if (line_one[i] == '$')
			line_one = replace_the_dollar(line_one,
							quotes_st, i + 1);
		if (line_one == NULL)
			return (NULL);
		++i;
	}
	return (line_one);
}