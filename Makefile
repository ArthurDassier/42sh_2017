##
## EPITECH PROJECT, 2018
## PSU_42sh_2017
## File description:
## Makefile
##

CC	=	gcc -g3

RM	=	rm -rf

TEST_CC	=	gcc -Wall -Wextra -I./include -I./lib/my/include --coverage

CFLAGS	+=	-Wall -Wextra

CPPFLAGS	+=	-I./include -I./lib/my/include

NAME	=	42sh

DIR	=	srcs/shell/

SRCS	=	srcs/main.c										\
			$(DIR)/alias/alias_cmd.c						\
			$(DIR)/alias/recup_aliases.c					\
			$(DIR)/alias/change_for_alias.c					\
			$(DIR)/utils/check_perm.c						\
			$(DIR)/utils/delete_list.c						\
			$(DIR)/utils/print.c							\
			$(DIR)/utils/fill_list.c						\
			$(DIR)/utils/get_env.c							\
			$(DIR)/utils/list_to_tab.c						\
			$(DIR)/utils/comp.c								\
			$(DIR)/utils/check_char.c						\
			$(DIR)/utils/delete_node.c						\
			$(DIR)/utils/display.c							\
			$(DIR)/utils/display_tree.c						\
			$(DIR)/utils/delim_words.c						\
			$(DIR)/utils/path.c								\
			$(DIR)/utils/free.c								\
			$(DIR)/utils/prompt.c							\
			$(DIR)/lexer/lexer.c							\
			$(DIR)/lexer/get_options.c						\
			$(DIR)/lexer/get_builtins.c						\
			$(DIR)/lexer/delim_lexem.c						\
			$(DIR)/lexer/get_cmd.c							\
			$(DIR)/parser/cmd_rule.c						\
			$(DIR)/parser/exp_rule.c						\
			$(DIR)/parser/get_name.c						\
			$(DIR)/parser/pipexp_rule.c						\
			$(DIR)/parser/rexp_rule.c						\
			$(DIR)/parser/s_rule.c							\
			$(DIR)/parser/handle_parentheses.c				\
			$(DIR)/execution/exec_cmd.c						\
			$(DIR)/execution/redirect.c						\
			$(DIR)/execution/builtins/cd_special_cases.c	\
			$(DIR)/execution/builtins/builtins.c			\
			$(DIR)/execution/builtins/cd.c					\
			$(DIR)/execution/builtins/env.c					\
			$(DIR)/execution/builtins/ignore_env.c			\
			$(DIR)/execution/builtins/env_chdir.c			\
			$(DIR)/execution/builtins/env_special_cases.c	\
			$(DIR)/execution/builtins/setenv.c				\
			$(DIR)/execution/pipe.c							\
			$(DIR)/execution/separators.c					\
			$(DIR)/execution/rules_exec.c					\
			$(DIR)/scripting/check_script.c					\
			$(DIR)/globbings/globbings.c					\
			$(DIR)/globbings/globbings_utils.c				\
			$(DIR)/inihibitors/inihibitors.c

SRCS_UT	=	$(DIR)/utils/check_perm.c			\
			$(DIR)/utils/delete_list.c			\
			$(DIR)/utils/print.c				\
			$(DIR)/utils/fill_list.c			\
			$(DIR)/utils/list_to_tab.c			\
			$(DIR)/utils/comp.c					\
			$(DIR)/utils/check_char.c			\
			$(DIR)/utils/delete_node.c			\
			$(DIR)/utils/display.c				\
			$(DIR)/utils/display_tree.c			\
			$(DIR)/utils/path.c					\
			$(DIR)/lexer/lexer.c				\
			$(DIR)/lexer/get_options.c			\
			$(DIR)/lexer/get_builtins.c			\
			$(DIR)/lexer/get_cmd.c				\
			$(DIR)/parser/cmd_rule.c			\
			$(DIR)/parser/exp_rule.c			\
			$(DIR)/parser/get_name.c			\
			$(DIR)/parser/pipexp_rule.c			\
			$(DIR)/parser/rexp_rule.c			\
			$(DIR)/parser/s_rule.c				\
			$(DIR)/execution/exec_cmd.c			\
			$(DIR)/execution/redirect.c			\
			$(DIR)/execution/pipe.c				\
			$(DIR)/execution/env.c				\
			$(DIR)/execution/builtins.c			\
			$(DIR)/execution/parentheses.c		\
			$(DIR)/execution/setenv.c			\
			$(DIR)/execution/cd.c				\
			$(DIR)/execution/rules_exec.c		\
			$(DIR)/alias/alias_cmd.c			\
			$(DIR)/alias/recup_aliases.c		\
			$(DIR)/aliaschange_for_alias.c		\
			$(DIR)/scripting/check_script.c


UT_DIR	=	tests/lib/

SRCS_TESTS=	tests/test_my_printf.c					\
			tests/minishell/test_check_char.c		\
			tests/minishell/test_check_builtins.c	\
			$(UT_DIR)test_my_strcat.c				\
			$(UT_DIR)test_my_fact_it.c				\
			$(UT_DIR)test_my_fact_rec.c				\
			$(UT_DIR)test_my_find_prime_sup.c		\
			$(UT_DIR)test_my_is_prime.c				\
			$(UT_DIR)test_my_power_it.c				\
			$(UT_DIR)test_my_power_rec.c			\
			$(UT_DIR)test_my_putnbr_base.c			\
			$(UT_DIR)test_my_revstr.c				\
			$(UT_DIR)test_my_getnbr.c				\
			$(UT_DIR)test_my_str_isalpha.c			\
			$(UT_DIR)test_my_str_islower.c			\
			$(UT_DIR)test_my_str_isnum.c			\
			$(UT_DIR)test_my_str_isupper.c			\
			$(UT_DIR)test_my_strcpy.c				\
			$(UT_DIR)test_my_strlowcase.c			\
			$(UT_DIR)test_my_strncpy.c				\
			$(UT_DIR)test_my_strstr.c				\
			$(UT_DIR)test_my_strupcase.c			\
			$(UT_DIR)test_my_char_is_alpha.c		\
			$(UT_DIR)test_my_char_is_alphanum.c		\
			$(UT_DIR)test_my_char_is_num.c			\
			$(UT_DIR)test_my_putstr.c				\
			$(UT_DIR)test_my_strdup.c				\
			$(UT_DIR)test_my_strlen.c				\
			$(UT_DIR)test_my_strncat.c				\
			$(UT_DIR)test_my_strncmp.c				\
			$(UT_DIR)test_my_swap.c

LDFLAGS=	-lcriterion --coverage -lreadline -lncurses -L./lib -lmy

TEST_NAME=	units

OBJS	=	$(SRCS:.c=.o)

LIB = libmy.a

all: $(LIB) $(NAME) $(VERSION_FLAGS)

tests_run:	EXEC
		./$(TEST_NAME)

./lib/my/libmy.a:
	make -C ./lib/my

EXEC:		./lib/my/libmy.a
		$(TEST_CC) -o $(TEST_NAME) $(SRCS_UT) $(SRCS_TESTS) $(LDFLAGS)


$(LIB):
	make -C ./lib/my

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	make -C ./lib/my

clean:
	$(RM) $(OBJS)
	find . -type f -name '*.gc*' -delete
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)
	$(RM) lib/libmy.a
	make -C ./lib/my fclean

re: fclean all

.PHONY:		all exec tests_run clean fclean re
