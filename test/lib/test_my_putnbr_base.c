/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_putnbr_base
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "42sh.h"

int my_putnbr_base(int, const char *str);

void redirect_all_nbr(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(my_putnbr_base, output_1, .init = redirect_all_nbr)
{
	my_putnbr_base(6, "01");
	cr_assert_stdout_eq_str("110");
}

Test(my_putnbr_base, output_2, .init = redirect_all_nbr)
{
	my_putnbr_base(1, "0123456789");
	cr_assert_stdout_eq_str("1");
}

Test(my_putnbr_base, output_3, .init = redirect_all_nbr)
{
	my_putnbr_base(11, "0123456789ABCDEF");
	cr_assert_stdout_eq_str("B");
}