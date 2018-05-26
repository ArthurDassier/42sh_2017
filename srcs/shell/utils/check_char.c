/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** check_char
*/
#include "42sh.h"
#include "const_values.h"

int	check_char(char *str)
{
	for (int i = 0; str[i]; ++i) {
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v'
		&& str[i] != '\r' && str[i] != '\n')
			return (SUCCESS);
	}
	return (FAILURE);
}