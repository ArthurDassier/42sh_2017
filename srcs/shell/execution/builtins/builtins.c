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

int	exit_built(char **line, __attribute((unused)) t_node **env_list)
{
	if (my_strarraylen(line) == VALID)
		exit(SUCCESS);
	exit(my_getnbr(line[1]));
	return (SUCCESS);
}

int	exec_builtins(char **line, t_node **env_list)
{
	for (int i = 0; i < NB_BUILT; ++i) {
		if (my_strcmp(tab_mini[i].builtin, line[0]) == SUCCESS) {
			if ((tab_mini[i].ptr)(line, env_list) == FAILURE)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}