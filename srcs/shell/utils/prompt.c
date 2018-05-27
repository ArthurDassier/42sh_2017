/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** prompt
*/

#include "shell.h"
#include "const_values.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static char *get_branch(void)
{
	int 	fd = open(".git/HEAD", O_RDWR);
	char	*branch;
	int		save;
	char	*curr = strdup(" \033[1;35mgit:(");

	if (fd == ERROR) {
		free(curr);
		return (NULL);
	}
	branch = get_next_line(fd);
	for (int i = 0; branch[i]; ++i) {
		if (branch[i] == '/')
			save = i;
	}
	curr = realloc(curr, sizeof(*curr) * strlen(branch + save + 1) + 15);
	strcat(curr, branch + save + 1);
	strcat(curr, ")");
	return (curr);
}

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
	char	*branch = get_branch();

	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		for (int i = 0; cwd[i]; ++i)
			if (cwd[i] == '/')
				slash = i;
		str = realloc(str, strlen(cwd) + strlen(save) +
		strlen(user) + 99);
		strcat(str, cwd + slash + 1);
		strcat(str, user);
		if (branch != NULL)
			strcat(str, branch);
		strcat(str, save);
	}
	return (str);
}