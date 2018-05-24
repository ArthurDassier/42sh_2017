/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_putstr
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "42sh.h"

void my_putstr(char const *str);

void redirect_all_stdr(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(my_putstr, output_1, .init = redirect_all_stdr)
{
	my_putstr("hello world");
	cr_assert_stdout_eq_str("hello world");
}

Test(my_putstr, output_2, .init = redirect_all_stdr)
{
	my_putstr("4553662");
	cr_assert_stdout_eq_str("4553662");
}

Test(my_putstr, output_3, .init = redirect_all_stdr)
{
	my_putstr("4\nbl*&^><\t\n");
	cr_assert_stdout_eq_str("4\nbl*&^><\t\n");
}