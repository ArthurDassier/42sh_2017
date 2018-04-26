/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** functions for cd builtin
*/
#include "minishell2.h"

static void	change_pwd(t_node **head, char *str)
{
	char	**line = malloc(sizeof(*line) * 4);
	char	buf[500];

	line[0] = my_strdup("setenv");
	line[1] = my_strdup("OLDPWD");
	line[2] = my_strdup(getcwd(buf, 500));
	line[3] = NULL;
	setenv_built(line, head);
	free(line[0]);
	free(line[1]);
	free(line[2]);
	free(line);
	chdir(str);
}

static void	only_cd(t_node **head, char *str)
{
	if ((str = get_env_content(*head, "HOME")) == NULL) {
		my_putstr("cd: No home directory.\n");
		return;
	}
	change_pwd(head, str);
}

static void	normal_cd(t_node **head, char **line)
{
	struct stat	s;

	if (stat(line[1], &s) == 0 && S_ISDIR(s.st_mode))
		change_pwd(head, line[1]);
	else {
		my_putstr(line[1]);
		my_putstr(": Not a directory.\n");
	}
}

static char	**get_cd(char *str, t_node **head)
{
	if (str == NULL) {
		my_putstr("cd: No variable OLDPWD.\n");
		return (NULL);
	}
	change_pwd(head, str);
	return (NULL);
}

char	**cd_built(char **line, t_node **head)
{
	char	*str = get_env_content(*head, "OLDPWD");

	if (my_strarraylen(line) == 1) {
		only_cd(head, str);
		return (NULL);
	}
	if (my_strcmp(line[1], "-") == 0) {
		if (get_cd(str, head) == NULL)
			return (NULL);
	} else if (my_strcmp(line[1], "~") == 0) {
		if ((str = get_env_content(*head, "HOME")) == NULL) {
			my_putstr("cd: No home directory.\n");
			return (NULL);
		}
		change_pwd(head, str);
	} else {
		normal_cd(head, line);
	}
	return (NULL);
}