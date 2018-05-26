/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** special_var
*/

#ifndef SPECIAL_VAR_H_
#define SPECIAL_VAR_H_

#include "list.h"
#include "42sh.h"
#include "quotes.h"

/*
** Special variables
*/
t_node	*init_set(void);
void		print_var(t_node *);
int		special_var(char **, t_node **);
void		spec_var(t_save *, char *);
void		reset_spec(t_node **, t_node *, char *, int);
int		alphabetic_order(void *, void *);
t_save		*initialiser(char *, char *);

#endif /* !SPECIAL_VAR_H_ */
