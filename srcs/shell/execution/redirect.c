/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** redirect
*/

#include "42sh.h"

const int BUFFER_SIZE = 2048;

bool	r_redirection(t_tree *tree, t_node **env_list)
{
	int	fd;
	int	dupfd = dup(1);

	if ((fd = open(tree->right->cmd.name[0], O_RDWR
	| O_CREAT | O_TRUNC, 0666)) == ERROR) {
		my_print_err("Failed to open");
		exit(FAILURE);
	}
	dup2(fd, 1);
	cmd_exec(tree->left, env_list);
	dup2(dupfd, 1);
	close(fd);
	close(dupfd);
	return (true);
}

bool	dr_redirection(t_tree *tree, t_node **env_list)
{
	int	fd;
	int	dupfd = dup(1);

	if ((fd = open(tree->right->cmd.name[0], O_RDWR
	| O_CREAT | O_APPEND, 0666)) == ERROR) {
		my_print_err("Failed to open");
		exit(FAILURE);
	}
	dup2(fd, 1);
	cmd_exec(tree->left, env_list);
	dup2(dupfd, 1);
	close(fd);
	close(dupfd);
	return (true);
}

bool	l_redirection(t_tree *tree, t_node **env_list)
{
	int	fd;
	int	dupfd = dup(0);

	if ((fd = open(tree->right->cmd.name[0], O_RDONLY)) == -1) {
		cmd_exec(tree->left, env_list);
		return (true);
	}
	dup2(fd, 0);
	cmd_exec(tree->left, env_list);
	dup2(dupfd, 0);
	close(fd);
	close(dupfd);
	return (true);
}

static	char *fill_buffer(t_tree *tree, char *buffer)
{
	char	*line = NULL;

	my_memset(buffer, BUFFER_SIZE);
	line = get_next_line(0);
	while (my_strcmp(line, tree->right->cmd.name[0]) != 0) {
		my_strcat(buffer, line);
		my_strcat(buffer, "\n");
		my_putstr("? ");
		free(line);
		line = get_next_line(0);
	}
	return (buffer);
}

bool	dl_redirection(t_tree *tree, t_node **env_list)
{
	int	pipefd[2];
	int	dupfd;
	char	buffer[BUFFER_SIZE];

	my_putstr("? ");
	fill_buffer(tree, buffer);
	pipe(pipefd);
	write(pipefd[1], buffer, my_strlen(buffer));
	close(pipefd[1]);
	dupfd = dup(0);
	dup2(pipefd[0], 0);
	cmd_exec(tree->left, env_list);
	dup2(dupfd, 0);
	close(dupfd);
	close(pipefd[0]);
	return (true);
}