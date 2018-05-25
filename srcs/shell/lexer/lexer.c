/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** lexer
*/
#include "42sh.h"
#include <stdlib.h>
#include <string.h>

void	add_node(t_node **cmd_list, e_token token, char *line)
{
	t_parser *parser = malloc(sizeof(*parser));

	if (!parser)
		exit(SUCCESS);
	parser->token = token;
	parser->name = strdup(line);
	parser->visited = false;
	insert_end(cmd_list, parser);
}

void	lexer(t_node **cmd_list, char **line, t_node *env_list)
{
	char **path;

	for (int i = 0; line[i]; ++i) {
		path = get_path(env_list);
		if ((get_lexem(cmd_list, line, i)) == FAILURE
		&& get_builtins(cmd_list, line[i]) == FAILURE)
			get_cmd(cmd_list, line[i], path);
	}
}
