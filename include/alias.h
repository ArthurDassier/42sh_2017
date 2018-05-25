/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** alias
*/

#ifndef ALIAS_H_
#define ALIAS_H_

typedef struct	s_aliases
{
	char	*src;
	char	*dest;
}		t_aliases;

typedef struct	s_aliases_list
{
	t_aliases		*alias;
	struct	s_aliases_list	*next;
}				t_aliases_list;

/*
** Aliases
*/
void	change_for_alias(t_aliases_list *, char **);
int	alias_cmd(t_aliases_list *, char **);
t_aliases_list	*recup_aliases(void);

#endif /* !ALIAS_H_ */
