/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** test_check_char
*/
#include <criterion/criterion.h>
#include "42sh.h"

int	check_char(char *);

Test(check_char, return_value_is_good)
{
	cr_assert_eq(check_char("    lol"), 0);
	cr_assert_eq(check_char("    mkdir    "), 0);
	cr_assert_eq(check_char("coucou"), 0);
	cr_assert_eq(check_char("\t"), 84);
	cr_assert_eq(check_char("coucou\r"), 0);
	cr_assert_eq(check_char("\r"), 84);
	cr_assert_eq(check_char("aaaa\naaaa"), 0);
	cr_assert_eq(check_char("mkdir"), 0);
}
