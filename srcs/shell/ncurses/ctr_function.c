/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** ctr_function
*/

#include "line.h"
#include <unistd.h>
#include <ncurses.h>
#include <termios.h>
#include <string.h>
#include <term.h>

int	ctr_l(__attribute((unused))char **str,
__attribute((unused)) const char *prompt)
{
	write(1, tgetstr("cl", 0), strlen(tgetstr("cl", 0)));
	write(1, prompt, strlen(prompt));
	write(1, *str, strlen(*str));
	return (0);
}