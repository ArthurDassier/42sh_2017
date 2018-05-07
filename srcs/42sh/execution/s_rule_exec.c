/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** s_rule_exec
*/

#include "42sh.h"

bool	s_exec(t_tree *tree, t_node **env_list)
{
	bool	ret;

	if (tree->cmd.token != L_PARENTHESE)
		ret = semiexp_exec(tree, env_list);
	else {
		ret = s_exec(tree->left, env_list);
		if (tree->right)
			ret = s_exec(tree->right, env_list);
	}
	return (ret);
}
