/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** options
*/
#include "minishell2.h"

// Array of const value
static const char	*lexem_list[WORD] = {
	"&&", "|", "||", ";", ">", "<", ">>", "<<"
};

int	get_lexem(t_node **lexer_list, char *str)
{
	int	i;

	for (i = 0; i < WORD && my_strcmp(str, lexem_list[i]) != 0; ++i);
	if (i == WORD)
		return (FAILURE);
	add_node(lexer_list, i, str);
	return (SUCCESS);
}