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

char	**env_built(char **line, t_node **head)
{
	(void)line;
	display_list(*head, &print_list);
	return (NULL);
}

char	**exit_built(char **line, t_node **head)
{
	(void)head;
	if (my_strarraylen(line) == 1)
		exit(0);
	exit(my_getnbr(line[1]));
	return (NULL);
}

int	exec_builtins(char **line, t_node **env)
{
	for (int i = 0; i < NB_BUILT; ++i) {
		if (my_strcmp(tab_mini[i].builtin, line[0]) == 0) {
			(tab_mini[i].ptr)(line, env);
			return (SUCCESS);
		}
	}
	return (SUCCESS);
}