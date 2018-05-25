/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** rexp_rule
*/

#include "42sh.h"

t_tree	*rexp_rule(t_node **cmd_list)
{
	t_tree *tree = create_node();

	tree->left = cmd_rule(cmd_list);
	if (!tree->left) {
		free(tree);
		return (NULL);
	}
	if (check_token(cmd_list, R_REDIRECT, tree) == false
	&& check_token(cmd_list, L_REDIRECT, tree) == false
	&& check_token(cmd_list, DR_REDIRECT, tree) == false
	&& check_token(cmd_list, DL_REDIRECT, tree) == false)
		return (ret_node(tree, tree->left));
	if (((t_parser *)(*cmd_list)->data)->visited == true)
		return (NULL);
	tree->right = cmd_rule(cmd_list);
	if (!tree->right) {
		free(tree->right);
		return (NULL);
	}
	return (tree);
}
