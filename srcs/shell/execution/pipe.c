/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** pipe
*/

#include "42sh.h"

// Father process
static void	p_father(int *pipefd, int dupfd, t_tree *tree,
t_node **env_list)
{
	dupfd = dup(0);
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	pipexp_exec(tree->right, env_list);
	dup2(dupfd, 0);
	close(pipefd[0]);
}

bool	pipe_exec(t_tree *tree, t_node **env_list)
{
	int	dupfd = 0;
	int	pipefd[2];

	pipe(pipefd);
	dupfd = dup(1);
	dup2(pipefd[1], 1);
	cmd_exec(tree->left, env_list);
	dup2(dupfd, 1);
	close(dupfd);
	p_father(pipefd, dupfd, tree, env_list);
	return (true);
}