/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** builtins
*/

#ifndef BUILTINS_H_
#define BUILTINS_H_

#include "list.h"
#include "42sh.h"

typedef struct	s_built {
	char	*builtin;
	int		(*ptr)(char **, t_node **);
}				t_built;

/*
** Built-ins
*/
int		env_built(char **, t_node **, t_files_info *);
int		exit_built(char **, t_node **);
int		cd_built(char **, t_node **);
int		setenv_built(char **, t_node **);
bool		check_env_name(t_node *, char *);
int		unsetenv_built(char **, t_node **);
void		change_pwd(t_node **, char *);
int		cd_special_cases(char **, t_node **, char *);
int		display_help(__attribute((unused)) char **, t_node **);
int		normal_cd(t_node **, char **);
int		unset_name(char **, t_node **);
int		get_cd(char *, t_node **);
int		display_version(char **line, t_node **);
int		rm_var(char **, t_node **);
int		ignore_env(char **, t_node **);
int		end_with_null(__attribute((unused)) char **, t_node **);
int		env_chdir(char **, t_node **, t_files_info *);

#endif /* !BUILTINS_H_ */
