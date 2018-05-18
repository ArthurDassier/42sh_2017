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
(__attribute((unused)) char **str, __attribute((unused)) const char *prompt))
{
	buf_function[CTR_L] = &ctr_l;
	buf_function[ARROW] = &move_cursor;
	buf_function[TAB] = &auto_completion;
}

char	*recup_line(const char *prompt)
{
	char	buf;
	char	*term;
	int	size = 10;
	char	*str = malloc(sizeof(char) * size);
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
		else if (special_char_function(buf, &str, prompt,
		buf_function) == 1)
			continue;
		else {
			write(1, &buf, 1);
			str[i++] = buf;
			str[i] = '\0';
		}
		if (i == size) {
			size += size;
			str = realloc(str, size);
		}
	}
	canonique_mode(0);
	printf("\n");
	return (str);
}