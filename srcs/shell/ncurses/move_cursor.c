/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** move_cursor
*/

#include "line.h"
#include "ncurses_define.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

static void	move_left(void)
{
	canonique_mode(0);
	cursorbackward(1);
	fflush(stdout);
	canonique_mode(1);
}

static void	move_right(void)
{
	canonique_mode(0);
	cursorforward(1);
	fflush(stdout);
	canonique_mode(1);
}

int	move_cursor(__attribute((unused)) char **line,
__attribute((unused)) const char *prompt)
{
	static int	pos = 0;
	char		buf;
	int		max_x = 0;
	int		min_x = strlen(*line) * -1;

	if (read(0, &buf, 1) == -1)
		return (84);
	if (read(0, &buf, 1) == -1)
		return (84);
	if (buf == LEFT_KEY && pos > min_x) {
		move_left();
		--pos;
	} else if (buf == RIGHT_KEY && pos < max_x) {
		move_right();
		++pos;
	}
	return (0);
}