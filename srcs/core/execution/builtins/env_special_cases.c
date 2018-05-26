/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** env_special_cases
*/

#include "builtins.h"
#include "const_values.h"
#include <stdlib.h>
#include <string.h>

int	unset_name(char **line, t_node **env_list)
{
	char **save;
	int i = 0;

	save = calloc(sizeof(char *) * (my_strarraylen(line) + 2) + 1, 0);
	if (!save)
		return (FAILURE);
	for (i = 0; i < 2; ++i) {
		save[i] = malloc(sizeof(char) * strlen(line[i]) + 1);
		if (!save)
			return (FAILURE);
		strcpy(save[i], line[i]);
	}
	save[2] = malloc(sizeof(char) * strlen(line[1] + 8) + 1);
	strcpy(save[2], line[1] + 8);
	save[3] = 0;
	rm_var(save, env_list);
	return (SUCCESS);
}