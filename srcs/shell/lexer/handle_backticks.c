/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** handle_backticks
*/

#include "42sh.h"

static void del_last_backticks(char **line, int index)
{
	while (line[index]) {
		if (strcmp(line[index], "`") == SUCCESS)
			line[index] = NULL;
		++index;
	}
}

static bool check_if_matching_quotes(char **line)
{
	int	count = 0;

	for (int i = 0; line[i]; ++i) {
		if (strcmp(line[i], "`") == SUCCESS)
			++count;
	}
	if (count % 2 == 0)
		return (true);
	return (false);
}

char *handle_backticks(char **line, int index, t_node *env_list)
{
	FILE *cmd;
	char *buffer = malloc(sizeof(char) * 10000);
	char *save = malloc(sizeof(char) * 10000);

	if (!buffer)
		return (NULL);
	if (check_if_matching_quotes(line) == false) {
		my_print_err("Unmatched '`'.\n");
		return (NULL);
	}
	del_last_backticks(line, index + 1);
	my_show_word_array(line);
	cmd = popen(line[index + 1], "r");
	while (fgets(buffer, sizeof(buffer), cmd) != 0) {
		save = realloc(save, sizeof(char) * strlen(buffer) + strlen(save) + 1);
		strcat(save, buffer);
	}
	pclose(cmd);
	return (save);
}