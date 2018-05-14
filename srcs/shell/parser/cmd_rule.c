/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** cmd_rule
*/

#include "42sh.h"

t_tree	*cmd_rule(t_node **cmd_list)
{
	t_tree *tree = create_node();

	if (check_token(cmd_list, WORD, tree) == true
	|| check_token(cmd_list, BUILTIN, tree) == true
	|| check_token(cmd_list, CMD, tree) == true)
		return (tree);
	return (NULL);
}