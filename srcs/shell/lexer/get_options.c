/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** options
*/
#include "42sh.h"
#include "const_values.h"
#include <string.h>

// Array of const value
static const char	*lexem_list[WORD] = {
	"&&", "|", "||", ";", ">", "<", ">>", "<<", "(", ")"
};

int	get_lexem(t_node **lexer_list, char **line, int index)
{
	int		i;

	for (i = 0; i < WORD && strcmp(line[index], lexem_list[i]) != 0; ++i);
	if (i == WORD)
		return (FAILURE);
	add_node(lexer_list, i, line[index]);
	return (SUCCESS);
}