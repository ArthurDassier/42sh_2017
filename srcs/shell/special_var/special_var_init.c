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

char **init_set_tab(void)
{
	char	**tab = malloc(sizeof(char *) * 12);

	if (tab == NULL)
		return (NULL);
	tab[0] = "cwd";
	tab[1] = "ignoreof";
	tab[2] = "path";
	tab[3] = "user";
	tab[4] = "term";
	tab[5] = "shell";
	tab[6] = "tty";
	tab[7] = "uid";
	tab[8] = "gid";
	tab[9] = "euid";
	tab[10] = "echo";
	tab[11] = NULL;
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
	return (element);
}
