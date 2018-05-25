/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** special_var
*/

#ifndef SPECIAL_VAR_H_
#define SPECIAL_VAR_H_

#include "list.h"
#include "quotes.h"

/*
** Special variables
*/
list_var	*init_set(void);
void		print_var(list_var *);
int		special_var(char **, list_var **);
list_var	*insert_end_var(list_var **, char *, char *);
void		spec_var(list_var *, char *);
void		reset_spec(list_var **, t_node *);
int		alphabetic_order(char *, char *);


#endif /* !SPECIAL_VAR_H_ */
