/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** alias_cmd
*/

#include "alias.h"
#include "define.h"
#include "list.h"
#include "my.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	create_aliase(t_node **head, char **line)
{
	t_aliases	*alias_data = (t_aliases *)(*head)->data;

	alias_data->src = malloc(sizeof(char) * (strlen(line[1]) + 1));
	alias_data->dest = malloc(sizeof(char) * (strlen(line[2]) + 1));
	strcpy(alias_data->src, line[1]);
	strcpy(alias_data->dest, line[2]);
	*head = (*head)->next;
	(*head)->next = NULL;
}

static void	change_alias(t_node *tmp, char *line)
{
	t_aliases	*alias_data = (t_aliases *)tmp->data;

	free(alias_data->dest);
	alias_data->dest = strdup(line);
}

static void write_in_aliase_txt(t_node *list)
{
	t_node		*head = list;
	int		fd = open(".42_src/aliases.txt", O_RDWR | O_CREAT |
	O_TRUNC, S_IWUSR | S_IRUSR);
	t_aliases	*alias_data = NULL;

	while (head->next != NULL) {
		alias_data = (t_aliases *)head->data;
		write(fd, "src / dest\n", 11);
		write(fd, alias_data->src, strlen(alias_data->src));
		write(fd, "\n", 1);
		write(fd, alias_data->dest, strlen(alias_data->dest));
		write(fd, "\n", 1);
		head = head->next;
	}
}

static void	new_alias(t_node **head)
{
	(*head)->data = malloc(sizeof(t_aliases));
	(*head)->next = malloc(sizeof(t_node));
	if ((*head)->data == NULL || (*head)->next == NULL)
		exit(FAILURE);
}

int	alias_cmd(t_node *list, char **line)
{
	int		fd = open(".42_src/aliases.txt", O_RDWR | O_APPEND);
	t_node		*head = list;
	t_aliases	*alias_data = NULL;

	if (my_strarraylen(line) != 3)
		return (VALID);
	while (head->next != NULL) {
		alias_data = (t_aliases *)head->data;
		if (strcmp(alias_data->src, line[1]) == SUCCESS)
			break;
		head = head->next;
	}
	if (head->next == NULL) {
		new_alias(&head);
		create_aliase(&head, line);
	} else
		change_alias(head, line[2]);
	close(fd);
	write_in_aliase_txt(list);
	return (SUCCESS);
}