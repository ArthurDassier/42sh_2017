/*
** EPITECH PROJECT, 2018
** ncurses
** File description:
** line
*/

#ifndef LINE_H_
	#define LINE_H_

#include "history.h"

typedef struct	s_readline
{
	char		*line;
	const char	*prompt;
	char		buf;
	int		size;
}			t_readline;

void	realloc_line(t_readline *, int *);
void	canonique_mode(int);
char	*recup_line(const char *, t_history **);
int	find_key(char *, int *);
char	*del_char(int *, char *, const char *);
char	*suppr_char(int *, char *, const char *);
char	*write_char(char, int *, char *, const char *);
void	rewrite_prompt_line(char *, const char *, int);
int	call_char_function(t_readline *, int *);

int	analyse_call_from_read(t_readline *, int *, t_history **,
int (**)(__attribute((unused)) char **,
__attribute((unused)) const char *, __attribute((unused)) t_history **));

int	special_char_function(t_readline *,
t_history **, int *, int (**)(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history **));

int	history_up(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history **);

int	history_down(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history **);

int	do_nothing(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history **);

int	move_right(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history **);

int	move_left(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history **);

int	auto_completion(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_history **);

int	ctr_l(__attribute((unused))char **str,
__attribute((unused)) const char *,
__attribute((unused)) t_history **);

#endif /* !LINE_H_ */
