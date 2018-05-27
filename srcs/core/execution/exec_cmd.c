/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** exec_cmd
*/

#include "shell.h"
#include "const_values.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static int	cmd_not_found(char **line)
{
	my_putstr(line[0]);
	my_putstr(": Command not found.\n");
	exit(VALID);
}

void	handling_sig(int status)
{
	if (WIFSIGNALED(status) != 0 && WTERMSIG(status) != 0) {
		if (WCOREDUMP(status) != 0 && WTERMSIG(status) == SIGSEGV)
			my_putstr("Segmentation fault (core dump)\n");
		else if (WTERMSIG(status) == SIGSEGV)
			my_putstr("Segmentation fault\n");
		if (WCOREDUMP(status) != 0 && WTERMSIG(status) == SIGFPE)
			my_putstr("Floating exception (core dump)\n");
		else if (WTERMSIG(status) == SIGFPE)
			my_putstr("Floating exception\n");
	}
}

void	exec_line(t_node *env_list, char **line)
{
	char	**tab = NULL;

	tab = list_to_tab(env_list);
	execve(line[0], line, tab);
	if (errno == ENOEXEC)
		printf("%s: Exec format error. Wrong architecture.\n", line[0]);
}

static void handle_big_input(t_files_info *info, int *status, pid_t pid)
{
	if (info->dwait_pipe == true)
			info->dwait_pipe = false;
	else if (info->background == true)
		waitpid(pid, status, WNOHANG);
	else
		waitpid(pid, status, WUNTRACED);
	handling_sig(*status);
}

bool	exec_cmd(char **line, t_node *env_list, t_files_info *info)
{
	char	**path = get_path(env_list);
	int		status = 0;
	pid_t	pid = fork();
	int		i;
	int		ret;

	if (pid == ERROR) {
		my_print_err("Failed\n");
	} else if (pid > 0) {
		handle_big_input(info, &status, pid);
	} else {
		i = check_path(line, path, env_list);
		if (i != FAILURE && (path == NULL || path[i] == NULL)
		&& (access(line[0], F_OK) != ERROR))
			check_perm_cmd(line, env_list);
		else
			cmd_not_found(line);
	}
	ret = WEXITSTATUS(status);
	return (ret != SUCCESS ? VALID : SUCCESS);
}