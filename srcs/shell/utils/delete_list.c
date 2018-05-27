/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** delete_list
*/

#include "shell.h"
#include <stdlib.h>

void	delete_tab(void *data)
{
	char **line = (char **)data;

	for (int i = 0; line[i]; ++i)
		free(line[i]);
	free(line);
}