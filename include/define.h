/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

/*
** Error handling
*/
#define	ERROR		-1
#define	VALID		1
#define	SUCCESS		0
#define	FAILURE		84
#define ERR_MSG1 "env: cannot specify --null (-0) with command\n"
#define ERR_MSG2 "Try 'env --help' for more information."

/*
** NB
*/
#define NB_BUILT	5
#define NB_FLAGS	9

/*
** Print
*/
#define VERSION_MSG1 "env (GNU coreutils) 8.28\nCopyright (C) 2017 Free "
#define VERSION_MSG2 "Software Foundation, Inc.\nThis is free software: you are"
#define VERSION_MSG3 " free to change and redistribute it.\nThere is NO "
#define VERSION_MSG4 "WARRANTY, to the extent permitted by law.\n\nWritten by"
#define VERSION_MSG5 " Angela Martoccia Boyadjian."
#define HELP_MSG1 "Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND "
#define HELP_MSG2 "[ARG]...]\nSet each NAME to VALUE in the environment and "
#define HELP_MSG3 "run COMMAND.\n\nMandatory arguments to long options are "
#define HELP_MSG4 "mandatory for short options too.\n\t-i, --ignore-environment"
#define HELP_MSG5 "  start with an empty environment\n\t-0, --null           "
#define HELP_MSG6 "end each output line with NUL, not newline\n"
#define HELP_MSG7 "\t-u, --unset=NAME     remove variable from the environment"
#define HELP_MSG8 "\n\t-C, --chdir=DIR      change working directory to DIR\n"
#define HELP_MSG9 "\t--help     display this help and exit\n"
#define HELP_MSG10 "\t--version  output version information and exit\n\n"
#define HELP_MSG11 "A mere - implies -i.  If no COMMAND, print the resulting "
#define HELP_MSG12 "environment."

/*
** Colors
*/
#define RED     	"\x1b[31m"
#define GREEN   	"\x1b[32m"
#define YELLOW  	"\x1b[33m"
#define BLUE    	"\x1b[34m"
#define MAGENTA 	"\x1b[35m"
#define CYAN    	"\x1b[36m"
#define RESET   	"\x1b[0m"

#endif /* !DEFINE_H_ */
