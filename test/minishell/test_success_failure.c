/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** test_success_failure
*/
#include "criterion/criterion.h"
#include "42sh.h"

Test(int_return, change_line)
{
	t_files_info *info = NULL;
	//char **l1 = my_str_to_word_array("Hello there");
	char **l2 = my_str_to_word_array("& Hello there");

	//cr_assert_eq(change_line(l1, info), 0);
	cr_assert_eq(change_line(l2, info), 84);
}
