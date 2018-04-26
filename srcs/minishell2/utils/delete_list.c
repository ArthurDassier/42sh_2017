/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** delete_list
*/

#include "minishell2.h"

void	delete_tab(void *data)
{
	char **line = (char **)data;

	for (int i = 0; line[i]; ++i)
		free(line[i]);
	free(line);
}