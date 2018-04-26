/*
** EPITECH PROJECT, 2017
** my_char_isalphanum.c
** File description:
** char is alphanum
*/
#include "my.h"

int	my_char_is_alphanum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
	(c >= '0' && c <= '9'))
		return (1);
	return (0);
}