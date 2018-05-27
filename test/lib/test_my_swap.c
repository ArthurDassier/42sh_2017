/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** test_my_swap
*/
#include <criterion/criterion.h>
#include <shell.h>

void my_swap(int *a, int *b);

Test(my_swap, values_are_equal)
{
	int	a = 35;
	int	b = 10;

	my_swap(&a, &b);
	cr_assert_eq(a, 10);
	cr_assert_eq(b, 35);
}