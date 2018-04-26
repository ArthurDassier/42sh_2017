/*
** EPITECH PROJECT, 2017
** my_realloc_to_str.c
** File description:
** reallocs a string
*/
#include "my.h"

char	*my_realloc_str(char *str, int size)
{
	char	*new;

	if (str == NULL)
		return (NULL);
	if (size < my_strlen(str))
		return (NULL);
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	my_strcpy(new, str);
	my_free(str);
	return (new);
}