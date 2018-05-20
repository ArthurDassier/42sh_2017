/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** line
*/

#ifndef LINE_H_
	#define LINE_H_

#include "history.h"

void	canonique_mode(int);
char	*recup_line(const char *, t_history *);

int	find_key(char *);
int	special_char_function(char, char **, const char *, int (**)
(__attribute((unused)) char **, __attribute((unused)) const char *));

int	do_nothing(__attribute((unused)) char **line,
__attribute((unused)) const char *prompt);

int	move_right(__attribute((unused)) char **,
__attribute((unused)) const char *);

int	move_left(__attribute((unused)) char **,
__attribute((unused)) const char *);

int	auto_completion(__attribute((unused)) char **,
__attribute((unused)) const char *);

int	ctr_l(__attribute((unused))char **str,
__attribute((unused)) const char *prompt);

#endif /* !LINE_H_ */
