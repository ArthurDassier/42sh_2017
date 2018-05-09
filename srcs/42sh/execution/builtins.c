/*
** EPITECH PROJECT, 2018
** env.c
** File description:
** env functions
*/
#include "42sh.h"

static t_built	tab_mini[NB_BUILT] = {
	{"cd", &cd_built},
	{"setenv", &setenv_built},
	{"env", &env_built},
	{"unsetenv", &unsetenv_built},
	{"exit", &exit_built}
};

int	env_built( __attribute((unused)) char **line, t_node **head)
{
	display_list(*head, &print_list);
	return (SUCCESS);
}

int	exit_built(char **line, __attribute((unused)) t_node **head)
{
	if (my_strarraylen(line) == 1)
		exit(SUCCESS);
	exit(my_getnbr(line[1]));
	return (SUCCESS);
}

int	exec_builtins(char **line, t_node **env)
{
	for (int i = 0; i < NB_BUILT; ++i) {
		if (my_strcmp(tab_mini[i].builtin, line[0]) == 0) {
			if ((tab_mini[i].ptr)(line, env) == FAILURE)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}