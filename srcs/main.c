/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** main
*/

#include "42sh.h"
#include "history.h"
#include "line.h"

const char *prompt_line = NULL;

static int	ignore_eof(list_var *spec)
{
	list_var *tmp = spec;

	while (tmp != NULL) {
		if (strcmp(tmp->name, "ignoreof") == SUCCESS
		&& tmp->content != NULL)
			return (atoi(tmp->content));
		tmp = tmp->next;
	}
	return (0);
}

static void	ctrl_c(int sig)
{
	(void)sig;
	my_putstr("\n");
	my_putstr(prompt_line);
}

static void	ctrl_d(char *s, list_var *spec)
{
	if (s == NULL) {
		if (ignore_eof(spec) != 0) {
			my_putstr("exit\n");
			exit(SUCCESS);
		}
		my_putstr("Use \"exit\" to leave 42sh.\n");
	}
}

static int	init_exec(char *s, t_node **cmd_list, t_node **env_list,
t_files_info *info)
{
	char	**line = NULL;
	t_tree	*tree;

	line = delim_lexem(s, " \t\r");
	line = handle_line(line, s, env_list, info->spec_var_list);
	if (line == NULL) {
		free(s);
		return (FAILURE);
	}
	change_for_alias(info->alias_list, line);
	lexer(cmd_list, line, *env_list);
	tree = s_rule(cmd_list);
	if (!tree) {
		my_putstr("Error\n");
		return (FAILURE);
	}
	s_exec(tree, env_list, info);
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
	t_files_info	*info = malloc(sizeof(t_files_info));

	info->hist_list = NULL;
	info->alias_list = recup_aliases();
	info->spec_var_list = init_set();
	open(".42_src/history.txt", O_RDWR | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR);
	signal(SIGINT, ctrl_c);
	init_list(&env_list, env);
	while (VALID) {
		prompt_line = prompt(env_list);
		free_list(cmd_list, &free_lexer);
		cmd_list = NULL;
		my_putstr(prompt_line);
		s = get_next_line(0);
		s = inib(s);
		ctrl_d(s, info->spec_var_list);
		if (s != NULL && check_char(s) == SUCCESS
		&& init_exec(s, &cmd_list, &env_list, info) == FAILURE)
				continue;
	}
	return (SUCCESS);
}
