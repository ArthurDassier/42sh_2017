/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** separators
*/

#include "42sh.h"

bool	separators_exec(t_tree *tree, t_node **env_list)
{
	bool	ret = cmd_exec(tree, env_list);

	return (ret);
}