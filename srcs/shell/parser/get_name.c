/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** get_name
*/

#include "shell.h"
#include "const_values.h"
#include <stdlib.h>
#include <string.h>

static int	get_nb_word(t_node *cmd_list)
{
	t_node	*tmp = cmd_list;
	t_parser *parser = (t_parser *)cmd_list->data;
	int		count = 0;

	do {
		++count;
		tmp = tmp->next;
		parser = (t_parser *)tmp->data;
	} while (tmp != cmd_list && (parser->token == WORD
	|| parser->token == CMD || parser->token == BUILTIN));
	return (count);
}

static char	**get_args_opt(t_node **cmd_list)
{
	char	**tab = malloc(sizeof(*tab) * (get_nb_word(*cmd_list) + 1));
	int	i = 0;
	t_parser *parser = (t_parser *)(*cmd_list)->data;

	if (!tab)
		exit(FAILURE);
	do {
		parser->visited = true;
		tab[i] = strdup(parser->name);
		*cmd_list = (*cmd_list)->next;
		++i;
		parser = (t_parser *)(*cmd_list)->data;
	} while ((parser->token == WORD
	|| parser->token == CMD || parser->token == BUILTIN)
	&& parser->visited == false);
	tab[i] = NULL;
	return (tab);
}

char	**get_name_cmd(t_node **cmd_list)
{
	char		**tab = NULL;
	t_parser	*parser = (t_parser *)(*cmd_list)->data;

	if (parser->token == CMD
	|| parser->token == BUILTIN) {
		tab = get_args_opt(cmd_list);
		return (tab);
	}
	tab = malloc(sizeof(*tab) * 2);
	if (!tab)
		exit(FAILURE);
	parser->visited = true;
	tab[0] = strdup(parser->name);
	tab[1] = NULL;
	*cmd_list = (*cmd_list)->next;
	return (tab);
}