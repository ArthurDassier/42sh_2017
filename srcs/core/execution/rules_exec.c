/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** rules_exec
*/

#include "shell.h"

bool	s_exec(t_tree *tree, t_node **env_list, t_files_info *info)
{
	bool	ret;

	if (tree->cmd.token != S_COLON)
		ret = exp_exec(tree, env_list, info);
	else {
		ret = s_exec(tree->left, env_list, info);
		if (tree->right)
			ret = s_exec(tree->right, env_list, info);
	}
	return (ret);
}

bool	exp_exec(t_tree *tree, t_node **env_list, t_files_info *info)
{
	bool	ret;

	if (tree->cmd.token != AND && tree->cmd.token != OR)
		ret = pipexp_exec(tree, env_list, info);
	else {
		ret = separators_exec(tree->left, env_list, info);
		if ((tree->cmd.token == AND && !ret)
		|| (tree->cmd.token == OR && ret))
			ret = exp_exec(tree->right, env_list, info);
	}
	return (ret);
}

bool	pipexp_exec(t_tree *tree, t_node **env_list,
t_files_info *info)
{
	bool	ret;

	if (tree->cmd.token != PIPE)
		ret = rexp_exec(tree, env_list, info);
	else {
		if (tree->cmd.token == PIPE)
			ret = pipe_exec(tree, env_list, info);
	}
	return (ret);
}

bool	rexp_exec(t_tree *tree, t_node **env_list, t_files_info *info)
{
	bool	ret;

	if (tree->cmd.token != R_REDIRECT && tree->cmd.token != L_REDIRECT
	&& tree->cmd.token != DR_REDIRECT && tree->cmd.token != DL_REDIRECT)
		ret = cmd_exec(tree, env_list, info);
	else {
		if (tree->cmd.token == R_REDIRECT)
			ret = r_redirection(tree, env_list, info);
		if (tree->cmd.token == L_REDIRECT)
			ret = l_redirection(tree, env_list, info);
		if (tree->cmd.token == DR_REDIRECT)
			ret = dr_redirection(tree, env_list, info);
		if (tree->cmd.token == DL_REDIRECT)
			ret = dl_redirection(tree, env_list, info);
	}
	return (ret);
}

bool	cmd_exec(t_tree *tree, t_node **env_list, t_files_info *info)
{
	bool	ret = false;

	if (tree->cmd.token == L_PAR)
		ret = s_exec(tree->left, env_list, info);
	if (tree->cmd.token == BUILTIN)
		ret = exec_builtins(tree->cmd.name, env_list, info);
	if (tree->cmd.token == CMD || tree->cmd.token == WORD)
		ret = exec_cmd(tree->cmd.name, *env_list, info);
	return (ret);
}
