/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** strdup function
*/
#include "my.h"

char *my_strdup(char const *src)
{
	char	*dest = malloc(sizeof(char*) * (my_strlen(src) + 1));
	int	i = 0;

	if (dest == NULL)
		return (NULL);
	while (i <= my_strlen(src)) {
		dest[i] = src[i];
		++i;
	}
	return (dest);
}