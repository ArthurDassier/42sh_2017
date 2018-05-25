/*
** EPITECH PROJECT, 2018
** quotes_utils.c
** File description:
** Arthur
*/

#include "42sh.h"
#include <string.h>

char *inc_space(char *line, char *s, char sign)
{
	int	i = 0;
	int	j = 0;

	while (s[i] != sign)
		++i;
	++i;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r') {
		line[j] = s[i];
		++j;
		++i;
	}
	line[j] = '\0';
	return (line);
}

char *find_endspace(char *line, char *s, char sign)
{
	int	i = 0;
	int	j = strlen(line);
	int	nb_sign = 0;

	while (nb_sign != 2) {
		if (s[i] == sign)
			++nb_sign;
		++i;
	}
	i -= 2;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r')
		--i;
	++i;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\r') {
		line[j] = s[i];
		++j;
		++i;
	}
	line[j] = '\0';
	return (line);
}