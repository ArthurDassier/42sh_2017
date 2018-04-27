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
#include <readline/readline.h>
#include <readline/history.h>
#include "list.h"
#include "my.h"
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

typedef struct	s_built {
	char	*builtin;
	char	**(*ptr)(char **, t_node **);
}		t_built;

/*
** Built-ins
*/
char	**env_built(char **, t_node **);
char	**exit_built(char **, t_node **);
int	exec_builtins(char **, t_node **);
char	**cd_built(char **, t_node **);
char	**setenv_built(char **, t_node **);
bool	check_env_name(t_node *, char *);
char	**unsetenv_built(char **, t_node **);

/*
** Initialization
*/
void	init_list(t_node **, char **);
void	init_cmd(t_node **, char *);

/*
** Utils
*/
char *prompt(t_node *);
void	delete_node(t_node **, char *);
int	cmp(void *, void *);
char	**list_to_tab(t_node *);
int	check_char(char *);
void	delete_tab(void *);
void	printing(void*);
t_tree	*s_rule(t_node **);
int	check_path(char **, char **path, t_node *);
char	*get_env_name(t_node *, char *);
void	check_perm(char **, char **, int, t_node *);
void	check_perm_cmd(char **, t_node *);
char	**get_path(t_node *);
char	*get_env_name(t_node *, char *);
char	*get_env_content(t_node *, char *);
int		delim_words(char *, char *);
bool	check_delim(char, char *);
int		is_lexem(char *);

/*
** Execution
*/
bool	exec_cmd(char **, t_node *);
bool	s_exec(t_tree *, t_node **);
bool	exp_exec(t_tree *, t_node **);
bool	pipexp_exec(t_tree *, t_node **);
bool	rexp_exec(t_tree *, t_node **);
bool	cmd_exec(t_tree *, t_node **);
void	exec_com(char **, char **, t_node *);
void	add_com(char **, char **);
void	exec_line(t_node *, char **);
bool	r_redirection(t_tree *, t_node **);
bool	dr_redirection(t_tree *, t_node **);
bool	l_redirection(t_tree *, t_node **);
bool	pipe_exec(t_tree *, t_node **);
bool	dl_redirection(t_tree *, t_node **);

/*
** Aliases
*/

int	aliases(t_aliases_list *, char **);
int	alias_cmd(t_aliases_list *, char **);
t_aliases_list	*recup_aliases_list(void);

/*
** History
*/

void	write_in_history(char *, int);

/*
** Display
*/

void	print_list(void *);
void	display(void *);

/*
** Free
*/
void	free_lexer(void *);
void	free_tree(t_tree *);

#endif /* !42SH_H_ */
