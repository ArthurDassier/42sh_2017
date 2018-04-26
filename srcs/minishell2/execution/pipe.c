/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** pipe
*/

#include "minishell2.h"

// Father process
static void	p_father(int *pipefd, int dupfd, t_tree *tree,
t_node **env_list)
{
	int	status;

	dupfd = dup(0);
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	pipexp_exec(tree->right, env_list);
	dup2(dupfd, 0);
	close(dupfd);
	close(pipefd[0]);
	wait(&status);
}

bool	pipe_exec(t_tree *tree, t_node **env_list)
{
	int	pid;
	int	dupfd = 0;
	int	pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == 0) {
		dupfd = dup(1);
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		cmd_exec(tree->left, env_list);
		dup2(dupfd, 1);
		close(dupfd);
		close(pipefd[1]);
		exit(0);
	} else {
		p_father(pipefd, dupfd, tree, env_list);
	}
	return (true);
}