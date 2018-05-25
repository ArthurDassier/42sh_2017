/*
** EPITECH PROJECT, 2018
** special_var_init.c
** File description:
** Arthur
*/

#include "42sh.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static const char	*special[13] = {
	"cwd", "ignoreof", "path", "user", "term", "shell",
	"tty", "uid", "gid", "euid", "echo", "status"
};

char **init_set_tab(void)
{
	int		i = 0;
	unsigned int	j = 0;
	char	**tab = malloc(sizeof(char *) * 13);

	if (tab == NULL)
		return (NULL);
	while (i != 12) {
		tab[i] = malloc(sizeof(char) * strlen(special[i]));
		for (j = 0; j != strlen(special[i]); ++j)
			tab[i][j] = special[i][j];
		tab[i][j] = '\0';
		++i;
	}
	tab[12] = NULL;
	return (tab);
}

list_var *init_set(void)
{
	list_var	*element = malloc(sizeof(list_var));
	char		**tab = init_set_tab();

	if (element == NULL || tab == NULL)
		return (NULL);
	element->name = tab[0];
	element->content = NULL;
	element->content = getcwd(element->content, 0);
	element->next = NULL;
	insert_end_var(&element, tab[1], "1");
	insert_end_var(&element, tab[2], "(");
	insert_end_var(&element, tab[3], "init");
	insert_end_var(&element, tab[4], "init");
	insert_end_var(&element, tab[5], "42sh");
	insert_end_var(&element, tab[6], NULL);
	insert_end_var(&element, tab[7], my_itoa(getuid()));
	insert_end_var(&element, tab[8], my_itoa(getgid()));
	insert_end_var(&element, tab[9], my_itoa(geteuid()));
	insert_end_var(&element, tab[10], NULL);
	insert_end_var(&element, tab[11], NULL);
	return (element);
}
