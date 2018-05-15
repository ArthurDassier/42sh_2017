/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** ignore_env
*/

#include "42sh.h"

static int	exec_no_env(char *line, char **tab)
{
	struct	stat s;
	int		status;
	pid_t	pid = fork();

	if (pid == ERROR) {
		my_print_err("Failed\n");
	} else if (pid > 0) {
		waitpid(pid, &status, WUNTRACED);
		handling_sig(status);
	} else {
		if ((stat(line, &s) == 0 && S_ISDIR(s.st_mode))
		|| (access(line, X_OK) == ERROR)) {
			my_putstr(line);
			my_putstr(": Permission denied.\n");
			exit(VALID);
		} else {
			execve(line, tab, NULL);
		}
	}
	return (SUCCESS);
}

int	ignore_env(char **line, __attribute((unused)) t_node **env_list)
{
	int	size = my_strarraylen(line);

	if (size < 3)
		return (SUCCESS);
	if (size == 4 && strcmp(line[2], "sh") == SUCCESS
	&& access(line[3], F_OK) != ERROR) {
		exec_no_env(line[3], line);
		return (SUCCESS);
	}
	if (size == 3 && strncmp(line[2], "./", 2) == SUCCESS
	&& access(line[2], F_OK) != ERROR) {
		exec_no_env(line[2], line);
		return (SUCCESS);
	}
	return (SUCCESS);
}