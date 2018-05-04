/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** recup_aliases
*/

#include "42sh.h"

static int	check_malloc_fd(t_aliases_list *list, int fd)
{
	if (list == NULL)
		exit(84);
	if (fd == -1) {
		my_putstr("open failed\n");
		return (-1);
	}
	return (0);
}

t_aliases_list	*recup_aliases(void)
{
	int		fd = open(".42_src/aliases.txt", O_RDONLY | O_TRUNC);
	t_aliases_list	*list = malloc(sizeof(t_aliases_list));
	t_aliases_list	*tmp = list;
	char		*buf = NULL;

	if (check_malloc_fd(list, fd) != 0)
		return (NULL);
	while ((buf = get_next_line(fd)) != NULL) {
		if ((tmp->alias = malloc(sizeof(t_aliases))) == NULL)
			exit(84);
		tmp->alias->src = get_next_line(fd);
		tmp->alias->dest = get_next_line(fd);
		if ((tmp->next = malloc(sizeof(t_aliases_list))) == NULL)
			exit(84);
		tmp = tmp->next;
	}
	free(tmp);
	tmp = NULL;
	free(buf);
	return (list);
}