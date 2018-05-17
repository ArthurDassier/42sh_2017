/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** main
*/

#include "42sh.h"

const char *prompt_line = NULL;

static void	ctrl_c(int sig)
{
	(void)sig;
	my_putstr("\n");
	my_putstr(prompt_line);
}

static void	ctrl_d(char *s)
{
	if (s == NULL) {
		my_putstr("exit\n");
		exit(SUCCESS);
	}
}

static int	init_exec(char *s, t_node **cmd_list, t_node **env_list,
t_aliases_list *alias_list)
{
	char	**line = NULL;
	t_tree	*tree;

	line = my_str_to_wordtab_delim(s, " \t\r");
	line = handle_backslash(line, s);
	line = globbings(line);
	if (line == NULL)
		return (FAILURE);
	change_for_alias(alias_list, line);
	lexer(cmd_list, line, *env_list);
	tree = s_rule(cmd_list);
	if (!tree) {
		my_putstr("Error\n");
		return (FAILURE);
	}
	//display_tree(tree);
	s_exec(tree, env_list);
	free(s);
	free_tree(tree);
	return (SUCCESS);
}

int	main(__attribute((unused)) int ac, __attribute((unused)) char **av, char
**env)
{
	char		*s;
	t_node		*env_list = NULL;
	t_node		*cmd_list = NULL;
	t_aliases_list	*alias_list = recup_aliases();

	open(".42_src/history.txt", O_RDWR | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
	signal(SIGINT, ctrl_c);
	init_list(&env_list, env);
	while (VALID) {
		prompt_line = prompt(env_list);
		free_list(cmd_list, &free_lexer);
		cmd_list = NULL;
		printf(CYAN);
		my_putstr(prompt_line);
		s = get_next_line(0);
		s = inib(s);
		ctrl_d(s);
		if (check_char(s) == SUCCESS
		&& init_exec(s, &cmd_list, &env_list, alias_list) == FAILURE)
				continue;
	}
	return (SUCCESS);
}
