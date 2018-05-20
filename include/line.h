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
char	*recup_line(const char *, t_history **);
int	find_key(char *);

int	special_char_function(char, char **, const char *,
t_history *, int (**)(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history *));

int	history_up(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history *);

int	do_nothing(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history *);

int	move_right(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history *);

int	move_left(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history *);

int	auto_completion(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history *);

int	ctr_l(__attribute((unused))char **str,
__attribute((unused)) const char *,
__attribute((unused)) t_history *);

#endif /* !LINE_H_ */
