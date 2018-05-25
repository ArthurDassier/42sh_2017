/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** special_var_init
*/

#include "special_var.h"
#include <unistd.h>

// Loop
char **init_set_tab(void)
{
	char	**tab = malloc(sizeof(char *) * 6);

	if (tab == NULL)
		return (NULL);
	tab[0] = malloc(sizeof(char) * 4);
	tab[0] = "cwd";
	tab[1] = malloc(sizeof(char) * 9);
	tab[1] = "ignoreof";
	tab[2] = malloc(sizeof(char) * 5);
	tab[2] = "path";
	tab[3] = malloc(sizeof(char) * 5);
	tab[3] = "user";
	tab[4] = malloc(sizeof(char) * 5);
	tab[4] = "term";
	tab[5] = NULL;
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
	return (element);
}
