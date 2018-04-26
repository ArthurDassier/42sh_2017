/*
** EPITECH PROJECT, 2018
** setenv.c
** File description:
** setenv command functions
*/
#include "minishell2.h"

static void	adding_variable(t_save *data, char **line,
t_node **head)
{
	data = malloc(sizeof(*data));

	if (data == NULL)
		return;
	data->name = my_strdup(line[1]);
	if (line[2] == NULL)
		data->content = my_strdup("");
	else
		data->content = my_strdup(line[2]);
	insert_end(head, data);
}

static void	normal_setenv(t_node *head, char **line,
t_save *data)
{
	t_node	*tmp = find_node(head, &cmp, line[1]);

	data = (t_save *)tmp->data;
	if (my_strarraylen(line) == 2)
		data->content = my_strdup("");
	else
		data->content = my_strdup(line[2]);
}

char	**setenv_built(char **line, t_node **head)
{
	t_save	*data = NULL;

	if (my_strarraylen(line) == 1) {
		display_list(*head, &print_list);
		return (NULL);
	}
	if (my_strisalphanum(line[1]) == 0) {
		my_putstr("setenv: Variable name must");
		my_putstr(" contain alphanumeric characters.\n");
		return (NULL);
	}
	if (check_env_name(*head, line[1]) == false) {
		adding_variable(data, line, head);
	} else {
		normal_setenv(*head, line, data);
	}
	return (NULL);
}

char	**unsetenv_built(char **line, t_node **head)
{
	char	*str;

	if (my_strarraylen(line) == 1) {
		my_print_err("unsetenv: Too few arguments.\n");
		return (NULL);
	}
	str = get_env_name(*head, line[1]);
	if (str == NULL)
		return (NULL);
	delete_node(head, str);
	return (NULL);
}