/*
** EPITECH PROJECT, 2018
** minishell.c
** File description:
** minishell 1
*/
#include "42sh.h"

static void	cmd_not_found(char **line)
{
	my_putstr(line[0]);
	my_putstr(": Command not found.\n");
}

int	check_path(char **line, char **path, t_node *head)
{
	int	i;

	for (i = 0; path != NULL && path[i] != 0; ++i) {
		add_com(path, line);
		exec_com(path, line, head);
	}
	return (i);
}

static void	handling_sig(int status)
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

void	exec_line(t_node *head, char **line)
{
	char	**tab = NULL;

	tab = list_to_tab(head);
	execve(line[0], line, tab);
}

bool	exec_cmd(char **line, t_node *head)
{
	char	**path = get_path(head);
	int		status;
	pid_t	pid = fork();
	int		i;

	if (pid == -1) {
		my_print_err("Failed\n");
	} else if (pid > 0) {
		waitpid(pid, &status, WUNTRACED);
		handling_sig(status);
	} else {
		i = check_path(line, path, head);
		if ((path == NULL || path[i] == 0)
		&& (access(line[0], F_OK) != -1))
			check_perm_cmd(line, head);
		else {
			cmd_not_found(line);
			return (true);
		}
	}
	return (false);
}