/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** delim_words
*/

#include "shell.h"

bool	check_delim(char to_cmp, char *delim)
{
	for (int i = 0; delim[i]; ++i) {
		if (to_cmp == delim[i])
			return (true);
	}
	return (false);
}

static void	if_false(char *str, char *delim, int *result, int *i)
{
	int	lex = 0;

	while (str[*i] && check_delim(str[*i], delim) == false) {
		if (lex > 0) {
			lex = 0;
			*result += 1;
		}
		if (is_lexem(str + *i) != -1) {
			*result += 1;
			++lex;
		}
		*i += 1;
	}
}

int	delim_words(char *str, char *delim)
{
	int	result = 0;

	for (int i = 0; str[i]; ++i) {
		if (str[i] && check_delim(str[i], delim) == false) {
			++result;
			if_false(str, delim, &result, &i);
		}
		if (!str[i])
			break;
	}
	return (result);
}
