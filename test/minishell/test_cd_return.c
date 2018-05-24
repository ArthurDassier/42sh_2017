/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** test_success_failure
*/
#include "criterion/criterion.h"
#include "42sh.h"

Test(cd_return, normal_cd)
{
	t_node **env_list = NULL;
	//char **l1 = my_str_to_word_array("cd include\n");
	char **l2 = my_str_to_word_array("cd hello\n");

	//cr_assert_eq(normal_cd(env_list, l1), 0);
	cr_assert_eq(normal_cd(env_list, l2), 84);
}

Test(cd_return, get_cd)
{
	t_node **env_list = NULL;
	char *s1 = NULL;
	//char *s2 = strdup("OLDPWD=/home/aloiseau/Tek1/minishell");

	cr_assert_eq(get_cd(s1, env_list), 84);
	//cr_assert_eq(get_cd(s2, env_list), 0);
}

/*Test(cd_return, cd_special_cases)
{
	t_node **env_list = NULL;
	char **line = my_str_to_word_array("cd ~");
	char *str = NULL;

	//cr_assert_eq(cd_special_cases(line, env_list, str), 84);
}

Test(cd_return, cd_built)
{
	t_node **env_list = NULL;
	char **line = NULL;

	//cr_assert_eq(cd_built(line, env_list), 84);
}*/
