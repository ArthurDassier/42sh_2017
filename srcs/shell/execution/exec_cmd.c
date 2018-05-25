/*
** EPITECH PROJECT, 2018
** minishell.c
** File description:
** minishell 1
*/

#include "42sh.h"
#include "define.h"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static int ret = false;

static int	cmd_not_found(char **line)
{
	my_putstr(line[0]);
	my_putstr(": Command not found.\n");
	exit(VALID);
}

int	check_path(char **line, char **path, t_node *env_list)
{
	int	i;

	for (i = 0; path != NULL && path[i] != 0; ++i) {
		add_com(path, line);
		exec_com(path, line, env_list);
	}
	return (i);
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
}

bool	exec_cmd(char **line, t_node *env_list, t_files_info *info)
{
	char	**path = get_path(env_list);
	int		status;
	pid_t	pid = fork();
	int		i;

	if (pid == ERROR) {
		my_print_err("Failed\n");
	} else if (pid > 0) {
		if (info->dwait_pipe == true)
			info->dwait_pipe = false;
		else if (info->background == true)
			waitpid(pid, &status, WNOHANG);
		else
			waitpid(pid, &status, WUNTRACED);
		handling_sig(status);
	} else {
		i = check_path(line, path, env_list);
		if ((path == NULL || path[i] == 0)
		&& (access(line[0], F_OK) != ERROR))
			check_perm_cmd(line, env_list);
		else
			cmd_not_found(line);
	}
	ret = WEXITSTATUS(status);
	return (status);
}