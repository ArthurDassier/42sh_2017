/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** special_char_function
*/

#include "line.h"
#include "ncurses_define.h"

int	do_nothing(__attribute((unused)) char **line,
__attribute((unused)) const char *prompt,
__attribute((unused)) t_history **hist_list)
{
	return (1);
}

int	special_char_function(t_readline *rd,
t_history **hist_list, int *pos, int (**buf_function)(__attribute((unused)) char **,
__attribute((unused)) const char *, __attribute((unused)) t_history **hist_list))
{
	switch (rd->buf) {
	case CTR_L :
		buf_function[CTR_L](&(rd->line), rd->prompt, hist_list);
		return (1);
	case CTR_R : return (1);
	case CTR_K : return (1);
	case CTR_U : return (1);
	case CTR_Y : return (1);
	case DEL : return (1);
	case TAB :
		if (buf_function[TAB](&(rd->line), rd->prompt, hist_list) == 1)
			return (2);
		return (1);
	case ARROW :
		buf_function[find_key(rd->line, pos)]((&rd->line),
		rd->prompt, hist_list);
		return (1);
	}
	return (0);
}