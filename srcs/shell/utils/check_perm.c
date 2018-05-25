/*
** EPITECH PROJECT, 2018
** check_perm.c
** File description:
** check permissions and file
*/
#include "42sh.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void	check_perm(char **path, char **line, int i, t_node *head)
{
	struct stat	s;
	char		**tab = list_to_tab(head);

	if ((stat(path[i], &s) == 0 && S_ISDIR(s.st_mode))
	|| (access(path[i], X_OK) == ERROR)) {
			my_putstr(path[i]);
			my_putstr(": Permission denied.\n");
			exit(VALID);
	} else if (access(path[i], X_OK) != ERROR) {
			execve(path[i], line, tab);
	}
}

void	check_perm_cmd(char **line, t_node *head)
{
	struct stat	s;

	if ((stat(line[0], &s) == 0 && S_ISDIR(s.st_mode))
	|| (access(line[0], X_OK) == ERROR)) {
			my_putstr(line[0]);
			my_putstr(": Permission denied.\n");
			exit(VALID);
	} else {
		exec_line(head, line);
	}
}