/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** my_tab_to_string
*/

#include "my.h"

static int	get_size_malloc(char **tab)
{
	int	res = 0;

	for (int i = 0; tab[i]; ++i)
		res += my_strlen(tab[i]);
	return (res);
}

char	*my_tab_to_str(char **tab)
{
	char *str = malloc((sizeof(*str) * get_size_malloc(tab)
	+ my_strarraylen(tab)) + 1);
	int	i;

	if (!str)
		return (NULL);
	for (i = 0; tab[i]; ++i) {
		my_strcat(str, tab[i]);
		my_strcat(str, " ");
	}
	str[my_strlen(str) - 1] = 0;
	return (str);
}
