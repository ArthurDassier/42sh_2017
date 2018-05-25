##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile lib
##
CC	=	gcc

CP	=	cp

AC	=	ar rc

SRCS =		array/my_show_word_array.c 		\
		array/my_tab_to_int.c			\
		array/my_strarraylen.c			\
		array/my_tab_to_str.c			\
		char/my_char_is_alpha.c			\
		char/my_char_is_num.c			\
		char/my_char_is_alphanum.c		\
		get_next_line/get_next_line.c		\
		lists/create_list.c			\
		lists/display_list.c			\
		lists/free_list.c			\
		lists/my_sort_list.c			\
		lists/find_node.c			\
		lists/get_size_list.c			\
		mem/my_free.c				\
		mem/my_malloc.c				\
		mem/my_memdel.c				\
		mem/my_memset.c				\
		mem/my_realloc.c			\
		mem/my_calloc.c				\
		mem/my_memcpy.c				\
		nbr/my_compute_factorial_it.c		\
		nbr/my_compute_factorial_rec.c		\
		nbr/my_compute_power_it.c		\
		nbr/my_compute_power_rec.c		\
		nbr/my_find_prime_sup.c			\
		nbr/my_getnbr_base.c			\
		nbr/my_getnbr.c				\
		nbr/my_is_prime.c			\
		nbr/my_isneg.c				\
		nbr/my_swap.c				\
		print/my_print_alpha.c			\
		print/my_print_digits.c			\
		print/my_print_err.c			\
		print/my_print_revalpha.c		\
		print/my_put_nbr.c			\
		print/my_putchar.c			\
		print/my_putnbr_base_2.c		\
		print/my_putnbr_base.c			\
		print/my_putstr.c			\
		printf/flags_2.c			\
		printf/flags_3.c			\
		printf/flags_4.c			\
		printf/flags.c				\
		printf/my_printf.c			\
		printf/utils.c				\
		str/my_itoa.c				\
		str/my_revstr.c				\
		str/my_str_isalpha.c			\
		str/my_str_islower.c			\
		str/my_str_isnum.c			\
		str/my_str_isprintable.c		\
		str/my_str_isupper.c			\
		str/my_strcat.c				\
		str/my_strcmp.c				\
		str/my_strcpy.c				\
		str/my_strdup.c				\
		str/my_strisalphanum.c			\
		str/my_strlen.c				\
		str/my_strlowcase.c			\
		str/my_strncat.c			\
		str/my_strncmp.c			\
		str/my_strncpy.c			\
		str/my_strndup.c			\
		str/my_strstr.c				\
		str/my_strupcase.c

OBJ	=	$(SRCS:.c=.o)

RM	=	rm -rf

CPPFLAGS +=	-I./include

CFLAGS	+=	-Wall -Wextra

NAME	=	libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	$(AC) $(NAME) $(OBJ)
	ranlib $(NAME)
	mv $(NAME) ..
	$(CP) include/list.h ../../include

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) libmy.a

re:	fclean all

.PHONY: all clean fclean re
