/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** test_string_return
*/
#include <criterion/criterion.h>
#include "shell.h"

char *new_str(t_aliases *, char *);

Test(string_return, new_str)
{
	t_aliases *alias = NULL;
	char *str = "Hello";

	cr_assert_str_eq(new_str(alias, str), str);
}

Test(string_return, history_completion)
{
	t_node *hist_list = NULL;
	char *line = strdup("Hello");

	cr_assert(history_completion(hist_list, line, "$>") == NULL);
}

Test(string_return, inib)
{
	char *s1 = strdup("Hello");
	char *s2 = strdup("\\Hello");

	cr_assert_str_eq(inib(s1), s1);
	cr_assert_str_eq(inib(s2), s2);
}

Test(string_return, handle_dollars)
{
	t_quotes *env_list = NULL;
	char *s1 = strdup("Hello");

	cr_assert_str_eq(handle_dollars(s1, env_list), s1);
	cr_assert(handle_dollars(s1, env_list) != NULL);
}
