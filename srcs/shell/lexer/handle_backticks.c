/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** handle_backticks
*/

#include "42sh.h"

static bool del_last_backticks(char **line, int index)
{
	while (line[index]) {
		if (strcmp(line[index], "`") == SUCCESS) {
			line[index] = NULL;
			return (true);

		}
		++index;
	}
	return (false);
}

char *handle_backticks(char **line, int index, t_node *env_list)
{
	t_node *cmd_list = NULL;
	t_tree *tree;
	char *buffer = malloc(sizeof(char) * 10000);
	int fd[2];
	unsigned int size;

	if (!buffer)
		return (NULL);
	if (del_last_backticks(line, index) == false) {
		my_print_err("Unmatched '`'.\n");
		return (NULL);
	}
	lexer(&cmd_list, line + index + 1, env_list);
	tree = s_rule(&cmd_list);
	pipe(fd);
	if (fork() == SUCCESS) {
			dup2(fd[1], STDOUT_FILENO);
			execlp("ls","ls", NULL);
	} else {
			size  = read(fd[0], buffer, 1000);
			if ((size > 0) && (size < sizeof(buffer)))
					buffer[size]='\0';
	}
	return (buffer);
}