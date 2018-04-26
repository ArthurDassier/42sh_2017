/*
** EPITECH PROJECT, 2017
** list.h
** File description:
** Header file for linked lists
*/
#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>

typedef struct	s_node {
	void		*data;
	struct s_node	*next;
	struct s_node	*prev;
}		t_node;

int	get_size_list(t_node *head);
t_node	*find_node(t_node *head, int (*cmp)(void *data,
	void *data_cmp), void *to_find);
void	free_list(t_node *list, void (*ptr)(void *data));
void	display_list(t_node *head, void (*ptr)(void *data));
void	my_sort_list(t_node *list, int (*ptr)(void *data, void *data_2));
void	insert_end(t_node **head, void *data);

#endif /* !LIST_H_ */