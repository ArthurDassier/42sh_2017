/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** env_chdir
*/

#include "42sh.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

static char **get_cmd_from_line(char **line)
{
	char	**cmd = malloc(sizeof(*cmd) * (my_strarraylen(line) - 2));
	int	j = 0;

	if (!cmd)
		return (NULL);
	for (int i = 3; line[i]; ++i) {
		cmd[j] = malloc(sizeof(char) * strlen(line[i]) + 1);
		if (!cmd)
			return (NULL);
		strcpy(cmd[j], line[i]);
		++j;
	}
	cmd[j] = NULL;
	return (cmd);
}

int	env_chdir(char **line, t_node **env_list, t_files_info *info)
{
	char	*str;
	struct stat	s;

	if (stat(line[2], &s) == SUCCESS && S_ISDIR(s.st_mode)) {
		change_pwd(env_list, line[2]);
	} else {
		my_putstr(line[2]);
		my_putstr(": Not a directory.\n");
		return (FAILURE);
	}
	exec_cmd(get_cmd_from_line(line), *env_list, info);
	str = get_env_content(*env_list, "OLDPWD");
	if (get_cd(str, env_list) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
