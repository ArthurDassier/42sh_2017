/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** 42sh
*/

#ifndef SH_H_
#define SH_H_
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <wait.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "my.h"
#include "history.h"
#include "parser.h"
#include "define.h"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

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

typedef struct	s_save {
	char	*name;
	char	*content;
}		t_save;

typedef struct s_list_var
{
	char			*name;
	char			*content;
	struct s_list_var	*next;
}		list_var;

typedef struct s_files_info
{
	t_aliases_list	*alias_list;
	t_history	*hist_list;
	list_var	*spec_var_list;
	bool		background;
	int		ret;
}			t_files_info;

typedef struct s_quotes
{
	t_node		**new_env;
	list_var	*spec_var_list;
}		t_quotes;

typedef struct	s_built {
	char	*builtin;
	int		(*ptr)(char **, t_node **);
}				t_built;

/*
** Change_the_line_from_info
*/
int	change_line(char **, t_files_info *);

/*
** Built-ins
*/
int		env_built(char **, t_node **);
int		exit_built(char **, t_node **);
int		cd_built(char **, t_node **);
int		setenv_built(char **, t_node **);
bool		check_env_name(t_node *, char *);
int		unsetenv_built(char **, t_node **);
void		change_pwd(t_node **, char *);
int		cd_special_cases(char **, t_node **, char *);
int		display_help(__attribute((unused)) char **, t_node **);
int		normal_cd(t_node **, char **);
int		unset_name(char **, t_node **);
int		get_cd(char *, t_node **);
int		display_version(char **line, t_node **);
int		rm_var(char **, t_node **);
int		ignore_env(char **, t_node **);
int		end_with_null(__attribute((unused)) char **, t_node **);
int		env_chdir(char **, t_node **, bool);

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
char	**handle_line(char **, char *, t_node **, list_var *);

/*
** Execution
*/
bool	exec_cmd(char **, t_node *, bool);
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
** Aliases
*/
void	change_for_alias(t_aliases_list *, char **);
int	alias_cmd(t_aliases_list *, char **);
t_aliases_list	*recup_aliases(void);

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
** Globbings
*/
char	**globbings(char **);
void	release_tmp(char **);
char	**copy_line(char **);
int	alloc_tab(char **, char **);
int	back_slash(int, char *);
int	count_glob(char **);

/*
** Inihibitors
*/

char	*inib(char *);
char	**handle_backslash(char **);
char	*delete_backslash(char *);
char	*decal_line(char *, int);

/*
** Quotes
*/

char	*handle_dollars(char *, t_quotes *);
char	**quotes(char **, char *, t_node **, list_var *);
char	**simple_quotes(char **, char *);
int	count_quotes(char **, char);
char	*delete_special(char *);
char	*inc_space(char *, char *, char);
char	*find_endspace(char *, char *, char);

/*
** Special variables
*/

list_var	*init_set(void);
void		print_var(list_var *);
int		special_var(char **, list_var **);
list_var	*insert_end_var(list_var **, char *, char *);
void		spec_var(list_var *, char *);
void		reset_spec(list_var **, t_node *, char *, int);
int		alphabetic_order(char *, char *);

/*
** Free
*/
void	free_lexer(void *);
void	free_tree(t_tree *);

#endif /* !42SH_H_ */
