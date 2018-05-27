/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history
*/

#ifndef HISTORY_H_
	#define HISTORY_H_

#include "list.h"

typedef struct	s_history
{
	char		*line;
	char		*timestamp;
}			t_history;

int	find_in_history(t_node *, char **);
int	check_in_history(char **, t_node *, int *, int);
int	print_no_event(int);
int	recup_index(char *line);
void	put_in_history(t_node **, char *);
char	*history_completion(t_node *, char *, const char *);
int	show_history(t_node *);
int	changes_from_history(t_node **, char **line);

#endif /* !HISTORY_H_ */
