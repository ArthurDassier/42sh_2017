/*
** EPITECH PROJECT, 2017
** my_str_isalpha.c
** File description:
** checks if str is alpha
*/
#include "my.h"

int	my_str_isalpha(char const *str)
{
	if (*str == 0)
		return (1);
	while ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
		++str;
	if (*str == 0)
		return (1);
	return (0);
}