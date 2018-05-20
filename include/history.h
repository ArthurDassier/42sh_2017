/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history
*/

#ifndef HISTORY_H_
	#define HISTORY_H_

typedef struct	s_history
{
	char			*line;
	char			*timestamp;
	struct s_history	*next;
	struct s_history	*prev;
}				t_history;

#endif /* !HISTORY_H_ */
