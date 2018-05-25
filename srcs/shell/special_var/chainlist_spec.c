/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** chainlist_spec
*/

#include "special_var.h"
#include "define.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

t_save *initialiser(char *name, char *content)
{
	t_save	*spec_var = malloc(sizeof(t_save));

	spec_var->name = name;
	spec_var->content = content;
	return (spec_var);
}

void print_var(t_node *list)
{
	t_node	*tmp = list;
	t_save	*tmp_save;

	do {
		tmp_save = (t_save *)tmp->data;
		printf("%s", tmp_save->name);
		if (tmp_save->content != NULL)
			printf("\t%s", tmp_save->content);
		fflush(stdout);
		putchar('\n');
		tmp = tmp->next;
	} while (tmp != list);
}
