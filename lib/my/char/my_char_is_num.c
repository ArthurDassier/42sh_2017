/*
** EPITECH PROJECT, 2017
** char_is_num.c
** File description:
** is char a number
*/
#include "printf.h"

int	my_char_is_num(char c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	return (0);
}