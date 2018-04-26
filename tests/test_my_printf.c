/*
** EPITECH PROJECT, 2017
** test_my_printf.c
** File description:
** test for my_printf function
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "minishell2.h"

int my_printf(char const *str, ...);

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(my_printf, output_1, .init = redirect_all_std)
{
	my_printf("hello world");
	cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, output_2, .init = redirect_all_std)
{
	my_printf("%s\n", "hello 42");
	cr_assert_stdout_eq_str("hello 42\n");
}

Test(my_printf, output_3, .init = redirect_all_std)
{
	my_printf("%d\n", 42);
	cr_assert_stdout_eq_str("42\n");
}

Test(my_printf, output_4, .init = redirect_all_std)
{
	my_printf("%c\n", 'a');
	cr_assert_stdout_eq_str("a\n");
}

Test(my_printf, output_5, .init = redirect_all_std)
{
	my_printf("%i\n", 42);
	cr_assert_stdout_eq_str("42\n");
}

Test(my_printf, output_6, .init = redirect_all_std)
{
	my_printf("%%");
	cr_assert_stdout_eq_str("%");
}

Test(my_printf, output_7, .init = redirect_all_std)
{
	my_printf("%+d %b %o %x %X %u % d %#o %u\n", 42, 42, 42, 42,
	42, 42, 42, 42, 42);
	cr_assert_stdout_eq_str("+42 101010 52 2a 2A 42  42 052 42\n");
}