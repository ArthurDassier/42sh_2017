/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** s_rule
*/

#include "shell.h"
#include "const_values.h"
#include <stdlib.h>
#include <string.h>

t_tree	*create_node(void)
{
	t_tree	*new = malloc(sizeof(*new));

	if (!new)
		exit(FAILURE);
	new->right = NULL;
	new->left = NULL;
	return (new);
}

bool	check_token(t_node **cmd_list, e_token token, t_tree *tree)
{
	if (((t_parser *)((*cmd_list)->data))->token == token) {
		tree->cmd.token = ((t_parser *)((*cmd_list)->data))->token;
		tree->cmd.name = get_name_cmd(cmd_list);
		return (true);
	}
	return (false);

}

t_tree *ret_node(t_tree *tree, t_tree *ret)
{
	free(tree);
	return (ret);
}

t_tree	*s_rule(t_node **cmd_list)
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
	tree->right = s_rule(cmd_list);
	if (!tree->right) {
		free(tree->right);
		return (NULL);
	}
	return (tree);
}