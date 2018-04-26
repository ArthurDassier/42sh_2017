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