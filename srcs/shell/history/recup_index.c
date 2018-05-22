/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** recup_index
*/

#include <stdlib.h>

int	recup_index(char *line)
{
	int	i = 0;

	while (line[i] != '\0') {
		line[i] = line[i + 1];
		++i;
	}
	return (atoi(line));
}