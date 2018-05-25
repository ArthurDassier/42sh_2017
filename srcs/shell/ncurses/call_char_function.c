/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** call_char_function
*/

#include "ncurses_define.h"
#include "line.h"

int	call_char_function(char buf, char *line, int *pos, const char *prompt)
{
	if (buf == CTR_D)
		return (1);
	else if (buf == ENTER_KEY) {
		if (line[0] == '\0')
			line[0] = ' ';
		return (1);
	}
	if (buf == DEL) {
		del_char(pos, line, prompt);
		return (2);
	} else if (buf == SUPPR) {
		suppr_char(pos, line, prompt);
		return (2);
	}
	return (0);
}