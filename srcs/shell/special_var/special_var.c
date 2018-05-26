/*
** EPITECH PROJECT, 2018
** special_var.c
** File description:
** Arthur
*/

#include "special_var.h"
#include "const_values.h"
#include <string.h>
#include <stdlib.h>

void change_spec(t_node **spec, char *line_one, char *line_two)
{
	t_node	*tmp = *(spec);
	t_save	*tmp_save;

	do {
		tmp_save = (t_save *)tmp->data;
		if (strcmp(tmp_save->name, line_one) == SUCCESS) {
			spec_var(tmp_save, line_two);
			return;
		}
		tmp = tmp->next;
	} while (tmp != *(spec));
	if (line_two != NULL)
		insert_end(spec, initialiser(strdup(line_one),
							strdup(line_two)));
	else
		insert_end(spec, initialiser(strdup(line_one), NULL));
	my_sort_list(*spec, &alphabetic_order);
}

void cut_line(t_node **spec, char *line)
{
	int	i = 0;
	int	j = 0;
	char	*line_one = malloc(sizeof(char) * (strlen(line) + 1));
	char	*line_two = malloc(sizeof(char) * (strlen(line) + 1));

	for (; line[i] != '\0'; ++i) {
		if (line[i] == '=')
			break;
		line_one[i] = line[i];
	}
	line_one[i] = '\0';
	if (line[i++] == '\0') {
		change_spec(spec, line_one, NULL);
	} else {
		for (; line[i] != '\0'; ++i)
			line_two[j++] = line[i];
		line_two[j] = '\0';
		change_spec(spec, line_one, line_two);
	}
}

void recup_arg_var(char **line, t_node **spec, int *i)
{
	if (line [*i + 1] != NULL && line[*i + 1][0] == '='
	&& strlen(line[*i + 1]) == 1) {
		change_spec(spec, line[*i], line[*i + 2]);
		*i += 2;
		return;
	}
	cut_line(spec, line[*i]);
}

int	change_var(char **line, t_node **spec)
{
	int	i = 1;

	while (line[i]) {
		if (my_strisalphanum(line[i]) == SUCCESS
		&& check_equal(line[i]) == SUCCESS) {
			my_putstr("set: Variable name must");
			my_putstr(" contain alphanumeric characters.\n");
			return (VALID);
		}
		if (line[i][0] >= '0' && line[i][0] <= '9') {
			my_putstr("set: Variable name must");
			my_putstr(" begin with a letter.\n");
			return (VALID);
		}
		recup_arg_var(line, spec, &i);
		++i;
	}
	return (SUCCESS);
}

int	special_var(char **line, t_node **spec)
{
	int	i = 0;

	while (line[i])
		++i;
	if (i == 1)
		print_var(*spec);
	else if (i > 1)
		if (change_var(line, spec) == VALID)
			return (VALID);
	return (SUCCESS);
}
