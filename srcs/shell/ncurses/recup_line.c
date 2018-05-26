/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** recup_line
*/

#include "my.h"
#include "line.h"
#include "ncurses_define.h"
#include "list.h"
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
(__attribute((unused)) char **line, __attribute((unused)) const char *prompt,
__attribute((unused)) t_node **hist_list))
{
	buf_function[0] = &do_nothing;
	buf_function[CTR_L] = &ctr_l;
	buf_function[RIGHT_KEY] = &move_right;
	buf_function[LEFT_KEY] = &move_left;
	buf_function[UP_KEY] = &history_up;
	buf_function[DOWN_KEY] = &history_down;
	buf_function[TAB] = &auto_completion;
}

static t_readline	*init_rd_struct(const char *prompt)
{
	t_readline	*rd = malloc(sizeof(t_readline));

	rd->size = 10;
	rd->line = malloc(sizeof(char) * 10);
	memset(rd->line, '\0', rd->size);
	rd->prompt = prompt;
	return (rd);
}

static char	*read_loop(const char *prompt, t_node **hist_list)
{
	t_readline	*rd = init_rd_struct(prompt);
	int		i = 0;
	int		pos = 0;
	int		ret = 0;
	t_node	*tmp = *hist_list;
	static int	(*buf_function[177])(__attribute((unused)) char **,
	__attribute((unused)) const char *,
	__attribute((unused)) t_node **);

	init_buf_function_tab(buf_function);
	while (read(0, &(rd->buf), 1) != 0) {
		ret = analyse_call_from_read(rd, &pos, &tmp, buf_function);
		if (ret == -1)
			break;
		else if (ret == -2)
			continue;
		realloc_line(rd, &i);
	}
	return (rd->line);
}

char	*recup_line(const char *prompt, t_node **hist_list)
{
	char	*term = NULL;
	char	*line = NULL;

	if (isatty(0) == 0)
		return (get_next_line(0));
	write(1, prompt, strlen(prompt));
	canonique_mode(1);
	term = getenv("TERM");
	if (tgetent(NULL, term) != 1)
		return (NULL);
	line = read_loop(prompt, hist_list);
	canonique_mode(0);
	if (strlen(line) > 0) {
		put_in_history(hist_list, line);
		printf("\n");
	} else
		return (NULL);
	return (line);
}