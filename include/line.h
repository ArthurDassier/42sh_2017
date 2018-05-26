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
char	*recup_line(const char *, t_node **);
int	find_key(char *, int *);
char	*del_char(int *, char *, const char *);
char	*suppr_char(int *, char *, const char *);
char	*write_char(char, int *, char *, const char *);
void	rewrite_prompt_line(char *, const char *, int);
int	call_char_function(t_readline *, int *);

int	analyse_call_from_read(t_readline *, int *, t_node **,
int (**)(__attribute((unused)) char **,
__attribute((unused)) const char *, __attribute((unused)) t_node **));

int	special_char_function(t_readline *,
t_node **, int *, int (**)(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_node **));

int	history_up(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_node **);

int	history_down(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_node **);

int	do_nothing(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_node **);

int	move_right(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_node **);

int	move_left(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_node **);

int	auto_completion(__attribute((unused)) char **,
__attribute((unused)) const char *,
__attribute((unused)) t_node **);

int	ctr_l(__attribute((unused))char **str,
__attribute((unused)) const char *,
__attribute((unused)) t_node **);

#endif /* !LINE_H_ */
