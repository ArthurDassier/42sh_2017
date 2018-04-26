/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** copies n characters
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
	int	i = 0;

	if (n < 0)
		return (0);
	while ((src[i]) && (i < n) && (n > 0)) {
		dest[i] = src[i];
		i++;
	}
	while (i < n) {
		dest[i] = '\0';
		i++;
	}
	return (dest);
}