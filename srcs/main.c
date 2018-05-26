/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** main
*/

#include "42sh.h"
#include "history.h"
#include "define.h"
#include "alias.h"
#include "line.h"
#include "inhibitors.h"
#include "special_var.h"
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

const char *prompt_line = NULL;

static int	ignore_eof(t_node **spec)
{
	t_node	*tmp = *(spec);
	t_save	*tmp_save;

	do {
		tmp_save = (t_save *)tmp->data;
		if (strcmp(tmp_save->name, "ignoreof") == SUCCESS
		&& tmp_save->content != NULL)
			return (atoi(tmp_save->content));
		tmp = tmp->next;
	} while (tmp != *(spec));
	return (SUCCESS);
}

static t_files_info	*init_files_info(void)
{
	t_files_info	*info = malloc(sizeof(t_files_info));

	info->dwait_pipe = false;
	info->hist_list = NULL;
	info->alias_list = recup_aliases();
	info->spec_var_list = init_set();
	info->ret = 0;
	creat(".42_src/history.txt", O_RDWR);
	return (info);
}

static void	reset_var_ctrl_d(char *s, t_node *env_list,
t_node **spec, int ret)
{
	int	ignoreof = ignore_eof(spec);

	reset_spec(spec, env_list, s, ret);
	if (!s) {
		if (ignoreof != 0) {
			my_putstr("exit\n");
			exit(ret);
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
	line = handle_line(line, s, env_list, &info->spec_var_list);
	if (!line) {
		free(s);
		return (FAILURE);
	}
	if (change_line(line, info) == FAILURE)
		return (FAILURE);
	lexer(cmd_list, line, *env_list);
	tree = s_rule(cmd_list);
	if (!tree)
		return (FAILURE);
	info->ret = s_exec(tree, env_list, info);
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
	t_files_info	*info = init_files_info();

	init_list(&env_list, env);
	while (VALID) {
		prompt_line = prompt(env_list);
		free_list(cmd_list, &free_lexer);
		cmd_list = NULL;
		s = recup_line(prompt_line, &info->hist_list);
		s = inib(s);
		reset_var_ctrl_d(s, env_list, &info->spec_var_list, info->ret);
		if (s != NULL && check_char(s) == SUCCESS
		&& init_exec(s, &cmd_list, &env_list, info) == FAILURE)
				continue;
	}
	return (SUCCESS);
}