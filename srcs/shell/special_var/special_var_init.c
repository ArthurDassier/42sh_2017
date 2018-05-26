/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** special_var_init
*/

#include "special_var.h"
#include "list.h"
#include <unistd.h>
#include <string.h>

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
		tab[i] = malloc(sizeof(char) * (strlen(special[i]) + 1));
		for (j = 0; j != strlen(special[i]); ++j)
			tab[i][j] = special[i][j];
		tab[i][j] = '\0';
		++i;
	}
	tab[12] = NULL;
	return (tab);
}

t_node *init_set(void)
{
	t_node	*element = NULL;
	char	**tab = init_set_tab();

	if (tab == NULL)
		return (NULL);
	insert_end(&element, initialiser(tab[0], getcwd(NULL, 0)));
	insert_end(&element, initialiser(tab[1], "1"));
	insert_end(&element, initialiser(tab[2], "init"));
	insert_end(&element, initialiser(tab[3], "init"));
	insert_end(&element, initialiser(tab[4], "init"));
	insert_end(&element, initialiser(tab[5], "42sh"));
	insert_end(&element, initialiser(tab[6], NULL));
	insert_end(&element, initialiser(tab[7], my_itoa(getuid())));
	insert_end(&element, initialiser(tab[8], my_itoa(getgid())));
	insert_end(&element, initialiser(tab[9], my_itoa(geteuid())));
	insert_end(&element, initialiser(tab[10], NULL));
	insert_end(&element, initialiser(tab[11], NULL));
	my_sort_list(element, &alphabetic_order);
	return (element);
}
