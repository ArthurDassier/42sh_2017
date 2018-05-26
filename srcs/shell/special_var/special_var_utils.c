/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** special_var_utils
*/

#include "special_var.h"
#include "const_values.h"
#include <string.h>
#include <stdlib.h>

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

// Change func name
void concerned_spec_part2(t_save *tmp, t_node *new_env)
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

void concerned_spec(t_save *tmp, t_node *new_env, char *s, int ret)
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

void reset_spec(t_node **spec, t_node *new_env, char *s, int ret)
{
	t_node	*tmp = *(spec);
	t_save	*tmp_save;

	do {
		tmp_save = (t_save *)tmp->data;
		concerned_spec(tmp_save, new_env, s, ret);
		tmp = tmp->next;
	} while (tmp != *(spec));
}

int	alphabetic_order(void *first, void *second)
{
	int	i = 0;
	t_save	*one = (t_save *)first;
	t_save	*two = (t_save *)second;
	char	*line_one = one->name;
	char	*line_two = two->name;

	while (line_one[i] != '\0' && line_two[i] != '\0') {
		if (line_one[i] < line_two[i])
			return (SUCCESS);
		if (line_one[i] > line_two[i])
			return (VALID);
		++i;
	}
	if (line_one[i] == '\0' && line_two[i] != '\0')
		return (VALID);
	return (SUCCESS);
}
