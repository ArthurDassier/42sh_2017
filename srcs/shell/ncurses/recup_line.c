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
(__attribute((unused)) char **line, __attribute((unused)) const char *prompt,
__attribute((unused)) t_history **hist_list))
{
	buf_function[0] = &do_nothing;
	buf_function[CTR_L] = &ctr_l;
	buf_function[RIGHT_KEY] = &move_right;
	buf_function[LEFT_KEY] = &move_left;
	buf_function[UP_KEY] = &history_up;
	buf_function[DOWN_KEY] = &history_down;
	buf_function[TAB] = &auto_completion;
}

static void	write_char(char buf, int *pos, char *line, int *i, const char *prompt)
{
	char	*save = strdup(line);
	int	j = strlen(line);
	int	len = 0;
	int	tmp = *pos;

	if (*pos == 0) {
		write(1, &buf, 1);
		line[*i] = buf;
		*i += 1;
		line[*i] = '\0';
		return;
	}
	line = realloc(line, strlen(line) + 2);
	while (tmp < 0) {
		--j;
		++tmp;
	}
	line[j] = buf;
	while (save[j] != '\0') {
		line[j + 1] = save[j];
		++j;
	}
	line[j + 1] = '\0';
	free(save);
	len = strlen(prompt) + strlen(line);
	cursorbackward(len);
	fflush(stdout);
	write(1, prompt, strlen(prompt));
	write(1, line, strlen(line));
	len = strlen(line) + *pos - 1;
	*pos -= 2;
	cursorbackward(len);
	fflush(stdout);
}

static char	*read_loop(const char *prompt, t_history **hist_list)
{
	int		size = 10;
	char		buf;
	int		i = 0;
	int		pos = 0;
	t_history	*tmp = *hist_list;
	char		*line = malloc(sizeof(char) * size);
	static int	(*buf_function[177])(__attribute((unused)) char **,
	__attribute((unused)) const char *,
	__attribute((unused)) t_history **);

	memset(line, '\0', size);
	init_buf_function_tab(buf_function);
	while (read(0, &buf, 1) != 0) {
	//	history_completion(*hist_list, line);
		if (buf == CTR_D)
			break;
		if (buf == ENTER_KEY)
			break;
		else if (special_char_function(buf, &line, prompt, &tmp,
		&pos, buf_function) == 1)
			continue;
		else
			write_char(buf, &pos, line, &i, prompt);
		if (i == size) {
			size += size;
			line = realloc(line, size);
		}
	}
	return (line);
}

char	*recup_line(const char *prompt, t_history **hist_list)
{
	char	*term = NULL;
	char	*line = NULL;

	write(1, prompt, strlen(prompt));
	canonique_mode(1);
	term = getenv("TERM");
	if (tgetent(NULL, term) != 1)
		return (NULL);
	line = read_loop(prompt, hist_list);
	canonique_mode(0);
	if (line != NULL && line[0] != '\0') {
		put_in_history(hist_list, line);
		printf("\n");
	} else
		return (NULL);
	return (line);
}