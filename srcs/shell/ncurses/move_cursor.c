/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** move_cursor
*/

#include "line.h"
#include "ncurses_define.h"
#include "const_values.h"
#include "list.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	move_left(__attribute((unused)) char **line,
__attribute((unused)) const char *prompt,
__attribute((unused)) t_node **hist_list)
{
	cursorbackward(1);
	fflush(stdout);
	return (SUCCESS);
}

int	move_right(__attribute((unused)) char **line,
__attribute((unused)) const char *prompt,
__attribute((unused)) t_node **hist_list)
{
	cursorforward(1);
	fflush(stdout);
	return (SUCCESS);
}

int	find_key(char *line, int *pos)
{
	char		buf;
	int		max_x = 0;
	int		min_x = strlen(line) * -1;

	if (read(0, &buf, 1) == -1)
		return (FAILURE);
	if (read(0, &buf, 1) == -1)
		return (FAILURE);
	if (buf == LEFT_KEY && *pos > min_x) {
		*pos -= 1;
		return (LEFT_KEY);
	} else if (buf == RIGHT_KEY && *pos < max_x) {
		*pos += 1;
		return (RIGHT_KEY);
	}
	if (buf == DOWN_KEY)
		return (DOWN_KEY);
	else if (buf == UP_KEY)
		return (UP_KEY);
	return (SUCCESS);
}