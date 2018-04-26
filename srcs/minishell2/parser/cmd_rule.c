/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** cmd_rule
*/

#include "minishell2.h"

t_tree	*cmd_rule(t_node **cmd_list)
{
	t_tree *tree = create_node();

	if (check_token(cmd_list, WORD, tree) == true
	|| check_token(cmd_list, BUILTIN, tree) == true
	|| check_token(cmd_list, CMD, tree) == true)
		return (tree);
	return (NULL);
}