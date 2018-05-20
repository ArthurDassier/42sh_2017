/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** special_char_function
*/

#include "line.h"
#include "ncurses_define.h"

int	do_nothing(__attribute((unused)) char **line,
__attribute((unused)) const char *prompt)
{
	return (1);
}

int	special_char_function(char buf, char **line, const char *prompt, int
(**buf_function) (__attribute((unused)) char **,
__attribute((unused)) const char *))
{
	switch (buf) {
	case CTR_L :
		buf_function[CTR_L](line, prompt);
		return (1);
	case CTR_R : return (1);
	case CTR_K : return (1);
	case CTR_U : return (1);
	case CTR_Y : return (1);
	case DEL : return (1);
	case TAB :
		buf_function[TAB](line, prompt);
		return (1);
	case ARROW :
		buf_function[find_key(*line)](line, prompt);
		return (1);
	}
	return (0);
}