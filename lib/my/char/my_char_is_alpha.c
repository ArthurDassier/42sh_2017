/*
** EPITECH PROJECT, 2017
** my_char_is_alpha.c
** File description:
** check if char is alpha
*/
#include "printf.h"

int my_char_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}