/*
** EPITECH PROJECT, 2017
** my_strstr.c
** File description:
** strstr function
*/
#include "my.h"

char	*my_strstr(char *str, char const *to_find)
{
	int i = 0;
	int j;

	while (str[i]) {
		j = 0;
		while (to_find[j] == str[i + j] && to_find[j])
			++j;
		if (!to_find[j])
			return (char*)&str[i];
		i++;
	}
	return (0);
}