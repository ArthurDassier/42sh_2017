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
	O_WRONLY | O_APPEND);
	static char		back_t = '\t';
	static int		nb = 1;

	write(fd, my_itoa(nb), my_strlen(my_itoa(nb)));
	write(fd, &back_t, 1);
	write(fd, my_list[my_hist->length - 1]->line,
	strlen(my_list[my_hist->length - 1]->line));
	write(fd, &back_t, 1);
	write(fd, my_list[my_hist->length - 1]->timestamp,
	strlen(my_list[my_hist->length - 1]->timestamp));
	++nb;
}

void put_in_history(char *s)
{
	time_t		timestamp = time(NULL);

	add_history(s);
	add_history_time(ctime(&timestamp));
	write_in_file();
}
