/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** 42sh
*/

#ifndef SH_H_
#define SH_H_
#include "list.h"
#include "my.h"
#include "history.h"
#include "alias.h"
#include "parser.h"
#include "define.h"
#include "quotes.h"

typedef struct	s_save {
	char	*name;
	char	*content;
}		t_save;

typedef struct s_files_info
{
	t_aliases_list	*alias_list;
	t_node		*hist_list;
	list_var	*spec_var_list;
	bool		background;
	bool		dwait_pipe;
}			t_files_info;

typedef struct	s_built {
	char	*builtin;
	int		(*ptr)(char **, t_node **);
}				t_built;


/*
** Change_the_line_from_info
*/
int	change_line(char **, t_files_info *);

/*
** Initialization
*/
void	init_list(t_node **, char **);
void	init_cmd(t_node **, char *);

/*
** Utils
*/
char 	*prompt(t_node *);
void	delete_node(t_node **, char *);
int	cmp(void *, void *);
char	**list_to_tab(t_node *);
int	check_char(char *);
void	delete_tab(void *);
void	printing(void*);
t_tree	*s_rule(t_node **);
int	check_path(char **, char **, t_node *);
char	*get_env_name(t_node *, char *);
void	check_perm(char **, char **, int, t_node *);
void	check_perm_cmd(char **, t_node *);
char	**get_path(t_node *);
char	*get_env_content(t_node *, char *);
int	delim_words(char *, char *);
bool	check_delim(char, char *);
int	is_lexem(char *);
void	handling_sig(int);

/*
** Execution
*/
bool	exec_cmd(char **, t_node *, t_files_info *);
bool	s_exec(t_tree *, t_node **, t_files_info *);
bool	exp_exec(t_tree *, t_node **, t_files_info *);
bool	pipexp_exec(t_tree *, t_node **, t_files_info *);
bool	rexp_exec(t_tree *, t_node **, t_files_info *);
bool	cmd_exec(t_tree *, t_node **, t_files_info *);
void	exec_com(char **, char **, t_node *);
void	add_com(char **, char **);
void	exec_line(t_node *, char **);
bool	r_redirection(t_tree *, t_node **, t_files_info *);
bool	dr_redirection(t_tree *, t_node **, t_files_info *);
bool	l_redirection(t_tree *, t_node **, t_files_info *);
bool	pipe_exec(t_tree *, t_node **, t_files_info *);
bool	dl_redirection(t_tree *, t_node **, t_files_info *);
bool	separators_exec(t_tree *, t_node **, t_files_info *);
int	exec_builtins(char **, t_node **, t_files_info *);
bool	semiexp_exec(t_tree *, t_node **);
bool	parentheses(t_tree *, t_node **);

/*
** Scripting
*/
bool	check_script(char **);

/*
** Display
*/
void	print_list(void *);
void	display(void *);
void	print_list_with_null(void *);


/*
** Free
*/
void	free_lexer(void *);
void	free_tree(t_tree *);

#endif /* !42SH_H_ */