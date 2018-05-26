/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** quotes
*/

#ifndef QUOTES_H_
#define QUOTES_H_

#include "list.h"

typedef struct s_quotes
{
	t_node		**new_env;
	t_node		**spec_var_list;
}		t_quotes;

/*
** Quotes
*/
char	*handle_dollars(char *, t_quotes *);
char	**quotes(char **, char *, t_node **, t_node **);
char	**simple_quotes(char **, char *);
int	count_quotes(char **, char);
char	*delete_special(char *);
char	*inc_space(char *, char *, char);
char	*find_endspace(char *, char *, char);
char	**handle_line(char **, char *, t_node **, t_node **);

#endif /* !QUOTES_H_ */
