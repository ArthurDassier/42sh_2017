/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header lib
*/
#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

// array
int	my_show_word_array(char * const *);
char	**my_str_to_wordtab_delim(char *, char *);
void	my_sort_int_array(int *, int);
int	my_strarraylen(char **);
int	*my_tab_to_int(char **, int);

// char
int	my_char_is_alpha(char);
int	my_char_is_num(char);
int	my_char_is_alphanum(char);

// mem
void	my_free(void *);
void	*my_malloc(int);
void	my_memdel(void **);
void	*my_realloc(void *, int);
void	*my_calloc(int);
void	my_memset(void *, int);
void	my_memcpy(void *, void *, size_t);

// nbr
int	my_compute_factorial_it(int);
int	my_compute_factorial_rec(int);
int	my_compute_power_it(int, int);
int	my_compute_power_rec(int, int);
int	my_compute_square_root(int);
int	my_is_prime(int);
int	my_find_prime_sup(int);
int	my_getnbr(char const *);
int	my_getnbr_base(char const *, char const *);
int	my_isneg(int);
void	my_swap(int *, int *);

// print
void	my_print_err(char *);
int	my_print_alpha(void);
int	my_print_digits(void);
void	my_putstr(char const *);
int	my_put_nbr(int);
void	my_putchar(char);
int	my_putnbr_base(int, char const *);
int	my_putnbr_base_2(unsigned long, char const *);
void	my_print_err(char *);
int	my_printf(char const *, ...);

// str
char	*my_itoa(int);
char	*my_revstr(char *);
int	my_str_isalpha(char const *);
int	my_str_isnum(char const *);
int	my_str_isprintable(char const *);
int	my_str_islower(char const *);
int	my_str_isupper(char const *);
char	*my_strcat(char *, char const *);
char	*my_strcpy(char *, char const *);
int	my_strcmp(char const *, char const *);
char	*my_strdup(char const *);
int	my_strisalphanum(char *);
int	my_strlen(char const *);
char	*my_strlowcase(char *);
char	*my_strncat(char *, char const *, int);
int	my_strncmp(char const *, char const *, int);
char	*my_strncpy(char *, char const *, int);
char	*my_strndup(char const *, int);
char	*my_strstr(char *, char const *);
char	*my_strupcase(char *);
char	*get_next_line(int);

#endif