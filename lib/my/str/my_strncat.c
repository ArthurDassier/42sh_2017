/*
** EPITECH PROJECT, 2017
** my_strncat.c
** File description:
** concat n characters
*/
#include "my.h"

char	*my_strncat(char *dest, char const *src, int nb)
{
	int	i = 0;
	int	dest_size = 0;

	while (dest[dest_size])
		dest_size++;
	while (i < nb && src[i]) {
		dest[dest_size] = src[i];
		dest_size++;
		i++;
	}
	dest[dest_size] = '\0';
	return (dest);
}