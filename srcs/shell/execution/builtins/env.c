/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** env
*/

#include "42sh.h"
#include <stdio.h>
#include <string.h>

static t_built	env_tab[NB_FLAGS] = {
	{"-i", &ignore_env},
	{"--ignore-environment", &ignore_env},
	{"-0", &end_with_null},
	{"--null", &end_with_null},
	{"-u", &rm_var},
	{"--help", &display_help},
	{"-C", &env_chdir},
	{"--version", &display_version},
	{"-", &ignore_env},
};

int	display_help(__attribute((unused)) char **line, __attribute((unused))
t_node **env_list)
{
	printf("%s%s%s%s", HELP_MSG1, HELP_MSG2, HELP_MSG3, HELP_MSG4);
	printf("%s%s%s%s", HELP_MSG5, HELP_MSG6, HELP_MSG7, HELP_MSG8);
	printf("%s%s%s%s\n", HELP_MSG9, HELP_MSG10, HELP_MSG11, HELP_MSG12);
	return (SUCCESS);
}

int display_version(__attribute((unused)) char **line, __attribute((unused))
t_node **env_list)
{
	printf("%s%s%s", VERSION_MSG1, VERSION_MSG2, VERSION_MSG3);
	printf("%s%s\n", VERSION_MSG4, VERSION_MSG5);
	return (SUCCESS);
}

int	rm_var(char **line, t_node **env_list)
{
	char *str = get_env_name(*env_list, line[2]);

	if (!str)
		return (FAILURE);
	delete_node(env_list, str);
	display_list(*env_list, &print_list);
	return (SUCCESS);
}

int end_with_null(__attribute((unused)) char **line, t_node **env_list)
{
	if (my_strarraylen(line) > 2) {
		printf("%s%s\n", ERR_MSG1, ERR_MSG2);
		return (SUCCESS);
	}
	display_list(*env_list, &print_list_with_null);
	return (SUCCESS);
}

int	env_built( __attribute((unused)) char **line, t_node **env_list)
{
	if (my_strarraylen(line) == VALID) {
		display_list(*env_list, &print_list);
		return (SUCCESS);
	}
	if (strncmp(line[1], "--unset=", 8) == SUCCESS) {
		if (unset_name(line, env_list) == FAILURE)
			return (FAILURE);
		return (SUCCESS);
	}
	for (int i = 0; i < NB_FLAGS; ++i) {
		if (strcmp(env_tab[i].builtin, line[1]) == SUCCESS) {
			if ((env_tab[i].ptr)(line, env_list) == FAILURE)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}