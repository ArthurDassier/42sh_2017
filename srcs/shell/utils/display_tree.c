/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** display_tree
*/

#include "42sh.h"
#include <stdio.h>

void	display_tree(t_tree *tree)
{
	if (!tree)
		return;
	printf("node %d / %s\n", tree->cmd.token , tree->cmd.name[0]);
	if (tree->left != NULL) {
		printf("left -> %d / %s\n", tree->left->cmd.token,
		tree->left->cmd.name[0]);
	}
	if (tree->right != NULL) {
		printf("right -> %d / %s\n\n", tree->right->cmd.token,
		tree->right->cmd.name[0]);
	}
	display_tree(tree->left);
	display_tree(tree->right);
}