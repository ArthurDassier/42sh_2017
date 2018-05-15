/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** check_script
*/

#include "42sh.h"

const int BUFF_SIZE = 256;

static bool check_shebang(char **line, int size)
{
	FILE* file = fopen(line[size - 1], "r");
	char	save[BUFF_SIZE];

	fgets(save, sizeof(save), file);
	fclose(file);
	printf("save =  %s\n", save);
	if (strncmp(save, "#!", 2) == SUCCESS)
		return (true);
	return (false);
}

//Returns true if line is a script. Returns false otherwise.
bool	check_script(char **line)
{
	int		size = my_strarraylen(line);

	if (check_shebang(line, size) == true)
			return (true);
	return (false);
}