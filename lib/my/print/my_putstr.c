/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** print a string
*/
#include "my.h"

void my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
}