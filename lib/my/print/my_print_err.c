/*
** EPITECH PROJECT, 2017
** my_print_err.c
** File description:
** prints on error output
*/
#include "my.h"

void my_print_err(char *c)
{
	write (2, c, my_strlen(c));
}
