/*
** EPITECH PROJECT, 2018
** Epitech First Year
** File description:
** main.c
*/

#include "42sh.h"

static void	ctrl_c(int sig)
{
	(void)sig;
	my_putstr("\n");
	my_putstr("$> ");
}

static void	ctrl_d(char *s)
{
	if (s == NULL) {
		my_putstr("exit\n");
		exit(0);
	}
}

static int	init_exec(char *s, t_node **cmd_list, t_node **env_list)
{
	char	**line = NULL;
	t_tree	*tree;

	line = my_str_to_wordtab_delim(s, " \t\r");
	line = globbings(line);
	lexer(cmd_list, line, *env_list);
	tree = s_rule(cmd_list);
	if (!tree) {
		my_putstr("ERROR\n");
		return (FAILURE);
	}
	s_exec(tree, env_list);
	free(s);
	free_tree(tree);
	return (SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	char		*s;
	t_node		*env_list = NULL;
	t_node		*cmd_list = NULL;

	(void)ac;
	(void)av;
	signal(SIGINT, ctrl_c);
	init_list(&env_list, env);
	while (1) {
		free_list(cmd_list, &free_lexer);
		cmd_list = NULL;
		printf(CYAN);
		s = readline(prompt(env_list));
		ctrl_d(s);
		if (check_char(s) == SUCCESS)
			if (init_exec(s, &cmd_list, &env_list) == FAILURE)
				continue;
	}
	return (SUCCESS);
}