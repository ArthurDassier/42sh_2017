/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for cd builtin
*/
#include "42sh.h"

static int	only_cd(t_node **head, char *str)
{
	if ((str = get_env_content(*head, "HOME")) == NULL) {
		my_putstr("cd: No home directory.\n");
		return (FAILURE);
	}
	change_pwd(head, str);
	return (SUCCESS);
}

int	cd_built(char **line, t_node **head)
{
	char	*str = get_env_content(*head, "OLDPWD");

	if (my_strarraylen(line) == 1) {
		if (only_cd(head, str) == FAILURE)
			return (FAILURE);
		return (SUCCESS);
	}
	if (cd_special_cases(line, head, str) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}