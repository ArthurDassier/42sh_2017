/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** parentheses
*/

#include "42sh.h"

bool	parentheses(t_tree *tree, t_node **env_list)
{
	bool	ret;
	pid_t	pid = fork();
	int		status;

	if (pid == -1) {
		my_print_err("Failed\n");
	} else if (pid > 0) {
		waitpid(pid, &status, WUNTRACED);
	} else {
		ret = cmd_exec(tree, env_list);
	}
	exit(0);
	return (ret);
}