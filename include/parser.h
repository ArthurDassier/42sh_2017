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
	L_PARENTHESE,
	R_PARENTHESE,
	OR,
	S_COLON,
	R_REDIRECT,
	L_REDIRECT,
	DR_REDIRECT,
	DL_REDIRECT,
	WORD,
	BUILTIN,
	CMD
}		t_token;

typedef struct s_cmd {
	char	**name;
	t_token	token;
}		t_cmd;

typedef	struct	s_tree {
	t_cmd		cmd;
	struct s_tree	*right;
	struct s_tree	*left;

}		t_tree;

typedef struct	s_parser {
	char	*name;
	t_token	token;
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
void	add_node(t_node **, t_token, char *);
int		get_builtins(t_node **, char *);
int		get_lexem(t_node **, char *);
void	lexer(t_node **, char **, t_node *);
char	**my_str_to_wordtab_delim(char *, char *);

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
bool	check_token(t_node **, t_token, t_tree *);
t_tree	*ret_node(t_tree *, t_tree *);
t_tree	*semiexp_rule(t_node **cmd_list);

#endif /* !PARSER_H_ */