/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** test_check_builtins
*/
#include <criterion/criterion.h>
#include "shell.h"

int	get_builtins(t_node **, char *);

Test(get_builtins, return_value_is_good)
{
	t_node *node = NULL;

	cr_assert_eq(get_builtins(&node, "cd"), 0);
	cr_assert_eq(get_builtins(&node, "cat"), 84);
	cr_assert_eq(get_builtins(&node, "setenv"), 0);
	cr_assert_eq(get_builtins(&node, "unsetenv"), 0);
	cr_assert_eq(get_builtins(&node, "env"), 0);
	cr_assert_eq(get_builtins(&node, "exit"), 0);
}

