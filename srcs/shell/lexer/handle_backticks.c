/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** handle_backticks
*/

#include "42sh.h"

static void del_last_backticks(char **line, int index)
{
	while (line[index]) {
		if (strcmp(line[index], "`") == SUCCESS)
			line[index] = NULL;
		++index;
	}
}

static bool check_if_matching_quotes(char **line)
{
	int	count = 0;

	for (int i = 0; line[i]; ++i) {
		if (strcmp(line[i], "`") == SUCCESS)
			++count;
	}
	if (count % 2 == 0)
		return (true);
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
	if (check_if_matching_quotes(line) == false) {
		my_print_err("Unmatched '`'.\n");
		return (NULL);
	}
	del_last_backticks(line, index + 1);
	lexer(&cmd_list, line + index + 1, env_list);
	tree = s_rule(&cmd_list);
	pipe(fd);
	if (fork() == SUCCESS) {
			dup2(fd[1], STDOUT_FILENO);
			s_exec(tree, &env_list);
	} else {
			size = read(fd[0], buffer, 1000);
			if ((size > 0) && (size < sizeof(buffer)))
					buffer[size] = 0;
	}
	//free_tree(tree);
	//free_list(cmd_list, &free_lexer);
	return (buffer);
}