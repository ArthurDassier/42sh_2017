/*
** EPITECH PROJECT, 2017
** my_str_to_wordarray_delim.c
** File description:
** str_to_wordarray with a delim as argument
*/
#include "42sh.h"

static const char	*lexem_list[10] = {
	"&&", "|", "||", ";", ">", "<", ">>", "<<", "(", ")"
};

int	is_lexem(char *str)
{
	int	i;
	int	save = ERROR;

	for (i = 0; i < 10; ++i) {
		if (strncmp(str, lexem_list[i],
		strlen(lexem_list[i])) == SUCCESS) {
			save = i;
		}
	}
	return (save);

}

static int	l_words(char *str, char *delim)
{
	int	count = 0;

	for (int i = 0; check_delim(str[i], delim) == false && str[i]; ++i)
		count++;
	return (count);
}

static int	add_lexem(char *str, char **tab, int *j, int count)
{
	if (is_lexem(str) != -1) {
		if (count > 0) {
			tab[*j][count] = '\0';
			*j += 1;
		}
		tab[*j] = strdup(lexem_list[is_lexem(str)]);
		*j += 1;
		return (strlen(lexem_list[is_lexem(str)]));
	} else {
		tab[*j][count] = '\0';
		*j += 1;
	}
	return (0);

}

char	**my_str_to_wordtab_delim(char *str, char *delim)
{
	char			**tab;
	int				nb = delim_words(str, delim);
	unsigned int	i = 0;
	int				j = 0;
	int				count = 0;

	tab = malloc(sizeof(char *) * (nb + 1));
	while (j < nb && i < strlen(str)) {
		while (check_delim(str[i], delim) == true)
			++i;
		count = 0;
		tab[j] = malloc(sizeof(char) * (l_words(str + i, delim) + 1));
		while (check_delim(str[i], delim) == false
		&& is_lexem(str + i) == -1 && str[i])
			tab[j][count++] = str[i++];
		i += add_lexem(str + i, tab, &j, count);
	}
	tab[j] = NULL;
	return (tab);
}