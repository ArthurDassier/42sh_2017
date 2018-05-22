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
	if (strcmp("alias", line[0]) == SUCCESS)
		return (alias_cmd(info->alias_list, line));
	if (strcmp("!", line[0]) == SUCCESS)
		return (show_history(info->hist_list));
	else if (line[0][0] == '!')
		return (find_in_history(info->hist_list, line));
	return (SUCCESS);
}