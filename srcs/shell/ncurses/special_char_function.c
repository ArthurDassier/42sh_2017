/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** special_char_function
*/

#include "line.h"
#include "const_values.h"
#include "list.h"
#include "ncurses_define.h"

int	do_nothing(__attribute((unused)) char **line,
__attribute((unused)) const char *prompt,
__attribute((unused)) t_node **hist_list)
{
	return (VALID);
}

int	special_char_function(t_readline *rd,
t_node **hist_list, int *pos, int (**buf_function)(__attribute((unused))
char **,
__attribute((unused)) const char *, __attribute((unused)) t_node **hist_list))
{
	switch (rd->buf) {
	case CTR_L :
		buf_function[CTR_L](&(rd->line), rd->prompt, hist_list);
		return (VALID);
	case CTR_R : return (VALID);
	case CTR_K : return (VALID);
	case CTR_U : return (VALID);
	case CTR_Y : return (VALID);
	case DEL : return (VALID);
	case TAB :
		if (buf_function[TAB](&(rd->line), rd->prompt, hist_list) == 1)
			return (2);
		return (VALID);
	case ARROW :
		buf_function[find_key(rd->line, pos)]((&rd->line),
		rd->prompt, hist_list);
		return (VALID);
	}
	return (SUCCESS);
}