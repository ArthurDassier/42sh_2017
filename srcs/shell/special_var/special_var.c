/*
** EPITECH PROJECT, 2018
** special_var.c
** File description:
** Arthur
*/

#include "42sh.h"
#include <string.h>
#include <stdlib.h>

void change_spec(list_var **spec, char *line_one, char *line_two)
{
	list_var *tmp = *spec;

	while (tmp != NULL) {
		if (strcmp(tmp->name, line_one) == SUCCESS) {
			spec_var(tmp, line_two);
			return;
		}
		tmp = tmp->next;
	}
	insert_end_var(spec, line_one, line_two);
}

void cut_line(list_var **spec, char *line)
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

void recup_arg_var(char **line, list_var **spec, int *i)
{
	if (line [*i + 1] != NULL && line[*i + 1][0] == '='
	&& strlen(line[*i + 1]) == 1) {
		change_spec(spec, line[*i], line[*i + 2]);
		*i += 2;
		return;
	}
	cut_line(spec, line[*i]);
}

void	change_var(char **line, list_var **spec)
{
	int	i = 1;

	while (line[i]) {
		if (my_strisalphanum(line[i]) == SUCCESS) {
			my_putstr("set: Variable name must");
			my_putstr(" contain alphanumeric characters.\n");
			return;
		}
		recup_arg_var(line, spec, &i);
		++i;
	}
}

int	special_var(char **line, list_var **spec)
{
	int	i = 0;

	while (line[i])
		++i;
	if (i == 1)
		print_var(*spec);
	else if (i > 1)
		change_var(line, spec);
	return (SUCCESS);
}
