/*
** EPITECH PROJECT, 2018
** special_var_init.c
** File description:
** Arthur
*/

#include "42sh.h"

char **init_set_tab(void)
{
	char	**tab = malloc(sizeof(char *) * 3);

	if (tab == NULL)
		return (NULL);
	tab[0] = malloc(sizeof(char) * 4);
	tab[0] = "cwd";
	tab[1] = malloc(sizeof(char) * 9);
	tab[1] = "ignoreof";
	tab[2] = NULL;
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
	return (element);
}
