/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** line
*/

#ifndef LINE_H_
	#define LINE_H_

int	special_char_function(char, char **, const char *, int (**)
(__attribute((unused)) char **, __attribute((unused)) const char *));

void	canonique_mode(int);

int	auto_completion(__attribute((unused)) char **,
__attribute((unused)) const char *);
int	ctr_l(__attribute((unused))char **str,
__attribute((unused)) const char *prompt);
int	move_cursor(__attribute((unused)) char **str,
__attribute((unused)) const char *prompt);

#endif /* !LINE_H_ */
