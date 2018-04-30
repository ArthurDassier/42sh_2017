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
	static int	count = 1;
	int		i = 0;
	int		tmp = count;
	char		*nb = malloc(sizeof(char) * 4);
	time_t		timestamp = time(NULL);

	while (tmp > 9) {
		nb[i++] = tmp % 10 + 48;
		tmp /= 10;
	}
	nb[i++] = tmp + 48;
	nb[i] = '\0';
	nb = my_revstr(nb);
	write(fd, nb, my_strlen(nb));
	write(fd, "\t", 1);
	write(fd, line, strlen(line));
	write(fd, "\t", 1);
	write(fd, ctime(&timestamp), my_strlen(ctime(&timestamp)));
	++count;
}
