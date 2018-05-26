/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** quotes_utils
*/

#include "quotes.h"
#include "define.h"
#include <string.h>

char *dollar_specials(char *line_one, char *line_two, t_quotes *quotes_st)
{
	line_one = strcat(line_one, line_two);
	line_one = delete_special(line_one);
	line_one = handle_dollars(line_one, quotes_st);
	return (line_one);
}

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
