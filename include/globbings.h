/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** globbings
*/

#ifndef GLOBBINGS_H_
#define GLOBBINGS_H_

/*
** Globbings
*/
char	**globbings(char **);
void	release_tmp(char **);
char	**copy_line(char **);
int	alloc_tab(char **, char **);
int	back_slash(int, char *);
int	count_glob(char **);

#endif /* !GLOBBINGS_H_ */
