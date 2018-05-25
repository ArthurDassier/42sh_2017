/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

typedef enum	s_token {
	AND,
	PIPE,
	OR,
	S_COLON,
	R_REDIRECT,
	L_REDIRECT,
	DR_REDIRECT,
	DL_REDIRECT,
	L_PAR,
	R_PAR,
	WORD,
	BUILTIN,
	CMD
}				e_token;

typedef struct s_cmd {
	char	**name;
	e_token	token;
}		t_cmd;

typedef	struct	s_tree {
	t_cmd		cmd;
	struct s_tree	*right;
	struct s_tree	*left;

}		t_tree;

typedef struct	s_parser {
	char	*name;
	e_token	token;
	bool	visited;
}		t_parser;

typedef struct	s_count {
	int	i;
	int	j;
}		t_count;

/*
** Lexer
*/
int		get_redirect_double(t_node **, char *);
int		get_redirect(t_node **, char *);
int		get_options(t_node **, char *);
void	get_cmd(t_node **, char *, char **);
void	add_node(t_node **, e_token, char *);
int		get_builtins(t_node **, char *);
void	lexer(t_node **, char **, t_node *);
char	**delim_lexem(char *, char *);
int	get_lexem(t_node **, char **, int);

/*
** Parser
*/
char	**get_name_cmd(t_node **);
void	display_tree(t_tree *);
t_tree	*cmd_rule(t_node **);
t_tree	*exp_rule(t_node **);
t_tree	*pipexp_rule(t_node **);
t_tree	*rexp_rule(t_node **);
t_tree	*s_rule(t_node **);
t_tree	*create_node(void);
bool	check_token(t_node **, e_token, t_tree *);
t_tree	*ret_node(t_tree *, t_tree *);
t_tree	*semiexp_rule(t_node **);
int		handle_parentheses(t_node **, t_tree *);

#endif /* !PARSER_H_ */