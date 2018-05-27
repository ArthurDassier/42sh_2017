/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** check_in_history
*/

#include "list.h"
#include "const_values.h"
#include "history.h"

int	check_in_history(char **line, t_node *hist_tmp, int *flag, int i)
{
	if (line[i][0] == '!' && line[i][1] != '\0') {
		if (find_in_history(hist_tmp,
		&line[i]) == ERROR)
			return (ERROR);
		*flag = 1;
	}
	return (SUCCESS);
}