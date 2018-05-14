/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** cd_special_cases
*/

#include "42sh.h"

void	change_pwd(t_node **env_list, char *str)
{
	char	**line = malloc(sizeof(*line) * 4);
	char	buf[500];

	line[0] = my_strdup("setenv");
	line[1] = my_strdup("OLDPWD");
	line[2] = my_strdup(getcwd(buf, 500));
	line[3] = NULL;
	setenv_built(line, env_list);
	free(line[0]);
	free(line[1]);
	free(line[2]);
	free(line);
	chdir(str);
}

static int	normal_cd(t_node **env_list, char **line)
{
	struct stat	s;

	if (stat(line[1], &s) == 0 && S_ISDIR(s.st_mode)) {
		change_pwd(env_list, line[1]);
		return (SUCCESS);
	} else {
		my_putstr(line[1]);
		my_putstr(": Not a directory.\n");
		return (FAILURE);
	}
}

static int get_cd(char *str, t_node **env_list)
{
	if (str == NULL) {
		my_putstr("cd: No variable OLDPWD.\n");
		return (FAILURE);
	}
	change_pwd(env_list, str);
	return (SUCCESS);
}

int cd_special_cases(char **line, t_node **env_list, char *str)
{
	if (my_strcmp(line[1], "-") == 0) {
		if (get_cd(str, env_list) == FAILURE)
			return (FAILURE);
		return (SUCCESS);
	} else if (my_strcmp(line[1], "~") == 0) {
		if ((str = get_env_content(*env_list, "HOME")) == NULL) {
			my_putstr("cd: No home directory.\n");
			return (FAILURE);
		}
		change_pwd(env_list, str);
		return (SUCCESS);
	} else {
		if (normal_cd(env_list, line) == FAILURE)
			return (FAILURE);
		return (SUCCESS);
	}
}