/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** semiexp_rule
*/

#include "42sh.h"

t_tree	*semiexp_rule(t_node **cmd_list)
{
	t_tree *tree = create_node();

	tree->left = exp_rule(cmd_list);
	if (!tree->left) {
		free(tree);
		return (NULL);
	}
	if (check_token(cmd_list, S_COLON, tree) == false)
		return (ret_node(tree, tree->left));
	if (((t_parser *)(*cmd_list)->data)->visited == true)
		return (tree);
	tree->right = semiexp_rule(cmd_list);
	if (!tree->right) {
		free(tree->right);
		return (NULL);
	}
	return (tree);
}