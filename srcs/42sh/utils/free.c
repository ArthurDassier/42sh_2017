/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** free
*/

#include "42sh.h"

void free_lexer(void *data)
{
	t_parser *parser = (t_parser *)data;

	free(parser->name);
}

static void	free_cmd(t_cmd *cmd)
{
	for (int i = 0; cmd->name[i]; ++i)
		free(cmd->name[i]);
	free(cmd->name);
}
void	free_tree(t_tree *tree)
{
	if (!tree)
		return;
	free_cmd(&(tree->cmd));
	free_tree(tree->left);
	free_tree(tree->right);
	free(tree);
}