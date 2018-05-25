/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for cd builtin
*/

#include "builtins.h"
#include "define.h"
#include <string.h>

static int	only_cd(t_node **env_list, char *str)
{
	if ((str = get_env_content(*env_list, "HOME")) == NULL) {
		my_putstr("cd: No home directory.\n");
		return (FAILURE);
	}
	change_pwd(env_list, str);
	return (SUCCESS);
}

int	cd_built(char **line, t_node **env_list)
{
	char	*str = get_env_content(*env_list, "OLDPWD");

	if (my_strarraylen(line) == VALID) {
		if (only_cd(env_list, str) == FAILURE)
			return (FAILURE);
		return (SUCCESS);
	}
	if (cd_special_cases(line, env_list, str) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}