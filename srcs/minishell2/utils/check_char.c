/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** check_char
*/
#include "minishell2.h"

int	check_char(char *str)
{
	for (int i = 0; str[i]; ++i) {
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v'
		&& str[i] != '\r' && str[i] != '\n')
			return (SUCCESS);
	}
	return (FAILURE);
}