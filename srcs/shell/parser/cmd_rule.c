/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** cmd_rule
*/

#include "42sh.h"

static t_node *save_par;

t_tree	*cmd_rule(t_node **cmd_list)
{
	t_tree *tree = create_node();

	if (((t_parser *)((*cmd_list)->data))->token == L_PAR) {
		save_par = *cmd_list;
		if (handle_parentheses(cmd_list, tree) == true)
			return (tree);
	}
	if (((t_parser *)((*cmd_list)->data))->token == R_PAR) {
		delete_node(cmd_list, ")");
		return (tree);
	}
	if (check_token(cmd_list, WORD, tree) == true
	|| check_token(cmd_list, BUILTIN, tree) == true
	|| check_token(cmd_list, CMD, tree) == true)
		return (tree);
	return (NULL);
}