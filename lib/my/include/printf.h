/*
** EPITECH PROJECT, 2017
** printf.h
** File description:
** printf header
*/
#ifndef PRINTF_H
#define PRINTF_H

#include "my.h"
#include <stdarg.h>

#define NB_FLAGS 15

struct s_flag {
	char	*flag;
	int	(*ptr)(va_list ap, char const *str);
};

//int my_printf(const char *str, ...);
int counting(int nb);
int flag_s(va_list ap, char const *str);
int flag_d(va_list ap, char const *str);
int flag_c(va_list ap, char const *str);
int flag_i(va_list ap, char const *str);
int flag_b(va_list ap, char const *str);
int flag_s_capitalize(va_list ap, char const *str);
int flag_hexa(va_list ap, char const *str);
int flag_hexa_capitalize(va_list ap, char const *str);
int flag_o(va_list ap, char const *str);
int flag_u(va_list ap, char const *str);
int flag_p(va_list ap, char const *str);
int flag_modulo(va_list ap, char const *str);
int my_putnbr_base_2(unsigned long, char const *);
int my_char_is_num(char c);
int flag_plus(va_list ap, char const *str);
int verif_flag(char const *str, int size, int check);
struct s_flag tab[NB_FLAGS];
int my_char_is_alpha(char c);
int get_flag(char const *str);
int flag_space(va_list ap, char const *str);
int flag_hash(va_list ap, char const *str);

#endif