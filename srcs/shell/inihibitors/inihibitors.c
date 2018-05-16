/*
** EPITECH PROJECT, 2018
** inihibitors.c
** File description:
** Arthur
*/

#include "42sh.h"

static char *check_inib(char *str, int *i)
{
	char *tmp;

	if (str[*i + 1] == '\\') {
		str[*i] = ' ';
		*i = *i + 1;
	} else {
		str[*i] = ' ';
		my_putstr("? ");
		tmp = get_next_line(0);
		if (tmp == NULL)
			return (str);
		my_strcat(str, tmp);
	}
	return (str);
}

char *inib(char *str)
{
	int i = 0;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0') {
		if (str[i] == '\\') {
			str = check_inib(str, &i);
		}
		++i;
	}
	return (str);
}
