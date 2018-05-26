/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** alias
*/

#ifndef ALIAS_H_
#define ALIAS_H_

#include "list.h"

typedef struct	s_aliases
{
	char	*src;
	char	*dest;
}		t_aliases;

/*
** Aliases
*/
void	change_for_alias(t_node *, char **);
int	alias_cmd(t_node *, char **);
t_node	*recup_aliases(void);

#endif /* !ALIAS_H_ */
