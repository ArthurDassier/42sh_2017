/*
** EPITECH PROJECT, 2018
** inihibitors.c
** File description:
** Arthur
*/

#include "42sh.h"

char	*decal_line(char *line, int i)
{
	while (line[i] != '\0') {
		line[i] = line[i + 1];
		++i;
	}
	return (line);
}

char	*delete_backslash(char *line)
{
	int i = 0;

	while (line[i] != '\0') {
		if (line[i] == '\\')
			line = decal_line(line, i);
		++i;
	}
	return (line);
}

char	**handle_backslash(char **line)
{
	int	i = 0;

	while (line[i]) {
		if (line[i][0] == '\\' && line[i][1] == '\0')
			line[i][0] = ' ';
		++i;
	}
	return (line);
}

static char	*check_inib(char *str, int *i)
{
	char *tmp;
	char *s;

	if (str[*i + 1] == '\0' && str[*i - 1] != '\\') {
		str[*i] = ' ';
		my_putstr("? ");
		tmp = get_next_line(0);
		if (tmp == NULL)
			return (str);
		s = malloc(sizeof(char) * (strlen(tmp) + strlen(str) + 1));
		s = strcpy(s, str);
		s = strcat(s, tmp);
		free(tmp);
		free(str);
		return (s);
	}
	return (str);
}

char	*inib(char *str)
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
