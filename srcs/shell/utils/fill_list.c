/*
** EPITECH PROJECT, 2018
** fill_list.c
** File description:
** functions to init and fill the list
*/
#include "42sh.h"
#include <string.h>
#include <stdlib.h>

static int	count(char *env)
{
	int	i = 0;

	for (i = 0; env[i] && env[i] != '='; ++i);
	return (i);
}

static char	*get_name(char *str)
{
	char	*name = malloc(sizeof(*name) * count(str) + 1);
	int	i;

	if (name == NULL)
		return (NULL);
	for (i = 0; str[i] && str[i] != '='; ++i)
		name[i] = str[i];
	name[i] = '\0';
	return (name);
}

static char *get_content(char *str)
{
	int	i = count(str);
	char	*content = malloc(sizeof(*content) * (strlen(str) - i));

	if (content == NULL)
		return (NULL);
	strcpy(content, str + i + 1);
	return (content);
}

static t_save *init_data(char *env)
{
	t_save *data = malloc(sizeof(*data));

	if (!data)
		return (NULL);
	data->name = get_name(env);
	data->content = get_content(env);
	return (data);
}

void	init_list(t_node **head, char **env)
{
	for (int i = 0; env[i]; ++i)
		insert_end(head, init_data(env[i]));
}
