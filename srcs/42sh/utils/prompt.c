/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** prompt
*/

#include "42sh.h"

static char *get_user(t_node *env)
{
	char	*user;
	char	*save = get_env_content(env, "USER");
	int		size;

	if (!save) {
		user = strdup("\033[1;31m user");
		return (user);
	}
	size = sizeof(char) * (strlen(save) + 11);
	user = calloc(size, size);
	if (!user)
		exit(FAILURE);
	strcat(user, "\033[1;31m ");
	strcat(user, save);
	return (user);
}

char *prompt(t_node *env)
{
	char	*str = strdup("\033[1;36m ");
	char	*save = " \033[1;33m-> \033[0m";
	char	cwd[1024];
	int		slash = 0;
	char	*user = get_user(env);

	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		for (int i = 0; cwd[i]; ++i) {
			if (cwd[i] == '/')
				slash = i;
		}
		++slash;
		str = realloc(str, strlen(cwd) + strlen(save) + strlen(user) + 1);
    	strcat(str, cwd + slash);
    	strcat(str, user);
    	strcat(str, save);
	}
	return (str);
}