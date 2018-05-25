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

SRCS	=	srcs/main.c									\
		srcs/change_line.c								\
			$(DIR)/history/recup_index.c						\
			$(DIR)/history/put_in_history.c						\
			$(DIR)/history/history_functions.c					\
			$(DIR)/history/history_completion.c					\
			$(DIR)/ncurses/autocompletion.c						\
			$(DIR)/ncurses/special_char_function.c					\
			$(DIR)/ncurses/ctr_function.c						\
			$(DIR)/ncurses/move_cursor.c						\
			$(DIR)/ncurses/delete_functions.c					\
			$(DIR)/ncurses/write_char.c						\
			$(DIR)/ncurses/recup_line.c						\
			$(DIR)/ncurses/history_key.c						\
			$(DIR)/alias/alias_cmd.c						\
			$(DIR)/alias/recup_aliases.c						\
			$(DIR)/alias/change_for_alias.c						\
			$(DIR)/utils/check_perm.c						\
			$(DIR)/utils/delete_list.c						\
			$(DIR)/utils/print.c							\
			$(DIR)/utils/fill_list.c						\
			$(DIR)/utils/get_env.c							\
			$(DIR)/utils/list_to_tab.c						\
			$(DIR)/utils/comp.c							\
			$(DIR)/utils/check_char.c						\
			$(DIR)/utils/delete_node.c						\
			$(DIR)/utils/display.c							\
			$(DIR)/utils/display_tree.c						\
			$(DIR)/utils/delim_words.c						\
			$(DIR)/utils/path.c							\
			$(DIR)/utils/free.c							\
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
			$(DIR)/parser/handle_parentheses.c					\
			$(DIR)/execution/exec_cmd.c						\
			$(DIR)/execution/redirect.c						\
			$(DIR)/execution/builtins/cd_special_cases.c				\
			$(DIR)/execution/builtins/builtins.c					\
			$(DIR)/execution/builtins/cd.c						\
			$(DIR)/execution/builtins/env.c						\
			$(DIR)/execution/builtins/ignore_env.c					\
			$(DIR)/execution/builtins/env_chdir.c					\
			$(DIR)/execution/builtins/env_special_cases.c				\
			$(DIR)/execution/builtins/setenv.c					\
			$(DIR)/execution/pipe.c							\
			$(DIR)/execution/separators.c						\
			$(DIR)/execution/rules_exec.c						\
			$(DIR)/handle_line/handle_line.c					\
			$(DIR)/scripting/check_script.c						\
			$(DIR)/globbings/globbings.c						\
			$(DIR)/globbings/globbings_utils.c					\
			$(DIR)/quotes/quotes.c							\
			$(DIR)/quotes/quotes_utils.c						\
			$(DIR)/quotes/simple_quotes.c						\
			$(DIR)/quotes/simple_quotes_utils.c					\
			$(DIR)/quotes/handle_dollars.c						\
			$(DIR)/inihibitors/inihibitors.c					\
			$(DIR)/special_var/chainlist_spec.c					\
			$(DIR)/special_var/special_var_init.c					\
			$(DIR)/special_var/special_var_utils.c					\
			$(DIR)/special_var/special_var.c					\
			$(DIR)/special_var/spec_var.c						\

