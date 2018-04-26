/*
** EPITECH PROJECT, 2017
** my_strndup.c
** File description:
** srtndup function
*/
#include "my.h"

char	*my_strndup(char const *src, int n)
{
	char	*dest = malloc(sizeof(char*) * n + 1);
	int	i = 0;

	if (dest == NULL)
		return (NULL);
	while (i < n && src[i] != '\0') {
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}