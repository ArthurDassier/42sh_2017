/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** recup_line
*/

#include "line.h"
#include "ncurses_define.h"
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

// function to set the canonique mode with the var set OFF = 0 / ON = 1
void	canonique_mode(int set)
{
	static struct	termios old;
	static struct	termios new;

	if (set == 1) {
		tcgetattr(STDIN_FILENO, &old);
		new = old;
		cfmakeraw(&new);
		tcsetattr(STDIN_FILENO, TCSANOW, &new);
	} else if (set == 0)
		tcsetattr(STDIN_FILENO, TCSANOW, &old);
}

// initialisation of the function tab
static void	init_buf_function_tab(int (**buf_function)
(__attribute((unused)) char **line, __attribute((unused)) const char *prompt))
{
	buf_function[0] = &do_nothing;
	buf_function[CTR_L] = &ctr_l;
	buf_function[RIGHT_KEY] = &move_right;
	buf_function[LEFT_KEY] = &move_left;
	buf_function[TAB] = &auto_completion;
}

char	*recup_line(const char *prompt, t_history *list)
{
	char	buf;
	char	*term;
	int	size = 10;
	char	*line = malloc(sizeof(char) * size);
	int	i = 0;
	static int (*buf_function[177])(__attribute((unused)) char **,
	__attribute((unused)) const char *);

	init_buf_function_tab(buf_function);
	write(1, prompt, strlen(prompt));
	canonique_mode(1);
	term = getenv("TERM");
	if (tgetent(NULL, term) != 1)
		return (NULL);
	while (read(0, &buf, 1) != 0) {
		if (buf == ENTER_KEY)
			break;
		else if (special_char_function(buf, &line, prompt,
		buf_function) == 1)
			continue;
		else {
			write(1, &buf, 1);
			line[i++] = buf;
			line[i] = '\0';
		}
		if (i == size) {
			size += size;
			line = realloc(line, size);
		}
	}
	canonique_mode(0);
	put_in_history(list, line);
	printf("\n");
	return (line);
}