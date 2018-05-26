/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** handle_parentheses
*/

#include "42sh.h"
#include "const_values.h"

// Returns true if there's a right ). Returns false otherwise.
static bool check_if_valid(t_node *cmd_list)
{
	t_node *tmp = cmd_list;
	t_parser	*parser;

	do {
		parser = (t_parser *)tmp->data;
		if (parser->token == R_PAR)
			break;
		tmp = tmp->next;
	} while (tmp != cmd_list);
	if (tmp == cmd_list) {
		my_print_err("Too many ('s\n");
		return (false);
	}
	return (true);
}

int	handle_parentheses(t_node **cmd_list, t_tree *tree)
{
	if (check_if_valid(*cmd_list) == false)
		return (FAILURE);
	check_token(cmd_list, L_PAR, tree);
	tree->left = s_rule(cmd_list);
	return (SUCCESS);
}