SRCS_UT	=	$(DIR)/utils/check_perm.c				\
			$(DIR)/utils/delete_list.c			\
			$(DIR)/utils/get_env.c				\
			$(DIR)/utils/fill_list.c			\
			$(DIR)/utils/print.c				\
			$(DIR)/utils/list_to_tab.c			\
			$(DIR)/utils/comp.c				\
			$(DIR)/utils/check_char.c			\
			$(DIR)/utils/delete_node.c			\
			$(DIR)/utils/display.c				\
			$(DIR)/utils/display_tree.c			\
			$(DIR)/utils/path.c				\
			$(DIR)/utils/delim_words.c			\
			$(DIR)/lexer/lexer.c				\
			$(DIR)/lexer/get_options.c			\
			$(DIR)/lexer/delim_lexem.c			\
			$(DIR)/lexer/get_builtins.c			\
			$(DIR)/lexer/get_cmd.c				\
			$(DIR)/lexer/handle_backticks.c		\
			$(DIR)/parser/cmd_rule.c			\
			$(DIR)/parser/exp_rule.c			\
			$(DIR)/parser/handle_parentheses.c		\
			$(DIR)/parser/get_name.c			\
			$(DIR)/parser/pipexp_rule.c			\
			$(DIR)/parser/s_rule.c				\
			$(DIR)/parser/rexp_rule.c			\
			$(DIR)/execution/exec_cmd.c			\
			$(DIR)/execution/redirect.c			\
			$(DIR)/execution/pipe.c				\
			$(DIR)/execution/builtins/builtins.c		\
			$(DIR)/execution/builtins/env.c			\
			$(DIR)/execution/builtins/setenv.c		\
			$(DIR)/execution/builtins/env_special_cases.c	\
			$(DIR)/execution/builtins/cd.c			\
			$(DIR)/execution/builtins/ignore_env.c		\
			$(DIR)/execution/builtins/env_chdir.c		\
			$(DIR)/execution/separators.c			\
			$(DIR)/execution/rules_exec.c			\
			$(DIR)/execution/builtins/cd_special_cases.c	\
			$(DIR)/inihibitors/inihibitors.c		\
			$(DIR)/quotes/handle_dollars.c			\
			$(DIR)/alias/alias_cmd.c			\
			$(DIR)/alias/change_for_alias.c			\
			$(DIR)/alias/recup_aliases.c			\
			$(DIR)/scripting/check_script.c			\
			$(DIR)/history/history_functions.c		\
			$(DIR)/history/history_completion.c		\
			$(DIR)/special_var/special_var_init.c		\
			$(DIR)/special_var/special_var_utils.c		\
			$(DIR)/special_var/special_var.c		\
			$(DIR)/history/recup_index.c			\
			$(DIR)/special_var/chainlist_spec.c		\
			$(DIR)/special_var/spec_var.c			\
			srcs/change_line.c

UT_DIR	=	test/lib/

SRCS_TESTS=	test/test_my_printf.c						\
			test/minishell/test_check_char.c			\
			test/minishell/test_check_builtins.c			\
			test/minishell/test_string_return.c			\
			test/minishell/test_cd_return.c				\
			test/minishell/test_success_failure.c			\
			$(UT_DIR)test_my_strcat.c				\
			$(UT_DIR)test_my_fact_it.c				\
			$(UT_DIR)test_my_fact_rec.c				\
			$(UT_DIR)test_my_find_prime_sup.c			\
			$(UT_DIR)test_my_is_prime.c				\
			$(UT_DIR)test_my_power_it.c				\
			$(UT_DIR)test_my_power_rec.c				\
			$(UT_DIR)test_my_putnbr_base.c				\
			$(UT_DIR)test_my_revstr.c				\
			$(UT_DIR)test_my_getnbr.c				\
			$(UT_DIR)test_my_str_isalpha.c				\
			$(UT_DIR)test_my_str_islower.c				\
			$(UT_DIR)test_my_str_isnum.c				\
			$(UT_DIR)test_my_str_isupper.c				\
			$(UT_DIR)test_my_strcpy.c				\
			$(UT_DIR)test_my_strlowcase.c				\
			$(UT_DIR)test_my_strncpy.c				\
			$(UT_DIR)test_my_strstr.c				\
			$(UT_DIR)test_my_strupcase.c				\
			$(UT_DIR)test_my_char_is_alpha.c			\
			$(UT_DIR)test_my_char_is_alphanum.c			\
			$(UT_DIR)test_my_char_is_num.c				\
			$(UT_DIR)test_my_putstr.c				\
			$(UT_DIR)test_my_strdup.c				\
			$(UT_DIR)test_my_strlen.c				\
			$(UT_DIR)test_my_strncat.c				\
			$(UT_DIR)test_my_strncmp.c				\
			$(UT_DIR)test_my_swap.c

LDFLAGS=	-lcriterion --coverage -lncurses -L./lib -lmy

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
