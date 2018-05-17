/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** options
*/
#include "42sh.h"

// Array of const value
static const char	*lexem_list[WORD] = {
	"&&", "|", "||", ";", ">", "<", ">>", "<<", "(", ")", "`"
};

int	get_lexem(t_node **lexer_list, char **line, int index, t_node *env_list)
{
	int		i;
	char	**save;
	char	**path;

	for (i = 0; i < WORD && my_strcmp(line[index], lexem_list[i]) != 0; ++i);
	if (i == WORD)
		return (FAILURE);
	if (i == BACKTICKS) {
		save = delim_lexem(handle_backticks(line, index, env_list), " \t\r");
		if (!save)
			return (FAILURE);
		path = get_path(env_list);
		for (int j = 0; save[j]; ++j) {
			get_cmd(lexer_list, save[j], path);
			return (SUCCESS);
		}
	}
	add_node(lexer_list, i, line[index]);
	return (SUCCESS);
}