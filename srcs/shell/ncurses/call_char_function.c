/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** call_char_function
*/

#include "ncurses_define.h"
#include "line.h"
#include "list.h"
#include "define.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	realloc_line(t_readline *rd, int *i)
{
	*i += 1;
	if (*i == rd->size - 1) {
		rd->size += rd->size;
		rd->line = realloc(rd->line, rd->size + 1);
		rd->line[rd->size] = '\0';
	}
}

int	call_char_function(t_readline *rd, int *pos)
{
	switch (rd->buf) {
	case CTR_D :
		if (strlen(rd->line) != 0)
			return (0);
		return (-1);
	case ENTER_KEY :
		if (strlen(rd->line) == 0)
			rd->line[0] = ' ';
		return (-1);
	case DEL :
		del_char(pos, rd->line, rd->prompt);
		return (-2);
	case SUPPR :
		suppr_char(pos, rd->line, rd->prompt);
		return (-2);
	case CTR_C :
		cursorbackward(100);
		printf("\n%s", rd->prompt);
		fflush(stdout);
	}
	return (SUCCESS);
}

int	analyse_call_from_read(t_readline *rd, int *pos, t_node **tmp,
int (**buf_function)(__attribute((unused)) char **,
__attribute((unused)) const char *, __attribute((unused)) t_node **hist_list))
{
	int	ret = 0;
	int	curs = 0;

	if ((ret = call_char_function(rd, pos)) == -1)
		return (-1);
	else if (ret == -2)
		return (-2);
	if ((curs = special_char_function(rd, tmp,
	pos, buf_function)) == 1)
		return (-2);
	else if (curs == 2)
		*pos = 0;
	else
		rd->line = write_char(rd->buf, pos, rd->line, rd->prompt);
	return (SUCCESS);
}