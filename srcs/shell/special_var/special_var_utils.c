/*
** EPITECH PROJECT, 2018
** special_var_utils.c
** File description:
** Arthur
*/

#include "42sh.h"

char *delete_points(char *path)
{
	char	*tmp = malloc(sizeof(char) * (strlen(path) + 3));
	int	i = 0;

	while (path[i] != '\0') {
		tmp[i] = path[i];
		if (tmp[i] == ':')
			tmp[i] = ' ';
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}

void concerned_spec_part2(list_var *tmp, t_node *new_env)
{
	if (strcmp(tmp->name, "cwd") == SUCCESS) {
		tmp->content = NULL;
		tmp->content = getcwd(tmp->content, 0);
	}
	if (strcmp(tmp->name, "path") == SUCCESS) {
		tmp->content = NULL;
		tmp->content = get_env_content(new_env, "PATH");
		if (tmp->content != NULL)
			tmp->content = delete_points(tmp->content);
	}
	if (strcmp(tmp->name, "user") == SUCCESS) {
		tmp->content = NULL;
		tmp->content = get_env_content(new_env, "USER");
	}
}

void concerned_spec(list_var *tmp, t_node *new_env, char *s, int ret)
{
	concerned_spec_part2(tmp, new_env);
	if (strcmp(tmp->name, "term") == SUCCESS) {
		tmp->content = NULL;
		tmp->content = get_env_content(new_env, "TERM");
	}
	if (strcmp(tmp->name, "status") == SUCCESS) {
		tmp->content = NULL;
		tmp->content = my_itoa(ret);
	}
	if (s != NULL && strcmp(tmp->name, "echo") == SUCCESS
	&& tmp->content != NULL)
		my_printf("%s\n", s);
}

void reset_spec(list_var **spec, t_node *new_env, char *s, int ret)
{
	list_var *tmp = *(spec);

	while (tmp != NULL) {
		concerned_spec(tmp, new_env, s, ret);
		tmp = tmp->next;
	}
}

int	alphabetic_order(char *line_one, char *line_two)
{
	int	i = 0;

	while (line_one[i] != '\0' && line_two[i] != '\0') {
		if (line_one[i] < line_two[i])
			return (0);
		if (line_one[i] > line_two[i])
			return (1);
		++i;
	}
	if (line_one[i] == '\0' && line_two[i] != '\0')
		return (0);
	return (1);
}
