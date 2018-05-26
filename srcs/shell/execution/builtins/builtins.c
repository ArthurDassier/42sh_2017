/*
** EPITECH PROJECT, 2018
** env.c
** File description:
** env functions
*/

#include "special_var.h"
#include "builtins.h"
#include "define.h"
#include <string.h>

enum { NB_BUILT = 4 };

static t_built	tab_mini[NB_BUILT] = {
	{"cd", &cd_built},
	{"setenv", &setenv_built},
	{"unsetenv", &unsetenv_built},
	{"exit", &exit_built}
};

int	exit_built(char **line, __attribute((unused)) t_node **env_list)
{
	if (my_strarraylen(line) == VALID)
		exit(SUCCESS);
	exit(atoi(line[1]));
	return (SUCCESS);
}

int	exec_builtins(char **line, t_node **env_list, t_files_info *info)
{
	for (int i = 0; i < NB_BUILT; ++i) {
		if (strcmp(tab_mini[i].builtin, line[0]) == SUCCESS) {
			if ((tab_mini[i].ptr)(line, env_list) == FAILURE)
				return (FAILURE);
		}
	}
	if (strcmp("env", line[0]) == SUCCESS)
		return (env_built(line, env_list, info));
	if (strcmp("alias", line[0]) == SUCCESS)
		return (alias_cmd(info->alias_list, line));
	if (strcmp("!", line[0]) == SUCCESS)
		return (show_history(info->hist_list));
	if (strcmp("set", line[0]) == SUCCESS)
		return (special_var(line, &info->spec_var_list));
	return (SUCCESS);
}
