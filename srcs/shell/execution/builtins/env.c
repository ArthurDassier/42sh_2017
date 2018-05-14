/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** env
*/

#include "42sh.h"

static t_built	env_tab[NB_FLAGS] = {
	{"-i", &ignore_env},
	{"--ignore-environment", &ignore_env},
	{"-0", &end_with_null},
	{"--null", &end_with_null},
	{"-u", &rm_var},
	{"--help", &display_help},
	{"--version", &display_version},
	{"-", &ignore_env},
};

int	display_help(__attribute((unused)) char **line, t_node **env_list)
{
	(void)env_list;
	return (SUCCESS);
}

int display_version(char **line, t_node **env_list)
{
	(void)line;
	(void)env_list;
	return (SUCCESS);
}

int	rm_var(char **line, t_node **env_list)
{
	char *str;

	if (strcmp(line[1], "-u") == SUCCESS) {
		str = get_env_name(*env_list, line[2]);
		if (!str)
			return (FAILURE);
		delete_node(env_list, str);
		display_list(*env_list, &print_list);
		return (SUCCESS);
	}
	return (SUCCESS);
}

int	ignore_env(char **line, t_node **env_list)
{
	(void)line;
	(void)env_list;
	return (SUCCESS);
}

int end_with_null(__attribute((unused)) char **line, t_node **env_list)
{
	display_list(*env_list, &print_list_with_null);
	return (SUCCESS);
}

int	env_built( __attribute((unused)) char **line, t_node **env_list)
{
	if (my_strarraylen(line) == VALID) {
		display_list(*env_list, &print_list);
		return (SUCCESS);
	}
	for (int i = 0; i < NB_BUILT; ++i) {
		if (my_strcmp(env_tab[i].builtin, line[1]) == SUCCESS) {
			if ((env_tab[i].ptr)(line, env_list) == FAILURE)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}