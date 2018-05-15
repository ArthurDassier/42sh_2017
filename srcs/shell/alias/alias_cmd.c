/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** alias_cmd
*/

#include "42sh.h"

static void	create_aliase(t_aliases *alias, char **line)
{
	alias->src = malloc(sizeof(char) * (my_strlen(line[1]) + 1));
	alias->dest = malloc(sizeof(char) * (my_strlen(line[2]) + 1));
	my_strcpy(alias->src, line[1]);
	my_strcpy(alias->dest, line[2]);
}

static void	change_alias(t_aliases_list *tmp, char *line)
{
	free(tmp->alias->dest);
	tmp->alias->dest = malloc(sizeof(char) * (my_strlen(line) + 1));
	my_strcpy(tmp->alias->dest, line);
}

static void write_in_aliase_txt(t_aliases_list *list)
{
	t_aliases_list	*head = list;
	int		fd = open(".42_src/aliases.txt", O_RDWR | O_CREAT |
	O_TRUNC, S_IWUSR | S_IRUSR);

	while (head->next != NULL) {
		write(fd, "src / dest\n", 11);
		write(fd, head->alias->src, my_strlen(head->alias->src));
		write(fd, "\n", 1);
		write(fd, head->alias->dest, my_strlen(head->alias->dest));
		write(fd, "\n", 1);
		head = head->next;
	}
}

int	alias_cmd(t_aliases_list *list, char **line)
{
	int		fd = open(".42_src/aliases.txt", O_RDWR | O_APPEND);
	t_aliases_list	*head = list;

	while (head->next != NULL) {
		if (my_strcmp(head->alias->src, line[1]) == 1)
			break;
		head = head->next;
	}
	if (head->next == NULL) {
		head->alias = malloc(sizeof(t_aliases));
		create_aliase(head->alias, line);
		head->next = malloc(sizeof(t_aliases_list));
		if (head->alias == NULL || head->next == NULL)
			exit(84);
		head = head->next;
		head->next = NULL;
	} else
		change_alias(head, line[2]);
	close(fd);
	write_in_aliase_txt(list);
	return (1);
}