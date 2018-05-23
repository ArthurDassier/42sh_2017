/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** change_line
*/

#include "42sh.h"

static bool	is_background(char **line)
{
	int	i = 0;

	while (line[i + 1] != NULL)
		++i;
	if (line[i][strlen(line[i] - 1)] == '&') {
		line[i] = NULL;
		return (true);
	}
	return (false);
}

int	change_line(char **line, t_files_info *info)
{
	change_for_alias(info->alias_list, line);
	if (changes_from_history(&info->hist_list, line) == -1)
		return (FAILURE);
	info->background  = is_background(line);
	return (SUCCESS);
}