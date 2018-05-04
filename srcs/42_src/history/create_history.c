/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** create_history
*/

#include "42sh.h"

void write_in_file(void)
{
	HISTORY_STATE		*my_hist = history_get_history_state();
	HIST_ENTRY		**my_list = history_list();
	int			fd = open(".42_src/history.txt",
	O_WRONLY | O_TRUNC);
	static char		back_t = '\t';
	int			nb = 1;

	for (int i = 0; i < my_hist->length; ++i) {
		write(fd, my_list[i]->line, strlen(my_list[i]->line));
		write(fd, &back_t, 1);
		write(fd, my_list[i]->timestamp,
		strlen(my_list[i]->timestamp));
		free_history_entry(my_list[i]);
		++nb;
	}
	free(my_hist);
	free(my_list);
}
