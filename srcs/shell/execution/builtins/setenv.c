/*
** EPITECH PROJECT, 2018
** setenv.c
** File description:
** setenv command functions
*/
#include "42sh.h"

static void	adding_variable(t_save *data, char **line,
t_node **env_list)
{
	data = malloc(sizeof(*data));

	if (!data)
		exit(FAILURE);
	data->name = strdup(line[1]);
	if (!line[2])
		data->content = strdup("");
	else
		data->content = strdup(line[2]);
	insert_end(env_list, data);
}

static void	normal_setenv(t_node *env_list, char **line,
t_save *data)
{
	t_node	*tmp = find_node(env_list, &cmp, line[1]);

	data = (t_save *)tmp->data;
	if (my_strarraylen(line) == 2)
		data->content = strdup("");
	else
		data->content = strdup(line[2]);
}

int		setenv_built(char **line, t_node **env_list)
{
	t_save	*data = NULL;

	if (my_strarraylen(line) == VALID) {
		display_list(*env_list, &print_list);
		return (SUCCESS);
	}
	if (my_strisalphanum(line[1]) == SUCCESS) {
		my_putstr("setenv: Variable name must");
		my_putstr(" contain alphanumeric characters.\n");
		return (FAILURE);
	}
	if (check_env_name(*env_list, line[1]) == false) {
		adding_variable(data, line, env_list);
	} else {
		normal_setenv(*env_list, line, data);
	}
	return (SUCCESS);
}

int		unsetenv_built(char **line, t_node **env_list)
{
	char	*str;

	if (my_strarraylen(line) == VALID) {
		my_print_err("unsetenv: Too few arguments.\n");
		return (FAILURE);
	}
	str = get_env_name(*env_list, line[1]);
	if (!str)
		return (FAILURE);
	delete_node(env_list, str);
	return (SUCCESS);
}