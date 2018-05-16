#include <stdio.h>

int main(int ac, char **av, char **env)
{
	if (!env[0])
		printf("no env\n");
	else
		printf("env exists\n");
	return 0;
}