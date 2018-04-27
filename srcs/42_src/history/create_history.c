/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** create_history
*/

#include "42sh.h"
#include <time.h>

void write_in_history(char *line, int fd)
{
	static int	i = 1;
	time_t		timestamp = time(NULL);

	write(fd, "\t", 1);
	write(fd, &i, sizeof(int));
	write(fd, ctime(&timestamp), my_strlen(ctime(&timestamp)));
	write(fd, "\t", 1);
	write(fd, line, my_strlen(line));
}