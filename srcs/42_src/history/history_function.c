/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history_function
*/

#include "42sh.h"

static char	*replace_and_show_command(int hist_line)
{
	HISTORY_STATE		*my_hist = history_get_history_state();
	HIST_ENTRY		**my_list = history_list();

	if (hist_line > 0) {
		my_putstr(my_list[hist_line - 1]->line);
		my_putchar('\n');
		return (my_list[hist_line - 1]->line);
	} else if (hist_line < 0) {
		my_putstr(my_list[my_hist->length - hist_line - 1]->line);
		my_putchar('\n');
		return (my_list[my_hist->length - hist_line - 1]->line);
	} else {
		my_put_nbr(hist_line);
		my_putstr(": Event not found.\n");
		return (NULL);
	}
}

void	replace_from_history(char **line)
{
	int	tmp = 0;

	if (line[0][0] == '!' && line[0][1] == '\0') {
		free(line[0]);
		free(line[1]);
		line[0] = "cat";
		line[1] = ".42_src/history.txt";
	} else if (line[0][0] == '!') {
		tmp = line[0][1] - 48;
		free(line[0]);
		line[0] = replace_and_show_command(tmp);
	}
}