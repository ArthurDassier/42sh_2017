/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** exp_rule
*/

#include "42sh.h"
#include <stdlib.h>
#include <string.h>

t_tree	*exp_rule(t_node **cmd_list)
{
	t_tree *tree = create_node();

	tree->left = pipexp_rule(cmd_list);
	if (!tree->left) {
		free(tree);
		return (NULL);
	}
	if (check_token(cmd_list, AND, tree) == false
	&& check_token(cmd_list, OR, tree) == false)
		return (ret_node(tree, tree->left));
	if (((t_parser *)(*cmd_list)->data)->visited == true)
		return (NULL);
	tree->right = exp_rule(cmd_list);
	if (!tree->right) {
		free(tree->right);
		return (NULL);
	}
	return (tree);
}
